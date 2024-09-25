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
    regular_exp = regular_exp;
  }
  
  int is_match(){

  }

  int is_match_at(){

  }
  
private:
  const std::vector<std::string> immutable_meta_strings = {"any", 
                                                           //"<~some_char to ~some_char>", 
                                                           //"<~some_char to ~some_char & ~some_char to ~some_char>"
                                                           "not", 
                                                           "|", 
                                                           "<",
                                                           ">", 
                                                           //"<n times>", // repeat function performs function on the string after it
                                                           //"<n to n times>" , 
                                                           "inf times",
                                                           "inf 1 times",
                                                           "space", 
                                                           "tab", 
                                                           "enter"};
                                                           //"/<~some_char>",   // / ignores the function of the > after it
                                                           //"/<~some_string~>"}; // / ignores the function of the > after it

  std::unordered_map<std::string, int> immutable_meta_strings_map; 
  void initialize_unordered_map(){
    for(auto i = 0; i < immutable_meta_strings.size(); i++){
      this -> immutable_meta_strings_map[immutable_meta_strings[i]] = i;
    }
  }
  
  std::vector<std::string> tokenized_output; 
  
  int start_index = 0;

  std::string curr_string = "";

  void tokenize_string_expression();
  void start_and_end_state();
  void state_norm_string_1();
  void state_norm_string_2();
  void state_norm_string_3();
  void state_expression();
  
  void remove_white_spaces(){
    std::string temp_string = "";
    for(int i = 0; i < curr_string.length(); i++){
      if(curr_string[i] != ' '){
        temp_string.push_back(curr_string[i]);
      }
    }
    curr_string = temp_string;
  }

  int find_numeral(){
    for(int i = 0; i < curr_string.length(); i++){

    }
  }
  //GO HEREEE
  int* interval_bound_check(std::string string_to_check){
    int check_array[4] = {-1, -1, -1, -1};
    int check_lower_bound_1 = static_cast<int> (string_to_check[0]);
    int check_upper_bound_1 = static_cast<int> (string_to_check[5]);

    if(check_lower_bound_1 >= 65 && check_lower_bound_1 <= 90){
      check_array[0] = 1;
    }
    else if(check_upper_bound_1 >= 97 && check_upper_bound_1 <= 122){
      check_array[0] = 1;
    }
    
    if(string_to_check.length() )
    int check_lower_bound_2 = static_cast<int> (string_to_check[9]);
    int check_upper_bound_2 = static_cast<int> (string_to_check[13]);

    if(static_cast<int> string_to_check[5] <= ){

    }
  }

  void tokenize_string_expression(){
    start_index = 0;
    start_and_end_state();
  }
   
  void start_and_end_state(){

    curr_string = ""; //Empty the string

    if(start_index == regular_exp.length()){
      std::cout << "Expression parsed successfully!\n";
    }
    else if(regular_exp[start_index] == '/'){
      start_index ++;
      state_norm_string_1();
    }
    else if(regular_exp[start_index] == '<'){
      start_index ++;
      state_expression();
    }
    else if(regular_exp[start_index] == ' '){
      start_index ++;
      start_and_end_state();
    }
    
    std::cout << "The expression has incorrect use of syntax! <start_and_end_state>\n at: " << regular_exp.substr(start_index) << '\n';
  }

  void state_norm_string_1(){
    if(regular_exp[start_index] == '<'){
      curr_string.push_back('<');
      start_index ++;
      state_norm_string_2();
    }

    std::cout << "The expression has incorrect use of syntax! <state_norm_string_1>\n at: " << regular_exp.substr(start_index) << '\n';
  }

  void state_norm_string_2(){
    if(regular_exp[start_index] == '/'){
      start_index ++;
      state_norm_string_3();
    }

    else if(regular_exp[start_index] == '>'){
      curr_string.push_back('>');
      this -> tokenized_output.push_back(curr_string);
      start_index ++;
      start_and_end_state();
    }

    else{
      curr_string.push_back(regular_exp[start_index]);
      start_index ++;
      state_norm_string_2();
    }
  }
  
  void state_norm_string_3(){
    if(regular_exp[start_index] != '>'){
      curr_string.push_back('/');
      curr_string.push_back(regular_exp[start_index]);
      start_index ++;
      state_norm_string_2();
    }
    else{
      curr_string.push_back(regular_exp[start_index]);
      start_index ++;
      state_norm_string_2();
    }
  }

  void state_expression(){// start_index SHOULD BE INCREMENTED ONLY WHEN EXECUTION IS FINISHED

    curr_string.push_back('<');
    int sub_count = 0;
    while(regular_exp[start_index + sub_count] != '>'){
      sub_count ++;
    }
    
    curr_string = regular_exp.substr(start_index, sub_count);
    std::cout << "The curr_string in state_expression: " << curr_string << '\n';
   

    if(immutable_meta_strings_map.count(curr_string)){
      //curr_string.insert(curr_string.begin(), '<');
      //curr_string.push_back('>');
      tokenized_output.push_back(curr_string);
      start_index ++;
      start_and_end_state();
    }

    else{
      
    }
  }

  std::string regex_scanner(){

  }

};
