%%

[_|a-z|A-Z]+[_|a-z|A-Z|0-9]* {
  printf("Variavel");
}

dbl|int|str|bol {
  printf("Tipo");
}

and|or|xor|not|+|-|*|/|%|>|>=|<|<=|==|!= {
  printf("Operadores");
}

if|str|case|dflt|for|whl|lop {
  printf("Palavra reservada");
}

(|)|{|}|;|,|[|] {
  printf("Pontuacao");
}

%%

int main() {
  yylex();
}