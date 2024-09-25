#include "lexer.hpp"



class AbstractTokenAdder{
public:
  void addExternalBuiltinToken();
};



class IfAdder : AbstractTokenAdder{
private: 
  void addExternalBuiltinToken(){
    std::shared_ptr<TokenKeywordBuilder> keywordBuilderObject = std::make_shared<TokenKeywordBuilder>();
    builtInTokensData.addBuiltinToken("if", keywordBuilderObject);
  }
public:
  IfAdder(){
    addExternalBuiltinToken();
  }
};

class ElseAdder : AbstractTokenAdder{
private: 
  void addExternalBuiltinToken(){
    std::shared_ptr<TokenKeywordBuilder> keywordBuilderObject = std::make_shared<TokenKeywordBuilder>();
    builtInTokensData.addBuiltinToken("else", keywordBuilderObject);
  }
public:
  ElseAdder(){
    addExternalBuiltinToken();
  }
};

class ElseIfAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    std::shared_ptr<TokenKeywordBuilder> keywordBuilderObject = std::make_shared<TokenKeywordBuilder>();
    builtInTokensData.addBuiltinToken("else if", keywordBuilderObject);
  }
public:
  ElseIfAdder(){
    addExternalBuiltinToken();
  }
}; 

class AndAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    std::shared_ptr<TokenKeywordBuilder> keywordBuilderObject = std::make_shared<TokenKeywordBuilder>();
    builtInTokensData.addBuiltinToken("and", keywordBuilderObject);
  } 
public:
  AndAdder(){
    addExternalBuiltinToken();
  }
};

class OrAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    std::shared_ptr<TokenKeywordBuilder> keywordBuilderObject = std::make_shared<TokenKeywordBuilder>();
    builtInTokensData.addBuiltinToken("or", keywordBuilderObject);
  }
public:
  OrAdder(){
    addExternalBuiltinToken();
  }
};

class VarAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    std::shared_ptr<TokenKeywordBuilder> keywordBuilderObject = std::make_shared<TokenKeywordBuilder>();
    builtInTokensData.addBuiltinToken("var", keywordBuilderObject);
  }
public:
  VarAdder(){
    addExternalBuiltinToken();
  }
};

class FalseAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    std::shared_ptr<TokenKeywordBuilder> keywordBuilderObject = std::make_shared<TokenKeywordBuilder>();
    builtInTokensData.addBuiltinToken("false", keywordBuilderObject);
  }
public:
  FalseAdder(){
    addExternalBuiltinToken();
  }
};

class TrueAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    std::shared_ptr<TokenKeywordBuilder> keywordBuilderObject = std::make_shared<TokenKeywordBuilder>();
    builtInTokensData.addBuiltinToken("true", keywordBuilderObject);
  }
public:
  TrueAdder(){
    addExternalBuiltinToken();
  }
};

class PrintAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    std::shared_ptr<TokenKeywordBuilder> keywordBuilderObject = std::make_shared<TokenKeywordBuilder>();
    builtInTokensData.addBuiltinToken("print", keywordBuilderObject);
  }
public:
  PrintAdder(){
    addExternalBuiltinToken();
  }
};

class ReturnAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    std::shared_ptr<TokenKeywordBuilder> keywordBuilderObject = std::make_shared<TokenKeywordBuilder>();
    builtInTokensData.addBuiltinToken("return", keywordBuilderObject);
  }
public:
  ReturnAdder(){
    addExternalBuiltinToken();
  }
};

class FunctionAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    std::shared_ptr<TokenKeywordBuilder> keywordBuilderObject = std::make_shared<TokenKeywordBuilder>();
    builtInTokensData.addBuiltinToken("funct", keywordBuilderObject);
  }
public:
  FunctionAdder(){
    addExternalBuiltinToken();
  }
};

class SwitchAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    std::shared_ptr<TokenKeywordBuilder> keywordBuilderObject = std::make_shared<TokenKeywordBuilder>();
    builtInTokensData.addBuiltinToken("switch", keywordBuilderObject);
  }
public:
  SwitchAdder(){
    addExternalBuiltinToken();
  }
};

class WhileAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    std::shared_ptr<TokenKeywordBuilder> keywordBuilderObject = std::make_shared<TokenKeywordBuilder>();
    builtInTokensData.addBuiltinToken("while", keywordBuilderObject);
  }
public:
  WhileAdder(){
    addExternalBuiltinToken();
  }
};

class ForAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    std::shared_ptr<TokenKeywordBuilder> keywordBuilderObject = std::make_shared<TokenKeywordBuilder>();
    builtInTokensData.addBuiltinToken("for", keywordBuilderObject);
  }
public:
  ForAdder(){
    addExternalBuiltinToken();
  }
};

class CaseAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    std::shared_ptr<TokenKeywordBuilder> keywordBuilderObject = std::make_shared<TokenKeywordBuilder>();
    builtInTokensData.addBuiltinToken("case", keywordBuilderObject);
  }
public:
  CaseAdder(){
    addExternalBuiltinToken();
  }
};

class CommandAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    std::shared_ptr<TokenKeywordBuilder> keywordBuilderObject = std::make_shared<TokenKeywordBuilder>();
    builtInTokensData.addBuiltinToken("cmd", keywordBuilderObject);
  }
public:
  CommandAdder(){
    addExternalBuiltinToken();
  }
};

class LeftBraceAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    std::shared_ptr<TokenSeparatorBuilder> separatorBuilderObject = std::make_shared<TokenSeparatorBuilder>();
    builtInTokensData.addBuiltinToken("{", separatorBuilderObject);
  }
public:
  LeftBraceAdder(){
    addExternalBuiltinToken();
  }
};

class RightBraceAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    std::shared_ptr<TokenSeparatorBuilder> separatorBuilderObject = std::make_shared<TokenSeparatorBuilder>();
    builtInTokensData.addBuiltinToken("}", separatorBuilderObject);
  }
public:
  RightBraceAdder(){
    addExternalBuiltinToken();
  }
};

class LeftBracketAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    std::shared_ptr<TokenSeparatorBuilder> separatorBuilderObject = std::make_shared<TokenSeparatorBuilder>();
    builtInTokensData.addBuiltinToken("(", separatorBuilderObject);
  }
public:
  LeftBracketAdder(){
    addExternalBuiltinToken();
  }
};

class RightBracketAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    std::shared_ptr<TokenSeparatorBuilder> separatorBuilderObject = std::make_shared<TokenSeparatorBuilder>();
    builtInTokensData.addBuiltinToken(")", separatorBuilderObject);
  }
public:
  RightBracketAdder(){
    addExternalBuiltinToken();
  }
};

class LineBreakAdder : AbstractTokenAdder{ 
private:
  void addExternalBuiltinToken(){
    std::shared_ptr<TokenSeparatorBuilder> separatorBuilderObject = std::make_shared<TokenSeparatorBuilder>();
    builtInTokensData.addBuiltinToken("\n", separatorBuilderObject);
  }
public:
  LineBreakAdder(){
    addExternalBuiltinToken();
  }
};

class CommaAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    std::shared_ptr<TokenSeparatorBuilder> separatorBuilderObject = std::make_shared<TokenSeparatorBuilder>();
    builtInTokensData.addBuiltinToken(",", separatorBuilderObject);
  }
public:
  CommaAdder(){
    addExternalBuiltinToken();
  }
};

class SemicolonAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    std::shared_ptr<TokenSeparatorBuilder> separatorBuilderObject = std::make_shared<TokenSeparatorBuilder>();
    builtInTokensData.addBuiltinToken(";", separatorBuilderObject);
  }
public:
  SemicolonAdder(){
    addExternalBuiltinToken();
  }
};

class DoubleQuotationAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    std::shared_ptr<TokenSeparatorBuilder> separatorBuilderObject = std::make_shared<TokenSeparatorBuilder>();
    builtInTokensData.addBuiltinToken("\"", separatorBuilderObject);
  }
public:
  DoubleQuotationAdder(){
    addExternalBuiltinToken();
  }
};

class SingleQuotationAdder : AbstractTokenAdder{
private: 
  void addExternalBuiltinToken(){ 
    std::shared_ptr<TokenSeparatorBuilder> separatorBuilderObject = std::make_shared<TokenSeparatorBuilder>();
    builtInTokensData.addBuiltinToken("'", separatorBuilderObject); 
  }
public:
  SingleQuotationAdder(){
    addExternalBuiltinToken();
  }
};

class StarAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    std::shared_ptr<TokenOperatorBuilder> operatorBuilderObject = std::make_shared<TokenOperatorBuilder>();
    builtInTokensData.addBuiltinToken("*", operatorBuilderObject);
  }
public:
  StarAdder(){
    addExternalBuiltinToken();
  }
};

class StarEqualAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    std::shared_ptr<TokenOperatorBuilder> operatorBuilderObject = std::make_shared<TokenOperatorBuilder>();
    builtInTokensData.addBuiltinToken("*=", operatorBuilderObject);
  }
public:
  StarEqualAdder(){
    addExternalBuiltinToken();
  }
};

class StarStarAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    std::shared_ptr<TokenOperatorBuilder> operatorBuilderObject = std::make_shared<TokenOperatorBuilder>();
    builtInTokensData.addBuiltinToken("**", operatorBuilderObject);
  }
public:
  StarStarAdder(){
    addExternalBuiltinToken();
  }
};

class NormalSlashAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    std::shared_ptr<TokenOperatorBuilder> operatorBuilderObject = std::make_shared<TokenOperatorBuilder>();
    builtInTokensData.addBuiltinToken("/", operatorBuilderObject);
  }
public:
  NormalSlashAdder(){
    addExternalBuiltinToken();
  }
};

class EscapeSlashAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    std::shared_ptr<TokenOperatorBuilder> operatorBuilderObject = std::make_shared<TokenOperatorBuilder>();
    builtInTokensData.addBuiltinToken("\\", operatorBuilderObject);
  }
public:
  EscapeSlashAdder(){
    addExternalBuiltinToken();
  }
};

class BangAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    std::shared_ptr<TokenOperatorBuilder> operatorBuilderObject = std::make_shared<TokenOperatorBuilder>();
    builtInTokensData.addBuiltinToken("!", operatorBuilderObject);
  }
public:
  BangAdder(){
    addExternalBuiltinToken();
  }
};

class EqualAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    std::shared_ptr<TokenOperatorBuilder> operatorBuilderObject = std::make_shared<TokenOperatorBuilder>();
    builtInTokensData.addBuiltinToken("=", operatorBuilderObject);
  }
public:
  EqualAdder(){
    addExternalBuiltinToken();
  }
};

class IsEqualAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    std::shared_ptr<TokenOperatorBuilder> operatorBuilderObject = std::make_shared<TokenOperatorBuilder>();
    builtInTokensData.addBuiltinToken("==", operatorBuilderObject);
  }
public:
  IsEqualAdder(){
    addExternalBuiltinToken();
  }
};

class NotEqualAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    std::shared_ptr<TokenOperatorBuilder> operatorBuilderObject = std::make_shared<TokenOperatorBuilder>();
    builtInTokensData.addBuiltinToken("!=", operatorBuilderObject);
  }
public:
  NotEqualAdder(){
    addExternalBuiltinToken();
  }
};

class LeftGreaterThanRightAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    std::shared_ptr<TokenOperatorBuilder> operatorBuilderObject = std::make_shared<TokenOperatorBuilder>();
    builtInTokensData.addBuiltinToken(">", operatorBuilderObject);
  }
public:
  LeftGreaterThanRightAdder(){
    addExternalBuiltinToken();
  }
};

class LeftLessThanRightAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    std::shared_ptr<TokenOperatorBuilder> operatorBuilderObject = std::make_shared<TokenOperatorBuilder>();
    builtInTokensData.addBuiltinToken("<", operatorBuilderObject);
  }
public:
  LeftLessThanRightAdder(){
    addExternalBuiltinToken();
  }
};

class LeftGreaterThanRightOrEqualAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    std::shared_ptr<TokenOperatorBuilder> operatorBuilderObject = std::make_shared<TokenOperatorBuilder>();
    builtInTokensData.addBuiltinToken(">=", operatorBuilderObject);
  }
public:
  LeftGreaterThanRightOrEqualAdder(){
    addExternalBuiltinToken();
  }
};

class LeftLessThanRightOrEqualAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    std::shared_ptr<TokenOperatorBuilder> operatorBuilderObject = std::make_shared<TokenOperatorBuilder>();
    builtInTokensData.addBuiltinToken("<=", operatorBuilderObject);
  }
public:
  LeftLessThanRightOrEqualAdder(){
    addExternalBuiltinToken();
  }
};

class DotAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    std::shared_ptr<TokenOperatorBuilder> operatorBuilderObject = std::make_shared<TokenOperatorBuilder>();
    builtInTokensData.addBuiltinToken(".", operatorBuilderObject);
  }
public:
  DotAdder(){
    addExternalBuiltinToken();
  }
};

class PlusAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    std::shared_ptr<TokenOperatorBuilder> operatorBuilderObject = std::make_shared<TokenOperatorBuilder>();
    builtInTokensData.addBuiltinToken("+", operatorBuilderObject);
  }
public:
  PlusAdder(){
    addExternalBuiltinToken();
  }
};

class PlusPlusAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    std::shared_ptr<TokenOperatorBuilder> operatorBuilderObject = std::make_shared<TokenOperatorBuilder>();
    builtInTokensData.addBuiltinToken("++", operatorBuilderObject);
  }
public:
  PlusPlusAdder(){
    addExternalBuiltinToken();
  }
};

class PlusEqualAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    std::shared_ptr<TokenOperatorBuilder> operatorBuilderObject = std::make_shared<TokenOperatorBuilder>();
    builtInTokensData.addBuiltinToken("+=", operatorBuilderObject);
  }
public:
  PlusEqualAdder(){
    addExternalBuiltinToken();
  }
};

class MinusAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    std::shared_ptr<TokenOperatorBuilder> operatorBuilderObject = std::make_shared<TokenOperatorBuilder>();
    builtInTokensData.addBuiltinToken("-", operatorBuilderObject);
  }
public:
  MinusAdder(){
    addExternalBuiltinToken();
  }
};

class MinusMinusAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    std::shared_ptr<TokenOperatorBuilder> operatorBuilderObject = std::make_shared<TokenOperatorBuilder>();
    builtInTokensData.addBuiltinToken("--", operatorBuilderObject);
  }
public:
  MinusMinusAdder(){
    addExternalBuiltinToken();
  }
};

class MinusEqualAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    std::shared_ptr<TokenOperatorBuilder> operatorBuilderObject = std::make_shared<TokenOperatorBuilder>();
    builtInTokensData.addBuiltinToken("-=", operatorBuilderObject);
  }
public:
  MinusEqualAdder(){
    addExternalBuiltinToken();
  }
};

class ScriptInlineAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    std::shared_ptr<TokenKeywordBuilder> keywordBuilderObject = std::make_shared<TokenKeywordBuilder>();
    builtInTokensData.addBuiltinToken("script_inline", keywordBuilderObject);
  }
public:
  ScriptInlineAdder(){
    addExternalBuiltinToken();
  }
};

class ScriptRunAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    std::shared_ptr<TokenKeywordBuilder> keywordBuilderObject = std::make_shared<TokenKeywordBuilder>();
    builtInTokensData.addBuiltinToken("script_run", keywordBuilderObject);
  }
public:
  ScriptRunAdder(){
    addExternalBuiltinToken();
  }
};

class NotAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    std::shared_ptr<TokenKeywordBuilder> keywordBuilderObject = std::make_shared<TokenKeywordBuilder>();
    builtInTokensData.addBuiltinToken("not", keywordBuilderObject);
  }
public:
  NotAdder(){
    addExternalBuiltinToken();
  }
};

class IntAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    std::shared_ptr<TokenKeywordBuilder> keywordBuilderObject = std::make_shared<TokenKeywordBuilder>();
    builtInTokensData.addBuiltinToken("int", keywordBuilderObject);
  }
public:
  IntAdder(){
    addExternalBuiltinToken();
  }
};

class HashAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    std::shared_ptr<TokenKeywordBuilder> keywordBuilderObject = std::make_shared<TokenKeywordBuilder>();
    builtInTokensData.addBuiltinToken("#", keywordBuilderObject);
  }
public:
  HashAdder(){
    addExternalBuiltinToken();
  }
};

class FloatAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    std::shared_ptr<TokenKeywordBuilder> keywordBuilderObject = std::make_shared<TokenKeywordBuilder>();
    builtInTokensData.addBuiltinToken("float", keywordBuilderObject);
  }
public:
  FloatAdder(){
    addExternalBuiltinToken();
  }
};

class CharAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    std::shared_ptr<TokenKeywordBuilder> keywordBuilderObject = std::make_shared<TokenKeywordBuilder>();
    builtInTokensData.addBuiltinToken("char", keywordBuilderObject);
  }
public:
  CharAdder(){
    addExternalBuiltinToken();
  }
};

class VoidAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    std::shared_ptr<TokenKeywordBuilder> keywordBuilderObject = std::make_shared<TokenKeywordBuilder>();
    builtInTokensData.addBuiltinToken("void", keywordBuilderObject);
  }
public:
  VoidAdder(){
    addExternalBuiltinToken();
  }
};

class StringAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    std::shared_ptr<TokenKeywordBuilder> keywordBuilderObject = std::make_shared<TokenKeywordBuilder>();
    builtInTokensData.addBuiltinToken("string", keywordBuilderObject);
  }
public:
  StringAdder(){
    addExternalBuiltinToken();
  }
};

class BoolAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    std::shared_ptr<TokenKeywordBuilder> keywordBuilderObject = std::make_shared<TokenKeywordBuilder>();
    builtInTokensData.addBuiltinToken("bool", keywordBuilderObject);
  }
public:
  BoolAdder(){
    addExternalBuiltinToken();
  }
};

class ContainerAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    std::shared_ptr<TokenKeywordBuilder> keywordBuilderObject = std::make_shared<TokenKeywordBuilder>();
    builtInTokensData.addBuiltinToken("container", keywordBuilderObject);
  }
public:
  ContainerAdder(){
    addExternalBuiltinToken();
  }
};

class AddressTypeAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    std::shared_ptr<TokenKeywordBuilder> keywordBuilderObject = std::make_shared<TokenKeywordBuilder>();
    builtInTokensData.addBuiltinToken("adrs_t", keywordBuilderObject);
  }
public:
  AddressTypeAdder(){
    addExternalBuiltinToken();
  }
};

class GetAddressAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    std::shared_ptr<TokenKeywordBuilder> keywordBuilderObject = std::make_shared<TokenKeywordBuilder>();
    builtInTokensData.addBuiltinToken("get_adrs", keywordBuilderObject);
  }
public:
  GetAddressAdder(){
    addExternalBuiltinToken();
  }
};

class LeftSquareBraceAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    std::shared_ptr<TokenSeparatorBuilder> separatorBuilderObject = std::make_shared<TokenSeparatorBuilder>();
    builtInTokensData.addBuiltinToken("[", separatorBuilderObject);
  }
public:
  LeftSquareBraceAdder(){
    addExternalBuiltinToken();
  }
};

class RightSquareBraceAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    std::shared_ptr<TokenSeparatorBuilder> separatorBuilderObject = std::make_shared<TokenSeparatorBuilder>();
    builtInTokensData.addBuiltinToken("]", separatorBuilderObject);
  }
public:
  RightSquareBraceAdder(){
    addExternalBuiltinToken();
  }
};

class GetValAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    std::shared_ptr<TokenKeywordBuilder> keywordBuilderObject = std::make_shared<TokenKeywordBuilder>();
    builtInTokensData.addBuiltinToken("get_val", keywordBuilderObject);
  }
public:
  GetValAdder(){
    addExternalBuiltinToken();
  }
};

class GetOrgAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    std::shared_ptr<TokenKeywordBuilder> keywordBuilderObject = std::make_shared<TokenKeywordBuilder>();
    builtInTokensData.addBuiltinToken("get_org", keywordBuilderObject);
  }
public:
  GetOrgAdder(){
    addExternalBuiltinToken();
  }
};

class SinAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    std::shared_ptr<TokenKeywordBuilder> keywordBuilderObject = std::make_shared<TokenKeywordBuilder>();
    builtInTokensData.addBuiltinToken("sin", keywordBuilderObject);
  }
public:
  SinAdder(){
    addExternalBuiltinToken();
  }
};

class CosAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    std::shared_ptr<TokenKeywordBuilder> keywordBuilderObject = std::make_shared<TokenKeywordBuilder>();
    builtInTokensData.addBuiltinToken("cos", keywordBuilderObject);
  }
public:
  CosAdder(){
    addExternalBuiltinToken();
  }
};

class TanAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    std::shared_ptr<TokenKeywordBuilder> keywordBuilderObject = std::make_shared<TokenKeywordBuilder>();
    builtInTokensData.addBuiltinToken("tan", keywordBuilderObject);
  }
public:
  TanAdder(){
    addExternalBuiltinToken();
  }
};

class CosecAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    std::shared_ptr<TokenKeywordBuilder> keywordBuilderObject = std::make_shared<TokenKeywordBuilder>();
    builtInTokensData.addBuiltinToken("cosec", keywordBuilderObject);
  }
public:
  CosecAdder(){
    addExternalBuiltinToken();
  }
};

class SecAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    std::shared_ptr<TokenKeywordBuilder> keywordBuilderObject = std::make_shared<TokenKeywordBuilder>();
    builtInTokensData.addBuiltinToken("sec", keywordBuilderObject);
  }
public:
  SecAdder(){
    addExternalBuiltinToken();
  }
};

class CotanAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    std::shared_ptr<TokenKeywordBuilder> keywordBuilderObject = std::make_shared<TokenKeywordBuilder>();
    builtInTokensData.addBuiltinToken("cotan", keywordBuilderObject);
  }
public:
  CotanAdder(){
    addExternalBuiltinToken();
  }
};

class GetSizeAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    std::shared_ptr<TokenKeywordBuilder> keywordBuilderObject = std::make_shared<TokenKeywordBuilder>();
    builtInTokensData.addBuiltinToken("size", keywordBuilderObject);
  }
public:
  GetSizeAdder(){
    addExternalBuiltinToken();
  }
};

class TypeOfAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    std::shared_ptr<TokenKeywordBuilder> keywordBuilderObject = std::make_shared<TokenKeywordBuilder>();
    builtInTokensData.addBuiltinToken("typeof", keywordBuilderObject);
  }
public:
  TypeOfAdder(){
    addExternalBuiltinToken();
  }
};

class CaretAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    std::shared_ptr<TokenOperatorBuilder> operatorBuilderObject = std::make_shared<TokenOperatorBuilder>();
    builtInTokensData.addBuiltinToken("^", operatorBuilderObject);
  }
public:
  CaretAdder(){
    addExternalBuiltinToken();
  }
};

class AmpersandAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    std::shared_ptr<TokenOperatorBuilder> operatorBuilderObject = std::make_shared<TokenOperatorBuilder>();
    builtInTokensData.addBuiltinToken("&", operatorBuilderObject);
  }
public:
  AmpersandAdder(){
    addExternalBuiltinToken();
  }
};

class PipeAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    std::shared_ptr<TokenOperatorBuilder> operatorBuilderObject = std::make_shared<TokenOperatorBuilder>();
    builtInTokensData.addBuiltinToken("|", operatorBuilderObject);
  }
public:
  PipeAdder(){
    addExternalBuiltinToken();
  }
};

class PIAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    std::shared_ptr<TokenConstantBuilder> constantBuilderObject = std::make_shared<TokenConstantBuilder>();
    builtInTokensData.addBuiltinToken("PI", constantBuilderObject);
  }
public:
  PIAdder(){
    addExternalBuiltinToken();
  }
};

class EAdder : AbstractTokenAdder{
private:
  void addExternalBuiltinToken(){
    std::shared_ptr<TokenConstantBuilder> constantBuilderObject = std::make_shared<TokenConstantBuilder>();
    builtInTokensData.addBuiltinToken("E", constantBuilderObject);
  }
public:
  EAdder(){
    addExternalBuiltinToken();
  }
};
