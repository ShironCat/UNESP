y.tab.c: lex.yy.o
	gcc -W -g y.tab.c lex.yy.o -o lushi

lex.yy.o: y.tab.h
	flex analex.l
	gcc -c lex.yy.c

y.tab.h: 
	yacc -d anasin.y
