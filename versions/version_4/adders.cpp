#include <bits/stdc++.h>
#include "lexer.hpp"

// Single char operators, separators and full keywords
std::unique_ptr comma_adder_object = std::make_unique<comma_adder>();
std::unique_ptr if_add_object = std::make_unique<if_adder>();
std::unique_ptr else_add_object = std::make_unique<else_adder>();
std::unique_ptr else_add_if_add_object = std::make_unique<else_if_adder>();
std::unique_ptr while_add_object = std::make_unique<while_adder>();
std::unique_ptr for_add_object = std::make_unique<for_adder>();
std::unique_ptr var_add_object = std::make_unique<var_adder>();
std::unique_ptr and_add_object = std::make_unique<and_adder>();
std::unique_ptr or_add_object = std::make_unique<or_adder>();
std::unique_ptr false_add_object = std::make_unique<false_adder>();
std::unique_ptr true_add_object = std::make_unique<true_adder>();
std::unique_ptr print_add_object = std::make_unique<print_adder>();
std::unique_ptr return_add_object = std::make_unique<return_adder>();
std::unique_ptr function_add_object = std::make_unique<function_adder>();
std::unique_ptr siwitch_add_object = std::make_unique<switch_adder>();
std::unique_ptr case_add_object = std::make_unique<case_adder>();
std::unique_ptr command_add_object = std::make_unique<command_adder>();
std::unique_ptr left_brace_add_object = std::make_unique<left_brace_adder>();
std::unique_ptr right_brace_add_object = std::make_unique<right_brace_adder>();
std::unique_ptr LeftLessRight_add_object = std::make_unique<LeftLessRight_adder>();
std::unique_ptr LeftGreaterRight_add_object = std::make_unique<LeftGreaterRight_adder>();
//std::unique_ptr LeftLessRightOrEqual_add_object = std::make_unique<LeftLessRightOrEqual_adder>();
//std::unique_ptr LeftGreaterRightOrEqual_add_object = std::make_unique<LeftGreaterRightOrEqual_adder>();
std::unique_ptr left_bracket_add_object = std::make_unique<left_bracket_adder>();
std::unique_ptr right_bracket_add_object = std::make_unique<right_bracket_adder>();
//std::unique_ptr line_break_add_object = std::make_unique<line_break_adder>(); // WHY THE HELL DID YOU WANT TO ADD LINE BREAKS AS TOKENS??
std::unique_ptr semicolon_add_object = std::make_unique<semicolon_adder>();
//std::unique_ptr double_quotation_add_object = std::make_unique<double_quotation_adder>();
std::unique_ptr single_quotation_add_object = std::make_unique<single_quotation_adder>();
std::unique_ptr bang_add_object = std::make_unique<bang_adder>();
std::unique_ptr equal_add_object = std::make_unique<equal_adder>();
//std::unique_ptr equal_equal_add_object = std::make_unique<is_equal_adder>();
//std::unique_ptr not_equal_add_object = std::make_unique<not_equal_adder>();
std::unique_ptr dot_add_object = std::make_unique<dot_adder>();
std::unique_ptr plus_add_object = std::make_unique<plus_adder>();
std::unique_ptr minus_add_object = std::make_unique<minus_adder>();
//std::unique_ptr minus_minus_add_object = std::make_unique<minus_minus_adder>();
std::unique_ptr shell_add_object = std::make_unique<shell_adder>();
std::unique_ptr script_add_object = std::make_unique<script_adder>();
//std::unique_ptr plus_plus_add_object = std::make_unique<plus_plus_adder>();
//
//
//
//
//
// Double char operators or separators go here
std::unique_ptr is_equal_double_add_object = std::make_unique<is_equal_double_adder>();
std::unique_ptr plus_plus_add_object = std::make_unique<plus_plus_double_adder>();
std::unique_ptr minus_minus_double_add_object = std::make_unique<minus_minus_double_adder>();
std::unique_ptr minus_equal_double_add_object = std::make_unique<minus_equal_double_adder>();
std::unique_ptr star_star_double_add_object = std::make_unique<star_star_double_adder>();
std::unique_ptr plus_equal_double_add_object = std::make_unique<plus_equal_double_adder>() ;
std::unique_ptr not_equal_double_add_object = std::make_unique<not_equal_double_adder>();
std::unique_ptr LeftLessRightOrEqual_double_add_object = std::make_unique<LeftLessRightOrEqual_double_adder>();
std::unique_ptr LeftGreaterRightOrEqual_double_add_object = std::make_unique<LeftGreaterRightOrEqual_double_adder>();






