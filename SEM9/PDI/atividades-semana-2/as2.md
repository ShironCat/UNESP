# Atividade Semana 2

- Victor Azadinho Miranda
- 171042191

## Exercício 1

Resolução espacial se refere à densidade de pixels utilizados na representação de uma imagem, enquanto que profundadide se refere à quantos bits são utilizados para representar a informação de cor de cada pixel.

## Exercício 2

Profundidade de 13 bits.

Definido por: $\log_2 8192 = 13$

## Exercício 3

A imagem possui um valor de entropia igual a: $1.815$

Definido por: $-\sum_{i=0}^{L_{max}}p_i\log_2p_i$

\begin{align*}
    p_1 &= 0.375\\
    p_2 &= 0.125\\
    p_3 &= 0.125\\
    p_4 &= 0.375\\
    \\
    H &= -[(0.375*-1.42)+(0.125*-3)+(0.125*-3)+(0.375*-1.42)]\\
    H &= -[(-0.5325)+(-0.375)+(-0.375)+(-0.5325)]\\
    H &= 1.815
\end{align*}

## Exercício 4

$D_E = \sqrt{(2-234)^2+(225-12)^2} = 314,95$

$D_4 = |2-234|+|225-12| = 445$

$D_8 = \max(|2-234|,|225-12|) = 232$