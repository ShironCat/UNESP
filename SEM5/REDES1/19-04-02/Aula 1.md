# Aula 1

## Internet 2019: perspectivas

"The network is the Computer" - SUN - John Gayge

"The app is the network" - Adriana

Quais são as coisas imutáveis na TI?
* Unix
* Linguagem C
* Modelo de camadas TCP/IP

* Em 1 fibra ótica é possível colocar 1000 lambdas (comprimento de onda) 10Gbps / lambda

1º Cabo submarino $\rightarrow$ 1 palavra a cada 10 minutos

## A internet hoje

"A internet é uma coleção de capacidades"
$\rightarrow$ Resultado da agregação de Regras

**Lei de Metcalfe**: O valor de uma rede aumenta proporcionalmente ao poder de todas as máquinas a ela acopladas.

Lei de Moore (1965) $\rightarrow$ Descreve a predição de que o poder computacional dos processadores **dobra** a cada **18 anos**.

Em 5 anos a tecnologia será
* $10 \times$ melhor
* $10 \times$ mais rápida

As empresas HOJE enfrentam menos de 1% do volume de tráfego que podem esperar em 5 anos.
$\rightarrow$ Obriga a renovação constante.

## Introdução e Conceitos Fundamentais

* O que é a internet?
* Dispositivos: Computadores, telefones, servidores...
* Componentes:
    * Enlaces (links) de comunicação
        * fibra ótica, cabo, satélite
    * Roteadores

* Internet é a rede de redes
    * **Estrutura da internet**
    * Borda (edge): Aplicações e dispositivos
    * Núcleo (core): Roteadores, rede de redes, links

links - enlace de dados
Redes de acesso: diversos meios físicos

* **A borda da rede**
* sistemas nas bordas: Rodam aplicações
* modelo cliente-servidor: Cliente solicita e recebe serviço do servidor
    * WWW (browser) + servidor
    * Cliente + servidor de e-mail
    * P2P
    * VoIP

* **Componentes da Internet**
* Protocolo: controlam envio e recepção de mensagens.
$\rightarrow$ TCP, IP, HTTP, FTP, SSH
* Inter net working $\rightarrow$ inter conexão de redes
* Padrões Internet
    * RFC $\rightarrow$ request for components *
    * IETF $\rightarrow$ internet engineering task force
* leis de internet <www.faqs.org>

* **serviços na internet**
Dois serviços de comunicação bem definidos:
* sem conexão
ou
* Orientado a conexão

* **Internet e sua explosão para o mundo**
Acesso a informação, em qualquer lugar.
Internet para negócios: World Wide Web

* **WWW**
* Hipótese $\rightarrow$ A mente humana (...) opera por associação. De posse de um item, ela parte instantâneamente para outro.
* 1988 - Xanadu Network $\rightarrow$ deu origem a "Gophen"
* 1992 / 1993 NCSA - Illinois e CERN - Suíça
"Ideia certa, criada pelos motivos errados"

* **Protocolo**
    * ... mensagens enviadas
    * ... ações em resposta ao receber mensagem

Protocolo de rede $\rightarrow$ definem o **formato**, a **ordem**, e as **ações** adotados ao **enviar** ou **receber** uma **mensagem** entre componentes de rede.

* **Borda da Rede: serviço orientado a conexão**
* Transferência de dados entre sistemas
Existe (obrigatóriamente) um "handshaking"
* preparação para iniciar transferência
* criação do "estado" (status)

## TCP - Transmission Control Protocol
* serviço orientado a conexão da internet
* Fluxo de bytes ordenado e confiável
(confirmação de entrega e retransmissão de dados no caso de falhas - ACK)
* Controle de fluxo
Não permite um transmissor rápido "afogar" um receptor mais lento
* Controle de congestionamento
Transmisso reduz a taxa de envio quando a rede congestiona.
* Overhead (causa delay/atraso)
    * Usado em HTTP, FTP, SSH (acesso remoto), SMTP
* **Borda da rede: sem conexão**
Transferência de dados entre sistemas

## UDP - User Datagram Protocol [REC 768]
Transferência de dados não confiável
Sem controle de fluxo
Sem controle de congestionamento
* Mais veloz
    * DNS utiliza UDP
    * streaming utiliza UDP
    * VoIP utiliza UDP

* **Núcleo da rede**
    * **Comutação de circuito** $\Rightarrow$ circuito dedicado por "chamada".
    * **Comutação de pacotes** $\Rightarrow$ dados seguimentados, enviados pela rede em "pedaços".

* **Comutação de circuito**
* Recursos fim a fim reservados para a chamada
* Utilizado em telecomunicação (não será o foco).
* Recursos d rede divididos e reservado em partes bem definidas
* Determinístico
* Não há compartilhamento

* **Multiplexação - Demultiplexação**
* Divisão de banda em pedaços
* Divisão por frequência (FDM)
* Divisão por tempo (TDM)
    * Possuir baixa eficiência
Um circuito de 10 Mbps só pode acomodar 10 usuários que consomem 1 Mbps cada.
* Muita ociosidade nos canais!

* **Comutação por pacotes**
* Cada fluxo de dados é dividido em pacotes
* Probabilístico
* Pacotes compartilham recursos
* Cada pacote usa a banda inteira do enlace
* Recursos são usados sob demanda
* Store and Forward
    * Pacotes passam por cada enlace (um de cada vez)
    * Roteador armaena e transmite através do enlace

Não há status
Não há setup

* Congestionamento $\Rightarrow$ Fila de pacotes em espera para o uso do enlace. (disputa pelo meio)

Comutação de Pacotes
**Vantagens**:
* Ótimos para dados em rajadas
* Compartilha recurso
* Não requer setup
**Problemas**:
* Se há congestionamento: ocorre retardo e perdas
* Como simular comportamento de circuitos?