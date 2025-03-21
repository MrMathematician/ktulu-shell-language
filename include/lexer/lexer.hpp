#include <bits/stdc++.h>
#include <sstream>
#include <string>
#include "../logger/logger.hpp" 

#pragma once

enum class tokenType{
  KEYWORD,
  LITERAL,
  SEPARATOR,
  OPERATOR,
  CONSTANT,
  STRING,
  NUMBER,

  INT,
  BOOL,
  FLOAT,
  CHAR,
  STRING_VAR,

  MATH_FUNCTION,

  CMD_OPERATOR,

  INTERPRETER_MODE,

  UNSPECIFIED
};





// SINGLETON FOR THE TOKEN TO STRING MAP
// THIS SINGELTON EXISTS FOR DEBUGGING. DO NOT DELETE IT
// I HAVE INCLUDED THIS NOTE BECAUSE I ALWAYS ATTEMPT TO REMOVE IT
class TokenEnumStringMap{
private:
  static TokenEnumStringMap globalInstance;
  std::unordered_map<tokenType, std::string> tokenEnumStringMap; // CONST CHAR MAY CAUSE AN ERROR HERE (IT DIDN'T)

  TokenEnumStringMap(){
    tokenEnumStringMap[tokenType :: KEYWORD] = "KEYWORD";
    tokenEnumStringMap[tokenType :: LITERAL] = "LITERAL";
    tokenEnumStringMap[tokenType :: SEPARATOR] = "SEPARATOR";
    tokenEnumStringMap[tokenType :: OPERATOR] = "OPERATOR";
    tokenEnumStringMap[tokenType :: STRING] = "STRING";
    tokenEnumStringMap[tokenType :: NUMBER] = "NUMBER"; // SPECIFIC TYPES WILL BE NUMBER IF RUN IN WEAKLY TYPED MODE
  
    // THESE TYPES ARE GOING TO BE SET BY THE PARSER NOT THE LEXER
    tokenEnumStringMap[tokenType :: INT] = "INT";
    tokenEnumStringMap[tokenType :: BOOL] = "BOOL";
    tokenEnumStringMap[tokenType :: FLOAT] = "FLOAT";
    tokenEnumStringMap[tokenType :: CHAR] = "CHAR";
    tokenEnumStringMap[tokenType :: STRING_VAR] = "STRING_VAR";
   
    tokenEnumStringMap[tokenType :: MATH_FUNCTION] = "MATH_FUNCTION";
   
    tokenEnumStringMap[tokenType :: CMD_OPERATOR] = "CMD_OPERATOR";
    
    tokenEnumStringMap[tokenType :: CONSTANT] = "CONSTANT";
   
    tokenEnumStringMap[tokenType :: INTERPRETER_MODE] = "INTERPRETER_MODE";

    tokenEnumStringMap[tokenType :: UNSPECIFIED]  = "UNSPECIFIED";
  }

public:
  static TokenEnumStringMap& getGlobalInstance(){
    return globalInstance;
  }

  std::string getStringifiedEnum(tokenType enumToken){
    if(tokenEnumStringMap.count(enumToken)){
      return tokenEnumStringMap[enumToken];
    }
    return "DEBUGGING MESSAGE: ENUM TYPE DOES NOT EXIST IN THE tokenType enum class!";
  }

  void showBuiltinEnums(){
    std::cout << "BUILT IN ENUMS : \n";
    long unsigned int index = 0;
    for(const auto& pair : tokenEnumStringMap){
      std::cout << index << pair.second << '\n';
      index ++;
    }
  }
};


// Initialize once, use forever
extern TokenEnumStringMap& tokenClassStringMapGlobalInstance;






class Token final{
private:
  std::string tokenString;
  tokenType tokenGeneralType; 
  tokenType tokenSpecificType = tokenType :: UNSPECIFIED;
  size_t lineOccurence;

public:
  Token(std::string newTokenString){ // THIS PART NEEDS TO BE OPTIMIZED USING std::move() in the near future
    tokenString = newTokenString; 
  }

  Token(){}

  void getInputStream(std::string&& inputStream){
    tokenString = std::move(inputStream);
  }
   
  void setTokenGeneralType(tokenType newTokenGeneralType){
    tokenGeneralType = newTokenGeneralType;
  }

  void setTokenSpecificType(tokenType newTokenSpecificType){
    tokenSpecificType = newTokenSpecificType;
  }

  void setTokenString(std::string& newTokenString){
    tokenString = newTokenString;
  }

  void setLineOccurence(int newLineOccurence){
    lineOccurence = newLineOccurence;
  }



  std::string getTokenString(){
    return tokenString;
  }

  tokenType getTokenGeneralType(){
    return tokenGeneralType;
  }

  tokenType getTokenSpecificType(){
    return tokenSpecificType;
  }

  std::string getStringGeneralTokenType(){
    return tokenClassStringMapGlobalInstance.getStringifiedEnum(tokenGeneralType);
  }

  std::string getStringSpecificTokenType(){
    return tokenClassStringMapGlobalInstance.getStringifiedEnum(tokenSpecificType);
  }

  size_t getStandingLineOccurrence(){
    return lineOccurence;
  }

  void displayElements(){
    std::cout << "[" << getStringGeneralTokenType() << ", " << getStringSpecificTokenType() << "]: "<< tokenString << '\n';
  }
};





class AbstractTokenBuilder{
public:
  virtual void buildTokenPars(std::string& someName, long unsigned int lineOccurence, std::shared_ptr<Token> someToken) = 0;

  std::shared_ptr<Token> getToken(std::string& tokenName){  
    std::shared_ptr<Token> tokenProduct = std::make_shared<Token>(tokenName);
    return tokenProduct; 
  }

  std::shared_ptr<Token> getToken(){
    std::shared_ptr<Token> tokenProduct = std::make_shared<Token>();
    return tokenProduct; 
  }
};





class TokenStringBuilder : public AbstractTokenBuilder{
  void buildTokenPars(std::string& tokenName, size_t lineOccurence, std::shared_ptr<Token> tokenProduct) override{
    tokenProduct -> setTokenString(tokenName);
    tokenProduct -> setTokenGeneralType(tokenType :: STRING);
    tokenProduct -> setLineOccurence(lineOccurence);
  }
};

class TokenLiteralBuilder : public AbstractTokenBuilder{
  void buildTokenPars(std::string& tokenName, size_t lineOccurence, std::shared_ptr<Token> tokenProduct) override{
    tokenProduct -> setTokenString(tokenName);
    tokenProduct -> setTokenGeneralType(tokenType :: LITERAL);
    tokenProduct -> setLineOccurence(lineOccurence);
  }
};

class TokenSeparatorBuilder : public AbstractTokenBuilder{
  void buildTokenPars(std::string& tokenName, size_t lineOccurence, std::shared_ptr<Token> tokenProduct) override{
    tokenProduct -> setTokenString(tokenName);
    tokenProduct -> setTokenGeneralType(tokenType :: SEPARATOR);
    tokenProduct -> setLineOccurence(lineOccurence);
  }
};

class TokenOperatorBuilder : public AbstractTokenBuilder{
  void buildTokenPars(std::string& tokenName, size_t lineOccurence, std::shared_ptr<Token> tokenProduct) override{
    tokenProduct -> setTokenString(tokenName);
    tokenProduct -> setTokenGeneralType(tokenType :: OPERATOR);
    tokenProduct -> setLineOccurence(lineOccurence);
  }
};

class TokenKeywordBuilder : public AbstractTokenBuilder{
void buildTokenPars(std::string& tokenName, size_t lineOccurence, std::shared_ptr<Token> tokenProduct) override{
    tokenProduct -> setTokenString(tokenName);
    tokenProduct -> setTokenGeneralType(tokenType :: KEYWORD);
    tokenProduct -> setLineOccurence(lineOccurence);
  }
};

class TokenConstantBuilder : public AbstractTokenBuilder{
void buildTokenPars(std::string& tokenName, size_t lineOccurence, std::shared_ptr<Token> tokenProduct) override{
    tokenProduct -> setTokenString(tokenName);
    tokenProduct -> setTokenGeneralType(tokenType :: CONSTANT);
    tokenProduct -> setLineOccurence(lineOccurence);
  }
};





class TokenDirectorSingleton{
private:
  TokenDirectorSingleton(){};
  static TokenDirectorSingleton globalInstance;
 
public:
  // CREATING A NORMAL TOKEN FOR LITERALS
  std::shared_ptr<Token> buildToken(std::string& tokenName, int lineOccurrence, std::shared_ptr<AbstractTokenBuilder> someBuilder){
    auto createdToken = someBuilder -> getToken();
    //std::cout << "Token Name: " << tokenName << '\n';
    someBuilder -> buildTokenPars(tokenName, lineOccurrence, createdToken);
    return createdToken;
  }

  static TokenDirectorSingleton& getGlobalInstance(){
    return globalInstance;
  }
};


//Initialize once, use forever ...
extern TokenDirectorSingleton& directorObject;





class SingletonData{
private:
  static SingletonData globalInstance;

  SingletonData(){}

  std::unordered_map<std::string, std::shared_ptr<AbstractTokenBuilder>> specialTokensMap;

public:  
  static SingletonData& getGlobalInstance(){
    return globalInstance;
  }
 
  void addBuiltinToken(std::string tokenBuiltinName, std::shared_ptr<AbstractTokenBuilder> tokenBuiltinBuilder){ // THIS MAY CAUSE THE INPUT TO GO UNDETECTED
    //std::cout << tokenBuiltinName << " " << "HEEEEEEEEEEEREEEEEEEEEEEEE\n";
    specialTokensMap[tokenBuiltinName] = tokenBuiltinBuilder;
  }

  bool isExists(std::string tokenString){
    //std::cout << "This is the string that is to be analyzed: "<< tokenString << '\n';
    //std::cout << "MAP HAS A SIZE OF " << specialTokensMap.size() << "\n";
    if(specialTokensMap.count(tokenString)){
      return true;
    }
    //std::cout << tokenString << " is not an operator or separator\n";
    return false;
  }

  std::shared_ptr<AbstractTokenBuilder> getTokenBuiltinBuilder(std::string& tokenString){
    if(specialTokensMap.count(tokenString)){
      return specialTokensMap[tokenString];
    }
    return nullptr;
  }

  void displayBuiltinTokens(){
    int currIndex = 1; for(const auto& pair: specialTokensMap){
      std::cout << currIndex << "STRING VALUE: "<< pair.first << '\t' << "IS MAPPED WITH: ";
      std::cout << pair.second << '\n';
      currIndex ++;
    }
  }
};


// Intialize once, use forever ...
extern SingletonData& builtInTokensData; 





class Script{
private:
  size_t counterIndex = 0;
  size_t lineCounter = 1;

  std::string stringBuffer;

  std::deque<std::shared_ptr<Token>> tokenizedOutput; 

public:
  void lex(){
    firstPhaseLex();   // CLASSIFIES INTO (LITERALS, SEPARATORS, OPERATORS, STRINGS)
    //secondPhaseLex();  // REMOVES COMMENTS
    thirdPhaseLex();   // CLASSIFIES KEYWORDS 
    fourthPhaseLex();  // NUMBER CREATOR
    fifthPhaseLex();   // MERGER
  }

  void firstPhaseLex(){
    firstPhaseStartState();
  }

  //void secondPhaseLex(){
  //  counterIndex = 0;
  //  secondPhaseStartState();
  //}
  
  void thirdPhaseLex(){
    classifyKeywords();
  }
  void fourthPhaseLex(){
    classifyToNums();
  }

  Script(){};  

  void setInputAndTokenStream(std::string&& inputStringBuffer, std::deque<std::shared_ptr<Token>>&& tokenStream){
    stringBuffer = std::move(inputStringBuffer);
    tokenizedOutput = std::move(tokenStream);
  }
  
  // EXISTS ONLY FOR INTERPRETER DEBUGGING 
  void displayTokenizedOutput(){
    for(size_t i = 0; i < tokenizedOutput.size(); i++){
      std::cout << "TOKEN: " << i;
      tokenizedOutput[i] -> displayElements();
    }
  }

  void logTokenizedOutput(std::string& filePath){
    std::ofstream outputFile(filePath, std::ios::trunc);

    if(outputFile.is_open()){
      for(std::shared_ptr<Token> token : tokenizedOutput){ 
        outputFile << token -> getTokenString() << '\n';
      }
      outputFile.close();
    }
    else{
      std::cout << "File name or path is incorrect >> " << filePath << std::endl;
    }
  }

  


  
  std::deque<std::shared_ptr<Token>> getTokenDeque(){
    return std::move(tokenizedOutput);
  }



private:
  size_t getIndex(){
    return counterIndex;
  }
  
  size_t getStandingLine(){
    return lineCounter;
  }
  
  std::deque<std::shared_ptr<Token>>* getTokenizedOutput(){
    return &tokenizedOutput;
  }

  void addToTokenizedOutput(std::shared_ptr<Token> newToken){
    tokenizedOutput.push_back(newToken);
  }
  


  std::string tempStringPhase1 = "";
  std::string tempStringPhase2 = "";



  

  void createAndAddOperatorOrSeparatorPhase1(){
    if(counterIndex >= stringBuffer.size()) return;
    std::string temp = std::string(1, stringBuffer[counterIndex]);
    std::shared_ptr<AbstractTokenBuilder> tempBuilder = builtInTokensData.getTokenBuiltinBuilder(temp);
    tokenizedOutput.push_back(directorObject.buildToken(temp, getStandingLine(), tempBuilder));
  }

  void createAndAddLiteralTokenPhase1(){
    std::shared_ptr<AbstractTokenBuilder> tempBuilder = std::make_shared<TokenLiteralBuilder>();
    tokenizedOutput.push_back(directorObject.buildToken(tempStringPhase1, getStandingLine(), tempBuilder));
  }

  void createAndAddStringTokenPhase1(){
    std::shared_ptr<TokenStringBuilder> tempBuilder = std::make_shared<TokenStringBuilder>();
    tokenizedOutput.push_back(directorObject.buildToken(tempStringPhase1, getStandingLine(), tempBuilder));
  }



  

  bool returnTrueIfSeparatorOrOperator(){
    std::string currChar = std::string(1, stringBuffer[counterIndex]);
    if(builtInTokensData.isExists(currChar)){
      return true;
    }
    //std::cout << stringBuffer[counterIndex] << " is not an operator or separator.\n";
    return false;
  }

  bool isComment = false;

  void firstPhaseStartState(){
    if(counterIndex >= stringBuffer.length()){
      return;
    }

    if(stringBuffer[counterIndex] == '/'){
      if(counterIndex + 1 < stringBuffer.size() 
        && (stringBuffer[counterIndex + 1] == '/' 
        || stringBuffer[counterIndex + 1] == '*')) commentState();
      //std::cout << "or this one?\n";
      if(!isComment) createAndAddOperatorOrSeparatorPhase1();
      isComment = false;
      counterIndex ++;
      firstPhaseStartState();
    }
    else if(stringBuffer[counterIndex] == '*'){
      createAndAddOperatorOrSeparatorPhase1();
      counterIndex ++;
      firstPhaseLiteralState();
    }
    else if(stringBuffer[counterIndex] == '"'){
      firstPhaseStringState();
    }
    else if(stringBuffer[counterIndex] == '\n'){
      lineCounter ++;
      counterIndex ++;
      firstPhaseStartState();
    }
    else if(stringBuffer[counterIndex] == ' '){
      counterIndex ++;
      firstPhaseStartState();
    } 
    else if(returnTrueIfSeparatorOrOperator()){
      createAndAddOperatorOrSeparatorPhase1();
      counterIndex ++;
      firstPhaseStartState();
    }
    else{
      firstPhaseLiteralState();
    }
  }


  


  void firstPhaseLiteralState(){
    if(counterIndex >= stringBuffer.length()){
      return;
    }

    if(stringBuffer[counterIndex] == '/'){
      if(counterIndex + 1 < stringBuffer.size() 
        && (stringBuffer[counterIndex + 1] == '/' 
        || stringBuffer[counterIndex + 1] == '*')) commentState();
      
      createAndAddLiteralTokenPhase1();
      //std::cout << "this path?\n";
      if(!isComment) createAndAddOperatorOrSeparatorPhase1();
      isComment = false;
      counterIndex ++;
      tempStringPhase1 = "";
      firstPhaseStartState();
      
    }
    else if(stringBuffer[counterIndex] == '*'){
      //std::cout << "path 6\n";
      createAndAddLiteralTokenPhase1();
      createAndAddOperatorOrSeparatorPhase1();
      counterIndex ++;
      tempStringPhase1 = "";
      firstPhaseStartState();
    }
    else if(stringBuffer[counterIndex] == '"'){
      createAndAddLiteralTokenPhase1();
      tempStringPhase1 = "";
      firstPhaseStringState();
    }
    else if(stringBuffer[counterIndex] == '\n'){
      createAndAddLiteralTokenPhase1();
      lineCounter ++;
      counterIndex ++;
      tempStringPhase1 = "";
      firstPhaseStartState();
    }
    else if(stringBuffer[counterIndex] == ' '){
      createAndAddLiteralTokenPhase1();
      counterIndex ++;
      tempStringPhase1 = "";
      firstPhaseStartState();
    }
    else if(returnTrueIfSeparatorOrOperator()){
      //std::cout << "path 7\n";
      createAndAddLiteralTokenPhase1();
      createAndAddOperatorOrSeparatorPhase1();
      counterIndex ++;
      tempStringPhase1 = "";
      firstPhaseStartState();
    }
    else{
      //std::cout << stringBuffer[counterIndex] << '\n';
      tempStringPhase1.push_back(stringBuffer[counterIndex]);
      counterIndex ++;
      firstPhaseLiteralState();
    }
  }

  



  void commentState(){
    if(stringBuffer[counterIndex + 1] == '*'){
      counterIndex ++;
      counterIndex ++;
      while(counterIndex + 1 < stringBuffer.size()){
        if(stringBuffer[counterIndex] == '*' && stringBuffer[counterIndex + 1] == '/') break;
        counterIndex ++;
      }
    }
    else{
      while(counterIndex < stringBuffer.size() && stringBuffer[counterIndex] != '\n') counterIndex ++;
    }
    //std::cout << "out of comment\n";
    isComment = true;
  }



  

  void firstPhaseStringState(){
    tempStringPhase1.push_back(stringBuffer[counterIndex]);
    counterIndex ++;

    if(counterIndex >= stringBuffer.length()){
      LOGGER :: genErrorStringUnterminated(tokenizedOutput.back() -> getStandingLineOccurrence());
      return;
    }

    if(stringBuffer[counterIndex] == '\\'){
      counterIndex ++;

      if(counterIndex >= stringBuffer.length()){
        LOGGER :: genErrorStringUnterminated(tokenizedOutput.back() -> getStandingLineOccurrence());
        return;
      }

      if(stringBuffer[counterIndex] == '"'){
        tempStringPhase1.push_back(stringBuffer[counterIndex]);
      }
      else{
        tempStringPhase1.push_back('\\');
        tempStringPhase1.push_back(stringBuffer[counterIndex]);
      }

      counterIndex ++;
      firstPhaseStringState();
      return;
    }


    if(stringBuffer[counterIndex] == '"'){
      tempStringPhase1.push_back(stringBuffer[counterIndex]);
      createAndAddStringTokenPhase1();
      counterIndex ++;
      tempStringPhase1 = "";
      firstPhaseStartState();
      return;
    }
    firstPhaseStringState();
  }


  /*
  void skipCharacterState(){
    counterIndex ++;

    if(stringBuffer[counterIndex] == '"'){
      firstPhaseStringState();
      return; 
    }
    tempStringPhase1.push_back('\\');
    counterIndex ++;
  }
  */



  

  void classifyKeywords(){
    for(size_t counterIndex3 = 0; counterIndex3 < tokenizedOutput.size(); counterIndex3++){
      //if(builtInTokensData.isExists((tokenizedOutput[counterIndex3] -> getTokenString()))){
      if(builtInTokensData.isExists(tokenizedOutput[counterIndex3] -> getTokenString())
        && tokenizedOutput[counterIndex3] -> getTokenGeneralType() != tokenType :: SEPARATOR
        && tokenizedOutput[counterIndex3] -> getTokenGeneralType() != tokenType :: OPERATOR
        && tokenizedOutput[counterIndex3] -> getTokenGeneralType() != tokenType :: CONSTANT){
          tokenizedOutput[counterIndex3] -> setTokenGeneralType(tokenType :: KEYWORD);
      }
    }
  }




    
  bool isNum(std::string stringToTest){
    
    bool floatAlready = false;

    for(long unsigned int i = 0; i < stringToTest.size(); i++){
      if(isdigit(stringToTest[i])){

      }
      else if(stringToTest[i] == '.' && floatAlready == false){
        floatAlready = true; 
      }
      else{
        return false;
      }
    }
    return true;
  }





  void classifyToNums(){
    for(size_t i = 0; i < tokenizedOutput.size(); i++){
      if(isNum(tokenizedOutput[i] -> getTokenString())){
        tokenizedOutput[i] -> setTokenGeneralType(tokenType :: NUMBER);
      }
    }
  }



  std::shared_ptr<Token> createAndAddOperatorTokenPhase5(std::string& mergedTokenString){
    std::shared_ptr<TokenOperatorBuilder> tempBuilder = std::make_shared<TokenOperatorBuilder>();
    return directorObject.buildToken(mergedTokenString, getStandingLine(), tempBuilder);
  }

  std::shared_ptr<Token> createAndAddSeparatorTokenPhase5(std::string& mergedTokenString){
    std::shared_ptr<TokenSeparatorBuilder> tempBuilder = std::make_shared<TokenSeparatorBuilder>();
    return directorObject.buildToken(mergedTokenString, getStandingLine(), tempBuilder);
  }

  std::shared_ptr<Token> createAndAddKeywordTokenPhase5(std::string& mergedTokenString){
    std::shared_ptr<TokenKeywordBuilder> tempBuilder = std::make_shared<TokenKeywordBuilder>();
    return directorObject.buildToken(mergedTokenString, getStandingLine(), tempBuilder);
  }



  std::shared_ptr<Token> mergeBasedOnType(tokenType typeOfTokensToMerge, std::string& mergedTokenString){
    switch(typeOfTokensToMerge){
      case tokenType :: OPERATOR:
        return createAndAddOperatorTokenPhase5(mergedTokenString);
        break;
      case tokenType :: SEPARATOR:
        return createAndAddSeparatorTokenPhase5(mergedTokenString);
        break;
      case tokenType :: KEYWORD:
        return createAndAddKeywordTokenPhase5(mergedTokenString);
        break;
      default:
        //std::cout << "INTERPRETER DEBUGGING MESSAGE: UNKNOWN TOKEN TYPE AT mergedBasedOnType??\n";
        return nullptr;
    }
  }

  std::shared_ptr<Token> mergeIfApplies(std::shared_ptr<Token> tokenPtr1, std::shared_ptr<Token> tokenPtr2){
    std::string mergedTokenString = tokenPtr1 -> getTokenString() + tokenPtr2 -> getTokenString();
    if(builtInTokensData.isExists(mergedTokenString) && 
       tokenPtr1 -> getStringGeneralTokenType() == tokenPtr2 -> getStringGeneralTokenType()){
      // CHECK FOR WHICH TYPE OF GENERAL TOKEN TYPE IT IS  
      // THEN CLASSIFY IT AND USE IT'S BUILDER (PUT THE FUNCTION THAT DOES THAT SEPARATELY)
      return mergeBasedOnType(tokenPtr1 -> getTokenGeneralType(), mergedTokenString);  
    }
    return nullptr;
  }




  void fifthPhaseLex(){
    std::shared_ptr<Token> tokenPtr1 = nullptr; 
    std::shared_ptr<Token> tokenPtr2 = nullptr;
    std::shared_ptr<Token> tokenPtrMerged = nullptr;
    
    for(size_t i = 0; i < tokenizedOutput.size() - 1; i++){
      //std::cout << tokenizedOutput[i] -> getTokenString() << '\n';

      tokenPtr1 = tokenizedOutput[i];
      tokenPtr2 = tokenizedOutput[i + 1];

      tokenPtrMerged = mergeIfApplies(tokenPtr1, tokenPtr2); // This object was already created

      if(tokenPtrMerged != nullptr){
      
        tokenizedOutput.erase(tokenizedOutput.begin() + i + 1);
        tokenizedOutput[i] = tokenPtrMerged; 
      }
    }
  }
};












