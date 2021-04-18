%{
    #include <cstdio>

%}
%token IF ELSE WHILE BREAK CONTINUE RET

%token AND OR EQ NEQ LEQ GEQ

%token INT CONST VOID

%token IMM ID

%%

Program         :CompUnit                               {  }
;
CompUnit        :CompUnit Decl                          {  }
                |CompUnit FuncDef                       {  }
                |Decl                                   {  }
                |FuncDef                                {  }
;
Decl            :ConstDecl                              {  }
                |VarDecl                                {  }
;
ConstDecl       :CONST INT ConstDefSeq ';'              {  }
;
ConstDefSeq     :ConstDefSeq ',' ConstDef               {  }
                |ConstDef                               {  }
;
ConstDef        :Ident '=' ConstInitVal                 {  }
;
ConstInitVal    :ConstExp                               {  }
                |'{' ConstInitValSeq '}'                {  }
                |'{' '}'                                {  }
;
ConstInitValSeq :ConstInitValSeq ',' ConstInitVal       {  }
                |ConstInitVal                           {  }
;
VarDecl         :INT VarDefSeq ';'                     {  }
;
VarDefSeq       :VarDefSeq ',' VarDef                   {  }
                |VarDef                                 {  }
;
VarDef          :Ident                                  {  }
                |Ident '=' InitVal                      {  } 
;
InitVal         :Exp                                    {  }
                |'{' InitValSeq '}'                     {  }
                |'{' '}'                                {  }
;
InitValSeq      :InitValSeq ',' InitVal                 {  }
                |InitVal                                {  }
;
FuncDef         :VOID ID '(' FuncFParams ')' Block  {  }
                |VOID ID '(' ')' Block              {  }
                |INT ID '(' FuncFParams ')' Block  {  }
                |INT ID '(' ')' Block              {  }
;
FuncFParams     :FuncFParams ',' FuncParam              {  }
                |FuncParam                              {  }
;
FuncParam       :INT FuncIdent                         {  }
;
FuncIdent       :ID '[' ']' BrackertsSeq                {  }
                |ID BrackertsSeq                        {  }
                |ID '[' ']'                             {  }
                |ID                                     {  }
;
Ident           :ID BrackertsSeq                        {  }
                |ID                                     {  }
;
BrackertsSeq    :BrackertsSeq '[' Exp ']'               {  }
                |'[' Exp ']'                            {  }
;
Block           :'{' BlockItemSeq '}'                   {  }
;
BlockItemSeq    :BlockItemSeq BlockItem                 {  }
                |BlockItem                              {  }
;
BlockItem       :Decl                                   {  }
                |Stmt                                   {  }
;
Stmt            :Ident '=' Exp ';'                      {  }
                |Exp ';'                                {  }
                |';'                                    {  }
                |Block                                  {  }
                |IF '(' Cond ')' Stmt                   {  }
                |IF '(' Cond ')' Stmt ELSE Stmt         {  }
                |WHILE '(' Cond ')' Stmt                {  }
                |BREAK ';'                              {  }
                |CONTINUE ';'                           {  }
                |RET Exp ';'                            {  }
                |RET ';'                                {  }
;
ConstExp        :Exp                                    {  }
;
Exp             :Exp '+' Term                           {  }
                |Exp '-' Term                           {  }
                |Term                                   {  }
;
Term            :Term '*' Factor                        {  }
                |Term '/' Factor                        {  }
                |Term '%' Factor                        {  }
                |Factor                                 {  }
;
Factor          :'(' Exp ')'                            {  }
                |Ident                                  {  }
                |IMM                                    {  }
                |ID '(' FuncRParams ')'                 {  }
                |ID '(' ')'                             {  }
                |UnaryOp Factor                         {  }
;
FuncRParams     :FuncFParams ',' Exp                    {  }
                |Exp                                    {  }
;
UnaryOp         :'+'                                    {  }
                |'-'                                    {  }
                |'!'                                    {  }
;
Cond            :LorOp                                  {  }
;
LorOp           :LorOp OR LandOp                        {  }
                |LandOp                                 {  }
;
LandOp          :LandOp AND EqOp                        {  }
                |EqOp                                   {  }
;
EqOp            :EqOp EQ RelOp                          {  }
                |EqOp NEQ RelOp                         {  }
                |RelOp                                  {  }
;
RelOp           :RelOp '<' Exp                          {  }
                |RelOp '>' Exp                          {  }
                |RelOp LEQ Exp                          {  }
                |RelOp GEQ Exp                          {  }
                |Exp                                    {  }
;
%%