#include <bits/stdc++.h>
#include <csignal>
#include "command_mode_lexer.hpp"
#include "script_mode_lexer.hpp"

int main(int argc, char *argv[]){
    
  std::string input_string;
  while(true){
       
    std::cout<<">>> ";
    std::getline(std::cin, input_string);
    Command new_command = Command(input_string);
    new_command.command_parse();
    
  }

  return 0;
}
