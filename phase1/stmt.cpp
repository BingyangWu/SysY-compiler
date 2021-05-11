#include "stmt.h"

Store::Store(Var lval, Expr rval) {
    StoreNode* data = new StoreNode();
    data->lval = lval;
    data->rval = rval;
    data_ = std::move(data);
}

Allocate::Allocate(Var var, Expr value) {
    AllocateNode* data = new AllocateNode();
    data->var = var;
    data->value = value;
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

IfThenElse::IfThenElse(Expr condition, Stmt then_case, Stmt else_case=Stmt()) {
    IfThenElseNode* data = new IfThenElseNode();
    data->condition = condition;
    data->then_case = then_case;
    data->else_case = else_case;
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

Ret::Ret(Var ret_val) {
    RetNode* data = new RetNode();
    data->ret_val = ret_val;
    data_ = std::move(data);
}

SeqStmt AppendStmt(SeqStmt a, SeqStmt b) {
    a->seq.insert(a->seq.end(), b->seq.begin(), b->seq.end());
    return a;
}