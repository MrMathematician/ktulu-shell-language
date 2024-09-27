#include <bits/stdc++.h>
#include "lexer.hpp"

enum class mainTypeExpression{
  MAJOR_EXPRESSION,
  NORMAL_STATEMENT,
  CONDITION_STATEMENT,
};

class NumMaker{
private:
  std::vector<std::shared_ptr<Token>>* tokenOutputPtr;
 
  std::shared_ptr<Token> tokenToCheck;

  bool isNum(){
    for(long unsigned int i = 0; i < tokenToCheck -> get_token_string().length(); i++){
      if(!std::isdigit(tokenToCheck -> get_token_string()[i])){
        return false;
      }
    }
    return true;
  }

public:
  void checkNumOrLiteral(std::shared_ptr<Script> scriptToParse){

    tokenOutputPtr = scriptToParse -> get_token_vector_pointer();
    
    for(long unsigned int i = 0; i < tokenOutputPtr -> size(); i++){
      tokenToCheck = tokenOutputPtr -> at(i);
      if(isNum()){
        tokenToCheck -> set_token_type("Number");
      }
    }
  }
};


/*
class BraceAndBracketChecker{
  std::shared_ptr<Token> checkBalanceOfBracket(std::shared_ptr<Script> scriptToCheck){
    // YOU ARE SUPPOSED TO USE LONG UNSIGNED INT. BUT I DON'T HAVE TIME TO DEAL WITH OVERFLOWS    
    int bracketBalance = 0;
    std::vector<std::shared_ptr<Token>>* tokenVectorPointer = scriptToCheck -> get_token_vector_pointer();
    std::shared_ptr<Token> caughtToken;
    for(long unsigned int i = 0; i < scriptToCheck -> get_token_vector_pointer() -> size(); i++){

      caughtToken = tokenVectorPointer -> at(i);

      if(bracketBalance < 0){
        return caughtToken;
      }
      else if(caughtToken -> get_token_string() == "("){
        bracketBalance ++;
      }
      else if(caughtToken -> get_token_string() == ")"){
        bracketBalance --;
      }
    }

    if(bracketBalance != 0){
      return caughtToken;
    }
    return nullptr;
  }

  
  std::shared_ptr<Token> checkBalanceOfBraces(std::shared_ptr<Script> scriptToCheck){
    // YOU ARE SUPPOSED TO USE LONG UNSIGNED INT. BUT I DON'T HAVE TIME TO DEAL WITH OVERFLOWS    
    int bracketBalance = 0;
    std::vector<std::shared_ptr<Token>>* tokenVectorPointer = scriptToCheck -> get_token_vector_pointer();
    std::shared_ptr<Token> caughtToken;
    for(long unsigned int i = 0; i < scriptToCheck -> get_token_vector_pointer() -> size(); i++){

      caughtToken = tokenVectorPointer -> at(i);

      if(bracketBalance < 0){
        return caughtToken;
      }
      else if(caughtToken -> get_token_string() == "{"){
        bracketBalance ++;
      }
      else if(caughtToken -> get_token_string() == "}"){
        bracketBalance --;
      }
    }

    if(bracketBalance != 0){
      return caughtToken;
    }
    return nullptr;
  }
  
};
*/




class GeneralExpression{
public:

  std::shared_ptr<GeneralExpression> lastParentExpression;
  std::string typeName;

  std::vector<std::shared_ptr<GeneralExpression>> expressionBody; 

  void addSubExpression(std::shared_ptr<GeneralExpression> newSubExpression){
    expressionBody.push_back(newSubExpression);
  }

  void setLastParentExpression(std::shared_ptr<GeneralExpression> newLastParentExpression){
    lastParentExpression = newLastParentExpression;
  }
};


class Expression : public GeneralExpression{
public:

  std::vector<std::shared_ptr<Token>> expressionElements;

  void addElement(std::shared_ptr<Token> newElement){
    expressionElements.push_back(newElement);
  }
  

  Expression(){
    typeName = "EXPRESSION";
  }
};


class Action : public GeneralExpression{
public:
  std::string actionToDo;
  std::vector<std::shared_ptr<Token>> operands;

  void addElement(std::shared_ptr<Token> newElement){
    operands.push_back(newElement);
  }

  Action(){
    typeName = "Action";
  }
};


class MINOR_STATEMENT : public GeneralExpression{
public:
  bool createNewVar = false;
  std::string variableName;
  std::vector<std::shared_ptr<Token>> attributedValue;

  MINOR_STATEMENT(){
    typeName = "MINOR_STATEMENT";
  }
};

/*
class MAIN_BODY : public GeneralExpression{
public:
  std::vector<std::shared_ptr<GeneralExpression>> mainBodyVector;
  
};
*/

class FUNCTION : public GeneralExpression{ // FUNCTIONS DO NOT HAVE PARENTS
public:
  std::vector<std::shared_ptr<Token>> parameters;  
  //std::vector<std::shared_ptr<GeneralExpression>> functionBody;
  //
  void addParameter(std::shared_ptr<Token> newParameter){
    parameters.push_back(newParameter);
  }

  FUNCTION(){
    typeName = "FUNCTION";
  }
};


class FOR : public GeneralExpression{
public: 
  //std::shared_ptr<MINOR_STATEMENT> startCondition;
  float counterVarValue;
  std::string counterVarName; // ALWAYS KEEP THE NAME IN THE SYMBOL TABLE GLOOBAAAALLLLLLLLY I DON'T WANT TROUBLE

  std::shared_ptr<Expression> startCondition;
  std::shared_ptr<Expression> endCondition;
  std::shared_ptr<Expression> incrementExp;
 
  void setStartCond(std::shared_ptr<Expression> newStartCond){
    startCondition = newStartCond;
  }

  void setEndCond(std::shared_ptr<Expression> newEndCond){
    endCondition = newEndCond;
  }

  void setIncrementExp(std::shared_ptr<Expression> newIncExp){
    incrementExp = newIncExp;
  }

  //std::vector<std::shared_ptr<GeneralExpression>> forBody; 

  FOR(){
    typeName = "FOR";
  }
};


class WHILE : public GeneralExpression{
public:
  std::shared_ptr<Expression> endCondition;
  //std::vector<std::shared_ptr<GeneralExpression>> whileBody; 

  void addCheckCondition(std::shared_ptr<Expression> newCheckCondition){
    endCondition = newCheckCondition;
  }

  WHILE(){
    typeName = "WHILE";
  }
};


class IF : public GeneralExpression{
public: 
  std::shared_ptr<Expression> checkCondition;
  //std::vector<std::shared_ptr<GeneralExpression>> ifBody; 
  
  void addCheckCondition(std::shared_ptr<Expression> newCheckCondition){
    checkCondition = newCheckCondition;
  }


  IF(){
    typeName = "IF";
  }
};


class ELSE : public GeneralExpression{
public: 
  //std::vector<std::shared_ptr<GeneralExpression>> elseBody; 

  ELSE(){
    typeName = "ELSE";
  }
};


class ELSE_IF : public GeneralExpression{
public: 
  std::shared_ptr<Expression> checkCondition;
  //std::vector<std::shared_ptr<GeneralExpression>> elseIfBody; 

  void addCheckCondition(std::shared_ptr<Expression> newCheckCondition){
    checkCondition = newCheckCondition;
  }

  ELSE_IF(){
    typeName = "ELSE IF";
  }
};







class ParseTreeCreator{
private:
  std::unordered_map<std::string, std::shared_ptr<FUNCTION>> functionSymbolTable;
  std::unordered_map<std::string, std::string> variableSymbolTable;
  std::vector<std::shared_ptr<Token>> tokenStream;

  std::shared_ptr<GeneralExpression> rootMother;

  long unsigned int currIndex = 0;


  std::shared_ptr<GeneralExpression> createNewGeneralExpression(){
    std::shared_ptr<GeneralExpression> newExpression = std::make_shared<GeneralExpression>();
    return newExpression;  
  }

  
  void checkIfCastingSuccessful(std::shared_ptr<GeneralExpression> expressionToTest){
    if(!expressionToTest){
      std::cout << '\n';
      std::cout << "!!!!!!!!!!!!!!!!!!CASTING FAILED!!!!!!!!!!!!!!!!!!!! at:" << tokenStream[currIndex] -> get_token_string() << '\n'; 
      std::cout << '\n';
    }
  }
  

  std::shared_ptr<Expression> createNewExpression(){
    std::shared_ptr<Expression> newExpression = std::make_shared<Expression>();
    return newExpression;  
  }

  std::shared_ptr<ELSE> createNewElse(){
    std::shared_ptr<ELSE> newElse = std::make_shared<ELSE>();
    return newElse;  
  }

  std::shared_ptr<ELSE_IF> createNewElseIf(){
    std::shared_ptr<ELSE_IF> newElseIf = std::make_shared<ELSE_IF>();
    return newElseIf;
  }
    
  std::shared_ptr<IF> createNewIf(){
    std::shared_ptr<IF> newIf = std::make_shared<IF>();
    return newIf;
  }

  std::shared_ptr<FUNCTION> createNewFunction(){
    std::shared_ptr<FUNCTION> newFunction = std::make_shared<FUNCTION>();
    return newFunction;
  }

  std::shared_ptr<FOR> createNewFor(){
    std::shared_ptr<FOR> newFor = std::make_shared<FOR>();
    return newFor;
  }

  std::shared_ptr<WHILE> createNewWhile(){
    std::shared_ptr<WHILE> newWhile = std::make_shared<WHILE>();
    return newWhile;
  }

  std::shared_ptr<MINOR_STATEMENT> createNewMinorStatement(){
    std::shared_ptr<MINOR_STATEMENT> newMinorStatement = std::make_shared<MINOR_STATEMENT>();
    return newMinorStatement;
  }

  std::shared_ptr<Action> createNewAction(){
    std::shared_ptr<Action> newAction = std::make_shared<Action>();
    return newAction;
  }

  // PARSING RELATED PARS
  int bracePolarity = 0;

  std::shared_ptr<GeneralExpression> fatherTempExpression;
  std::shared_ptr<GeneralExpression> standingExpressionPointer;

  void exitIfBracePolarityWrong(){
    if(bracePolarity < 0){
      // CHANGE THIS TO 0 WHEN DONE AND CHANGE std::cout to std::cerr
      std::cout << "Extra brace was found at: " << tokenStream[currIndex] -> get_line_occurence();
      exit(0);
    }
  }

  void exitIfBracketPolarityWrong(int bracketPolarity){
    if(bracketPolarity < 0){
      // CHANGE THIS TO 0 WHEN DONE AND CHANGE std::cout to std::cerr
      std::cout << "Extra brace was found at: " << tokenStream[currIndex] -> get_line_occurence();
      exit(0);
    }
  }

  bool checkIfIndexOverflows(){
    if(currIndex >= tokenStream.size()){
      return true;
    }
    return false;
  }

  void beginStatement(){
    // WHERE WE BEGAN AND WHERE WE DIE
    if(checkIfIndexOverflows() && bracePolarity > 0){
      std::cout << "Missing closing brace at line:" << tokenStream[currIndex - 1] -> get_line_occurence() << '\n';
      exit(0);
    }
    else if(checkIfIndexOverflows()){
      return;
    }
     

    if(tokenStream[currIndex] -> get_token_string() == "for"){
      forNode();
    }
    else if(tokenStream[currIndex] -> get_token_string() == "if"){
      ifNode();
    }
    else if(tokenStream[currIndex] -> get_token_string() == "else if"){
      elseIfNode();
    }
    else if(tokenStream[currIndex] -> get_token_string() == "else"){
      elseNode();
    }
    else if(tokenStream[currIndex] -> get_token_string() == "while"){
      whileNode();
    }
    else if(tokenStream[currIndex] -> get_token_string() == "function"){
      functionNode();
    }
    else if(tokenStream[currIndex] -> get_token_string() == "print"){
      printNode();
    }
    /*
    else if(tokenStream[currIndex] -> get_token_string() == "script"){
      scriptNode();
    }
    
    else if(tokenStream[currIndex] -> get_token_string() == "shell"){
      shellNode();
    }
    */
    else if(tokenStream[currIndex] -> get_token_string() == "command"){
      commandNode();
    }
    else if(tokenStream[currIndex] -> get_token_type() == "Literal" || tokenStream[currIndex] -> get_token_type() == "Number"){
      minorStatement();
    }
    else if(tokenStream[currIndex] -> get_token_string() == "}"){
      //std::cout << "Incorrect declaration at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
      //exit(0);
      bracePolarity --;
      if(bracePolarity < 0){
        std::cout <<  "Extra brace enclosing nothing at line: " << tokenStream[currIndex] -> get_token_string() << '\n';
        exit(0);
      }

      currIndex ++;
      standingExpressionPointer = standingExpressionPointer -> lastParentExpression;
      beginStatement();
    }
    else if(tokenStream[currIndex] -> get_token_type() == "Separator" || tokenStream[currIndex] -> get_token_type() == "Operator"){
      std::cout << "Statement cannot start with separator or operator at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
      exit(0);
    }
    else{
      std::cout << "Found this: " << tokenStream[currIndex] -> get_token_string() << "Guess I am exiting the MAJOR statement??\n";
    }
  }
   
  

  




  void forNode(){
 
    /*
    // UPCAST THE INSTANCE TO THE SPECIFIC ONE
    standingExpressionPointer = static_cast<std::shared_ptr<FOR>>(standingExpressionPointer);
    */
   
    fatherTempExpression = standingExpressionPointer; // SAVE THE ADDRESS OF THE OLD EXPRESSION TERMPORARILY
    standingExpressionPointer = createNewFor(); // CREATE THE NEW EXPRESSION
    fatherTempExpression -> addSubExpression(standingExpressionPointer); // ADD THE NEW EXPRESSION TO THE OLD EXPRESSION
    standingExpressionPointer -> setLastParentExpression(fatherTempExpression); // CONNECT THE NEW WITH THE OLD AS A SON
    currIndex ++;
    if(checkIfIndexOverflows()){
      std::cout << "Missing bracket for for at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
    }

    // FROM NOW ON, YOU WILL DEAL WITH THE tempExpressionPointerHolder AS LONG AS YOU ARE INSIDE THE FUNCTION
    std::shared_ptr<FOR> tempExpressionPointerHolder = std::static_pointer_cast<FOR>(standingExpressionPointer);
    checkIfCastingSuccessful(tempExpressionPointerHolder);

    std::shared_ptr<Expression> start_exp = std::make_shared<Expression>();
    std::shared_ptr<Expression> end_exp = std::make_shared<Expression>();
    std::shared_ptr<Expression> increment_exp = std::make_shared<Expression>();

    

    // START CONDITION SYNTAX CHECK
    if(currIndex + 3 >= tokenStream.size()){
      std::cout << "Incomplete expression inside for loop start condition at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
      exit(0);
    }


    if(tokenStream[currIndex] -> get_token_string() == "var" && 
      tokenStream[currIndex + 1] -> get_token_type() == "Literal" &&
      tokenStream[currIndex + 2] -> get_token_string() == "="){
      
      tempExpressionPointerHolder -> counterVarName = tokenStream[currIndex + 1] -> get_token_string();

      currIndex += 3;
      

      // START CONDITION COLLECTOR
      while(tokenStream[currIndex] -> get_token_string() != ";"){
        if(checkIfIndexOverflows()){
          std::cout << "Incomplete expression inside for loop start condition at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
          exit(0);
        }
        start_exp -> addElement(tokenStream[currIndex]);
        currIndex ++;
      }


      
    }
    else{
      std::cout << "Incorrect syntax in for loop at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
      exit(0);
    }
    
    // END CONDITION SYNTAX CHECK
    currIndex ++;
    if(checkIfIndexOverflows()){
      std::cout << "Incomplete expression inside for loop end condition at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
      exit(0);
    }

    while(tokenStream[currIndex] -> get_token_string() != ";"){
      if(checkIfIndexOverflows()){
        std::cout << "Incomplete expression inside for loop start condition at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
        exit(0);
      }
      end_exp -> addElement(tokenStream[currIndex]);
      currIndex ++;
    }

    // INCREMENT SYNTAX CHECK 
    currIndex ++;
    if(checkIfIndexOverflows()){
      std::cout << "Incomplete expression inside for loop end condition at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
      exit(0);
    }

    while(tokenStream[currIndex] -> get_token_string() != ")"){
      if(checkIfIndexOverflows()){
        std::cout << "Incomplete expression inside for loop start condition at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
        exit(0);
      }
      increment_exp -> addElement(tokenStream[currIndex]);
      currIndex ++;
    }

    // FOR THE BODY OF THE FOR
    currIndex ++;
    if(checkIfIndexOverflows()){
      std::cout << "Incomplete expression inside for loop end condition at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
      exit(0);
    }

    if(tokenStream[currIndex] -> get_token_string() == "{"){
      currIndex ++;
      bracePolarity ++;
      if(checkIfIndexOverflows()){
        std::cout << "Missing statement after the if declaration at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
        exit(0);
      }
      beginStatement();
    }
    else{
      std::cout << "Expected a starting brace at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
      exit(0);
    }
    
    // FOR THE ENDING OF THE FOR LOOP EXPRESSION
   

    // THIS PART WILL BE COMMENTED OUT
    /*
    if(tokenStream[currIndex] -> get_token_string() == "}"){
      // JUMP UP IN THE TREE BEFORE YOU CONTINUE
      
      currIndex ++;
      if(checkIfIndexOverflows()){
        return; 
      }
      beginStatement();
    }
    else{
      std::cout << "Why did you fail to find me?\n";
    }
    */
  }



  void ifNode(){
    fatherTempExpression  = standingExpressionPointer;
    standingExpressionPointer = createNewIf();
    fatherTempExpression -> addSubExpression(standingExpressionPointer); // ADD THE NEW EXPRESSION TO THE OLD EXPRESSION
    standingExpressionPointer -> setLastParentExpression(fatherTempExpression);
    currIndex ++;
    if(checkIfIndexOverflows()){
      std::cout << "Missing bracket for if at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
      exit(0);
    }

    // FROM NOW ON, YOU WILL DEAL WITH THE tempExpressionPointerHolder AS LONG AS YOU ARE INSIDE THE FUNCTION
    std::shared_ptr<IF> tempExpressionPointerHolder = std::static_pointer_cast<IF>(standingExpressionPointer);
    checkIfCastingSuccessful(tempExpressionPointerHolder);

    // CREATE AN EXPRESSION FOR THE CONDITION
    std::shared_ptr<Expression> conditionExpression = std::make_shared<Expression>();

    // STORE THE EXPRESSION TO BE EVALUATED
    int bracketPolarity = 0;

    // ENTER THE BRACKET AND START FROM THERE AND ALSO INCREMENT INDEX
    if(tokenStream[currIndex] -> get_token_string() == "("){
      conditionExpression -> addElement(tokenStream[currIndex]);
      bracketPolarity ++;
      currIndex ++;
      if(checkIfIndexOverflows()){
        std::cout << "Missing expression for if at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
        exit(0);
      }
    }
    else{
      std::cout << "Missing bracket for if at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
      exit(0);
    }
    
    // Check for bracket polarity while fetching expression elements and adding them to the conditionExpression
    while(bracketPolarity >= 0){
      if(tokenStream[currIndex] -> get_token_string() == "("){
        conditionExpression -> addElement(tokenStream[currIndex]);
        bracketPolarity ++;
        currIndex ++;
        if(checkIfIndexOverflows()){
          std::cout << "Expected a closing bracket, but was not found at line: " << tokenStream[currIndex] -> get_token_string() << '\n';
          exit(0);
        }
      }
      else if(tokenStream[currIndex] -> get_token_string() == ")"){
        conditionExpression -> addElement(tokenStream[currIndex]);
        bracketPolarity --;
        currIndex ++;
        if(checkIfIndexOverflows()){
          std::cout << "Expected a closing bracket, but was not found at line: " << tokenStream[currIndex] -> get_token_string() << '\n';
          exit(0);
        }
      }
      else{
        conditionExpression -> addElement(tokenStream[currIndex]);
        currIndex ++;
        if(checkIfIndexOverflows()){
          std::cout << "Expected a closing bracket, but was not found at line: " << tokenStream[currIndex] -> get_token_string() << '\n';
          exit(0);
        }
      }


      if(bracketPolarity < 0){
        std::cout << "Extra Bracket at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
        exit(0);
      }
    }
    

    // FOR THE BODY OF THE IF
    currIndex ++;
      
    // ADD THE CONDITION EXPRESSION TO THE IF STATEMENT AFTER CREATION 
    tempExpressionPointerHolder -> addCheckCondition(conditionExpression);
    
    exitIfBracketPolarityWrong(bracketPolarity);
    
    // FOR THE BODY OF THE IF
    //


    if(checkIfIndexOverflows()){
      std::cout << "Missing brace after the if declaration at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
      exit(0);
    }

    if(tokenStream[currIndex] -> get_token_string() == "{"){
      currIndex ++;
      bracePolarity ++;
      if(checkIfIndexOverflows()){
        std::cout << "Missing statement after the if declaration at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
        exit(0);
      }
      beginStatement();
    }
    else{
      std::cout << "Incorrect syntax for if statement at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
      exit(0);
    }

    // THIS PART WILL BE COMMENTED OUT
    /*
    if(tokenStream[currIndex] -> get_token_string() == "}"){
      // GO BACK TO THE FATHER
      standingExpressionPointer = tempExpressionPointerHolder -> lastParentExpression;
      
      currIndex ++;
      bracePolarity --;
      if(checkIfIndexOverflows()){
        return;
      }
      beginStatement();
    }
    */
  }



  void elseIfNode(){
    fatherTempExpression  = standingExpressionPointer;
    standingExpressionPointer = createNewIf();
    fatherTempExpression -> addSubExpression(standingExpressionPointer); // ADD THE NEW EXPRESSION TO THE OLD EXPRESSION
    standingExpressionPointer -> setLastParentExpression(fatherTempExpression);
    currIndex ++;
    if(checkIfIndexOverflows()){
      std::cout << "Missing bracket for else if at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
      exit(0);
    }

    // FROM NOW ON, YOU WILL DEAL WITH THE tempExpressionPointerHolder AS LONG AS YOU ARE INSIDE THE FUNCTION
    std::shared_ptr<ELSE_IF> tempExpressionPointerHolder = std::static_pointer_cast<ELSE_IF>(standingExpressionPointer);
    checkIfCastingSuccessful(tempExpressionPointerHolder);

    // CREATE AN EXPRESSION FOR THE CONDITION
    std::shared_ptr<Expression> conditionExpression = std::make_shared<Expression>();

    // STORE THE EXPRESSION TO BE EVALUATED
    int bracketPolarity = 0;

    // ENTER THE BRACKET AND START FROM THERE AND ALSO INCREMENT INDEX
    //bracketPolarity ++;
    //currIndex ++;
    if(tokenStream[currIndex] -> get_token_string() == "("){
      conditionExpression -> addElement(tokenStream[currIndex]);
      bracketPolarity ++;
      currIndex ++;
      if(checkIfIndexOverflows()){
        std::cout << "Missing expression for else if at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
        exit(0);
      }
    }
    else{
      std::cout << "Missing bracket for else if at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
      exit(0);
    }

    // Check for bracket polarity while fetching expression elements and adding them to the conditionExpression
    while(bracketPolarity >= 0){
      if(tokenStream[currIndex] -> get_token_string() == "("){
        conditionExpression -> addElement(tokenStream[currIndex]);
        bracketPolarity ++;
        currIndex ++;
        if(checkIfIndexOverflows()){
          std::cout << "Expected a closing bracket, but was not found at line: " << tokenStream[currIndex] -> get_token_string() << '\n';
          exit(0);
        }
      }
      else if(tokenStream[currIndex] -> get_token_string() == ")"){
        conditionExpression -> addElement(tokenStream[currIndex]);
        bracketPolarity --;
        currIndex ++;
        if(checkIfIndexOverflows()){
          std::cout << "Expected a closing bracket, but was not found at line: " << tokenStream[currIndex] -> get_token_string() << '\n';
          exit(0);
        }
      }
      else{
        conditionExpression -> addElement(tokenStream[currIndex]);
        currIndex ++;
        if(checkIfIndexOverflows()){
          std::cout << "Expected a closing bracket, but was not found at line: " << tokenStream[currIndex] -> get_token_string() << '\n';
          exit(0);
        }
      }


      if(bracketPolarity < 0){
        std::cout << "Extra Bracket at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
        exit(0);
      }
    }
      
    // FOR THE BODY OF THE ELSE IF
    currIndex ++;
    // ADD THE CONDITION EXPRESSION TO THE IF STATEMENT AFTER CREATION 
    tempExpressionPointerHolder -> addCheckCondition(conditionExpression);
    
    exitIfBracketPolarityWrong(bracketPolarity);
    

    if(checkIfIndexOverflows()){
      std::cout << "Missing brace after the else if declaration at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
      exit(0);
    }


    if(tokenStream[currIndex] -> get_token_string() == "{"){
      currIndex ++;
      bracePolarity ++;
      if(checkIfIndexOverflows()){
        std::cout << "Missing statement after the else if declaration at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
        exit(0);
      }
      beginStatement();
    }
    else{
      std::cout << "Incorrect syntax for if statement at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
      exit(0);
    }


    // THIS PART WILL BE COMMENTED OUT
    /*
    if(tokenStream[currIndex] -> get_token_string() == "}"){
      // GO BACK TO THE FATHER
      standingExpressionPointer = tempExpressionPointerHolder -> lastParentExpression;
      
      currIndex ++;
      bracePolarity --;
      if(checkIfIndexOverflows()){
        return;
      }
      beginStatement();
    }
    */
  }



  void elseNode(){
    fatherTempExpression  = standingExpressionPointer;
    standingExpressionPointer = createNewElse();
    fatherTempExpression -> addSubExpression(standingExpressionPointer); // ADD THE NEW EXPRESSION TO THE OLD EXPRESSION
    standingExpressionPointer -> setLastParentExpression(fatherTempExpression);
    currIndex ++;
    if(checkIfIndexOverflows()){
      std::cout << "Expected expression after else declaration at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
      exit(0);
    }

    std::shared_ptr<ELSE> tempExpressionPointerHolder = std::static_pointer_cast<ELSE>(standingExpressionPointer);
    checkIfCastingSuccessful(tempExpressionPointerHolder);


    // FOR THE BODY OF THE ELSE STATEMENT
    //currIndex ++;

    if(tokenStream[currIndex] -> get_token_string() == "{"){
      bracePolarity ++;
      beginStatement();
    }
    else{
      std::cout << "Incorrect syntax for else statement at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
      exit(0);
    }

    // THIS PART WILL BE COMMENTED OUT
    /*
    if(tokenStream[currIndex] -> get_token_string() == "}"){
      // GO BACK TO THE FATHEk
      standingExpressionPointer = tempExpressionPointerHolder -> lastParentExpression;

      currIndex ++;
      bracePolarity --;
      if(checkIfIndexOverflows()){
        return;
      }
      beginStatement();
    }
    */
  }



  void whileNode(){
    fatherTempExpression  = standingExpressionPointer;
    standingExpressionPointer = createNewWhile();
    fatherTempExpression -> addSubExpression(standingExpressionPointer); // ADD THE NEW EXPRESSION TO THE OLD EXPRESSION
    standingExpressionPointer -> setLastParentExpression(fatherTempExpression);
    currIndex ++;
    if(checkIfIndexOverflows()){
      std::cout << "Missing bracket for while at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
      exit(0);
    }

    std::shared_ptr<WHILE> tempExpressionPointerHolder = std::static_pointer_cast<WHILE>(standingExpressionPointer);
    checkIfCastingSuccessful(tempExpressionPointerHolder);

    // CREATE AN EXPRESSION FOR THE CONDITION
    std::shared_ptr<Expression> conditionExpression = std::make_shared<Expression>();

    // STORE THE EXPRESSION TO BE EVALUATED
    int bracketPolarity = 0;

    // ENTER THE BRACKET AND START FROM THERE AND ALSO INCREMENT INDEX
    //bracketPolarity ++;
    //currIndex ++;
    if(tokenStream[currIndex] -> get_token_string() == "("){
      conditionExpression -> addElement(tokenStream[currIndex]);
      bracketPolarity ++;
      currIndex ++;

      if(checkIfIndexOverflows()){
        std::cout << "Missing expression for while at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
        exit(0);
      }
    }
    else{
      std::cout << "Missing bracket for while at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
      exit(0);
    }

    // Check for bracket polarity while fetching expression elements and adding them to the conditionExpression
    while(bracketPolarity >= 0){
      if(tokenStream[currIndex] -> get_token_string() == "("){
        conditionExpression -> addElement(tokenStream[currIndex]);
        bracketPolarity ++;
        currIndex ++;

        if(checkIfIndexOverflows()){
          std::cout << "Expected a closing bracket, but was not found at line: " << tokenStream[currIndex] -> get_token_string() << '\n';
          exit(0);
        }
      }
      else if(tokenStream[currIndex] -> get_token_string() == ")"){
        conditionExpression -> addElement(tokenStream[currIndex]);
        bracketPolarity --;
        currIndex ++;
        if(checkIfIndexOverflows()){
          std::cout << "Expected a closing bracket, but was not found at line: " << tokenStream[currIndex] -> get_token_string() << '\n';
          exit(0);
        }
      }
      else{
        conditionExpression -> addElement(tokenStream[currIndex]);
        currIndex ++;
        if(checkIfIndexOverflows()){
          std::cout << "Expected a closing bracket, but was not found at line: " << tokenStream[currIndex] -> get_token_string() << '\n';
          exit(0);
        }
      }


      if(bracketPolarity < 0){
        std::cout << "Extra Bracket at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
        exit(0);
      }
    }
      
    // FOR THE BODY OF THE WHILE
    currIndex ++;
    // ADD THE CONDITION EXPRESSION TO THE IF STATEMENT AFTER CREATION 
    tempExpressionPointerHolder -> addCheckCondition(conditionExpression);
    
    // FOR THE BODY OF THE WHILE
    currIndex ++;
   
    exitIfBracketPolarityWrong(bracketPolarity);

    if(checkIfIndexOverflows()){
      std::cout << "Missing brace after the else if declaration at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
      exit(0);
    }


    if(tokenStream[currIndex] -> get_token_string() == "{"){
      currIndex ++;
      bracePolarity ++;
      if(checkIfIndexOverflows()){
        std::cout << "Missing statement after the while declaration at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
        exit(0);
      }
      beginStatement();
    }
    else{
      std::cout << "Incorrect syntax for while statement at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
      exit(0);
    }

    // THIS PART WILL BE COMMENTED OUT
    /*
    if(tokenStream[currIndex] -> get_token_string() == "}"){
      // GO BACK TO THE FATHER
      standingExpressionPointer = tempExpressionPointerHolder -> lastParentExpression;
      bracePolarity --;
      currIndex ++;

      if(checkIfIndexOverflows()){
        return;
      }
      beginStatement();
    }
    */
  }


  
  void functionNode(){
    std::string functionName = tokenStream[currIndex] -> get_token_string();

    // KEEP IN MIND THAT IT DOESN'T NEED TO HAVE A PARENT AT ALL. HOOOOOOOOWEEEEEEEEVEEEEER, IT MUST BE IMPLEMENTED IN ORDER TO NOT BREAK THE TREE
    fatherTempExpression  = standingExpressionPointer;
    standingExpressionPointer = createNewFunction();
    fatherTempExpression -> addSubExpression(standingExpressionPointer); // ADD THE NEW EXPRESSION TO THE OLD EXPRESSION
    standingExpressionPointer -> setLastParentExpression(fatherTempExpression);
    currIndex ++;

    std::shared_ptr<FUNCTION> tempExpressionPointerHolder = std::static_pointer_cast<FUNCTION>(standingExpressionPointer);
    checkIfCastingSuccessful(tempExpressionPointerHolder);

    // RESOLVE THE PARAMETERS OF THE FUNCTION
    if(tokenStream[currIndex] -> get_token_string() == "("){
      currIndex ++;
      if(checkIfIndexOverflows()){
        std::cout << "Missing brace after the else if declaration at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
        exit(0);
      }
      while(tokenStream[currIndex] -> get_token_string() != ")"){
        if(tokenStream[currIndex] -> get_token_type() == "Literal"){
          tempExpressionPointerHolder -> addParameter(tokenStream[currIndex]);
          currIndex ++;
        }
        else if(tokenStream[currIndex] -> get_token_string() == ","){
          currIndex ++;
        }
        else{
          std::cout << "Incorrect parameter declaration inside function at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
          exit(0);
        }
      }
    }

    //currIndex ++;
    if(checkIfIndexOverflows()){
      std::cout << "Missing brace after function declaration at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
      exit(0);
    }

    if(tokenStream[currIndex] -> get_token_string() == "{"){
      currIndex ++;
      bracePolarity ++;
      if(checkIfIndexOverflows()){
        std::cout << "Missing statement after the while declaration at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
        exit(0);
      }
      beginStatement();
    }
    else{
      std::cout << "Incorrect syntax for while statement at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
      exit(0);
    }

      

    functionSymbolTable[functionName] = tempExpressionPointerHolder;
  
    // THIS PART WILL BE COMMETNTED OUT AND THE LINE ABOVE IT WAS WITHIN AND UNDER THE LINE: standingExpressionPointer = tempExpressionPointerHolder -> lastParentExpression;
    /*
    if(tokenStream[currIndex] -> get_token_string() == "}"){
      // SAVE THE FUNCTION IN THE SYMBOL TABLE
      // AND SAVE THE FATHER
      standingExpressionPointer = tempExpressionPointerHolder -> lastParentExpression;


      currIndex ++;
      bracePolarity --;
      if(checkIfIndexOverflows()){
        return;
      }
      beginStatement();
    }
    */
  }



  void minorStatement(){
    fatherTempExpression  = standingExpressionPointer;
    standingExpressionPointer = createNewMinorStatement();
    fatherTempExpression -> addSubExpression(standingExpressionPointer); // ADD THE NEW EXPRESSION TO THE OLD EXPRESSION
    standingExpressionPointer -> setLastParentExpression(fatherTempExpression);
    //currIndex ++; // YOU ALREADY NEED TO ANALYZE VAR
    if(checkIfIndexOverflows()){
      std::cout <<  "Expected an identifier or identifier declaration at line: " << tokenStream[currIndex] << '\n';
      exit(0);
    }
  
    std::shared_ptr<MINOR_STATEMENT> tempExpressionPointerHolder = std::static_pointer_cast<MINOR_STATEMENT>(standingExpressionPointer);
    checkIfCastingSuccessful(tempExpressionPointerHolder);

    if(tokenStream[currIndex] -> get_token_string() == "var"){
      tempExpressionPointerHolder -> createNewVar = true;
    }
    else if(tokenStream[currIndex] -> get_token_type() == "Literal"){
      tempExpressionPointerHolder -> variableName = tokenStream[currIndex] -> get_token_string();
      currIndex ++;
    }
    else{
      std::cout << "Unspecified BEHAVIOR!!!!!!!!!!!!! at line: " << tokenStream[currIndex] -> get_line_occurence();
      exit(0);
    }


    if(tokenStream[currIndex] -> get_token_string() == "=" ||
       tokenStream[currIndex] -> get_token_string() == "+=" ||
       tokenStream[currIndex] -> get_token_string() == "-=" ||
       tokenStream[currIndex] -> get_token_string() == "++" ||
       tokenStream[currIndex] -> get_token_string() == "--"){

      while(tokenStream[currIndex] -> get_token_string() != ";"){
        // ADD THE TOKENS 
        tempExpressionPointerHolder -> attributedValue.push_back(tokenStream[currIndex]);

        currIndex ++;
      }
      if(checkIfIndexOverflows()){
        return;
      }
    }
    /*
    else if(tokenStream[currIndex] -> get_token_string() == "++" ||
            tokenStream[currIndex] -> get_token_string() == "--"){
      
    }
    */
    else{
      std::cout << "Incorrect syntax for declarative statement at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
      exit(0);
    }

    currIndex ++;
    if(checkIfIndexOverflows()){
      return;
    }

    beginStatement();
  }



  void printNode(){
    fatherTempExpression  = standingExpressionPointer;
    standingExpressionPointer = createNewAction();
    fatherTempExpression -> addSubExpression(standingExpressionPointer); // ADD THE NEW EXPRESSION TO THE OLD EXPRESSION
    standingExpressionPointer -> setLastParentExpression(fatherTempExpression);
    currIndex ++;
    if(checkIfIndexOverflows()){
      std::cout << "Expected an expression at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
      exit(0);
    }
  
    std::shared_ptr<Action> tempExpressionPointerHolder = std::static_pointer_cast<Action>(standingExpressionPointer);
    checkIfCastingSuccessful(tempExpressionPointerHolder);

    tempExpressionPointerHolder -> actionToDo = "print";


    int bracketPolarity = 0;

    // ENTER THE BRACKET AND START FROM THERE AND ALSO INCREMENT INDEX
    //bracketPolarity ++;
    //currIndex ++;
    if(tokenStream[currIndex] -> get_token_string() == "("){
      tempExpressionPointerHolder -> addElement(tokenStream[currIndex]);
      bracketPolarity ++;
      currIndex ++;
      if(checkIfIndexOverflows()){
        std::cout << "Missing expression for while at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
        exit(0);
      }
    }
    else{
      std::cout << "Missing bracket for while at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
      exit(0);
    }

    // Check for bracket polarity while fetching expression elements and adding them to the conditionExpression
    while(bracketPolarity >= 0){
      if(tokenStream[currIndex] -> get_token_string() == "("){
        tempExpressionPointerHolder -> addElement(tokenStream[currIndex]);
        bracketPolarity ++;
        currIndex ++;
        if(checkIfIndexOverflows()){
          std::cout << "Expected a closing bracket, but was not found at line: " << tokenStream[currIndex] -> get_token_string() << '\n';
          exit(0);
        }
      }
      else if(tokenStream[currIndex] -> get_token_string() == ")"){
        tempExpressionPointerHolder -> addElement(tokenStream[currIndex]);
        bracketPolarity --;
        currIndex ++;
        if(checkIfIndexOverflows()){
          std::cout << "Expected a closing bracket, but was not found at line: " << tokenStream[currIndex] -> get_token_string() << '\n';
          exit(0);
        }
      }
      else{ 

        tempExpressionPointerHolder -> addElement(tokenStream[currIndex]);
        currIndex ++;
        if(checkIfIndexOverflows()){
          std::cout << "Expected a closing bracket, but was not found at line: " << tokenStream[currIndex] -> get_token_string() << '\n';
          exit(0);
        }
      }


      if(bracketPolarity < 0){
        std::cout << "Extra Bracket at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
        exit(0);
      }
    }


    currIndex ++;

    if(tokenStream[currIndex] -> get_token_string() == ";"){
      beginStatement();
    }

  }


  /*
  void shellNode(){

  }

  void scriptNode(){

  }
  */


  void commandNode(){
    fatherTempExpression  = standingExpressionPointer;
    standingExpressionPointer = createNewAction();
    fatherTempExpression -> addSubExpression(standingExpressionPointer); // ADD THE NEW EXPRESSION TO THE OLD EXPRESSION
    standingExpressionPointer -> setLastParentExpression(fatherTempExpression);
    currIndex ++;
    if(checkIfIndexOverflows()){
      std::cout << "Expected an expression at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
      exit(0);
    }
  
    std::shared_ptr<Action> tempExpressionPointerHolder = std::static_pointer_cast<Action>(standingExpressionPointer);
    checkIfCastingSuccessful(tempExpressionPointerHolder);

    tempExpressionPointerHolder -> actionToDo = "command";


    int bracketPolarity = 0;

    // ENTER THE BRACKET AND START FROM THERE AND ALSO INCREMENT INDEX
    //bracketPolarity ++;
    //currIndex ++;
    if(tokenStream[currIndex] -> get_token_string() == "("){
      tempExpressionPointerHolder -> addElement(tokenStream[currIndex]);
      bracketPolarity ++;
      currIndex ++;
      if(checkIfIndexOverflows()){
        std::cout << "Missing expression for while at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
        exit(0);
      }
    }
    else{
      std::cout << "Missing bracket for while at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
      exit(0);
    }

    // Check for bracket polarity while fetching expression elements and adding them to the conditionExpression
    
    while(bracketPolarity >= 0){
      if(tokenStream[currIndex] -> get_token_string() == "("){
        tempExpressionPointerHolder -> addElement(tokenStream[currIndex]);
        bracketPolarity ++;
        currIndex ++;
        if(checkIfIndexOverflows()){
          std::cout << "Expected a closing bracket, but was not found at line: " << tokenStream[currIndex] -> get_token_string() << '\n';
          exit(0);
        }
      }
      else if(tokenStream[currIndex] -> get_token_string() == ")"){
        tempExpressionPointerHolder -> addElement(tokenStream[currIndex]);
        bracketPolarity --;
        currIndex ++;
        if(checkIfIndexOverflows()){
          std::cout << "Expected a closing bracket, but was not found at line: " << tokenStream[currIndex] -> get_token_string() << '\n';
          exit(0);
        }
      }
      else{ tempExpressionPointerHolder -> addElement(tokenStream[currIndex]);
        currIndex ++;
        if(checkIfIndexOverflows()){
          std::cout << "Expected a closing bracket, but was not found at line: " << tokenStream[currIndex] -> get_token_string() << '\n';
          exit(0);
        }
      }


      if(bracketPolarity < 0){
        std::cout << "Extra Bracket at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
        exit(0);
      }
    }


    currIndex ++;

    if(tokenStream[currIndex] -> get_token_string() == ";"){
      beginStatement();
    }
  }





public:
  
  void getTokenStream(std::vector<std::shared_ptr<Token>>* newTokenStream){
    tokenStream = *newTokenStream;
  }

  std::shared_ptr<GeneralExpression>* getParseTree(){
    //initializeRoot(); // THIS PART WAS REPLACED BY MAIN_BODY
    rootMother = std::make_shared<GeneralExpression>();
    beginStatement();
    return &rootMother;
  }
};
