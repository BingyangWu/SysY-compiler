#include "expr.h"
#include "type.h"
#include "context.h"
#include "globals.h"
#include <assert.h>

Imm::Imm(DataType dtype, int value) {
    assert(dtype.is_int());
    ImmNode* data = new ImmNode();
    data->dtype = dtype;
    data->value = value;
    data_ = std::move(data);
}

BinaryOp::BinaryOp(Expr a, BinaryOpType dtype, Expr b) {
    BinaryOpNode* data = new BinaryOpNode();
    data->a = a;
    data->dtype = dtype;
    data->b = b;
    data_ = std::move(data);
}

Not::Not(Expr a) {
    NotNode* data = new NotNode();
    data->a = a;
    data_ = std::move(data);
}

Call::Call(Var func, List<Expr> args) {
    CallNode* data = new CallNode();
    data->func = func;
    data->args = args;

    if (func->name == "starttime") {
        data->func = Var(kVoid, "_sysy_starttime");
        data->args = List<Expr>(Imm(kInt, lineno));
    }

    if (func->name == "stoptime") {
        data->func = Var(kVoid, "_sysy_stoptime");
        data->args = List<Expr>(Imm(kInt, lineno));
    }

    data_ = std::move(data);
}

Var::Var(DataType dtype, std::string name) {
    VarNode* data = new VarNode();
    data->dtype = dtype;
    data->name = name;
    data_ = std::move(data);
}

Array::Array(Var id, List<Expr> args, bool unknown_dim) {
    ArrayNode* data = new ArrayNode();
    data->dtype = id.get()->dtype;
    data->name = id.get()->name;
    if (unknown_dim)
        args = AppendList(*new List<Expr>(Imm(kInt, 0)), args);
    data->args = args;
    data_ = std::move(data);
}

int BinaryOpNode::get_value(Context& context) {
    switch (dtype.code()) {
        case kAdd: return a->get_value(context) + b->get_value(context);
        case kSub: return a->get_value(context) - b->get_value(context);
        case kMul: return a->get_value(context) * b->get_value(context);
        case kDiv: return a->get_value(context) / b->get_value(context);
        case kMod: return a->get_value(context) % b->get_value(context);
        case kEQ: return a->get_value(context) == b->get_value(context);
        case kNEQ: return a->get_value(context) != b->get_value(context);
        case kLT: return a->get_value(context) < b->get_value(context);
        case kGT: return a->get_value(context) > b->get_value(context);
        case kLEQ: return a->get_value(context) <= b->get_value(context);
        case kGEQ: return a->get_value(context) >= b->get_value(context);
        case kAnd: return a->get_value(context) && b->get_value(context);
        case kOr: return a->get_value(context) || b->get_value(context);
    }
    return -1;
}

int NotNode::get_value(Context& context) {
    if (a->get_value(context) > 0)
        return 0;
    else return 1;
}

int VarNode::get_value(Context& context) {
    return std::stoi(context.find_var(name));
}

std::string ImmNode::generate_eeyore(Context& context) {
    name_key = std::to_string(value);
    return "";
}

std::string BinaryOpNode::generate_eeyore(Context& context) {
    std::string text = "";
    std::string label_true, label_next;
    name_key = context.define_var(Var(kInt, std::string(dtype)), "t");

    switch (dtype.code()) {
        case kAnd:
            label_true = context.new_label();
            label_next = context.new_label();

            text += a->generate_eeyore(context);
            text += "if " + a->name_key + " > 0 goto " + label_true + "\n";
            text += name_key + " = 0\n";
            text += "goto " + label_next + "\n";
            text += label_true + ":\n";
            text += b->generate_eeyore(context);
            text += name_key + " = " + b->name_key + "\n";
            text += label_next + ":\n";
            break;

        case kOr:
            label_true = context.new_label();
            label_next = context.new_label();

            text += a->generate_eeyore(context);
            text += "if " + a->name_key + " > 0 goto " + label_true + "\n";
            text += b->generate_eeyore(context);
            text += name_key + " = " + b->name_key + "\n";
            text += "goto " + label_next + "\n";
            text += label_true + ":\n";
            text += name_key + " = 1\n";
            text += label_next + ":\n";
            break;

        default:
            text += a->generate_eeyore(context) + b->generate_eeyore(context);
            text += name_key + " = " + a->name_key + " " + std::string(dtype) + " " + b->name_key + "\n";
            break;
    }

    return text;
}

std::string NotNode::generate_eeyore(Context& context) {
    std::string text = "";
    name_key = context.define_var(Var(kInt, "!"), "t");

    text += a->generate_eeyore(context);
    text += name_key + " = !" + a->name_key + "\n";

    return text;
}

std::string CallNode::generate_eeyore(Context& context) {
    std::string text = "";

    text += args->generate_eeyore(context);

    for (auto it = args->args.begin(); it != args->args.end(); ++it) {
        text += "param " + (*it)->name_key + "\n";
    }

    if (context.has_ret_value(func->name)) {
        name_key = context.define_var(Var(kInt, "call"+func->name), "t");
        text += name_key + " = ";
    }
    else {
        name_key = "";
    }
    text += "call f_" + func->name + "\n";
    
    return text;
}

std::string VarNode::generate_eeyore(Context& context) {
    name_key = context.find_var(name);
    return "";
}

std::string ArrayNode::generate_eeyore(Context& context) {
    base_var = context.find_var(name);
    std::vector<int>& dims = context.array_dims[base_var];
    std::string text = "";
    std::string last_var;
    
    int i;
    for (i = 0; i < args->args.size(); ++i) {
        text += args->args[i]->generate_eeyore(context);

        if (i > 0) {
            offset_var = context.define_var(Var(kInt, "array_"+name+"_"+std::to_string(i)), "t");
            std::string temp_var = context.define_var(Var(kInt, "temp_array_"+name+"_"+std::to_string(i)), "t");
            text += temp_var + " = " + last_var + " * " + std::to_string(dims[i]) + "\n";
            text += offset_var + " = " + temp_var + " + " + args->args[i]->name_key + "\n";
            last_var = offset_var;
        }
        else last_var = args->args[i]->name_key;
    }

    bool get_value = (i == dims.size());
    int width = 4;
    for (; i < dims.size(); ++i)
        width *= dims[i];

    offset_var = context.define_var(Var(kInt, "array_"+name+"_offset_var"), "t");
    text += offset_var + " = " + last_var + " * " + std::to_string(width) + "\n";
    name_key = context.define_var(Var(kInt, "array_rvalue_"+name), "t");

    if (get_value)
        text += name_key + " = " + base_var + "[" + offset_var + "]\n";
    else
        text += name_key + " = " + base_var + " + " + offset_var + "\n";
    return text;
}