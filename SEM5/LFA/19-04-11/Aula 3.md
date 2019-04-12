# Aula 3

## Autômatos Finitos

* um estado de um sistema é uma descrição instantânea do sistema fornece todas as informações necessárias para determinar como o sistema pode evoluir a partir daquele ponto.
* **transições** são mudanças de estado e podem acontecer em resposta a estímulos externos.
* um sistema com conjunto de estados finito é denominado sistema de estado finito.

Esse sistema pode ser modulado (ou abstraído) por um modelo matemático denominado **autômato finito**.

### Definição

Um autômato finito determinado $M$ é uma tupla $M = (Q, \Sigma , \delta , q_{0}, F)$ onde:

* $Q$: é o conjunto finito de estados
* $\Sigma$: é o alfabeto de entrada
* $q_{0}$: $q_{0} \in Q$ é o estado inicial
* $F$: é o conjunto de estados finais $F \subset Q$
* $\delta$: é a função de transição ou função programa $\delta :Q \times \Sigma \rightarrow Q$

* a cabeça de leitura movimenta-se sempre uma célular por vez, da esquerda para a direita;
* no início do processamento está posicionado sobre o símbolo mais à esquerda
* a fita é finita e é dividida em células
* cada célula possui um único símbolo

## Representação de um Autômato Finito

1. Diagrama de estados
2. Tabela de transição
3. Notação formal

### Definição

Um Autômato Finito Não-Determinístico $N$ é uma tupla $N = (Q, \Sigma , \delta , q_{0}, F)$ onde,

* $Q$: é o conjunto finito de estados
* $\Sigma$: é o alfabeto de entrada
* $q_{0}$: $q_{0} \in Q$ é o estado inicial
* $F$: é o conjunto de estados finais $F \subset Q$

* $\delta$: é a função de transição ou função programa.
* $\delta$: $Q \times \Sigma \cup \{ \varepsilon \} \rightarrow 2^{Q}$[^1]

[^1]: conjunto dos subconjuntos de $Q$