#include <bits/stdc++.h>
#include <csignal>
#include <fstream>
#include "../include/lexer/lexer.hpp"
#include "../include/lexer/adders.hpp"

TokenDirectorSingleton TokenDirectorSingleton :: globalInstance; 
TokenDirectorSingleton& directorObject = TokenDirectorSingleton :: getGlobalInstance(); 

SingletonData SingletonData :: globalInstance; 
SingletonData& builtInTokensData = SingletonData :: getGlobalInstance();

TokenEnumStringMap TokenEnumStringMap :: globalInstance;
TokenEnumStringMap& tokenClassStringMapGlobalInstance = TokenEnumStringMap :: getGlobalInstance();


// GO BACK TO argc and argv after all tests pass
int main(){

  std::string input_string;
  std::string customInputCommandHolder = "";
  std::string line;
  std::shared_ptr<Script> commandLine;


  // FILE ACCESS (THE FILE TO TEST)
  std::ifstream customInputCommand("../tests/test1.seash");

  if(!customInputCommand.is_open()) {
    std::cerr << "Error opening the file!\n";
    return 1;
  }

  while (getline(customInputCommand, line)){
    customInputCommandHolder += line + '\n';
  }
    
  commandLine = std::make_shared<Script>(customInputCommandHolder);


  // LEX IT
  std::cout << "Starting to lex!\n";
  commandLine -> lex();
  commandLine -> displayTokenizedOutput();

  //

  // Close the file
  customInputCommand.close();
}
