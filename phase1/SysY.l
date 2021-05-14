%option noyywrap
%{
    #include "expr.h"
    #include "globals.h"
    #include "SysY.tab.hpp"
    #include <cstdio>
    #include <cstdlib>
    #include <string>
%}

letter              [a-zA-Z]
whitespace          [ \t]+
newline             \n

digit               [0-9]
identifier_nondigit {letter}|_
identifier          {identifier_nondigit}+({identifier_nondigit}|{digit})*

nonzero_digit       [1-9]
decimal_integer     0|{nonzero_digit}+({nonzero_digit}|0)*

octal_digit         [0-7]
octal_integer       0{octal_digit}+

hexadecimal_digit   [0-9a-fA-F]
hexadecimal_prefix  0x|0X
hexadecimal_integer {hexadecimal_prefix}{hexadecimal_digit}+

integer             {decimal_integer}|{octal_integer}|{hexadecimal_integer}

comment             "//".*|"/*"[^*]*"*"+([^*/][^*]*"*"+)*"/"

%%

"if"                                { ECHO; return IF; }
"else"                              { ECHO; return ELSE; }
"while"                             { ECHO; return WHILE; }
"break"                             { ECHO; return BREAK; }
"continue"                          { ECHO; return CONTINUE; }
"return"                            { ECHO; return RET; }

"&&"                                { ECHO; return AND; }
"||"                                { ECHO; return OR; }
"=="                                { ECHO; return EQ; }
"!="                                { ECHO; return NEQ; }
"<="                                { ECHO; return LEQ; }
">="                                { ECHO; return GEQ; }

{integer}                           { ECHO; yylval = new Imm(kInt, (int)strtol(yytext, nullptr, 0)); return IMM; }

"int"                               { ECHO; return INT; }
"const"                             { ECHO; return CONST; }
"void"                              { ECHO; return VOID; }

{identifier}                        { ECHO; yylval = new Var(kInt, std::string(yytext)); return ID; }

{comment}                           {  }
{whitespace}                        { ECHO; }
{newline}                           { ECHO; }

[\+\-\*\/\%\=\!\<\>\(\)\[\]\,\;]    { ECHO; return yytext[0]; }

%%