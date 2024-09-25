#include <bits/stdc++.h>
#include "tokens.hpp"

class Token_director_singleton final{
private:
  Token_director_singleton(){};
  static Token_director_singleton global_instance; // Was named director_object


public:
  std::shared_ptr<Token> build_token(std::shared_ptr<Abstract_token_builder> some_builder){ some_builder -> build_token_type();
    return some_builder -> get_token();
  }

  static Token_director_singleton& get_global_instance(){
    return global_instance; // Was named director_object
  } 
};



//Initialize once, use forever ...
//Token_director_singleton Token_director_singleton :: director_object; // This line was not there
Token_director_singleton& director_object = Token_director_singleton :: get_global_instance();


//This class should be instantiated after the subclasses are instantiated.
class Singleton_data{
private:
  static std::unordered_map<std::string, std::shared_ptr<Token>> keywords_map;

  int largest_keyword_size = 0;

  void sort_keywords_map(){ // Replace with sort
    
  }

  Singleton_data(){
    sort_keywords_map();
  }
  
  static Singleton_data global_instance;

public: 
  static Singleton_data& get_global_instance(){
    return global_instance;
  }

  int get_largest_keyword_size(){
    return largest_keyword_size;
  }

  void display_keywords_map(){
    for(int i = 0; i < keywords_map.size(); i++){
      // HOW TO PRINT ALL THE KEYS IN AN UNORDERED MAP AND THEIR VALUES 
    }
  }

  void add_token(std::string token_name){
    std::shared_ptr<Token_if_builder> new_token;
    keywords_map[token_name] = director_object.build_token(std::static_pointer_cast<Abstract_token_builder>(new_token));
  }
};



// Intialize once, use forever ...
Singleton_data& Global_data = Singleton_data :: get_global_instance();







// This block was not commented before !!!!!!!

/*

class Abstract_adder{
  //virtual void call_add_token() const = 0;
};


class if_adder : Abstract_adder{
private:
  std::shared_ptr<Token_if_builder> new_token;
public: 
  static void call_add_token(){
    Global_data.add_token("if");
  }
};

//if_adder :: add_token();

class else_adder : Abstract_adder{
private:
  std::shared_ptr<Token_else_builder> new_token;
public: 
  static void call_add_token(){
    Global_data.add_token("else");
  }
};

class else_if_adder : Abstract_adder{
private:
  std::shared_ptr<Token_else_if_builder> new_token;
public:
  static void call_add_token(){
    Global_data.add_token("else if");
  }
};

class and_adder : Abstract_adder{ private: std::shared_ptr<Token_and_builder> new_token;
public:
  static void call_add_token(){
    Global_data.add_token("and");
  }
};

class or_adder : Abstract_adder{
private:
  std::shared_ptr<Token_or_builder> new_token;
public:
  static void call_add_token(){
    Global_data.add_token("or");
  }
};

class var_adder : Abstract_adder{
private:
  std::shared_ptr<Token_var_builder> new_token;
public:
  static void call_add_token(){
    Global_data.add_token("var");
  }
};

class false_adder : Abstract_adder{
private:
  std::shared_ptr<Token_false_builder> new_token;
public:
  static void call_add_token(){
    Global_data.add_token("false");
  }
};

class true_adder : Abstract_adder{
private:
  std::shared_ptr<Token_true_builder> new_token;
public:
  static void call_add_token(){
    Global_data.add_token("true");
  }
};

class print_adder : Abstract_adder{
private:
  std::shared_ptr<Token_print_builder> new_token;
public:
  static void call_add_token(){
    Global_data.add_token("print");
  }
};

class return_adder : Abstract_adder{
private:
  std::shared_ptr<Token_return_builder> new_token;
public:
  static void call_add_token(){
    Global_data.add_token("return");
  }
};

class function_adder : Abstract_adder{
private:
  std::shared_ptr<Token_function_builder> new_token;
public:
  static void call_add_token(){
    Global_data.add_token("function");
  }
};

class switch_adder : Abstract_adder{
private:
  std::shared_ptr<Token_switch_builder> new_token;
public:
  static void call_add_token(){
    Global_data.add_token("switch");
  }
};

class while_adder : Abstract_adder{
private:
  std::shared_ptr<Token_while_builder> new_token;
public:
  static void call_add_token(){
    Global_data.add_token("while");
  }
};

class for_adder : Abstract_adder{
private:
  std::shared_ptr<Token_for_builder> new_token;
public:
  static void call_add_token(){
    Global_data.add_token("for");
  }
};

class case_adder : Abstract_adder{
private:
  std::shared_ptr<Token_case_builder> new_token;
public:
  static void call_add_token(){
    Global_data.add_token("case");
  }
};

class command_adder : Abstract_adder{
private:
  std::shared_ptr<Token_command_builder> new_token;
public:
  static void call_add_token(){
    Global_data.add_token("command");
  }
};

class left_brace_adder : Abstract_adder{
private:
  std::shared_ptr<Token_separator_left_brace_builder> new_token;
public:
  static void call_add_token(){
    Global_data.add_token("{");
  }
};

class right_brace_adder : Abstract_adder{
private:
  std::shared_ptr<Token_separator_right_brace_builder> new_token;
public:
  static void call_add_token(){
    Global_data.add_token("}");
  }
};

class left_bracket_adder : Abstract_adder{
private:
  std::shared_ptr<Token_separator_left_bracket_builder> new_token;
public:
  static void call_add_token(){
    Global_data.add_token("(");
  }
};

class right_bracket_adder : Abstract_adder{
private:
  std::shared_ptr<Token_separator_right_bracket_builder> new_token;
public:
  static void call_add_token(){
    Global_data.add_token(")");
  }
};


// WHY THE HELL ARE YOU ADDING WHITE SPACES

//class white_space_adder : Abstract_adder{
//private:
//  std::shared_ptr<Token_white_space_builder> new_token;
//
//  void call_add_token(){
//    keywords_map[" "] = director_object.build_token(std::static_pointer_cast<Abstract_token_builder>(new_token));
//  }
//
//public:
//  white_space_adder(){
//    void call_add_token();
//  }
//};
//
//class tab_adder : Abstract_adder{
//private:
//  std::shared_ptr<Token_tab_space_builder> new_token;
//
//  void call_add_token(){
//    keywords_map["\t"] = director_object.build_token(std::static_pointer_cast<Abstract_token_builder>(new_token));
//  }
//
//public:
//  tab_adder(){
//    void call_add_token();
//  }
//};


class line_break_adder : Abstract_adder{
private:
  std::shared_ptr<Token_line_break_builder> new_token;
public:
  static void call_add_token(){
    Global_data.add_token("\n");
  }
};

class comma_adder : Abstract_adder{
private:
  std::shared_ptr<Token_comma_builder> new_token;
public:
  static void call_add_token(){
    Global_data.add_token(",");
  }
};

class semicolon_adder : Abstract_adder{
private:
  std::shared_ptr<Token_semicolon_builder> new_token;
public:
  static void call_add_token(){
    Global_data.add_token(";");
  }
};

class double_quotation_adder : Abstract_adder{
private:
  std::shared_ptr<Token_double_quotation_builder> new_token;
public:
  static void call_add_token(){
    Global_data.add_token("\"");
  }
};

class single_quotation_adder : Abstract_adder{
private:
  std::shared_ptr<Token_single_quotation_builder> new_token;
public:
  static void call_add_token(){
    Global_data.add_token("'");
  }
};

class star_adder : Abstract_adder{
private:
  std::shared_ptr<Token_star_builder> new_token;
public:
  static void call_add_token(){
    Global_data.add_token("*");
  }
};

class normal_slash_adder : Abstract_adder{
private:
  std::shared_ptr<Token_normal_slash_builder> new_token;
public:
  static void call_add_token(){
    Global_data.add_token("/");
  }
};

class forward_slash_adder : Abstract_adder{
private:
  std::shared_ptr<Token_escape_slash_builder> new_token;
public:
  static void call_add_token(){
    Global_data.add_token("\\");
  }
};

class bang_slash_adder : Abstract_adder{
private:
  std::shared_ptr<Token_bang_builder> new_token;
public:
  static void call_add_token(){
    Global_data.add_token("!");
  }
};

class equal_adder : Abstract_adder{
private:
  std::shared_ptr<Token_equal_builder> new_token;
public:
  static void call_add_token(){
    Global_data.add_token("=");
  }
};

class is_equal_adder : Abstract_adder{
private:
  std::shared_ptr<Token_is_equal_builder> new_token;
public:
  static void call_add_token(){
    Global_data.add_token("==");
  }
};

class not_equal_adder : Abstract_adder{
private:
  std::shared_ptr<Token_not_equal_builder> new_token;
public:
  static void call_add_token(){
    Global_data.add_token("!=");
  }
};

class LeftGreaterRight_adder : Abstract_adder{
private:
  std::shared_ptr<Token_leftGreaterRight_builder> new_token;
public:
  static void call_add_token(){
    Global_data.add_token(">");
  }
};

class LeftLessRight_adder : Abstract_adder{
private:
  std::shared_ptr<Token_leftLessRight_builder> new_token;
public:
  static void call_add_token(){
    Global_data.add_token("<");
  }
};

class LeftGreaterRightOrEqual_adder : Abstract_adder{
private:
  std::shared_ptr<Token_leftGreaterRightOrEqual_builder> new_token;
public:
  static void call_add_token(){
    Global_data.add_token(">=");
  }
};

class LeftLessRightOrEqual_adder : Abstract_adder{
private:
  std::shared_ptr<Token_leftLessRightOrEqual_builder> new_token;
public:
  static void call_add_token(){
    Global_data.add_token("<=");
  }
};

class dot_adder : Abstract_adder{
private:
  std::shared_ptr<Token_dot_builder> new_token;
public:
  static void call_add_token(){
    Global_data.add_token(".");
  }
};

class plus_adder : Abstract_adder{
private:
  std::shared_ptr<Token_plus_builder> new_token;
public:
  static void call_add_token(){
    Global_data.add_token("+");
  }
};

class plus_plus_adder : Abstract_adder{
private:
  std::shared_ptr<Token_double_plus_builder> new_token;
public:
  static void call_add_token(){
    Global_data.add_token("++");
  }
};

class minus_adder : Abstract_adder{
private:
  std::shared_ptr<Token_minus_builder> new_token;
public:
  static void call_add_token(){
    Global_data.add_token("-");
  }
};

class minus_minus_adder : Abstract_adder{
private:
  std::shared_ptr<Token_minus_minus_builder> new_token;
public:
  static void call_add_token(){
    Global_data.add_token("--");
  }
};

class shell_adder : Abstract_adder{
private:
  std::shared_ptr<Token_shell_builder> new_token;
public:
  static void call_add_token(){
    Global_data.add_token("shell");
  }
};

class script_adder : Abstract_adder{
private:
  std::shared_ptr<Token_shell_builder> new_token;
public:
  static void call_add_token(){
    Global_data.add_token("script");
  }
};





class Script{
private:
  int start_index = 0;
  int line_counter = 1;

  std::string string_buffer;
  std::vector<Token> tokenized_output; 

public:
  void lex(){
    fn_start_state();
  }

  Script(std::string string_buffer){
    this -> string_buffer = string_buffer;
  }

private:
  void increment_index(){
    this -> start_index ++;
  };

  void increment_index_custom(int custom_num){
    this -> start_index += custom_num;
  }
  
  void set_index(int custom_index){
    this -> start_index = custom_index;
  }

  int get_index(){
    return this -> start_index;
  }
  
  void set_line_counter(int custom_line){
    this -> line_counter = custom_line;
  }
  
  void increment_line_counter(){
    if(string_buffer[start_index] == '\n'){
      this -> line_counter ++;
    }
  }
  
  int get_line(){
    return this -> line_counter;
  }
  
  void reset_index(){
    this -> start_index = 0;
  }
  
  std::vector<Token> get_tokenized_output(){
    return this -> tokenized_output;
  }

  void add_to_tokenized_output(Token new_token){
    this -> tokenized_output.push_back(new_token);
  }


  // Algorithm implementation (uses the state design pattern)
  

  int literal_length = 0;
  int lookahead_dist = 0;

  std::string temp_string = "";

  int get_max_lookahead(){
    while(start_index + lookahead_dist < string_buffer.length() - 1 && lookahead_dist < Global_data.get_largest_keyword_size()){
      lookahead_dist ++;  
    }
    return lookahead_dist;
  }

 

  void fn_start_state(){
    get_max_lookahead();
     

    
    increment_line_counter();
    increment_index();
  }

  void literal_state(){

    increment_line_counter();
    increment_index_custom(literal_length);
  }

  void string_state(){

    increment_line_counter();
    increment_index_custom(literal_length);
  }

  void comment_state_1(){

    increment_line_counter();
    increment_index();
  }

  void commen_state_2(){

    increment_line_counter();
    increment_index();
  }
};
*/











