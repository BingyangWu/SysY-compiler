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

TiggerProgram           :TiggerProgram TiggerGlobalVarDecl  {  }
                        |TiggerProgram TiggerFunctionDef    {  }
                        |                                   {  }
;
TiggerGlobalVarDecl     :T_ID '=' T_IMM                     { emit_global_variable_declaration($1, $3); }
                        |T_ID '=' T_MALLOC T_IMM            { emit_global_array_declaration($1, $4); }
;
TiggerFunctionDef       :TiggerFunctionHeader TiggerExpressions TiggerFunctionEnd {  }
;
TiggerFunctionHeader    :T_ID '[' T_IMM ']' '[' T_IMM ']'   { emit_function_header($1, $3, $6); }
;
TiggerExpressions       :TiggerExpressions TiggerExpression {  }
                        |                                   {  }
;
TiggerFunctionEnd       :T_END T_ID                         { emit_function_end($2); }
;
TiggerExpression        :T_ID '=' T_ID TiggerOp T_ID        { emit_reg_binary_operation_reg($1, $3, $4, $5); }
                        |T_ID '=' T_ID TiggerOp T_IMM       { emit_reg_binary_operation_imm($1, $3, $4, $5); }
                        |T_ID '=' '!' T_ID                  { emit_reg_not_reg($1, $4); }
                        |T_ID '=' T_ID                      { emit_assignment($1, $3); }
                        |T_ID '=' T_IMM                     { emit_assignment_imm($1, $3); }
                        |T_ID '[' T_IMM ']' '=' T_ID        { emit_array_assignment_reg($1, $3, $6); }
                        |T_ID '=' T_ID '[' T_IMM ']'        { emit_reg_assignment_array($1, $3, $5); }
                        |T_IF T_ID TiggerOp T_ID T_GOTO T_ID
                                                            { emit_conditional_goto($2, $3, $4, $6); }
                        |T_GOTO T_ID                        { emit_goto($2); }
                        |T_ID ':'                           { emit_label($1); }
                        |T_CALL T_ID                        { emit_call($2); }
                        |T_RET                              { emit_return(); }
                        |T_STORE T_ID T_IMM                 { emit_store($2, $3); }
                        |T_LOAD T_IMM T_ID                  { emit_load_stack($2, $3); }
                        |T_LOAD T_ID T_ID                   { emit_load_variable($2, $3); }
                        |T_LOADADDR T_IMM T_ID              { emit_loadaddr_stack($2, $3); }
                        |T_LOADADDR T_ID T_ID               { emit_loadaddr_variable($2, $3); }
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