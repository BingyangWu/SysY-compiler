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
    std::vector<SymbolTable> symbol_table_list;
    std::map<std::string, int> type_counter;
    std::map<std::string, std::vector<int>> array_dims;
    int label_counter;

    std::map<std::string, bool> func_table;

    std::vector<std::string> next_label;
    std::vector<std::string> begin_label;

    Context(): label_counter(0) {
        type_counter["T"] = 0;
        type_counter["t"] = 0;
        type_counter["p"] = 0;
    }

    std::string define_var(Var var, std::string var_type);
    std::string find_var(std::string var_name);
    void define_func(Var var, DataType ret_type);
    bool has_ret_value(std::string func_name);
    std::string new_label();
};

#endif