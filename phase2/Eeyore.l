%option prefix="zz"
%option noyywrap
%{
    #include "Eeyore.tab.hpp"
    #include <cstdio>
    #include <cstdlib>
    #include <cstring>
    
    void zzecho() {
        fprintf(stderr, "%s", zztext);
    }

    char *fork_string(const char*old_ptr) {
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

"var"                                   { zzecho(); return E_VAR; }
"param"                                 { zzecho(); return E_PARAM; }
"call"                                  { zzecho(); return E_CALL; }
"if"                                    { zzecho(); return E_IF; }
"goto"                                  { zzecho(); return E_GOTO; }
"return"                                { zzecho(); return E_RET; }
"end"                                   { zzecho(); return E_END; }

"&&"                                    { zzecho(); return E_AND; }
"||"                                    { zzecho(); return E_OR; }
"=="                                    { zzecho(); return E_EQ; }
"!="                                    { zzecho(); return E_NEQ; }
"<="                                    { zzecho(); return E_LEQ; }
">="                                    { zzecho(); return E_GEQ; }

{integer}                               { zzecho(); zzlval.str = fork_string(zztext); return E_IMM; }

{identifier}                            { zzecho(); zzlval.str = fork_string(zztext); return E_ID; }

{comment}                               {  }
{whitespace}                            { zzecho(); }
{newline}                               { zzecho(); }
[\+\-\*\/\%\=\!\<\>\(\)\[\]\{\}\,\;\:]    { zzecho(); return zztext[0]; }

.                                       { fprintf(stderr, "\nflex error!!: %s\n", zztext); }

%%
