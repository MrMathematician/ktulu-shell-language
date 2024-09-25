#pragma once
#include "weak_t_parser.hpp"

class WeakTParser;


class GrammarChecker{
protected:
  virtual void checkGrammar(WeakTParser* parser) {}

  friend WeakTParser;
};





class ForGrammerChecker : public GrammarChecker{
  void checkGrammar(WeakTParser* parser) override{

  }
};

class WhileGrammarChecker : public GrammarChecker{
  void checkGrammar(WeakTParser* parser) override{

  }
};

class IfGrammarChecker : public GrammarChecker{
  void checkGrammar(WeakTParser* parser) override{

  }
};

class FunctionGrammarChecker : public GrammarChecker{
  void checkGrammar(WeakTParser* parser) override{

  }
};


