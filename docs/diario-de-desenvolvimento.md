# Diário de desenvolvimento

## 01/11/2026 - A origem da curiosidade

Este projeto nasceu de uma curiosidade que me acompanha desde a infância: **como o ser humano consegue transformar minerais extraídos da natureza em componentes capazes de realizar operações tão complexas quanto as de um computador?** Hoje, essas tecnologias estão presentes em praticamente todos os aspectos da nossa vida, dos computadores e videogames às televisões e aos eletrodomésticos. Mas, apesar de convivermos diariamente com esses dispositivos, raramente paramos para pensar em como eles realmente funcionam.

Talvez limitar essa curiosidade ao computador seja restritivo. Ao longo dos meus estudos, aprendi sobre programação, bancos de dados, redes e diversas outras áreas da tecnologia. Entretanto, percebi que havia uma peça fundamental sobre a qual eu sabia muito pouco: o processador. Eu entendia como escrever programas e manipular dados, mas nunca havia explorado em profundidade como o hardware responsável por executar essas instruções era construído, como funcionava internamente ou quais materiais tornavam tudo isso possível.

Ao investigar essas questões, descobri que as arquiteturas utilizadas em muitos dos processadores comerciais que conhecemos, como os da Intel e da AMD, além dos chips Snapdragon presentes em dispositivos móveis, envolvem tecnologias proprietárias e segredos industriais. Isso tornou o desafio ainda mais interessante: como aprender a construir um processador quando boa parte da tecnologia utilizada pela indústria não está aberta para estudo e experimentação?

Foi nesse caminho que descobri o **RISC-V, uma arquitetura de conjunto de instruções aberta e livre de royalties**. Diferentemente das arquiteturas proprietárias, ela permite que estudantes, pesquisadores, empresas e entusiastas estudem suas especificações e desenvolvam suas próprias implementações. Vejo nisso não apenas uma oportunidade de aprendizado, mas também um caminho para ampliar o acesso ao conhecimento, incentivar a inovação e contribuir para a soberania tecnológica do Brasil. Acredito que tecnologias abertas como essa merecem ser mais exploradas, especialmente em um mundo no qual o domínio do hardware e do software tem importância estratégica.

Ao longo deste projeto, quero aprofundar meus conhecimentos em programação de baixo nível, arquitetura de computadores, lógica digital e desenvolvimento de hardware. Meu objetivo é compreender, nos mínimos detalhes, como um processador funciona: desde a interpretação de uma instrução até sua execução por circuitos lógicos. Quero sair da abstração do software e chegar mais perto do funcionamento físico da máquina, explorando cada etapa desse processo.

Mais do que construir um processador funcional, quero entender o que existe por trás dele. Quero responder a perguntas que surgiram muito antes de eu conhecer as linguagens de programação, os bancos de dados ou as redes de computadores. De certa forma, este projeto é uma oportunidade de revisitar aquela curiosidade da infância, agora com as ferramentas e os conhecimentos necessários para investigá-la de verdade.

Para dar os primeiros passos, decidi estudar **Rust e Arduino**, explorando a relação entre programação, software de baixo nível e hardware. A escolha do Rust também representa uma oportunidade de conhecer uma linguagem com características diferentes das linguagens que já fazem parte da minha experiência, especialmente C e C++. Com o Arduino, pretendo experimentar a interação entre código e componentes físicos, construindo uma base prática para avançar, gradualmente, em direção à lógica digital, à arquitetura RISC-V e à implementação de um processador em FPGA.

**Este diário será o registro dessa jornada:** os conceitos que aprender, os experimentos que realizar, os erros que encontrar e as soluções que desenvolver. Não espero dominar todas essas áreas de imediato, mas quero construir esse conhecimento de forma progressiva, compreendendo não apenas como fazer as coisas funcionarem, mas principalmente por que elas funcionam.

Afinal, por trás de toda essa tecnologia existe uma pergunta simples que me acompanha desde criança: **como transformamos os recursos da natureza em máquinas capazes de executar nossas ideias?** É essa pergunta que pretendo explorar ao longo deste projeto.

## 01/11/2026 -Definição do plano de estudos de Rust

Para iniciar os estudos, selecionei três recursos gratuitos que se complementam e permitem aprender a linguagem de forma progressiva, combinando teoria, exercícios práticos e experimentação.

### Recursos de estudo

1. **Teoria:** [The Rust Programming Language](https://doc.rust-lang.org/book/) — livro oficial que apresenta os principais conceitos da linguagem, desde os fundamentos até tópicos mais avançados.
2. **Exercícios:** [Rustlings](https://rustlings.rust-lang.org/) — conjunto de exercícios práticos que ajudam a fixar os conceitos estudados e a desenvolver familiaridade com a sintaxe e as particularidades do Rust.
3. **Experimentação:** [Rust Playground](https://play.rust-lang.org/) — ambiente on-line que permite escrever, compilar e executar pequenos programas em Rust diretamente no navegador, sem a necessidade de configurar um ambiente de desenvolvimento local.

A combinação desses três recursos oferece uma abordagem equilibrada de aprendizado: o livro apresenta os conceitos, o Rustlings permite praticá-los e o Rust Playground facilita a experimentação livre. Além disso, todos estão disponíveis gratuitamente.

### Etapas de aprendizagem

O plano foi organizado para construir uma base sólida em Rust e, gradualmente, direcionar os estudos para os conceitos necessários ao desenvolvimento de um processador RISC-V.

| Etapa | Conteúdo | O bjetivo |
| --- | --- | --- |
| 1 | Tipos, variáveis, funções e controle de fluxo | Compreender os fundamentos da linguagem e desenvolver os primeiros programas. |
| 2 | Arrays, tuplas, slices e referências | Aprender a organizar dados e trabalhar com diferentes formas de acesso à memória. |
| 3 | Ownership, borrowing e lifetimes | Entender o gerenciamento de memória e os mecanismos de segurança do Rust. |
| 4 | Structs, enums e pattern matching | Representar estruturas de dados e modelar comportamentos de maneira organizada. |
| 5 | Manipulação de bits e operações binárias | Trabalhar com representação binária, máscaras de bits, deslocamentos e operações lógicas. |
| 6 | Leitura e decodificação de instruções RISC-V | Compreender como instruções de máquina são representadas em binário e interpretadas por um programa. |
| 7 | Desenvolvimento de um simulador RV32I em Rust | Aplicar os conhecimentos adquiridos na implementação de um simulador capaz de interpretar e executar instruções da arquitetura RISC-V RV32I. |

### Objetivo final

Ao concluir essas etapas, espero ter conhecimentos suficientes de Rust para desenvolver um **simulador funcional da arquitetura RISC-V RV32I**.

Esse simulador será um passo importante para o objetivo principal do projeto: compreender como um processador funciona internamente, desde a representação binária de uma instrução até sua execução.

A ideia é utilizar o simulador como uma ponte entre o desenvolvimento de software e a arquitetura de computadores. Antes de implementar um processador em hardware, poderei experimentar conceitos como registradores, memória, decodificação de instruções e fluxo de execução por meio de um programa em Rust.

Dessa forma, cada etapa do aprendizado terá uma aplicação prática no projeto, evitando que o estudo da linguagem se limite à memorização de sintaxe e exemplos isolados.

### [Hello World!](../rust/fundamentos/hello_world.rs)

A construção  e compilação foi relativamente simples, me passando a impressão de interface amigavel.

## 06/11/2026 — Primeiros passos com Arduino

Entre o início dos meus estudos de Rust e o dia de hoje, meu kit Arduino finalmente foi entregue. Aproveitei esse período para começar a estudar os fundamentos de eletrônica e realizar alguns experimentos com os motores que acompanham o kit, inicialmente motivado por um projeto pessoal.

É impressionante perceber o que esses pequenos microcontroladores são capazes de fazer. Com poucas linhas de código e alguns componentes eletrônicos, conseguimos controlar movimentos, acionar dispositivos e construir sistemas que interagem diretamente com o mundo físico. Entretanto, durante esses primeiros experimentos, percebi que ainda enxergo boa parte do funcionamento do microcontrolador como uma espécie de **caixa-preta**: escrevo o código, compilo e envio para a placa, mas ainda não compreendo completamente o que acontece entre essas etapas.

Ao experimentar um servomotor e um motor de passo, algumas dúvidas começaram a surgir. Como os sinais elétricos são enviados pelo Arduino e interpretados por esses componentes? Por que o motor de passo necessita de um driver para funcionar corretamente, enquanto o servomotor pode ser conectado diretamente aos pinos da placa? Como funcionam os sinais PWM (Pulse Width Modulation) gerados pelo Arduino? O que acontece durante a gravação do programa compilado no microcontrolador? Como ele armazena, interpreta e executa essas instruções?

Essas são algumas das questões que ainda quero investigar. Percebi que simplesmente aprender a utilizar bibliotecas e escrever códigos para controlar componentes não é suficiente para o que pretendo alcançar com este projeto. Quero entender o que acontece por trás dessas abstrações, desde os sinais elétricos até a execução das instruções pelo microcontrolador.

Além das questões técnicas, esses primeiros contatos também despertaram reflexões sobre a própria indústria de semicondutores. Quanto custa produzir um microcontrolador? Quais recursos, tecnologias e conhecimentos são necessários para fabricá-lo? Por que ainda temos tanta dependência de componentes produzidos no exterior?

Acredito que seria extremamente importante para o Brasil desenvolver maior autonomia nessa indústria e incentivar uma cultura de experimentação e desenvolvimento tecnológico desde o ensino básico. Imagino quantos jovens com curiosidades semelhantes à minha poderiam ser impactados se tivessem acesso a ferramentas, componentes e oportunidades para experimentar desde cedo. Esse conhecimento poderia gerar contribuições em diversos setores, inclusive em áreas nas quais o Brasil já possui grande relevância, como a agropecuária. Afinal, a tecnologia embarcada, a automação e os sistemas inteligentes têm um enorme potencial de transformação nesses segmentos.

Infelizmente, hoje o acesso a componentes eletrônicos e ferramentas de desenvolvimento ainda pode ser bastante limitado pelo custo e pela disponibilidade. Isso reforça minha percepção de que democratizar o acesso ao conhecimento e à experimentação é tão importante quanto desenvolver a própria tecnologia.

Para dar continuidade ao aprendizado e tentar responder algumas dessas perguntas na prática, decidi iniciar um novo experimento: **desenvolver um videogame utilizando uma Raspberry Pi Pico com o microcontrolador RP2040, reaproveitando um controle de videogame retrô que já possuo.**

A ideia é utilizar esse projeto como uma oportunidade para explorar melhor a interação entre software e hardware, compreender como os microcontroladores trabalham com entradas e saídas, estudar comunicação com periféricos e descobrir como transformar código em algo que efetivamente acontece no mundo físico.

Mais uma vez, o objetivo não é apenas fazer funcionar, mas entender como e por que funciona. Afinal, cada novo experimento aproxima um pouco mais aquela curiosidade inicial da compreensão de como essas máquinas são construídas.

## 25/11/2026 — Primeiros experimentos com Rust e engenharia reversa de hardware

Depois dos primeiros contatos com Rust e Arduino, comecei a direcionar meus estudos para pequenos experimentos que tivessem relação mais direta com o objetivo principal deste projeto: compreender como um processador funciona e como o software interage com o hardware.

### Rust: saindo da teoria para a prática

Nos estudos de Rust, avancei para os primeiros exercícios práticos, utilizando os conceitos apresentados no livro oficial da linguagem. Um dos primeiros desafios foi desenvolver o tradicional *Guessing Game*, um jogo de adivinhação que utiliza entrada de dados pelo terminal, estruturas de repetição, comparação de valores e tratamento de erros.

Esse exercício foi interessante principalmente para entender como o Rust trabalha com entradas do usuário e conversão de tipos. Também comecei a perceber algumas particularidades da linguagem, como o tratamento de resultados por meio de `Result` e `match`, além da necessidade de lidar explicitamente com situações em que uma operação pode falhar.

Depois desse exercício, decidi criar algo mais próximo do objetivo final do projeto: uma pequena ALU (*Arithmetic Logic Unit*).

A ideia foi desenvolver uma calculadora simples que recebesse dois valores e permitisse realizar operações de adição e subtração. Embora seja um programa bastante simples, ele representa um primeiro contato com um dos componentes fundamentais de qualquer processador.

Uma ALU é responsável por executar operações aritméticas e lógicas sobre os dados utilizados pelo processador. Naturalmente, minha implementação ainda está muito distante de uma unidade real, mas considero importante começar a reproduzir esses conceitos por meio de software antes de avançar para a implementação em hardware.

Nesse primeiro momento, utilizei o tipo `u32`, estruturas condicionais, `match` e `loop`. Também precisei trabalhar com a conversão de entradas textuais para valores numéricos.

O próximo passo será expandir essa pequena ALU, adicionando novas operações e explorando melhor a representação binária dos números.

### Arduino: engenharia reversa de um controle de videogame retrô

Uma das partes mais interessantes desse período foi a tentativa de reaproveitar um controle de videogame antigo, proveniente de um DVD Game, para utilizá-lo no projeto do meu próprio console com Raspberry Pi Pico e RP2040.

Inicialmente, tinha apenas uma placa de circuito com um chip encapsulado em resina (conhecido como *chip-on-board* ou simplesmente "gota preta") e cinco fios conectados a ela, sem qualquer identificação. O conector original possuía nove posições, mas apenas cinco delas estavam efetivamente conectadas. Não havia documentação técnica disponível e, portanto, precisei descobrir como aquele circuito funcionava por conta própria.

Decidi abordar o problema como um exercício de engenharia reversa, começando pela análise física da placa e utilizando um multímetro para investigar suas conexões.

**1. Identificação da alimentação e do aterramento**

O primeiro desafio foi descobrir a função de cada um dos cinco fios. Utilizando o multímetro na escala de continuidade, comecei a verificar as conexões entre os contatos dos botões e os fios da placa.

Com esses testes, identifiquei que o fio amarelo estava conectado ao ponto comum de oito dos dez botões, indicando que provavelmente era o GND (terra).

Para identificar a alimentação, utilizei a escala de teste de diodo do multímetro. Ao realizar medições entre os fios, encontrei uma queda de tensão de aproximadamente 700 mV entre o fio branco e o amarelo, com a ponta COM conectada ao branco. Esse comportamento indicou a presença de estruturas semicondutoras internas, permitindo levantar a hipótese de que o fio branco correspondia ao VCC (+5 V).

Essa etapa foi importante porque não queria simplesmente conectar uma alimentação sem conhecer minimamente a estrutura elétrica do circuito e correr o risco de danificar o chip original.

**2. Investigação da comunicação digital com Arduino**

Depois de identificar os possíveis fios de alimentação, comecei a investigar os três fios restantes. Minha hipótese era que o controle utilizava algum tipo de comunicação digital para transmitir os estados dos botões ao console.

Para isso, utilizei meu Arduino UNO R3 como ferramenta de investigação. A ideia era observar os sinais elétricos e tentar identificar possíveis padrões de comunicação.

Após algumas combinações e experimentos, consegui identificar três sinais:

- **DATA (vermelho):** responsável pela transmissão dos dados referentes aos botões.
- **CLOCK (azul):** responsável pela sincronização e avanço da leitura dos bits.
- **LATCH (marrom):** utilizado para controlar a captura ou seleção dos estados dos botões.

Desenvolvi um programa em Arduino para gerar os sinais de controle, realizar as leituras digitais e apresentar os resultados no Monitor Serial. Também configurei a comunicação em 115200 baud e implementei uma comparação entre as leituras atuais e anteriores, exibindo somente quando havia alterações nos estados dos botões.

Com isso, consegui observar uma sequência binária correspondente aos acionamentos do controle, aproximando-me da compreensão de como o chip original transmite suas informações.

**3. Descoberta de uma arquitetura de leitura híbrida**

Durante os experimentos, percebi algo curioso: embora o controle possuísse dez botões, inicialmente conseguia identificar apenas oito deles nas leituras.

Ao cruzar os resultados dos testes com as conexões físicas da placa, percebi que os dois botões restantes apresentavam um comportamento diferente. Enquanto oito botões compartilhavam um ponto comum de acionamento, os outros dois estavam conectados de maneira distinta ao circuito.

Isso levantou a hipótese de que o controle utilizava dois bancos de leitura, com uma lógica de seleção adicional para acessar os botões restantes.

A partir dessa descoberta, comecei a investigar a possibilidade de realizar uma leitura em dois ciclos, alternando o sinal de seleção para acessar os diferentes grupos de botões.

Essa investigação mostrou que nem sempre a quantidade de botões físicos corresponde diretamente à quantidade de sinais necessários para representá-los. O circuito pode utilizar mecanismos de multiplexação e registradores de deslocamento para transmitir diversas informações utilizando poucas conexões.

**4. O que aprendi com esse experimento**

Esse foi um dos primeiros momentos do projeto em que precisei deixar de lado a programação convencional e pensar diretamente no funcionamento de um circuito eletrônico.

Até então, estava acostumado a utilizar bibliotecas e abstrações que escondem boa parte da comunicação entre software e hardware. Dessa vez, precisei investigar sinais elétricos, identificar possíveis níveis lógicos, entender sincronização por clock e interpretar sequências de bits.

Também percebi a importância de utilizar ferramentas diferentes para investigar um mesmo problema. O multímetro me ajudou a compreender as conexões físicas, enquanto o Arduino permitiu observar o comportamento lógico do circuito.

Ainda preciso validar completamente a leitura dos dez botões, especialmente os dois que aparentemente utilizam um segundo ciclo de seleção. Entretanto, já consegui reconstruir boa parte da comunicação do controle sem possuir qualquer documentação técnica original.

Mais do que reaproveitar um periférico antigo, esse experimento me proporcionou uma primeira experiência prática de engenharia reversa de hardware.

### Reflexões e próximos passos

Esses experimentos começaram a conectar diferentes áreas que, até então, eu estava estudando de maneira relativamente isolada.

Com Rust, comecei a reproduzir operações que futuramente estarão presentes no processador que pretendo desenvolver. Com Arduino, comecei a investigar como os sinais elétricos são utilizados para transmitir informações entre componentes.

Percebo que existe uma relação muito maior entre essas duas frentes do que imaginava inicialmente. Afinal, um processador também precisa interpretar informações, executar operações e controlar o fluxo de dados internamente.

Quero continuar avançando nessa direção, aprofundando meus conhecimentos em representação binária, operações com bits e arquitetura de computadores. Também pretendo concluir a investigação do controle retrô para finalmente começar a desenvolver o videogame com a Raspberry Pi Pico.

Ainda estou nos primeiros passos, mas acredito que esses pequenos experimentos são fundamentais para construir uma compreensão mais sólida sobre o funcionamento das máquinas.

**Meu objetivo continua sendo o mesmo: deixar de apenas utilizar a tecnologia e começar a entender como ela é construída.**
