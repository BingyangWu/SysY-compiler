#ifndef _STMT_H_
#define _STMT_H_

#include "expr.h"

class StmtNode: public Object {
public:
};

class Stmt: public ObjectRef {
public:
    DEFINE_OBJECT_REF_METHODS(Stmt, ObjectRef, StmtNode);
};

class StoreNode: public StmtNode {
public:
    Var lval;
    Expr rval;
};

class Store: public Stmt {
public:
    Store(Var lval, Expr rval);
    DEFINE_OBJECT_REF_METHODS(Store, Stmt, StoreNode);
};

class AllocateNode: public StmtNode {
public:
    Var var;
    Expr value;
};

class Allocate: public Stmt {
public:
    Allocate(Var var, Expr value);
    DEFINE_OBJECT_REF_METHODS(Allocate, Stmt, AllocateNode);
};

class EvaluateNode: public StmtNode {
public:
    Expr value;
};

class Evaluate: public Stmt {
public:
    Evaluate(Expr value);
    DEFINE_OBJECT_REF_METHODS(Evaluate, Stmt, EvaluateNode);
};

class FuncNode: public StmtNode {
public:
    DataType ret_type;
    Var name;
    List<Var> params;
    Stmt body;
};

class Func: public Stmt {
public:
    Func(DataType ret_type, Var name, List<Var> params, SeqStmt body);
    DEFINE_OBJECT_REF_METHODS(Func, Stmt, FuncNode);
};

class SeqStmtNode: public StmtNode {
public:
    std::vector<Stmt> seq;
};

class SeqStmt: public Stmt {
public:
    SeqStmt(std::vector<Stmt> seq);
    SeqStmt(Stmt stmt);
    DEFINE_OBJECT_REF_METHODS(SeqStmt, Stmt, SeqStmtNode);
};

class IfThenElseNode: public StmtNode {
public:
    Expr condition;
    Stmt then_case;
    Stmt else_case;
};

class IfThenElse: public Stmt {
public:
    IfThenElse(Expr condition, Stmt then_case, Stmt else_case);
    DEFINE_OBJECT_REF_METHODS(IfThenElse, Stmt, IfThenElseNode);
};

class WhileNode: public StmtNode {
public:
    Expr condition;
    Stmt body;
};

class While: public Stmt {
public:
    While(Expr condition, Stmt body);
    DEFINE_OBJECT_REF_METHODS(While, Stmt, WhileNode);
};

class GotoNode: public StmtNode {
public:
    std::string location;
};

class Goto: public Stmt {
public:
    Goto(std::string location);
    DEFINE_OBJECT_REF_METHODS(Goto, Stmt, GotoNode);
};

class RetNode: public StmtNode {
public:
    Var ret_val;
};

class Ret: public Stmt {
public:
    Ret(Var ret_val);
    DEFINE_OBJECT_REF_METHODS(Ret, Stmt, RetNode);
};

SeqStmt AppendStmt(SeqStmt a, SeqStmt b);

#endif // _STMT_H_