#include "context.h"

void Context::define_var(Var var, std::string var_type) {
    SymbolTableEntry entry;
    entry.var_type = var_type;
    entry.var_no = type_counter[var_type]++;
    
    ArrayNode *data = dynamic_cast<ArrayNode*>(var.operator->());
    if (data != nullptr) {
        entry.width = 4;
        for (auto it = data->args->args.begin(); it != data->args->args.end(); ++it) {
            Expr expr = *it;
            int dim = expr->get_value();
            data->dims.push_back(dim);
            entry.width *= dim;
        }
    } else {
        entry.width = 0;
    }

    symbole_table_list.back().symbol_table[var->name] = entry;

    var->name_key = entry.var_type + entry.var_no;
}