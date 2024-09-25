#include <bits/stdc++.h>
#include "../lexer/lexer.hpp"
#pragma once

class LOGGER{
public:
  // ERRORS WILL INCLUDE exit(1) WHEN GOING INTO PRODUCTION
  static void genErrorStringUnterminated(std::shared_ptr<Token> tokenOfError){
    std::cout << "ERROR: Unterminated string at line: " << tokenOfError -> getStandingLineOccurrence() << std::endl;
  }

  static void getErrorParsingTypeNotSpecified(std::shared_ptr<Token> tokenOfError){
    std::cout << "ERROR: Parsing type unspecified properly at line: " << tokenOfError -> getStandingLineOccurrence() << '\n';
    std::cout << "No type specified would result in defaulting at weakly typed mode\n" << std::endl;
  }
};
