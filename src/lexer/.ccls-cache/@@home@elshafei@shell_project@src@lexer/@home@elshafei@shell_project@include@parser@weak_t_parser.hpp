#pragma once
#include <bits/stdc++.h>
#include "../lexer/lexer.hpp"
#include "grammar.hpp"






class RulesContainerSingelton{
private:
  static RulesContainerSingelton globalInstance;

  std::unordered_map<std::string, GrammarChecker> grammarSelectorMap;

public:
  static RulesContainerSingelton& getGlobalInstance(){
    return globalInstance; 
  }

  void addRule(std::string& ruleEntry, GrammarChecker& ruleChecker){
    grammarSelectorMap[ruleEntry] = ruleChecker;
  }
};



extern RulesContainerSingelton& rulesContainerSingeltonObject;





class CodeUnit{
private:
  std::shared_ptr<CodeUnit> parent;
  std::deque<std::shared_ptr<CodeUnit>> codeBody; 

  friend class FunctionUnit;
  friend class ForUnit;
  friend class WhileUnit;
  friend class IfUnit; 
};

class FunctionUnit : public CodeUnit{
  std::string functionName;
  std::deque<std::string> parameters;
};

class VariableUnit : public CodeUnit{
  bool newlyDefined;
  std::string variableName;
  std::string attributedValue;
};

class ForUnit : public CodeUnit{
  std::string counterVariableName;
  std::vector<std::shared_ptr<Token>> initialExpression;

  std::vector<std::shared_ptr<Token>> endExpression;

  std::vector<std::shared_ptr<Token>> incremenetExpression;

};

class WhileUnit : public CodeUnit{
  std::vector<std::shared_ptr<Token>> endExpression;
};

class IfUnit : public CodeUnit{
  std::vector<std::shared_ptr<Token>> conditionExpression; 
};

class SwitchUnit : public CodeUnit{
  std::vector<std::shared_ptr<Token>> jumpExpression;
  std::unordered_map<std::string, std::shared_ptr<CodeUnit>> cases;
};







class DequeDataStructureString{
  std::deque<std::shared_ptr<DequeDataStructureString>> subDeque;
  std::string heldValue; 
};

class DequeDataStructureNumber{
  std::deque<std::shared_ptr<DequeDataStructureNumber>> subDeque;
  double heldValue; 
};





class WeakTParser{
public:
  void getTokenStream(std::deque<std::shared_ptr<Token>>* inpuTokenStream){
    tokenStream = inpuTokenStream; 
  }

  void parse(){
    initStatement();
  }

  void traverseParseTree(){
    // THIS METHOD EXISTS ONLY FOR DEBUGGING
  }

  WeakTParser() {}

private:
  // GRAMMAR CHECKERS
  friend class WhileGrammarChecker;
  friend class ForGrammerChecker;
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


  
  // PARSER INSIDER VARIABLES
  enum class currentBody{
    NORM,
    FOR,
    WHILE,
    IF,
    ELSE,
    ELSE_IF,
    SWITCH,
    VAR_DEC,
    FUNCTION
  };
  
  // COUNTER VARIABLES
  intmax_t curvedBracketPolarity;
  intmax_t curlyBracePolarity;
  currentBody grammarStatement;

  size_t scriptIndex = 0;

  bool isAtSuccessfulCompletion(){
    if(scriptIndex == tokenStream -> size()){
      return true;
    }
    return false;
  }


  // USE THE A HASH MAP TO MAP A STRING TO A CLASS, THE CLASS INHERITS FROM ANOTHER PARENT CLASS WHERE METHODS ARE OVERRIDDEN EVERY TIME
  // A POINTER TO THIS CLASS IS PASSED TO THAT CLASS, WHERE scritpIndex IS MODIFIED.
  // THIS WILL ENSURE A PROPER DECOUPLING


  void initStatement(){
    while(true){
      if(isAtSuccessfulCompletion()) return;
       


    }
  }

















};
