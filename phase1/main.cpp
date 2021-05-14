#include "globals.h"
#include "SysY.tab.hpp"
#include "context.h"
#include <iostream>

int main(int argc, char* argv[]) {
    freopen(argv[3], "r", stdin);
    freopen(argv[5], "w", stdout);
    yyparse();

    Context context;
    std::string text = (*TreeRoot)->generate_eeyore(context);
    std::cout << text;
    return 0;
}