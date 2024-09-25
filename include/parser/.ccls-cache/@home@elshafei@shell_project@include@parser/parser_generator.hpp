#include <bits/stdc++.h>
#include "../lexer/lexer.hpp"
#include "../logger/logger.hpp"



class Term{
protected:
  std::string name;
  bool terminal = false;
  void setName(std::string newName){
    name = newName;
  }

  void setIsTerminal(bool terminalType){
    terminal = terminalType;
  }
 
  bool isTerminal(){
    return terminal;
  }
};





class Terminal : public Term{};



class NonTerminal : public Term{
private:
  std::vector<std::unique_ptr<Term>> replaceables;
public:
  NonTerminal(){
    replaceables[0] = nullptr;
  }

  void addToReplaceables(std::unique_ptr<Term>& newTerm){
    replaceables.push_back(newTerm);
  }
};





class Binary{
private:
  std::shared_ptr<Token> firstOperand = nullptr;
  std::shared_ptr<Token> secondOperand = nullptr;
  std::shared_ptr<Token> Operator = nullptr;
public:
  void setFirstOperand(std::shared_ptr<Token>){

  }
};





class ParserGenerator{
private:
  std::vector<const char *> unitiliazedLanguageRules; // LEXED VECTOR OF DSL
  std::vector<std::unique_ptr<Term>> initializedLanguageRules; // CLEANED VECTOR OF DSL

  // LANGUAGE RULES LEXER SHOULD BE HERE

public:
  std::vector<std::unique_ptr<Term>>* getLanguageRules() {
    return &initializedLanguageRules;
  }
};




class Parser{
private:
  std::vector<Token> tokenStream;

  std::vector<std::unique_ptr<Term>> languageRules;
  std::shared_ptr<Term> rootMother;

  size_t currTokenIndex = 0;

  void startSymbol(){
    for(size_t i = 0; i < languageRules.size(); i++){
      if(){
        break;
      }
    }
  }
  
  

















};
