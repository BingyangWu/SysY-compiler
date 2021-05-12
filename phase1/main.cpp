#include "globals.h"
#include "SysY.tab.hpp"
#include "context.h"
#include <iostream>

int main() {
    yyparse();

    Context context;
    std::string text = TreeRoot->generate_eeyore(context);
    std::cout << text;
    return 0;
}