#pragma once
#include <bits/stdc++.h>
#include "../lexer/lexer.hpp"
#include "strong_t_parser.hpp"
#include "weak_t_parser.hpp"

// tokenizedOutput WAS RENAMED TO tokenStream AS IT BETTER FITS THE ROLE IN THE PARSING STAGE

class ParserAction{
private:
  bool weaklyTyped = true;
  std::deque<std::shared_ptr<Token>>* tokenStream;

   

  void determineParsingType(){
    if(!(tokenStream -> empty())) return;
    
    if(tokenStream -> at(0) -> getTokenString() == "#" 
      && tokenStream -> size() >= 2 
      && tokenStream -> at(1) -> getTokenString() == "STRONGLY_TYPED"){

      weaklyTyped = false; 
    }
    else if(tokenStream -> at(0) -> getTokenString() == "#" 
      && tokenStream -> size() >= 2 
      && tokenStream -> at(1) -> getTokenString() == "WEAKLY_TYPED"){

      weaklyTyped = true; 
    }
    else if(tokenStream -> at(0) -> getTokenString() == "#"){
      LOGGER ::getErrorParsingTypeNotSpecified(tokenStream -> at(0) -> getStandingLineOccurrence());
    }
  }
  
  void getTokens(Script& scriptToParse){
    tokenStream = scriptToParse.getTokenDequePointer(); 
  }

public:
  ParserAction() {}
  
  void startParsing(){
    if(weaklyTyped){
      startWeakParsing();
      return;
    }
    startStrongParsing();
  }

  void startWeakParsing(){
    WeakTParser parser = WeakTParser();
    parser.inputTokenStream(tokenStream);
    parser.debugParseTree();
    // PARSE
  }

  void startStrongParsing(){
    //StrongTParser parser = StrongTParser();
    std::cout << "Strongly Typed mode is still in development. Only Weakly Typed mode is currently avaiable!\n";
  }
};
