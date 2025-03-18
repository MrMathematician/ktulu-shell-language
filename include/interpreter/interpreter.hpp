#include <bits/stdc++.h>
#include "../lexer/lexer.hpp"
//#include "../syntax_analyzer/analyze.hpp"
//#include "../ast_gen/"

class Interpreter{
private:
  std::deque<std::shared_ptr<Token>> tokenStream;

public:
  Interpreter(){}

  void tokenize(std::string&& inputStream){
    Script script = Script();
    script.setInputAndTokenStream(std::move(inputStream), std::move(tokenStream));
    script.lex();
    tokenStream = script.getTokenDeque();
  }

  void checkSyntax(){
    // syntax analysis and ast gen have not been created yet 
  }

  void createAST(){

  }
  
  void startEngine(){

  }

  void outputTokenStream(){
    for(const auto& tokenPtr : tokenStream) tokenPtr -> displayElements();
    std::cout << std::endl;
  }

  std::string recreateScript(){
    std::string recreated;
    for(const auto& tokenPtr : tokenStream) recreated += tokenPtr -> getTokenString();
    return recreated;
  }

  std::string recreateDiscrete(){
    std::string recreated;
    for(const auto& tokenPtr : tokenStream){
      recreated += tokenPtr -> getStringGeneralTokenType() 
        + " " + tokenPtr -> getStringSpecificTokenType() 
        + ":" + tokenPtr -> getTokenString() 
        + "\n";
    }
    return recreated;
  }

  void reset(){
    tokenStream.clear();
  }
};



