#include <bits/stdc++.h>
#include "../lexer/lexer.hpp"
# pragma once


class LanguageSpecification{
public:
  std::string wordName;
  bool isTerminal;
};


class CodeUnit{
  std::string operationName;

  std::shared_ptr<std::shared_ptr<CodeUnit>> operationBody;
};





class Parser{
private:
  std::vector<std::shared_ptr<Token>>& tokenStream;
  std::unordered_map<std::shared_ptr<LanguageSpecification>, std::shared_ptr<LanguageSpecification>>& grammarRules;

  std::shared_ptr<CodeUnit> mainPoint; // WHERE THE CODE STARTS (AKA HEAD)


public:
  Parser(std::unordered_map<std::shared_ptr<LanguageSpecification>, std::shared_ptr<LanguageSpecification>>& inputGrammarRules, 
         std::vector<std::shared_ptr<Token>>& inputTokenStream) 
  : grammarRules(inputGrammarRules), tokenStream(inputTokenStream) {}

private:

  void parse(){
    constructTree();
  }

  void constructTree(){
    for(const auto& pair : grammarRules){
      if(pair.first -> isTerminal){
        std::cout << "INTERPRETER DEBUGGING MESSAGE: Terminal was placed at front!\n";
        return;
      }


    }
  }

















};
