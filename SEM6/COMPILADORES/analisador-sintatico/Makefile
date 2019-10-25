y.tab.c: lex.yy.o
	gcc -W -g anasin.tab.c -o lushi

lex.yy.c: y.tab.h
	flex analex.l

y.tab.h: 
	bison -d anasin.y
