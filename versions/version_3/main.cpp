#include <bits/stdc++.h>
#include <csignal>
#include "tokens.hpp"

Token_director_singleton Token_director_singleton :: global_instance; 
Token_director_singleton& director_object = Token_director_singleton :: get_global_instance(); 

Singleton_data Singleton_data :: global_instance; 
Singleton_data& Global_data = Singleton_data :: get_global_instance();

int main(/*int argc, char *argv[]*/){

  Global_data.display_keywords_map();

  std::string input_string;
  while(true){
       
    std::cout<<">>> ";
    std::getline(std::cin, input_string);
    //Command new_command = Command(input_string);
    //new_command.command_parse();
    
  }

  return 0;
}
