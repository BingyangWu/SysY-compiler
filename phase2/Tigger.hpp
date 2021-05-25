#ifndef _TIGGER_HPP_
#define _TIGGER_HPP_

#include <iostream>
#include <vector>
#include <map>

class TiggerStatement {
public:
};

class TiggerDeclaration {
public:
};

extern std::vector<TiggerStatement *> tigger_statements;
extern std::vector<TiggerDeclaration *> tigger_declarations;
extern std::map<std::string, std::pair<int, int>> eeyore_functions;

#endif