#include <bits/stdc++.h>
#include <csignal>
#include <fstream>
#include "../include/lexer/lexer.hpp"
#include "../include/parser/weak_t_parser.hpp"



// LEXER DEFINED SINGELTONS
TokenDirectorSingleton TokenDirectorSingleton :: globalInstance; 
TokenDirectorSingleton& directorObject = TokenDirectorSingleton :: getGlobalInstance(); 

SingletonData SingletonData :: globalInstance; 
SingletonData& builtInTokensData = SingletonData :: getGlobalInstance();

TokenEnumStringMap TokenEnumStringMap :: globalInstance;
TokenEnumStringMap& tokenClassStringMapGlobalInstance = TokenEnumStringMap :: getGlobalInstance();



// PARSER DEFINED SINGELTONS
RulesContainerSingelton RulesContainerSingelton :: globalInstance;
RulesContainerSingelton& rulesContainerSingeltonObject = RulesContainerSingelton :: getGlobalInstance();



// UNCOMMENT THIS LINE IN PRODUCTION
#define TESTING

#ifdef TESTING

std::string fileString;

void setTest(std::string& filePath){
  std::ifstream testFile(filePath);
  std::string lineString;

  if(testFile.is_open()){
    while(std::getline(testFile, lineString)){
      fileString += lineString; 
    }
    testFile.close();
  }
  else{
    std::cout << "File path or name is incorrect >> " << filePath << std::endl;
  }
}



void runFileAndLogLex(std::string& actualOutputPath){
  Script sampleCode = Script();
  sampleCode.setSringStream(std::move(actualOutputPath));
  sampleCode.lex();
  sampleCode.logTokenizedOutput(actualOutputPath);
}

void runFileAndLogParse(std::string& actualOutputPath){
  
}



void compareExpectedWithActual(std::string& actualOutputPath, std::string& expectedOutputPath){
  std::ifstream actual(actualOutputPath);
  std::ifstream expected(expectedOutputPath);

  std::string lineActual;
  std::string lineExpected;

  std::string actualString;
  std::string expectedString;


  if(!actual.is_open()){
    std::cout << "Actual output file path is incorrect >> " << actualOutputPath << std::endl;
  }
  if(!expected.is_open()){
    std::cout << "Expected output file path is incorrect >> " << expectedOutputPath << std::endl;
  }

  while(std::getline(actual, lineActual)){
    actualString += lineActual;
  }
  while(std::getline(expected, lineExpected)){
    expectedString += lineExpected;
  }

  if(actualString.size() != expectedString.size()){
    std::cout << "Size is not even the same!\n";
  }
  
  
  int lineCounter = 0;
  for(size_t i = 0; i < actualString.size(); i++){
    if(actualString.at(i) == '\n') lineCounter ++;

    if(actualString.at(i) != expectedString.at(i)){
      std::cout << "Test <<" << actualOutputPath << ">> FAILED at line: " << lineCounter << std::endl;
      return;
    }
  }
  std::cout << "Test <<" << actualOutputPath << ">> SUCCEEDED" << lineCounter << std::endl;
}





class Test{
public:
  std::string testCodePath;
  std::string actualOutputPath;
  std::string expectedOutputPath;

  Test(std::string& testCodePathInput, std::string& actualOutputPathInput, std::string& expectedOutputPathInput) :
    testCodePath(testCodePathInput),
    actualOutputPath(actualOutputPathInput),
    expectedOutputPath(expectedOutputPathInput) {}
};






// MAIN PROGRAM ENTRY POINT
int main(){
  std::vector<Test> tests;
  

  // TESTS ARE ADDED HERE
  //tests.push_back(Test());
  //tests.push_back(Test());
  //tests.push_back(Test());


  for(Test test : tests){
    std::cout << "WHAT?\n";
    setTest(test.testCodePath);
    runFileAndLogLex(test.actualOutputPath);
    compareExpectedWithActual(test.actualOutputPath, test.expectedOutputPath);
  }
  
  /*
  for(Test test : tests){
    setTest(test.testCodePath);
    runFileAndLogParse(test.actualOutputPath);
    compareExpectedWithActual(test.actualOutputPath, test.expectedOutputPath);
  }
  */
}



#else 
int main(){
  std::cout << "NOT TESTING\n";




}


#endif
  

