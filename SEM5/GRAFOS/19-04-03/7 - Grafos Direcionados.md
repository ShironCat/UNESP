# Grafos Direcinados

## Introdução

* Até o momento trabalhamos com grafos tais que as arestas são pares não ordenados de vértices
* Várias situações práticas requerem que associemos sentido às arestas do grafo.
* Por exemplo, considere um grafo representando as ruas de uma cidade. Nem todas as ruas são de mão dupla. Ao se estudar rotas de ônibus é necessário considerar se as ruas são de mão única, isto é, permitem fluxo apenas no sentido $(v_{i}, v_{j})$ ou se são de mão dupla.
* Outras situações são: fluxograma de programas computacionais onde os vértices representam instruções e as arestas a sequência de execução; redes elétricas; fluxos em redes que possuem válvulas nos encanamentos.
* Quando associamos sentido às arestas do grafo temos um **grafo direcionado** ou **digrafo**.
* A maioria dos conceitos e terminologia usados para grafos não-orientados são também aplicados para digrafos.
* Por exemplo, o conceito de planaridade independe do sentido associado às arestas.

Vamos chamar atenção neste tópico apenas para as propriedades e conceitos que se aplicam apenas a digrafos.

O conceito formal de um grafo direcionado é dado a seguir.

## Digrafos

### Definição

Um **grafo direcionado** $G(V, A)$ é constituido por um conjunto $V = \{v_{1}, v_{2}, \ldots, v_{n}\}$ não-vazio de objetos, chamados vértices (ou nós), e um conjunto $A = \{a_{1}, a_{2}, \ldots, a_{m}\}$ de arestas ou arcos, e uma aplicação $\Psi$ que associa cada aresta a um par ordenado de vértices.

Os digrafos são representados através de um diagrama onde os vértices são representados por pontos e cada aresta $(v_{i}, v_{j})$ é representada por uma linha ligando $v_{i}$ a $v_{j}$ com uma seta apontando para $v_{j}$.

## Grau de vértices

Em um digrafo, quando dizemos que uma aresta é incidente a um vértice queremos saber em que sentido, isto é, se a aresta é convergente ou divergente a este vértice.

É natural dizer que uma aresta $a$ associada ao par $(v_{i}, v_{j})$ é convergente a $v_{j}$ e divergente de $v_{i}$.

Em relação ao grau de um vértice $v_{i}$ queremos também saber:
* o número de arestas convergentes, chamado **grau de entrada** e denotado $d_{e}(v_{i})$ (ou $d^{-}(v_{i})$);
* o número de arestas divergentes, chamado **grau de saída** e denotado $d_{s}(v_{i})$ (ou $d^{+}(v_{i})$).

## Mais definições

* Temos uma **fonte** quando o grau de entrada é nulo e um **sumidouro** quando o grau de saída é nulo.
* Duas arestas são **paralelas** se elas incidem nos mesmos vértices e possuem a mesma orientação.
* Muitas das propriedades de grados não orientados são válidas para digrafos e portanto muitas vezes a orientação do grafo e desconsiderada.
* Definimos o **grafo associado** a um grafo $G$ como sendo o grafo obtido desconsiderando a orientação de $G$.

## Orientação de um grafo

A operação oposta também pode ser considerada:

Dado um grafo (não orientado) $G$ podemos definir alguma orientação para suas arestas obtendo assim um digrafo $\overrightarrow{G}$ chamado de um **digrafo associado** a $G$.

* Observemos que enquanto o grafo associado a um digrafo é único (a menos de isomorfismos), um digrafo associado a um grafo pode ter várias orientações distintas.

## Digrafos Isomorfos

Dados digrafos $G$ e $H$, dizemos que eles são **isomorfos** quando os grafos associados são isomorfos e além disso a orientação das arestas coincide.

## Tipos de digrafos

Seja $G(V, A)$ um digrafo. Então $G$ é dito:
* **Simples** se não possui loops ou arestas paralelas;
* **Assimétrico** se possui no máximo uma aresta **orientada** entre cada par (não-ordenado) de vértices;
    * Grafos assimétricos podem ter loops;
* **Simétrico** se para cada aresta $(a, b)$ existe também uma aresta $(b, a)$;
* **Completo Simétrico** se $G$ é simples e existe exatamente uma aresta de todo vértice para todos os outros vértices;
* **Completo Assimétrico** se $d_{e}(v_{i}) = d_{s}(v_{i})$ para todo $v_{i} \in V$;
* **Regular** se existe um inteiro $k$ tal que $d_{e}(v_{i}) = d_{s}(v_{i}) = k$ para todo $v_{i} \in V$. Dizemos que o digrafo é $k$-regular.

## Caminhos Orientados

* Definimos passeios da mesma forma que para grafos. No entanto, a orientação das arestas deve coincidir: **isto é, dado um par de arestas consecutivos onde $v$ é o vértice comum, a primeiro aresta converge para $v$ enquanto a segunda diverge de $v$.** Neste caso podemos chamar a sequência de passeio orientado, ou simplesmente passeio.
    * Quando a orientação das arestas não coincide, dizemos que a sequência é um semi-passeio.
* De forma similar definimos trajetos, semi-trajetos, caminhos, semi-caminhos e semi-circuitos.

## Digrafos Conexos

### Definição

Um digrafo $D(V, A)$ é **fortemente conexo** se existe um caminho orientado de $v_{i}$ para $v_{j}$ e de $v_{j}$ para $v_{i}$, quaisquer que sejam $v_{i}, v_{j} \in V$.

Um digrafo $D(V, A)$ é **fracamente conexo** se o grafo associado é conexo mas $D$ não é fortemente conexo.

## Propriedades

Um digrafo é dito ser **acíclico** se não possui circuitos.

* Um digrafo é acíclico se, e somente se, todo trajeto orientado é também um caminho orientado.
* Todo digrafo acíclico possui pelo menos uma fonte e um sumidouro.