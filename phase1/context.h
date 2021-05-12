#ifndef _CONTEXT_H_
#define _CONTEXT_H_

#include <map>
#include <vector>
#include "expr.h"

class SymbolTableEntry {
public:
    std::string var_type, var_no;
    int width;
};

class SymbolTable {
public:
    std::map<std::string, SymbolTableEntry> symbol_table;

    std::string generate_eeyore() {
        std::string text = "";

        for (std::map<std::string, SymbolTableEntry>::iterator it = symbol_table.begin(); it != symbol_table.end(); ++it) {
            SymbolTableEntry& entry = it->second;
            std::string var_name = it->first;
            std::string define_var = "var " + entry.var_type + entry.var_type + " // " + var_name + "\n";
            text += define_var;
        }

        return text;
    }
};

class Context {
public:
    std::vector<SymbolTable> symbole_table_list;
    std::map<std::string, int> type_counter;
    int label_counter;

    std::vector<std::string> next_label;
    std::vector<std::string> begin_label;

    Context(): label_counter(0) {
        type_counter["T"] = 0;
        type_counter["t"] = 0;
        type_counter["p"] = 0;
    }

    void define_var(Var var, std::string var_type);
    std::string new_label() {
        return "l" + std::to_string(label_counter++);
    }
};

#endif