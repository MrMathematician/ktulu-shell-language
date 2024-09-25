#include <vector>
#include <iostream>
#include <cassert>
#include <string>
#include <unordered_map>

class READABLE_REGULAR_EXP{
private:

  std::string regular_exp;

public:

  READABLE_REGULAR_EXP(std::string regular_exp){
    regular_exp = this -> regular_exp;
  }
  
  int is_match(){

  }

  int is_match_at(){

  }
  
private:
  const std::vector<std::string> readable_regex_syntax = {"<any>", 
                                                          //"<~some_char to ~some_char>", 
                                                          //"<~some_char to ~some_char & ~some_char to ~some_char>"
                                                          "<not>", 
                                                          "<|>", 
                                                           "<<>",
                                                           "<>>", 
                                                           //"<n times>", // repeat function performs function on the string after it
                                                           //"<n to n times>" , 
                                                           "<inf times>",
                                                           "<inf 1 times>",
                                                           "<space>", 
                                                           "<tab>", 
                                                           "<enter>"};
                                                           //"/<~some_char>",   // / ignores the function of the > after it
                                                           //"/<~some_string~>"}; // / ignores the function of the > after it

  std::unordered_map<std::string, int> readable_regex_syntax_map; 
  void initialize_unordered_map(){
    for(auto i = 0; i < readable_regex_syntax.size(); i++){
      this -> readable_regex_syntax_map[readable_regex_syntax[i]] = i;
    }

  
  std::vector<std::string> tokenized_output; 
  
  int start_index = 0;

  std::string curr_string;
  void start_and_end_state();
  void state_norm_string_1();
  void state_norm_string_2();
  void state_norm_string_3();
  void state_expression();

  void tokenize_string_expression(){
    this -> start_index = 0;
    start_and_end_state();
  }
   
  void start_and_end_state(){
        
    if(this -> start_index == this -> regular_exp.length()){
      std::cout << "Expression parsed successfully!\n";
    }
    else if(this -> regular_exp[this -> start_index] == '/'){
      this -> start_index ++;
      state_norm_string_1();
    }
    else if(this -> regular_exp[this -> start_index] == '<'){
      this -> start_index ++;
      state_expression();
    }
    
    std::cout << "The expression has incorrect use of syntax! <start_and_end_state>\n";
  }

  void state_norm_string_1(){
    if(this -> regular_exp[this -> start_index] == '<'){
      this -> start_index ++;
      state_norm_string_2();
    }

    std::cout << "The expression has incorrect use of syntax! <state_norm_string_1>\n";
  }

  void state_norm_string_2(){
    if(this -> regular_exp[this -> start_index] == '/'){
      this -> start_index ++;
      state_norm_string_3();
    }
    else if(this -> regular_exp[this -> start_index] == '>'){
      this -> start_index ++;
      start_and_end_state();
    }

    std::cout << "The expression has incorrect use of syntax! <state_norm_string_2>\n";
  }
  
  void state_norm_string_3(){
    char curr_char = this -> regular_exp[this -> start_index];
    this -> start_index ++;
    state_norm_string_2();
  }

  void state_expression(){
    this -> start_index ++;
    // ONE & TO AVOID CHECKING OTHER CONDITIONS!!
    if(static_cast<int>regular_exp[this -> start_index + 1] <= 122 & static_cast<int>regular_exp[this -> start_index + 1] >= 97 &
       static_cast<int>regular_exp[this -> start_index + 6] <= 122 & static_cast<int>regular_exp[this -> start_index + 6] >= 97 &
       
       ){
      //lower case

    }
    else if(static_case<int>regular_exp[this -> start_index + 1] <= 90 && static_cast<int>regular_exp[this -> start_index + 1] >= 65){

    }

        
  }

  void state_expression_any(){

  }
  
  void state_expression_not(){

  }
  
  void state_expression_or(){

  }

  void state_expression_n_to_n_times(){

  }
  
  void state_expression_inf_times(){

  }

  void state_expression_inf_1_times(){

  }

  std::string regex_scanner(){

  }

};
