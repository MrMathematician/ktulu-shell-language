#include <bits/stdc++.h>
#include "../../include/lexer/adders.hpp"


// USED TO SPECIFY INTERPRETATION MODE (WEAKLY TYPED OR STRONGLY TYPED)
HashAdder hashAddObject = HashAdder();
// GENERAL OPERATORS FOR BOTH WEAKLY TYPED AND STRONGLY TYPED

// FLOW CONTROL
IfAdder ifAddObject = IfAdder();
ElseAdder elseAddObject = ElseAdder(); // else
ElseIfAdder elseAddIfAddObject = ElseIfAdder(); // else if
WhileAdder  whileAddObject = WhileAdder(); // while
ForAdder forAddObject = ForAdder(); // for
SwitchAdder switchAddObject = SwitchAdder(); // switch
CaseAdder caseAddObject = CaseAdder(); // case
ContinueAdder continueAddObject = ContinueAdder();
BreakAdder breakAddObject = BreakAdder();

// PRINT TO CONSOLE AND TAKE INPUT
PrintAdder printAddObject = PrintAdder(); // print
InputAdder inputAddObject = InputAdder();


// FUNCTION RETURN
ReturnAdder returnAddObject = ReturnAdder(); // return


// COMMAND MODE
CommandAdder commandAddObject = CommandAdder(); // cmd


// SEPARATORS
LeftBraceAdder leftBraceAddObject = LeftBraceAdder(); // {
RightBraceAdder rightBraceAddObject = RightBraceAdder(); // }
LeftBracketAdder leftBracketAddObject = LeftBracketAdder(); // (
RightBracketAdder rightBracketAddObject = RightBracketAdder(); // )
SemicolonAdder semicolonAddObject = SemicolonAdder(); // ;
CommaAdder commaAddObject = CommaAdder(); // ,
SingleQuotationAdder singleQuotationAddObject = SingleQuotationAdder(); // '
DoubleQuotationAdder doubleQuotationAddObject = DoubleQuotationAdder(); // " // WAS COMMENTED DUE TO STRINGING
EscapeSlashAdder escapeSlashAddObject = EscapeSlashAdder(); // espace slash
NormalSlashAdder normalSlashAddObject = NormalSlashAdder(); // /
LeftSquareBraceAdder leftSquareBraceAddObject = LeftSquareBraceAdder(); // [
RightSquareBraceAdder rightSquareBraceAddObject = RightSquareBraceAdder(); // ]

// ASSIGNMENT OPERATOR
EqualAdder equalAddObject = EqualAdder(); // =


// FLOAT AND FUNCTION CALLING
DotAdder dotAddObject = DotAdder(); // .


// MATH OPERATORS
PlusAdder plusAddObject = PlusAdder(); // +
MinusAdder minusAddObject = MinusAdder(); // -
PlusPlusAdder plusPlusAddObject = PlusPlusAdder(); // ++
MinusMinusAdder minusMinusAddObject = MinusMinusAdder(); // --
MinusEqualAdder minusEqualAddObject = MinusEqualAdder(); // -=
StarAdder starAddObject = StarAdder();
StarStarAdder starStarAddObject = StarStarAdder(); // **
StarEqualAdder starEqualAddObject = StarEqualAdder();
PlusEqualAdder plusEqualAddObject = PlusEqualAdder() ; // +=
PercentageAdder percentageAddObject = PercentageAdder(); // %

// BOOLEAN OPERATORS AND KEYWORDS
NotAdder notAddObject = NotAdder(); // not
TrueAdder trueAddObject = TrueAdder(); // true
AndAdder andAddObject = AndAdder(); // and
OrAdder orAddObject = OrAdder(); // or
FalseAdder falseAddObject = FalseAdder(); // false


// COMPARATIVE OPERATORS
IsEqualAdder isEqualAddObject = IsEqualAdder(); // ==
NotEqualAdder notEqualDoubleaddObject = NotEqualAdder(); // !=
LeftLessThanRightOrEqualAdder LeftLessThanRightOrEqualAddObject = LeftLessThanRightOrEqualAdder(); // <=
LeftGreaterThanRightOrEqualAdder LeftGreaterThanRightOrEqualAddObject = LeftGreaterThanRightOrEqualAdder(); // >=
BangAdder bangAddObject = BangAdder(); // !
LeftLessThanRightAdder leftLessThanRightAddObject = LeftLessThanRightAdder(); // <
LeftGreaterThanRightAdder leftGreaterThanRightAddObject = LeftGreaterThanRightAdder(); // >


// INSIDE THE CMD
ScriptInlineAdder scriptInlineAddObject = ScriptInlineAdder(); // script_inline
ScriptRunAdder scriptRunAddObject = ScriptRunAdder(); // script_run


// FOR WEAKLY TYPED
//CreateAdder varAddObject = CreateAdder(); // var 
FunctionAdder functionAddObject = FunctionAdder(); // funct 

// FOR STORNGLY TYPED
// FOR VARIABLE TYPES
IntAdder intAddObject = IntAdder();
FloatAdder floatAddObject = FloatAdder();
CharAdder charAddObject = CharAdder();
StringAdder stringAddObject = StringAdder();
BoolAdder boolAddObject = BoolAdder();

// FOR VOID FUNCTIONS 
VoidAdder voidAddObject = VoidAdder();

// STRUCTS
ContainerAdder containerAddObject = ContainerAdder();

// PASING BY VALUE AND REFERENCE
AddressTypeAdder addressTypeAddObject = AddressTypeAdder();
GetAddressAdder getAddressAddObject = GetAddressAdder();
GetValAdder getValAddObject = GetValAdder();
GetOrgAdder getOrgAddObject = GetOrgAdder();

// TRIG FUNCTIONS (THIS IS AVAILABLE FOR BOTH STRONGLY TYPED MODE AND WEAKLY TYPED MODE)
SinAdder sinAddObject = SinAdder();
CosAdder cosAddObject = CosAdder();
TanAdder tanAddObject = TanAdder();

CosecAdder cosecAddObject = CosecAdder();
SecAdder secAddObject = SecAdder();
CotanAdder cotanAddObject = CotanAdder();











