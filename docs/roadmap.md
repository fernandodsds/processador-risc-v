# Roadmap técnico — Processador RISC-V

Este documento descreve a sequência técnica do projeto, os objetivos de cada fase e os critérios para avançar. O quadro Trello contém as tarefas individuais; este arquivo mantém a visão de dependências e dos marcos de longo prazo.

## Regras para usar o roadmap

- Concluir os critérios de aceitação antes de considerar uma fase finalizada.
- Registrar bloqueios e decisões técnicas importantes.
- Reavaliar a plataforma e o escopo quando surgirem medições reais de lógica, memória, frequência e desempenho.
- Não presumir que a Tang Nano 20K será suficiente para Linux: essa decisão depende dos requisitos do kernel e da plataforma.
- Preferir Rust para software quando houver suporte adequado; usar SystemVerilog para RTL sintetizável e outras linguagens quando forem exigidas pelo ecossistema.

---

## Fase 0 — Planejamento e ambiente

**Objetivo:** preparar um fluxo de desenvolvimento reproduzível.

### Atividades
- Criar o repositório Git e definir convenções de diretórios.
- Instalar e validar Rust, Cargo, Git e ferramentas de compilação.
- Preparar o ambiente para SystemVerilog e Verilator.
- Identificar ferramentas de síntese, place-and-route e programação compatíveis com a Tang Nano 20K.
- Organizar o quadro Trello e registrar dependências.
- Criar um diário técnico para decisões e resultados.

### Critérios de saída
- [ ] Repositório criado com README e roadmap.
- [ ] Versões das ferramentas documentadas.
- [ ] Um programa Rust de exemplo compila e executa.
- [ ] Um exemplo mínimo de RTL pode ser simulado.
- [ ] Procedimento de compilação e teste documentado.

## Fase 1 — Rust e fundamentos de baixo nível

**Objetivo:** adquirir a base de programação necessária para simuladores e ferramentas.

### Atividades
- Tipos, funções, controle de fluxo, structs, enums e pattern matching.
- Ownership, borrowing, referências e gerenciamento de memória.
- Coleções, tratamento de erros, módulos e testes unitários.
- Operações binárias, máscaras, deslocamentos e representação de inteiros.
- Noções de memória, endianness, stack, heap, compilação e linking.
- Leitura e escrita de arquivos e criação de ferramentas de linha de comando.

### Critérios de saída
- [ ] Pequenos programas em Rust compilam e têm testes.
- [ ] Operações bit a bit usadas em campos de instruções podem ser explicadas.
- [ ] Existe uma ferramenta simples de linha de comando documentada.

## Fase 2 — Arduino e eletrônica básica

**Objetivo:** conectar conceitos de software a sinais e componentes físicos.

### Atividades
- Identificar tensão, corrente, resistência, GND e limites elétricos.
- Usar entradas e saídas digitais e compreender pull-up/pull-down.
- Ler botões e controlar LEDs.
- Estudar debounce, temporização e interrupções em nível introdutório.
- Experimentar comunicação serial.
- Aprender a consultar datasheets e diagramas de pinos.
- Registrar circuitos, código e resultados.

### Cuidados
- Conferir tensão lógica, corrente máxima e alimentação de cada componente.
- Não conectar cargas que excedam os limites dos pinos.
- Desenergizar o circuito antes de alterar ligações.

### Critérios de saída
- [ ] Experimentos básicos documentados.
- [ ] Entrada de botão e saída de LED funcionam previsivelmente.
- [ ] Comunicação serial envia e recebe dados.
- [ ] Limites elétricos dos componentes usados foram verificados.

## Fase 3 — Rust embarcado

**Objetivo:** entender as diferenças entre software de aplicação e software próximo ao hardware.

### Atividades
- Estudar `no_std`, alvo de compilação e toolchain.
- Entender memória mapeada em registradores (MMIO), sem fazer acessos arbitrários em hardware real.
- Aprender linker scripts, startup code e organização de memória em nível conceitual.
- Explorar HALs e crates compatíveis com a placa escolhida.
- Comparar um programa hospedado no PC com um programa embarcado.

### Critérios de saída
- [ ] Um exemplo embarcado compatível com a placa escolhida compila.
- [ ] O fluxo de build e gravação está documentado.
- [ ] O papel de `no_std`, linker e HAL está explicado em notas próprias.

## Fase 4 — Arquitetura RISC-V

**Objetivo:** compreender o conjunto de instruções antes de implementar uma CPU.

### Atividades
- Estudar registradores, PC, memória e formatos de instrução.
- Estudar instruções aritméticas, lógicas, load/store, branches e jumps.
- Entender codificação e decodificação de instruções.
- Definir inicialmente o escopo RV32I e documentar simplificações.
- Estudar alinhamento, endianness e comportamento esperado das instruções.
- Criar programas pequenos em assembly ou código compilado para teste.

### Critérios de saída
- [ ] Documento inicial de arquitetura escrito.
- [ ] Formatos de instrução e semântica das instruções selecionadas documentados.
- [ ] Programas de teste têm resultados esperados definidos.

## Fase 5 — Simulador RISC-V em Rust

**Objetivo:** criar um modelo executável da CPU, útil como referência para a implementação em RTL.

### Atividades
- Representar registradores, PC e memória.
- Implementar carregamento de um programa de teste.
- Implementar fetch, decode e execute.
- Adicionar instruções em incrementos pequenos.
- Tratar branches, jumps, loads/stores e limites de memória.
- Definir comportamento para instruções inválidas e condições não suportadas.
- Criar testes unitários por instrução e testes de programas completos.
- Comparar resultados com referências independentes quando possível.
- Documentar as instruções suportadas e as limitações do simulador.

### Critérios de saída
- [ ] Instruções implementadas têm testes automatizados.
- [ ] Programas de teste produzem o estado final esperado.
- [ ] O simulador documenta suas instruções suportadas e limitações.
- [ ] Existe uma forma reproduzível de executar a suíte de testes.

## Fase 6 — SystemVerilog e verificação RTL

**Objetivo:** implementar uma CPU sintetizável e demonstrar que ela corresponde ao comportamento esperado.

### Atividades
- Estudar lógica combinacional e sequencial, clock, reset e máquinas de estados.
- Criar módulos para PC, banco de registradores, ALU, decoder e interface de memória.
- Escolher uma microarquitetura inicial simples, como multicycle, antes de considerar pipeline.
- Implementar a CPU por etapas e simular cada módulo.
- Criar testbenches para reset, instruções, branches, loads/stores e casos inválidos.
- Usar Verilator para simulação e automação de testes.
- Comparar o estado final da RTL com o simulador em Rust para os mesmos programas.
- Sintetizar e avaliar uso de LUTs, registradores, BRAM e frequência.
- Preparar constraints e fluxo de programação para a Tang Nano 20K.

### Critérios de saída
- [ ] Testes dos módulos aprovados.
- [ ] Programas de teste produzem resultados coerentes com o simulador Rust.
- [ ] Síntese concluída e relatório de recursos registrado.
- [ ] Bitstream executado na FPGA.
- [ ] Procedimento de programação e depuração documentado.

## Fase 7 — Plataforma compatível com Linux

**Objetivo:** definir o hardware e o software de suporte que um Linux real exigirá.

### Atividades
- Selecionar uma versão/configuração de Linux e estudar seus requisitos para RISC-V.
- Confirmar os requisitos de ISA e extensões, modos de privilégio e ABI.
- Definir o mapa de memória e a interface com RAM e ROM/flash.
- Planejar exceções/traps, interrupções e temporizadores.
- Planejar um console serial e dispositivos de entrada/saída.
- Estudar o papel do firmware, SBI/OpenSBI quando aplicável e do bootloader.
- Avaliar a necessidade de MMU e paginação para a configuração Linux pretendida.
- Estimar memória, lógica, clock e periféricos necessários.
- Decidir com evidências se a Tang Nano 20K permanece útil para alguma parte ou se será necessária outra plataforma.

### Critérios de saída
- [ ] Requisitos do Linux alvo documentados a partir de fontes oficiais.
- [ ] Matriz de recursos do hardware versus requisitos concluída.
- [ ] Mapa de memória e periféricos documentados.
- [ ] Decisão fundamentada sobre a plataforma final registrada.
- [ ] Plano de boot definido.

## Fase 8 — Firmware, boot e Linux

**Objetivo:** levar o sistema de um estado de reset até um kernel com console funcional.

### Atividades
- Criar ou adaptar o código de inicialização adequado à plataforma.
- Integrar firmware e mecanismo de boot escolhidos.
- Implementar ou integrar os dispositivos mínimos necessários.
- Preparar a descrição de hardware da plataforma, incluindo device tree quando aplicável.
- Compilar e configurar o kernel Linux para a arquitetura e os dispositivos disponíveis.
- Usar inicialmente console serial para separar problemas de boot dos problemas da matriz LED.
- Validar memória, traps, interrupções, timer e armazenamento conforme a configuração.
- Registrar logs de boot e corrigir problemas em ordem.

### Critérios de saída
- [ ] Firmware inicia de forma reproduzível.
- [ ] Kernel inicia na plataforma escolhida.
- [ ] Console serial permite observar a inicialização e interagir com o sistema.
- [ ] Build, gravação e boot estão documentados.

## Fase 9 — Interface: terminal em matriz RGB 64 × 32

**Objetivo:** criar a interface visual final sem depender de um monitor convencional.

### Atividades
- Identificar o modelo exato do painel e seu controlador/interface (por exemplo, HUB75, se aplicável).
- Confirmar tensões, alimentação, corrente, temporização e requisitos de atualização.
- Definir se a matriz será controlada diretamente pela CPU, por controlador dedicado ou por microcontrolador auxiliar.
- Criar uma camada de framebuffer/renderização e uma fonte bitmap simples.
- Implementar caracteres, linhas, rolagem e atualização do terminal.
- Integrar a saída do terminal do sistema à matriz.
- Definir entrada de comandos: começar por serial USB/UART e avaliar teclado ou outra interface depois.
- Medir estabilidade, legibilidade, taxa de atualização e consumo de recursos.

### Cuidados
- Não alimentar o painel diretamente a partir de pinos da FPGA.
- Usar fonte e interface elétrica adequadas ao painel.
- Confirmar níveis lógicos e necessidade de buffers antes de conectar sinais.

### Critérios de saída
- [ ] Painel acende e apresenta padrões de teste estáveis.
- [ ] Texto legível é exibido na matriz 64 × 32.
- [ ] Saída do terminal é apresentada corretamente.
- [ ] Existe uma forma funcional de enviar comandos.
- [ ] Esquema de ligação e procedimento de teste documentados.

## Fase 10 — Estabilização e documentação

**Objetivo:** tornar os resultados compreensíveis e reproduzíveis.

### Atividades
- Automatizar os testes possíveis.
- Documentar dependências, versões de ferramentas e comandos de build.
- Registrar limitações conhecidas, erros e soluções.
- Revisar a arquitetura e identificar dívida técnica.
- Criar um guia de reprodução desde o ambiente limpo até a demonstração final.
- Preparar imagens, diagramas e logs para apresentar o projeto.

### Critérios de saída
- [ ] Outra pessoa consegue seguir a documentação e reproduzir as etapas principais.
- [ ] Testes automatizados passam ou suas falhas conhecidas estão explicadas.
- [ ] Limitações e componentes externos estão listados.
- [ ] Demonstração final documentada.

---

## Dependências de alto nível

```text
Planejamento
    ├── Rust e fundamentos ───────────────┐
    ├── Arduino e eletrônica              │
    └── Rust embarcado                    │
                                          ▼
Arquitetura RISC-V ───────────────► Simulador em Rust
                                          │
                                          ▼
                              SystemVerilog + Verilator
                                          │
                                          ▼
                                   CPU em FPGA
                                          │
                                          ▼
                       Requisitos da plataforma para Linux
                                          │
                                          ▼
                              Firmware + kernel Linux
                                          │
                                          ▼
                         Terminal serial funcional primeiro
                                          │
                                          ▼
                            Matriz RGB 64 × 32 + entrada
                                          │
                                          ▼
                                Estabilização e documentação
```

Algumas fases podem ocorrer parcialmente em paralelo, mas o simulador e os testes de referência devem ajudar a validar a CPU RTL.

## Marcos sugeridos

| Marco | Resultado verificável |
|---|---|
| M1 — Ambiente pronto | Repositório, ferramentas e testes mínimos documentados. |
| M2 — Fundamentos | Experimentos iniciais de Rust, Arduino e baixo nível concluídos. |
| M3 — CPU de referência | Simulador Rust executa programas de teste definidos. |
| M4 — Primeira CPU física | CPU RTL sintetizada e executando na Tang Nano 20K. |
| M5 — Plataforma Linux definida | Requisitos e plataforma escolhida com justificativa técnica. |
| M6 — Primeiro boot | Kernel Linux com console serial funcional. |
| M7 — Interface final | Terminal exibido na matriz RGB e entrada de comandos validada. |
| M8 — Projeto reproduzível | Documentação e testes suficientes para reproduzir a demonstração. |

## Registro de decisões técnicas

Quando uma decisão afetar arquitetura, ferramentas ou hardware, registre em `docs/decisoes-tecnicas.md`:

- Contexto e problema.
- Alternativas consideradas.
- Critérios de comparação.
- Decisão escolhida e justificativa.
- Consequências, riscos e data.
- Evidências ou testes que sustentam a decisão.

## Revisão periódica

Ao fim de cada semana ou etapa:
1. Atualizar o estado das tarefas no Trello.
2. Registrar o que foi aprendido e quais testes foram executados.
3. Revisar bloqueios e dependências.
4. Atualizar este roadmap se uma decisão técnica alterar a sequência.
5. Escolher a próxima tarefa pequena e verificável.
