#include <bits/stdc++.h>
# pragma once

class Token final{
private:
  std::string token_string;
  std::string token_type; // CONST MAY CAUSE AN ERROR 
  int line_occurence;
public:
  Token(std::string token_string){
    this -> token_string = token_string; 
    //std::cout << "TOKEN STRING FROM CONSTRUCTOR: " << token_string << '\n';
    //std::cout << "TOKEN TYPE FROM CONSTRUCTOR: " << token_type << '\n';
  }

  Token(){
    //std::cout << "NO PARAMETERS GIVEN FOR TOKEN CONSTRUCTOR!!!!!\n";
  }
   
  void set_token_type(std::string new_token_type){
    this -> token_type = new_token_type;
  }

  void set_token_string(std::string new_token_string){
    this -> token_string = new_token_string;
  }

  void set_line_occurence(int new_line_occurence){
    this -> line_occurence = new_line_occurence;
  }

  std::string get_token_string(){
    return this -> token_string;
  }

  std::string get_token_type(){
    return this -> token_type;
  }

  int get_line_occurence(){
    return this -> line_occurence;
  }

  void display_elements(){
    std::cout << '\n';
    std::cout << "<<<TOKEN>>>\n";
    std::cout << "TOKEN_STRING: " << token_string << '\n';
    std::cout << "TOKEN_TYPE: " << token_type << '\n';
    std::cout << '\n';
  }
};



class Abstract_token_builder{
public:

  virtual void build_token_pars(std::shared_ptr<Token> some_token) = 0;
  virtual void build_token_pars(std::string some_name, std::shared_ptr<Token> some_token) = 0;

  void build_line_occurence(int curr_line, std::shared_ptr<Token> some_token){ // Was virtual with no behavior
    some_token -> set_line_occurence(curr_line);
  }

  std::shared_ptr<Token> get_token(std::string token_name){  

    std::shared_ptr<Token> token_product = std::make_shared<Token>(token_name);

    return token_product; 
  }

  std::shared_ptr<Token> get_token(){

    std::shared_ptr<Token> token_product = std::make_shared<Token>();

    return token_product; 
  }
};



class Token_if_builder : public Abstract_token_builder{
public:
  void build_token_pars(std::shared_ptr<Token> token_product){
    token_product -> set_token_string("if");
    token_product -> set_token_type("Keyword");
    //token_product -> display_elements();
  }

  void build_token_pars(std::string some_name, std::shared_ptr<Token> token_product){
    std::cout << "INCORRECT USE OF Token_if_builder!!!!!!!!!!!!!!\n";
  }
};

class Token_else_if_builder : public Abstract_token_builder{
public:
  void build_token_pars(std::shared_ptr<Token> token_product){
    token_product -> set_token_string("else if");
    token_product -> set_token_type("Keyword");
    //token_product -> display_elements();
  }

  void build_token_pars(std::string some_name, std::shared_ptr<Token> token_product){
    std::cout << "INCORRECT USE OF Token_else_if_builder!!!!!!!!!!!!!!\n";
  }
};
  
class Token_else_builder : public Abstract_token_builder{
public:
  void build_token_pars(std::shared_ptr<Token> token_product){
    token_product -> set_token_string("else");
    token_product -> set_token_type("Keyword");
    //token_product -> display_elements();
  }

  void build_token_pars(std::string some_name, std::shared_ptr<Token> token_product){
    std::cout << "INCORRECT USE OF Token_else_builder!!!!!!!!!!!!!!!\n";
  }
};

class Token_while_builder : public Abstract_token_builder{
public:
  void build_token_pars(std::shared_ptr<Token> token_product){
    token_product -> set_token_string("while");
    token_product -> set_token_type("Keyword");
    //token_product -> display_elements();
  }

  void build_token_pars(std::string some_name, std::shared_ptr<Token> token_product){
    std::cout << "INCORRECT USE OF Token_while_builder!!!!!!!!!!\n";
  }
};


class Token_for_builder : public Abstract_token_builder{
public:
  void build_token_pars(std::shared_ptr<Token> token_product){
    token_product -> set_token_string("for");
    token_product -> set_token_type("Keyword");
    //token_product -> display_elements();
  }

  void build_token_pars(std::string some_name, std::shared_ptr<Token> token_product){
    std::cout << "INCORRECT USE OF Token_for_builder!!!!!!!!!!\n";
  }
};

class Token_var_builder : public Abstract_token_builder{
public:
  void build_token_pars(std::shared_ptr<Token> token_product){
    token_product -> set_token_string("var");
    token_product -> set_token_type("Keyword");
    //token_product -> display_elements();
  }

  void build_token_pars(std::string some_name, std::shared_ptr<Token> token_product){
    std::cout << "INCORRECT USE OF Token_var_builder!!!!!!!!!!\n";
  }
};

class Token_and_builder : public Abstract_token_builder{
public:
  void build_token_pars(std::shared_ptr<Token> token_product){
    token_product -> set_token_string("and");
    token_product -> set_token_type("Keyword");
    //token_product -> display_elements();
  }

  void build_token_pars(std::string some_name, std::shared_ptr<Token> token_product){
    std::cout << "INCORRECT USE OF Token_and_builder!!!!!!!!!!\n";
  }
};

class Token_or_builder : public Abstract_token_builder{
public:
  void build_token_pars(std::shared_ptr<Token> token_product){
    token_product -> set_token_string("or");
    token_product -> set_token_type("Keyword");
    //token_product -> display_elements();
  }

  void build_token_pars(std::string some_name, std::shared_ptr<Token> token_product){
    std::cout << "INCORRECT USE OF Token_or_builder!!!!!!!!!!\n";
  }
};

class Token_false_builder : public Abstract_token_builder{
public:
  void build_token_pars(std::shared_ptr<Token> token_product){
    token_product -> set_token_string("false");
    token_product -> set_token_type("Keyword");
    //token_product -> display_elements();
  }

  void build_token_pars(std::string some_name, std::shared_ptr<Token> token_product){
    std::cout << "INCORRECT USE OF Token_false_builder!!!!!!!!!!\n";
  }
};

class Token_true_builder : public Abstract_token_builder{
public:
  void build_token_pars(std::shared_ptr<Token> token_product){
    token_product -> set_token_string("true");
    token_product -> set_token_type("Keyword");
    //token_product -> display_elements();
  }

  void build_token_pars(std::string some_name, std::shared_ptr<Token> token_product){
    std::cout << "INCORRECT USE OF Token_true_builder!!!!!!!!!!\n";
  }
};

class Token_print_builder : public Abstract_token_builder{
public:
  void build_token_pars(std::shared_ptr<Token> token_product){
    token_product -> set_token_string("print");
    token_product -> set_token_type("Keyword");
    //token_product -> display_elements();
  }

  void build_token_pars(std::string some_name, std::shared_ptr<Token> token_product){
    std::cout << "INCORRECT USE OF Token_print_builder!!!!!!!!!!\n";
  }
};

class Token_return_builder : public Abstract_token_builder{
public:
  void build_token_pars(std::shared_ptr<Token> token_product){
    token_product -> set_token_string("return");
    token_product -> set_token_type("Keyword");
    //token_product -> display_elements();
  }

  void build_token_pars(std::string some_name, std::shared_ptr<Token> token_product){
    std::cout << "INCORRECT USE OF Token_return_builder!!!!!!!!!!\n";
  }
};

class Token_function_builder : public Abstract_token_builder{
public:
  void build_token_pars(std::shared_ptr<Token> token_product){
    token_product -> set_token_string("function");
    token_product -> set_token_type("Keyword");
    //token_product -> display_elements();
  }

  void build_token_pars(std::string some_name, std::shared_ptr<Token> token_product){
    std::cout << "INCORRECT USE OF Token_function_builder!!!!!!!!!!\n";
  }
};

class Token_switch_builder : public Abstract_token_builder{
public:
  void build_token_pars(std::shared_ptr<Token> token_product){
    token_product -> set_token_string("switch");
    token_product -> set_token_type("Keyword");
    //token_product -> display_elements();
  }

  void build_token_pars(std::string some_name, std::shared_ptr<Token> token_product){
    std::cout << "INCORRECT USE OF Token_switch_builder!!!!!!!!!!\n";
  }
};

class Token_case_builder : public Abstract_token_builder{
public:
  void build_token_pars(std::shared_ptr<Token> token_product){
    token_product -> set_token_string("case");
    token_product -> set_token_type("Keyword");
    //token_product -> display_elements();
  }

  void build_token_pars(std::string some_name, std::shared_ptr<Token> token_product){
    std::cout << "INCORRECT USE OF Token_case_builder!!!!!!!!!!\n";
  }
};

class Token_command_builder : public Abstract_token_builder{
public:
  void build_token_pars(std::shared_ptr<Token> token_product){
    token_product -> set_token_string("command");
    token_product -> set_token_type("Keyword");
    //token_product -> display_elements();
  }

  void build_token_pars(std::string some_name, std::shared_ptr<Token> token_product){
    std::cout << "INCORRECT USE OF Token_command_builder!!!!!!!!!!\n";
  }
};

class Token_string_builder : public Abstract_token_builder{
public:
  void build_token_pars(std::string string_token, std::shared_ptr<Token> token_product){
    token_product -> set_token_string(string_token);
    token_product -> set_token_type("String");
    //token_product -> display_elements();
  }

  void build_token_pars(std::shared_ptr<Token> token_product){
    std::cout << "INCORRECT USE OF Token_string_builder!!!!!!!!!!\n";
  }
};
// WE START AT THE VERY BEGINNINGS; THE INCUBATORS
class Token_separator_left_brace_builder : public Abstract_token_builder{
public:
  void build_token_pars(std::shared_ptr<Token> token_product){
    token_product -> set_token_string("{");
    token_product -> set_token_type("Separator");
    //token_product -> display_elements();
  }

  void build_token_pars(std::string some_name, std::shared_ptr<Token> token_product){
    std::cout << "INCORRECT USE OF Token_separator_left_brace_builder!!!!!!!!!!\n";
  }
};

class Token_separator_right_brace_builder : public Abstract_token_builder{
public:
  void build_token_pars(std::shared_ptr<Token> token_product){
    token_product -> set_token_string("}");
    token_product -> set_token_type("Separator");
    //token_product -> display_elements();
  }

  void build_token_pars(std::string some_name, std::shared_ptr<Token> token_product){
    std::cout << "INCORRECT USE OF Token_separator_right_brace_builder!!!!!!!!!!\n";
  }
};

class Token_separator_left_bracket_builder : public Abstract_token_builder{
public:
  void build_token_pars(std::shared_ptr<Token> token_product){
    token_product -> set_token_string("(");
    token_product -> set_token_type("Separator");
    //token_product -> display_elements();
  }

  void build_token_pars(std::string some_name, std::shared_ptr<Token> token_product){
    std::cout << "INCORRECT USE OF Token_separator_left_bracket_builder!!!!!!!!!!\n";
  }
};

class Token_separator_right_bracket_builder : public Abstract_token_builder{
public:
  void build_token_pars(std::shared_ptr<Token> token_product){
    token_product -> set_token_string(")");
    token_product -> set_token_type("Separator");
    //token_product -> display_elements();
  }

  void build_token_pars(std::string some_name, std::shared_ptr<Token> token_product){
    std::cout << "INCORRECT USE OF Token_separator_right_bracket_builder!!!!!!!!!!\n";
  }
};

class Token_line_break_builder : public Abstract_token_builder{
public:
  void build_token_pars(std::shared_ptr<Token> token_product){
    token_product -> set_token_string("\n");
    token_product -> set_token_type("Separator");
    //token_product -> display_elements();
  }

  void build_token_pars(std::string some_name, std::shared_ptr<Token> token_product){
    std::cout << "INCORRECT USE OF Token_line_break_builder!!!!!!!!!!\n";
  }
};

class Token_comma_builder : public Abstract_token_builder{
public:
  void build_token_pars(std::shared_ptr<Token> token_product){
    token_product -> set_token_string(",");
    token_product -> set_token_type("Separator");
    //token_product -> display_elements();
  }

  void build_token_pars(std::string some_name, std::shared_ptr<Token> token_product){
    std::cout << "INCORRECT USE OF Token_comma_builder!!!!!!!!!!\n";
  }
};

class Token_semicolon_builder : public Abstract_token_builder{
public:
  void build_token_pars(std::shared_ptr<Token> token_product){
    token_product -> set_token_string(";");
    token_product -> set_token_type("Separator");
    //token_product -> display_elements();
  }

  void build_token_pars(std::string some_name, std::shared_ptr<Token> token_product){
    std::cout << "INCORRECT USE OF Token_semicolon_builder!!!!!!!!!!\n";
  }
};

class Token_double_quotation_builder : public Abstract_token_builder{
public:
  void build_token_pars(std::shared_ptr<Token> token_product){
    token_product -> set_token_string("\"");
    token_product -> set_token_type("Separator");
    //token_product -> display_elements();
  }

  void build_token_pars(std::string some_name, std::shared_ptr<Token> token_product){
    std::cout << "INCORRECT USE OF Token_double_quotation_builder!!!!!!!!!!\n";
  }
};

class Token_single_quotation_builder : public Abstract_token_builder{
public:
  void build_token_pars(std::shared_ptr<Token> token_product){
    token_product -> set_token_string("'");
    token_product -> set_token_type("Separator");
    //token_product -> display_elements();
  }

  void build_token_pars(std::string some_name, std::shared_ptr<Token> token_product){
    std::cout << "INCORRECT USE OF Token_single_quotation_builder!!!!!!!!!!\n";
  }
};

class Token_star_builder : public Abstract_token_builder{
public:
  void build_token_pars(std::shared_ptr<Token> token_product){
    token_product -> set_token_string("*");
    token_product -> set_token_type("Operator");
    //token_product -> display_elements();
  }

  void build_token_pars(std::string some_name, std::shared_ptr<Token> token_product){
    std::cout << "INCORRECT USE OF Token_star_builder!!!!!!!!!!\n";
  }
};

class Token_normal_slash_builder : public Abstract_token_builder{
public:
  void build_token_pars(std::shared_ptr<Token> token_product){
    token_product -> set_token_string("/");
    token_product -> set_token_type("Operator");
    //token_product -> display_elements();
  }

  void build_token_pars(std::string some_name, std::shared_ptr<Token> token_product){
    std::cout << "INCORRECT USE OF Token_normal_slash_builder!!!!!!!!!!\n";
  }
};

class Token_escape_slash_builder : public Abstract_token_builder{
public:
  void build_token_pars(std::shared_ptr<Token> token_product){
    token_product -> set_token_string("\\");
    token_product -> set_token_type("Operator");
    //token_product -> display_elements();
  }

  void build_token_pars(std::string some_name, std::shared_ptr<Token> token_product){
    std::cout << "INCORRECT USE OF Token_escape_slash_builder!!!!!!!!!!\n";
  }
};

class Token_bang_builder : public Abstract_token_builder{
public:
  void build_token_pars(std::shared_ptr<Token> token_product){
    token_product -> set_token_string("!");
    token_product -> set_token_type("Operator");
    //token_product -> display_elements();
  }

  void build_token_pars(std::string some_name, std::shared_ptr<Token> token_product){
    std::cout << "INCORRECT USE OF Token_bang_builder!!!!!!!!!!\n";
  }
};

class Token_equal_builder : public Abstract_token_builder{
public:
  void build_token_pars(std::shared_ptr<Token> token_product){
    token_product -> set_token_string("=");
    token_product -> set_token_type("Operator");
    //token_product -> display_elements();
  }

  void build_token_pars(std::string some_name, std::shared_ptr<Token> token_product){
    std::cout << "INCORRECT USE OF Token_equal_builder!!!!!!!!!!\n";
  }
};

class Token_is_equal_builder : public Abstract_token_builder{
public:
  void build_token_pars(std::shared_ptr<Token> token_product){
    token_product -> set_token_string("==");
    token_product -> set_token_type("Operator");
    //token_product -> display_elements();
  }

  void build_token_pars(std::string some_name, std::shared_ptr<Token> token_product){
    std::cout << "INCORRECT USE OF Token_is_equal_builder!!!!!!!!!!\n";
  }
};

class Token_not_equal_builder : public Abstract_token_builder{
public:
  void build_token_pars(std::shared_ptr<Token> token_product){
    token_product -> set_token_string("!=");
    token_product -> set_token_type("Operator");
    //token_product -> display_elements();
  }

  void build_token_pars(std::string some_name, std::shared_ptr<Token> token_product){
    std::cout << "INCORRECT USE OF Token_not_equal_builder!!!!!!!!!!\n";
  }
};


class Token_leftGreaterRight_builder : public Abstract_token_builder{
 public:
  void build_token_pars(std::shared_ptr<Token> token_product){
    token_product -> set_token_string(">");
    token_product -> set_token_type("Operator");
    //token_product -> display_elements();
  }

  void build_token_pars(std::string some_name, std::shared_ptr<Token> token_product){
    std::cout << "INCORRECT USE OF Token_leftGreaterRight_builder!!!!!!!!!!\n";
  }
};

class Token_leftLessRight_builder : public Abstract_token_builder{
 public:
  void build_token_pars(std::shared_ptr<Token> token_product){
    token_product -> set_token_string("<");
    token_product -> set_token_type("Operator");
    //token_product -> display_elements();
  }

  void build_token_pars(std::string some_name, std::shared_ptr<Token> token_product){
    std::cout << "INCORRECT USE OF Token_leftLessRight_builder!!!!!!!!!!\n";
  }
};

class Token_leftLessRightOrEqual_builder : public Abstract_token_builder{
 public:
  void build_token_pars(std::shared_ptr<Token> token_product){
    token_product -> set_token_string("<=");
    token_product -> set_token_type("Operator");
    //token_product -> display_elements();
  }

  void build_token_pars(std::string some_name, std::shared_ptr<Token> token_product){
    std::cout << "INCORRECT USE OF Token_leftLessRightOrEqual_builder!!!!!!!!!!\n";
  }
};

class Token_leftGreaterRightOrEqual_builder : public Abstract_token_builder{
 public:
  void build_token_pars(std::shared_ptr<Token> token_product){
    token_product -> set_token_string(">=");
    token_product -> set_token_type("Operator");
    //token_product -> display_elements();
  }

  void build_token_pars(std::string some_name, std::shared_ptr<Token> token_product){
    std::cout << "INCORRECT USE OF Token_leftGreaterRightOrEqual_builder!!!!!!!!!!\n";
  }
};

class Token_dot_builder : public Abstract_token_builder{
 public:
  void build_token_pars(std::shared_ptr<Token> token_product){
    token_product -> set_token_string(".");
    token_product -> set_token_type("Operator");
    //token_product -> display_elements();
  }

  void build_token_pars(std::string some_name, std::shared_ptr<Token> token_product){
    std::cout << "INCORRECT USE OF Token_dot_builder!!!!!!!!!!\n";
  }
};

class Token_plus_builder : public Abstract_token_builder{
 public:
  void build_token_pars(std::shared_ptr<Token> token_product){
    token_product -> set_token_string("+");
    token_product -> set_token_type("Operator");
    //token_product -> display_elements();
  }

  void build_token_pars(std::string some_name, std::shared_ptr<Token> token_product){
    std::cout << "INCORRECT USE OF Token_plus_builder!!!!!!!!!!\n";
  }
};

class Token_plus_plus_builder : public Abstract_token_builder{
 public:
  void build_token_pars(std::shared_ptr<Token> token_product){
    token_product -> set_token_string("++");
    token_product -> set_token_type("Operator");
    //token_product -> display_elements();
  }

  void build_token_pars(std::string some_name, std::shared_ptr<Token> token_product){
    std::cout << "INCORRECT USE OF Token_plus_plus_builder!!!!!!!!!!\n";
  }
};

class Token_minus_builder : public Abstract_token_builder{
public:
  void build_token_pars(std::shared_ptr<Token> token_product){
    token_product -> set_token_string("-");
    token_product -> set_token_type("Operator");
    //token_product -> display_elements();
  }

  void build_token_pars(std::string some_name, std::shared_ptr<Token> token_product){
    std::cout << "INCORRECT USE OF Token_minus_builder!!!!!!!!!!\n";
  }
};

class Token_minus_minus_builder : public Abstract_token_builder{ 
public: 
  void build_token_pars(std::shared_ptr<Token> token_product){
    token_product -> set_token_string("--");
    token_product -> set_token_type("Operator");
    //token_product -> display_elements();
  }

  void build_token_pars(std::string some_name, std::shared_ptr<Token> token_product){
    std::cout << "INCORRECT USE OF Token_minus_minus_builder!!!!!!!!!!\n";
  }
};

class Token_literal_builder : public Abstract_token_builder{
public:
  void build_token_pars(std::string literal, std::shared_ptr<Token> token_product){
    token_product -> set_token_string(literal);
    token_product -> set_token_type("Literal");
    //token_product -> display_elements();
  }

  void build_token_pars(std::shared_ptr<Token> token_product){
    std::cout << "INCORRECT USE OF Token_literal_builder!!!!!!!!!!\n";
  }
};

class Token_shell_builder : public Abstract_token_builder{
public:
  void build_token_pars(std::shared_ptr<Token> token_product){ //This costd::shared_ptr<Token> token_productmmand is for running shell scripts 
    token_product -> set_token_string("shell");
    token_product -> set_token_type("Keyword");
    //token_product -> display_elements();
  }

  void build_token_pars(std::string some_name, std::shared_ptr<Token> token_product){
    std::cout << "INCORRECT USE OF Token_shell_builder!!!!!!!!!!\n"; 
  }
};

class Token_script_builder : public Abstract_token_builder{
public:
  void build_token_pars(std::shared_ptr<Token> token_product){ //This costd::shared_ptr<Token> token_productmmand is for running shell scripts within the command mode itself
    token_product -> set_token_string("script");
    token_product -> set_token_type("Keyword");
    //token_product -> display_elements();
  }

  void build_token_pars(std::string some_name, std::shared_ptr<Token> token_product){
    std::cout << "INCORRECT USE OF Token_script_builder!!!!!!!!!!!!!!!!\n";
  }
};

class Token_plus_equal_builder : public Abstract_token_builder{
public:
  void build_token_pars(std::shared_ptr<Token> token_product){
    token_product -> set_token_string("+=");
    token_product -> set_token_type("Operator");
    //token_product -> display_elements();
  }

  void build_token_pars(std::string some_name, std::shared_ptr<Token> token_product){
    std::cout << "INCORRECT USE OF Token_plus_equal_builder!!!!!!!!!!!!!!!!\n";
  }
};

class Token_minus_equal_builder : public Abstract_token_builder{
public:
  void build_token_pars(std::shared_ptr<Token> token_product){
    token_product -> set_token_string("-=");
    token_product -> set_token_type("Operator");
    //token_product -> display_elements();
  }

  void build_token_pars(std::string some_name, std::shared_ptr<Token> token_product){
    std::cout << "INCORRECT USE OF Token_minus_equal_builder!!!!!!!!!!!!!!!!\n";
  }
};

class Token_star_star_builder : public Abstract_token_builder{
public:
  void build_token_pars(std::shared_ptr<Token> token_product){
    token_product -> set_token_string("**");
    token_product -> set_token_type("Operator");
    //token_product -> display_elements();
  }

  void build_token_pars(std::string some_name, std::shared_ptr<Token> token_product){
    std::cout << "INCORRECT USE OF Token_star_star_builder!!!!!!!!!!!!!!!!\n";
  }
};



class Token_director_singleton{
private:
  Token_director_singleton(){};
  static Token_director_singleton global_instance;
 
public:
  // CREATING A NORMAL TOKEN FOR LITERALS
  std::shared_ptr<Token> build_token(std::string token_name, int line_occurence, std::shared_ptr<Abstract_token_builder> some_builder){
    auto created_token = some_builder -> get_token();
    some_builder -> build_token_pars(token_name, created_token);
    some_builder -> build_line_occurence(line_occurence, created_token);
    return created_token;
  }

  // CREATING A NORMAL TOKEN FOR KEYWORDS 
  std::shared_ptr<Token> build_token(int line_occurence, std::shared_ptr<Abstract_token_builder> some_builder){
    auto created_token = some_builder -> get_token();
    some_builder -> build_token_pars(created_token);
    some_builder -> build_line_occurence(line_occurence, created_token);
    return created_token; 
  }

  // OLD
  // VIRTUAL TOKEN (THIS ONE IS CAUSING A SEG FAULT) THEY WILL ALL DO SO BECAUSE THE ISSUE HAS TO DO WITH THE shared_ptr
  // Alhamudllah the problem was solved. NEVER USE SMART POINTERS ON STACK ALLOCATED OBJECTS
  /*
  std::shared_ptr<Token> build_token(std::shared_ptr<Abstract_token_builder> some_builder){
    std::cout << "I BEGAN HERE\n";
    auto created_token = some_builder -> get_token();
    some_builder -> build_token_pars(created_token); 
    std::cout << "I ENDED HERE\n";
    return created_token;
  }
  */

  static Token_director_singleton& get_global_instance(){
    return global_instance;
  }
};



//Initialize once, use forever ...
extern Token_director_singleton& director_object;


class Singleton_data{
private:
  Singleton_data(){}
  
  static Singleton_data global_instance;

public: 
  std::unordered_map<std::string, std::shared_ptr<Abstract_token_builder>> keywords_map;
  std::unordered_map<std::string, std::shared_ptr<Abstract_token_builder>> double_char_operator_or_separator_map;
  
  static Singleton_data& get_global_instance(){
    return global_instance;
  }
  
  void add_token_builder(std::string token_name, std::shared_ptr<Abstract_token_builder> new_builder){
    keywords_map[token_name] = new_builder;
  }

  void add_double_char_token_builder(std::string token_name, std::shared_ptr<Abstract_token_builder> new_builder){
    double_char_operator_or_separator_map[token_name] = new_builder;
  }

  void display_token_builders(){
    int curr_index = 0;

    for(const auto& pair: keywords_map){
      curr_index++;
      std::cout << pair.first << "\t\t:ORDER:\t" << curr_index << "\t:WITH ADDRESSES:\t"<< pair.second << '\n';
    }
  }

  std::shared_ptr<Token> check_merge_need(std::shared_ptr<Token> token_ptr_1, std::shared_ptr<Token> token_ptr_2){
    int line_presence = token_ptr_1 -> get_line_occurence();
    std::shared_ptr<Abstract_token_builder> merged_token_builder;
    std::shared_ptr<Token> merged_token_ptr;
    std::string key_string = token_ptr_1 -> get_token_string() + token_ptr_2 -> get_token_string();

    if(double_char_operator_or_separator_map.count(key_string)){
      merged_token_builder = double_char_operator_or_separator_map[key_string];
      merged_token_ptr = director_object.build_token(line_presence, merged_token_builder);
      return merged_token_ptr;
    }
    return nullptr;
  }
};



// Intialize once, use forever ...
extern Singleton_data& Global_data; 



class Abstract_adder{
  virtual void call_add_token_builder() = 0;
};



class if_adder : public Abstract_adder{
public: 
  void call_add_token_builder(){
    auto new_builder = std::make_shared<Token_if_builder>();
    Global_data.add_token_builder("if", new_builder);
  }
  
  if_adder(){
    call_add_token_builder();
  }
};


class else_adder : public Abstract_adder{
public: 
  void call_add_token_builder(){
    auto new_builder = std::make_shared<Token_else_builder>();
    Global_data.add_token_builder("else", new_builder);
  }

  else_adder(){
    call_add_token_builder();
  }
};

class else_if_adder : public Abstract_adder{
public:
  void call_add_token_builder(){
    auto new_builder = std::make_shared<Token_else_if_builder>();
    Global_data.add_token_builder("else if", new_builder);
  }

  else_if_adder(){
    call_add_token_builder();
  }
}; class and_adder : public Abstract_adder{
public:
  void call_add_token_builder(){
    auto new_builder = std::make_shared<Token_and_builder>();
    Global_data.add_token_builder("and", new_builder);
  }

  and_adder(){
    call_add_token_builder();
  }
};

class or_adder : public Abstract_adder{
public:
  void call_add_token_builder(){
    auto new_builder = std::make_shared<Token_or_builder>();
    Global_data.add_token_builder("or", new_builder);
  }

  or_adder(){
    call_add_token_builder();
  }
};

class var_adder : public Abstract_adder{
public:
  void call_add_token_builder(){
    auto new_builder = std::make_shared<Token_var_builder>();
    Global_data.add_token_builder("var", new_builder);
  }

  var_adder(){
    call_add_token_builder();
  }
};

class false_adder : public Abstract_adder{
public:
  void call_add_token_builder(){
    auto new_builder = std::make_shared<Token_false_builder>();
    Global_data.add_token_builder("false", new_builder);
  }

  false_adder(){
    call_add_token_builder();
  }
};

class true_adder : public Abstract_adder{
public:
  void call_add_token_builder(){
    auto new_builder = std::make_shared<Token_true_builder>();
    Global_data.add_token_builder("true", new_builder);
  }

  true_adder(){
    call_add_token_builder();
  }
};

class print_adder : public Abstract_adder{
public:
  void call_add_token_builder(){
    auto new_builder = std::make_shared<Token_print_builder>();
    Global_data.add_token_builder("print", new_builder);
  }

  print_adder(){
    call_add_token_builder();
  }
};

class return_adder : public Abstract_adder{
public:
  void call_add_token_builder(){
    auto new_builder = std::make_shared<Token_return_builder>();
    Global_data.add_token_builder("return", new_builder);
  }

  return_adder(){
    call_add_token_builder();
  }
};

class function_adder : public Abstract_adder{
public:
  void call_add_token_builder(){
    auto new_builder = std::make_shared<Token_function_builder>();
    Global_data.add_token_builder("function", new_builder);
  }

  function_adder(){
    call_add_token_builder();
  }
};

class switch_adder : public Abstract_adder{
public:
  void call_add_token_builder(){
    auto new_builder = std::make_shared<Token_switch_builder>();
    Global_data.add_token_builder("switch", new_builder);
  }

  switch_adder(){
    call_add_token_builder();
  }
};

class while_adder : public Abstract_adder{
public:
  void call_add_token_builder(){
    auto new_builder = std::make_shared<Token_while_builder>();
    Global_data.add_token_builder("while", new_builder);
  }

  while_adder(){
    call_add_token_builder();
  }
};

class for_adder : public Abstract_adder{
public:
  void call_add_token_builder(){
    auto new_builder = std::make_shared<Token_for_builder>();
    Global_data.add_token_builder("for", new_builder);
  }

  for_adder(){
    call_add_token_builder();
  }
};

class case_adder : public Abstract_adder{
public:
  void call_add_token_builder(){
    auto new_builder = std::make_shared<Token_case_builder>();
    Global_data.add_token_builder("case", new_builder);
  }

  case_adder(){
    call_add_token_builder();
  }
};

class command_adder : public Abstract_adder{
public:
  void call_add_token_builder(){
    auto new_builder = std::make_shared<Token_command_builder>();
    Global_data.add_token_builder("command", new_builder);
  }

  command_adder(){
    call_add_token_builder();
  }
};

class left_brace_adder : public Abstract_adder{
public:
  void call_add_token_builder(){
    auto new_builder = std::make_shared<Token_separator_left_brace_builder>();
    Global_data.add_token_builder("{", new_builder);
  }

  left_brace_adder(){
    call_add_token_builder();
  }
};

class right_brace_adder : public Abstract_adder{
public:
  void call_add_token_builder(){
    auto new_builder = std::make_shared<Token_separator_right_brace_builder>();
    Global_data.add_token_builder("}", new_builder);
  }

  right_brace_adder(){
    call_add_token_builder();
  }
};

class left_bracket_adder : public Abstract_adder{
public:
  void call_add_token_builder(){
    auto new_builder = std::make_shared<Token_separator_left_bracket_builder>();
    Global_data.add_token_builder("(", new_builder);
  }

  left_bracket_adder(){
    call_add_token_builder();
  }
};

class right_bracket_adder : public Abstract_adder{
public:
  void call_add_token_builder(){
    auto new_builder = std::make_shared<Token_separator_right_bracket_builder>();
    Global_data.add_token_builder(")", new_builder);
  }

  right_bracket_adder(){
    call_add_token_builder();
  } };

class line_break_adder : public Abstract_adder{ 
public:
  void call_add_token_builder(){
    auto new_builder = std::make_shared<Token_line_break_builder>();
    Global_data.add_token_builder("\n", new_builder);
  }

  line_break_adder(){
    call_add_token_builder();
  }
};

class comma_adder : public Abstract_adder{
public:
  void call_add_token_builder(){
    auto new_builder = std::make_shared<Token_comma_builder>();
    Global_data.add_token_builder(",", new_builder);
  }

  comma_adder(){
    call_add_token_builder();
  }
};

class semicolon_adder : public Abstract_adder{
public:
  void call_add_token_builder(){
    auto new_builder = std::make_shared<Token_semicolon_builder>();
    Global_data.add_token_builder(";", new_builder);
  }

  semicolon_adder(){
    call_add_token_builder();
  }
};

class double_quotation_adder : public Abstract_adder{
public:
  void call_add_token_builder(){
    auto new_builder = std::make_shared<Token_double_quotation_builder>();
    Global_data.add_token_builder("\"", new_builder);
  }

  double_quotation_adder(){
    call_add_token_builder();
  }
};

class single_quotation_adder : public Abstract_adder{
public: 
  void call_add_token_builder(){ 
    auto new_builder = std::make_shared<Token_single_quotation_builder>();
    Global_data.add_token_builder("'", new_builder); 
  }

  single_quotation_adder(){
    call_add_token_builder();
  }
};


class star_adder : public Abstract_adder{
public:
  void call_add_token_builder(){
    auto new_builder = std::make_shared<Token_star_builder>();
    Global_data.add_token_builder("*", new_builder);
  }

  star_adder(){
    call_add_token_builder();
  }
};

class normal_slash_adder : public Abstract_adder{
public:
  void call_add_token_builder(){
    auto new_builder = std::make_shared<Token_normal_slash_builder>();
    Global_data.add_token_builder("/", new_builder);
  }

  normal_slash_adder(){
    call_add_token_builder();
  }
};

class escape_slash_adder : public Abstract_adder{
public:
  void call_add_token_builder(){
    auto new_builder = std::make_shared<Token_escape_slash_builder>();
    Global_data.add_token_builder("\\", new_builder);
  }

  escape_slash_adder(){
    call_add_token_builder();
  }
};

class bang_adder : public Abstract_adder{
public:
  void call_add_token_builder(){
    auto new_builder = std::make_shared<Token_bang_builder>();
    Global_data.add_token_builder("!", new_builder);
  }

  bang_adder(){
    call_add_token_builder();
  }
};

class equal_adder : public Abstract_adder{
public:
  void call_add_token_builder(){
    auto new_builder = std::make_shared<Token_equal_builder>();
    Global_data.add_token_builder("=", new_builder);
  }

  equal_adder(){
    call_add_token_builder();
  }
};

class is_equal_adder : public Abstract_adder{
public:
  void call_add_token_builder(){
    auto new_builder = std::make_shared<Token_is_equal_builder>();
    Global_data.add_token_builder("==", new_builder);
  }

  is_equal_adder(){
    call_add_token_builder();
  }
};

class not_equal_adder : public Abstract_adder{
public:
  void call_add_token_builder(){
    auto new_builder = std::make_shared<Token_not_equal_builder>();
    Global_data.add_token_builder("!=", new_builder);
  }

  not_equal_adder(){
    call_add_token_builder();
  }
};

class LeftGreaterRight_adder : public Abstract_adder{
public:
  void call_add_token_builder(){
    auto new_builder = std::make_shared<Token_leftGreaterRight_builder>();
    Global_data.add_token_builder(">", new_builder);
  }

  LeftGreaterRight_adder(){
    call_add_token_builder();
  }
};

class LeftLessRight_adder : public Abstract_adder{
public:
  void call_add_token_builder(){
    auto new_builder = std::make_shared<Token_leftLessRight_builder>();
    Global_data.add_token_builder("<", new_builder);
  }

  LeftLessRight_adder(){
    call_add_token_builder();
  }
};

class LeftGreaterRightOrEqual_adder : public Abstract_adder{
public:
  void call_add_token_builder(){
    auto new_builder = std::make_shared<Token_leftGreaterRightOrEqual_builder>();
    Global_data.add_token_builder(">=", new_builder);
  }

  LeftGreaterRightOrEqual_adder(){
    call_add_token_builder();
  }
};

class LeftLessRightOrEqual_adder : public Abstract_adder{
public:
  void call_add_token_builder(){
    auto new_builder = std::make_shared<Token_leftLessRightOrEqual_builder>();
    Global_data.add_token_builder("<=", new_builder);
  }

  LeftLessRightOrEqual_adder(){
    call_add_token_builder();
  }
};

class dot_adder : public Abstract_adder{
public:
  void call_add_token_builder(){
    auto new_builder = std::make_shared<Token_dot_builder>();
    Global_data.add_token_builder(".", new_builder);
  }

  dot_adder(){
    call_add_token_builder();
  }
};

class plus_adder : public Abstract_adder{
public:
  void call_add_token_builder(){
    auto new_builder = std::make_shared<Token_plus_builder>();
    Global_data.add_token_builder("+", new_builder);
  }

  plus_adder(){
    call_add_token_builder();
  }
};

class plus_plus_adder : public Abstract_adder{
public:
  void call_add_token_builder(){
    auto new_builder = std::make_shared<Token_plus_plus_builder>();
    Global_data.add_token_builder("++", new_builder);
  }

  plus_plus_adder(){
    call_add_token_builder();
  }
};

class minus_adder : public Abstract_adder{
public:
  void call_add_token_builder(){
    auto new_builder = std::make_shared<Token_minus_builder>();
    Global_data.add_token_builder("-", new_builder);
  }

  minus_adder(){
    call_add_token_builder();
  }
};

class minus_minus_adder : public Abstract_adder{
public:
  void call_add_token_builder(){
    auto new_builder = std::make_shared<Token_minus_minus_builder>();
    Global_data.add_token_builder("--", new_builder);
  }

  minus_minus_adder(){
    call_add_token_builder();
  }
};

class shell_adder : public Abstract_adder{
public:
  void call_add_token_builder(){
    auto new_builder = std::make_shared<Token_shell_builder>();
    Global_data.add_token_builder("shell", new_builder);
  }

  shell_adder(){
    call_add_token_builder();
  }
};

class script_adder : public Abstract_adder{
public:
  void call_add_token_builder(){
    auto new_builder = std::make_shared<Token_script_builder>();
    Global_data.add_token_builder("script", new_builder);
  }

  script_adder(){
    call_add_token_builder();
  }
};



// Double char operator and separator adders
class double_adder{
  virtual void call_add_token_builder () = 0; 
};



class LeftLessRightOrEqual_double_adder : public double_adder{
public:
  void call_add_token_builder(){
    auto new_builder = std::make_shared<Token_leftLessRightOrEqual_builder>();
    Global_data.add_double_char_token_builder("<=", new_builder);
  }

  LeftLessRightOrEqual_double_adder(){
    call_add_token_builder();
  }
};

class LeftGreaterRightOrEqual_double_adder : public double_adder{
public:
  void call_add_token_builder(){
    auto new_builder = std::make_shared<Token_leftGreaterRightOrEqual_builder>();
    Global_data.add_double_char_token_builder(">=", new_builder);
  }
  
  LeftGreaterRightOrEqual_double_adder(){
    call_add_token_builder();
  }
};

class plus_plus_double_adder : public double_adder{
public:
  void call_add_token_builder(){
    auto new_builder = std::make_shared<Token_plus_plus_builder>();
    Global_data.add_double_char_token_builder("++", new_builder);
  }

  plus_plus_double_adder(){
    call_add_token_builder();
  }
};

class is_equal_double_adder : public double_adder{
public:
  void call_add_token_builder(){
    auto new_builder = std::make_shared<Token_is_equal_builder>();
    Global_data.add_double_char_token_builder("==", new_builder);
  }

  is_equal_double_adder(){
    call_add_token_builder();
  }
};

class minus_minus_double_adder : public double_adder{
public:
  void call_add_token_builder(){
    auto new_builder = std::make_shared<Token_minus_minus_builder>();
    Global_data.add_double_char_token_builder("--", new_builder);
  }

  minus_minus_double_adder(){
    call_add_token_builder();
  }
};

class plus_equal_double_adder : public double_adder{
public:
  void call_add_token_builder(){
    auto new_builder = std::make_shared<Token_plus_equal_builder>();
    Global_data.add_double_char_token_builder("+=", new_builder);
  }

  plus_equal_double_adder(){
    call_add_token_builder();
  }
};

class minus_equal_double_adder : public double_adder{
public:
void call_add_token_builder(){
    auto new_builder = std::make_shared<Token_minus_equal_builder>();
    Global_data.add_double_char_token_builder("-=", new_builder);
  }

  minus_equal_double_adder(){
    call_add_token_builder();
  }
};

class star_star_double_adder : public double_adder{
public:
void call_add_token_builder(){
    auto new_builder = std::make_shared<Token_star_star_builder>();
    Global_data.add_double_char_token_builder("**", new_builder);
  }

  star_star_double_adder(){
    call_add_token_builder();
  }
};

class not_equal_double_adder : public double_adder{
public:
void call_add_token_builder(){
    auto new_builder = std::make_shared<Token_not_equal_builder>();
    Global_data.add_double_char_token_builder("!=", new_builder);
  }

  not_equal_double_adder(){
    call_add_token_builder();
  }
};




class Script{
private:
  long unsigned int start_index = 0;
  long unsigned int secondPhaseStartIndex = 0;
  int line_counter = 1;

  std::string string_buffer;

  std::vector<std::shared_ptr<Token>> tokenized_output;  // statically allocated, DO NOT USED SHARED_PTRS
  std::vector<std::shared_ptr<Token>> semiTokenizedOutput;

public:

  void lex(){
    //std::cout << "I STARTED?\n";
    firstPhaseStartState();
    secondPhaseStartState();
    thirdPhaseLex();
    checkNumOrLiteral();
    fourthPhaseLex(); // WE ARE IN THE TESTING OF THIS RN
  }

  Script(std::string string_buffer){
    this -> string_buffer = string_buffer;
  }  

  Script(){

  }

  

  void display_tokenized_output(){

    for(long unsigned int i = 0; i < tokenized_output.size(); i++){
      std::cout << "TOKEN: " << i << '\n';
      tokenized_output[i] -> display_elements();
    }
  }
  
  void set_buffer_string(std::string new_string_buffer){
    string_buffer = new_string_buffer;
  }
  std::string get_string_buffer(){
    return string_buffer;  
  }

  std::vector<std::shared_ptr<Token>>* get_token_vector_pointer(){
    return &tokenized_output;
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

  long unsigned int get_index(){
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
  
  std::vector<std::shared_ptr<Token>> get_tokenized_output(){
    return this -> tokenized_output;
  }

  void add_to_tokenized_output(std::shared_ptr<Token> new_token){
    this -> tokenized_output.push_back(new_token);
  }


  /*
  // Algorithm implementation (uses the state design pattern)
  
  // CHECK KEYWORD RELATED VARIABLES
  long unsigned int max_lookahead = 0;
  std::string sub_string;

  void set_max_lookahead(){
    int temp_max_lookahead = 0;
    while(temp_max_lookahead + start_index < string_buffer.length() && temp_max_lookahead < 11){

      temp_max_lookahead ++;
    }
    max_lookahead = temp_max_lookahead;
  }

  bool check_keyword(){
    // HOW ARE YOU CALLING THE FUNCTION AFTER USING THE STRING???????????????????
    // BRO, I COMING FROM THE FUTURE AFTER A FEW HOURS OF DEBUGGING. I KINDA DON'T UNDERSTAND WHY TBH
    set_max_lookahead();

    if(start_index >= string_buffer.length()){

      return false;
    }

    for(long unsigned int i = max_lookahead; i > 0 ; i--){ 
      
      sub_string = string_buffer.substr(start_index, i); 

      //std::cout << "Took sub_sub_string from index: " << start_index << " to " << i + start_index << '\n';

      if(Global_data.keywords_map.count(sub_string)){
        //std::cout << '\n';
        //std::cout << "Large keyword found: \"" << sub_string << "\" :at line: " << get_line() << '\n'; // TESTING
        //std::cout << '\n';
        //
        //std::cout << "Standing at line: " << get_line() << '\n';
        std::shared_ptr<Token> created_token_pointer = director_object.build_token(get_line(), Global_data.keywords_map[sub_string]);
        add_to_tokenized_output(created_token_pointer);

        //std::cout << "Large tokenized_output: " << tokenized_output.size() << '\n';
        

        // THIS IS INSIDE THE IF CONDITION
        increment_index_custom(i);

        return true;
      }
    }

    std::cout << sub_string << '\n'; // TESTING
     
    // WILL INTEGRATING IT WORK??????
    return false;
    //jump_dist = 1;
  }

  bool check_and_add_char_token(){

    set_max_lookahead();

    if(start_index >= string_buffer.length() - 1){

      return false;
    }
    
    sub_string = string_buffer.substr(start_index, 1);
      
    if(Global_data.keywords_map.count(sub_string)){

      std::cout << sub_string << '\n'; // TESTING
      //std::cout << "Number of owners of the pointer in the map: " << Global_data.keywords_map[sub_string].use_count() << '\n';
      std::shared_ptr<Token> created_token_pointer = director_object.build_token(get_line(), Global_data.keywords_map[sub_string]);

      add_to_tokenized_output(created_token_pointer);

      increment_index();

      return true;
    }
    

    return false;
  }

  std::shared_ptr<Token> check_only_char_token(){

    set_max_lookahead();

    std::shared_ptr<Token> created_token_pointer; 

    if(start_index >= string_buffer.length()){

      return nullptr; // MAY CAUSE AN ISSUE
    }
    
    sub_string = string_buffer.substr(start_index, 1);
      
    
    if(Global_data.keywords_map.count(sub_string)){

      created_token_pointer = director_object.build_token(get_line(), Global_data.keywords_map[sub_string]);

      increment_index();

      return created_token_pointer;
    }

    return nullptr;
  }



  std::string temp_string = "";
  
  void fn_start_state(){

    set_max_lookahead();
    
    std::shared_ptr<Token> created_token_pointer;
    std::shared_ptr<Token_escape_slash_builder> escape_slash_builder = std::make_shared<Token_escape_slash_builder>();

    if(get_index() >= string_buffer.length()){ // WHEN IT ALL PASSES ALL TESTS CHANGE >= to ==
      //std::cout << "Ended lexing due to hitting buffer end!\n";
      return;
    }

    
    if(check_keyword()){
      //std::cout << "FOUND LARGE KEYWORD!!!!!!!!!\n";
      fn_start_state();
    }
    
    // and keep in mind \ is an operator
    
    else{
      //std::cout << "WAS NOT MET WITH EITHER KEYWORD " << "because it is: " << sub_string << '\n';
      switch(string_buffer[start_index]){
        case ' ':
          //std::cout << "fn_start_state() met a whitespace\n";
          increment_index();
          fn_start_state();
          break;
        case '/':
          //std::cout << "fn_start_state() met a normal_slash\n";
          //increment_index();
          comment_state_1();
          break;
        case '\n':
          //std::cout << "fn_start_state() met a line_break\n";
          increment_line_counter();
          increment_index();
          fn_start_state();
          break;
        case '\'':
          //std::cout << "fn_start_state() met an escape_slash\n";

          created_token_pointer = director_object.build_token(get_line(), escape_slash_builder);
          add_to_tokenized_output(created_token_pointer);
          increment_index();

          break;
        case '"':
          //std::cout << "fn_start_state() met a double_quotation\n";
          string_state();
          break;
        default:

          literal_state();
          break;
      }
    }
  }

  
  void literal_state(){

    if(get_index() >= string_buffer.length()){ // WHEN IT ALL PASSES ALL TESTS CHANGE >= to ==
      //std::cout << "Ended lexing due to hitting buffer end!\n";
      return;
    }

    set_max_lookahead();

    std::shared_ptr<Abstract_token_builder> temp_builder = nullptr;

    std::shared_ptr<Token> created_token_pointer = check_only_char_token();
    std::shared_ptr<Token> created_token_pointer_literal = nullptr; 

    if(created_token_pointer != nullptr){
      if(temp_string != ""){
        temp_builder = std::make_shared<Token_literal_builder>();
        created_token_pointer_literal = director_object.build_token(temp_string, get_line(), temp_builder);
        add_to_tokenized_output(created_token_pointer_literal);
      }

      temp_string = "";

      add_to_tokenized_output(created_token_pointer);

      increment_index(); // THIS WAS ADDED (BECAUSE I NORMALLY SHOULD HAVE) IT KINDA WORKED WITHOUT IT, which it weird tbh  
      fn_start_state();
    }

    else{
      switch(string_buffer[start_index]){
        case ' ':
          //std::cout << "literal_state() met a whitespace\n";

          temp_builder = std::make_shared<Token_literal_builder>();
          created_token_pointer = director_object.build_token(temp_string, get_line(), temp_builder);
          add_to_tokenized_output(created_token_pointer);

          temp_string = ""; // I DON'T WANT TO BE  DEALING WITH GARBAGE VALUES LYING AROUND
          increment_index();
          fn_start_state();

          break;
        case '/':
          //std::cout << "literal_state() met a normal_slash\n";

          temp_builder = std::make_shared<Token_literal_builder>();
          created_token_pointer = director_object.build_token(temp_string, get_line(), temp_builder);
          add_to_tokenized_output(created_token_pointer);

          
          temp_string = ""; // I DON'T WANT TO BE  DEALING WITH GARBAGE VALUES LYING AROUND
          //increment_index();
          comment_state_1();

          break;
        case '\n':
          //std::cout << "literal_state() met a line_break\n";

          temp_builder = std::make_shared<Token_literal_builder>();
          created_token_pointer = director_object.build_token(temp_string, get_line(), temp_builder);
          add_to_tokenized_output(created_token_pointer);

          increment_line_counter();

          temp_string = ""; // I DON'T WANT TO BE  DEALING WITH GARBAGE VALUES LYING AROUND
          increment_index();
          fn_start_state();

          break;
        case '\'':
          // WAAAAAAAAAAAAARRRNING THIS WILL BE ADDED BEFORE TEMP_STRING
          //std::cout << "literal_state() met an escape_slash\n";

          temp_builder = std::make_shared<Token_literal_builder>();
          created_token_pointer = director_object.build_token(temp_string, get_line(), temp_builder);
          add_to_tokenized_output(created_token_pointer);

          temp_builder = std::make_shared<Token_escape_slash_builder>(); // IN THIS, temp_builder WILL BE A NULLPTR
          created_token_pointer = director_object.build_token(get_line(), temp_builder); 
          add_to_tokenized_output(created_token_pointer);

          temp_string = ""; // I DON'T WANT TO BE  DEALING WITH GARBAGE VALUES LYING AROUND
          increment_index();
          fn_start_state();

          break;
        case '"':

          created_token_pointer = director_object.build_token(temp_string, get_line(), temp_builder);
          add_to_tokenized_output(created_token_pointer);
          
          temp_string = ""; // I DON'T WANT TO BE  DEALING WITH GARBAGE VALUES LYING AROUND

          string_state();

          break;
        default:

          temp_string += string_buffer[start_index];

          if(get_index() == string_buffer.length() - 1){
            temp_builder = std::make_shared<Token_literal_builder>();
            created_token_pointer_literal = director_object.build_token(temp_string, get_line(), temp_builder);
            add_to_tokenized_output(created_token_pointer_literal);
          }

          increment_index(); // This was added  recently
          //std::cout << "literal_state called itself!\n";
          literal_state();

          break;
      }
    }
  }


  void string_state(){

    if(get_index() >= string_buffer.length()){
      return;
    }

    set_max_lookahead();

    std::shared_ptr<Abstract_token_builder> temp_builder;
    // FOR THE SAKE OF PEACEFUL DEBUGGING, I WILL LEAVE THE DOUBLE QUOTATIONS

    temp_string.push_back(string_buffer[start_index]);
    increment_index();

    while(string_buffer[start_index] != '"'){

      temp_string.push_back(string_buffer[start_index]);
      increment_index();
      // I AM NOT DOING ANY SUB STRINGS (NOT NOW)
    }

    temp_string.push_back('"');

    temp_builder = std::make_shared<Token_string_builder>(); 
    tokenized_output.push_back(director_object.build_token(temp_string, get_line(), temp_builder));
    
    temp_string = ""; // THIS IS VERY IMPORTANT. I DON'T WANT ANY GARBAGE VALUES LYING AROUND
    //std::cout << "string_state called itself!\n";

    increment_index();
    fn_start_state();
  }

  void comment_state_1(){

    if(get_index() >= string_buffer.length()){
      return;
    }
    
    std::cout << "comment_state_1 :: " << string_buffer[start_index] << '\n';
    
    set_max_lookahead();

    std::shared_ptr<Abstract_token_builder> temp_builder;
    switch(string_buffer[start_index + 1]){
      case '*':
        increment_index(); // OLD INCREMENT
        increment_index(); // NEW INCREMENT
        std::cout << "Passed to comment_state_2 separation is by * / !\n";
        comment_state_2();
        break; 
      case '/':
        increment_index();
        increment_index();
        std::cout << "Passed to comment_state_3 separation is by escape character n !\n";
        comment_state_3();
        break;
      default:
        temp_builder = std::make_shared<Token_normal_slash_builder>();
        tokenized_output.push_back(director_object.build_token(get_line(), temp_builder));
        increment_index();

        if(check_and_add_char_token()){
          fn_start_state();
        }

        else if(check_keyword()){
          fn_start_state();
        }

        else{
          increment_index();
          literal_state();
        }
         
        break;
    }
    
  }

  void comment_state_2(){
    std::cout << "comment_state_2 :: " << string_buffer[start_index] << '\n';

    if(get_index() >= string_buffer.length()){
      return;
    }

    set_max_lookahead();

    switch(string_buffer[start_index]){
      case '*':
        increment_index();
        comment_state_4();
        break;
      default:
        increment_index();
        comment_state_2();
        break;
    }
  }

    void comment_state_3(){
    
      std::cout << "comment_state_3 :: " << string_buffer[start_index] << '\n';

      if(get_index() >= string_buffer.length()){
        return;
      }

      set_max_lookahead();

      switch(string_buffer[start_index]){
        case '\n' :
          increment_index();
          fn_start_state();
          break;
        default:
          increment_index();
          comment_state_3();
          break;
      }
    }

    void comment_state_4(){
      
      std::cout << "comment_state_4 :: " << string_buffer[start_index] << '\n';

      if(get_index() >= string_buffer.length()){
        return;
      }

      set_max_lookahead();

      switch(string_buffer[start_index]){
        case '/':
          increment_index();
          fn_start_state();
          break;
        default:
          increment_index();
          comment_state_2();
          break;
      } 
    }
    */
   

  std::string tempStringPhase1 = "";
  std::string tempStringPhase2 = "";
  std::shared_ptr<Abstract_token_builder> temp_builder;


  void firstPhaseStartState(){
    if(start_index >= string_buffer.length()){
      return;
    }

    if(string_buffer[start_index] == '/'){
      temp_builder = std::make_shared<Token_normal_slash_builder>();
      semiTokenizedOutput.push_back(director_object.build_token(get_line(), temp_builder));
      start_index ++;
      firstPhaseLiteralState();
    }
    else if(string_buffer[start_index] == '*'){
      temp_builder = std::make_shared<Token_star_builder>();
      semiTokenizedOutput.push_back(director_object.build_token(get_line(), temp_builder));
      start_index ++;
      firstPhaseLiteralState();
    }
    else if(string_buffer[start_index] == '"'){
      firstPhaseStringState();
    }
    else if(string_buffer[start_index] == '\n'){
      line_counter ++;
      start_index ++;
      firstPhaseStartState();
    }
    else if(string_buffer[start_index] == ' '){
      start_index ++;
      firstPhaseStartState();
    } else if(Global_data.keywords_map.count(std::string(1, string_buffer[start_index]))){
      temp_builder = Global_data.keywords_map[std::string(1, string_buffer[start_index])];
      semiTokenizedOutput.push_back(director_object.build_token(get_line(), temp_builder));
      start_index ++;
      firstPhaseStartState();
    }
    else{
      firstPhaseLiteralState();
    }
  }





  void firstPhaseLiteralState(){
    if(start_index >= string_buffer.length()){
      return;
    }

    if(string_buffer[start_index] == '/'){
      temp_builder = std::make_shared<Token_literal_builder>();
      semiTokenizedOutput.push_back(director_object.build_token(tempStringPhase1, get_line(), temp_builder));

      temp_builder = std::make_shared<Token_normal_slash_builder>();
      semiTokenizedOutput.push_back(director_object.build_token(get_line(), temp_builder));
      start_index ++;
      tempStringPhase1 = "";
      firstPhaseStartState();
    }
    else if(string_buffer[start_index] == '*'){
      temp_builder = std::make_shared<Token_literal_builder>();
      semiTokenizedOutput.push_back(director_object.build_token(tempStringPhase1, get_line(), temp_builder));

      temp_builder = std::make_shared<Token_star_builder>();
      semiTokenizedOutput.push_back(director_object.build_token(get_line(), temp_builder));
      start_index ++;
      tempStringPhase1 = "";
      firstPhaseStartState();
    }
    else if(string_buffer[start_index] == '"'){
      temp_builder = std::make_shared<Token_literal_builder>();
      semiTokenizedOutput.push_back(director_object.build_token(tempStringPhase1, get_line(), temp_builder));
      tempStringPhase1 = "";
      firstPhaseStringState();
    }
    else if(string_buffer[start_index] == '\n'){
      temp_builder = std::make_shared<Token_literal_builder>();
      semiTokenizedOutput.push_back(director_object.build_token(tempStringPhase1, get_line(), temp_builder));
      line_counter ++;
      start_index ++;
      tempStringPhase1 = "";
      firstPhaseStartState();
    }
    else if(string_buffer[start_index] == ' '){
      temp_builder = std::make_shared<Token_literal_builder>();
      semiTokenizedOutput.push_back(director_object.build_token(tempStringPhase1, get_line(), temp_builder));
      
      start_index ++;
      tempStringPhase1 = "";
      firstPhaseStartState();
    }

    else if(Global_data.keywords_map.count(std::string(1, string_buffer[start_index]))){
      temp_builder = std::make_shared<Token_literal_builder>();
      semiTokenizedOutput.push_back(director_object.build_token(tempStringPhase1, get_line(), temp_builder));
    
      temp_builder = Global_data.keywords_map[std::string(1, string_buffer[start_index])];
      semiTokenizedOutput.push_back(director_object.build_token(get_line(), temp_builder));
      start_index ++;
      tempStringPhase1 = "";
      firstPhaseStartState();
    }
    else{
      tempStringPhase1.push_back(string_buffer[start_index]);
      start_index ++;
      firstPhaseLiteralState();
    }

  }





  void firstPhaseStringState(){
    if(start_index >= string_buffer.length()){
      return;
    }

    tempStringPhase1.push_back(string_buffer[start_index]);
    start_index ++;

    if(string_buffer[start_index] == '"'){
      tempStringPhase1.push_back(string_buffer[start_index]);
      temp_builder = std::make_shared<Token_string_builder>();
      semiTokenizedOutput.push_back(director_object.build_token(tempStringPhase1, get_line(), temp_builder));
      start_index ++;
      tempStringPhase1 = "";
      firstPhaseStartState();
    }
    firstPhaseStringState();
  }





  void secondPhaseStartState(){
    if(secondPhaseStartIndex >= semiTokenizedOutput.size()){
      return;
    }

    if(semiTokenizedOutput[secondPhaseStartIndex] -> get_token_string() == "/"){
      secondPhaseStartIndex ++;
      if(secondPhaseStartIndex >= semiTokenizedOutput.size()){
        return;
      }

      if(semiTokenizedOutput[secondPhaseStartIndex] -> get_token_string() == "*"){
        secondPhaseStartIndex ++;
        blockCommentState();
      }
      else if(semiTokenizedOutput[secondPhaseStartIndex] -> get_token_string() == "/"){
        secondPhaseStartIndex ++;
        lineCommentState();
      }
      else{
        tokenized_output.push_back(semiTokenizedOutput[secondPhaseStartIndex - 1]);
        tokenized_output.push_back(semiTokenizedOutput[secondPhaseStartIndex]);
        secondPhaseStartIndex ++;
        secondPhaseStartState();
      }

    }
    else{
      tokenized_output.push_back(semiTokenizedOutput[secondPhaseStartIndex]);
      secondPhaseStartIndex ++;
      secondPhaseStartState();
    }
  }



  

  void blockCommentState(){
    if(secondPhaseStartIndex >= semiTokenizedOutput.size()){
      return;
    }

    if(semiTokenizedOutput[secondPhaseStartIndex] -> get_token_string() == "*"){
      secondPhaseStartIndex ++;
      if(secondPhaseStartIndex >= semiTokenizedOutput.size()){
        return;
      }
      
      if(semiTokenizedOutput[secondPhaseStartIndex] -> get_token_string() == "/"){
        secondPhaseStartIndex ++;
        secondPhaseStartState();
      }
      else{
        secondPhaseStartIndex ++;
        blockCommentState();
      }
    }
  }





  void lineCommentState(){
    if(semiTokenizedOutput[secondPhaseStartIndex] -> get_token_string() == "\n"){
      secondPhaseStartIndex ++;
      secondPhaseStartState();
    }
  }
  

  long unsigned int newCounter = 0;


  void thirdPhaseLex(){
    if(newCounter >= tokenized_output.size()){
      return;
    }

    if(Global_data.keywords_map.count(tokenized_output[newCounter] -> get_token_string()) && tokenized_output[newCounter] -> get_token_string().length() > 1){
      tokenized_output[newCounter] -> set_token_type("Keyword");
    }
    newCounter ++;
    thirdPhaseLex();
    /*
    if(tokenized_output[newCounter] -> get_token_string() == "print"){
      std::cout << "THERE IS THE ISSUE: \n";
    }
    */
    newCounter ++;
  }


    
  bool isNum(std::shared_ptr<Token> tokenToCheck){
    
    bool floatAlready = false;

    for(long unsigned int i = 0; i < tokenToCheck -> get_token_string().length(); i++){
      if(isdigit(tokenToCheck -> get_token_string().at(i))){
         
      }
      else if(tokenToCheck -> get_token_string().at(i) == '.' && floatAlready == false){
        floatAlready = true; 
      }
      else{
        return false;
      }
    }
    return true;
  }

  void checkNumOrLiteral(){
    
    std::shared_ptr<Token> currToken;

    for(long unsigned int i = 0; i < tokenized_output.size(); i++){
      currToken = tokenized_output.at(i);
      if(isNum(currToken)){
        currToken -> set_token_type("Number");
      }
    }
  }



  void fourthPhaseLex(){
    std::shared_ptr<Token> token_ptr_1; 
    std::shared_ptr<Token> token_ptr_2;
    std::shared_ptr<Token> token_ptr_merged;
    
    for(long unsigned int i = 0; i < tokenized_output.size() - 1; i++){

      token_ptr_1 = tokenized_output[i];
      token_ptr_2 = tokenized_output[i + 1];

      token_ptr_merged = Global_data.check_merge_need(token_ptr_1, token_ptr_2); // This object was already created

      if(token_ptr_merged != nullptr){
      
        std::cout << "something required to be merged!\n";

        tokenized_output.erase(tokenized_output.begin() + i + 1);
        tokenized_output[i] = token_ptr_merged; 
      }
    }
  }

  
  };












