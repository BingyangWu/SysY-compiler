#include "phase1/globals.h"
#include "phase1/SysY.tab.hpp"
#include "phase1/context.h"
#include "phase2/Eeyore.tab.hpp"
#include "phase2/Eeyore.hpp"
#include "phase3/Tigger.tab.hpp"
#include "phase3/Tigger.hpp"
#include <iostream>

typedef struct zz_buffer_state * ZZ_BUFFER_STATE;
extern ZZ_BUFFER_STATE zz_scan_string(const char * str);
// extern void zz_delete_buffer(ZZ_BUFFER_STATE buffer);

typedef struct rr_buffer_state * RR_BUFFER_STATE;
extern RR_BUFFER_STATE rr_scan_string(const char * str);

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
    text = context.variable_definition_code + text;

    ZZ_BUFFER_STATE buffer = zz_scan_string(text.c_str());    
    zzparse();
    // zz_delete_buffer(buffer);

    eeyore_statements.insert(eeyore_statements.begin() + eeyore_functions["f_main"].start_pos, 
        eeyore_initializations.begin(), eeyore_initializations.end());
    
    std::string tigger_code = "";
    
    for (auto it = eeyore_statements.begin(); it != eeyore_statements.end(); ++it) {
        std::string code_segment = (*it)->emit_tigger(enviroment);
        tigger_code += code_segment;
    }

    RR_BUFFER_STATE rrbuffer = rr_scan_string(tigger_code.c_str());    
    rrparse();

    return 0;
}