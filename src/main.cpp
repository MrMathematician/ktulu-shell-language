#include <bits/stdc++.h>
#include <fstream>
#include "../include/interpreter/interpreter.hpp"


// LEXER DEFINED SINGELTONS
TokenDirectorSingleton TokenDirectorSingleton :: globalInstance; 
TokenDirectorSingleton& directorObject = TokenDirectorSingleton :: getGlobalInstance(); 

SingletonData SingletonData :: globalInstance; 
SingletonData& builtInTokensData = SingletonData :: getGlobalInstance();

TokenEnumStringMap TokenEnumStringMap :: globalInstance;
TokenEnumStringMap& tokenClassStringMapGlobalInstance = TokenEnumStringMap :: getGlobalInstance();



// PARSER DEFINED SINGELTONS
// RulesContainerSingelton RulesContainerSingelton :: globalInstance;
// RulesContainerSingelton& rulesContainerSingeltonObject = RulesContainerSingelton :: getGlobalInstance();



// COMMENT THIS LINE IN PRODUCTION

#define TEST_DIR "/home/elshafei/archive/projects/shell_project/tests/correctness_tests/lexer/samples/test"
#define OUTPUT_DIR "/home/elshafei/archive/projects/shell_project/tests/correctness_tests/lexer/actual/out"

const int START_TEST = 1;
const int END_TEST = 11;

#ifdef TEST

std::vector<std::string> tests;

void takeFileInput(){
  for(int i = START_TEST; i < END_TEST; i++){
    std::ifstream file(TEST_DIR + std::to_string(i) + ".ktsh");

    if(file){
      std::cout << "Loaded test number " << i << '\n';
      std::stringstream buffer;
      buffer << file.rdbuf();
      tests.push_back(buffer.str());
      file.close();
    }
    else std::cout << "Error occurred, file not found!\n";
  }
}

void runTests(){
  Interpreter interpreter = Interpreter();
  for(int i = 0; i < tests.size(); i++){
    std::ofstream file(OUTPUT_DIR + std::to_string(i + 1) + ".txt");

    interpreter.tokenize(std::move(tests.at(i)));

    file << interpreter.recreateDiscrete();
    //interpreter.outputTokenStream();

    std::cout << "Finished test " << i + 1 << '\n';

    interpreter.reset();
  }
}



int main(){
  std::cout << "Initializing Tests ...\n";

  takeFileInput();
  runTests();

  std::cout << "Generated Successfully!\n\n";
  std::cout << "Check /home/elshafei/archive/projects/shell_project/tests/correctness_tests/lexer/actual/\n";
}



#else 
int main(){
  std::cout << "NOT TESTING\n";




}


#endif
  

