%{
  #include <stdio.h>
  
  int yylex(void);
  void yyerror(char const*);
%}

%token TYPE A_OPERATOR L_OPERATOR COMPARATOR ATRIBUTION IF ELSE SWITCH CASE DEFAULT FOR WHILE LOOP RETURN L_PARENTHESES R_PARENTHESES L_CURLY R_CURLY SEMICOLON COMMA L_SQUARE R_SQUARE BOOL NUMBER STRING VARIABLE

%%

input:
  %empty
  | input function
  ;

function:
  '\n'
  | TYPE VARIABLE L_PARENTHESES parameter_1 R_PARENTHESES L_CURLY statement R_CURLY
  ;

parameter_1:
  TYPE VARIABLE
  | TYPE VARIABLE parameter_n
  ;

parameter_n:
  COMMA TYPE VARIABLE
  | COMMA TYPE VARIABLE parameter_n
  ;
  
statement:
  declaration_1 SEMICOLON statement
  | atribution SEMICOLON statement
  | conditional statement
  ;

declaration_1:
  TYPE VARIABLE atribution
  ;

declaration_n:
  COMMA VARIABLE atribution
  ;

atribution:
  declaration_n
  | ATRIBUTION a_expression declaration_n
  | ATRIBUTION l_expression declaration_n
  ;

conditional:
  IF L_PARENTHESES l_expression R_PARENTHESES L_CURLY statement R_CURLY
  ;

l_expression:
  L_PARENTHESES l_id R_PARENTHESES
  | l_id L_OPERATOR l_id
  | l_id
  ;

l_id:
  VARIABLE
  | BOOL
  | l_expression
  ;

a_expression:
  L_PARENTHESES a_expression R_PARENTHESES
  | VARIABLE A_OPERATOR a_expression
  | NUMBER A_OPERATOR a_expression
  | VARIABLE
  | NUMBER
  ;

%%

void yyerror(char const* s) {
  fprintf(stderr, "%s\n", s);
}

#include "lex.yy.o"

int main(int argc, char* argv[]) {
  argv++;
  argc--;
  yyin = fopen(*argv, "r");
  yyparse();
}
