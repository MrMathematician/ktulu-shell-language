#include <bits/stdc++.h>
#include "../logger/logger.hpp"
# pragma once

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
  std::unordered_map<tokenType, const char*> tokenEnumStringMap; // CONST CHAR MAY CAUSE AN ERROR HERE (IT DIDN'T)

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
  Token(std::string newTokenString){
    tokenString = newTokenString; 
  }

  Token(){}


   
  void setTokenGeneralType(tokenType newTokenGeneralType){
    tokenGeneralType = newTokenGeneralType;
  }

  void setTokenSpecificType(tokenType newTokenSpecificType){
    tokenSpecificType = newTokenSpecificType;
  }

  void setTokenString(std::string newTokenString){
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

  long unsigned int getStandingLineOccurrence(){
    return lineOccurence;
  }

  void displayElements(){
    std::cout << "[" << getStringGeneralTokenType() << ", " << getStringSpecificTokenType() << "]: "<< tokenString << '\n';
  }
};





class AbstractTokenBuilder{
public:
  virtual void buildTokenPars(const char* someName, long unsigned int lineOccurence, std::shared_ptr<Token> someToken) = 0;

  std::shared_ptr<Token> getToken(const char* tokenName){  
    std::shared_ptr<Token> tokenProduct = std::make_shared<Token>(tokenName);
    return tokenProduct; 
  }

  std::shared_ptr<Token> getToken(){
    std::shared_ptr<Token> tokenProduct = std::make_shared<Token>();
    return tokenProduct; 
  }
};





class TokenStringBuilder : public AbstractTokenBuilder{
  void buildTokenPars(const char* tokenName, size_t lineOccurence, std::shared_ptr<Token> tokenProduct) override{
    tokenProduct -> setTokenString(tokenName);
    tokenProduct -> setTokenGeneralType(tokenType :: STRING);
    tokenProduct -> setLineOccurence(lineOccurence);
  }
};

class TokenLiteralBuilder : public AbstractTokenBuilder{
  void buildTokenPars(const char* tokenName, size_t lineOccurence, std::shared_ptr<Token> tokenProduct) override{
    tokenProduct -> setTokenString(tokenName);
    tokenProduct -> setTokenGeneralType(tokenType :: LITERAL);
    tokenProduct -> setLineOccurence(lineOccurence);
  }
};

class TokenSeparatorBuilder : public AbstractTokenBuilder{
  void buildTokenPars(const char* tokenName, size_t lineOccurence, std::shared_ptr<Token> tokenProduct) override{
    tokenProduct -> setTokenString(tokenName);
    tokenProduct -> setTokenGeneralType(tokenType :: SEPARATOR);
    tokenProduct -> setLineOccurence(lineOccurence);
  }
};

class TokenOperatorBuilder : public AbstractTokenBuilder{
void buildTokenPars(const char* tokenName, size_t lineOccurence, std::shared_ptr<Token> tokenProduct) override{
    tokenProduct -> setTokenString(tokenName);
    tokenProduct -> setTokenGeneralType(tokenType :: OPERATOR);
    tokenProduct -> setLineOccurence(lineOccurence);
  }
};

class TokenKeywordBuilder : public AbstractTokenBuilder{
void buildTokenPars(const char* tokenName, size_t lineOccurence, std::shared_ptr<Token> tokenProduct) override{
    tokenProduct -> setTokenString(tokenName);
    tokenProduct -> setTokenGeneralType(tokenType :: KEYWORD);
    tokenProduct -> setLineOccurence(lineOccurence);
  }
};

class TokenConstantBuilder : public AbstractTokenBuilder{
void buildTokenPars(const char* tokenName, size_t lineOccurence, std::shared_ptr<Token> tokenProduct) override{
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
  std::shared_ptr<Token> buildToken(const char* tokenName, int lineOccurrence, std::shared_ptr<AbstractTokenBuilder> someBuilder){
    auto createdToken = someBuilder -> getToken();
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

private: 
  std::unordered_map<std::string, std::shared_ptr<AbstractTokenBuilder>> specialTokensMap;

public:  
  static SingletonData& getGlobalInstance(){
    return globalInstance;
  }
 
  void addBuiltinToken(const char* tokenBuiltinName, std::shared_ptr<AbstractTokenBuilder> tokenBuiltinBuilder){ // THIS MAY CAUSE THE INPUT TO GO UNDETECTED
    specialTokensMap[tokenBuiltinName] = tokenBuiltinBuilder;
  }

  bool isExists(const char* tokenString){
    //std::cout << "This is the string that is to be analyzed: "<< tokenString << '\n';
    if(specialTokensMap.count(tokenString)){
      return true;
    }
    return false;
  }

  std::shared_ptr<AbstractTokenBuilder> getTokenBuiltinBuilder(const char* tokenString){
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
  size_t counterIndexPhase1 = 0;
  size_t counterIndexPhase2 = 0;
  size_t lineCounter = 1;

  std::string stringBuffer;

  std::vector<std::shared_ptr<Token>> tokenizedOutput;  // stack allocated, DO NOT USE SHARED_PTRS
  std::vector<std::shared_ptr<Token>> semiTokenizedOutput; // stack allocated, DO NOT USE SHARED_PTRS

public:
  void lex(){
    firstPhaseLex(); // CLASSIFIES INTO (LITERALS, SEPARATORS, OPERATORS, STRINGS)
    secondPhaseLex(); // REMOVES COMMENTS
    thirdPhaseLex(); // CLASSIFIES KEYWORDS 
    fourthPhaseLex(); // NUMBER CREATOR
    fifthPhaseLex();  // MERGER
  }

  void firstPhaseLex(){
    firstPhaseStartState();
  }

  void secondPhaseLex(){
    secondPhaseStartState();
  }

  void thirdPhaseLex(){
    classifyKeywords();
  }
  void fourthPhaseLex(){
    classifyToNums();
  }

  Script(const char* newStringBuffer){
    stringBuffer = newStringBuffer;
  }  

  Script(){}

  void displayTokenizedOutput(){
    for(size_t i = 0; i < tokenizedOutput.size(); i++){
      std::cout << "TOKEN: " << i;
      tokenizedOutput[i] -> displayElements();
    }
  }
  
  void set_buffer_string(std::string newStringBuffer){
    stringBuffer = newStringBuffer;
  }
  std::string get_stringBuffer(){
    return stringBuffer;  
  }

  std::vector<std::shared_ptr<Token>>* getTokenVectorPointer(){
    return &tokenizedOutput;
  }



private:
  size_t getIndex(){
    return counterIndexPhase1;
  }
  
  size_t getStandingLine(){
    return lineCounter;
  }
  
  std::vector<std::shared_ptr<Token>> getTokenizedOutput(){
    return tokenizedOutput;
  }

  void addToTokenizedOutput(std::shared_ptr<Token> newToken){
    tokenizedOutput.push_back(newToken);
  }
  


  std::string tempStringPhase1 = "";
  std::string tempStringPhase2 = "";



  

  void createAndAddOperatorOrSeparatorPhase1(){
    std::shared_ptr<AbstractTokenBuilder> tempBuilder = builtInTokensData.getTokenBuiltinBuilder(std::string(1, stringBuffer[counterIndexPhase1]).c_str());
    semiTokenizedOutput.push_back(directorObject.buildToken(std::string(1, stringBuffer[counterIndexPhase1]).c_str(), getStandingLine(), tempBuilder));
  }

  void createAndAddLiteralTokenPhase1(){
    std::shared_ptr<AbstractTokenBuilder> tempBuilder = std::make_shared<TokenLiteralBuilder>();
    semiTokenizedOutput.push_back(directorObject.buildToken(tempStringPhase1.c_str(), getStandingLine(), tempBuilder));
  }

  void createAndAddStringTokenPhase1(){
    std::shared_ptr<TokenStringBuilder> tempBuilder = std::make_shared<TokenStringBuilder>();
    semiTokenizedOutput.push_back(directorObject.buildToken(tempStringPhase1.c_str(), getStandingLine(), tempBuilder));
  }



  

  bool returnTrueIfSeparatorOrOperator(){
    const char currChar = stringBuffer[counterIndexPhase1];
    if(builtInTokensData.isExists(&currChar)){
      return true;
    }
    return false;
  }



  void firstPhaseStartState(){
    if(counterIndexPhase1 >= stringBuffer.length()){
      //counterIndexPhase1 = 0;
      return;
    }

    if(stringBuffer[counterIndexPhase1] == '/'){
      createAndAddOperatorOrSeparatorPhase1();
      counterIndexPhase1 ++;
      firstPhaseLiteralState();
    }
    else if(stringBuffer[counterIndexPhase1] == '*'){
      createAndAddOperatorOrSeparatorPhase1();
      counterIndexPhase1 ++;
      firstPhaseLiteralState();
    }
    else if(stringBuffer[counterIndexPhase1] == '"'){
      firstPhaseStringState();
    }
    else if(stringBuffer[counterIndexPhase1] == '\n'){
      lineCounter ++;
      counterIndexPhase1 ++;
      firstPhaseStartState();
    }
    else if(stringBuffer[counterIndexPhase1] == ' '){
      counterIndexPhase1 ++;
      firstPhaseStartState();
    } 
    else if(returnTrueIfSeparatorOrOperator()){
      createAndAddOperatorOrSeparatorPhase1();
      counterIndexPhase1 ++;
      firstPhaseStartState();
    }
    else{
      firstPhaseLiteralState();
    }
  }





  void firstPhaseLiteralState(){
    if(counterIndexPhase1 >= stringBuffer.length()){
      return;
    }

    if(stringBuffer[counterIndexPhase1] == '/'){
      createAndAddLiteralTokenPhase1();
      createAndAddOperatorOrSeparatorPhase1();
      counterIndexPhase1 ++;
      tempStringPhase1 = "";
      firstPhaseStartState();
    }
    else if(stringBuffer[counterIndexPhase1] == '*'){
      createAndAddLiteralTokenPhase1();
      createAndAddOperatorOrSeparatorPhase1();
      counterIndexPhase1 ++;
      tempStringPhase1 = "";
      firstPhaseStartState();
    }
    else if(stringBuffer[counterIndexPhase1] == '"'){
      createAndAddLiteralTokenPhase1();
      tempStringPhase1 = "";
      firstPhaseStringState();
    }
    else if(stringBuffer[counterIndexPhase1] == '\n'){
      createAndAddLiteralTokenPhase1();
      lineCounter ++;
      counterIndexPhase1 ++;
      tempStringPhase1 = "";
      firstPhaseStartState();
    }
    else if(stringBuffer[counterIndexPhase1] == ' '){
      createAndAddLiteralTokenPhase1();
      counterIndexPhase1 ++;
      tempStringPhase1 = "";
      firstPhaseStartState();
    }
    else if(returnTrueIfSeparatorOrOperator()){
      createAndAddLiteralTokenPhase1();
      createAndAddOperatorOrSeparatorPhase1();
      counterIndexPhase1 ++;
      tempStringPhase1 = "";
      firstPhaseStartState();
    }
    else{
      tempStringPhase1.push_back(stringBuffer[counterIndexPhase1]);
      counterIndexPhase1 ++;
      firstPhaseLiteralState();
    }
  }





  void firstPhaseStringState(){
    if(counterIndexPhase1 >= stringBuffer.length()){
      LOGGER :: genErrorStringUnterminated(getStandingLine());
      return;
    }

    // IN A FUTURE VERSION, INNER DOUBLE QUOTATION WITH ESCAPE SLASH WILL BE ADDED
    tempStringPhase1.push_back(stringBuffer[counterIndexPhase1]);
    counterIndexPhase1 ++;

    if(stringBuffer[counterIndexPhase1] == '"'){
      tempStringPhase1.push_back(stringBuffer[counterIndexPhase1]);
      createAndAddStringTokenPhase1();
      counterIndexPhase1 ++;
      tempStringPhase1 = "";
      firstPhaseStartState();
      return;
    }
    firstPhaseStringState();
  }





  void secondPhaseStartState(){
    if(counterIndexPhase2 >= semiTokenizedOutput.size()){
      return;
    }

    if(semiTokenizedOutput[counterIndexPhase2] -> getTokenString() == "/"){
      counterIndexPhase2 ++;
      if(counterIndexPhase2 >= semiTokenizedOutput.size()){
        return;
      }

      if(semiTokenizedOutput[counterIndexPhase2] -> getTokenString() == "*"){
        counterIndexPhase2 ++;
        blockCommentState();
      }
      else if(semiTokenizedOutput[counterIndexPhase2] -> getTokenString() == "/"){
        counterIndexPhase2 ++;
        lineCommentState();
      }
      else{
        tokenizedOutput.push_back(semiTokenizedOutput[counterIndexPhase2 - 1]);
        tokenizedOutput.push_back(semiTokenizedOutput[counterIndexPhase2]);
        counterIndexPhase2 ++;
        secondPhaseStartState();
      }
    }
    else{
      tokenizedOutput.push_back(semiTokenizedOutput[counterIndexPhase2]);
      counterIndexPhase2 ++;
      secondPhaseStartState();
    }
  }



  

  void blockCommentState(){
    if(counterIndexPhase2 >= semiTokenizedOutput.size()){
      return;
    }

    if(semiTokenizedOutput[counterIndexPhase2] -> getTokenString() == "*"){
      counterIndexPhase2 ++;
      if(counterIndexPhase2 >= semiTokenizedOutput.size()){
        return;
      }
      
      if(semiTokenizedOutput[counterIndexPhase2] -> getTokenString() == "/"){
        counterIndexPhase2 ++;
        secondPhaseStartState();
      }
      else{
        counterIndexPhase2 ++;
        blockCommentState();
      }
    }
  }





  void lineCommentState(){
    if(semiTokenizedOutput[counterIndexPhase2] -> getTokenString() == "\n"){
      counterIndexPhase2 ++;
      secondPhaseStartState();
    }
  }
 




  void classifyKeywords(){
    for(size_t counterIndexPhase3 = 0; counterIndexPhase3 < tokenizedOutput.size(); counterIndexPhase3++){
      //if(builtInTokensData.isExists((tokenizedOutput[counterIndexPhase3] -> getTokenString()))){
      if(builtInTokensData.isExists(tokenizedOutput[counterIndexPhase3] -> getTokenString().c_str())
        && tokenizedOutput[counterIndexPhase3] -> getTokenGeneralType() != tokenType :: SEPARATOR
        && tokenizedOutput[counterIndexPhase3] -> getTokenGeneralType() != tokenType :: OPERATOR
        && tokenizedOutput[counterIndexPhase3] -> getTokenGeneralType() != tokenType :: CONSTANT){
          tokenizedOutput[counterIndexPhase3] -> setTokenGeneralType(tokenType :: KEYWORD);
      }
    }
  }




    
  bool isNum(const char* stringToTest){
    
    bool floatAlready = false;

    for(long unsigned int i = 0; i < strlen(stringToTest); i++){
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
      if(isNum(tokenizedOutput[i] -> getTokenString().c_str())){
        tokenizedOutput[i] -> setTokenGeneralType(tokenType :: NUMBER);
      }
    }
  }



  std::shared_ptr<Token> createAndAddOperatorTokenPhase5(const char* mergedTokenString){
    std::shared_ptr<TokenOperatorBuilder> tempBuilder = std::make_shared<TokenOperatorBuilder>();
    return directorObject.buildToken(mergedTokenString, getStandingLine(), tempBuilder);
  }

  std::shared_ptr<Token> createAndAddSeparatorTokenPhase5(const char* mergedTokenString){
    std::shared_ptr<TokenSeparatorBuilder> tempBuilder = std::make_shared<TokenSeparatorBuilder>();
    return directorObject.buildToken(mergedTokenString, getStandingLine(), tempBuilder);
  }

  std::shared_ptr<Token> createAndAddKeywordTokenPhase5(const char* mergedTokenString){
    std::shared_ptr<TokenKeywordBuilder> tempBuilder = std::make_shared<TokenKeywordBuilder>();
    return directorObject.buildToken(mergedTokenString, getStandingLine(), tempBuilder);
  }



  std::shared_ptr<Token> mergeBasedOnType(tokenType typeOfTokensToMerge, const char* mergedTokenString){
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
        std::cout << "DEBUGGING MESSAGE: UNKNOWN TOKEN TYPE AT mergedBasedOnType??\n";
        return nullptr;
    }
  }

  std::shared_ptr<Token> mergeIfApplies(std::shared_ptr<Token> tokenPtr1, std::shared_ptr<Token> tokenPtr2){
    std::string mergedTokenString = tokenPtr1 -> getTokenString() + tokenPtr2 -> getTokenString();
    if(builtInTokensData.isExists(mergedTokenString.c_str()) && 
       tokenPtr1 -> getStringGeneralTokenType() == tokenPtr2 -> getStringGeneralTokenType()){
      // CHECK FOR WHICH TYPE OF GENERAL TOKEN TYPE IT IS  
      // THEN CLASSIFY IT AND USE IT'S BUILDER (PUT THE FUNCTION THAT DOES THAT SEPARATELY)
      return mergeBasedOnType(tokenPtr1 -> getTokenGeneralType(), mergedTokenString.c_str());  
    }
    return nullptr;
  }




  void fifthPhaseLex(){
    std::shared_ptr<Token> tokenPtr1 = nullptr; 
    std::shared_ptr<Token> tokenPtr2 = nullptr;
    std::shared_ptr<Token> tokenPtrMerged = nullptr;
    
    for(size_t i = 0; i < tokenizedOutput.size() - 1; i++){

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












