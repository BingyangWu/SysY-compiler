#ifndef _EXPR_H_
#define _EXPR_H_

#include "object.h"
#include "type.h"
#include <vector>

class ExprNode: public Object {
public:
    DataType dtype;
    std::string name_key;
    virtual int get_value();
};

class Expr: public ObjectRef {
public:
    DEFINE_OBJECT_REF_METHODS(Expr, ObjectRef, ExprNode);
};

class ImmNode: public ExprNode {
public:
    int value;
    virtual int get_value() {
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
    virtual int get_value();
};

class BinaryOp: public Expr {
public:
    BinaryOp(Expr a, BinaryOpType dtype, Expr b);
    DEFINE_OBJECT_REF_METHODS(BinaryOp, Expr, BinaryOpNode);
};

class NotNode: public ExprNode {
public:
    Expr a;
};

class Not: public Expr {
public:
    Not(Expr a);
    DEFINE_OBJECT_REF_METHODS(Not, Expr, NotNode);
};

class CallNode: public ExprNode {
public:
    Var func;
    List<Expr> args;
};

class Call: public Expr {
public:
    Call(Var func, List<Expr> args);
    DEFINE_OBJECT_REF_METHODS(Call, Expr, CallNode);
};

class VarNode: public ExprNode {
public:
    std::string name;
};

class Var: public Expr {
public:
    Var(DataType dtype, std::string name);
    DEFINE_OBJECT_REF_METHODS(Var, Expr, VarNode);
};

class ArrayNode: public VarNode {
public:
    List<Expr> args;
    std::vector<int> dims;
};

class Array: public Var {
public:
    Array(Var id, List<Expr> args, bool unknown_dim=false);
    DEFINE_OBJECT_REF_METHODS(Array, Var, ArrayNode);
};

template<typename T>
class ListNode: public ExprNode {
public:
    std::vector<T> args;
};

template<typename T>
class List: public Expr {
public:
    List(std::vector<T> args);
    List(T arg);
    DEFINE_OBJECT_REF_METHODS(List<T>, Expr, ListNode<T>);
};

template<typename T>
List<T> AppendList(List<T> a, List<T> b);

#endif // _EXPR_H_