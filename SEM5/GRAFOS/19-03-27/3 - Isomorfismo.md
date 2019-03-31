# Isomorfismo

Nós já vimos que é possível representar um mesmo grafo de várias maneiras. Como determinar se dois grafos são equivalentes, ou seja, se possuem as mesmas propriedades? Isto é, como determinar se dois grafos são isomorfos? A palavra isomorfismo vem do grego *iso* (mesmo) e *morfo* (mesma forma).

## Definição

Dizemos que dois grafos $G$ e $H$ são **isomorfos** se existir uma correspondência biunívuca entre os vértices de $G$ e os vértices de $H$ que preserve a relação de adjacência entre vértices e arestas. Em outras palavras, é possível obter o grafo $H$ a partir de uma nova rotulação dos vértices de $G$.

**Aplicações:** O estudo de isomorfismo pode ser aplicado na descoberta de novos compostos orgânicos. Os químicos mantém uma tabela de compostos orgânicos. Cada vez que um novo composto é descoberto é necessário determinar se ele é isomorfo a algum composto já existente.

Determinar se dois grafos são isomorfos não é uma tarefa muito simples. De fato, a determinação de isomorfismos é uma área de intensa pesquisa em teoria dos grafos. Condições necessárias para que dois grafos sejam isomorfos são facilmente determinadas.

## Proposição

(Condições necessárias para isomorfismo). Sejam $G$ e $H$ grafos dados. Se $G$ e $H$ são isomorfos, então:

1. $G$ e $H$ devem possuir o mesmo número de vértices;
2. $G$ e $H$ devem possuir o mesmo número de arestas;
3. $G$ e $H$ devem possuir o mesmo número de vértices com um determinado grau.

As condições 1, 2 e 3 são suficientes para garantir o isomorfismo entre dois grafos? A resposta é NÃO!