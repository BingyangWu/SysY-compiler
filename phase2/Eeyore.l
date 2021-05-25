%option prefix="zz"
%option noyywrap
%{
    #include "Eeyore.tab.hpp"
    #include <cstdio>
    
    void zzecho() {
        fprintf(stderr, "%s", zztext);
    }
%}

%%

.   { zzecho(); }

%%
