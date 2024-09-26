#pragma once
#include <bits/stdc++.h>
#include "../lexer/lexer.hpp"
#include "grammar.hpp"






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





class CodeUnit{
public:
  std::shared_ptr<CodeUnit> parent;
  std::deque<std::shared_ptr<CodeUnit>> codeBody; 

  friend class FunctionUnit;
  friend class ForUnit;
  friend class WhileUnit;
  friend class IfUnit; 
};

class FunctionUnit : public CodeUnit{
public:
  std::string functionName;
  std::vector<std::string> parameters;
};

class VariableUnit : public CodeUnit{
public:
  std::string variableName;
  std::vector<std::shared_ptr<Token>> expression;
};

class ForUnit : public CodeUnit{
public:
  std::string counterVariableName;

  std::vector<std::shared_ptr<Token>> initialExpression;

  std::vector<std::shared_ptr<Token>> endExpression;

  std::vector<std::shared_ptr<Token>> incremenetExpression;

};

class WhileUnit : public CodeUnit{
public:
  std::vector<std::shared_ptr<Token>> endExpression;
};

class IfUnit : public CodeUnit{
public:
  std::vector<std::shared_ptr<Token>> conditionExpression; 
};

class ElseIfUnit : public CodeUnit{
public:
  std::vector<std::shared_ptr<Token>> conditionExpression;
};

class ElseUnit : public CodeUnit{
public:
  std::vector<std::shared_ptr<Token>> conditionExpression;
};

class SwitchUnit : public CodeUnit{
public:
  std::vector<std::shared_ptr<Token>> jumpExpression;
  std::unordered_map<std::string, std::shared_ptr<CodeUnit>> cases;
};







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
    initStatement();
  }

  void debugParseTree(){
    // THIS METHOD EXISTS ONLY FOR DEBUGGING
  }

  std::shared_ptr<CodeUnit> getParseTree(){
    return parseTreeRoot;
  }

  WeakTParser() {}

private:
  // GRAMMAR CHECKERS
  friend class WhileGrammarChecker;
  friend class ForGrammarChecker;
  friend class IfGrammarChecker;
  friend class FunctionGrammarChecker;

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
      else rulesContainerSingeltonObject.grammarSelectorMap["<<<MUTABLE>>>"] -> checkGrammar(this);
    }
  }
};
