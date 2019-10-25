%{
  #include <stdio.h>
  
  int yylex(void);
  void yyerror(char const*);
%}

%start start

%token TYPE A_OPERATOR L_OPERATOR COMPARATOR ATRIBUTION IF ELSE SWITCH CASE DEFAULT FOR WHILE LOOP RETURN L_PARENTHESES R_PARENTHESES L_CURLY R_CURLY SEMICOLON COMMA L_SQUARE R_SQUARE BOOL NUMBER STRING VARIABLE

%%

start:
  %empty
  | function
  | start function
  ;

function:
  TYPE VARIABLE L_PARENTHESES parameter R_PARENTHESES statement_block
  | TYPE VARIABLE L_PARENTHESES R_PARENTHESES statement_block
  ;

parameter:
  TYPE VARIABLE COMMA
  | parameter TYPE VARIABLE COMMA
  ;

statement_block:
  L_CURLY R_CURLY
  | L_CURLY statement_list R_CURLY
  ;

statement_list:
  statement
  | statement_list statement
  ;

statement:
  TYPE VARIABLE SEMICOLON
  | VARIABLE ATRIBUTION a_expression SEMICOLON
  | conditional
  | loop
  ;

a_expression:
  a_id A_OPERATOR a_id
  | L_PARENTHESES a_id R_PARENTHESES
  | a_id
  ;

a_id:
  a_expression
  | VARIABLE
  | NUMBER
  ;

l_expression:
  l_id L_OPERATOR l_id
  | l_id COMPARATOR l_id
  | L_PARENTHESES l_id R_PARENTHESES
  | l_id
  ;

l_id:
  l_expression
  | VARIABLE
  | NUMBER
  ;

conditional:
  IF L_PARENTHESES l_expression R_PARENTHESES statement_block ELSE statement_block
  | IF L_PARENTHESES l_expression R_PARENTHESES
  | SWITCH L_PARENTHESES VARIABLE R_PARENTHESES statement_switch
  ;

statement_switch:
  CASE VARIABLE statement_block
  | statement_switch CASE VARIABLE statement_block
  | DEFAULT statement_block
  ;

loop:
  FOR L_PARENTHESES TYPE VARIABLE SEMICOLON l_expression SEMICOLON VARIABLE ATRIBUTION a_expression SEMICOLON R_PARENTHESES statement_block
  | WHILE L_PARENTHESES l_expression R_PARENTHESES statement_block
  | LOOP statement_block
  ;
  
%%

#include "lex.yy.c"

void yyerror(char const* s) {
  fprintf(stderr, "%s\n", s);
}

int main(int argc, char* argv[]) {
  argv++;
  argc--;
  yyin = fopen(*argv, "r");
  yyparse();
}
