%define api.prefix {zz}
%{
    int zzerror(const char *);
    extern int zzlex(void);
%}
%define api.value.type {
    union ZZ_DATA {
        char* str;
    }
}

%token E_VAR E_PARAM E_CALL E_IF E_GOTO E_RET E_END

%token E_AND E_OR E_EQ E_NEQ E_LEQ E_GEQ

%token E_IMM E_ID

%%

Eeyore          :Code                                   {}
;
Code            :Code Declaration                       {}
                |Declaration                            {}
                |Code Initialization                    {}
                |Initialization                         {}
                |Code FunctionDef                       {}
                |FunctionDef                            {}
;
Declaration     :E_VAR E_ID                             {}
                |E_VAR E_IMM E_ID                       {}
;
Initialization  :E_ID '=' E_IMM                         {}
                |E_ID '=' E_ID                          {}
                |E_ID '[' E_IMM ']' '=' E_IMM           {}
                |E_ID '[' E_IMM ']' '=' E_ID            {}
;
FunctionDef     :FunctionHeader Statements FunctionEnd  {}
;
FunctionHeader  :E_ID '[' E_IMM ']'                     {}
;
Statements      :Statements Statement                   {}
                |Statement                              {}
;
FunctionEnd     :E_END E_ID                             {}
;
Statement       :Expression                             {}
                |Declaration                            {}
;
Expression      :E_ID '=' RightValue BinOp RightValue   {}
                |E_ID '=' '!' RightValue                {}
                |E_ID '=' RightValue                    {}
                |E_ID '[' RightValue ']' '=' RightValue {}
                |E_ID '=' E_ID '[' RightValue ']'       {}
                |E_IF RightValue BinOp RightValue E_GOTO E_ID
                                                        {}
                |E_GOTO E_ID                            {}
                |E_ID ':'                               {}
                |E_PARAM RightValue                     {}
                |E_CALL E_ID                            {}
                |E_ID '=' E_CALL E_ID                   {}
                |E_RET RightValue                       {}
                |E_RET                                  {}
;
RightValue      :E_ID                                   {}
                |E_IMM                                  {}
;
BinOp           :E_AND                                  {}
                |E_OR                                   {}
                |E_EQ                                   {}
                |E_NEQ                                  {}
                |E_LEQ                                  {}
                |E_GEQ                                  {}
                |'>'                                    {}
                |'<'                                    {}
                |'+'                                    {}
                |'-'                                    {}
                |'*'                                    {}
                |'/'                                    {}
                |'%'                                    {}
;
%%
int zzerror(const char *message) {
	return 0;
}