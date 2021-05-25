%define api.prefix {zz}
%{
    int zzerror(const char *);
    extern int zzlex(void);
%}

%%

Code    :   {}

%%
int zzerror(const char *message) {
	return 0;
}