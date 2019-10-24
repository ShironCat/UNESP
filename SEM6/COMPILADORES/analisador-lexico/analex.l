%{
  #include <math.h>

  int
    row = 1,
    col = 1;

  char* table(int id) {
    char *result = (char*) malloc(sizeof(char) * 11);
    switch(id) {
      case 0:
        sprintf(result, "type");
        break;
      case 1:
        sprintf(result, "operator");
        break;
      case 2:
        sprintf(result, "reserved");
        break;
      case 3:
        sprintf(result, "punctuation");
        break;
      case 4:
        sprintf(result, "number");
        break;
      case 5:
        sprintf(result, "string");
        break;
			case 6:
        sprintf(result, "variable");
        break;
      case 7:
        sprintf(result, "comment");
        break;
			case 8:
				sprintf(result, "boolean");
				break;
      default:
        sprintf(result, "token not defined\n");
    }
    return result;
  }

  void accept(int id) {
    col += strlen(yytext);
    fprintf(
      stdout,
      "%s : %s\n",
      yytext,
      table(id)
    );
  }
%}

TYPE        "dbl"|"int"|"str"|"bol"
OPERATOR    "and"|"or"|"xor"|"not"|"+"|"-"|"*"|"/"|"%"|">"|">="|"<"|"<="|"="|"=="|"!="
RESERVED    "if"|"els"|"swt"|"case"|"dflt"|"for"|"whl"|"lop"|"rtn"
PUNCTUATION "("|")"|"{"|"}"|";"|","|"["|"]"
BOOL				"tru"|"fls"
NUMBER      "-"?([0-9]+("."[0-9]+)?)
STRING      ("\"".*"\"")
VARIABLE    ([_a-zA-Z][_a-zA-Z0-9]*)

COMMENT     ("//".*)

%%

[\$]          { row++; col++; }
[[:blank:]]   { col++; }

{TYPE}        { accept(0); }
{OPERATOR}    { accept(1); }
{RESERVED}    { accept(2); }
{PUNCTUATION} { accept(3); }
{BOOL}				{ accept(8); }
{NUMBER}      { accept(4); }
{STRING}      { accept(5); }
{VARIABLE}    { accept(6); }

{COMMENT}     { accept(7); }

.             {
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
 
int yywrap() { }
int main(int argc, char* argv[]) {
  argv++;
  argc--;
  if(argc == 0) {
    yyin = stdin;
  } else {
    yyin = fopen(*argv, "r");
    if(yyin == NULL) {
      fprintf(
        stdout,
        "%s not found, using as interactive shell.\n\n",
        *argv
      );
      yyin = stdin;
    }
  }
  yylex();
}
