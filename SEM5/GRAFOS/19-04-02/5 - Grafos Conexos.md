# Grafos Conexos

## Definição

Um grafo é dito **conexo** se existir pelo menos um caminho entre cada par de vértices do grafo. Caso contrário, o grafo é chamado de desconexo.

Cada um dos subgrafos conexos maximais de um grafo desconexo é chamado de uma **componente** do grafo. Ou seja, uma componente é um subgrafo conexo que não esteja estritamente contido em outros subgrafos conexos.[^1]

[^1]: Sejam $S$ e $S'$ tais que $S' \subset S$. $S'$ é maximal em relação a uma propriedade $P$ quando $S'$ satisfaz $P$ e não existe $S'' \supset S'$ que também satisfaça $P$.

Dado um grafo qualquer, como determinar se o grafo é conexo?

### Teorema

Um grafo $G(V, A)$ é desconexo se, e somente se, seu conjunto de vértices $V$ puder ser particionado em dois conjuntos disjuntos e não-vazios, $V_{1}$ e $V_{2}$, de forma que não exista uma aresta com uma extremidade em $V_{1}$ e outra extremidade em $V_{2}$.

**Demonstração**: [$\Rightarrow$] Suponhamos que $G$ seja desconexo e mostremos que existe uma partição de $V$, $V_{1}$ e $V_{2}$, tal que não existe uma aresta com uma extremidade em $V_{1}$ e outra extremidade em $V_{2}$.

Considere um vértice $v \in V$ qualquer. Forme o conjunto $V_{1}$ com todos os vértices de $V$ que estejam ligados a $v$ por um caminho. Como $G$ é desconexo, $V_{1}$ não contém todos os vértices de $G$. Assim os vértices restantes formam um conjunto não-vazio $V_{2}$, e não existe nenhuma aresta de $G$ com uma extremidade em $V_{1}$ e outra em $V_{2}$. Assim $V_{1}$ e $V_{2}$ formam a partição desejada.

[$\Leftarrow$] Suponhamos que exista uma partição de $V$, $V_{1}$ e $V_{2}$, tal que não existe uma aresta com uma extremidade em $V_{1}$, e outra extremidade em $V_{2}$ e mostraremos que $G$ é desconexo.

Considere dois vértices arbitrários $v, w \in V$ tais que $v \in V_{1}$ e $w \in V_{2}$. Não pode existir nenhum caminho entre $v$ e $w$, pois se existisse, haveria uma aresta com uma extremidade em $V_{1}$ e outra em $V_{2}$. Portanto se uma partição existe então o grafo e desconexo.

Cada vértice pode ser ligado por uma aresta a cada um dos outros vértices do grafo, isto é, aos outros ($n - 1$). Isto nos dá ($n - 1$) arestas. Como existem $n$ vértices, teremos então $n(n - 1)$ arestas. No entanto, cada aresta interliga dois vértices e portanto está sendo considerado duas vezes. Assim, para obtermos o número correto de arestas é necessário dividir o valor que temos até o momento por 2. O número máximo de arestas é então:

$$
    n(n - 1) / 2
$$

### Teorema

Seja $G$ um grafo simples com $n$ vértices. Se $G$ possui $k$ componentes, então o número $m$ de arestas de $G$ satisfaz

$$
    n - k \leq m \leq (n - k)(n - k + 1) / 2
$$

**Demonstração**: Vamos provar que $m \geq n - k$ por indução sobre o número de arestas de G. É claro que o resultado é verdadeiro para um grafo nulo ($m = 0$). Suponha que a desigualdade é verdadeira para todo grafo com menos do que $m_{0}$ arestas, onde $m_{0}$ é um inteiro positivo. Vamos supor ainda, sem perda de generalidade, que $G$ possui o menor número de arestas possível, no sentido de que a retirada de qualquer aresta de $G$ aumenta o número de componentes em uma unidade. Neste caso, o grafo resultante teria os mesmos $n$ vértices, $k + 1$ componentes e $m_{0} - 1$ arestas. Segue da hipótese de indução que

$$
    m_{0} - 1 \geq n - (k + 1) \Leftrightarrow m_{0} \geq n - k
$$

Agora mostremos que vale a segunda desigualdade, supondo, sem perda de generalidade, que cada componente de $G$ é um grafo completo. Suponhamos que existem dois componentes $C_{i}$ e $C_{j}$ com $n_{i}$ e $n_{j}$ vértices, respectivamente, onde $n_{i} \geq n_{j} > 1$. Se trocarmos $C_{i}$ e $C_{j}$ por grafos completos com $n_{i} + 1$ e $n_{j} - 1$ vértices, então o número total de vértices permanece o mesmo, e o número de arestas é alterado para

$$
    \frac{(n_{i} + 1) n_{i} - n_{i} (n_{i} - 1)}{2} - \frac{n_{j} (n_{j} - 1) - (n_{j} - 1) (n_{j} - 2)}{2} = n_{i} - n_{j} + 1 > 0
$$

Segue que, para que o número máximo de arestas seja atingido, $G$ deve consistir de um grafo completo com $n - (k - 1)$ vértices e $k - 1$ vértices isolados.