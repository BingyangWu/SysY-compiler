%option prefix="rr"
%option noyywrap
%{
    #include "Tigger.tab.hpp"
    #include <cstdio>
    #include <cstdlib>
    #include <cstring>
    
    void rrecho() {
        fprintf(stderr, "%s", rrtext);
    }

    char *rr_fork_string(const char*old_ptr) {
        char *ptr = new char [sizeof(old_ptr)/sizeof(char)];
        strcpy(ptr, old_ptr);
        return ptr;
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

"malloc"                                { rrecho(); return T_MALLOC; }
"call"                                  { rrecho(); return T_CALL; }
"if"                                    { rrecho(); return T_IF; }
"goto"                                  { rrecho(); return T_GOTO; }
"return"                                { rrecho(); return T_RET; }
"end"                                   { rrecho(); return T_END; }
"load"                                  { rrecho(); return T_LOAD; }
"loadaddr"                              { rrecho(); return T_LOADADDR; }
"store"                                 { rrecho(); return T_STORE; }

"&&"                                    { rrecho(); rrlval = rr_fork_string(rrtext); return T_AND; }
"||"                                    { rrecho(); rrlval = rr_fork_string(rrtext); return T_OR; }
"=="                                    { rrecho(); rrlval = rr_fork_string(rrtext); return T_EQ; }
"!="                                    { rrecho(); rrlval = rr_fork_string(rrtext); return T_NEQ; }
"<="                                    { rrecho(); rrlval = rr_fork_string(rrtext); return T_LEQ; }
">="                                    { rrecho(); rrlval = rr_fork_string(rrtext); return T_GEQ; }

{integer}                               { rrecho(); rrlval = rr_fork_string(rrtext); return T_IMM; }

{identifier}                            { rrecho(); rrlval = rr_fork_string(rrtext); return T_ID; }

{comment}                               {  }
{whitespace}                            { rrecho(); }
{newline}                               { rrecho(); }
[\+\-\*\/\%\=\!\<\>\(\)\[\]\{\}\,\;\:]  { rrecho(); rrlval = rr_fork_string(rrtext); return rrtext[0]; }

.                                       { fprintf(stderr, "\nflex error!!: %s\n", rrtext); }

%%
