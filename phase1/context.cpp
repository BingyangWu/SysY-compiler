#include "context.h"

std::string Context::define_var(Var var, std::string var_type) {
    SymbolTableEntry entry;
    std::vector<int> dims;
    entry.var_type = var_type;
    entry.var_no = std::to_string(type_counter[var_type]++);
    
    ArrayNode *data = dynamic_cast<ArrayNode*>(var.operator->());
    if (data != nullptr) {
        entry.width = 4;
        for (auto it = data->args->args.begin(); it != data->args->args.end(); ++it) {
            Expr expr = *it;
            int dim = expr->get_value();
            dims.push_back(dim);
            entry.width *= dim;
        }
    } else {
        entry.width = 0;
    }

    if (var_type == "t")
        var->name += "_" + entry.var_no;
    symbol_table_list.back().symbol_table[var->name] = entry;

    var->name_key = entry.var_type + entry.var_no;
    array_dims[var->name_key] = dims;

    return var->name_key;
}

std::string Context::find_var(std::string var_name) {
    for (auto it = symbol_table_list.rbegin(); it != symbol_table_list.rend(); ++it) {
        if (it->symbol_table.find(var_name) != it->symbol_table.end())
            return it->symbol_table[var_name].var_type + it->symbol_table[var_name].var_no;
    }
    return "error!";
}

void Context::define_func(Var var, DataType ret_type) {
    func_table[var->name] = (ret_type.code() == kVoid ? false : true);
}

bool Context::has_ret_value(std::string func_name) {
    return func_table[func_name];
}

std::string Context::new_label() {
    return "l" + std::to_string(label_counter++);
}