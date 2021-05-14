%option noyywrap
%{
    #include "expr.h"
    #include "globals.h"
    #include "SysY.tab.hpp"
    #include <cstdio>
    #include <cstdlib>
    #include <string>
    #include <iostream>

    void yyecho() {
        fprintf(stderr, "%s", yytext);
    }
%}

letter              [a-zA-Z]
whitespace          [ \t]+
newline             \n|(\r\n)

digit               [0-9]
identifier_nondigit {letter}|_
identifier          {identifier_nondigit}+({identifier_nondigit}|{digit})*

nonzero_digit       [1-9]
decimal_integer     0|({nonzero_digit}+({nonzero_digit}|0)*)

octal_digit         [0-7]
octal_integer       0{octal_digit}+

hexadecimal_digit   [0-9a-fA-F]
hexadecimal_prefix  0x|0X
hexadecimal_integer {hexadecimal_prefix}{hexadecimal_digit}+

integer             {decimal_integer}|{octal_integer}|{hexadecimal_integer}

comment             "//".*|"/*"[^*]*"*"+([^*/][^*]*"*"+)*"/"

%%

"if"                                { yyecho(); return IF; }
"else"                              { yyecho(); return ELSE; }
"while"                             { yyecho(); return WHILE; }
"break"                             { yyecho(); return BREAK; }
"continue"                          { yyecho(); return CONTINUE; }
"return"                            { yyecho(); return RET; }

"&&"                                { yyecho(); return AND; }
"||"                                { yyecho(); return OR; }
"=="                                { yyecho(); return EQ; }
"!="                                { yyecho(); return NEQ; }
"<="                                { yyecho(); return LEQ; }
">="                                { yyecho(); return GEQ; }

{integer}                           { yyecho(); yylval = new Imm(kInt, (int)strtol(yytext, nullptr, 0)); return IMM; }

"int"                               { yyecho(); return INT; }
"const"                             { yyecho(); return CONST; }
"void"                              { yyecho(); return VOID; }

{identifier}                        { yyecho(); yylval = new Var(kInt, std::string(yytext)); return ID; }

{comment}                           {  }
{whitespace}                        { yyecho(); }
{newline}                           { yyecho(); }

[\+\-\*\/\%\=\!\<\>\(\)\[\]\{\}\,\;]    { yyecho(); return yytext[0]; }

.                                   { fprintf(stderr, "\nflex error!!: %s\n", yytext); }

%%