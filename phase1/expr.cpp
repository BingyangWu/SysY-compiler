#include "expr.h"
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
    data_ = std::move(data);
}

Var::Var(DataType dtype, std::string name) {
    VarNode* data = new VarNode();
    data->dtype = dtype;
    data->name = name;
    data_ = std::move(data);
}

Array::Array(Var id, List<Expr> args, bool unknown_dim=false) {
    ArrayNode* data = new ArrayNode();
    data->dtype = id.get()->dtype;
    data->name = id.get()->name;
    if (unknown_dim)
        args = AppendList(List<Expr>(Imm(kInt, 0)), args);
    data->args = args;
    data_ = std::move(data);
}

template<typename T>
List<T>::List(std::vector<T> args) {
    ListNode* data = new ListNode();
    data->args = args;
    data_ = std::move(data);
}

template<typename T>
List<T>::List(T arg) {
    ListNode* data = new ListNode();
    data->args.push_back(arg);
    data_ = std::move(data);
}

template<typename T>
List<T> AppendList(List<T> a, List<T> b) {
    a->args.insert(a->args.end(), b->args.begin(), b->args.end());
    return a;
}

List<Expr> EmptyList() {
    List<Expr> a(Imm(kInt, -1));
    a->args.pop_back();
    return a;
}