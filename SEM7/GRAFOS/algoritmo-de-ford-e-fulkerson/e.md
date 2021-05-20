# Victor Azadinho Miranda

- Victor Azadinho Miranda
- RA: 171042191

# Exercício - Algoritmo de Ford e Fulkerson

Início:

\begin{align*}
  f(s, a) = 0 \\
  f(s, d) = 0 \\
  f(a, b) = 0 \\
  f(a, c) = 0 \\
  f(d, b) = 0 \\
  f(d, c) = 0 \\
  f(b, t) = 0 \\
  f(c, t) = 0
\end{align*}

$F = 0$

## 1ª iteração

Caminho aumentante: $\{s, a, b, t\}$

$F' = min\{12, 10, 5\} = 5$

\begin{align*}
  f(s, a) = 5 \\
  f(s, d) = 0 \\
  f(a, b) = 5 \\
  f(a, c) = 0 \\
  f(d, b) = 0 \\
  f(d, c) = 0 \\
  f(b, t) = 5 \\
  f(c, t) = 0
\end{align*}

$F = 5$

## 2ª iteração

Caminho aumentante: $\{s, d, c, t\}$

$F' = min\{10, 12, 18\} = 10$

\begin{align*}
  f(s, a) = 5 \\
  f(s, d) = 10 \\
  f(a, b) = 5 \\
  f(a, c) = 0 \\
  f(d, b) = 0 \\
  f(d, c) = 10 \\
  f(b, t) = 5 \\
  f(c, t) = 10
\end{align*}

$F = 15$

## 3ª iteração

Caminho aumentante: $\{s, a, c, t\}$

$F' = min\{7, 4, 8\} = 4$

\begin{align*}
  f(s, a) = 9 \\
  f(s, d) = 10 \\
  f(a, b) = 5 \\
  f(a, c) = 4 \\
  f(d, b) = 0 \\
  f(d, c) = 10 \\
  f(b, t) = 5 \\
  f(c, t) = 14
\end{align*}

$F = 19$

Corte mínimo: $S = \{s, a, d\}$