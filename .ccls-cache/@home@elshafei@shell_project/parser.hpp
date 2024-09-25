#include <bits/stdc++.h>
#include "lexer.hpp"

// CONTEXT SENSITIVITY WILL BE ADDED IN A LATER VERSION 

enum class mainTypeExpression{
  MAJOR_EXPRESSION,
  NORMAL_STATEMENT,
  CONDITION_STATEMENT,
};





class Expression{
private: 

  std::shared_ptr<Expression> parentExpression = nullptr;

  std::vector<std::shared_ptr<Expression>> subExpressions;
  std::vector<std::shared_ptr<Token>> mathExpressionTerms; // FOR CONDITION STATEMENT
  std::vector<std::shared_ptr<Expression>> conditionExpressions;

  bool variableRedefine = false;

  std::string actionToken;
  std::shared_ptr<Token> literalToken;

  mainTypeExpression expressionType;

  long unsigned int parentLastIndex;

public:
  Expression(){}

  void addSubExpression(std::shared_ptr<Expression> newSubExpression){
    subExpressions.push_back(newSubExpression);
  }

  void addConditionExpression(std::shared_ptr<Expression> newConditionExpression){
    conditionExpressions.push_back(newConditionExpression); 
  }

  void addMathExpressionTerm(std::shared_ptr<Token> newMathTerm){
    mathExpressionTerms.push_back(newMathTerm);
  }
 


  std::shared_ptr<Expression> getSubExpressionPointer(long unsigned int currIndex){
    return subExpressions[currIndex];
  }

  std::shared_ptr<Expression> getConditionExpressionPointer(long unsigned int currIndex){
    return conditionExpressions[currIndex];
  }
  
  std::shared_ptr<Token> getMathTermPointer(long unsigned int currIndex){
    return mathExpressionTerms[currIndex];
  }

  long unsigned int getParentLastIndex(){
    return parentLastIndex;
  }

  std::shared_ptr<Expression> getParentExpressionPointer(){
    return parentExpression; 
  }



  void setExpressionType(mainTypeExpression newExpressionType){
    expressionType = newExpressionType; 
  }

  void setActionToken(std::string newActionToken){
    actionToken = newActionToken;
  }

  void setLiteralToken(std::shared_ptr<Token> newLiteralToken){
    literalToken = newLiteralToken;
  }

  void setParentExpression(std::shared_ptr<Expression> newParentExpression){
    parentExpression = newParentExpression; 
  }

  void setVariableRedefine(){
    variableRedefine = true;  
  }
};





class ParseTreeCreator{ // AKA Parse EXPRESSION Creator 

private:
  std::shared_ptr<Expression> rootExpressionPointer; 
  std::vector<std::shared_ptr<Token>> tokenStream;

  std::unordered_map<std::string, std::string> symbolVariableTable;
  std::unordered_map<std::string, std::shared_ptr<Expression>> symbolFunctionTable;

  std::shared_ptr<Expression> lastParentExpressionPointer;
  std::shared_ptr<Expression> tempStatementPointer;
  std::shared_ptr<Expression> currentExpressionNodePointer;

  long unsigned int currIndex = 0;

  void exitIfIndexOverflows(char exitCondition){
    if(currIndex >= tokenStream.size()){
      switch(exitCondition){
        case ')':
          std::cerr << "Unterminated bracket!\n";
          exit(1);
        case '}':
          std::cerr << "Unterminated brace!\n";
          exit(1);
        case ';':
          std::cerr << "Unterminated semicolon!\n";
          exit(1);
        default:
          std::cerr << "Unspecified lack of termination!\n";
          exit(1);
          break;
      }
    }
  }



  void defaultState(){
         
    if(tokenStream[currIndex] -> get_token_string() == "var" || tokenStream[currIndex] -> get_token_type() == "Literal"){
      minorStatementBegin();
      //currIndex++;
    }

    else{
      majorStatementBegin();
      //currIndex++;

    }
  }

  void minorStatementBegin(){
    if(tokenStream[currIndex] -> get_token_string() == "var" /*|| tokenStream[currIndex] -> get_token_type() == "Keyword"*/){
      tempStatementPointer = std::make_shared<Expression>(); 

      tempStatementPointer -> setExpressionType(mainTypeExpression::NORMAL_STATEMENT);
      tempStatementPointer -> setParentExpression(lastParentExpressionPointer);
   
      tempStatementPointer -> setVariableRedefine();

      lastParentExpressionPointer -> addSubExpression(tempStatementPointer);

      currIndex ++;

      exitIfIndexOverflows(';');
      
      minorStatementContinueNew();
    }

    else if(tokenStream[currIndex] -> get_token_type() == "Literal"){
      tempStatementPointer = std::make_shared<Expression>();
      
      tempStatementPointer -> setExpressionType(mainTypeExpression::NORMAL_STATEMENT);
      tempStatementPointer -> setParentExpression(lastParentExpressionPointer);
    
      lastParentExpressionPointer -> addSubExpression(tempStatementPointer);

      currIndex ++;

      exitIfIndexOverflows(';');

      minorStatementContinueOld();
    }

    else{
      // ERROR ENCOUTNERED AT PARSING
      std::cerr << "ERROR encountered at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
      std::cerr << "Expected an identifier or a new identifier declaration, and instead met a: " << tokenStream[currIndex] -> get_token_type() << '\n';
      exit(1);
    }
  }
  
 
  void minorStatementContinueNew(){
    
    if(tokenStream[currIndex] -> get_token_type() == "Literal"){
  
      tempStatementPointer -> setLiteralToken(tokenStream[currIndex]); 

      currIndex++;  
      exitIfIndexOverflows(';');

    }
    else{
      std::cerr << "ERROR encountered at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
      std::cerr << "Expected an identifier or a new identifier declaration, and instead met a: " << tokenStream[currIndex] -> get_token_type() << '\n';
      exit(1);
      //return;
    }

    
    if(tokenStream[currIndex] -> get_token_type() == "Operator"){
      currIndex++; 

      exitIfIndexOverflows(';');

    }
    else{
      std::cerr << "ERROR encountered at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
      std::cerr << "Expected a semicolon, and instead met a: " << tokenStream[currIndex] -> get_token_type() << '\n';
      exit(1);
      //return;
    }


    if(tokenStream[currIndex] -> get_token_string() == ";"){
      std::cerr << "ERROR encountered at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
      std::cerr << "Expected an right value, and instead met a semicolon\n";
      exit(1);
    }
   
    // VERY IMPORTANT TO AVOID SEGFAULTS 
    exitIfIndexOverflows(';');

    while(tokenStream[currIndex] -> get_token_string() != ";"){
      tempStatementPointer -> addMathExpressionTerm(tokenStream[currIndex]);
      currIndex++;
    
      exitIfIndexOverflows(';');
    }


    // THAT'S AN ISSUE TO BE RESOLVED IN RUNTIME 
    /*
    if(tokenStream[currIndex] -> get_token_string() == "=" || "<=" || ">=" || "!=" || ){
        
    }
    */
  }

  void minorStatementContinueOld(){
    
    if(tokenStream[currIndex] -> get_token_type() == "Operator"){
      currIndex++; 
      exitIfIndexOverflows(';');

    }
    else{
      std::cerr << "ERROR encountered at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
      std::cerr << "Expected a semicolon, and instead met a: " << tokenStream[currIndex] -> get_token_type() << '\n';
      exit(1);
      //return;
    }

    while(tokenStream[currIndex] -> get_token_string() != ";"){
      tempStatementPointer -> addMathExpressionTerm(tokenStream[currIndex]);
      currIndex++;
      
      exitIfIndexOverflows(';');

    }
  }



  void majorStatementBegin(){
    if(tokenStream[currIndex] -> get_token_string() == "for"){
      tempStatementPointer = std::make_shared<Expression>(); 
      
      tempStatementPointer -> setExpressionType(mainTypeExpression::MAJOR_EXPRESSION);
      tempStatementPointer -> setParentExpression(lastParentExpressionPointer);

      tempStatementPointer -> setActionToken("for");
    
      lastParentExpressionPointer -> addSubExpression(tempStatementPointer);
      
      currIndex ++;
      exitIfIndexOverflows('}');
      majorStatementFor();
    }

    else if(tokenStream[currIndex] -> get_token_string() == "while"){
      tempStatementPointer = std::make_shared<Expression>(); 
      
      tempStatementPointer -> setExpressionType(mainTypeExpression::MAJOR_EXPRESSION);
      tempStatementPointer -> setParentExpression(lastParentExpressionPointer);
      
      tempStatementPointer -> setActionToken("while");
    
      lastParentExpressionPointer -> addSubExpression(tempStatementPointer);
 
      currIndex ++;
      exitIfIndexOverflows('}');
      majorStatementWhile();
    }

    else if(tokenStream[currIndex] -> get_token_string() == "if"){
      tempStatementPointer = std::make_shared<Expression>(); 
      
      tempStatementPointer -> setExpressionType(mainTypeExpression::MAJOR_EXPRESSION);
      tempStatementPointer -> setParentExpression(lastParentExpressionPointer);
      
      tempStatementPointer -> setActionToken("if");
    
      lastParentExpressionPointer -> addSubExpression(tempStatementPointer);
 
      currIndex ++;
      exitIfIndexOverflows('}');
      majorStatementIf();
    }

    else if(tokenStream[currIndex] -> get_token_string() == "else if"){
      tempStatementPointer = std::make_shared<Expression>(); 
      
      tempStatementPointer -> setExpressionType(mainTypeExpression::MAJOR_EXPRESSION);
      tempStatementPointer -> setParentExpression(lastParentExpressionPointer);
      
      tempStatementPointer -> setActionToken("else if");
    
      lastParentExpressionPointer -> addSubExpression(tempStatementPointer);
 
      currIndex ++;
      exitIfIndexOverflows('}');
      majorStatementElseIf();
    }

    else if(tokenStream[currIndex] -> get_token_string() == "else"){
      tempStatementPointer = std::make_shared<Expression>(); 
      
      tempStatementPointer -> setExpressionType(mainTypeExpression::MAJOR_EXPRESSION);
      tempStatementPointer -> setParentExpression(lastParentExpressionPointer);

      tempStatementPointer -> setActionToken("else");
    
      lastParentExpressionPointer -> addSubExpression(tempStatementPointer);
 
      currIndex ++;
      exitIfIndexOverflows('}');
      majorStatementElse();
    }

    else{
      std::cerr << "THE PARSER WAS NOT SUPPOSED TO GO HERE!\n";
      exit(1);
    }
  }



  void majorStatementFor(){
    std::shared_ptr<Expression> tempConditionExpressionPointer = std::make_shared<Expression>();
    tempConditionExpressionPointer -> setExpressionType(mainTypeExpression::CONDITION_STATEMENT);
   

    tempStatementPointer -> addConditionExpression(minorStatementContinueNewFor());
    tempStatementPointer -> addConditionExpression(minorStatementContinueOldFor());
    tempStatementPointer -> addConditionExpression(minorStatementContinueOldFor());


    //evaluateInnerForLoop();

    /*
    if(tokenStream[currIndex] -> get_token_string() == "("){
      currIndex ++;
    }
    else{
      std::cerr << "Expected start condition statement with ( at line : " << tokenStream[currIndex] -> get_line_occurence() << '\n';
      std::cerr << "Instead, was met with: " << tokenStream[currIndex] -> get_token_string() << '\n';
      exit(1);
    }


    if(tokenStream[currIndex] -> get_token_string() == "var"){
      currIndex ++;
    }
    else{
      std::cerr << "Expected start condition statement with var at line : " << tokenStream[currIndex] -> get_line_occurence() << '\n';
      std::cerr << "Instead, was met with: " << tokenStream[currIndex] -> get_token_string() << '\n';
      exit(1);
    }


    if(tokenStream[currIndex] -> get_token_string() == "="){
      currIndex ++;
    }
    else{
      std::cerr << "Expected start condition statement with = at line : " << tokenStream[currIndex] -> get_line_occurence() << '\n';
      std::cerr << "Instead, was met with: " << tokenStream[currIndex] -> get_token_string() << '\n';
      exit(1);
    }


    // THE NUMBER WILL NEED TO BE CHECKED LATER
    if(tokenStream[currIndex] -> get_token_type() == "Literal" || tokenStream[currIndex] -> get_token_type() == "Number"){
      currIndex ++;
    }
    else{
      std::cerr << "Expected a number for start condition on line : " << tokenStream[currIndex] -> get_line_occurence() << '\n';
      std::cerr << "Instead, was met with: " << tokenStream[currIndex] -> get_token_string() << '\n';
      exit(1);
    }
  */

  }

  std::shared_ptr<Expression> minorStatementContinueNewFor(){

    std::shared_ptr<Expression> forTempStatementPointer; 
    
    if(tokenStream[currIndex] -> get_token_type() == "Literal"){
      currIndex++;  
      exitIfIndexOverflows(';');

    }
    else{
      std::cerr << "ERROR encountered at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
      std::cerr << "Expected an identifier or a new identifier declaration, and instead met a: " << tokenStream[currIndex] -> get_token_type() << '\n';
      exit(1);
      //return;
    }

    
    if(tokenStream[currIndex] -> get_token_type() == "Operator"){
      currIndex++; 

      exitIfIndexOverflows(';');

    }
    else{
      std::cerr << "ERROR encountered at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
      std::cerr << "Expected a semicolon, and instead met a: " << tokenStream[currIndex] -> get_token_type() << '\n';
      exit(1);
      //return;
    }


    if(tokenStream[currIndex] -> get_token_string() == ";"){
      std::cerr << "ERROR encountered at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
      std::cerr << "Expected an right value, and instead met a semicolon\n";
      exit(1);
    }
   
    // VERY IMPORTANT TO AVOID SEGFAULTS 
    exitIfIndexOverflows(';');

    while(tokenStream[currIndex] -> get_token_string() != ";"){
      forTempStatementPointer -> addMathExpressionTerm(tokenStream[currIndex]);
      currIndex++;
    
      exitIfIndexOverflows(';');
    }
    return forTempStatementPointer;
  }




  std::shared_ptr<Expression> minorStatementContinueOldFor(){
    
    std::shared_ptr<Expression> forTempStatementPointer;

    if(tokenStream[currIndex] -> get_token_type() == "Operator"){
      currIndex++; 
      exitIfIndexOverflows(';');

    }
    else{
      std::cerr << "ERROR encountered at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
      std::cerr << "Expected a semicolon, and instead met a: " << tokenStream[currIndex] -> get_token_type() << '\n';
      exit(1);
      //return;
    }

    while(tokenStream[currIndex] -> get_token_string() != ";"){
      forTempStatementPointer -> addMathExpressionTerm(tokenStream[currIndex]);
      currIndex++;
      
      exitIfIndexOverflows(';');
    }
    return forTempStatementPointer;
  }




  void majorStatementWhile(){
    
  }

  void majorStatementIf(){

  }

  void majorStatementElseIf(){

  }

  void majorStatementElse(){

  }

  public: 

  void startCreateTree(std::vector<std::shared_ptr<Token>>* newTokenStreamPointer){
    rootExpressionPointer = std::make_shared<Expression>();
    lastParentExpressionPointer = rootExpressionPointer;
    tokenStream = *newTokenStreamPointer;
    defaultState();
  }

  std::shared_ptr<Expression> getTree(){
    return rootExpressionPointer;
  }

  

















};
