# Aula 3

## Modelagem de Dados

Processo de especificação do projeto de banco de dados por meio do uso de um modelo de dados

1. Projeto de Sistemas

Projeto Conceitual: Permite especificar o projeto de banco de dados por meio de um modelo de dados de alto nível de representação semántica e independente de um SGBD.

Projeto Lógico: É a concepção do projeto de dados segundo um SGBD a ser adotado, ou seja, a específicação de um projeto de banco de dados segundo um modelo de dados suportado por um SGBD

Projeto Físico: Permite específicar detalhes do projeto de banco de dados em nível mais baixo tais como: os tipos de dados, estruturas de indexação, métodos de armazenamento de memória, etc

## Modelo Entidade Relacionamento

P. Chen $\rightarrow$ 1976

Por meio do Modelo E-R é possível descrever os objetos, suas associações e restrições

Exemplo de Objetos: Entidades públicas e privadas; Eventos; fatos; etc

objeto Pessoa
instância 'João José'
conjunto de entidades
Pessoa - conjunto de entidades
'João José' - uma entidade

Atributos $\rightarrow$ as características de um conjunto de Entidades

domínio de um atributo $\rightarrow$ coleção de valores possíveis para o atributo

* Componentes
    * Simples - atributo é composto por um único item
    Ex: nome, sexo, RG
    * composto - formado por mais do que um componente

* valores
monovalorado - possui apenas um único valor
Ex: sexo 'masculino'
multivalorado - possui uma coleção de valores
Ex: fone - os vários números de telefone do indivíduo
* chave primária
superchave - é uma coleção de atributos de um conjunto entidade que, dado um valor (atribuído valor), é possível localizar uma entidade no conjunto entidade.
Ex: RG; RG + nome

chave cadidata - é uma superchave que não tenha nenhum subconjunto próprio que seja uma superchave
$\{ \text{RG, nome, sexo} \} = \{ \text{RG, nome} \} , \{ \text{RG} \} , \{ \text{RG, sexo} \} \ldots$

chave primária - a classe candidata escolhida pelo projetista

restrição de cardinalidade permite descrever as possibilidades de associação entre os conjuntos de entidades