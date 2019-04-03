# Caminhos e Circuitos

## Subgrafos

### Definição

Um grafo $H(V', A')$ é um **subgrafo** de um grafo $G(V, A)$ se todos os vértices e todas as arestas de $H$ pertencem a $G$ e cada aresta de $H$ possui as mesmas extremidades que em $G$ (isto é, $V' \subseteq V, A' \subseteq A)$. Usamos a mesma notação usada para conjuntos, isto é, $H \subset G$.

**Observação**: As seguintes observações podem ser feitas:
* Todo grafo é um subgrafo de si próprio.
* Um subgrafo de um subgrafo de um grafo $G$ também é um subgrafo de $G$.
* Um vértice de um grafo $G$ é um subgrafo de $G$.
* Uma aresta (e os vértices aos quais ela é incidente) de um grafo $G$ é um subgrafo de $G$.

### Definição

Dois subgrafos de um grafo $G$, $G_{1}$ e $G_{2}$, são **aresta-disjuntos** se eles não possuem arestas em comum. Se $G_{1}$ e $G_{2}$ não possuírem vértices em comum, os dois subgrafos são chamados de **vértice-disjuntos**.

## Trajetos, Caminhos e Circuitos

Vamos discutir aqui alguns tipos especiais de subgrafos de um grafo $G$. Quando discutimos o problema das Pontes de Königsbergh, estávamos interessados em deterinar um roteiro que passasse por todas as pontes apenas uma vez. Se estudarmos este poblema através de grafos, vamos precisar de alguns conceitos para achar a solução do problema.

### Definição

Dado um grafo $G(V, A)$, um **passeio** (ou uma **trilha**) em $G$ consiste de uma sequência finita alternada de vértices e arestas, começando e terinando por vértices, tal que cada aresta é incidente ao vértice que a precede e ao que a sucede.

### Definição

Dado um grafo $G(V, A)$, um **trajeto** em $G$ consiste de uma sequência finita alternada de vértices e arestas, começando e terminando por vértices, tal que cada aresta aparece apenas uma vez e é incidente ao vértice que a precede e ao que a sucede.

### Definição

Dado um grafo $G(V, A)$, um **caminho** em G consiste de uma sequência finita alternada de vértices e arestas, começando e terminando por vértices, tal que cada aresta é incidente ao vértice que a precede e que a sucede e não há repetição de vértices.

**Observação**: Em grafos simples podemos mencionar um caminho ou trajeto listando apenas os vértices (ou arestas), sem menção explícita às arestas (ou aos vértices).

### Definição

Um trajeto no qual o vértice inicial e o final são iguais é chamado de **trajeto fechado**.

### Definição

Um trajeto fechado no qual nenhum vértice (com exceção do inicial e do final) aparece mais de uma vez é chamada de **ciclo** (**circuito** ou **caminho fechado**).