#include <bits/stdc++.h>
# pragma once

class LOGGER{
public:
  // ERRORS WILL INCLUDE exit(1) WHEN GOING INTO PRODUCTION
  static void genErrorStringUnterminated(size_t standingLine){
    std::cout << "ERROR: Unterminated string at line: " << standingLine << '\n';
  }
};
