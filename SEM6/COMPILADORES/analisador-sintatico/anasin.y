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
  %empty
  | TYPE VARIABLE paramenter_n
  ;

parameter_n:
  %empty
  | COMMA TYPE VARIABLE paramenter_n
  ;

statement:
  %empty
  | declaration_1 SEMICOLON statement
  | atribution SEMICOLON statement
  | conditional statement
  ;

declaration_1:
  %empty
  | TYPE VARIABLE atribution
  ;

declaration_n:
  %empty
  | COMMA VARIABLE atribution
  ;

atribution:
  %empty declaration_n
  | ATRIBUTION a_expression declaration_n
  | ATRIBUTION l_expression declaration_n
  ;

conditional:
  IF L_PARENTHESES l_expression R_PARENTHESES L_CURLY statement R_CURLY
  ;

l_expression:
  l_id L_OPERATOR l_id
  | L_PARENTHESES l_id
  ;

%%

void yyerror(char const* s) {
  fprintf(stderr, "%s\n", s);
}
