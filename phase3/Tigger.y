%define api.prefix {rr}
%{
    #include "Tigger.hpp"

    int rrerror(const char *);
    extern int rrlex(void);
%}
%define api.value.type {char *}

%token T_CALL T_IF T_GOTO T_RET T_END

%token T_AND T_OR T_EQ T_NEQ T_LEQ T_GEQ

%token T_IMM T_ID

%token T_LOAD T_LOADADDR T_STORE T_MALLOC

%%

TiggerProgram           :TiggerProgram TiggerGlobalVarDecl  {}
                        |TiggerProgram TiggerFunctionDef    {}
                        |                                   {}
;
TiggerGlobalVarDecl     :T_ID '=' T_IMM                     {}
                        |T_ID '=' T_MALLOC T_IMM            {}
;
TiggerFunctionDef       :TiggerFunctionHeader TiggerExpressions TiggerFunctionEnd {}
;
TiggerFunctionHeader    :T_ID '[' T_IMM ']' '[' T_IMM ']'   {}
;
TiggerExpressions       :TiggerExpressions TiggerExpression {}
                        |                                   {}
;
TiggerFunctionEnd       :T_END T_ID                         {}
;
TiggerExpression        :T_ID '=' T_ID TiggerOp T_ID        {}
                        |T_ID '=' T_ID TiggerOp T_IMM       {}
                        |T_ID '=' TiggerOp T_ID             {}
                        |T_ID '=' T_ID                      {}
                        |T_ID '=' T_IMM                     {}
                        |T_ID '[' T_IMM ']' '=' T_ID        {}
                        |T_ID '=' T_ID '[' T_IMM ']'        {}
                        |T_IF T_ID TiggerOp T_ID T_GOTO T_ID
                                                            {}
                        |T_GOTO T_ID                        {}
                        |T_ID ':'                           {}
                        |T_CALL T_ID                        {}
                        |T_RET                              {}
                        |T_STORE T_ID T_IMM                 {}
                        |T_LOAD T_IMM T_ID                  {}
                        |T_LOAD T_ID T_ID                   {}
                        |T_LOADADDR T_IMM T_ID              {}
                        |T_LOADADDR T_ID T_ID               {}
;
TiggerOp                :T_AND                              { $$ = $1; }
                        |T_OR                               { $$ = $1; }
                        |T_EQ                               { $$ = $1; }
                        |T_NEQ                              { $$ = $1; }
                        |T_LEQ                              { $$ = $1; }
                        |T_GEQ                              { $$ = $1; }
                        |'>'                                { $$ = $1; }
                        |'<'                                { $$ = $1; }
                        |'+'                                { $$ = $1; }
                        |'-'                                { $$ = $1; }
                        |'*'                                { $$ = $1; }
                        |'/'                                { $$ = $1; }
                        |'%'                                { $$ = $1; }
;
%%
int rrerror(const char *message) {
	return 0;
}