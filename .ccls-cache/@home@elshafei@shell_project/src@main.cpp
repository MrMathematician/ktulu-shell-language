#include <bits/stdc++.h>
#include <csignal>
#include <fstream>
#include "../include/lexer/lexer.hpp"
#include "../include/lexer/adders.hpp"
#include "../include/parser/weak_t_parser.hpp"
#include "../include/parser/grammar.hpp"


// LEXER DEFINED SINGELTONS
TokenDirectorSingleton TokenDirectorSingleton :: globalInstance; 
TokenDirectorSingleton& directorObject = TokenDirectorSingleton :: getGlobalInstance(); 

SingletonData SingletonData :: globalInstance; 
SingletonData& builtInTokensData = SingletonData :: getGlobalInstance();

TokenEnumStringMap TokenEnumStringMap :: globalInstance;
TokenEnumStringMap& tokenClassStringMapGlobalInstance = TokenEnumStringMap :: getGlobalInstance();


// PARSER DEFINED SINGELTONS
RulesContainerSingelton RulesContainerSingelton :: globalInstance;
RulesContainerSingelton& rulesContainerSingeltonObject = RulesContainerSingelton :: getGlobalInstance();


int main(){

  std::string input_string;
  std::string customInputCommandHolder = "";
  std::string line;
  //Script commandLine;


  // FILE ACCESS (THE FILE TO TEST)
  std::ifstream customInputCommand("../tests/test1.seash");

  if(!customInputCommand.is_open()) {
    std::cerr << "Error opening the file!\n";
    return 1;
  }

  while (getline(customInputCommand, line)){
    customInputCommandHolder += line + '\n';
  }
    
  Script commandLine = Script(customInputCommandHolder);


  // LEX IT
  std::cout << "Starting to lex!\n";
  commandLine.lex();
  commandLine.displayTokenizedOutput();


  // PARSE IT

  // Close the file
  customInputCommand.close();
}
