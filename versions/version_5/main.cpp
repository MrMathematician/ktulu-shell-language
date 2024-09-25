#include <bits/stdc++.h>
#include <csignal>
#include "tokens.hpp"
#include "parser.hpp"


Token_director_singleton Token_director_singleton :: global_instance; 
Token_director_singleton& director_object = Token_director_singleton :: get_global_instance(); 

Singleton_data Singleton_data :: global_instance; 
Singleton_data& Global_data = Singleton_data :: get_global_instance();

int main(/*int argc, char *argv[]*/){

  //Global_data.display_keywords_map();

  std::string input_string;
  std::unique_ptr<Script> command_line;


  
  while(true){
    
    //Global_data.show_count();
    command_line = std::make_unique<Script>();
       
    std::cout<<">>> ";
    std::getline(std::cin, input_string);
    
    command_line -> set_buffer_string(input_string);

    //std::cout << "WAS THERE ANYTHING IN THE FIRST PLACE??? " << command_line -> get_string_buffer() << '\n';

    command_line -> lex();
    std::cout << "\n<<<<Original string>>>> :"<< input_string << '\n';
    std::cout << "\n<<<<The lexed output>>>> : " << "\n\n";
    command_line -> display_tokenized_output();
    command_line = nullptr;
    //Command new_command = Command(input_string);
    //new_command.command_parse();
    
  }

  return 0;
}
