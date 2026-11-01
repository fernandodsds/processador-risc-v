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

| Etapa | Conteúdo | Objetivo |
|---|---|---|
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
