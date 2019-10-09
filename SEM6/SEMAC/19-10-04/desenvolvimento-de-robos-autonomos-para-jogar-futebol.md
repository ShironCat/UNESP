# Desenvolvimento de Robôs Autônomos para Jogar Futebol

Prof. Dr. Marcos Máximo

E-mail: maximo.marcos@gmail.com

## RoboCup 2D Soccer Simulation

* 11 robôs (+ técnico) simulados por time.
* Completamente autônomos!
* Robôs são processos separados.
* Simulação simplificada: robô sabe andar, chutar etc.
* Foco na estratégia de cooperação entre os agentes

## RoboCup 3D Soccer Simulation

* 11 robôs simulados por time.
* Robôs são processos separados.
* Modelo de robô é o Nao.
* Física realista.
* Sensores e atuadores semelhantes aos do Nao.

## Very Small Size (VSS)

* 3 robôs por time.
* Câmera em cima do campo.
* Robôs controlados por controlador central.

## RoboCup Small Size

* 6 robôs por time.
* Câmera em cima do campo.
* Robôs controlados por computador central.

## Robô Small Size

* Movimento omnidirecional.
* Dribbler.
* Kicker.
* Chipper.

## Futebol Humanoide

* 4 robôs por time.
* Sem intervenção humana.
* Tópicos de pesquisa:
  * Detecção de objetos usando Aprendizado de Maquina

## Robô Chape

* 53 cm de altura.
* Computador: Intel Core i5 @ 2.6 GHz dual-core.
* PCBs: CMB, PWB, RIB.
* Bateria LiPo 4 células.
* 20 servos Dynamixel MX-28AT

## Robô Chape 2ª Geração (desenvolvimento)

* 65 cm de altura.
* Computador: Intel Core i7 @ 3.5 dual-core.
* Intel Movidius 2.
* PCMB e RIB.
* Bateria de LiPo 4 células.
* 8 servos Dynamixel MX-28AT.
* 12 servos Dynamixel

## Mecânica - Fabricação

Peças em alumínio são fresada pelos alunos usando uma fresa CNC Sherline.

## Eletrônica

* Câmera Logitech

## OpenAI

* OpenAI Five: venceu melhor time de humanos no Dota 2 (13 de abril de 2019).
* 180 anos de treino por dia. 128k núcleos de CPUs e 256 GPUs.

## Starcraft 2

* Venceu jogadores profissionais em Starcraft 2.
* Por enquanto, joga apenas com Protoss.

## Curriculum-Based Deep RL Applied to Humanoid Robots

* Mestrado do Alexandre Muzio, 2018.

## Abordagem Hierárquica

* Aprendizado por Reforço aprende "High Level Controller".

## Corrida de Humanoide

* Espaço de estados:

\\[
  s = (x, y, \phi, v_{x}, v_{y}, v_{\phi})
\\]

* Espaço de ações:

\\[
  a = (v_{x, ref}, v_{y, ref}, v_{\phi, ref})
\\]

* Função de recompensa:

\\[
  r(s, a) = c_{0}v_{x} - c_{1}(v_{\phi}^{2} + v_{y}^{2}) - c_{2}a^{2} - c_{3}y^{2} + c_{4}1{\text{linha de chegada}}
\\]

## Aprendizado de Chute (PPO)

* Técnicas de *Deep Reinforcement Learning* ficam presas em máximos locais.
* Uma abordagem híbrida é muito efetiva para aprendizado de movientos de alto desempenho.
  1. Copiar movimento conhecido (*imitation learning*).

## Treinamento Distribuído

* ***Speed up* de ~110 ao distribuir no cluster.**
* **740 milhões de amostras**

## Aprendendo a Passar

* Usar supervisionado + reforço para aprender chutes para várias distâncias

## Corrida

* Proximal Policy Optimization (PPO).
* Informações de vários sensores.

## Visão Computacional

* Bola e traves: rede neural convolucional baseada em YOLO.
* Bordas do campo e linhas: visão clássica com OpenCV (segmentação de cores, formação de *blobs*)

## YOLO

* YOLO: *You Only Look Once.*
* Divide imagem em células.

## Visão do Humanoide

* IC do Lucas Steuernagel.