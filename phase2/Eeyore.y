%define api.prefix {zz}
%{
    int zzerror(const char *);
    extern int zzlex(void);
%}
%define api.value.type {
    union ZZ_DATA {
        int i;
        char* str;
    }
}

%token E_VAR E_PARAM E_CALL E_IF E_GOTO E_RET E_END

%token E_AND E_OR E_EQ E_NEQ E_LEQ E_GEQ

%token E_IMM E_ID

%%

Code :  {}

%%
int zzerror(const char *message) {
	return 0;
}