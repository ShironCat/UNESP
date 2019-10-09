# Como tornar a IoT mais inteligente - abordagens e aplicações

## Mudanças no mundo

* Airbnb
* Carros autônomos
* Blockchain

## Hoje e o futuro próximo

* Arealidade hoje...
* E as tendências que podem destravar oportunidades totalmente novas
  * Inteligência Artificial
  * Internet das coisas (IoT)
  * Blockchain

## Blockchain e o modelo tradicional

* Modelo Tradicional (Ledger)
  * Modelo centralizado
  * Transações são garantidas por autoridades conhecidas
  * Confiança baseada em regulamentação e auditoria
* Blockchain (Distributed Ledger)
  * Modelo descentralizado
  * Transações são garantidas pelo cosenso da rede
  * Confiança baseada em algoritmos criptográficos

## Blockchain e os contratos inteligentes

* Contrato tradicional
  * Linguagem: jurídica
  * Execução feita pelos envolvidos
  * Registro em cartório ou mantido entre as partes
* Smart Contract
  * Linguagem: script
  * Auto-executável, com decisões baseadas em dados de entrada
  * Registro Blockchain Ethereum

## Motivação para o blockchain

* Redes que conectam participantes
* Mercados organizam compras/vendas

## O que é blockchain? Livro-contábil digital

* Livro-contábil armazena todas as atividades de negócio como transações
* É um banco de dados contendo informações de troca/intercâmbio de bens
* Todo mercado e rede possui um livro contábil
* Problema - muitas instâncias de livro-contábil
  * Todo mercado possui o seu
  * Toda organização possui a sua

## E o blockchain?

* Um livro único e confiável
* Blackchain cria um único livro para todos os participantes
* É um livro-razão para troca de informações digitais de maneira confiável
* Assegura a auditabilidade e a imutabilidade das transações
* Apenas realiza o "append"
* É uma lista encadeada

## Moedas e DLTs

* Bitcoin usa Blockchain
* Ethereum usa Blockchain
* IOTA usa o Tangle
* Libra usa o Blockchain (consenso baseado no PBFT, o do LibraBFT)

## Teorema de CAP

Blockchain é baseado em:

* Peer to Peer
* Banco de dados distribuído

Propriedades do Teorema:

* Consistensy
* Availability
* Partition Tolerance

"De acordo com o teorema da CAP, em qualquer rede distribuída é impossível fornecer mais de duas dessas três propriedades como um recurso garantido".

## Disponibilidade sobre consistência (A + P)

* Toda solicitação à rede recebe a resposta;
* esmo que não haja garantia

## CAP no blockchain do Bitcoin?

* Como as redes blockchain (como Bitcoin) são sistemas distribuídos;
* elas precisam lidar com a tolerância de partição;
* das duas opções restantes, eles escolhem A em vez de C;
* ou seja, Disponibilidade em vez de Consistência;

## Como funciona o blockchain?

1. A user requests for a transaction
2. A block representing the transaction is created
3. The block is broadcasted to all the nodes of the network
4. All the nodes validate the block and the transaction
5. The block is added to the chain
6. The transaction then gets validated

## Blockchain Público e Privado

* Public Blockchain Permissionless
* Private Blockchain Permissioned

## Rede Centralizada, Descentralizada e Distribuída

* Centralized Network
  * Um único node central
* Descentralized Network
  * Múltiplos nodes "centrais"
* Distributed Network
  * Não há node centrais

## O que é um protocolo de consenso?

* Protocolo para alcançar o acordo sobre um dado ou um estado da rede entre os seus participantes
* Todos os membros designados para isso participam
* Dois principais
  * Proof of Work (PoW) - Deve ser capaz de provar que realizou o trabalho; deve mostrar que gastou tempo para chegar a uma resposta
  * Bitcoin e Litecoin
  * Proof of Stake (PoS)

## A evolução do blockchain

* Classificação de blockchain:
  * blockchain 1.0: Bitcoin
  * blockchain 2.0: Contratos inteligentes

## Função hash

* Definição
* h = H(m)

## O que é o nonce?

```javascript
  let nounce = 0;
  let hash;
  let input;

  while(!isValidHashDifficulty(hash)) {
    nonce = nonce + 1;
    input = index + previousHash + timestamp + data + nonce;
    hash = CryptoJS.SHA256(input)
  }
```

## Camadas do blockchain

* Camada de aplicação
* Camada de contrato
* Camada de rede
* Camada de dados

## Prova de Trabalho

* Proof of Work (PoW)
* Proposto pro Nakamoto em 2008/2009
* Base da criptomoeda Bitcoin

## Prova de Participação

* Proof of Stake (PoS)
* Reduzir o custo de validação
* É baseado na posse da criptomoeda

## Protocolo Bizantino

* Baseado em tolerância a falhas Bizantinas práticas - PBFT
* Problemas dos generais Bizantinos
* Protocolo privado
* Baseado em votação para validar o bloco
* Os nós falhos < número total / 3
* Validação:
  * É eleito um líder
  * Uma solicitação de entrada

## Contratos inteligentes

1. A contract is created between two parties
2. Some triggering events are set i.e. deadlines
3. Regulator and users can analyze all the activities

## Contrato inteligente

* Contratos são códigos escritos em uma linguagem que humanos e máquinas

## Desafios dos contratos inteligentes

* Confidencialidade
* Erros
* Contratos fraudulentos

## Na área financeira

* BNDES Token
* Blockchain público

## Na área política

* Contagem de votos
* Aplicação baseada em blockchain para voto eletrônico

## Out multimodal approach for sensing at interaction time

* Combination of several sensor with AI for reckonizing emotions at interaction time

## Seguro de autos

* Estilos de direção poderão ser armazenados em blockchain
* Pode reduzir fraudes porque blockchain caracteriza por ser imutável e auditável
* Pode auxiliar nas novas tarifas de seguro

## Corporações já usando o blockchain

Setores que lideram (2018)

* Cadeias de suprimentos

## Blockchain e Web 3.0

* A Web 3.0 é a terceira geração da Internet
* Dispositivos estão conectados em uma rede descentralizada
* Em vez de servidores
* A nova Internet é centrada no usuário, mais segura, privada e melhor conectada, QoE.

## Blockchain in healthcare

* Secure medical data dissemination among actors (confidentiality)
* Dissemination protocol for multiple actors

## Blockchain and VANET: Negotiation Protocol

* Content delivery

How to assure the car has the right content?

Use Zero Knowledge Proof?

* Micropayment

How to assure the other car will not run away or has the needed amount?

Rely on Trusted Third Party (e.g. bank)

## Considerações finais

* Blockchain é muito mais do que só Bitcoin
* Pode ser explorado em qualquer área
* É considerado a Internet dos Negócios