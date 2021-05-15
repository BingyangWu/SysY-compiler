#include "stmt.h"
#include "context.h"

Store::Store(Var lval, Expr rval) {
    StoreNode* data = new StoreNode();
    data->lval = lval;
    data->rval = rval;
    data_ = std::move(data);
}

Allocate::Allocate(Var var, Expr value=Expr(), bool with_init_value=false) {
    AllocateNode* data = new AllocateNode();
    data->var = var;
    data->value = value;
    data->with_init_value = with_init_value;
    data_ = std::move(data);
}

Evaluate::Evaluate(Expr value) {
    EvaluateNode* data = new EvaluateNode();
    data->value = value;
    data_ = std::move(data);
}

Func::Func(DataType ret_type, Var name, List<Var> params, SeqStmt body) {
    FuncNode* data = new FuncNode();
    data->ret_type = ret_type;
    data->name = name;
    data->params = params;
    data->body = body;
    data_ = std::move(data);
}

SeqStmt::SeqStmt(std::vector<Stmt> seq) {
    SeqStmtNode* data = new SeqStmtNode();
    data->seq = seq;
    data_ = std::move(data);
}

SeqStmt::SeqStmt(Stmt stmt) {
    SeqStmtNode* data = new SeqStmtNode();
    data->seq.push_back(stmt);
    data_ = std::move(data);
}

IfThenElse::IfThenElse(Expr condition, Stmt then_case, Stmt else_case, bool with_else) {
    IfThenElseNode* data = new IfThenElseNode();
    data->condition = condition;
    data->then_case = then_case;
    data->else_case = else_case;
    data->with_else = with_else;
    data_ = std::move(data);
}

While::While(Expr condition, Stmt body) {
    WhileNode* data = new WhileNode();
    data->condition = condition;
    data->body = body;
    data_ = std::move(data);
}

Goto::Goto(std::string location) {
    GotoNode* data = new GotoNode();
    data->location = location;
    data_ = std::move(data);
}

Ret::Ret(Expr ret_val, bool with_ret_val) {
    RetNode* data = new RetNode();
    data->ret_val = ret_val;
    data->with_ret_val = with_ret_val;
    data_ = std::move(data);
}

SeqStmt& AppendStmt(SeqStmt& a, SeqStmt& b) {
    a->seq.insert(a->seq.end(), b->seq.begin(), b->seq.end());
    return a;
}

std::string StoreNode::generate_eeyore(Context& context) {
    std::string text = lval->generate_eeyore(context) + rval->generate_eeyore(context);
    text += lval->address() + " = " + rval->name_key + "\n";;
    return text;
}

int prod(std::vector<int>& v, std::vector<int>& limit) {
    int bias = 0;
    for (int i = 0; i < v.size(); ++i) {
        bias = bias * limit[i] + v[i];
    }
    return bias;
}

int step_one(std::vector<int>& v, std::vector<int>& limit, int dim) {
    ++v[dim];
    for (int i = dim + 1; i < v.size(); ++i) {
        v[i] = 0;
    }

    int cnt = 0;
    for (int i = dim; i >= 0; --i) {
        v[i] += cnt;
        cnt = v[i] / limit[i];
        v[i] %= limit[i];
    }
    return cnt;
}

std::string generate_array_code(ArrayNode* var_container, ListNode<Expr>* init_list, std::vector<int>& pos, int current_dim, Context& context, int& carry_bit) {
    std::string text = "";
    std::vector<int>& dims = context.array_dims[var_container->name_key];
    std::vector<int> end_pos = pos;
    if (current_dim - 1 >= 0) step_one(end_pos, dims, current_dim-1);

    for (auto it = init_list->args.begin(); it != init_list->args.end(); ++it) {
        Expr expr = *it;
        ListNode<Expr>* nested_list = dynamic_cast<ListNode<Expr>*>(expr.operator->());
        
        if (nested_list == nullptr) {
            text += var_container->name_key + "[" + std::to_string(prod(pos, dims)*4) + "] = " + expr->name_key + "\n";
            carry_bit = step_one(pos, dims, pos.size() - 1);
        }
        else {
            text += generate_array_code(var_container, nested_list, pos, current_dim + 1, context, carry_bit);
        }
    }

    while (pos != end_pos || (carry_bit != 1 && current_dim == 0)) {
        text += var_container->name_key + "[" + std::to_string(prod(pos, dims)*4) + "] = 0\n";
        carry_bit = step_one(pos, dims, pos.size() - 1);
    }

    return text;
}

std::string AllocateNode::generate_eeyore(Context& context) {
    var->name_key = context.define_var(var, "T");
    
    std::string text = /* var->generate_eeyore(context) + */ value->generate_eeyore(context);
    
    if (with_init_value) {
        if (dynamic_cast<ArrayNode *>(var.operator->()) == nullptr) {
            text += var->name_key + " = " + value->name_key + "\n";
        } else {
            ArrayNode* var_container = dynamic_cast<ArrayNode *>(var.operator->());
            ListNode<Expr>* init_list = dynamic_cast<ListNode<Expr> *>(value.operator->());

            std::vector<int> pos;
            for (int i = 0; i < var_container->args->args.size(); ++i) {
                pos.push_back(0);
            }

            int carry_bit = 0;
            text += generate_array_code(var_container, init_list, pos, 0, context, carry_bit);
        }
    }

    return text;
}

std::string EvaluateNode::generate_eeyore(Context& context) {
    return value->generate_eeyore(context);
}

std::string FuncNode::generate_eeyore(Context& context) {
    context.symbol_table_list.push_back(SymbolTable());
    context.define_func(name, ret_type);

    int args_num = params->args.size();
    for (auto it = params->args.begin(); it != params->args.end(); ++it) {
        Var var = *it;
        var->name_key = context.define_var(var, "p");
    }

    std::string func_name = "f_" + name->name;
    std::string text = func_name + " [" + std::to_string(args_num) + "]\n";
    std::string body_text = body->generate_eeyore(context);
    text += context.variable_definition_code + body_text;
    context.variable_definition_code = "";
    text += "end " + func_name + "\n";

    context.symbol_table_list.pop_back();
    return text;
}

std::string SeqStmtNode::generate_eeyore(Context& context) {
    std::string text = "";
    context.symbol_table_list.push_back(SymbolTable());

    for (std::vector<Stmt>::iterator it = seq.begin(); it != seq.end(); ++it) {
        Stmt &stmt = *it;
        text += stmt->generate_eeyore(context);
    }

    context.variable_definition_code += context.symbol_table_list.back().generate_eeyore();

    context.symbol_table_list.pop_back();
    return text;
}

std::string IfThenElseNode::generate_eeyore(Context& context) {
    std::string text = "";
    
    // std::string label_branch = context.new_label();
    std::string label_true = context.new_label();
    std::string label_false = context.new_label();
    std::string label_next = context.new_label();

    // context.next_label.push_back(label_branch);
    
    text += condition->generate_eeyore(context);

    // context.next_label.pop_back();

    text += "if " + condition->name_key + " > 0 goto " + label_true + "\n";
    // text += label_branch + ":\n";
    text += "goto " + label_false + "\n";

    // context.next_label.push_back(label_next);
    
    text += label_true + ":\n";
    text += then_case->generate_eeyore(context);
    if (with_else)
        text += "goto " + label_next + "\n";

    text += label_false + ":\n";
    if (with_else) {
        text += else_case->generate_eeyore(context);
        text += label_next + ":\n";
    }
    // context.next_label.pop_back();

    return text;
}

std::string WhileNode::generate_eeyore(Context& context) {
    std::string text = "";
    std::string label_while_begin = context.new_label();
    std::string label_next = context.new_label();
    std::string label_condition_begin = context.new_label();

    text += "goto " + label_condition_begin + "\n";
    text += label_while_begin + ":\n";

    context.next_label.push_back(label_next);
    context.begin_label.push_back(label_condition_begin);

    text += body->generate_eeyore(context);

    context.next_label.pop_back();
    context.begin_label.pop_back();

    text += label_condition_begin + ":\n";

    // context.next_label.push_back(label_next);
    text += condition->generate_eeyore(context);
    // context.next_label.pop_back();

    text += "if " + condition->name_key + " > 0 goto " + label_while_begin + "\n";

    text += label_next + ":\n";

    return text;
}

std::string GotoNode::generate_eeyore(Context& context) {
    std::string text = "";

    if (location == "next")
        text += "goto " + context.next_label.back() + "\n";
    else if (location == "begin")
        text += "goto " + context.begin_label.back() + "\n";
    
    return text;
}

std::string RetNode::generate_eeyore(Context& context) {
    std::string text = "";
    if (!with_ret_val)
        text += "return\n";
    else {
        text += ret_val->generate_eeyore(context);
        text += "return " + ret_val->name_key + "\n";
    }
    return text;
}