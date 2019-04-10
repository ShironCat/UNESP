# Aula 2

## Redes de acesso e meios físicos

* Ligar dispositivos (hosts) ao primeiro roteador (**gateway**).
* Denominação:
    * 1º "hop" (salto) numa rede local.
    * "última milha" numa rede pública de comunicação (termo herdado da telefonia).

MAC:

* Camada Enlace
* Datalink
* 48 Bits Address "Endereço Físico"

### Acesso institucional

* **Rede local** (LAN) liga sistema terminal ao 1º Roteador (gateway).
* **Exemplo: ethernet**
    * Meio compartilhado ou dedicado usado para acesso ao roteador

### Meio físico: guiados ou não guiados

* Meio guiado:
    * Meio sólido: cobre, fibra.
* Meio não guiado:
    * Sinai propagam em meios abertos: rádio, wifi, micro-ondas, bluetooth.

### Par trançado (Twisted Pair - TP)

* Fios isolados de cobre.
    * Categoria 3: fio telefônico, ethernet de 10 Mbps.
        * (**Nunca usado no Brasil**)
    * Categoria 5: ethernet de 100 Mbps (mais usado).
    * Categoria **5e**: até gigabit ethernet 1000 Mbps.
    * Categoria 6: gigabit ethernet 1 Gbps até 10 Gbps.

### Meios físicos

#### cabo coaxial

* Fio (portador sinal) dentro de outro fio (blindagem).
    * Banda básica: canal único no cabo.
    * **Banda larga**: múltiplos canais no cabo.
* Bidirecional
* Uso era comum em **Ethernet** de 10 Mbps.
* Mas cabo coaxial suporta bandas maiores.
* Exemplo: internet cable ("NET virtua") a **240 Mbps**.

#### fibra ótica

Cabo de **fibra ótica**:

* Fibra de silício iluminado por pulsos de luz
* Operações de alta velocidade:
    * Mais comum atualmente suporte de 1 a 10 Gbps.
* Baixa taxa de erro.
* 2 tipos de fibra:
    * Monomodo.
    * Multimodo.

#### rádio

* Não guiado
* Usa o espectro eletromagnético.
* Bidirecional.
* Efeitos sobre propagação de ambiente:
    * Reflexão.
    * Obstrução por objetos.
    * Interferência.

* **Microondas terrestres**
    * Canais até 155 Mbps
* **Rede local** wi-fi
    * 802.11g, 802.11n, 802.11ac
    * 54 Mbps, 300 Mbps, 600 Mbps, 800 Mbps, 1200 Mbps
    * 2.4 GHz e 5 GHz
* **Longa distância** (p.ex., celular)
    * 3G e 4G em alta velocidade
* **Satélite**
    * Canais de até 50 Mbps (ou múltiplos canais menores)
    * Retardo ponto a ponto de 270 ms.
    * Geossíncrono x LEOS (Low Earth Orbit Satellite)

### Acesso residencial

#### acesso ponto a ponto

* **ADSL: Asymmetric Digital Subscriber Line**
    * Até 34 Mbps de roteador a casa.
    * Até 4 Mbps de casa ao roteador.
    * Disponibilidade de ADSL: Telefônica, Oi, etc...

#### cable modem

* **HFC: Hybrid Fiber Coax (Cable)**
    * Assimétrico
* **Responsabilidade do Headend**

### Como surgiu Banda Larga

* **John Doerr** e **Bruce Ranenel** (intel)
* **Dezembro de 1944**: feira **Western Cable Show** em Anahein (CA/USA).
    * Stand da **Motorola**: demonstração de uma caixa de US$300,00

## Atrasos/Delays

### Atrasos em redes de pacotes

* Pacotes experimentam **atrasos** em caminhos fim a fim.

Atraso total de nó

Transmissão; Propagação; Processamento; Enfileiramento.

### Atrasos ou retardos (delays)

Enquanto um pacote viaja

### Atraso de Processamento

* **Atraso de Processamento ($d_{proc}$)**: O tempo para examinar o cabeçalho do pacote, e determinar o que fazer.
* Então tipicamente na ordem dos **microsegundos**, ou menores. Após este processamento, o router envia o pacote à fila que precede a ligação até o router B.

### Atraso de Fila

* **atraso de enfileiramento $d_{queue} \rightarrow$** depende da quantidade de outros pacotes, que chegaram antes, e que estão na fila aguardando a transmissão através do link.
* Se a fila estiver vazia

### Atraso de Transmissão $d_{trans}$

Depende da **Largura de Banda** do enlace.

* Tamanho do pacote $\rightarrow$ **L bits**.
* Banda do link entre roteadores $\rightarrow$ **R bits/sec**.

**R** é a **taxa de transmissão**.

* **Atraso de transmissão** $d_{queue} = L / R$

Tempo para enviar o pacote R

banda (depende da tecnologa e do SLA)

* R = banda do enlace (bps)
* L = tamanho do pacote (bits)
* Tempo (atraso) para transmitir pacote do enlace $d_{trans} = L / R$

Quantidade de bits dividido pela velocidade disponível.

Não confundir transmissão com propagação!

### Atraso de **Propagação**

* **Atraso da propagação** $\rightarrow$ Tempo para viajar ao longo do link.

Retardo de **propagação**:

* s = distância do enlace
* v = velocidade de propagação. ($~2 \times 10^{8}$ metros/sec)
* **Atraso de propagação** = distância / velocidade

Esses atrasos acontecem em cada um dos nós.

### Em redes de pacotes

Considerando $d_{prop}$; $d_{queue}$

### Queue delay

### "Drop" de pacotes

* **A capacidade da fila não é infinita**
    * Atrasos não tendem a infinito: pacotes **se perdem**.
* **Pacote pode chegar e encontrar uma fila cheia**.
    * Não há como armazenar ou tratar o pacote.
    * Então routes **descarta** o pacote $\rightarrow$ **"drop" do pacote**
* O desempenho em um nó não é medido apenas pelos atrasos, mas também com a probabilidade da perda de pacotes

## Camada de Protocolo

**Redes são complexas!**

* Muitos componentes:
    * Hosts.
    * Roteadores.
    * Links.
    * Aplicações.
    * Protocolos.
    * Hardware, software...

**Pergunta**: Como **organizar** a estrutura de rede?

### Por que usar camadas?

* Lidar com sistemas complexos
* Modelo de referência
* Manutenção e atualização facilitados

### Pilha de protocolo da Internet

* **Aplicação**: suporta aplicações de rede
* **Transporte**: roteamento de pacotes
* **Enlace**: LAN
* Física: bits nos cabos

conexão de redes (TCP/IP)

rede local

### Modelo de Referência TCP/IP

4. Aplicação
3. Transporte
2. Internet
1. Host/Rede

### Modelo TCP/IP x pilha TCP/IP

4. Aplicação
3. Transporte
2. Internet
1. Host/Rede

5. Aplicação
4. Transporte
3. Rede
2. Enlace
1. Física

### Modelo de rede ISO/OSI

* Modelo de 7 camadas
* Nunca implementado de fato.

### Relação ISO/OSI x TCP/IP

Aplicação

Apresentação

Sessão

Transporte

Rede

Ligação de Dados

Física

### Camadas: comunicação lógica

* Usa os serviços da camada de baixo.

"Entidade-par" de origem se comunica **logicamente** com "entidade-par" no destino

### Camada de protocolos dados

* Cada camada **recebe** dados da **camada superior**.
* **Acrescenta cabeçalho** com informação para criar nova unidade de dados.
* **Entrega** a nova unidade de dados para **camadas inferiores**.

## Backbones, NAPs e ISPs

* Internet é **hierárquica**.
* Dispositivos são conectados aos **provedores de serviço locais da Internet** (Internet Service Providers - ISPs).
* **ISPs locais** são conectados a **ISPs regionais ou nacionais**.
* Os ISPs nacionais e internacionais são conectados juntos no topo do nó mais elevado na hierarquia.

* Ponto mais alto da hierarquia: **ISPs nacionais**.

* Como a hierarquia se

### Transit ou peering

Solução:

* Introduzir **pontos de conexão** ligando os provedores Regionais e Nacionais.
* Há duas maneiras de fazer isso:
    * Como um **Ponto de Trânsito** ("transit")
    * Ou com **Ponto de Troca de Tráfego (PTT)**
        * Também chamados de **NAPS** (Network Access Points).
    * Interconectam provedores.
* Veremos a diferença entre eles.

### Peering x Transit

* "Transit: dinheiro
    * the advertisement by an Internet service provider (ISP) of routes to a costumer's Internet Protocol address to the other ISPs who constitute the rest of the Internet, thereby soliciting inbound traffic from them on behalf

* **Peering**: troca voluntária de dados "**voluntary** interconnection of administratively separate Internet networks for the purpose of exchanging traffic between the

AS $\rightarrow$ Autonomous System

* Só eles podem realizar peering