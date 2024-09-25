#include <bits/stdc++.h>
#include "command_mode_lexer.hpp"

class Token{
public:
  std::string token_string;
  std::string token_type;
  int line_occurence;

  Token(std::string token_string, std::string token_type, int line_occurence){
    this -> token_string = token_string;
    this -> token_type = token_type;
    this -> line_occurence = line_occurence;
  }
};

class Script{
public:
  int start_index = 0;
  std::string string_buffer;
  std::vector<Token> tokenized_output; 

  Script(int start_index, std::string string_buffer, std::vector<Token> tokenized_output){
    this -> start_index = start_index;
    this -> string_buffer = string_buffer;
    this -> tokenized_output = tokenized_output;
  }
};

std::string input_file;
std::vector<Token> tokens_structure; 
std::string single_token;

std::regex if_regex{"\\s+|\n|;if(|\\s+"};
std::regex else_regex{"\\s+|\n|;else(|\\s+"};
std::regex else_if_regex{"\\s+|\n|;else\\sif\\s+|("};
std::regex for_regex{"\\s+|\n|;for\\s+|("};
std::regex while_regex{"\\s+|\n|;while\\s+|("};
std::regex function_regex{"\\s+|\n|;function\\s+|("};
std::regex switch_regex{"\\s+|\n|;switch\\s+|("};
std::regex case_regex{"\\s+|\n|;case\\s+|("};

void script_state_1(Script curr_script);
void script_state_2(Script curr_script);

void start_lex(Script curr_script){
  if(curr_script.string_buffer[curr_script.start_index] == '"'){
    script_state_1(curr_script);
  }
  curr_script.start_index ++;    
}

void script_state_1(Script curr_script){
  if(curr_script.string_buffer[curr_script.start_index] == '\\'){
    curr_script.start_index ++;
    script_state_2(curr_script);
    return;
  }
  if(curr_script.string_buffer[curr_script.start_index] == '"'){
    tokenized_output  
  }
}

void script_state_2(Script curr_script){
    
}






