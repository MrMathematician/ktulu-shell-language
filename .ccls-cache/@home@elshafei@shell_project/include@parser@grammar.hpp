#pragma once
#include "weak_t_parser.hpp"

class WeakTParser;


class GrammarChecker{
public:
  virtual void checkGrammar(WeakTParser* parser) {}

  friend WeakTParser;
};





class ForGrammarChecker : public GrammarChecker{
private:
  std::shared_ptr<ForUnit> createdUnit;
  intmax_t bracketPolarity = 0;

  void checkInitialExpression(){

  }

  void checkIncremenetExpression(){

  }

  void checkEnd
public:
  void checkGrammar(WeakTParser* parser) override{
    createdUnit = std::make_shared<ForUnit>();

    parser -> statemenetLevelStack.push("for");

    parser -> updateCurrent();
    if(parser -> currString == "(") bracketPolarity ++;
    else exit(0); // ERROR MESSAGE GOES HERE

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

    parser -> updateCurrent();
    while(parser -> currString != ";"){
      if(parser -> currString == "(") bracketPolarity ++;
      if(parser -> currString == ")") bracketPolarity --;
      if(bracketPolarity == 0) exit(0); // ERROR MESSAGE GOES HERE

      createdUnit -> incremenetExpression.push_back(parser -> currToken);
      parser -> updateCurrent();
    }
    
    parser -> updateCurrent();
    
  }
};

class WhileGrammarChecker : public GrammarChecker{
public:
  void checkGrammar(WeakTParser* parser) override{

  }
};

class IfGrammarChecker : public GrammarChecker{
public:
  void checkGrammar(WeakTParser* parser) override{

  }
};

class FunctionGrammarChecker : public GrammarChecker{
public:
  void checkGrammar(WeakTParser* parser) override{

  }
};

class VariableDeclarationChecker : public GrammarChecker{
public:
  void checkGrammar(WeakTParser* parser) override{

  }
};

class VariableMutationChecker : public GrammarChecker{
public:
  void checkGrammar(WeakTParser* parser) override{

  }
};

class SwitchGrammarChecker : public GrammarChecker{
public:
  void checkGrammar(WeakTParser* parser) override{

  }
};
