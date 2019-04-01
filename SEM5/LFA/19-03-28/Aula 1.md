# Aula 1

## Conceitos básicos

* **Símbolos**: representações gráficas indivisíveis, usadas na contrução de cadeias.
* **Cadeias** (palavras): justaposição de um número finito de símbolos. Normalmente, representados por $u$, $v$, $w$, $x$, $y$, $z$ (letras minúsculas).
* **Alfabeto**: Conjunto finito, não-vazio, de símbolos. Denota-se por $\Sigma$.
* **Comprimento** ou **tamanho** de uma cadeia: número de símbolos que a compoem.
* **Cadeia vazia**: $\Epsilon$ $|\Epsilon| = 0$ É uma cadeia cujo tamanho é zero.
* Concatenação de cadeias: é a junção dos símbolos de ambas as cadeias.
* **Prefixo**: de uma cadeia é qualquer sequência de símbolos inicial de uma cadeia.
* **Sufixo**: de uma cadeia é qualquer sequência de símbolos final de uma cadeia.
* **Subcadeia**:  de uma cadeia é qualquer sequência de símbolos contiguos de uma cadeia.
* **Linguagem**: é um conjunto de cadeias sobre um determinado alfabeto. Pode ser finito ou infinito.

## Métodos de Representação de Linguagem

Uma linguagem pode ser representada por 3 mecaninsmos.

1. Enumeração das cadeias da linguagem.
2. Através do conjunto de leis de formação das cadeias (mecanismo gerador) $\rightarrow$ Gramática.
3. Através das regras de aceitação das cadeias (mecanismo de aceitação) $\rightarrow$ Reconhecedores.

## Hierarquia das Linguagens Formais

### Hierarquia de Chomsky

* Linguagem | Mecanismo Gerador | Mecanismo Aceitador
* tipo 3: regular | gramática regular | autômato finito
* tipo 2: livre de contexto | GLC | autômato com pilha
* tipo 1: sensível ao contexto | GSC | autômato linearmente limitado
* tipo 0: irrestrita | GI | Maquina de Turing

## Gramáticas

### Definição

Uma grámatica $G$ é uma tupla $G = (V, \Sigma, P, S)$ onde;

* $V$: conjunto não-vazio de símbolos não-terminais (letras maiúsculas)
* $\Sigma$: alfabeto (letras minúsculas)
* $P$: conjunto de regras de produção ou leis de formação
* $S$: símbolo de partida, $S \in V$
	* uma regra de produção é representada por $\alpha \rightarrow \beta$ ($\alpha$ produz $\beta$)
	* uma sequência de regras de produção $\alpha \rightarrow \beta_{1}, \alpha \rightarrow \beta_{2}, \ldots, \alpha \rightarrow \beta_{n}$ pode ser abreviada por $\alpha \rightarrow \beta_{1}|\beta_{2}|\ldots|\beta_{n}$

**observação**: $\alpha \in (V \cup \Sigma)^{+}$ e $\beta \in (V \cup \Sigma)^{*}$

* a aplicação de uma regra de produção é denominada derivação de uma cadeia
* a aplicação sucessiva de regras de produção permite deixar as cadeias de linguagem gerada pela gramática

### Definição

Seja $G = (V, \Sigma, P, S)$ uma grámatica. Uma derivação em $G$ é um par da relação deriva $\Rightarrow$ $(\alpha \Rightarrow \beta)$

**Observação**: $\alpha \Rightarrow^{*} \gamma$ (zero ou mais passos de derivação sucessivos)
$\alpha \Rightarrow^{+} \gamma$ (1 ou mais passos de derivação sucessivos)