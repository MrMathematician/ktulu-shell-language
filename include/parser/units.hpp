#include <bits/stdc++.h>
#include "../lexer/lexer.hpp"
#pragma once

class CodeUnit{
public:
  std::string unitName;
  std::shared_ptr<CodeUnit> parent;
  std::deque<std::shared_ptr<CodeUnit>> codeBody; 
};

class FunctionUnit : public CodeUnit{
public:
  std::string functionName;
  std::vector<std::shared_ptr<Token>> parameters;
};

class VariableUnit : public CodeUnit{
public:
  std::string variableName;
  std::vector<std::shared_ptr<Token>> expression;
};

class ForUnit : public CodeUnit{
public:
  std::string counterVariableName;

  std::vector<std::shared_ptr<Token>> initialExpression;

  std::vector<std::shared_ptr<Token>> endExpression;

  std::vector<std::shared_ptr<Token>> incremenetExpression;

};

class WhileUnit : public CodeUnit{
public:
  std::vector<std::shared_ptr<Token>> endExpression;
};

class IfUnit : public CodeUnit{
public:
  std::vector<std::shared_ptr<Token>> conditionExpression; 
};

class ElseIfUnit : public CodeUnit{
public:
  std::vector<std::shared_ptr<Token>> conditionExpression;
};

class ElseUnit : public CodeUnit{
public:
  std::vector<std::shared_ptr<Token>> conditionExpression;
};

class SwitchUnit : public CodeUnit{
public:
  std::vector<std::shared_ptr<Token>> jumpExpression;
  std::unordered_map<std::shared_ptr<Token>, std::shared_ptr<CodeUnit>> cases;
};

class PrintUnit : public CodeUnit{
public:
  std::vector<std::shared_ptr<Token>> printExpression;
};

class InputUnit : public CodeUnit{};

