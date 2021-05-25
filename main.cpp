#include "phase1/globals.h"
#include "phase1/SysY.tab.hpp"
#include "phase1/context.h"
#include "phase2/Eeyore.tab.hpp"
#include <iostream>

typedef struct zz_buffer_state * ZZ_BUFFER_STATE;
extern ZZ_BUFFER_STATE zz_scan_string(const char * str);
// extern void zz_delete_buffer(ZZ_BUFFER_STATE buffer);

int main(int argc, char* argv[]) {
    freopen(argv[3], "r", stdin);
    freopen(argv[5], "w", stdout);
    yyparse();

    Context context;
    context.define_func(Var(kInt, "getint"), kInt);
    context.define_func(Var(kInt, "getch"), kInt);
    context.define_func(Var(kInt, "getarray"), kInt);
    context.define_func(Var(kInt, "putch"), kVoid);
    context.define_func(Var(kInt, "putarray"), kVoid);

    std::string text = (*TreeRoot)->generate_eeyore(context);
    text += context.variable_definition_code;

    ZZ_BUFFER_STATE buffer = zz_scan_string(text.c_str());    
    zzparse();
    // zz_delete_buffer(buffer);
    return 0;
}