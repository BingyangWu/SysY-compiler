all: Eeyore

Eeyore: flex bison context.cpp context.h expr.cpp expr.h globals.h main.cpp object.h stmt.cpp stmt.h type.h
	g++ -Wno-register -O2 -lm -std=c++17 type.h context.h object.h expr.h stmt.h globals.h SysY.tab.hpp SysY.tab.cpp lex.yy.cpp context.cpp expr.cpp main.cpp stmt.cpp globals.cpp -o compiler -Idirs

flex: SysY.l bison
	flex -o lex.yy.cpp SysY.l

bison: SysY.y
	bison -d -o SysY.tab.cpp SysY.y

clean:
	rm lex.yy.cpp SysY.tab.hpp SysY.tab.cpp compiler