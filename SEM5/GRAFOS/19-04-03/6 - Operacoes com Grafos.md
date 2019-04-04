# Operações com Grafos

## Definição

A **união** de dios grafos $G_{1}(V_{1}, A_{1})$ e $G_{2}(V_{2}, A_{2})$ é um grafo $G_{3}(V_{3}, A_{3})$ onde:

$$
    G_{3} = G_{1} \cup G_{2},\ V_{3} = V_{1} \cup V_{2}\ e\ A_{3} = A_{1} \cup A_{2}.
$$

## Definição

A **intersecção** de dois grafos $G_{1}(V_{1}, A_{1})$ e $G_{2}(V_{2}, A_{2})$ é um grafo $G_{3}(V_{3}, A_{3})$ onde:

$$
    G_{3} = G_{1} \cap G_{2},\ V_{3} = V_{1} \cap V_{2}\ e\ A_{3} = A_{1} \cap A_{2}.
$$

### Observação

Pelas definições dadas é fácil verificar que as operações de união e intersecção de grafos são comutativas, isto é:

$$
    G_{1} \cup G_{2} = G_{2} \cup G_{1},
    G_{1} \cap G_{2} = G_{2} \cap G_{1}.
$$

## Definição

Um grafo $G$ é dito **decomposto** em dois sub-grafos $G_{1}$ e $_{2}$ se:

$$
    G_{1} \cup G_{2} = G\ e\ G_{1} \cap G_{2} = grafo\ nulo.
$$

Ou seja, cada aresta de $G$ pertence a $G_{1}$ ou a $G_{2}$. Alguns vértices no entanto podem pertencer aos dois.

## Definição

Se $a$ é uma aresta de um dado grafo $G$, então $G - a$ é um sub-grafo de $G$ obtido pela remoção da aresta $a$ do grafo $G$.

Se $v$ é um vértice de $G$, então $G - v$ é um sub-grafo de $G$ obtido pela remoção do vértice $v$ do grafo $G$.

* A remoção de um vértice implica na remoção das arestas a ele incidentes.

De maneira similar é possível incluir vértices e arestas em um grafo.

## Definição

A **soma** de dois grafos $G_{1}(V_{1}, A_{1})$ e $G_{2}(V_{2}, A_{2})$ é um grafo $G_{3}(V_{3}, A_{3})$ onde:

$$
    G_{3} = G_{1} + G_{2},
    V_{3} = V_{1} \cup V_{2}\ e\ A_{3} = A_{1} \cup A_{2} \cup \{(v_{i}, v_{j}):\ v_{i} \in V_{1}, v_{j} \in V_{2}\}.
$$

## Definição

A **soma direta** de dois grafos $G_{1}(V_{1}, A_{1})$ e $G_{2}(V_{2}, A_{2})$ é um grafo $G_{3}(V_{3}, A_{3})$ onde:

$$
    G_{3} = G_{1} \oplus G_{2}, V_{3} = V_{1} \cup V_{2}\ e\ A_{3} = [ \,A_{1} \cup A_{2}] \, \backslash [ \,A_{1} \cap A_{2}] \,.
$$

## Definição

A **fusão** de um par de vértices $a$ e $b$ em um Grafo $G$ é feita substituindo os dois vértices por um único vértice $\overline{ab}$, de tal forma que toda aresta que era incidente no vértice $a$ e/ou no vértice $b$ ou em ambos passa a ser incidente no novo vértice $\overline{ab}$.

### Observação

A fusão de vértices em um grafo não altera seu número de arestas, apenas diminui o número de vértices.

## Definição

A **contrção de dois vértices** $a$ e $b$ é feita através da fusão dos vértices $a$ e $b$ e a remoção dos loops e arestas paralelas que são formadas no processo.

## Definição

A **contração de uma aresta** $(a, b)$ é feita removendo-se a aresta $(a, b)$ e fazendo a fusão dos vértices $a$ e $b$. É denotado por $G \backslash (a, b)$.