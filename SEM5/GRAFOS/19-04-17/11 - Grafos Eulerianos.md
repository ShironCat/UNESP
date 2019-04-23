# Grafos Eulerianos

## Introdução

No ínicio do curso nós estudamos o problema das Pontes de Konigsberg

Queríamos saber se é possível fazer um passeio pela cidade, começando e terminando no mesmo lugar e passando por cada uma das pontes apenas uma vez.

**Em outras palavras queríamos encontrar no grafo acima um trajeto que incluísse todas as arestas do grafo.**

### Definições

#### Definição

Um trajeto que inclua todas as arestas de um dado grafo $G(V, A)$ é chamado de **trajeto euleriano**.

Seja $G$ um grafo conexo. Dizemos que $G$ é **euleriano** se possui um trajeto euleriano fechado.

Um grafo $G$ não-euleriano é dito ser **semi-euleriano** se possui um trajeto euleriano.

#### Observação

Note que em um grafo euleriano cada aresta é percorrida um, e uma única, vez.

### Resultado auxiliar

#### Lema

Se $G(V, A)$ é um grafo tal que $d(v) \geq 2$ para todo $v \in V$, então $G$ contém um ciclo.

#### Demonstração

Se $G$ possui laços ou arestas paralelas, não há o que provar.

Vamos supor que $G$ é um grafo simples. Seja $v_{0} \in V$ um vértice arvitrário de $G$. Como $d(v) \geq 2$ para todo $v \in V$, podemos construir um passeio $v_{0} \rightarrow v_{1} \rightarrow \ldots$ indutivamente, escolhendo $v_{i + 1}$ como sendo qualquer vértice adjacente a $v_{i}$ exceto $v_{i - 1}$.

Como $G$ possui uma quantidade finita de vértices, em algum momento escolheremos algum vértice, digamos $v_{k}$, pela segunda vez.

A parte do passeio entre a primeira e a segunda ocorrência de $v_{k}$ constitui um ciclo.

### Condição necessário e suficiente

#### Teorema (Euler, 1736)

Um grafo conexo $G(V, A)$ é euleriano se, e somente se, o grau de cada vértice de $G$ é par.

#### Demonstração ($\Rightarrow$)

Seja $T$ um trajeto euleriano fechado de $G$. Cada vez que um vértice $v$ ocorre no trajeto $T$, há uma contribuição de duas unidades para o grau de $v$ (uma aresta para chegar a $v$ e outra para sair).

Isto vale não só para os vértices intermediários mas também para o vértice final, pois "saímos" e "entramos" no mesmo vértice no início e no final do trajeto.

Como cada aresta ocorre extamente uma vez em $T$, cada vértice possui grau par.

#### ($\Leftarrow$)

A prova é por indução no número de arestas de $G$. Suponhamos que o grau de cada vértice de $G$ é par. Como $G$ é conexo, $d(v) \geq 2$ para todo $v \in V$. Segue então do lema anterior que $G$ contém um ciclo $C$.

Se $C$ contém todas as arestas de $G$, o teorema está provado.

Se não, removemos de $G$ as arestas de $C$, resultando num grafo $H$, possivelmente desconexo, com menos arestas do que $G$.

####  

É fácil ver que todos os vértices de $H$ possuem grau par. Logo, pela hipótese de indução, cada componente de $H$ possui um trajeto euleriano fechado.

Além disso, pela conexidade de $G$, cada componente de $H$ possui ao menos um vértice em comum com $C$.

Portanto, concatenando os trajetos eulerianos fechados de cada compoennte de $H$ com o ciclo $C$ obtemos um trajeto euleriano fechado em $G$, ou seja, $G$ é um grafo euleriano.

### Algoritmo de Fleury (Fleury, 1883)

Considere um grafo conexo $G(V, A)$, onde $d(v)$ é par $\forall v \in V$.

Comece em qualquer vértice $v$ e percorra as arestas de forma aleatória, seguindo sempre as seguintes regras:

* Exclua as arestas depois de passar por elas;
* Exclua os vértices isolados, caso ocorram;
* Passe por uma ponte[^1] somente se não houver outra alternativa.

[^1]: Uma aresta é dita ser uma **ponte** se a sua remoção torna o grafo desconexo.

## Digrafos Eulerianos

### Definições

#### Definição

Um trajeto **orientado** que inclua todas as arestas de um dado digrafo $G(V, A)$ é chamado de **trajeto euleriano**.

Seja $G$ um digrafo conexo (fortemente ou fracamente). Dizemos que $G$ é **euleriano** se possui um trajeto euleriano fechado.

Um digrafo $G$ não-euleriano é dito ser **semi-euleriano** se possui um trajeto euleriano.

### Teorema de Euler para digrafos

#### Teorema

Um digrafo $D(V, A)$ é euleriano se, e somente se, $D$ é balanceado (i.e., $d_{e}(v) = d_{s}(v) \forall v \in V$).

#### Corolário

Um digrafo $D(V, A)$ é semi-euleriano se, e somente se, existem dois vértices $x, y \in V$ tais que

$$
    d_{s}(x) - d_{e}(x) = 1, d_{e}(y) - d_{s}(y) = 1
$$

e

$$
    d_{e}(v) = d_{s}(v) \forall v \in V \\ \{ x, y \}.
$$

## O Problema Chinês do Carteiro

### Definição do problema

O Problema Chines do Carteiro foi postulado em 1962 pelo matemático chinês Mei-Ku Kwan:

Considere um grafo valorado (ou rede) $G$ tal que os pesos das arestas sçao não-negativos. Encontre um passeio fechado que percorra todas as arestas de $G$ com peso total mínimo.

**Aplicações:**

1. Coleta de lixo;
2. Entregas;
3. Limpeza de ruas;
4. Checagem de páginas da interne:

### Exemplo de [Maarten van Steen, Graph Theory and Complex Networks]

Checking a Web site: Typically, a Web site consists of numerous pages, in turn containing links to each other. As is so often the case, most Web sites are notoriosly poor at having their links maintained to the correct pages. This is often due to the simple reason that so many people are responsible for maintaining their part of a site. Apart from links that are broken (i.e., refer to nonexisting pages), it is often necessary to manually check how pages are linked to each other.

Graph theory can help by modeling a Web site as an undirected graph where a page is represented by a vertex and a link by an edge having weight 1. Note that we are not using a directed graph, as we may need to cross a link in reverse order, for example, when goig back to the original page. If a site is to be manually inspected, then we are seeking a solution to navigate through a site, but with preferably crossing a link at most once. This is now the same as finding a directed walk containing all edges of minimal length.

### Algoritmo [Gibbons, 1985]

Considere um grafo valorado conexo $G$ em que o conjunto de vértices de grau ímpar é $V_{impar} = \{ v_{1} , \ldots , v_{2k} \}$, onde $k \geq 1$.

1. Para cada par $( v_{i} , v_{j} ) \in V_{impar} \times V_{impar}$ com $v_{i} \neq v_{j}$, encontre o caminho mínimo $P_{ij}$ entre $v_{i}$ e $v_{j}$.
2. Construa um grafo completo com os $2k$ vértices de $V_{impar}$ em que o peso da aresta $( v_{i} , v_{j} )$ é o peso do caminho mínimo $P_{ij}$.
3. Determine o conjunto $E = \{ e_{1} , e_{2} , \ldots , e_{k} \}$ de $k$ arestas do grafo completo, duas a duas não-adjacentes, tal que a soma de seus pesos seja a mínima.
4. Para cada aresta $e = ( v_{i} , v_{j} ) \in E$, duplique as arestas de $P_{ij}$ em $G$.