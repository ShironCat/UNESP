%{
  #include "anasin.tab.h"
  
  int
    row = 1,
    col = 1;
%}

TYPE          "dbl"|"int"|"str"|"bol"
A_OPERATOR    "+"|"-"|"*"|"/"|"%"
L_OPERATOR    "and"|"or"|"xor"|"not"
COMPARATOR    ">"|">="|"<"|"<="|"=="|"!="
ATRIBUTION    "="
IF            "if"
ELSE          "els"
SWITCH        "swt"
CASE          "case"
DEFAULT       "dflt"
FOR           "for"
WHILE         "whl"
LOOP          "lop"
RETURN        "rtn"
L_PARENTHESES "("
R_PARENTHESES ")"
L_CURLY       "{"
R_CURLY       "}"
SEMICOLON     ";"
COMMA         ","
L_SQUARE      "["
R_SQUARE      "]"
BOOL				  "tru"|"fls"
NUMBER        "-"?([0-9]+("."[0-9]+)?)
STRING        ("\"".*"\"")
VARIABLE      ([_a-zA-Z][_a-zA-Z0-9]*)

COMMENT       ("//".*)

%%

[\$]            { row++; col++;           }
[[:blank:]]     { col++;                  }

{TYPE}          { return(TYPE);           }
{A_OPERATOR}    { return(A_OPERATOR);     }
{L_OPERATOR}    { return(L_OPERATOR);     }
{COMPARATOR}    { return(COMPARATOR);     }
{ATRIBUTION}    { return(ATRIBUTION);     }
{IF}            { return(IF);             }
{ELSE}          { return(ELSE);           }
{SWITCH}        { return(SWITCH);         }
{CASE}          { return(CASE);           }
{DEFAULT}       { return(DEFAULT);        }
{FOR}           { return(FOR);            }
{WHILE}         { return(WHILE);          }
{LOOP}          { return(LOOP);           }
{RETURN}        { return(RETURN);         }
{L_PARENTHESES} { return(L_PARENTHESES);  }
{R_PARENTHESES} { return(R_PARENTHESES);  }
{L_CURLY}       { return(L_CURLY);        }
{R_CURLY}       { return(R_CURLY);        }
{SEMICOLON}     { return(SEMICOLON);      }
{COMMA}         { return(COMMA);          }
{L_SQUARE}      { return(L_SQUARE);       }
{R_SQUARE}      { return(R_SQUARE);       }
{BOOL}				  { return(BOOL);           }
{NUMBER}        { return(NUMBER);         }
{STRING}        { return(STRING);         }
{VARIABLE}      { return(VARIABLE);       }

{COMMENT}       {}

.               {
								  col += strlen(yytext) - 1;
                  fprintf(
                    stdout,
                    "Error in %d:%d, \'%s\' is not a valid token.\n",
                    row,
                    col,
                    yytext
                  );
                }

%%

int yywrap() {}
