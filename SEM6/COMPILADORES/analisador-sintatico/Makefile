y.tab.c: lex.yy.c
	gcc -W -g y.tab.c -o lushi

lex.yy.c: y.tab.h
	flex analex.l

y.tab.h: 
	yacc -d anasin.y
