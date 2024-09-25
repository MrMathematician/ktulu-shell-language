#pragma once
#include <bits/stdc++.h>


class LOGGER{
public:
  // ERRORS WILL INCLUDE exit(1) WHEN GOING INTO PRODUCTION
  static void genErrorStringUnterminated(size_t lineOccurrence){
    std::cout << "ERROR: Unterminated string at line: " << lineOccurrence << std::endl;
  }

  static void getErrorParsingTypeNotSpecified(size_t lineOccurrence){
    std::cout << "ERROR: Parsing type unspecified properly at line: " << lineOccurrence << '\n';
    std::cout << "No type specified would result in defaulting at weakly typed mode\n" << std::endl;
  }
};
