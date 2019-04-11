# Representação de Grafos

A representação computacional de um grafo (ou digrafo) deve usar uma estrutura que:

* corresponde de forma única a um grafo dado;
* pode ser armazenado e manipulado em um computador.

A representação gráfica de um grafo através de um diagrama de pontos e linhas não satisfaz a segunda condição acima.

Vamos discutir a seguir algumas estruturas que satisfazem estes dois critérios.

Considere um grafo $G(V, A)$ com $n$ vértices e $m$ arestas.

## Matriz de Adjacência

A matriz de adjacência é uma matriz $n \times m$, denotada por $X = [ \,x_{ij}] \,$ e definida como:

$$
    x_{ij} = 
    \begin{cases}
        1 & \text{se existe uma aresta entre os vértices } v_{i} \text{ e } v_{j}, \\
        0 & \text{caso contrário}.
    \end{cases}
$$

**Observações**:

* É necessário fazer uma rotulação nos vértices de $G$.
* A complexidade em termos de espaço de memória de um algoritmo que use uma matriz de adjacência para armazenar o grafo é $O(n^{2})$.
* Qualquer tipo de grafo pode ser armazenado nesta estrutura?
    * Não! Apenas grafos que não possuam arestas paralelas.
* As entradas ao longo da diagonal principal de $X$ são todas nulas se, e somente se, o grafo não possui laços. Quando há um laço em um vértice $v_{i}$ temos $x_{ii} = 1$.
* Se o grafo é simples, o grau de um vértice é dado pela soma dos elementos de sua linha (ou coluna) correspondente.
* Permutações de linhas e das colunas correspondentes implicam em uma reordenação dos vértices. Portanto dois grafos simples $G_{1}$ e $G_{2}$ são isomorfos se, e somente se, $X(G_{2}) = R^{-1}X(G_{1})R$, onde $R$ é uma matriz de permutação.
* Dado uma matriz qualquer $Q \in \mathbb{R}^{n \times n}$ simétrica e binária, sempre é possível contruir um grafo $G$ com $n$ vértices tal que $X(G) = Q$.
* Quantos elementos diferentes de zero esta matriz possui?
* Um grafo $G$ é desconexo com dois componentes $G_{1}$ e $G_{2}$ se, e somente se,

$$
    X(G) = \begin{bmatrix}
        X(G_{1}) & 0 \\
        0 & X(G_{2})
    \end{bmatrix}.
$$

* O que representa a matriz $B = X^{2}$? Os elementos $b_{ij}$, $i \neq j$, representam o número de caminhos distintos de comprimento 2 entre os vértices $v_{i}$ e $v_{j}$. De fato:

$$
    b_{ij} = \sum_{k = 1}^{n} x_{ik} x_{kj} = x_{i1} x_{1j} + x_{i2} x_{2j} + \ldots + x_{in} x_{nj}
$$

e existe um caminho se $x_{ik} = x_{kj} = 1$, e o caminho é dado por $\{i, (i, k), k, (k, j), j\}$.

### Teorema

Seja $X$ a matriz de adjacência de uma grafo simples $G$. Então a $ij$-ésima entrada de $X^{r}$ é o número de passeios diferentes de comprimento $r$ entre os vértices $v_{i}$ e $v_{j}$.

### Corolário

Em um grafo conexo, a distância entre dois vértices $v_{i}$ e $v_{j}$, $i \neq j$, é $k$ se, e somente se, $k$ é o menor inteiro para o qual a $ij$-ésima entrada em $X^{k}$ é não-nula.

### Corolário

Se $X$ é a matriz de adjacência de um grafo com $n$ vértices, e

$$
    Y = X + X^{2} + X^{3} + \ldots + X^{n - 1},
$$

então $G$ é desconexo se, e somente se, existe ao menos uma entrada na matriz $Y$ que é igual a zero.

É possível utilizar esta estrutura para armazenar digrafos?

Sim. Dado um digrafo $D(V, A)$ com $n$ vértices e sem arestas paralelas, definimos

$$
    x_{ij} = \begin{cases}
        1 & \text{se existe uma aresta direcionada do vértice } v_{i} \text{ para o vértice } v_{j}, \\
        0 & \text{caso contrário}.
    \end{cases}
$$

### Observações

* Neste caso a matriz só será simétrica se o digrafo for simétrico.
* O grau de saída do vértice $v_{i}$ é dado pela soma dos elementos da linha $i$.
* O grau de entrada do vértice $v_{i}$ é dado pela soma dos elementos da coluna $i$.
* Se $X$ é a matriz de adjacência de um digrafo $D$, então a sua transposta $X^{T}$ é a matriz de adjacência do digrafo obtido pela inversão da orientação das arestas de $D$.

## Matriz de Incidência

Seja $G$ um grafo com $n$ vértices e $m$ arestas. Sua matriz de incidência é uma matriz de ordem $n \times m$, denotada por $A = [ \,a_{ij}] \,$, definida como

$$
    x_{ij} = \begin{cases}
        1 & \text{se a aresta } a_{j} \text{ é incidente no } v_{i}, \\
        0 & \text{caso contrário}.
    \end{cases}
$$

### Observações

* É necessário fazer uma rotulação nos vértices e nas arestas de $G$.
* A complexidade em termos de espaço de memória de uma algoritmo que use uma matriz de adjacência para armazenar o grafo é $O(nm)$.
* Qualquer tipo de grafo pode ser armazenado nesta estrutura?
    * Não! Apenas grafos que não possuam arestas laço.
* Como cada aresta é incidente em exatamente dois vértices, cada coluna de $A(G)$ possui exatamente dois 1's.
* O número de 1's em cada linha é igual ao grau do vértice correspondente.
* Uma linha de 0's representa um vértice isolado.
* Arestas paralelas correspondem a colunas idênticas.
* Se $G$ é um grafo desconexo com dois componentes $G_{1}$ e $G_{2}$, então

$$
    A(G) = \begin{bmatrix}
        A(G_{1}) & 0 \\
        0 & A(G_{2})
    \end{bmatrix}.
$$

* Dois grafos $G_{1}$ e $G_{2}$ são isomorfos se, e somentes se, suas matrizes de incidêcia $A(G_{1})$ e $A(G_{2})$ diferem apenas por permutações de linhas e colunas.
* Quantos elementos diferentes de zero esta matriz possui?

É possível utilizar esta estrutura para armazenar digrafo?

Sim. Com uma pequena modificação, uma vez que ao dizer que uma aresta incide em um vértice é necessário especificar se ela converge para ou diverge para este vértice.

Seja $D$ um digrafo com $n$ vértices e $m$ arestas e sen arestas laço. Sua matriz de incidência $A = [ \,a_{ij}] \, \in \mathbb{R}^{n \times m}$ é definida como

$$
    x_{ij} = \begin{cases}
        1 & \text{se a aresta } a_{j} \text{ diverge do vértice } v_{i}, \\
        -1 & \text{se a aresta } a_{j} \text{ converge para o vértice } v_{i}, \\
        0 & \text{caso contrário}.
    \end{cases}
$$

As duas representações dadas (matrizes de adjacência e de incidência) são importantes porque elas facilitam a recuperação de uma série de informações a respeito de um grafo.

Por exemplo, o grau de um vértice, determinar se dois vértices são adjacentes, entre outras.

No entanto ela não valem para qualquer grafo dado, e demandam muito espaço d memória: $O(n^{2})$ e $O(nm)$ para armazenar apenas $2m$ elementos diferentes de zero.

É possível encontrar formas mais eficientes de armazenamento de dados.

É bom salientar no entanto que a melhor maneira de armazenar um grafo ou digrafo vai depender do algoritmo a ser implementado.

## Lista de Arestas

O digrafo (ou grafo) $G$ é representado por dois vetores $m$-dimensionais $F = (f_{1}, f_{2}, \ldots , f_{m})$ e $H = (h_{1}, h_{2}, \ldots , h_{m})$.

Cada elemento destes vetores recebe o rótulo de um vértice, de modo que a $i$-ésima aresta diverge do vértice $f_{i}$ e converge para o vértice $h_{i}$.

Se $G$ é não-direcionado, os vetores são definidos da mesma forma, apenas desconsidere os termos "converge" e "diverge".

Qual é o espaço necessário para esta estrutura? $O(2m)$.

## Lista de Sucessores

Quando a razão $m/n$ não é muito alta, é conveniente usar uma lista de sucessores.

Para isto definimos $n$ vetores. Cada vetor é associado a um vértice.

O primeiro elemento do vetor $k$ é o vértice $v_{k}$ e os demais elementos são os vértices adjacentes ao vértice $v_{k}$.

Em um digrafo, os vértices que possuem um caminho direcionado de comprimento um a partir de $v_{k}$.

Supondo que $d_{med}$ é o grau médio (ou grau de saída médio), o espaço de memória necessário para esta estrutura é $O(nd_{med})$.