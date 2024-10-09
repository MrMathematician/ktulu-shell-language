#pragma once
#include "weak_t_parser.hpp"

class WeakTParser;


class GrammarChecker{
public:
  WeakTParser* parser;

  intmax_t bracketPolarity = 0;
  virtual void checkGrammar(WeakTParser* parser) {}

  friend WeakTParser;
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
public:
  void checkGrammar(WeakTParser* inputParser) override{
    parser = inputParser;  
  }
};

class VariableDeclarationChecker : public GrammarChecker{
public:
  void checkGrammar(WeakTParser* inputParser) override{

  }
};

class VariableMutationChecker : public GrammarChecker{
public:
  void checkGrammar(WeakTParser* inputParser) override{

  }
};

class SwitchGrammarChecker : public GrammarChecker{
public:
  void checkGrammar(WeakTParser* inputParser) override{

  }
};
