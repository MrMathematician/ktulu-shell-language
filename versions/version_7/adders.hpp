#include "lexer.hpp"



class AbstractTokenAdder{
public:
  void addExternalBuiltinToken();
};



class IfAdder : AbstractTokenAdder{
private: 
  void addExternalBuiltinToken(){
    builtInTokensData.addBuiltinToken("if", tokenType :: KEYWORD);
  }
public:
  IfAdder(){
    addExternalBuiltinToken();
  }
};

class ElseAdder : AbstractTokenAdder{
private: 
  void addExternalBuiltinToken(){
    builtInTokensData.addBuiltinToken("else", tokenType :: KEYWORD);
  }
public:
  ElseAdder(){
    addExternalBuiltinToken();
  }
};

class ElseIfAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    builtInTokensData.addBuiltinToken("else if", tokenType :: KEYWORD);
  }
public:
  ElseIfAdder(){
    addExternalBuiltinToken();
  }
}; 

class AndAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    builtInTokensData.addBuiltinToken("and", tokenType :: KEYWORD);
  } 
public:
  AndAdder(){
    addExternalBuiltinToken();
  }
};

class OrAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    builtInTokensData.addBuiltinToken("or", tokenType :: KEYWORD);
  }
public:
  OrAdder(){
    addExternalBuiltinToken();
  }
};

class VarAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    builtInTokensData.addBuiltinToken("var", tokenType :: KEYWORD);
  }
public:
  VarAdder(){
    addExternalBuiltinToken();
  }
};

class FalseAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    builtInTokensData.addBuiltinToken("false", tokenType :: KEYWORD);
  }
public:
  FalseAdder(){
    addExternalBuiltinToken();
  }
};

class TrueAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    builtInTokensData.addBuiltinToken("true", tokenType :: KEYWORD);
  }
public:
  TrueAdder(){
    addExternalBuiltinToken();
  }
};

class PrintAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    builtInTokensData.addBuiltinToken("print", tokenType :: KEYWORD);
  }
public:
  PrintAdder(){
    addExternalBuiltinToken();
  }
};

class ReturnAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    builtInTokensData.addBuiltinToken("return", tokenType :: KEYWORD);
  }
public:
  ReturnAdder(){
    addExternalBuiltinToken();
  }
};

class FunctionAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    builtInTokensData.addBuiltinToken("funct", tokenType :: KEYWORD);
  }
public:
  FunctionAdder(){
    addExternalBuiltinToken();
  }
};

class SwitchAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    builtInTokensData.addBuiltinToken("switch", tokenType :: KEYWORD);
  }
public:
  SwitchAdder(){
    addExternalBuiltinToken();
  }
};

class WhileAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    builtInTokensData.addBuiltinToken("while", tokenType :: KEYWORD);
  }
public:
  WhileAdder(){
    addExternalBuiltinToken();
  }
};

class ForAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    builtInTokensData.addBuiltinToken("for", tokenType :: KEYWORD);
  }
public:
  ForAdder(){
    addExternalBuiltinToken();
  }
};

class CaseAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    builtInTokensData.addBuiltinToken("case", tokenType :: KEYWORD);
  }
public:
  CaseAdder(){
    addExternalBuiltinToken();
  }
};

class CommandAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    builtInTokensData.addBuiltinToken("cmd", tokenType :: KEYWORD);
  }
public:
  CommandAdder(){
    addExternalBuiltinToken();
  }
};

class LeftBraceAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    builtInTokensData.addBuiltinToken("{", tokenType :: SEPARATOR);
  }
public:
  LeftBraceAdder(){
    addExternalBuiltinToken();
  }
};

class RightBraceAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    builtInTokensData.addBuiltinToken("}", tokenType :: SEPARATOR);
  }
public:
  RightBraceAdder(){
    addExternalBuiltinToken();
  }
};

class LeftBracketAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    builtInTokensData.addBuiltinToken("(", tokenType :: SEPARATOR);
  }
public:
  LeftBracketAdder(){
    addExternalBuiltinToken();
  }
};

class RightBracketAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    builtInTokensData.addBuiltinToken(")", tokenType :: SEPARATOR);
  }
public:
  RightBracketAdder(){
    addExternalBuiltinToken();
  }
};

class LineBreakAdder : AbstractTokenAdder{ 
private:
  void addExternalBuiltinToken(){
    builtInTokensData.addBuiltinToken("\n", tokenType :: SEPARATOR);
  }
public:
  LineBreakAdder(){
    addExternalBuiltinToken();
  }
};

class CommaAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    builtInTokensData.addBuiltinToken(",", tokenType :: SEPARATOR);
  }
public:
  CommaAdder(){
    addExternalBuiltinToken();
  }
};

class SemicolonAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    builtInTokensData.addBuiltinToken(";", tokenType :: SEPARATOR);
  }
public:
  SemicolonAdder(){
    addExternalBuiltinToken();
  }
};

class DoubleQuotationAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    builtInTokensData.addBuiltinToken("\"", tokenType :: SEPARATOR);
  }
public:
  DoubleQuotationAdder(){
    addExternalBuiltinToken();
  }
};

class SingleQuotationAdder : AbstractTokenAdder{
private: 
  void addExternalBuiltinToken(){ 
    builtInTokensData.addBuiltinToken("'", tokenType :: SEPARATOR); 
  }
public:
  SingleQuotationAdder(){
    addExternalBuiltinToken();
  }
};

class StarAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    builtInTokensData.addBuiltinToken("*", tokenType :: OPERATOR);
  }
public:
  StarAdder(){
    addExternalBuiltinToken();
  }
};

class StarEqualAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    builtInTokensData.addBuiltinToken("*=", tokenType :: OPERATOR);
  }
public:
  StarEqualAdder(){
    addExternalBuiltinToken();
  }
};

class StarStarAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    builtInTokensData.addBuiltinToken("**", tokenType :: OPERATOR);
  }
public:
  StarStarAdder(){
    addExternalBuiltinToken();
  }
};

class NormalSlashAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    builtInTokensData.addBuiltinToken("/", tokenType :: OPERATOR);
  }
public:
  NormalSlashAdder(){
    addExternalBuiltinToken();
  }
};

class EscapeSlashAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    builtInTokensData.addBuiltinToken("\\", tokenType :: OPERATOR);
  }
public:
  EscapeSlashAdder(){
    addExternalBuiltinToken();
  }
};

class BangAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    builtInTokensData.addBuiltinToken("!", tokenType :: OPERATOR);
  }
public:
  BangAdder(){
    addExternalBuiltinToken();
  }
};

class EqualAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    builtInTokensData.addBuiltinToken("=", tokenType :: OPERATOR);
  }
public:
  EqualAdder(){
    addExternalBuiltinToken();
  }
};

class IsEqualAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    builtInTokensData.addBuiltinToken("==", tokenType :: OPERATOR);
  }
public:
  IsEqualAdder(){
    addExternalBuiltinToken();
  }
};

class NotEqualAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    builtInTokensData.addBuiltinToken("!=", tokenType :: OPERATOR);
  }
public:
  NotEqualAdder(){
    addExternalBuiltinToken();
  }
};

class LeftGreaterThanRightAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    builtInTokensData.addBuiltinToken(">", tokenType :: OPERATOR);
  }
public:
  LeftGreaterThanRightAdder(){
    addExternalBuiltinToken();
  }
};

class LeftLessThanRightAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    builtInTokensData.addBuiltinToken("<", tokenType :: OPERATOR);
  }
public:
  LeftLessThanRightAdder(){
    addExternalBuiltinToken();
  }
};

class LeftGreaterThanRightOrEqualAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    builtInTokensData.addBuiltinToken(">=", tokenType :: OPERATOR);
  }
public:
  LeftGreaterThanRightOrEqualAdder(){
    addExternalBuiltinToken();
  }
};

class LeftLessThanRightOrEqualAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    builtInTokensData.addBuiltinToken("<=", tokenType :: OPERATOR);
  }
public:
  LeftLessThanRightOrEqualAdder(){
    addExternalBuiltinToken();
  }
};

class DotAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    builtInTokensData.addBuiltinToken(".", tokenType :: OPERATOR);
  }
public:
  DotAdder(){
    addExternalBuiltinToken();
  }
};

class PlusAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    builtInTokensData.addBuiltinToken("+", tokenType :: OPERATOR);
  }
public:
  PlusAdder(){
    addExternalBuiltinToken();
  }
};

class PlusPlusAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    builtInTokensData.addBuiltinToken("++", tokenType :: OPERATOR);
  }
public:
  PlusPlusAdder(){
    addExternalBuiltinToken();
  }
};

class PlusEqualAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    builtInTokensData.addBuiltinToken("+=", tokenType :: OPERATOR);
  }
public:
  PlusEqualAdder(){
    addExternalBuiltinToken();
  }
};

class MinusAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    builtInTokensData.addBuiltinToken("-", tokenType :: SEPARATOR);
  }
public:
  MinusAdder(){
    addExternalBuiltinToken();
  }
};

class MinusMinusAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    builtInTokensData.addBuiltinToken("--", tokenType :: OPERATOR);
  }
public:
  MinusMinusAdder(){
    addExternalBuiltinToken();
  }
};

class MinusEqualAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    builtInTokensData.addBuiltinToken("-=", tokenType :: OPERATOR);
  }
public:
  MinusEqualAdder(){
    addExternalBuiltinToken();
  }
};

class ScriptInlineAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    builtInTokensData.addBuiltinToken("script_inline", tokenType :: KEYWORD);
  }
public:
  ScriptInlineAdder(){
    addExternalBuiltinToken();
  }
};

class ScriptRunAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    builtInTokensData.addBuiltinToken("script_run", tokenType :: KEYWORD);
  }
public:
  ScriptRunAdder(){
    addExternalBuiltinToken();
  }
};

class NotAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    builtInTokensData.addBuiltinToken("not", tokenType :: KEYWORD);
  }
public:
  NotAdder(){
    addExternalBuiltinToken();
  }
};

class IntAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    builtInTokensData.addBuiltinToken("int", tokenType :: KEYWORD);
  }
public:
  IntAdder(){
    addExternalBuiltinToken();
  }
};

class HashAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    builtInTokensData.addBuiltinToken("#", tokenType :: OPERATOR);
  }
public:
  HashAdder(){
    addExternalBuiltinToken();
  }
};

class FloatAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    builtInTokensData.addBuiltinToken("float", tokenType :: KEYWORD);
  }
public:
  FloatAdder(){
    addExternalBuiltinToken();
  }
};

class CharAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    builtInTokensData.addBuiltinToken("char", tokenType :: KEYWORD);
  }
public:
  CharAdder(){
    addExternalBuiltinToken();
  }
};

class VoidAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    builtInTokensData.addBuiltinToken("void", tokenType :: KEYWORD);
  }
public:
  VoidAdder(){
    addExternalBuiltinToken();
  }
};

class StringAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    builtInTokensData.addBuiltinToken("string", tokenType :: KEYWORD);
  }
public:
  StringAdder(){
    addExternalBuiltinToken();
  }
};

class BoolAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    builtInTokensData.addBuiltinToken("bool", tokenType :: KEYWORD);
  }
public:
  BoolAdder(){
    addExternalBuiltinToken();
  }
};

class ContainerAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    builtInTokensData.addBuiltinToken("container", tokenType :: KEYWORD);
  }
public:
  ContainerAdder(){
    addExternalBuiltinToken();
  }
};

class AddressTypeAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    builtInTokensData.addBuiltinToken("adrs_t", tokenType :: KEYWORD);
  }
public:
  AddressTypeAdder(){
    addExternalBuiltinToken();
  }
};

class GetAddressAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    builtInTokensData.addBuiltinToken("get_adrs", tokenType :: KEYWORD);
  }
public:
  GetAddressAdder(){
    addExternalBuiltinToken();
  }
};

class LeftSquareBraceAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    builtInTokensData.addBuiltinToken("[", tokenType :: SEPARATOR);
  }
public:
  LeftSquareBraceAdder(){
    addExternalBuiltinToken();
  }
};

class RightSquareBraceAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    builtInTokensData.addBuiltinToken("]", tokenType :: SEPARATOR);
  }
public:
  RightSquareBraceAdder(){
    addExternalBuiltinToken();
  }
};

class GetValAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    builtInTokensData.addBuiltinToken("get_val", tokenType :: KEYWORD);
  }
public:
  GetValAdder(){
    addExternalBuiltinToken();
  }
};

class GetOrgAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    builtInTokensData.addBuiltinToken("get_org", tokenType :: KEYWORD);
  }
public:
  GetOrgAdder(){
    addExternalBuiltinToken();
  }
};

class SinAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    builtInTokensData.addBuiltinToken("sin", tokenType :: KEYWORD);
  }
public:
  SinAdder(){
    addExternalBuiltinToken();
  }
};

class CosAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    builtInTokensData.addBuiltinToken("cos", tokenType :: KEYWORD);
  }
public:
  CosAdder(){
    addExternalBuiltinToken();
  }
};

class TanAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    builtInTokensData.addBuiltinToken("tan", tokenType :: KEYWORD);
  }
public:
  TanAdder(){
    addExternalBuiltinToken();
  }
};

class CosecAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    builtInTokensData.addBuiltinToken("cosec", tokenType :: KEYWORD);
  }
public:
  CosecAdder(){
    addExternalBuiltinToken();
  }
};

class SecAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    builtInTokensData.addBuiltinToken("sec", tokenType :: KEYWORD);
  }
public:
  SecAdder(){
    addExternalBuiltinToken();
  }
};

class CotanAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    builtInTokensData.addBuiltinToken("cotan", tokenType :: KEYWORD);
  }
public:
  CotanAdder(){
    addExternalBuiltinToken();
  }
};

class GetSizeAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    builtInTokensData.addBuiltinToken("size", tokenType :: KEYWORD);
  }
public:
  GetSizeAdder(){
    addExternalBuiltinToken();
  }
};

class TypeOfAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    builtInTokensData.addBuiltinToken("typeof", tokenType :: KEYWORD);
  }
public:
  TypeOfAdder(){
    addExternalBuiltinToken();
  }
};

class CaretAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    builtInTokensData.addBuiltinToken("^", tokenType :: OPERATOR);
  }
public:
  CaretAdder(){
    addExternalBuiltinToken();
  }
};

class AmpersandAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    builtInTokensData.addBuiltinToken("&", tokenType :: OPERATOR);
  }
public:
  AmpersandAdder(){
    addExternalBuiltinToken();
  }
};

class PipeAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    builtInTokensData.addBuiltinToken("|", tokenType :: OPERATOR);
  }
public:
  PipeAdder(){
    addExternalBuiltinToken();
  }
};

class PIAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    builtInTokensData.addBuiltinToken("PI", tokenType :: CONSTANT);
  }
public:
  PIAdder(){
    addExternalBuiltinToken();
  }
};

class EAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    builtInTokensData.addBuiltinToken("E", tokenType :: CONSTANT);
  }
public:
  EAdder(){
    addExternalBuiltinToken();
  }
};
