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
    std::cout << "NO PARAMETERS GIVEN FOR TOKEN CONSTRUCTOR!!!!!\n";
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
    std::cout << "TOKEN_STRING: " << token_string << '\n';
    std::cout << "TOKEN_TYPE: " << token_type << '\n';
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
    token_product -> display_elements();
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
    token_product -> display_elements();
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
    token_product -> display_elements();
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
    token_product -> display_elements();
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
    token_product -> display_elements();
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
    token_product -> display_elements();
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
    token_product -> display_elements();
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
    token_product -> display_elements();
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
    token_product -> display_elements();
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
    token_product -> display_elements();
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
    token_product -> display_elements();
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
    token_product -> display_elements();
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
    token_product -> display_elements();
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
    token_product -> display_elements();
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
    token_product -> display_elements();
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
    token_product -> display_elements();
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
    token_product -> display_elements();
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
    token_product -> display_elements();
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
    token_product -> display_elements();
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
    token_product -> display_elements();
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
    token_product -> display_elements();
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
    token_product -> display_elements();
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
    token_product -> display_elements();
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
    token_product -> display_elements();
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
    token_product -> display_elements();
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
    token_product -> display_elements();
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
    token_product -> display_elements();
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
    token_product -> display_elements();
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
    token_product -> display_elements();
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
    token_product -> display_elements();
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
    token_product -> display_elements();
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
    token_product -> display_elements();
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
    token_product -> display_elements();
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
    token_product -> display_elements();
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
    token_product -> display_elements();
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
    token_product -> display_elements();
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
    token_product -> display_elements();
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
    token_product -> display_elements();
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
    token_product -> display_elements();
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
    token_product -> display_elements();
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
    token_product -> display_elements();
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
    token_product -> display_elements();
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
    token_product -> display_elements();
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
    token_product -> display_elements();
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
    token_product -> display_elements();
  }

  void build_token_pars(std::string some_name, std::shared_ptr<Token> token_product){
    std::cout << "INCORRECT USE OF Token_script_builder!!!!!!!!!!!!!!!!\n";
  }
};



class Token_director_singleton{
private:
  Token_director_singleton(){};
  static Token_director_singleton global_instance;

public:
  // CREATING A NORMAL TOKEN FOR LITERALS
  std::shared_ptr<Token> build_token(std::string token_name, int line_occurence, std::shared_ptr<Abstract_token_builder> some_builder){
    auto created_token = some_builder -> get_token(token_name);
    some_builder -> build_token_pars(created_token);
    some_builder -> build_line_occurence(line_occurence, created_token);
    return created_token;
  }

  // CREATING A NORMAL TOKEN FOR KEYWORDS 
  std::shared_ptr<Token> build_token(int line_occurence, std::shared_ptr<Abstract_token_builder> some_builder){
    auto created_token = some_builder -> get_token();
    some_builder -> build_token_pars(created_token);
    some_builder -> build_line_occurence(line_occurence, created_token);
    return some_builder -> get_token();
  }

  // VIRTUAL TOKEN (THIS ONE IS CAUSING A SEG FAULT) THEY WILL ALL DO SO BECAUSE THE ISSUE HAS TO DO WITH THE shared_ptr
  // Alhamudllah the problem was solved. NEVER USE SMART POINTERS ON STACK ALLOCATED OBJECTS
  std::shared_ptr<Token> build_token(std::shared_ptr<Abstract_token_builder> some_builder){
    std::cout << "I BEGAN HERE\n";
    auto created_token = some_builder -> get_token();
    some_builder -> build_token_pars(created_token); 
    std::cout << "I ENDED HERE\n";
    return created_token;
  }

  static Token_director_singleton& get_global_instance(){
    return global_instance;
  }
};



//Initialize once, use forever ...
//Token_director_singleton& director_object = Token_director_singleton :: get_global_instance(); // old line
extern Token_director_singleton& director_object;


//This class should be instantiated after the subclasses are instantiated ?
class Singleton_data{
private:
  std::unordered_map<std::string, std::shared_ptr<Token>> keywords_map;

  Singleton_data(){}
  
  static Singleton_data global_instance;

public: 
  static Singleton_data& get_global_instance(){
    return global_instance;
  }

  void display_keywords_map(){
    for(const auto& pair : keywords_map){
      std::cout << pair.first << " has values: " << '\n';
      pair.second -> display_elements();
    }
  }

  void add_token(std::string token_name, std::shared_ptr<Abstract_token_builder> new_builder){
    if(new_builder.use_count() != 0){
      std::cout << "OWNED :" << new_builder.use_count() << '\n';
      keywords_map[token_name] = director_object.build_token(new_builder); 
    }
    else{
      std::cout << "WHAT THE HELL \n";
    }
  }
};



// Intialize once, use forever ...
extern Singleton_data& Global_data; 

class Abstract_adder{
  virtual void call_add_token() = 0;
};


class if_adder : public Abstract_adder{
public: 
  void call_add_token(){
    auto new_builder = std::make_shared<Token_if_builder>();
    Global_data.add_token("if", new_builder);
  }

  if_adder(){
    call_add_token();
  }
};


class else_adder : public Abstract_adder{
public: 
  void call_add_token(){
    auto new_builder = std::make_shared<Token_else_builder>();
    Global_data.add_token("else", new_builder);
  }

  else_adder(){
    call_add_token();
  }
};

class else_if_adder : public Abstract_adder{
public:
  void call_add_token(){
    auto new_builder = std::make_shared<Token_else_if_builder>();
    Global_data.add_token("else if", new_builder);
  }

  else_if_adder(){
    call_add_token();
  }
}; class and_adder : public Abstract_adder{
public:
  void call_add_token(){
    auto new_builder = std::make_shared<Token_and_builder>();
    Global_data.add_token("and", new_builder);
  }

  and_adder(){
    call_add_token();
  }
};

class or_adder : public Abstract_adder{
public:
  void call_add_token(){
    auto new_builder = std::make_shared<Token_or_builder>();
    Global_data.add_token("or", new_builder);
  }

  or_adder(){
    call_add_token();
  }
};

class var_adder : public Abstract_adder{
public:
  void call_add_token(){
    auto new_builder = std::make_shared<Token_var_builder>();
    Global_data.add_token("var", new_builder);
  }

  var_adder(){
    call_add_token();
  }
};

class false_adder : public Abstract_adder{
public:
  void call_add_token(){
    auto new_builder = std::make_shared<Token_false_builder>();
    Global_data.add_token("false", new_builder);
  }

  false_adder(){
    call_add_token();
  }
};

class true_adder : public Abstract_adder{
public:
  void call_add_token(){
    auto new_builder = std::make_shared<Token_true_builder>();
    Global_data.add_token("true", new_builder);
  }

  true_adder(){
    call_add_token();
  }
};

class print_adder : public Abstract_adder{
public:
  void call_add_token(){
    auto new_builder = std::make_shared<Token_print_builder>();
    Global_data.add_token("print", new_builder);
  }

  print_adder(){
    call_add_token();
  }
};

class return_adder : public Abstract_adder{
public:
  void call_add_token(){
    auto new_builder = std::make_shared<Token_return_builder>();
    Global_data.add_token("return", new_builder);
  }

  return_adder(){
    call_add_token();
  }
};

class function_adder : public Abstract_adder{
public:
  void call_add_token(){
    auto new_builder = std::make_shared<Token_function_builder>();
    Global_data.add_token("function", new_builder);
  }

  function_adder(){
    call_add_token();
  }
};

class switch_adder : public Abstract_adder{
public:
  void call_add_token(){
    auto new_builder = std::make_shared<Token_switch_builder>();
    Global_data.add_token("switch", new_builder);
  }

  switch_adder(){
    call_add_token();
  }
};

class while_adder : public Abstract_adder{
public:
  void call_add_token(){
    auto new_builder = std::make_shared<Token_while_builder>();
    Global_data.add_token("while", new_builder);
  }

  while_adder(){
    call_add_token();
  }
};

class for_adder : public Abstract_adder{
public:
  void call_add_token(){
    auto new_builder = std::make_shared<Token_for_builder>();
    Global_data.add_token("for", new_builder);
  }

  for_adder(){
    call_add_token();
  }
};

class case_adder : public Abstract_adder{
public:
  void call_add_token(){
    auto new_builder = std::make_shared<Token_case_builder>();
    Global_data.add_token("case", new_builder);
  }

  case_adder(){
    call_add_token();
  }
};

class command_adder : public Abstract_adder{
public:
  void call_add_token(){
    auto new_builder = std::make_shared<Token_comma_builder>();
    Global_data.add_token("command", new_builder);
  }

  command_adder(){
    call_add_token();
  }
};

class left_brace_adder : public Abstract_adder{
public:
  void call_add_token(){
    auto new_builder = std::make_shared<Token_separator_left_brace_builder>();
    Global_data.add_token("{", new_builder);
  }

  left_brace_adder(){
    call_add_token();
  }
};

class right_brace_adder : public Abstract_adder{
public:
  void call_add_token(){
    auto new_builder = std::make_shared<Token_separator_right_brace_builder>();
    Global_data.add_token("}", new_builder);
  }

  right_brace_adder(){
    call_add_token();
  }
};

class left_bracket_adder : public Abstract_adder{
public:
  void call_add_token(){
    auto new_builder = std::make_shared<Token_separator_left_bracket_builder>();
    Global_data.add_token("(", new_builder);
  }

  left_bracket_adder(){
    call_add_token();
  }
};

class right_bracket_adder : public Abstract_adder{
public:
  void call_add_token(){
    auto new_builder = std::make_shared<Token_separator_right_bracket_builder>();
    Global_data.add_token(")", new_builder);
  }

  right_bracket_adder(){
    call_add_token();
  }
};

class line_break_adder : public Abstract_adder{ 
public:
  void call_add_token(){
    auto new_builder = std::make_shared<Token_line_break_builder>();
    Global_data.add_token("\n", new_builder);
  }

  line_break_adder(){
    call_add_token();
  }
};

class comma_adder : public Abstract_adder{
public:
  void call_add_token(){
    auto new_builder = std::make_shared<Token_comma_builder>();
    Global_data.add_token(",", new_builder);
  }

  comma_adder(){
    call_add_token();
  }
};

class semicolon_adder : public Abstract_adder{
public:
  void call_add_token(){
    auto new_builder = std::make_shared<Token_semicolon_builder>();
    Global_data.add_token(";", new_builder);
  }

  semicolon_adder(){
    call_add_token();
  }
};

class double_quotation_adder : public Abstract_adder{
public:
  void call_add_token(){
    auto new_builder = std::make_shared<Token_double_quotation_builder>();
    Global_data.add_token("\"", new_builder);
  }

  double_quotation_adder(){
    call_add_token();
  }
};

class single_quotation_adder : public Abstract_adder{
public: 
  void call_add_token(){ 
    auto new_builder = std::make_shared<Token_single_quotation_builder>();
    Global_data.add_token("'", new_builder); 
  }

  single_quotation_adder(){
    call_add_token();
  }
};


class star_adder : public Abstract_adder{
public:
  void call_add_token(){
    auto new_builder = std::make_shared<Token_star_builder>();
    Global_data.add_token("*", new_builder);
  }

  star_adder(){
    call_add_token();
  }
};

class normal_slash_adder : public Abstract_adder{
public:
  void call_add_token(){
    auto new_builder = std::make_shared<Token_normal_slash_builder>();
    Global_data.add_token("/", new_builder);
  }

  normal_slash_adder(){
    call_add_token();
  }
};

class escape_slash_adder : public Abstract_adder{
public:
  void call_add_token(){
    auto new_builder = std::make_shared<Token_escape_slash_builder>();
    Global_data.add_token("\\", new_builder);
  }

  escape_slash_adder(){
    call_add_token();
  }
};

class bang_adder : public Abstract_adder{
public:
  void call_add_token(){
    auto new_builder = std::make_shared<Token_bang_builder>();
    Global_data.add_token("!", new_builder);
  }

  bang_adder(){
    call_add_token();
  }
};

class equal_adder : public Abstract_adder{
public:
  void call_add_token(){
    auto new_builder = std::make_shared<Token_equal_builder>();
    Global_data.add_token("=", new_builder);
  }

  equal_adder(){
    call_add_token();
  }
};

class is_equal_adder : public Abstract_adder{
public:
  void call_add_token(){
    auto new_builder = std::make_shared<Token_is_equal_builder>();
    Global_data.add_token("==", new_builder);
  }

  is_equal_adder(){
    call_add_token();
  }
};

class not_equal_adder : public Abstract_adder{
public:
  void call_add_token(){
    auto new_builder = std::make_shared<Token_not_equal_builder>();
    Global_data.add_token("!=", new_builder);
  }

  not_equal_adder(){
    call_add_token();
  }
};

class LeftGreaterRight_adder : public Abstract_adder{
public:
  void call_add_token(){
    auto new_builder = std::make_shared<Token_leftGreaterRight_builder>();
    Global_data.add_token(">", new_builder);
  }

  LeftGreaterRight_adder(){
    call_add_token();
  }
};

class LeftLessRight_adder : public Abstract_adder{
public:
  void call_add_token(){
    auto new_builder = std::make_shared<Token_leftLessRight_builder>();
    Global_data.add_token("<", new_builder);
  }

  LeftLessRight_adder(){
    call_add_token();
  }
};

class LeftGreaterRightOrEqual_adder : public Abstract_adder{
public:
  void call_add_token(){
    auto new_builder = std::make_shared<Token_leftGreaterRightOrEqual_builder>();
    Global_data.add_token(">=", new_builder);
  }

  LeftGreaterRightOrEqual_adder(){
    call_add_token();
  }
};

class LeftLessRightOrEqual_adder : public Abstract_adder{
public:
  void call_add_token(){
    auto new_builder = std::make_shared<Token_leftLessRightOrEqual_builder>();
    Global_data.add_token("<=", new_builder);
  }

  LeftLessRightOrEqual_adder(){
    call_add_token();
  }
};

class dot_adder : public Abstract_adder{
public:
  void call_add_token(){
    auto new_builder = std::make_shared<Token_dot_builder>();
    Global_data.add_token(".", new_builder);
  }

  dot_adder(){
    call_add_token();
  }
};

class plus_adder : public Abstract_adder{
public:
  void call_add_token(){
    auto new_builder = std::make_shared<Token_plus_builder>();
    Global_data.add_token("+", new_builder);
  }

  plus_adder(){
    call_add_token();
  }
};

class plus_plus_adder : public Abstract_adder{
public:
  void call_add_token(){
    auto new_builder = std::make_shared<Token_plus_plus_builder>();
    Global_data.add_token("++", new_builder);
  }

  plus_plus_adder(){
    call_add_token();
  }
};

class minus_adder : public Abstract_adder{
public:
  void call_add_token(){
    auto new_builder = std::make_shared<Token_minus_builder>();
    Global_data.add_token("-", new_builder);
  }

  minus_adder(){
    call_add_token();
  }
};

class minus_minus_adder : public Abstract_adder{
public:
  void call_add_token(){
    auto new_builder = std::make_shared<Token_minus_minus_builder>();
    Global_data.add_token("--", new_builder);
  }

  minus_minus_adder(){
    call_add_token();
  }
};

class shell_adder : public Abstract_adder{
public:
  void call_add_token(){
    auto new_builder = std::make_shared<Token_shell_builder>();
    Global_data.add_token("shell", new_builder);
  }

  shell_adder(){
    call_add_token();
  }
};

class script_adder : public Abstract_adder{
public:
  void call_add_token(){
    auto new_builder = std::make_shared<Token_script_builder>();
    Global_data.add_token("script", new_builder);
  }

  script_adder(){
    call_add_token();
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
  int max_lookahead = 8;

  std::string temp_string = "";

  void fn_start_state(){
    if(get_index() >= string_buffer.length()){
      return;
    }

    // FIRST CHECK FOR EXPRESSIONS \ is an operator


    switch(string_buffer[start_index]){
      case ' ':
      case '/':
      case '\n':
      default:
    }




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












