# Conceitos Iniciais

## Definição

Seja $G(V, A)$ um grafo. Dada uma aresta $a = (v_{i}, v_{j}) \in A$, dizemos que:

* a) $v_{i}$ e $v_{j}$ são os extremos da aresta $a$;
* b) a aresta $a$ é dita ser **incidente** nos vértices $v_{i}$ e $v_{j}$;
* c) $v_{i}$ e $v_{j}$ são chamados de **vértices adjacentes**;
* d) se $v_{i} = v_{j}$ a aresta $a$ é chamada de **loop** (ou **laço**);
* e) se existir uma aresta $f = (v_{k}, v_{t})$ tal que $v_{k} = v_{i}$ e $v_{j} = v_{t}$, as arestas $a$ e $f$ são chamadas de **arestas paralelas** (ou **múltiplas**). Grafos que contém arestas paralelas, às vezes, são chamados de multi-grafos.

## Definição

Um grafo é **simples** se não possui loops e/ou arestas paralelas.

## Definição

Duas areas são ditas **adjacentes** se elas incidem no mesmo vértice.

## Definição

O **grau** de um vértice $v, d(v)$, em um grafo sem loops é determinado pelo número de arestas incidentes em $v$. Caso haja loops, estas arestas contribuem com grau 2.

## Definição

A **sequência de graus** de um grafo $G$ é a sequência não-decrescente formada pelos graus dos vértices de $G$.

## Definição

Dizemos que:

* a) Um vértice $v$ é **isolado** se $d(v) = 0$.
* b) Um vértice $v$ é **pendente** se $d(v) = 1$.
* c) Um grafo $G(V, A)$ é dito **nulo** se o conjunto de arestas $A$ é vazio. É representado por $N_{n}$, onde $n$ é o número de vértices do grafo.
* d) Um grafo $G(V, A)$ é dito **regular** se todos os seus vértices tem o mesmo grau.
* e) Um grafo $G(V, A)$ é dito **completo** se existe uma aresta entre cada par vértices. É representado por $K_{n}$, onde $n$ é o número de vértices do grafo.
* f) Um grafo $G(V, A)$ em que $V = {v_{1}, v_{2},...,v_{n}}$ e $A = {(V_{1}, v_{2}), (v_{2}, v_{3}),...,(v_{n-1}, v_{n})}$ é dito ser um **caminho**. É representado por $P_{n}$.
* g) Um grafo $G(V, A)$ em que $V = {v_{1}, v_{2},..., v_{n}}$ e $A = {(v_{1}, v_{2}), (v_{2}, v_{3}),..., (v_{n-1}, v_{n}), (v_{n}, v_{1})}$ é dito ser um **ciclo** (ou **circuito**). É representado por $C_{n}$.
* h) Um grafo $G(V, A)$ é dito **valorado** (ou é chamado de **rede**) se são atribuídos valores para os vértices e/ou arestas.
* i) Um grafo $G(V, A)$ em que $V = V_{1} \cup V_{2}$, $V_{1} \cap V_{2} = \emptyset$, e para toda aresta $(v, w) \in A$ tem-se $v \in V_{1}$ e $w \in V_{2}$ é dito ser um **grafo bipartido**.
* j) Um grafo bipartido $G(V_{1} \cup V_{2}, A)$ é dito ser **bipartido completo** se $(v, w) \in A$ para todos $v \in V_{1}$ e $w \in V_{2}$. Neste caso, é representado por $K_{p,q}$, onde $p$ é o número de vértices de $V_{1}$ e $q$ é o número de vértices $de V_{2}$.
* k) Dado um grafo $G$, o seu complemento, representado por $\bar{G}$, é o grafo tal que $V(\bar{G}) = V(G)$ e $A(\bar{G}) = A(K_{n}) \ A(G)$, onde $n$ é o número de vértices de $G$.

## Proposição

Dado um grafo G com n vértices, $v_{1}, v_{2},..., v_{n}$ e m arestas, temos que:

* $\sum_{i=1}^{n}d(v_{i}) = 2m$.

Por que este resultado é válido? Observe que cada aresta contribui com 2 graus na soma dos graus de todos os vértices, ou seja, cada aresta é contada duas vezes. Assim, a soma é igual a duas vezes o número de arestas.

## Teorema

O número de vértices de grau ímpar em um grafo é sempre par.

Demonstração. Vamos dividir a soma em duas parcelas. Os vértices com grau par e os vértices com grau ímpar:

* $\sum_{i=1}^{n}d(v_{1}) = \sum_{v_{1}\ tem\ grau\ par}d(v_i) + \sum_{v_{i}\ tem\ grau\ ímpar}d(v_{i})$.

O lado esquerdo da equação é par. A primeira parcela do lado direito também é par, pois é a soma de números pares. Para que a igualdade seja válida, a segunda parcela também deve ser par:


* $\sum_{v_{i}\ tem\ grau\ ímpar}d(v_{i})$ é par.

Como cada parcela $d(v_{i})$ é ímpar temos que ter um número par de elementos para que a soma seja um número par (lembre-se que um número ímpar é da forma ($2k + 1$)).