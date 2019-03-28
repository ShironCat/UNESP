# Introdução

## O que é um Grafo?

Um grafo G é constituído de um conjunto V não-vazio de objetos, chamados de vértices (ou nós), e uma família A de pares não ordenados de elementos V, chamados de arestas. Denotamos o grafo por G(V, A) ou simplesmente G. Em algumas situações, dado um grafo G, denotamos seu conjunto de vértices como V(G) e sua lista de arestas como A(G).

Os grafos podem ser representados através de um diagrama onde as vértices são representados por pontos e cada aresta é representada por uma linha ligando os pares de vértices que a definem.

Em algumas aplicações, as arestas são definidas como pares ordenados de vértices. Neste caso dizemos que o grafo é orientado ou direcionado e o chamamos de Digrafo.

## O que é um Digrafo?

Um grafo orientado (ou direcionado) G(V, A) é constituído por um conjunto V não-vazio de objetos, chamados vértices (ou nós), e uma família A de pares ordenados de elementos V, chamados de arestas ou arcos.

Os digrafos podem ser desenhados através de um diagrama onde os vértices são representados por pontos e cada aresta $(v_{i}, v_{j})$ é representada por uma linha ligando $v_{i}$ a $v_{j}$ com uma seta apontando para $v_{j}$.

Um mesmo grafo, ou um mesmo digrafo, pode ter diferentes representações gráficas.

O que é que caracteriza um grafo? O conjunto de vértices e a família de arestas, ou seja, um conjunto e objetos (vértices) e a relação entre estes objetos (arestas). Durante o curso, a distinção entre grafos e digrafos será feita de acordo com o tópico estudado.

Assim, podemos dizer que a Teoria dos Grafos é um ramo da matemática que estuda as relações entre os objetos de um determinado conjunto.

## Aplicações

### O problema das pontes de Königsberg

Na cidade de Königsberg (Hoje Kaliningrado - Rússia) sete pontes cruzam o rio Pregel estabelecendo ligações entre uma ilha e o continente.

Será que é possível fazer um passeio pela cidade, começando e terminando no mesmo lugar e passando por cada uma das ponter apenas uma vez?

**Problema Chinês do Carteiro:** Determinar a rota de menor custo que saia da agência central dos correios, passe por todas as ruas de um determinado bairro, e volte a origem.

### O problema do caixeiro viajante

Um viajante necessita visitar um certo número de cidades. É possível minar um roteiro de viagem tal que cada cidade seja visitada apenas uma vez?

Considere, por exemplo, um trecho do mapa rodoviário que inclui a cidade de São José do Rio Preto (SJRP). Suponha que o viajante tenha que sair de SJRP e visitar as cidades de Marilia, Araçatuba, Bauru e São Carlos.

É possível encontrar uma rota que passe por todas as cidades apenas uma vez e retorne a cidade de SJRP? Caso existam mais de uma rota, qual é a rota que minimiza o trecho viajado?