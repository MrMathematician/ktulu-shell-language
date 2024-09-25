#include "../../include/lexer/lexer.hpp"
#include "../../include/lexer/adders.hpp"
#include "../../include/parser/weak_t_parser.hpp"



RulesContainerSingelton RulesContainerSingelton :: globalInstance;
RulesContainerSingelton& rulesContainerSingeltonObject = RulesContainerSingelton :: getGlobalInstance();
