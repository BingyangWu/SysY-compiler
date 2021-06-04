all: Eeyore

Eeyore: Eeyore_flex Eeyore_bison Tigger_flex Tigger_bison RISCV_flex RISCV_bison phase1/context.cpp phase1/context.h phase1/expr.cpp phase1/expr.h phase1/globals.h main.cpp phase1/object.h phase1/stmt.cpp phase1/stmt.h phase1/type.h phase2/Eeyore.hpp phase2/Eeyore.cpp
	g++ -Wno-register -lm -std=c++17 phase1/type.h phase1/context.h phase1/object.h phase1/expr.h phase1/stmt.h phase1/globals.h phase1/SysY.tab.hpp phase2/Eeyore.tab.hpp phase2/Eeyore.hpp phase3/Tigger.tab.hpp phase3/Tigger.hpp \
	phase1/SysY.tab.cpp phase2/Eeyore.tab.cpp phase3/Tigger.tab.cpp phase1/lex.yy.cpp phase2/lex.zz.cpp phase3/lex.rr.cpp phase1/context.cpp phase1/expr.cpp main.cpp phase1/stmt.cpp phase1/globals.cpp phase2/Eeyore.cpp phase3/Tigger.cpp \
	-o compiler -Idirs -g

Eeyore_flex: phase1/SysY.l Eeyore_bison
	flex -o phase1/lex.yy.cpp phase1/SysY.l

Eeyore_bison: phase1/SysY.y
	bison -d -o phase1/SysY.tab.cpp phase1/SysY.y

Tigger_flex: phase2/Eeyore.l Tigger_bison
	flex -o phase2/lex.zz.cpp phase2/Eeyore.l

Tigger_bison: phase2/Eeyore.y
	bison -d -o phase2/Eeyore.tab.cpp phase2/Eeyore.y

RISCV_flex: phase3/Tigger.l RISCV_bison
	flex -o phase3/lex.rr.cpp phase3/Tigger.l

RISCV_bison: phase3/Tigger.y
	bison -d -o phase3/Tigger.tab.cpp phase3/Tigger.y

clean:
	rm lex.yy.cpp SysY.tab.hpp SysY.tab.cpp compiler