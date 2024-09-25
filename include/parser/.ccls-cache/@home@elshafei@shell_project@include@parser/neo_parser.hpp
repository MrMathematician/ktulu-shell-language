#include <bits/stdc++.h>
#include "../../include/lexer/lexer.hpp"

enum class mainTypeExpression{
  MAJOR_EXPRESSION,
  NORMAL_STATEMENT,
  CONDITION_STATEMENT,
};

// IMPLEMENT A SAFETY FEATURE TO DETECT MALICIOUS COMMANDS BEFORE GETTING INTO RUNTIME


// Can detect more than x malicious commands.
// Detect possible race conditions.

class GeneralExpression{
public:

  long unsigned int lastIndexVisited = 0;
  std::shared_ptr<GeneralExpression> lastParentExpression;
  std::string typeName;

  std::vector<std::shared_ptr<GeneralExpression>> expressionBody; 

  void addSubExpression(std::shared_ptr<GeneralExpression> newSubExpression){
    expressionBody.push_back(newSubExpression);
    //expressionBody.emplace_back(newSubExpression); // TEMPORARILY
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
  
  void displayElements(){
    for(long unsigned int i = 0; i < expressionElements.size(); i++){
      expressionElements[i] -> display_elements();
    }
    std::cout << "Expression ended!\n";
  }

  Expression(){
    typeName = "Expression";
  }
};


class Action : public GeneralExpression{
public:
  std::string actionToDo;
  std::vector<std::shared_ptr<Token>> operands;

  void addElement(std::shared_ptr<Token> newElement){
    operands.push_back(newElement);
  }

  void displayElements(){
   
    std::cout << "ACTION: " << actionToDo << '\n';
    std::cout << "These are the operands: " << '\n';

    for(long unsigned int i = 0; i < operands.size(); i++){
      operands[i] -> display_elements();
    }
    std::cout << "ACTION ENDED" << '\n';
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

  void displayElements(){
    
    std::cout << "NEW ASSIGNMENT STATUS: " << createNewVar << '\n';
    std::cout << "VARIABLE NAME: " << variableName << '\n';
    std::cout << "These are the operands: " << '\n';

    for(long unsigned int i = 0; i < attributedValue.size(); i++){
      attributedValue[i] -> display_elements();
    }
    std::cout << "MINOR STATEMENT ENDED" << '\n';
  }

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

  void displayElements(){
    std::cout << "Parameters: \n";
    for(long unsigned int i = 0; i < parameters.size(); i++){
      parameters[i] -> display_elements();
    }
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

  // TEMPORARY REMOVE IT AFTER FINISHING IT
  std::vector<std::shared_ptr<FOR>> temporaryVector;  
  void temporaryAdd(std::shared_ptr<FOR> temp){
    temporaryVector.push_back(temp);
  }



  void setStartCond(std::shared_ptr<Expression> newStartCond){
    startCondition = newStartCond;
  }

  void setEndCond(std::shared_ptr<Expression> newEndCond){
    endCondition = newEndCond;
  }

  void setIncrementExp(std::shared_ptr<Expression> newIncExp){
    incrementExp = newIncExp;
  }

  void displayElements(){
    std::cout << "COUNTER VARIBALE NAME: " << counterVarName << '\n';
    startCondition -> displayElements();
    endCondition -> displayElements();
    incrementExp -> displayElements();
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

  void displayElements(){
    endCondition -> displayElements();
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

  void displayElements(){
    checkCondition -> displayElements();
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

  void displayElements(){
    checkCondition -> displayElements();
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

  std::shared_ptr<GeneralExpression> fatherTempExpression = nullptr;
  std::shared_ptr<GeneralExpression> standingExpressionPointer = nullptr;

  void exitIfBracePolarityWrong(){
    if(bracePolarity < 0){
      // CHANGE THIS TO 0 WHEN DONE AND CHANGE std::cout to std::cerr
      std::cout << "Extra brace was found at: " << tokenStream[currIndex] -> get_line_occurence();
      //exit(0);
    }
  }

  void exitIfBracketPolarityWrong(int bracketPolarity){
    if(bracketPolarity < 0){
      // CHANGE THIS TO 0 WHEN DONE AND CHANGE std::cout to std::cerr
      std::cout << "Extra brace was found at: " << tokenStream[currIndex] -> get_line_occurence();
      //exit(0);
    }
  }

  bool checkIfIndexOverflows(){
    if(currIndex >= tokenStream.size()){
      return true;
    }
    return false;
  }


  //bool headTraversed = false;


  void beginStatement(){
    // WHERE WE BEGAN AND WHERE WE DIE
    std::cout << "new statement being created!\n";
    if(checkIfIndexOverflows() && bracePolarity > 0){
      std::cout << "Missing closing brace at line:" << tokenStream[currIndex - 1] -> get_line_occurence() << '\n';
      //exit(0);
    }
    else if(checkIfIndexOverflows()){
      std::cout << "Finished beginStatement() at index: ";
      std::cout << currIndex << '\n';
      return;
    }
     

    if(tokenStream[currIndex] -> get_token_string() == "for"){
      //std::cout << "Did we get heree?\n";
      std::cout << "Found for!\n";
      forNode();
    }
    else if(tokenStream[currIndex] -> get_token_string() == "if"){
      std::cout << "Found if!\n";
      ifNode();
    }
    else if(tokenStream[currIndex] -> get_token_string() == "else if"){
      std::cout << "Found else if!\n";
      elseIfNode();
    }
    else if(tokenStream[currIndex] -> get_token_string() == "else"){
      std::cout << "Found else!\n";
      elseNode();
    }
    else if(tokenStream[currIndex] -> get_token_string() == "while"){
      std::cout << "Found while!\n";
      whileNode();
    }
    else if(tokenStream[currIndex] -> get_token_string() == "function"){
      std::cout << "Found function!\n";
      functionNode();
    }
    else if(tokenStream[currIndex] -> get_token_string() == "print"){
      std::cout << "Found print!\n";
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
      std::cout << "Found command!\n";
      commandNode();
    }
    else if(tokenStream[currIndex] -> get_token_type() == "Literal" || tokenStream[currIndex] -> get_token_type() == "Number" || tokenStream[currIndex] -> get_token_string() == "var"){
      std::cout << "Found minor statement!\n";
      minorStatement();
    }
    else if(tokenStream[currIndex] -> get_token_string() == "}"){
      std::cout << "went out of the current expression\n";
      //std::cout << "Incorrect declaration at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
      ////exit(0);
      bracePolarity --;
      if(bracePolarity < 0){
        std::cout <<  "Extra brace enclosing nothing at line: " << tokenStream[currIndex] -> get_token_string() << '\n';
        //exit(0);
      }

      currIndex ++;
      standingExpressionPointer = standingExpressionPointer -> lastParentExpression;
      beginStatement();
    }
    else if(tokenStream[currIndex] -> get_token_type() == "Separator" || tokenStream[currIndex] -> get_token_type() == "Operator"){
      std::cout << "Statement cannot start with separator or operator at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
      std::cout << tokenStream[currIndex] -> get_token_string() << " is out what was seen\n";
      //exit(0);
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
    standingExpressionPointer = createNewFor(); // CREATE THE NEW EXPRESSION // THIS LINE HAS AN ERROR
    fatherTempExpression -> addSubExpression(standingExpressionPointer); // ADD THE NEW EXPRESSION TO THE OLD EXPRESSION
    standingExpressionPointer -> setLastParentExpression(fatherTempExpression); // CONNECT THE NEW WITH THE OLD AS A SON
    currIndex ++;
    if(checkIfIndexOverflows()){
      std::cout << "Missing bracket for for at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
      //exit(0);
    }

    //std::cout << "WE GOT HERE!\n";
    if(tokenStream[currIndex] -> get_token_string() == "("){
      currIndex ++;
      if(checkIfIndexOverflows()){
        std::cout << "Missing expression for for at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
        //exit(0);
      }
    }

    // FROM NOW ON, YOU WILL DEAL WITH THE tempExpressionPointerHolder AS LONG AS YOU ARE INSIDE THE FUNCTION
    std::shared_ptr<FOR> tempExpressionPointerHolder = std::static_pointer_cast<FOR>(standingExpressionPointer);
    //checkIfCastingSuccessful(tempExpressionPointerHolder);
   
    std::shared_ptr<Expression> start_exp = std::make_shared<Expression>();
    std::shared_ptr<Expression> end_exp = std::make_shared<Expression>();
    std::shared_ptr<Expression> increment_exp = std::make_shared<Expression>();

     

    // START CONDITION SYNTAX CHECK
    if(currIndex + 3 >= tokenStream.size()){
      std::cout << "Incomplete expression inside for loop start condition at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
      //exit(0);
    }

    if(tokenStream[currIndex] -> get_token_string() == "var" && 
      tokenStream[currIndex + 1] -> get_token_type() == "Literal" &&
      tokenStream[currIndex + 2] -> get_token_string() == "="){
      
      tempExpressionPointerHolder -> counterVarName = tokenStream[currIndex + 1] -> get_token_string();

      currIndex += 3;
      

      // START CONDITION COLLECTOR
      while(tokenStream[currIndex] -> get_token_string() != ";"){
        if(checkIfIndexOverflows()){
          std::cout << "Incomplete expression inside for loop start condition at line: " << tokenStream[currIndex] -> get_line_occurence() <<'\n';
          //exit(0);
        }
        start_exp -> addElement(tokenStream[currIndex]);
        currIndex ++;
      }


      
    }
    else{
      std::cout << "Incorrect syntax in for loop at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
      //exit(0);
    }
    
    // END CONDITION SYNTAX CHECK
    currIndex ++;
    if(checkIfIndexOverflows()){
      std::cout << "Incomplete expression inside for loop end condition at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
      //exit(0);
    }

    while(tokenStream[currIndex] -> get_token_string() != ";"){
      if(checkIfIndexOverflows()){
        std::cout << "Incomplete expression inside for loop start condition at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
        //exit(0);
      }
      end_exp -> addElement(tokenStream[currIndex]);
      currIndex ++;
    }

    // INCREMENT SYNTAX CHECK 
    currIndex ++;
    if(checkIfIndexOverflows()){
      std::cout << "Incomplete expression inside for loop end condition at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
      //exit(0);
    }

    while(tokenStream[currIndex] -> get_token_string() != ")"){
      if(checkIfIndexOverflows()){
        std::cout << "Incomplete expression inside for loop start condition at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
        //exit(0);
      }
      increment_exp -> addElement(tokenStream[currIndex]);
      currIndex ++;
    }

    // FOR THE BODY OF THE FOR
    currIndex ++;
    if(checkIfIndexOverflows()){
      std::cout << "Incomplete expression inside for loop end condition at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
      //exit(0);
    }

    if(tokenStream[currIndex] -> get_token_string() == "{"){
      currIndex ++;
      bracePolarity ++;
      if(checkIfIndexOverflows()){
        std::cout << "Missing statement after the if declaration at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
        //exit(0);
      }
      //std::cout << "NIGHTMARE FUEL!!!!!!\n ";
      beginStatement();
    }
    else{
      std::cout << "Expected a starting brace at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
      //exit(0);
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
      //exit(0);
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
        //exit(0);
      }
    }
    else{
      std::cout << "Missing bracket for if at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
      //exit(0);
    }
    
    // Check for bracket polarity while fetching expression elements and adding them to the conditionExpression
    while(bracketPolarity > 0){
      if(tokenStream[currIndex] -> get_token_string() == "("){
        conditionExpression -> addElement(tokenStream[currIndex]);
        bracketPolarity ++;
        currIndex ++;
        if(checkIfIndexOverflows()){
          std::cout << "Expected a closing bracket, but was not found at line: " << tokenStream[currIndex] -> get_token_string() << '\n';
          //exit(0);
        }
      }
      else if(tokenStream[currIndex] -> get_token_string() == ")"){
        conditionExpression -> addElement(tokenStream[currIndex]);
        bracketPolarity --;
        currIndex ++;
        if(checkIfIndexOverflows()){
          std::cout << "Expected a closing bracket, but was not found at line: " << tokenStream[currIndex] -> get_token_string() << '\n';
          //exit(0);
        }
      }
      else{
        conditionExpression -> addElement(tokenStream[currIndex]);
        currIndex ++;
        if(checkIfIndexOverflows()){
          std::cout << "Expected a closing bracket, but was not found at line: " << tokenStream[currIndex] -> get_token_string() << '\n';
          //exit(0);
        }
      }


      if(bracketPolarity < 0){
        std::cout << "Extra Bracket at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
        //exit(0);
      }
    }
    

    // FOR THE BODY OF THE IF
    //currIndex ++; // THIS WAS COMMENTED JUST NOW
      
    // ADD THE CONDITION EXPRESSION TO THE IF STATEMENT AFTER CREATION 
    tempExpressionPointerHolder -> addCheckCondition(conditionExpression);
    
    exitIfBracketPolarityWrong(bracketPolarity);
    
    // FOR THE BODY OF THE IF
    //


    if(checkIfIndexOverflows()){
      std::cout << "Missing brace after the if declaration at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
      //exit(0);
    }

    if(tokenStream[currIndex] -> get_token_string() == "{"){
      currIndex ++;
      bracePolarity ++;
      if(checkIfIndexOverflows()){
        std::cout << "Missing statement after the if declaration at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
        //exit(0);
      }
      beginStatement();
    }
    else{
      std::cout << "Incorrect syntax for if statement at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
      std::cout << tokenStream[currIndex] -> get_token_string() << " was encountered\n";
      //exit(0);
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
      //exit(0);
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
        //exit(0);
      }
    }
    else{
      std::cout << "Missing bracket for else if at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
      //exit(0);
    }

    // Check for bracket polarity while fetching expression elements and adding them to the conditionExpression
    while(bracketPolarity > 0){
      if(tokenStream[currIndex] -> get_token_string() == "("){
        conditionExpression -> addElement(tokenStream[currIndex]);
        bracketPolarity ++;
        currIndex ++;
        if(checkIfIndexOverflows()){
          std::cout << "Expected a closing bracket, but was not found at line: " << tokenStream[currIndex] -> get_token_string() << '\n';
          //exit(0);
        }
      }
      else if(tokenStream[currIndex] -> get_token_string() == ")"){
        conditionExpression -> addElement(tokenStream[currIndex]);
        bracketPolarity --;
        currIndex ++;
        if(checkIfIndexOverflows()){
          std::cout << "Expected a closing bracket, but was not found at line: " << tokenStream[currIndex] -> get_token_string() << '\n';
          //exit(0);
        }
      }
      else{
        conditionExpression -> addElement(tokenStream[currIndex]);
        currIndex ++;
        if(checkIfIndexOverflows()){
          std::cout << "Expected a closing bracket, but was not found at line: " << tokenStream[currIndex] -> get_token_string() << '\n';
          //exit(0);
        }
      }


      if(bracketPolarity < 0){
        std::cout << "Extra Bracket at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
        //exit(0);
      }
    }
      
    // FOR THE BODY OF THE ELSE IF
    currIndex ++;
    // ADD THE CONDITION EXPRESSION TO THE IF STATEMENT AFTER CREATION 
    tempExpressionPointerHolder -> addCheckCondition(conditionExpression);
    
    exitIfBracketPolarityWrong(bracketPolarity);
    

    if(checkIfIndexOverflows()){
      std::cout << "Missing brace after the else if declaration at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
      //exit(0);
    }


    if(tokenStream[currIndex] -> get_token_string() == "{"){
      currIndex ++;
      bracePolarity ++;
      if(checkIfIndexOverflows()){
        std::cout << "Missing statement after the else if declaration at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
        //exit(0);
      }
      beginStatement();
    }
    else{
      std::cout << "Incorrect syntax for if statement at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
      //exit(0);
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
      //exit(0);
    }

    std::shared_ptr<ELSE> tempExpressionPointerHolder = std::static_pointer_cast<ELSE>(standingExpressionPointer);
    checkIfCastingSuccessful(tempExpressionPointerHolder);


    // FOR THE BODY OF THE ELSE STATEMENT
    //currIndex ++;

    if(tokenStream[currIndex] -> get_token_string() == "{"){
      bracePolarity ++;
      currIndex ++;
      beginStatement();
    }
    else{
      std::cout << "Incorrect syntax for else statement at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
      //exit(0);
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
      //exit(0);
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
        //exit(0);
      }
    }
    else{
      std::cout << "Missing bracket for while at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
      //exit(0);
    }

    // Check for bracket polarity while fetching expression elements and adding them to the conditionExpression
    while(bracketPolarity > 0){
      if(tokenStream[currIndex] -> get_token_string() == "("){
        conditionExpression -> addElement(tokenStream[currIndex]);
        bracketPolarity ++;
        currIndex ++;

        if(checkIfIndexOverflows()){
          std::cout << "Expected a closing bracket, but was not found at line: " << tokenStream[currIndex] -> get_token_string() << '\n';
          //exit(0);
        }
      }
      else if(tokenStream[currIndex] -> get_token_string() == ")"){
        conditionExpression -> addElement(tokenStream[currIndex]);
        bracketPolarity --;
        currIndex ++;
        if(checkIfIndexOverflows()){
          std::cout << "Expected a closing bracket, but was not found at line: " << tokenStream[currIndex] -> get_token_string() << '\n';
          //exit(0);
        }
      }
      else{
        conditionExpression -> addElement(tokenStream[currIndex]);
        currIndex ++;
        if(checkIfIndexOverflows()){
          std::cout << "Expected a closing bracket, but was not found at line: " << tokenStream[currIndex] -> get_token_string() << '\n';
          //exit(0);
        }
      }


      if(bracketPolarity < 0){
        std::cout << "Extra Bracket at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
        //exit(0);
      }
    }
      
    // FOR THE BODY OF THE WHILE
    //currIndex ++;
    // ADD THE CONDITION EXPRESSION TO THE IF STATEMENT AFTER CREATION 
    tempExpressionPointerHolder -> addCheckCondition(conditionExpression);
    
    // FOR THE BODY OF THE WHILE
    //currIndex ++;
   
    exitIfBracketPolarityWrong(bracketPolarity);

    if(checkIfIndexOverflows()){
      std::cout << "Missing brace after the else if declaration at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
      //exit(0);
    }


    if(tokenStream[currIndex] -> get_token_string() == "{"){
      currIndex ++;
      bracePolarity ++;
      if(checkIfIndexOverflows()){
        std::cout << "Missing statement after the while declaration at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
        //exit(0);
      }
      beginStatement();
    }
    else{
      std::cout << "Missing brace for while statement at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
      //exit(0);
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
        //exit(0);
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
          //exit(0);
        }
      }
    }

    //currIndex ++;
    if(checkIfIndexOverflows()){
      std::cout << "Missing brace after function declaration at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
      //exit(0);
    }

    if(tokenStream[currIndex] -> get_token_string() == "{"){
      currIndex ++;
      bracePolarity ++;
      if(checkIfIndexOverflows()){
        std::cout << "Missing statement after the while declaration at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
        //exit(0);
      }
      beginStatement();
    }
    else{
      std::cout << "Incorrect syntax for while statement at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
      //exit(0);
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
      //exit(0);
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
      //exit(0);
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
        std::cout << "Finished minorStatement??? \n";
        std::cout << currIndex << '\n';
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
      //exit(0);
    }

    currIndex ++;
    if(checkIfIndexOverflows()){
      std::cout << "Finished minorStatement in last step??? \n";
      std::cout << currIndex << '\n';
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
      //exit(0);
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
        //exit(0);
      }
    }
    else{
      std::cout << "Missing bracket for while at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
      //exit(0);
    }

    // Check for bracket polarity while fetching expression elements and adding them to the conditionExpression
    while(bracketPolarity > 0){
      if(tokenStream[currIndex] -> get_token_string() == "("){
        tempExpressionPointerHolder -> addElement(tokenStream[currIndex]);
        bracketPolarity ++;
        currIndex ++;
        if(checkIfIndexOverflows()){
          std::cout << "Expected a closing bracket, but was not found at line: " << tokenStream[currIndex] -> get_token_string() << '\n';
          //exit(0);
        }
      }
      else if(tokenStream[currIndex] -> get_token_string() == ")"){
        tempExpressionPointerHolder -> addElement(tokenStream[currIndex]);
        bracketPolarity --;
        currIndex ++;
        if(checkIfIndexOverflows()){
          std::cout << "Expected a closing bracket, but was not found at line: " << tokenStream[currIndex] -> get_token_string() << '\n';
          //exit(0);
        }
      }
      else{ 

        tempExpressionPointerHolder -> addElement(tokenStream[currIndex]);
        currIndex ++;
        if(checkIfIndexOverflows()){
          std::cout << "Expected a closing bracket, but was not found at line: " << tokenStream[currIndex] -> get_token_string() << '\n';
          //exit(0);
        }
      }


      if(bracketPolarity < 0){
        std::cout << "Extra Bracket at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
        //exit(0);
      }
    }




    if(tokenStream[currIndex] -> get_token_string() == ";"){
      currIndex ++;
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
      //exit(0);
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
        //exit(0);
      }
    }
    else{
      std::cout << "Missing bracket for while at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
      //exit(0);
    }

    // Check for bracket polarity while fetching expression elements and adding them to the conditionExpression
    
    while(bracketPolarity > 0){
      //std::cout << "So are we in an infinite loop?\n";
      if(tokenStream[currIndex] -> get_token_string() == "("){
        tempExpressionPointerHolder -> addElement(tokenStream[currIndex]);
        bracketPolarity ++;
        currIndex ++;
        if(checkIfIndexOverflows()){
          std::cout << "Expected a closing bracket, but was not found at line: " << tokenStream[currIndex] -> get_token_string() << '\n';
          //exit(0);
        }
      }
      else if(tokenStream[currIndex] -> get_token_string() == ")"){
        tempExpressionPointerHolder -> addElement(tokenStream[currIndex]);
        bracketPolarity --;
        currIndex ++;
        if(checkIfIndexOverflows()){
          std::cout << "Expected a closing bracket, but was not found at line: " << tokenStream[currIndex] -> get_token_string() << '\n';
          //exit(0);
        }
      }
      else{ 
        tempExpressionPointerHolder -> addElement(tokenStream[currIndex]);
        currIndex ++;
        if(checkIfIndexOverflows()){
          std::cout << "Expected a closing bracket, but was not found at line: " << tokenStream[currIndex] -> get_token_string() << '\n';
          //exit(0);
        }
      }


      if(bracketPolarity < 0){
        std::cout << "Extra Bracket at line: " << tokenStream[currIndex] -> get_line_occurence() << '\n';
        //exit(0);
      }
    }


    //currIndex ++;

    if(tokenStream[currIndex] -> get_token_string() == ";"){
      currIndex ++;
      beginStatement();
    }
  }





public:
  void getTokenStream(std::vector<std::shared_ptr<Token>>* newTokenStream){
    tokenStream = *newTokenStream;
  }

  void parse(){
    rootMother = std::make_shared<GeneralExpression>();
    standingExpressionPointer = rootMother;
    //rootMother = standingExpressionPointer
    beginStatement();
    std::cout << '\n';
    std::cout << "<<<<<Parsed successfully!>>>>>\n";
    std::cout << '\n';
  }

  void showParseTree(){
    // THIS ONE WILL PROBABLY BE REMOVED AFTER USING THE BASE SLIDER 
    if(rootMother){
      std::cout << "So it is not null!\n";
    }
    currGeneralNode = rootMother;

    // THE BASE SLIDER
    //currBaseNode = rootMother;
    //currSliderNode = rootMother;

  } 
  /*
  void createParseTree(){
    //initializeRoot(); // THIS PART WAS REPLACED BY MAIN_BODY

    rootMother = std::make_shared<GeneralExpression>();
    beginStatement();
  }
  */

  std::shared_ptr<GeneralExpression> getParseTree(){
    return rootMother;
  }



  // TREE WALKER RELATED


  std::shared_ptr<GeneralExpression> currGeneralNode = nullptr;

  std::shared_ptr<GeneralExpression> currBaseNode = nullptr; 
  std::shared_ptr<GeneralExpression> currSliderNode = nullptr;
    
  std::shared_ptr<FOR> currForNode = nullptr;
  std::shared_ptr<IF> currIfNode = nullptr;
  std::shared_ptr<ELSE_IF> currElseIfNode = nullptr;
  std::shared_ptr<ELSE> currElseNode = nullptr;
  std::shared_ptr<WHILE> currWhileNode = nullptr;
  std::shared_ptr<FUNCTION> currFunctionNode = nullptr;
  std::shared_ptr<Action> currActionNode = nullptr;
  std::shared_ptr<Expression> currExpressionNode = nullptr;
  std::shared_ptr<MINOR_STATEMENT> currMinorStatementNode = nullptr;

  //long unsigned int standingIndex;


  void walkAcrossTree(){
    // SLIDER AND BASE METHOD
    if(!(currGeneralNode -> expressionBody.empty())){
      // GO TO SUB NODE (DOWN)
      std::cout << currGeneralNode -> typeName << "<<<<contains: >>>>" << '\n';
      currGeneralNode = currGeneralNode -> expressionBody[currGeneralNode -> lastIndexVisited];
      currGeneralNode -> lastParentExpression -> lastIndexVisited ++;
    }
    else if(currGeneralNode -> lastIndexVisited < currGeneralNode -> expressionBody.size()){
      // GO TO THE ADJACENT NODES (SIDE)
      std::cout << currGeneralNode -> typeName << "is adjacent to: \n";
      currGeneralNode = currGeneralNode -> expressionBody[currGeneralNode -> lastIndexVisited];
    }
    else{
      // GO BACK TO PARENT NODE (UP)
      std::cout << "<<<<decontains: >>>>" << '\n';
      currGeneralNode = currGeneralNode -> lastParentExpression;
    }

    
    /*
    if(!(currGeneralNode -> expressionBody.empty())){
      // GO DEEPER
      std::cout << currGeneralNode -> typeName << " <<<<contains: >>>>" << '\n';
      standingIndex = currGeneralNode -> lastIndexVisited; 
      //currGeneralNode -> lastIndexVisited ++;
      currGeneralNode = currGeneralNode -> expressionBody[0];
    }
    else if(currGeneralNode -> lastIndexVisited < currGeneralNode -> expressionBody.size()){
      // GO RIGHT 
      std::cout << '\n';
      std::cout << currGeneralNode -> typeName << " is just the next statement: " << '\n';
      std::cout << '\n';
      standingIndex ++;
      currGeneralNode = currGeneralNode -> expressionBody[]
    }
    else if(standingIndex >= currGeneralNode -> expressionBody.size() || (currGeneralNode -> expressionBody.empty())){
      // GO UP 
      std::cout << '\n';
      std::cout << currGeneralNode -> typeName << " <<<<DEcontains: >>>>" << '\n';
      std::cout << '\n';
      currGeneralNode = currGeneralNode -> lastParentExpression;
      // Increment after going up
      currGeneralNode -> lastIndexVisited ++;
    }
    else{
      std::cout << "How is this even possible??????\n";
    }
    */

    // EXTRAPOLATE THE NODE
    if(currGeneralNode -> typeName == "FOR"){
      currForNode = std::static_pointer_cast<FOR>(currGeneralNode);
      //currForNode -> lastIndexVisited ++;
      currForNode -> displayElements();
      walkAcrossTree();
    }
    else if(currGeneralNode -> typeName == "IF"){
      currIfNode = std::static_pointer_cast<IF>(currGeneralNode);
      //currIfNode -> lastIndexVisited ++; 
      currIfNode -> displayElements();
      walkAcrossTree();
    }
    else if(currGeneralNode -> typeName == "ELSE IF"){
      currElseIfNode = std::static_pointer_cast<ELSE_IF>(currGeneralNode);
      //currElseIfNode -> lastIndexVisited ++;
      currElseIfNode -> displayElements();
      walkAcrossTree();
    }
    else if(currGeneralNode -> typeName == "ELSE"){
      currElseNode = std::static_pointer_cast<ELSE>(currGeneralNode);
      //currElseNode -> lastIndexVisited ++;
      walkAcrossTree();
    }
    else if(currGeneralNode -> typeName == "WHILE"){
      currWhileNode = std::static_pointer_cast<WHILE>(currGeneralNode);
      //currWhileNode -> lastIndexVisited ++;
      currWhileNode -> displayElements();
      walkAcrossTree();
    }
    else if(currGeneralNode -> typeName == "FUNCTION"){
      currFunctionNode = std::static_pointer_cast<FUNCTION>(currGeneralNode);
      //currFunctionNode -> lastIndexVisited ++;
      currFunctionNode -> displayElements();
      walkAcrossTree();
    }
    else if(currGeneralNode -> typeName == "Action"){
      currActionNode = std::static_pointer_cast<Action>(currGeneralNode);
      //currActionNode -> lastIndexVisited ++;
      currActionNode -> displayElements();
      walkAcrossTree();
    }
    else if(currGeneralNode -> typeName == "Expression"){
      currExpressionNode = std::static_pointer_cast<Expression>(currGeneralNode);
      //currExpressionNode -> lastIndexVisited ++;
      currExpressionNode -> displayElements();
      walkAcrossTree();
    }
    else if(currGeneralNode -> typeName == "MINOR_STATEMENT"){
      currMinorStatementNode  = std::static_pointer_cast<MINOR_STATEMENT>(currGeneralNode);
      //currMinorStatementNode -> lastIndexVisited ++;
      currMinorStatementNode -> displayElements();
      walkAcrossTree();
    }
    else{
      std::cout << "MET A RAW GENERAL EXPRESSION????????????????? IS THIS EVEN POSSIBLE?????\n";
    }
  }















};
