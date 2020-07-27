# Caminho Mínimo em Grafos

- Victor Azadinho Miranda
- RA: 171042191

## Exercício 1

### R1

$it = 1$

\begin{align*}
  &rot(a) = min \{ \infty, 0 + w_{sa} \} = min \{ \infty, 7 \} = 7 \\
  &rot(b) = min \{ \infty, 0 + w_{sb} \} = min \{ \infty, 13 \} = 13 \\
  &rot(c) = min \{ \infty, 0 + w_{sc} \} = min \{ \infty, 28 \} = 28 \\
  &rot(d) = min \{ \infty, 0 + w_{sd} \} = min \{ \infty, \infty \} = \infty \\
  &rot(e) = min \{ \infty, 0 + w_{se} \} = min \{ \infty, \infty \} = \infty \\
  &rot(t) = min \{ \infty, 0 + w_{st} \} = min \{ \infty, \infty \} = \infty \\
  \\
  &min \{ 7, 13, 28, \infty, \infty, \infty \} = 7 \Rightarrow rot(a) \text{ torna-se permanente}
\end{align*}

$it = 2$

\begin{align*}
  &rot(b) = min \{ 13, 7 + w_{ab} \} = min \{ 13, 11 \} = 11 \\
  &rot(c) = min \{ 28, 7 + w_{ac} \} = min \{ 28, \infty \} = 28 \\
  &rot(d) = min \{ \infty, 7 + w_{ad} \} = min \{ \infty, 32 \} = 32 \\
  &rot(e) = min \{ \infty, 7 + w_{ae} \} = min \{ \infty, 17 \} = 17 \\
  &rot(t) = min \{ \infty, 7 + w_{at} \} = min \{ \infty, \infty \} = \infty \\
  \\
  &min \{ 11, 28, 32, 17, \infty \} = 11 \Rightarrow rot(b) \text{ torna-se permanente}
\end{align*}

$it = 3$

\begin{align*}
  &rot(c) = min \{ 28, 11 + w_{bc} \} = min \{ 28, 16 \} = 16 \\
  &rot(d) = min \{ 32, 11 + w_{bd} \} = min \{ 32, 17 \} = 17 \\
  &rot(e) = min \{ 17, 11 + w_{be} \} = min \{ 17, \infty \} = 17 \\
  &rot(t) = min \{ \infty, 11 + w_{bt} \} = min \{ \infty, \infty \} = \infty \\
  \\
  &min \{ 16, 17, 17, \infty \} = 16 \Rightarrow rot(c) \text{ torna-se permanente}
\end{align*}

$it = 4$

\begin{align*}
  &rot(d) = min \{ 17, 16 + w_{cd} \} = min \{ 17, \infty \} = 17 \\
  &rot(e) = min \{ 17, 16 + w_{ce} \} = min \{ 17, 19 \} = 17 \\
  &rot(t) = min \{ \infty, 16 + w_{ct} \} = min \{ \infty, \infty \} = \infty \\
  \\
  &min \{ 17, 17, \infty \} = 17 \Rightarrow rot(d) \text{ torna-se permanente}
\end{align*}

$it = 5$

\begin{align*}
  &rot(e) = min \{ 17, 17 + w_{de} \} = min \{ 17, \infty \} = 17 \\
  &rot(t) = min \{ \infty, 17 + w_{dt} \} = min \{ \infty, 22 \} = 22 \\
  \\
  &min \{ 17, 22 \} = 17 \Rightarrow rot(e) \text{ torna-se permanente}
\end{align*}

$it = 6$

\begin{align*}
  &rot(t) = min \{ 22, 17 + w_{et} \} = min \{ 22, 29 \} = 22 \\
  \\
  &min \{ 22 \} = 22 \Rightarrow rot(t) \text{ torna-se permanente}
\end{align*}

Fim. Menor caminho: $s, a, b, d, t$.

### R2

$it = 1$

\begin{align*}
  &rot(a) = min \{ \infty, 0 + w_{sa} \} = min \{ \infty, 4 \} = 4 \\
  &rot(b) = min \{ \infty, 0 + w_{sb} \} = min \{ \infty, 6 \} = 6 \\
  &rot(c) = min \{ \infty, 0 + w_{sc} \} = min \{ \infty, 7 \} = 7 \\
  &rot(d) = min \{ \infty, 0 + w_{sd} \} = min \{ \infty, \infty \} = \infty \\
  &rot(e) = min \{ \infty, 0 + w_{se} \} = min \{ \infty, \infty \} = \infty \\
  &rot(f) = min \{ \infty, 0 + w_{sf} \} = min \{ \infty, \infty \} = \infty \\
  &rot(t) = min \{ \infty, 0 + w_{st} \} = min \{ \infty, \infty \} = \infty \\
  \\
  &min \{ 4, 6, 7, \infty, \infty, \infty, \infty \} = 4 \Rightarrow rot(a) \text{ torna-se permanente}
\end{align*}

$it = 2$

\begin{align*}
  &rot(b) = min \{ 6, 4 + w_{ab} \} = min \{ 6, \infty \} = 6 \\
  &rot(c) = min \{ 7, 4 + w_{ac} \} = min \{ 7, \infty \} = 7 \\
  &rot(d) = min \{ \infty, 4 + w_{ad} \} = min \{ \infty, 11 \} = 11 \\
  &rot(e) = min \{ \infty, 4 + w_{ae} \} = min \{ \infty, 9 \} = 9 \\
  &rot(f) = min \{ \infty, 4 + w_{af} \} = min \{ \infty, \infty \} = \infty \\
  &rot(t) = min \{ \infty, 4 + w_{at} \} = min \{ \infty, \infty \} = \infty \\
  \\
  &min \{ 6, 7, 11, 9, \infty, \infty \} = 6 \Rightarrow rot(b) \text{ torna-se permanente}
\end{align*}

$it = 3$

\begin{align*}
  &rot(c) = min \{ 7, 6 + w_{bc} \} = min \{ 7, \infty \} = 7 \\
  &rot(d) = min \{ 11, 6 + w_{bd} \} = min \{ 11, 11 \} = 11 \\
  &rot(e) = min \{ 9, 6 + w_{be} \} = min \{ 9, \infty \} = 9 \\
  &rot(f) = min \{ \infty, 6 + w_{bf} \} = min \{ \infty, 13 \} = 13 \\
  &rot(t) = min \{ \infty, 6 + w_{bt} \} = min \{ \infty, \infty \} = \infty \\
  \\
  &min \{ 7, 11, 9, 13, \infty \} = 7 \Rightarrow rot(c) \text{ torna-se permanente}
\end{align*}

$it = 4$

\begin{align*}
  &rot(d) = min \{ 11, 7 + w_{cd} \} = min \{ 11, \infty \} = 11 \\
  &rot(e) = min \{ 9, 7 + w_{ce} \} = min \{ 9, 11 \} = 9 \\
  &rot(f) = min \{ 13, 7 + w_{cf} \} = min \{ 13, 12 \} = 12 \\
  &rot(t) = min \{ \infty, 7 + w_{ct} \} = min \{ \infty, \infty \} = \infty \\
  \\
  &min \{ 11, 9, 12, \infty \} = 9 \Rightarrow rot(e) \text{ torna-se permanente}
\end{align*}

$it = 5$

\begin{align*}
  &rot(d) = min \{ 11, 9 + w_{ed} \} = min \{ 11, 12 \} = 11 \\
  &rot(f) = min \{ 12, 9 + w_{ef} \} = min \{ 12, 11 \} = 11 \\
  &rot(t) = min \{ \infty, 9 + w_{et} \} = min \{ \infty, 18 \} = 18 \\
  \\
  &min \{ 11, 11, 18 \} = 11 \Rightarrow rot(d) \text{ torna-se permanente}
\end{align*}

$it = 6$

\begin{align*}
  &rot(f) = min \{ 11, 11 + w_{df} \} = min \{ 11, \infty \} = 11 \\
  &rot(t) = min \{ 18, 11 + w_{dt} \} = min \{ 18, 18 \} = 18 \\
  \\
  &min \{ 11, 18 \} = 11 \Rightarrow rot(f) \text{ torna-se permanente}
\end{align*}

$it = 7$

\begin{align*}
  &rot(t) = min \{ 18, 11 + w_{ft} \} = min \{ 18, 17 \} = 17 \\
  \\
  &min \{ 17 \} = 17 \Rightarrow rot(t) \text{ torna-se permanente}
\end{align*}

Fim. Menor caminho: $s, a, e, f, t$.

### R3

$it = 1$

\begin{align*}
  &rot(a) = min \{ \infty, 0 + w_{sa} \} = min \{ \infty, 3 \} = 3 \\
  &rot(b) = min \{ \infty, 0 + w_{sb} \} = min \{ \infty, 2 \} = 2 \\
  &rot(c) = min \{ \infty, 0 + w_{sc} \} = min \{ \infty, 8 \} = 8 \\
  &rot(d) = min \{ \infty, 0 + w_{sd} \} = min \{ \infty, \infty \} = \infty \\
  &rot(e) = min \{ \infty, 0 + w_{se} \} = min \{ \infty, \infty \} = \infty \\
  &rot(f) = min \{ \infty, 0 + w_{sf} \} = min \{ \infty, \infty \} = \infty \\
  &rot(g) = min \{ \infty, 0 + w_{sg} \} = min \{ \infty, \infty \} = \infty \\
  &rot(h) = min \{ \infty, 0 + w_{sh} \} = min \{ \infty, \infty \} = \infty \\
  &rot(t) = min \{ \infty, 0 + w_{st} \} = min \{ \infty, \infty \} = \infty \\
  \\
  &min \{ 3, 2, 8, \infty, \infty, \infty, \infty, \infty, \infty \} = 2 \Rightarrow rot(b) \text{ torna-se permanente}
\end{align*}

$it = 2$

\begin{align*}
  &rot(a) = min \{ 3, 2 + w_{ba} \} = min \{ 3, \infty \} = 3 \\
  &rot(c) = min \{ 8, 2 + w_{bc} \} = min \{ 8, 8 \} = 8 \\
  &rot(d) = min \{ \infty, 2 + w_{bd} \} = min \{ \infty, 11 \} = 11 \\
  &rot(e) = min \{ \infty, 2 + w_{be} \} = min \{ \infty, \infty \} = \infty \\
  &rot(f) = min \{ \infty, 2 + w_{bf} \} = min \{ \infty, \infty \} = \infty \\
  &rot(g) = min \{ \infty, 2 + w_{bg} \} = min \{ \infty, \infty \} = \infty \\
  &rot(h) = min \{ \infty, 2 + w_{bh} \} = min \{ \infty, \infty \} = \infty \\
  &rot(t) = min \{ \infty, 2 + w_{bt} \} = min \{ \infty, \infty \} = \infty \\
  \\
  &min \{ 3, 8, 11, \infty, \infty, \infty, \infty, \infty \} = 3 \Rightarrow rot(a) \text{ torna-se permanente}
\end{align*}

$it = 3$

\begin{align*}
  &rot(c) = min \{ 8, 3 + w_{ac} \} = min \{ 8, 7 \} = 7 \\
  &rot(d) = min \{ 11, 3 + w_{ad} \} = min \{ 11, \infty \} = 11 \\
  &rot(e) = min \{ \infty, 3 + w_{ae} \} = min \{ \infty, 7 \} = 7 \\
  &rot(f) = min \{ \infty, 3 + w_{af} \} = min \{ \infty, \infty \} = \infty \\
  &rot(g) = min \{ \infty, 3 + w_{ag} \} = min \{ \infty, \infty \} = \infty \\
  &rot(h) = min \{ \infty, 3 + w_{ah} \} = min \{ \infty, \infty \} = \infty \\
  &rot(t) = min \{ \infty, 3 + w_{at} \} = min \{ \infty, \infty \} = \infty \\
  \\
  &min \{ 7, 11, 7, \infty, \infty, \infty, \infty \} = 7 \Rightarrow rot(c) \text{ torna-se permanente}
\end{align*}

$it = 4$

\begin{align*}
  &rot(d) = min \{ 11, 7 + w_{cd} \} = min \{ 11, \infty \} = 11 \\
  &rot(e) = min \{ 7, 7 + w_{ce} \} = min \{ 7, 8 \} = 7 \\
  &rot(f) = min \{ \infty, 7 + w_{cf} \} = min \{ \infty, 9 \} = 9 \\
  &rot(g) = min \{ \infty, 7 + w_{cg} \} = min \{ \infty, \infty \} = \infty \\
  &rot(h) = min \{ \infty, 7 + w_{ch} \} = min \{ \infty, \infty \} = \infty \\
  &rot(t) = min \{ \infty, 7 + w_{ct} \} = min \{ \infty, \infty \} = \infty \\
  \\
  &min \{ 11, 7, 9, \infty, \infty, \infty \} = 7 \Rightarrow rot(e) \text{ torna-se permanente}
\end{align*}

$it = 5$

\begin{align*}
  &rot(d) = min \{ 11, 7 + w_{ed} \} = min \{ 11, \infty \} = 11 \\
  &rot(f) = min \{ 9, 7 + w_{ef} \} = min \{ 9, \infty \} = 9 \\
  &rot(g) = min \{ \infty, 7 + w_{eg} \} = min \{ \infty, 13 \} = 13 \\
  &rot(h) = min \{ \infty, 7 + w_{eh} \} = min \{ \infty, \infty \} = \infty \\
  &rot(t) = min \{ \infty, 7 + w_{et} \} = min \{ \infty, \infty \} = \infty \\
  \\
  &min \{ 11, 9, 13, \infty, \infty \} = 9 \Rightarrow rot(f) \text{ torna-se permanente}
\end{align*}

$it = 6$

\begin{align*}
  &rot(d) = min \{ 11, 9 + w_{fd} \} = min \{ 11, \infty \} = 11 \\
  &rot(g) = min \{ 13, 9 + w_{fg} \} = min \{ 13, 14 \} = 13 \\
  &rot(h) = min \{ \infty, 9 + w_{fh} \} = min \{ \infty, 15 \} = 15 \\
  &rot(t) = min \{ \infty, 9 + w_{ft} \} = min \{ \infty, 18 \} = 18 \\
  \\
  &min \{ 11, 13, 15, 18 \} = 11 \Rightarrow rot(d) \text{ torna-se permanente}
\end{align*}

$it = 7$

\begin{align*}
  &rot(g) = min \{ 13, 11 + w_{dg} \} = min \{ 13, \infty \} = 13 \\
  &rot(h) = min \{ 15, 11 + w_{dh} \} = min \{ 15, 15 \} = 15 \\
  &rot(t) = min \{ 18, 11 + w_{dt} \} = min \{ 18, \infty \} = 18 \\
  \\
  &min \{ 13, 15, 18 \} = 13 \Rightarrow rot(g) \text{ torna-se permanente}
\end{align*}

$it = 8$

\begin{align*}
  &rot(h) = min \{ 15, 13 + w_{gh} \} = min \{ 15, \infty \} = 15 \\
  &rot(t) = min \{ 18, 13 + w_{gt} \} = min \{ 18, 18 \} = 18 \\
  \\
  &min \{ 15, 18 \} = 15 \Rightarrow rot(h) \text{ torna-se permanente}
\end{align*}

$it = 8$

\begin{align*}
  &rot(t) = min \{ 18, 15 + w_{ht} \} = min \{ 18, 17 \} = 17 \\
  \\
  &min \{ 17 \} = 17 \Rightarrow rot(t) \text{ torna-se permanente}
\end{align*}

Fim. Caminho Mínimo: $s, b, d, h, t$.