#ifndef _EXPR_H_
#define _EXPR_H_

#include "object.h"
#include "type.h"
#include <vector>

class ExprNode: public Object {
public:
    DataType dtype;
    std::string name_key;
    virtual int get_value(Context& context) { return -1; }
};

class Expr: public ObjectRef {
public:
    DEFINE_OBJECT_REF_METHODS(Expr, ObjectRef, ExprNode);
};

class ImmNode: public ExprNode {
public:
    int value;
    virtual std::string generate_eeyore(Context&);
    virtual int get_value(Context& context) {
        return value;
    }
};

class Imm: public Expr {
public:
    Imm(DataType dtype, int value);
    DEFINE_OBJECT_REF_METHODS(Imm, Expr, ImmNode);
};

class BinaryOpNode: public ExprNode {
public:
    BinaryOpType dtype;
    Expr a, b;
    virtual std::string generate_eeyore(Context&);
    virtual int get_value(Context& context);
};

class BinaryOp: public Expr {
public:
    BinaryOp(Expr a, BinaryOpType dtype, Expr b);
    DEFINE_OBJECT_REF_METHODS(BinaryOp, Expr, BinaryOpNode);
};

class NotNode: public ExprNode {
public:
    Expr a;
    virtual std::string generate_eeyore(Context&);
    virtual int get_value(Context& context);
};

class Not: public Expr {
public:
    Not(Expr a);
    DEFINE_OBJECT_REF_METHODS(Not, Expr, NotNode);
};

class VarNode: public ExprNode {
public:
    std::string name;
    virtual std::string generate_eeyore(Context&);
    virtual std::string address() { return name_key; }
    virtual int get_value(Context& context);
};

class Var: public Expr {
public:
    Var(DataType dtype, std::string name);
    DEFINE_OBJECT_REF_METHODS(Var, Expr, VarNode);
};

template<typename T>
class ListNode: public ExprNode {
public:
    std::vector<T> args;
    virtual std::string generate_eeyore(Context&);
};

template<typename T>
class List: public Expr {
public:
    List(std::vector<T> args);
    List(T arg);
    DEFINE_OBJECT_REF_METHODS(List<T>, Expr, ListNode<T>);
};

class CallNode: public ExprNode {
public:
    Var func;
    List<Expr> args;
    virtual std::string generate_eeyore(Context&);
};

class Call: public Expr {
public:
    Call(Var func, List<Expr> args);
    DEFINE_OBJECT_REF_METHODS(Call, Expr, CallNode);
};

class ArrayNode: public VarNode {
public:
    List<Expr> args;
    std::string base_var, offset_var;
    virtual std::string generate_eeyore(Context&);
    virtual std::string address() { return base_var + "[" + offset_var + "]"; }
};

class Array: public Var {
public:
    Array(Var id, List<Expr> args, bool unknown_dim=false);
    DEFINE_OBJECT_REF_METHODS(Array, Var, ArrayNode);
};

template<typename T>
List<T>& AppendList(List<T>& a, List<T>& b) {
    a->args.insert(a->args.end(), b->args.begin(), b->args.end());
    return a;
}

template<typename T>
List<T>* EmptyList() {
    List<T>* a = new List<T>(T());
    (*a)->args.pop_back();
    return a;
}

template<typename T>
List<T>::List(std::vector<T> args) {
    ListNode<T>* data = new ListNode<T>();
    data->args = args;
    data_ = std::move(data);
}

template<typename T>
List<T>::List(T arg) {
    ListNode<T>* data = new ListNode<T>();
    data->args.push_back(arg);
    data_ = std::move(data);
}

template<typename T>
std::string ListNode<T>::generate_eeyore(Context& context) {
    std::string text = "";

    for (auto it = args.begin(); it != args.end(); ++it) {
        T expr = *it;
        text += expr->generate_eeyore(context);
        name_key = expr->name_key;
    }

    return text;
}

#endif // _EXPR_H_