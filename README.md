# Processador RISC-V: do Arduino ao Linux

> Projeto de aprendizado e desenvolvimento de um sistema computacional baseado em RISC-V, começando por fundamentos de eletrônica e software de baixo nível e evoluindo até executar Linux em uma plataforma própria.

## Visão geral

O objetivo é compreender e construir, passo a passo, os componentes de um computador: lógica digital, execução de instruções, firmware, sistema operacional e interface de usuário.

A primeira implementação física será uma CPU simples baseada em **RV32I**, executada em uma FPGA **Sipeed Tang Nano 20K**. Em paralelo, será desenvolvido um simulador em Rust para testar a arquitetura antes de levá-la ao hardware.

O objetivo final é executar Linux em um sistema RISC-V desenvolvido e integrado ao longo do projeto, oferecendo um terminal cuja saída seja apresentada em uma **matriz RGB de LEDs de 64 × 32 pixels**, sem depender de um monitor convencional.

## Objetivos

- Aprender fundamentos de eletrônica digital, arquitetura de computadores e programação de baixo nível.
- Usar Rust como linguagem principal para simuladores, ferramentas e software sempre que for tecnicamente adequado.
- Implementar um simulador de instruções RISC-V em Rust.
- Descrever uma CPU sintetizável em SystemVerilog e verificá-la com testes.
- Executar uma primeira CPU em FPGA.
- Entender e implementar os recursos necessários para inicializar Linux em uma plataforma RISC-V.
- Construir uma interface de terminal para matriz RGB 64 × 32 e definir um mecanismo de entrada, começando possivelmente por serial.
- Registrar decisões, experimentos, limitações e resultados de forma reproduzível.

## Escopo e expectativas realistas

O projeto será incremental. A Tang Nano 20K é adequada para aprender lógica digital e implementar uma CPU simples, mas **não deve ser considerada, desde o início, a plataforma garantida para executar Linux**. O sistema Linux final poderá exigir outra FPGA ou plataforma com mais memória e recursos.

Uma CPU capaz de executar Linux precisa de muito mais do que decodificar instruções. Dependendo do kernel e da plataforma escolhidos, serão necessários, entre outros:

- modos de privilégio e mecanismos de exceção/trap;
- interrupções e temporizadores;
- uma interface de console e dispositivos de entrada/saída;
- memória suficiente para firmware, kernel e processos;
- mapa de memória e descrição de hardware coerentes;
- suporte às extensões e aos recursos exigidos pela configuração do Linux;
- uma MMU e suporte à paginação para uma configuração Linux convencional.

A arquitetura exata, o modelo de memória e a plataforma final serão definidos com base em testes e documentação técnica. Uma alternativa inicial para validar o fluxo de boot pode ser um ambiente mais simples antes de tentar uma configuração completa de Linux.

## Tecnologias

| Tecnologia | Uso |
|---|---|
| **Rust** | Simulador, ferramentas auxiliares e software compatível com o ecossistema. |
| **Arduino** | Experimentos introdutórios com entradas, saídas, sensores e temporização. |
| **SystemVerilog** | Descrição do hardware digital sintetizável. |
| **Verilator** | Simulação e verificação da RTL. |
| **RISC-V** | Arquitetura de conjunto de instruções do processador. |
| **Sipeed Tang Nano 20K** | Primeira plataforma FPGA para a CPU simples. |
| **Git e GitHub** | Versionamento do código, documentação e decisões. |
| **Trello** | Planejamento, prioridades, dependências e acompanhamento das tarefas. |
| **Linux e ferramentas de compilação** | Etapas de firmware, boot e sistema operacional. |
| **Matriz RGB 64 × 32** | Interface visual final planejada. |

Rust será a linguagem principal do software quando houver suporte e isso fizer sentido. SystemVerilog será usado para descrever o circuito sintetizável. Também poderão ser necessários Assembly, linker scripts, Makefiles ou C em componentes do ecossistema de boot/Linux, conforme a plataforma e as ferramentas escolhidas.

## Roadmap resumido

1. **Planejamento e ambiente** — preparar repositório, ferramentas e critérios de validação.
2. **Rust e fundamentos de baixo nível** — desenvolver a base de programação necessária.
3. **Arduino e eletrônica básica** — experimentar sinais digitais e periféricos simples.
4. **Rust embarcado** — compreender compilação, memória e interação com hardware.
5. **Arquitetura RISC-V** — estudar instruções, registradores, memória e execução.
6. **Simulador RISC-V em Rust** — executar e testar programas sem depender da FPGA.
7. **SystemVerilog e verificação RTL** — implementar e validar uma CPU em hardware.
8. **Arquitetura necessária para Linux** — planejar privilégios, traps, interrupções, temporizadores, memória e dispositivos.
9. **Boot, firmware e Linux** — integrar a plataforma e buscar a inicialização do sistema.
10. **Interface final** — criar saída de terminal para a matriz LED e entrada de comandos.
11. **Estabilização** — reproduzir testes, registrar limitações e publicar resultados.

O detalhamento e os critérios de conclusão de cada fase estão em [`docs/roadmap.md`](docs/roadmap.md). O Trello é o quadro operacional das tarefas; este roadmap é a visão técnica de conjunto.

## Estrutura sugerida do repositório

```text
processador-riscv/
├── README.md
├── docs/
│   ├── roadmap.md
│   ├── arquitetura.md
│   ├── decisoes-tecnicas.md
│   └── diario-de-desenvolvimento.md
├── arduino/
├── rust/
│   ├── fundamentos/
│   ├── simulador-riscv/
│   └── ferramentas/
├── rtl/
│   ├── src/
│   └── testbench/
├── fpga/
│   └── tang-nano-20k/
├── firmware/
├── linux/
├── interface/
│   └── matriz-led/
└── tests/
```

Essa é uma estrutura-alvo, não uma exigência para o primeiro dia. Crie cada diretório quando houver conteúdo para ele.

### Responsabilidade de cada diretório

| Diretório | Conteúdo esperado |
|---|---|
| `docs/` | Roadmap, documentação da arquitetura, decisões técnicas e diário de desenvolvimento. |
| `arduino/` | Experimentos de eletrônica e programas usados na fase introdutória. |
| `rust/fundamentos/` | Exercícios de Rust e exemplos de programação de baixo nível. |
| `rust/simulador-riscv/` | Código-fonte e testes do simulador RISC-V em Rust. |
| `rust/ferramentas/` | Utilitários para conversão, geração de programas de teste e automação. |
| `rtl/src/` | Módulos sintetizáveis da CPU escritos em SystemVerilog. |
| `rtl/testbench/` | Testbenches e cenários de verificação da RTL. |
| `fpga/tang-nano-20k/` | Arquivos de projeto, constraints, scripts e instruções específicos da FPGA. |
| `firmware/` | Código de inicialização e componentes de firmware da plataforma. |
| `linux/` | Configurações, patches, device tree e instruções relacionados ao Linux. |
| `interface/matriz-led/` | Código e documentação para renderização do terminal e controle do painel LED. |
| `tests/` | Testes de integração, programas de referência e recursos compartilhados de validação. |

Os diretórios podem ser criados gradualmente. Evite manter pastas vazias só para reproduzir a árvore: adicione-as quando a fase correspondente começar.

## Marcos de sucesso

- [ ] Ambiente de desenvolvimento documentado e reproduzível.
- [ ] Pequenos programas Rust compilados e testados.
- [ ] Experimentos de Arduino documentados.
- [ ] Simulador executando um subconjunto inicial de instruções RISC-V.
- [ ] Testes automatizados do simulador aprovados.
- [ ] CPU RTL aprovada nos testes de unidade e integração.
- [ ] CPU sintetizada e executada na Tang Nano 20K.
- [ ] Requisitos e limitações da plataforma Linux documentados.
- [ ] Firmware executando na plataforma escolhida.
- [ ] Kernel Linux inicializado, com console funcional.
- [ ] Saída de terminal apresentada na matriz RGB 64 × 32.
- [ ] Método de entrada de comandos validado.
- [ ] Instruções de compilação, execução e testes documentadas.

## Como trabalhar no projeto

- **Trello:** cada tarefa deve ter descrição, critérios de aceitação, prioridade e dependências quando aplicável.
- **Git:** faça commits pequenos, com mensagens que expliquem a mudança.
- **Testes:** registre o comando executado e o resultado observado; não marque uma etapa como concluída apenas porque o código compila.
- **Diário técnico:** anote decisões, problemas, medições e links para documentação relevante.
- **Escopo:** mantenha uma tarefa principal em andamento e evite começar várias etapas dependentes ao mesmo tempo.
- **Evidências:** quando possível, anexe logs, testes, capturas de tela, diagramas ou vídeos curtos ao cartão do Trello ou à documentação.

## Princípios de desenvolvimento

1. Priorizar compreensão e testes reproduzíveis, não apenas obter um resultado que funcione uma vez.
2. Separar o comportamento esperado da implementação e validá-lo com testes.
3. Usar ferramentas de simulação antes de depurar no hardware sempre que possível.
4. Documentar decisões que alterem a arquitetura ou dificultem uma futura mudança.
5. Revisar os requisitos de hardware antes de assumir que uma etapa será executada na FPGA atual.

## Estado atual

**Fase:** planejamento e preparação do ambiente.

**Próxima ação sugerida:** criar o repositório, confirmar as ferramentas instaladas e iniciar a primeira tarefa do Trello.

> O projeto é de longo prazo. A arquitetura final pode mudar conforme o aprendizado, as limitações da FPGA e os resultados dos testes.
