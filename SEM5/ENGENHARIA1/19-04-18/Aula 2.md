# Aula 2

## O produto e o processo

### O produto

* Importância do software
    * "motor que dirige a tomada de decisões nos negócios"
    * Presente em diversos setores da economia: transportes, saúde, telecomunicações, militares, processos industriais, etc.
* Tecnologias que tornem mais fácil, rápido e menos dispendiosa a construção de programas de alta qualidade
* Software = duplo papel
    * Produto: transformador de informação
    * Veículo para entrega do produto: base para controle do computador, comunicação da informação e para a criação e controle de outros programas.

### Motivações para a criação de Software mais sofisticado

* Melhora no desempenho do hardware
* Aumento na capacidade de armazenamento
* Variedade de opções de entrada e saída.
* Alerta:
    * Sofisticação e variedade podem produzir resultados mafníficos
    * Podem causar enormes problemas para quem precisa construir software mais complexos.

### Problemas que ainda existem no desenvolvimento do produto

* Habilidade em construir software deixa a desejar em relação ao potencial do hardware
* Construção do software não é rápida o suficiente para atender as necessidades do mercado
* Sociedade depende cada vez mais de software confiável
* Esforço para construir software confiável e de qualidade é muito grande
* Suporte aos programas existentes é apoiado por projetos pobres e recursos inadequados

### Dúvidas que persistem

* Por que leva tanto tempo para concluir software?
* Por que os custos de desenvolvimento são tão altos?
* Por que não podemos achar todos os erros antes de entregar o software ao cliente?
* Por que gastamos tanto tempo e esforço mantendo programas existentes?
* Por ue continuamos a ter dificuldade em avaliar o progresso enquanto o software é desenvolvido e mantido?

### Características do software - Produto

* O software é desenvolvido ou passa por um processo de engenharia
* Não é manufaturado no sentido clássico
* Desenvolvimento, na grande maioria, sob encomenda
* O software não se desgasta, mas se deteriora

### Causa dos problemas no desenvolvimento de software

1. Natureza do software
    * O software é um elemento de sistema lógico e não físico. O sucesso é medido pela qualidade de uma única entidade e não pela qualidade de muitas entidades manufaturadas
2. Falhas das pessoas
    * Gerentes sem nenhum background em software
    * Os profissionais têm recebido pouco treinamento formal em novas técnicas para o desenvolvimento de software
    * Resistência a mudanças
3. Mitos do software
    * Atitudes enganosas que causam sérios problemas, tanto para gerentes quanto para pessoal técnico

### Mitos

* Mitos da gerência
    * Um livro cheio de padrões e procedimentos para elaboração de software fornece tudo que a equipe precisa saber
    * O atraso pode ser corrigido adicionando mais programadores
    * A terceirização de um projeto de software permite relaxar
* Mitos do cliente
    * O estabelecimento geral de objetivos é suficiente para iniciar o desenvolvimento, pois os detalhes podem ser fornecidos posteriormente
    * Os requisitos do projeto mudam continuamente e as mudanças podem ser facilmente acomodadas porque é software flexível
* Mitos do profissional
    * O trabalho termina quando escrevemos o programa e o fazemos funcionar
    * Avaliação de qualidade só é possível quando existe um programa "rodando"
    * O único produto de trabalho (artefato) que pode ser entregue para um projeto de software bem-sucedido é o programa executável
    * A Engenharia de Software vai nos fazer criar documentação volumosa e desnecessária que certamente nos atrasará

### Princípios gerais

* Para criar um bom produto
    * Razão de existir - gerar valor para o usuário
    * O projeto deve ser o mais simples possível - Compreender e manter
    * Visão clara do projeto - visão arquitetônica adequada
    * O que um produz os outros consomem - simples de entender
    * Aberto ao futuro - adaptar a mudanças
    * Reutilização
    * Pensar antes de agir

### O Processo

* Definição
    * Conjunto de atividades necessárias para transformar os requisitos do usuário em um software de qualidade
        * Processo = Engenharia de software?
    * Processo define a abordagem adotada quando o software é elaborado
    * Engenharia de software engloba também as tecnologias, como métodos e ferramentas automatizadas para a construção do software

### Arcabouço de processo

* Identificação de um pequeno número de atividades aplicáveis a todos os projetos
    * Atividades guarda-chuva: são aplicáveis durante todo o processo de software
    * Cada atividade é composta por ações
    * Ações são compostas por tarefas

### Arcabouço de processo genérico

* Comunicação
    * Comunicação e colaboração com o cliente
        * Levantamento de requisitos
* Planejamento
    * Plano para o trabalho
        * Tarefas a serem realizadas
        * Riscos prováveis
        * Recursos necessários
        * Cronograma
* Modelagem
    * Criação de modelos que permitam o entendimento dos requisitos
        * Modelo dos componentes
        * Modelo do Banco de Dados
* Construção
    * Geração de código e testes
        * Implementação
        * Teste unitário
* Implantação
    * Entrega do software ao cliente

### Atividades guarda-chuva

* Acompanhamento e controle de projetos
    * Análise de progresso e medidas para cumprir cronograma
* Gestão de riscos
    * Avaliar os riscos que podem afetar os objetivos
* Garantia de qualidade
    * Conduzir atividades que garantem a qualidade
* Revisões técnicas formais
    * Avaliar os artefatos do software

### Por que focar o processo de software?

* Foco no produto
    * Não se aplica o conhecimento de como fazer um produto melhor
* Foco no processo
    * Repetição de resultados
    * Tendências futuras do projeto
    * Características do produto

### Modelo de processo de software

* Representação abstrata de um processo de software
* Para muitos sistemas de grande porte
    * Processo diferentes são usados para desenvolver cada parte do software
* Modelos ajudam no controle e na coordenação de um projeto de software
* Definem as atividades que devem ser realizadas
* São selecionados com base:
    * Natureza e aplicação do projeto
    * Métodos e ferramentas a serem utilizados
    * Controles e produtos que precisam ser entregues

### 1. Modelo sequencial linear / ciclo de vida clássico / modelo cascata

* Característica:
    * Abordagem sequencial para o desenvolvimento de software
    * Requisitos bem definidos e estáveis
* Problemas
    * Projetos reais raramente seguem o fluxo sequencial que o modelo propõe
    * Dificuldade em acomodar a incerteza natural que existe no começo de vários projetos
    * Versão executável não vai ficar disponível até o projeto terminar

### 2. Modelos incrementais

* Característica:
    * Produzir software em incrementos
    * Cada incremente fornece um conjunto funcional aos usuários
* 2.1 Modelo incremental
    * Combina elementos do modelo em cascata aplicado de maneira iterativa
    * Cada sequencia linear produz "incrementos" (produto operacional a cada incremento) do software passíveis a serem entregues
    * Vantagens:
        * Os primeiros incrementos podem ser implementados com menos pessoas
        * Os incrementos podem ser planejados para gerir os riscos técnicos
* 2.2 Modelo RAD (Rapid Application Development)
    * Ciclo de desenvolvimento extremamente curto
    * Construção baseada em componentes
    * Usado quando os requisitos são bem compreendidos e o objetivo do projeto restrito
    * Problemas:
        * Em projetos grandes, exige recursos humanos suficientes para criar um número adequado de equipes
        * Exige desenvolvedores e clientes compromissados com atividades continuamente rápidas
        * Nem todos os tipos de aplicações são apropriadas para o RAD - não é adequado quando os riscos técnicos forem elevados

### 3. Modelos evolucionários