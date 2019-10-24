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
  yyparse();
}
