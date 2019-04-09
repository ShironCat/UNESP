# Aula 2

## Níveis de abstrações

* Visões
* Conceitual
* Físico

## Esquema e Instâncias

Esquema:
* A descrição lógica dos dados

Instâncias:
* São ocorrências de valores para a concepção lógica definido para o respectivo esquema

esquemas x instâncias
* não é possível modificar esquemas e é possível alterar instâncias.

## Independência dos dados

lógica:
* é a capacidade de evitar a propagação de alterações junto às aplicações quando é efetivada (estas alterações) nos esquemas

física:
* é a capacidade de evitar a propagração, junto às aplicações, das alterações efetivadas no nível físico.

## Modelo de Dados

### Definição

"Uma coleção de ferramentas conceituais que permitem descrever as abstrações do mundo real e pertinentes ao projeto de baco de dados pretendido"

### Modelos de Dados

* O.O.
* R.O.
* ME-R
* Relacional
* Redes
* Hierárquico

## linguagem em um SGBD

1. linguagem de definição de dados - LDD
    * Permite a descrição do esquema
2. linguagem de maniúlação dos dados - LMD
    * Permite a manipulação das instâncias

no modelo Relacional
* SQL (LDD + LMD)

no modelo Orientado a Objetos
* OQL está baseado SQL

## Arquitetura de um SGBD

* tipos de usuário
* SGBD
* S.O.
* Dispositivo de Armazenamento Secundário