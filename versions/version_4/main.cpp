#include <bits/stdc++.h>
#include <csignal>
#include "lexer.hpp"
#include "neo_parser.hpp"
#include <fstream>

Token_director_singleton Token_director_singleton :: global_instance; 
Token_director_singleton& director_object = Token_director_singleton :: get_global_instance(); 

Singleton_data Singleton_data :: global_instance; 
Singleton_data& Global_data = Singleton_data :: get_global_instance();


// GO BACK TO argc and argv after all tests pass
int main(/*int argc, char *argv[]*/){

  //Global_data.display_keywords_map();

  std::string input_string;
  std::string customInputCommandHolder = "";
  std::string line;
  std::shared_ptr<Script> commandLine;
  std::shared_ptr<ParseTreeCreator> commandParser;

   
  std::ifstream customInputCommand("test1.seash");

  commandLine = std::make_shared<Script>();

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

  commandLine -> lex();
  commandLine -> display_tokenized_output();
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
    commandLine -> display_tokenized_output();

    // THIS IS ONLY FOR 

      


    commandLine = nullptr;
    commandParser = nullptr;
    //Command new_command = Command(input_string);
    //new_command.command_parse();
    
  }
  */
  

  return 0;
}
