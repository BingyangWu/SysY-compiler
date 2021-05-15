%{
    #include <cstdio>
    #include "globals.h"
    #include "stmt.h"
    #include "expr.h"
    int yyerror(const char *);
    extern int yylex(void);
%}
%token IF ELSE WHILE BREAK CONTINUE RET

%token AND OR EQ NEQ LEQ GEQ

%token INT CONST VOID

%token IMM ID

%%

Program         :CompUnit                               { TreeRoot = $1; }
;
CompUnit        :CompUnit Decl                          { $$ = &AppendStmt(*dynamic_cast<SeqStmt*>($1), *dynamic_cast<SeqStmt*>($2)); }
                |CompUnit FuncDef                       { $$ = &AppendStmt(*dynamic_cast<SeqStmt*>($1), *new SeqStmt(*dynamic_cast<Stmt*>($2))); }
                |Decl                                   { $$ = $1; }
                |FuncDef                                { $$ = new SeqStmt(*dynamic_cast<Stmt*>($1)); }
;
Decl            :ConstDecl                              { $$ = $1; }
                |VarDecl                                { $$ = $1; }
;
ConstDecl       :CONST INT ConstDefSeq ';'              { $$ = $3; }
;
ConstDefSeq     :ConstDefSeq ',' ConstDef               { $$ = &AppendStmt(*dynamic_cast<SeqStmt*>($1), *new SeqStmt(*dynamic_cast<Stmt*>($3))); }
                |ConstDef                               { $$ = new SeqStmt(*dynamic_cast<Stmt*>($1)); }
;
ConstDef        :Ident '=' ConstInitVal                 { $$ = new Allocate(*dynamic_cast<Var*>($1), *dynamic_cast<Expr*>($3), true); }
;
ConstInitVal    :ConstExp                               { $$ = $1; }
                |'{' ConstInitValSeq '}'                { $$ = $2; }
                |'{' '}'                                { $$ = EmptyList<Expr>(); }
;
ConstInitValSeq :ConstInitValSeq ',' ConstInitVal       { $$ = &AppendList(*dynamic_cast<List<Expr>*>($1), *new List<Expr>(*dynamic_cast<Expr*>($3))); }
                |ConstInitVal                           { $$ = new List<Expr>(*dynamic_cast<Expr*>($1)); }
;
VarDecl         :INT VarDefSeq ';'                     { $$ = $2; }
;
VarDefSeq       :VarDefSeq ',' VarDef                   { $$ = &AppendStmt(*dynamic_cast<SeqStmt*>($1), *new SeqStmt(*dynamic_cast<Stmt*>($3))); }
                |VarDef                                 { $$ = new SeqStmt(*dynamic_cast<Stmt*>($1)); }
;
VarDef          :Ident                                  { $$ = new Allocate(*dynamic_cast<Var*>($1), Expr(), false); }
                |Ident '=' InitVal                      { $$ = new Allocate(*dynamic_cast<Var*>($1), *dynamic_cast<Expr*>($3), true); } 
;
InitVal         :Exp                                    { $$ = $1; }
                |'{' InitValSeq '}'                     { $$ = $2; }
                |'{' '}'                                { $$ = EmptyList<Expr>(); }
;
InitValSeq      :InitValSeq ',' InitVal                 { $$ = &AppendList(*dynamic_cast<List<Expr>*>($1), *new List<Expr>(*dynamic_cast<Expr*>($3))); }
                |InitVal                                { $$ = new List<Expr>(*dynamic_cast<Expr*>($1)); }
;
FuncDef         :VOID ID '(' FuncFParams ')' Block  { $$ = new Func(kVoid, *dynamic_cast<Var*>($2), *dynamic_cast<List<Var>*>($4), *dynamic_cast<SeqStmt*>($6)); }
                |VOID ID '(' ')' Block              { $$ = new Func(kVoid, *dynamic_cast<Var*>($2), *EmptyList<Var>(), *dynamic_cast<SeqStmt*>($5)); }
                |INT ID '(' FuncFParams ')' Block  { $$ = new Func(kInt, *dynamic_cast<Var*>($2), *dynamic_cast<List<Var>*>($4), *dynamic_cast<SeqStmt*>($6)); }
                |INT ID '(' ')' Block              { $$ = new Func(kInt, *dynamic_cast<Var*>($2), *EmptyList<Var>(), *dynamic_cast<SeqStmt*>($5)); }
;
FuncFParams     :FuncFParams ',' FuncParam              { $$ = &AppendList(*dynamic_cast<List<Var>*>($1), *new List<Var>(*dynamic_cast<Var*>($3))); }
                |FuncParam                              { $$ = new List<Var>(*dynamic_cast<Var*>($1)); }
;
FuncParam       :INT FuncIdent                         { $$ = $2; }
;
FuncIdent       :ID '[' ']' BrackertsSeq                { $$ = new Array(*dynamic_cast<Var*>($1), *dynamic_cast<List<Expr>*>($3), true); }
                |ID BrackertsSeq                        { $$ = new Array(*dynamic_cast<Var*>($1), *dynamic_cast<List<Expr>*>($2), false); }
                |ID '[' ']'                             { $$ = new Array(*dynamic_cast<Var*>($1), *EmptyList<Expr>(), true); }
                |ID                                     { $$ = $1; }
;
Ident           :ID BrackertsSeq                        { $$ = new Array(*dynamic_cast<Var*>($1), *dynamic_cast<List<Expr>*>($2), false); }
                |ID                                     { $$ = $1; }
;
BrackertsSeq    :BrackertsSeq '[' Exp ']'               { $$ = &AppendList(*dynamic_cast<List<Expr>*>($1), *new List<Expr>(*dynamic_cast<Expr*>($3))); }
                |'[' Exp ']'                            { $$ = new List<Expr>(*dynamic_cast<Expr*>($2)); }
;
Block           :'{' BlockItemSeq '}'                   { $$ = $2; }
;
BlockItemSeq    :BlockItemSeq BlockItem                 { $$ = &AppendStmt(*dynamic_cast<SeqStmt*>($1), *dynamic_cast<SeqStmt*>($2)); }
                |BlockItem                              { $$ = $1; }
;
BlockItem       :Decl                                   { $$ = $1; }
                |Stmt                                   { $$ = new SeqStmt(*dynamic_cast<Stmt*>($1)); }
;
Stmt            :Ident '=' Exp ';'                      { $$ = new Store(*dynamic_cast<Var*>($1), *dynamic_cast<Expr*>($3)); }
                |Exp ';'                                { $$ = new Evaluate(*dynamic_cast<Expr*>($1)); }
                |';'                                    { $$ = new Stmt(); }
                |Block                                  { $$ = $1; }
                |IF '(' Cond ')' Stmt                   { $$ = new IfThenElse(*dynamic_cast<Expr*>($3), *dynamic_cast<Stmt*>($5)); }
                |IF '(' Cond ')' Stmt ELSE Stmt         { $$ = new IfThenElse(*dynamic_cast<Expr*>($3), *dynamic_cast<Stmt*>($5), *dynamic_cast<Stmt*>($7), true); }
                |WHILE '(' Cond ')' Stmt                { $$ = new While(*dynamic_cast<Expr*>($3), *dynamic_cast<Stmt*>($5)); }
                |BREAK ';'                              { $$ = new Goto("next"); }
                |CONTINUE ';'                           { $$ = new Goto("begin"); }
                |RET Exp ';'                            { $$ = new Ret(*dynamic_cast<Expr*>($2), true); }
                |RET ';'                                { $$ = new Ret(Expr(), false); }
;
ConstExp        :Exp                                    { $$ = $1; }
;
Exp             :Exp '+' Term                           { $$ = new BinaryOp(*dynamic_cast<Expr*>($1), kAdd, *dynamic_cast<Expr*>($3)); }
                |Exp '-' Term                           { $$ = new BinaryOp(*dynamic_cast<Expr*>($1), kSub, *dynamic_cast<Expr*>($3)); }
                |Term                                   { $$ = $1; }
;
Term            :Term '*' Factor                        { $$ = new BinaryOp(*dynamic_cast<Expr*>($1), kMul, *dynamic_cast<Expr*>($3)); }
                |Term '/' Factor                        { $$ = new BinaryOp(*dynamic_cast<Expr*>($1), kDiv, *dynamic_cast<Expr*>($3)); }
                |Term '%' Factor                        { $$ = new BinaryOp(*dynamic_cast<Expr*>($1), kMod, *dynamic_cast<Expr*>($3)); }
                |Factor                                 { $$ = $1; }
;
Factor          :'(' Exp ')'                            { $$ = $2; }
                |Ident                                  { $$ = $1; }
                |IMM                                    { $$ = $1; }
                |ID '(' FuncRParams ')'                 { $$ = new Call(*dynamic_cast<Var*>($1), *dynamic_cast<List<Expr>*>($3)); }
                |ID '(' ')'                             { $$ = new Call(*dynamic_cast<Var*>($1), *EmptyList<Expr>()); }
                |'+' Factor                             { $$ = $2; }
                |'-' Factor                             { $$ = new BinaryOp(Imm(kInt, 0), kSub, *dynamic_cast<Expr*>($2)); }
                |'!' Factor                             { $$ = new Not(*dynamic_cast<Expr*>($2)); }
;
FuncRParams     :FuncFParams ',' Exp                    { $$ = &AppendList(*dynamic_cast<List<Expr>*>($1), *new List<Expr>(*dynamic_cast<Expr*>($3))); }
                |Exp                                    { $$ = new List<Expr>(*dynamic_cast<Expr*>($1)); }
;

Cond            :LorOp                                  { $$ = $1; }
;
LorOp           :LorOp OR LandOp                        { $$ = new BinaryOp(*dynamic_cast<Expr*>($1), kOr, *dynamic_cast<Expr*>($3)); }
                |LandOp                                 { $$ = $1; }
;
LandOp          :LandOp AND EqOp                        { $$ = new BinaryOp(*dynamic_cast<Expr*>($1), kAnd, *dynamic_cast<Expr*>($3)); }
                |EqOp                                   { $$ = $1; }
;
EqOp            :EqOp EQ RelOp                          { $$ = new BinaryOp(*dynamic_cast<Expr*>($1), kEQ, *dynamic_cast<Expr*>($3)); }
                |EqOp NEQ RelOp                         { $$ = new BinaryOp(*dynamic_cast<Expr*>($1), kNEQ, *dynamic_cast<Expr*>($3)); }
                |RelOp                                  { $$ = $1; }
;
RelOp           :RelOp '<' Exp                          { $$ = new BinaryOp(*dynamic_cast<Expr*>($1), kLT, *dynamic_cast<Expr*>($3)); }
                |RelOp '>' Exp                          { $$ = new BinaryOp(*dynamic_cast<Expr*>($1), kGT, *dynamic_cast<Expr*>($3)); }
                |RelOp LEQ Exp                          { $$ = new BinaryOp(*dynamic_cast<Expr*>($1), kLEQ, *dynamic_cast<Expr*>($3)); }
                |RelOp GEQ Exp                          { $$ = new BinaryOp(*dynamic_cast<Expr*>($1), kGEQ, *dynamic_cast<Expr*>($3)); }
                |Exp                                    { $$ = $1; }
;
%%
int yyerror(const char *message) {
	return 0;
}