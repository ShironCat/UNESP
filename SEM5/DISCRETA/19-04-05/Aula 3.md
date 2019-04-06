# Aula 3

## Função

### Definição (Bijeção)

$f:A \rightarrow B$ é bijetora se, e somente se é injetora e sobrejetora ou seja

$$
    f\ é\ bijetora \iff \forall y \in B, \exists! x \in A | f(x) = y
$$

$f$ é bijetora se, e somente para qualquer $y \in B$, existe um único $x \in A$ tal que $f(x) = y$

## Composição de funções

sejam

$$
    f:S \rightarrow T
$$
$$
    g:T \rightarrow U
$$

observe que $\forall s \in S, f(s) \in T$ e $T$ é o domínio de $g$. Logo, a função $g$ pode ser calculada em f(s) que serulta em $g(f(s)) \in U$.

### Definição

Sejam $f:S \rightarrow T$ e $f:T \rightarrow U$

A **função composta** $g \circ f$ é a função de $S$ em $U$ definida por **$(g \circ f)(s) = g \circ f(s) = g(f(s))$**

## Função Inversa

### Observação

Considere uma função bijetora de $A$ em $B$, ou seja, todo elemento de $B$ é imagem de um único elemento de $A$.

$$
    f:A \rightarrow B
$$
$$
    \forall b \in B, \exists! a \in A, f(a) = b
$$

$b$ é imagem de $a$ pelo $f$.

Neste caso podemos definir a **função inversa de $f$**.

### Definição

Seja $f:A \rightarrow B$ bijetora, a **função inversa de $f$** é a função que leva a um elemento $b \in B$ o único elemento $a \in A$ tal que $f(a) = b$. A função inversa de $f$ é indicada por $f^{-1}$.

Assim, $f^{-1} = a$ quando $f(a) = b$

### Observação

Não confundir $f^{-1}$ com $\frac{1}{f(x)}$, $f^{-1}$ e $\frac{1}{f(x)}$ não são iguais.

### Observação

Uma função bijetora é chamada de inversível (ou invertível) ou seja possui inversa.