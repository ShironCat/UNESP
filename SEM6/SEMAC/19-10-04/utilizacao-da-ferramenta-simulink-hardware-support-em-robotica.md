# Utilização da ferramenta Simulink Hardware Support em robótica

Simulink para Microcontroladores e Sistemas Embarcados

LER - Laboratório de Engenharia Robótica

Prof. Dr. Luis Antonio Bassora

Centro Universitário do Norte Paulista (UNORP)

## Roteiro

* Introdução
* Conceitos
* Exemplo

## Introdução

Comunicação do MATLAB com outros dispositivos

## Conceitos

* MATLAB
* SIMULINK

## MATLAB (MATrix LABoratory)

* Software de Cálculo Numérico
* Desenvolvido pela Mathworks por cientistas e engenheiros
* Possui ambiente computacional complexo
* Utiliza matrizes como base para os cálculos
* Utilizado para solucionar problemas de origem física, química, biológica

## SIMULINK (Aplicativo do MATLAB)

* Para Modelagem, Simulação e Análise de Sistemas Dinâmicos e Plantas Físicas;
* Descreve Sistemas na forma de Diagrama de Blocos (Sistemas de Controle, de Comunicação e de Processamento de Sinais);
* Possui uma Bilioteca de Blocos Diversificada, com operadores lógicos, matemáticos

## Exemplo de Aplicações

* Imagem de Ressonância Magnética.
* Identificação de tumores na mama.

---

* Reconhecimento de Gestos.
* Reconhecimento de Placas de Trânsito.

---

* Estrutura de modelamento em um grau de liberdade
* Modelo físico construído no Simulink

---

* Simulação de Aeromodelos

---

* Prótese Mecânica

---

* Software de Controle de Carro Autônomo
* Leitura de sensores de um dispositivo com sistema embarcado

---

* Módulos de E S FPGA configuráveis
* Módulos de E / S FPGA configuráveis

## Simulink Hardware Support

Hardware Suportado pelo Simulink - Pacotes

* Dispositivos Android
  * Sensores;
  * Captura e reprodução de Áudio;
  * Entrada de câmera e de vídeo;
  * Interface de rede;
  * Etc...
* Dispositivos Apple iOS

## Hardware Support

* Microcontroles e sistemas embarcados
  * Arduino
    * Arduino Mega 2560

## Projeto Utilizando Simulink Hardware Support

Projeto de Iniciação Científica

(Alex Garrefa/Engenharia Elétrica)

* Implementar a Etapa de Controle de um robô de equilíbrio dinâmico de sistemas instável baseado no modelo de pêndulo invertido. (K3NK0)
* Portar o código desenvolvido paralelamente por outros participantes do projeto em ambiente de programação comum, isto é, por meio de algoritmos de linguagem C para Arduino para o Simulink no modelo de diagrama de blocos.

## Controle de um Robô de Equilíbrio Dinâmico

**Metodologia**

* Software necessário:
  * MATLAB 2015b

---

**MPU6050**

Sensor micro-eletromecânico