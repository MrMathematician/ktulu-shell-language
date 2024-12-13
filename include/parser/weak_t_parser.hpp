#pragma once
#include <bits/stdc++.h>
#include "../lexer/lexer.hpp"
#include "units.hpp"





class WeakTParser;


class GrammarChecker{
public:
  WeakTParser* parser;

  intmax_t bracketPolarity = 0;
  virtual void checkGrammar(WeakTParser* parser) {}

  friend WeakTParser;
};





class RulesContainerSingelton{
private:
  static RulesContainerSingelton globalInstance;

public:
  std::unordered_map<std::string, std::shared_ptr<GrammarChecker>> grammarSelectorMap;

  static RulesContainerSingelton& getGlobalInstance(){
    return globalInstance; 
  }

  void addRule(std::string ruleEntry, std::shared_ptr<GrammarChecker> ruleChecker){
    grammarSelectorMap[ruleEntry] = ruleChecker;
  }
};



extern RulesContainerSingelton& rulesContainerSingeltonObject;







class DequeDataStructureString{
public:
  std::deque<std::shared_ptr<DequeDataStructureString>> subDeque;
  std::string heldValue; 
};

class DequeDataStructureNumber{
public:
  std::deque<std::shared_ptr<DequeDataStructureNumber>> subDeque;
  double heldValue; 
};





class WeakTParser{
public:
  void inputTokenStream(std::deque<std::shared_ptr<Token>>* inpuTokenStream){
    tokenStream = inpuTokenStream; 
  }

  void parse(){
    parseTreeRoot = std::make_shared<CodeUnit>();
    traversalUnit = parseTreeRoot;
    traversalUnit -> unitName = "<main>";
    initStatement();
  }

  void debugParseTree(){
    // THIS METHOD EXISTS ONLY FOR DEBUGGING
  }

  std::shared_ptr<CodeUnit> getParseTree(){
    return parseTreeRoot;
  }

  WeakTParser(){}

private:
  // GRAMMAR CHECKERS
  friend class WhileGrammarChecker;
  friend class ForGrammarChecker;
  friend class IfGrammarChecker;
  friend class ElseIfGrammarChecker;
  friend class ElseGrammarChecker;
  friend class FunctionGrammarChecker;
  friend class SwitchGrammarChecker; 

  // TOKENSTREAM_PTR
  std::deque<std::shared_ptr<Token>>* tokenStream;

  // PRIMITIVE DATATYPES
  std::unordered_map<std::string, double> numberVariableMap; 
  std::unordered_map<std::string, std::string> stringVariableMap;

  // DATASTRUCTURES
  std::unordered_map<std::string, std::shared_ptr<DequeDataStructureString>> dequeDataStructureStringMap;
  std::unordered_map<std::string, std::shared_ptr<DequeDataStructureNumber>> dequeDataStructureNumberMap;

  // FUNCTIONS
  std::unordered_map<std::string, std::shared_ptr<FunctionUnit>> functionsMap;

  // STATEMENT TRACKER STACK // THIS WILL BE REMOVED
  std::stack<std::string> statemenetLevelStack;
  
  // PARSE TREE ROOT
  std::shared_ptr<CodeUnit> parseTreeRoot;

  // TREE TRAVERSAL VARIABLE
  std::shared_ptr<CodeUnit> traversalUnit;

  size_t scriptIndex = 0;

  bool isAtSuccessfulCompletion(){
    if(scriptIndex == tokenStream -> size()){
      return true;
    }
    return false;
  }



  std::string currString;
  std::shared_ptr<Token> currToken;

  void updateCurrent(){
    scriptIndex ++;
    if(scriptIndex == tokenStream -> size()) exit(0); // OUT OF BOUNDS ERROR
    currString = tokenStream -> at(scriptIndex) -> getTokenString();
    currToken = tokenStream -> at(scriptIndex);
  }



  void initStatement(){
    while(true){
      if(isAtSuccessfulCompletion()) return;

      if(rulesContainerSingeltonObject.grammarSelectorMap.count(currString)){
        rulesContainerSingeltonObject.grammarSelectorMap[currString] -> checkGrammar(this);
        continue;
      }
      else if(currString == "}"){
        traversalUnit = traversalUnit -> parent;
        if(statemenetLevelStack.empty()) exit(0); // ERROR MESSAGE GOES HERE
        else statemenetLevelStack.pop();
      }
      else rulesContainerSingeltonObject.grammarSelectorMap["<<<MUTABLE>>>"] -> checkGrammar(this);
    }
  }
};







class ForGrammarChecker : public GrammarChecker{
private:
  std::shared_ptr<ForUnit> createdUnit;

  void checkInitialExpression(){
    parser -> updateCurrent();
    if(parser -> currString != "create") exit(0); // ERROR MESSAGE GOES HERE

    parser -> updateCurrent();
    if(parser -> currToken -> getTokenGeneralType() != tokenType :: LITERAL) exit(0); // ERROR MESSAGE GOES HERE
    createdUnit -> counterVariableName = parser -> currString;
    
    parser -> updateCurrent();
    if(parser -> currString != "=") exit(0); // ERROR MESSAGE GOES HERE
   
    parser -> updateCurrent();
    while(parser -> currString != ";"){
      if(parser -> currString == "(") bracketPolarity ++;
      if(parser -> currString == ")") bracketPolarity --;
      if(bracketPolarity == 0) exit(0); // ERROR MESSAGE GOES HERE

      createdUnit -> initialExpression.push_back(parser -> currToken);
      parser -> updateCurrent();
    }
  }

  void checkEndExpression(){
    parser -> updateCurrent();
    while(parser -> currString != ";"){
      if(parser -> currString == "(") bracketPolarity ++;
      if(parser -> currString == ")") bracketPolarity --;
      if(bracketPolarity == 0) exit(0); // ERROR MESSAGE GOES HERE

      createdUnit -> endExpression.push_back(parser -> currToken);
      parser -> updateCurrent();
    }
  }

  void checkIncrementExpression(){
    parser -> updateCurrent();
    while(bracketPolarity != 0){
      if(parser -> currString == "(") bracketPolarity ++;
      if(parser -> currString == ")") bracketPolarity --;
      if(!bracketPolarity) return;

      createdUnit -> incremenetExpression.push_back(parser -> currToken);
      parser -> updateCurrent();
    }
  }

public:
  void checkGrammar(WeakTParser* inputParser) override{
    parser = inputParser;

    createdUnit = std::make_shared<ForUnit>();
    createdUnit -> unitName = "for";
   
    parser -> traversalUnit -> codeBody.push_back(createdUnit);
    parser -> traversalUnit = createdUnit;


    parser -> statemenetLevelStack.push("for");

    parser -> updateCurrent();
    if(parser -> currString == "(") bracketPolarity ++;
    else exit(0); // ERROR MESSAGE GOES HERE

    checkInitialExpression();
    checkEndExpression();
    checkIncrementExpression();
    
    parser -> updateCurrent();
    
    if(parser -> currString != "{") exit(0); // ERROR MESSAGE GOES HERE
    parser -> updateCurrent();
  }
};



class WhileGrammarChecker : public GrammarChecker{
private:
  std::shared_ptr<WhileUnit> createdUnit; 

  void checkEndExpression(){
    parser -> updateCurrent();

    while(bracketPolarity != 0){
      if(parser -> currString == "(") bracketPolarity ++;
      if(parser -> currString == ")") bracketPolarity --;
      if(!bracketPolarity) return;

      createdUnit -> endExpression.push_back(parser -> currToken);
      parser -> updateCurrent();
    }
  }

public:
  void checkGrammar(WeakTParser* inputParser) override{
    parser = inputParser;

    createdUnit = std::make_shared<WhileUnit>();
    createdUnit -> unitName = "while";
   
    parser -> traversalUnit -> codeBody.push_back(createdUnit);
    parser -> traversalUnit = createdUnit;


    parser -> statemenetLevelStack.push("while");

    parser -> updateCurrent();
    if(parser -> currString == "(") bracketPolarity ++;
    else exit(0); // ERROR MESSAGE GOES HERE

    checkEndExpression();

    parser -> updateCurrent();

    if(parser -> currString != "{") exit(0); // ERROR MESSAGE GOES HERE
    parser -> updateCurrent();
  }
};



class IfGrammarChecker : public GrammarChecker{
private: 
  std::shared_ptr<IfUnit> createdUnit;

  void checkIfCondition(){
    parser -> updateCurrent();

    while(bracketPolarity != 0){
      if(parser -> currString == "(") bracketPolarity ++;
      if(parser -> currString == ")") bracketPolarity --;
      if(!bracketPolarity) return;

      createdUnit -> conditionExpression.push_back(parser -> currToken);
      parser -> updateCurrent();
    }


  }

public:
  void checkGrammar(WeakTParser* inputParser) override{
    parser = inputParser;

    createdUnit = std::make_shared<IfUnit>();
    createdUnit -> unitName = "if";

    parser -> traversalUnit -> codeBody.push_back(createdUnit);
    parser -> traversalUnit = createdUnit;

    parser -> statemenetLevelStack.push("if");

    parser -> updateCurrent();
    if(parser -> currString == "(") bracketPolarity ++;
    else exit(0); // ERROR MESSAGE GOES HERE

    checkIfCondition();
    
    parser -> updateCurrent();

    if(parser -> currString != "{") exit(0); // ERROR MESSAGE GOES HERE
  
    parser -> updateCurrent();
  }
};

class ElseIfGrammarChecker : public GrammarChecker{
private: 
  std::shared_ptr<ElseIfUnit> createdUnit;

  void checkIfCondition(){
    parser -> updateCurrent();

    while(bracketPolarity != 0){
      if(parser -> currString == "(") bracketPolarity ++;
      if(parser -> currString == ")") bracketPolarity --;
      if(!bracketPolarity) return;

      createdUnit -> conditionExpression.push_back(parser -> currToken);
      parser -> updateCurrent();
    }
  }

public:
  void checkGrammar(WeakTParser* inputParser) override{
    parser = inputParser;

    if(parser -> traversalUnit -> codeBody.back() -> unitName != "if") exit(0); // ERROR MESSAGE GOES HERE

    createdUnit = std::make_shared<ElseIfUnit>();
    createdUnit -> unitName = "else if";

    parser -> traversalUnit -> codeBody.push_back(createdUnit);
    parser -> traversalUnit = createdUnit;

    parser -> statemenetLevelStack.push("else if");

    parser -> updateCurrent();
    if(parser -> currString == "(") bracketPolarity ++;
    else exit(0); // ERROR MESSAGE GOES HERE

    checkIfCondition();
    
    parser -> updateCurrent();

    if(parser -> currString != "{") exit(0); // ERROR MESSAGE GOES HERE
  
    parser -> updateCurrent();
  }
};

class ElseGrammarChecker : public GrammarChecker{
private:
  std::shared_ptr<ElseUnit> createdUnit;
public:
  void checkGrammar(WeakTParser* inputParser) override{
    parser = inputParser;

    if(parser -> traversalUnit -> codeBody.back() -> unitName != "if" 
    || parser -> traversalUnit -> codeBody.back() -> unitName != "else if") exit(0); // ERROR MESSAGE GOES HERE

    createdUnit = std::make_shared<ElseUnit>();
    createdUnit -> unitName = "else";

    parser -> traversalUnit -> codeBody.push_back(createdUnit);
    parser -> traversalUnit = createdUnit;

    parser -> statemenetLevelStack.push("else");

    parser -> updateCurrent();

    if(parser -> currString != "{") exit(0); // ERROR MESSAGE GOES HERE
  
    parser -> updateCurrent();
  }
};

class FunctionGrammarChecker : public GrammarChecker{
private:
  std::shared_ptr<FunctionUnit> createdUnit;

  void setArgs(){
    while(true){
      if(parser -> currString == ")") return;
      
      if(parser -> currString == ",") exit(0); // ERROR MESSAGE GOES HERE // USE CURRENT TOKEN TO GET TYPE INSTEAD
      // CONTINUE HERE
      parser -> updateCurrent();
      if(parser -> currToken -> getTokenGeneralType() == )
      
    }
  }

  void checkFunctionValidity(){
    if(parser -> currString == "(") exit(0); // ERROR MESSAGE GOES HERE
    
    parser -> functionsMap[parser -> currString] = createdUnit;
    parser -> updateCurrent();
    
    if(parser -> currString != "(") exit(0); //ERROR MESSAGE GOES HERE
    parser -> updateCurrent();
    
    setArgs();

     
  }
public:
  void checkGrammar(WeakTParser* inputParser) override{
    parser = inputParser;  

    createdUnit = std::make_shared<FunctionUnit>();
    createdUnit -> unitName = "funct";
    
    parser -> traversalUnit -> codeBody.push_back(createdUnit);
    parser -> traversalUnit = createdUnit;
    
    parser -> statemenetLevelStack.push("funct");

    parser -> updateCurrent();

    if(parser -> currString != "(") exit(0); // ERROR MESSAGE GOES HERE
    checkFunctionValidity();
    
    parser -> updateCurrent();
  }
};
/*
class VariableDeclarationChecker : public GrammarChecker{
private:
  std::shared_ptr<VariableUnit> createdUnit;
public:
  void checkGrammar(WeakTParser* inputParser) override{
    parser = inputParser;
  }
};
*/
class VariableMutationChecker : public GrammarChecker{
private:
  std::shared_ptr<VariableUnit> createdUnit;
public:
  void checkGrammar(WeakTParser* inputParser) override{
    // IT COULD BE A FUNCTION CALL OR A VARIABLE MUTATION OR CREATION
    parser = inputParser;

  }
};

class SwitchGrammarChecker : public GrammarChecker{
private:
  std::shared_ptr<SwitchUnit> createdUnit;
public:
  void checkGrammar(WeakTParser* inputParser) override{
    parser = inputParser;
  }
};

class CaseGrammarChecker : public GrammarChecker{
// COPY THE TRAVERSAL UNIT INTO A TEMP
// CASE THE TEMP DYNAMICALLY INTO A SWITCH
// ADD THE CASE TO THE HASHMAP
public:
  void checkGrammar(WeakTParser* inputParser) override{

  }
};

class PrintGrammarChecker : public GrammarChecker{
public:
  void checkGrammar(WeakTParser* inputPraser) override{
    parser = inputPraser;
  }
};

class InputGrammarChecker : public GrammarChecker{
  
};

class CommandGrammarChecker : public GrammarChecker{

};
