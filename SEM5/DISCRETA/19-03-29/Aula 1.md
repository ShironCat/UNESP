# Matemática Discreta

**Definição**: Conjunto é uma coleção não ordenada de objetos que são os seus elementos.

Em geral, todos os objetos do conjunto têm alguma propriedade em comum.

Ex:

* $A = \{1, 2, 3\}$
* $B = \{2, 3, 1\}$

Notação:

* letras maiúsculas ara denotar conjuntos
* letras minúsculas para denotar elementos/objetos
* $\in$ para denotar pertinência

* $a \in A$: significa que o elemento $a$ pertence ao conjunto $A$
* $a \notin A$: caso contrário

$\mathbb{N}$ conjunto de todos os números inteiros não negativos ($0 \in \mathbb{N}$)

$\mathbb{Z}$ conjunto de todos os números inteiros

$\mathbb{Q}$ conjunto de todos os números racionais

$\mathbb{R}$ conjunto de todos os números reais

$\emptyset$ conjunto vazio (não tem elementos)

Ex:

* $A = \{x | x \in \mathbb{N} e\ x < 0\}$

Definição: O conjunto é um **subconjunto** de $B$ se, e somente se todos os elementos de $A$ também é um elemento de $B$.

Notação $A \subseteq B$ ou $A \subset B$

Observação: Se existir um elemento de $A$ que não pertencer a $B$, então $A$ não é subconjunto de $B$ ou seja, $A \not\subset B$

* Dados $S$ e $T$ conjuntos não vazios
* $S \times T = \{(s, t) | s \in S e\ t \in T\}$

$(s, t)$ é chamado **par ordenado**
$S \times T$ lê-se $S$ cartesiano $T$

Ex:

* $S = \{1, 2, 3\}$
* $T = \{0 , 1\}$
* $S \times T = \{(1, 0), (1, 1), (2, 0), (2, 1), (3, 0), (3, 1)\}$

## Funções ou Aplicações

Definição: Sejam $S$ e $T$ conjuntos não vazio. Uma **função** (ou aplicação) $f$ de $S$ em $T$, denotada por $f:S \rightarrow T$, é um subconjunto de $S \times T$ tal que cada elemento do $S$ aparece exatamente uma vez como a primeira componente de um par ordenado.

* $S$ é o domínio e $T$ é o contradomínio da função.
* Se $(s, t) \in f$, então denotamos $t = f(s)$, $t$ é a imagem de $s$ dada pela função $f$.

Notação:

* $D(f) = \{s \in S | \exists t \in T : (s, t) \in f\}$
* $CD(f) = T$
* $Im(f) = f(S) = \{t \in T | t = f(s)$ para algum $s \in S\} \subseteq D(f)$