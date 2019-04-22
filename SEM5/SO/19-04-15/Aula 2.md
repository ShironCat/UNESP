# Aula 2

## Introdução sobre SOs

Um sistema computacional moderno consiste em diversos componentes como: **processadores**, **memória principal**, discos, periféricos, dentre outros. Ou seja, um sistema **complexo**. Um programador seria incapaz de entender como tudo funciona, **gerenciar** todos esses **componentes** e **usá-los** de **maneira otimizada**. Assim, os sistemas computacionais possuem um dispositivo de software denominado **sistema operacional**, para cuidar desses componentes.

O objetivo do S.O. é fornecer aos programas do usuário um **modelo mais simples** de lidar com o **gerenciamento de recursos**.

Na parte inferior, o **hardware** (física). Na parte superior, o **software** (lógica). O S.O. é parte básica do sistema de software e opera em **modo núcleo** (supervisor). Neste caso, ele tem acesso completo ao hardware e pode **executar qualquer instrução**. O restante da camada de software opera em **modo usuário**, no qual apenas um **subconjunto** de **instruções** está disponível.

Assim, um S.O.:

* Fornece aos programadores um **conjunto de recursos abstratos** claros em vez de confusos recursos de hardware;
* Gerenciar os recursos de hardware.

### O S.O. como uma máquina extendida

A **arquitetura** da maioria dos computadores em nível de linguagem de máquina é primitiva e de difícil programação. Assim, gerenciar essas **abstrações** é ponto chave do S.O. Transformar o que é "**feio**" em algo "**bonito**".

### S.O. como um gerenciador de recursos

Agora em uma visão bottom-up, permite-se que múltiplos recursos sejam **compartilhados**, por exemplo, com o uso da **multiprogramação**. Estes podem usufruir de recursos tanto no **tempo** (**execução**) quanto no **espaço** (**armazenamento**).