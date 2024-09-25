#include <bits/stdc++.h>

int start_index = 0; 
std::string input_stream;
std::string token;

void string_tokenizer();

std::vector<std::string> lex(){
  std::string token = "";
  if(input_stream[start_index] == '"'){
    string_tokenizer();
  }
}

void string_tokenizer(){
  if(input_stream[start_index] == '\\'){
    
  }
  if(input_stream[start_index] != '"'){
    token.push_back(input_stream[start_index]);
    start_index ++;
  }

  else if(input_stream[start_index] == ){

  }
  string_tokenizer();
}




















