#include "globals.h"
#include "SysY.tab.hpp"
#include "context.h"
#include <iostream>

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
    std::cout << context.variable_definition_code << text;
    return 0;
}