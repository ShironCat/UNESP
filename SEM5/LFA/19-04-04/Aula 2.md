# Aula 2

## Gramática do tipo 0 (irrestrita)

### Definição

Uma gramática $G = (V, \Sigma, P, S)$ é uma gramática irrestrita quando não são impostas limitações às regras de produção.

* **Observação**: $V, \Sigma, P, S$ já definidos
* As produções são da forma $\alpha \rightarrow \beta, \alpha \in (V \cup \Sigma)^{+}, \beta \in (V \cup \Sigma)^{*}$

### Definição

Uma gramática irrestrita gera uma linguagem irrestrita

### Definição

Uma gramática do tipo 1 ou sensível ao contexto é uma gramática $G(V, \Sigma, P, S)$ onde as produções são do tipo $\alpha \rightarrow \beta\ |\alpha| \Leftarrow |\beta|, \alpha, \beta \in (V \cup \Sigma)^{+}$

Nenhuma substituição pode reduzir o comprimento da "forma sentencial" à qual a substituição é aplicada.

### Definição

Uma gramática do tipo 1 gera uma linguagem do tipo 1.

### Definição

Uma gramática $G(V, \Sigma, P, S)$ é uma gramática do tipo 2 ou livre de contexto quando as regras de produção são da forma $A \rightarrow \beta, A \in V\ \beta \in (V \cup \Sigma)^{*}$

A linguagem gerada por uma gramática do tipo 2 é a linguagem livre de contexto.

### Definição

Uma gramática $G = (V, \Sigma, P, S)$ é uma gramática do tipo 3 ou regular quando as produções são da forma $A \rightarrow aB$ ou $A \rightarrow a$ (linear a direita) ou $A \rightarrow Ba$ ou $A \rightarrow a$ (linar a esquerda) $A, B \in V, a \in \Sigma$

A linguagem gerada por uma gramática regular é denominada linguagem regular.