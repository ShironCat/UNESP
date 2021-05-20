# Atividade semana 8

- Victor Azadinho Miranda
- RA: 171042191

## Matrizes PAM

Matrizes de substituição são usadas para atribuir pontuações individuais a posições de sequência alinhadas. Uma matriz de substituição define valores para todos os pares de resíduos possíveis.

### Métodos

- Quantas sequências de nucleotídeos devem ser modificadas para obter esta mutação. Lembre-se de que três nucleotídeos codificam um aminoácido.
- Propriedades físico-químicas e semelhanças.
- Os mais bem-sucedidos são baseados em evidências reais.

### Como as pontuações são atribuídas

- Cada possível identidade e substituição é atribuída uma pontuação com base nas frequências observadas de tais ocorrências em alinhamentos de proteínas relacionadas.
- A pontuação é calculada a partir da frequência de ocorrência de uma combinação dos dois aminoácidos individuais em sequências evolutivamente relacionadas e fornece uma medida de um alinhamento casual dos dois aminoácidos.
- Essa pontuação também refletirá a frequência com que um determinado aminoácido ocorre na natureza, pois alguns aminoácidos são mais abundantes do que outros.
- Pontuações mais altas indicam que a probabilidade de que esses dois aminoácidos alinhados ao acaso é muito pequena, e pontuações mais baixas indicam uma alta probabilidade de os dois aminoácidos alinhados ao acaso e não estão evolutivamente relacionados.

Assim, as identidades são atribuídas às pontuações mais positivas, as substituições frequentemente observadas também recebem pontuações positivas, mas as correspondências que provavelmente não foram resultado da evolução e são mais provavelmente indicativas de falta de relacionamento nessa posição recebem pontuações negativas. Matrizes com esquemas de pontuação com base nas taxas de substituição observadas são superiores às pontuações de identidade simples, ou pontuações baseadas apenas na similaridade da porção da cadeia lateral.

### Tipos de Matrizes

Existem dois tipos principais de matrizes.

- PAM
- BLOSUM

### PAM

PAM significa *Percent Accepted Mutation* (Porcentagem de Mutação Aceita). Foi Margaret Day Hoff quem realizou um estudo para encontrar a frequência relativa com que os aminoácidos se substituem/substituem uns aos outros durante o curso da evolução.

As matrizes de pontuação de substituição PAM foram projetadas para rastrear as origens evolutivas das proteínas. Estes usam frequências de substituição derivadas de conjuntos de sequências de proteínas intimamente relacionadas. Existe mais de uma matriz e cada matriz corresponde a uma quantidade particular de mutações aceitas - mutações que foram retidas na sequência. A quantidade é medida.

### Tipos de PAM

- PAM250
- PAM120

### PAM250

Uma das mais amplamente utilizadas dessas tabelas de frequência de mutação é a matriz PAM250. A matriz de substituição PAM 250 é usada para sequências distantemente relacionadas. O PAM 250 aceita 250 mutações. O 250 no PAM 250 representa os dados coletados de 71 conjuntos de sequências alinhadas extrapoladas até o nível de 250 substituições de aminoácidos por 100 resíduos.

### PAM120

PAM120 aceita 120 mutações. A matriz de substituição PAM 120 é usada para sequências intimamente relacionadas e é melhor para alinhamentos gerais.

### Vantagens da matriz PAM

- As matrizes PAM são baseadas no “alinhamento global” de proteínas relacionadas.
- Como as tabelas PAM são baseadas em mutações observadas, elas podem ser extremamente úteis na determinação dos processos responsáveis por essas mutações e também fornecem critérios para selecionar e corrigir uma mutação em uma população.
- Outra vantagem do ponto de vista estatístico é que os dados são derivados de sequências para construir uma tabela PAM, agora usando essa tabela PAM de dados pode-se fornecer informações sobre as mudanças na estrutura de um resíduo de aminoácido após um determinado número de mutações.
- As tabelas PAM fornecem determinação empírica e experimental de substituição conservada.

### Desvantagens da matriz PAM

- Ele assume que todos os tipos de mutações são distribuídos uniformemente pelas proteínas.
- Ele usa dados de proteínas intimamente relacionadas para inferir relações entre proteínas muito diferentes.

## Bibliografia

Saud, Omama (2009). ["PAM and BLOSUM Substitution Matrices"](https://web.archive.org/web/20130309015755/http://birec.org/sandbox/omamasaudtutorial). Birec. Arquivado [do original](http://www.birec.org/sandbox/omamasaudtutorial) em 9 de Março de 2013. Acessado em 20 de Agosto de 2020.