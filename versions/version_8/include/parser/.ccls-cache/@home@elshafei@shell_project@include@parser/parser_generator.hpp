#include <bits/stdc++.h>
#include "../lexer/lexer.hpp"

class Term{
protected:
  const char* name;

  void setName(const char* newName){
    name = newName;
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



class BinaryOperation{
private:
  std::shared_ptr<Token> firstOperand = nullptr;
  std::shared_ptr<Token> secondOperand = nullptr;
  std::shared_ptr<Token> Operator = nullptr;
public:
  void setFirstOperatnd(std::shared_ptr<Token>){

  }
};



//class 






class Parser{
private:
  std::vector<Term> languageRules;
  
public:


















};
