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
int main(/*int argc, char *argv[]*/){

  std::string input_string;
  std::string customInputCommandHolder = "";
  std::string line;
  std::shared_ptr<Script> commandLine;
  //std::shared_ptr<ParseTreeCreator> commandParser;

  commandLine = std::make_shared<Script>();
  //commandParser = std::make_shared<ParseTreeCreator>();

  builtInTokensData.displayBuiltinTokens();



  // FILE ACCESS (THE FILE TO TEST)
  std::ifstream customInputCommand("test1.seash");

  if(!customInputCommand.is_open()) {
    std::cerr << "Error opening the file!\n";
    return 1;
  }

  while (getline(customInputCommand, line)){
    customInputCommandHolder += line + '\n';
  }
    
  commandLine -> set_buffer_string(customInputCommandHolder);
  std::cout << customInputCommandHolder << '\n';
  std::cout << "^^ THIS WAS THE FILE ^^\n";


  // LEX IT
  std::cout << "Starting to lex!\n";
  commandLine -> lex();
  commandLine -> displayTokenizedOutput();

  // PARSE IT
  //std::cout << "Starting to parse!\n";
  //commandParser -> getTokenStream(commandLine -> getTokenVectorPointer());
  //commandParser -> parse();
  //commandParser -> walkAcrossTree();


  // Close the file
  customInputCommand.close();

 

  /*
  // ACTUAL PROGRAM
  while(true){
    
    commandLine = std::make_shared<Script>();
    commandParser = std::make_shared<ParseTreeCreator>();
       
    std::cout<<">>> ";
    std::getline(std::cin, input_string);
    commandLine -> set_buffer_string(input_string);

    // LEXING THE INPUT
    commandLine -> lex();

    // THIS IS ONLY FOR TESTING THE LEXER
    std::cout << "\n<<<<Original string>>>> :"<< input_string << '\n';
    std::cout << "\n<<<<The lexed output>>>> : " << "\n\n";
    commandLine -> displayTokenizedOutput();

    // THIS IS ONLY FOR 

      


    commandLine = nullptr;
    commandParser = nullptr;
    //Command new_command = Command(input_string);
    //new_command.command_parse();
    
  }
  */
  

  return 0;
}
