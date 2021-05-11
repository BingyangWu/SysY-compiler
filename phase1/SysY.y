%{
    #include <cstdio>
    #include "globals.h"
    #include "stmt.h"
    #include "expr.h"
%}
%token IF ELSE WHILE BREAK CONTINUE RET

%token AND OR EQ NEQ LEQ GEQ

%token INT CONST VOID

%token IMM ID

%%

Program         :CompUnit                               { TreeRoot = $1; }
;
CompUnit        :CompUnit Decl                          { $$ = AppendStmt($1, $2); }
                |CompUnit FuncDef                       { $$ = AppendStmt($1, $2); }
                |Decl                                   { $$ = SeqStmt($1); }
                |FuncDef                                { $$ = SeqStmt($1); }
;
Decl            :ConstDecl                              { $$ = $1; }
                |VarDecl                                { $$ = $1; }
;
ConstDecl       :CONST INT ConstDefSeq ';'              { $$ = $3; }
;
ConstDefSeq     :ConstDefSeq ',' ConstDef               { $$ = AppendStmt($1, $3); }
                |ConstDef                               { $$ = SeqStmt($1); }
;
ConstDef        :Ident '=' ConstInitVal                 { $$ = Allocate($1, $3); }
;
ConstInitVal    :ConstExp                               { $$ = Evaluate($1); }
                |'{' ConstInitValSeq '}'                { $$ = List($2); }
                |'{' '}'                                { $$ = EmptyList(); // problematic }
;
ConstInitValSeq :ConstInitValSeq ',' ConstInitVal       { $$ = AppendList($1, $3); }
                |ConstInitVal                           { $$ = List($1); }
;
VarDecl         :INT VarDefSeq ';'                     { $$ = $2; }
;
VarDefSeq       :VarDefSeq ',' VarDef                   { $$ = AppendStmt($1, $3); }
                |VarDef                                 { $$ = Stmt($1); }
;
VarDef          :Ident                                  { $$ = Allocate($1); }
                |Ident '=' InitVal                      { $$ = Allocate($1, $3); } 
;
InitVal         :Exp                                    { $$ = Evaluate($1); }
                |'{' InitValSeq '}'                     { $$ = List($2); }
                |'{' '}'                                { $$ = EmptyList(); }
;
InitValSeq      :InitValSeq ',' InitVal                 { $$ = AppendList($1, $3); }
                |InitVal                                { $$ = List($1); }
;
FuncDef         :VOID ID '(' FuncFParams ')' Block  { $$ = Func(kVoid, $2, $4, $6); }
                |VOID ID '(' ')' Block              { $$ = Func(kVoid, $2, $6); }
                |INT ID '(' FuncFParams ')' Block  { $$ = Func(kVoid, $2, $4, $6); }
                |INT ID '(' ')' Block              { $$ = Func(kVoid, $2, $6); }
;
FuncFParams     :FuncFParams ',' FuncParam              { $$ = AppendStmt($1, $3); }
                |FuncParam                              { $$ = SeqStmt($1); }
;
FuncParam       :INT FuncIdent                         { $$ = $2; }
;
FuncIdent       :ID '[' ']' BrackertsSeq                { $$ = Array($1, $3, true); }
                |ID BrackertsSeq                        { $$ = Array($1, $2, false); }
                |ID '[' ']'                             { $$ = Array($1, false); }
                |ID                                     { $$ = $1; }
;
Ident           :ID BrackertsSeq                        { $$ = Array($1, $2, false); }
                |ID                                     { $$ = $1; }
;
BrackertsSeq    :BrackertsSeq '[' Exp ']'               { $$ = AppendList($1, $3); }
                |'[' Exp ']'                            { $$ = List($2); }
;
Block           :'{' BlockItemSeq '}'                   { $$ = SeqStmt($2); // problematic }
;
BlockItemSeq    :BlockItemSeq BlockItem                 { $$ = AppendStmt($1, $2); }
                |BlockItem                              { $$ = SeqStmt($1); }
;
BlockItem       :Decl                                   { $$ = $1; }
                |Stmt                                   { $$ = $1; }
;
Stmt            :Ident '=' Exp ';'                      { $$ = Store($1, $3); }
                |Exp ';'                                { $$ = Evaluate($1); }
                |';'                                    { $$ = Stmt(); }
                |Block                                  { $$ = $1; }
                |IF '(' Cond ')' Stmt                   { $$ = IfThenElse($3, $5); }
                |IF '(' Cond ')' Stmt ELSE Stmt         { $$ = IfThenElse($3, $5, $7); }
                |WHILE '(' Cond ')' Stmt                { $$ = While($3, $5); }
                |BREAK ';'                              { $$ = Goto("next"); }
                |CONTINUE ';'                           { $$ = Goto("begin"); }
                |RET Exp ';'                            { $$ = Ret($2); }
                |RET ';'                                { $$ = Ret(Var()); }
;
ConstExp        :Exp                                    { $$ = $1; }
;
Exp             :Exp '+' Term                           { $$ = BinaryOp($1, kAdd, $3); }
                |Exp '-' Term                           { $$ = BinaryOp($1, kSub, $3); }
                |Term                                   { $$ = $1; }
;
Term            :Term '*' Factor                        { $$ = BinaryOp($1, kMul, $3); }
                |Term '/' Factor                        { $$ = BinaryOp($1, kDiv, $3); }
                |Term '%' Factor                        { $$ = BinaryOp($1, kMod, $3); }
                |Factor                                 { $$ = $1; }
;
Factor          :'(' Exp ')'                            { $$ = $2; }
                |Ident                                  { $$ = $1; //problematic }
                |IMM                                    { $$ = $1; }
                |ID '(' FuncRParams ')'                 { $$ = Call($1, $3); }
                |ID '(' ')'                             { $$ = Call($1, EmptyList()); }
                |'+' Factor                             { $$ = $2; }
                |'-' Factor                             { $$ = BinaryOp(Imm(kInt, 0), $2); }
                |'!' Factor                             { $$ = Not($2); }
;
FuncRParams     :FuncFParams ',' Exp                    { $$ = AppendList($1, $3); }
                |Exp                                    { $$ = List($1); }
;

Cond            :LorOp                                  { $$ = $1; }
;
LorOp           :LorOp OR LandOp                        { $$ = BinaryOp($1, kOr, $3); }
                |LandOp                                 { $$ = $1; }
;
LandOp          :LandOp AND EqOp                        { $$ = BinaryOp($1, kAnd, $3); }
                |EqOp                                   { $$ = $1; }
;
EqOp            :EqOp EQ RelOp                          { $$ = BinaryOp($1, kEQ, $3); }
                |EqOp NEQ RelOp                         { $$ = BinaryOp($1, kNEQ, $3); }
                |RelOp                                  { $$ = $1; }
;
RelOp           :RelOp '<' Exp                          { $$ = BinaryOp($1, kLT, $3); }
                |RelOp '>' Exp                          { $$ = BinaryOp($1, kGT, $3); }
                |RelOp LEQ Exp                          { $$ = BinaryOp($1, kLEQ, $3); }
                |RelOp GEQ Exp                          { $$ = BinaryOp($1, kGEQ, $3); }
                |Exp                                    { $$ = $1; }
;
%%