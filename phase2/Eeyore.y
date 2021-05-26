%define api.prefix {zz}
%{
    #include "Eeyore.hpp"

    int zzerror(const char *);
    extern int zzlex(void);
%}
%define api.value.type {char *}

%token E_VAR E_PARAM E_CALL E_IF E_GOTO E_RET E_END

%token E_AND E_OR E_EQ E_NEQ E_LEQ E_GEQ

%token E_IMM E_ID

%%

Code            :Code Declaration                       {  }
                |Code Initialization                    {  }
                |Code FunctionDef                       {  }
                |                                       { eeyore_statements.clear(); eeyore_initializations.clear(); eeyore_functions.clear(); }
;
Declaration     :E_VAR E_ID                             { enviroment.declare($2, 0); }
                |E_VAR E_IMM E_ID                       { enviroment.declare($3, std::stoi($2)); }
;
Initialization  :E_ID '=' RightValue                    { eeyore_initializations.push_back(new Assignment($1, "", $3, "", "")); }
                |E_ID '[' E_IMM ']' '=' RightValue      { eeyore_initializations.push_back(new Assignment($1, $3, $6, "", "")); }
;
FunctionDef     :FunctionHeader Statements FunctionEnd  {  }
;
FunctionHeader  :E_ID '[' E_IMM ']'                     { eeyore_statements.push_back(new FunctionHeader($1, $3)); enviroment.enter_function($1, $3, eeyore_statements.size()); }
;
Statements      :Statements Statement                   {  }
                |                                       {  }
;
FunctionEnd     :E_END E_ID                             { eeyore_statements.push_back(new FunctionEnd($2)); enviroment.exit_function($2, eeyore_statements.size()); }
;
Statement       :Expression                             {  }
                |Declaration                            {  }
;
Expression      :E_ID '=' RightValue BinOp RightValue   { eeyore_statements.push_back(new Assignment($1, "", $3, $4, $5)); }
                |E_ID '=' '!' RightValue                { eeyore_statements.push_back(new Assignment($1, "", $4, "!", "")); }
                |E_ID '=' RightValue                    { eeyore_statements.push_back(new Assignment($1, "", $3, "", "")); }
                |E_ID '[' RightValue ']' '=' RightValue { eeyore_statements.push_back(new Assignment($1, $3, $6, "", "")); }
                |E_ID '=' E_ID '[' RightValue ']'       { eeyore_statements.push_back(new Assignment($1, "", $3, "[]", $5)); }
                |E_IF RightValue BinOp RightValue E_GOTO E_ID
                                                        { eeyore_statements.push_back(new IfGoto($6, $2, $3, $4)); }
                |E_GOTO E_ID                            { eeyore_statements.push_back(new IfGoto($2, "", "", "")); }
                |E_ID ':'                               { eeyore_statements.push_back(new Label($1)); }
                |E_PARAM RightValue                     { eeyore_statements.push_back(new PassParameter($2)); }
                |E_CALL E_ID                            { eeyore_statements.push_back(new CallFunction("", $2)); }
                |E_ID '=' E_CALL E_ID                   { eeyore_statements.push_back(new CallFunction($1, $4)); }
                |E_RET RightValue                       { eeyore_statements.push_back(new Return($2)); }
                |E_RET                                  { eeyore_statements.push_back(new Return("")); }
;
RightValue      :E_ID                                   { $$ = $1; }
                |E_IMM                                  { $$ = $1; }
;
BinOp           :E_AND                                  { $$ = $1; }
                |E_OR                                   { $$ = $1; }
                |E_EQ                                   { $$ = $1; }
                |E_NEQ                                  { $$ = $1; }
                |E_LEQ                                  { $$ = $1; }
                |E_GEQ                                  { $$ = $1; }
                |'>'                                    { $$ = $1; }
                |'<'                                    { $$ = $1; }
                |'+'                                    { $$ = $1; }
                |'-'                                    { $$ = $1; }
                |'*'                                    { $$ = $1; }
                |'/'                                    { $$ = $1; }
                |'%'                                    { $$ = $1; }
;
%%
int zzerror(const char *message) {
	return 0;
}