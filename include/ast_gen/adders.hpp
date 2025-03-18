#include "grammar.hpp"
#include "weak_t_parser.hpp"


class AbstractGrammarAdder{
  virtual void addGrammar(){};
};



class ForGrammarAdder{
private:
  void addGrammar(){
    std::shared_ptr<ForGrammarChecker> instance = std::make_shared<ForGrammarChecker>();
    rulesContainerSingeltonObject.addRule("for", instance);
  }
public:
  ForGrammarAdder(){
    addGrammar();
  }
};

class WhileGrammarAdder{
private:
  void addGrammar(){
    std::shared_ptr<WhileGrammarChecker> instance = std::make_shared<WhileGrammarChecker>();
    rulesContainerSingeltonObject.addRule("while", instance);
  }
public:
  WhileGrammarAdder(){
    addGrammar();
  }
};

class IfGrammarAdder{
private:
  void addGrammar(){
    std::shared_ptr<IfGrammarChecker> instance = std::make_shared<IfGrammarChecker>();
    rulesContainerSingeltonObject.addRule("if", instance);
  }
public:
  IfGrammarAdder(){
    addGrammar();
  }
};


class ElseIfGrammarAdder{
private:
  void addGrammar(){
    std::shared_ptr<ElseIfGrammarChecker> instance = std::make_shared<ElseIfGrammarChecker>();
    rulesContainerSingeltonObject.addRule("else if", instance);
  }
public:
  ElseIfGrammarAdder(){
    addGrammar();
  }
};

class ElseGrammarAdder{
private:
  void addGrammar(){
    std::shared_ptr<ElseGrammarChecker> instance = std::make_shared<ElseGrammarChecker>();
    rulesContainerSingeltonObject.addRule("else", instance);
  }
public:
  ElseGrammarAdder(){
    addGrammar();
  }
};

class FunctionGrammarAdder{
private:
  void addGrammar(){
    std::shared_ptr<FunctionGrammarChecker> instance = std::make_shared<FunctionGrammarChecker>();
    rulesContainerSingeltonObject.addRule("funct", instance);
  }
public:
  FunctionGrammarAdder(){
    addGrammar();
  }
};

/*
class VariableDeclarationGrammarAdder{
private:
  void addGrammar(){
    std::shared_ptr<VariableDeclarationChecker> instance = std::make_shared<VariableDeclarationChecker>();
    rulesContainerSingeltonObject.addRule("create", instance);
  }
public:
  VariableDeclarationGrammarAdder() {
    addGrammar();
  }
};
*/

class SwitchGrammarAdder{
private:
  void addGrammar(){
    std::shared_ptr<SwitchGrammarChecker> instance = std::make_shared<SwitchGrammarChecker>();
    rulesContainerSingeltonObject.addRule("switch", instance); 
  }
public:
  SwitchGrammarAdder(){
    addGrammar();
  }
};

class CaseGrammarAdder{
private:
  void addGrammar(){
    std::shared_ptr<CaseGrammarChecker> instance = std::make_shared<CaseGrammarChecker>();
    rulesContainerSingeltonObject.addRule("case", instance); 
  }
public:
  CaseGrammarAdder(){
    addGrammar();
  }
};

class VariableMutationGrammarAdder{
private:
  void addGrammar(){
    std::shared_ptr<VariableMutationChecker> instance = std::make_shared<VariableMutationChecker>();
    rulesContainerSingeltonObject.addRule("<<<MUTABLE>>>", instance); 
    // IT'S IMPOSSIBLE THE TOKENIZER TO FORM A TOKEN OF THIS STRING,
    // AND THEREFORE, IT IS USED FOR CASES THAT DO NOT START WITH A KEYWORD
  }
public:
  VariableMutationGrammarAdder(){
    addGrammar();
  }
};

class PrintGrammarAdder{
private:
  void addGrammar(){
    std::shared_ptr<PrintGrammarChecker> instance = std::make_shared<PrintGrammarChecker>();
    rulesContainerSingeltonObject.addRule("print", instance); 
  }
public:
  PrintGrammarAdder(){
    addGrammar();
  }
};
