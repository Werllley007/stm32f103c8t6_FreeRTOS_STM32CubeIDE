# Projeto STM32F103C8T6 com FreeRTOS

Este é um projeto desenvolvido para o microcontrolador STM32F103C8T6 com a utilização do FreeRTOS para gerenciamento de tarefas. O projeto envolve o controle de LEDs através de tarefas do FreeRTOS, utilizando a função de **taskBlink** para acender e apagar um LED no pino PC13 do STM32.

## Funcionalidades

- Controle de LEDs usando FreeRTOS.
- Criação de tarefas no FreeRTOS para execução paralela.
- Uso de eventos para gerenciar o estado de operação do sistema.

## Estrutura do Projeto

O projeto está estruturado da seguinte forma:

### Pré-requisitos

Certifique-se de ter as seguintes ferramentas instaladas em sua máquina:

- **STM32CubeIDE**: Para desenvolver e compilar o código.
- **STM32CubeMX**: Para configuração do microcontrolador.
- **FreeRTOS**: O FreeRTOS já está integrado ao projeto.

### Passos para Compilação

1. **Abra o STM32CubeIDE** e importe o projeto.
2. **Configure o microcontrolador** no STM32CubeMX (se necessário).
3. **Compile o projeto**:
   - Clique em "Build" no STM32CubeIDE para compilar o código.
4. **Carregue o código no microcontrolador**:
   - Use o ST-Link ou outro programador compatível para carregar o código no STM32F103C8T6.

### Teste

Após a compilação e o upload para o microcontrolador, o LED no pino PC13 deve começar a piscar a cada 500 ms, indicando que o FreeRTOS está gerenciando as tarefas corretamente.

## Funções Principais

### `taskBlink`

Esta função é executada em uma tarefa do FreeRTOS e é responsável por alternar o estado de um LED no pino PC13.

```c
void taskBlink(void *argument);


## Componentes e Funcionamento do Sistema

### Componentes Principais:

1. **STM32F103C8T6**:  
   O microcontrolador STM32F103C8T6 é a unidade central de processamento (CPU) do sistema. Ele é responsável por executar o código, controlar os periféricos e gerenciar as tarefas do sistema em tempo real com o FreeRTOS.

2. **FreeRTOS**:  
   FreeRTOS é um sistema operacional de tempo real (RTOS) usado para gerenciar múltiplas tarefas simultâneas no microcontrolador. Ele permite a criação de threads (tarefas), gerenciamento de recursos e sincronização entre tarefas, como no caso do controle do LED.

3. **LED (PC13)**:  
   O LED no pino **PC13** do microcontrolador é utilizado para indicar visualmente o funcionamento do sistema. Ele é controlado por uma tarefa do FreeRTOS que alterna seu estado (acende/desliga) periodicamente para demonstrar o funcionamento das threads.

4. **GPIO**:  
   A configuração do **GPIO** (General Purpose Input/Output) é feita para controlar o LED através do pino **PC13**, configurado como uma saída digital para acionar o LED.

5. **Funções Principais**:  
   As funções `taskBlink` e `taskMain` são responsáveis por controlar o comportamento do sistema. `taskBlink` gerencia o controle do LED, e `taskMain` gerencia a execução geral do sistema, esperando por eventos e realizando ações como **shutdown**, **reset** ou **standby**.

### Funcionamento do Sistema:

1. **Inicialização**:  
   O sistema começa com a inicialização do hardware (GPIO, UART) e do FreeRTOS. A função `main()` chama o método `osKernelInitialize()` para configurar o FreeRTOS, cria a tarefa principal usando `osThreadNew()`, e inicia o agendador de tarefas com `osKernelStart()`.

2. **Criação de Tarefas**:  
   A tarefa principal `taskMain` é criada logo após a inicialização do agendador. Essa tarefa espera eventos específicos, como **SHUTDOWN**, **RESET**, ou **STANDBY**, e pode executar ações relacionadas a esses eventos.

3. **Controle do LED (taskBlink)**:  
   A tarefa `taskBlink` é criada no FreeRTOS e é responsável por alternar o estado do LED no pino PC13. Ela é configurada para acender e apagar o LED a cada 500 ms, usando a função `osDelay()` do FreeRTOS para gerar o atraso entre os estados do LED.

4. **Eventos e Sincronização**:  
   A tarefa `taskMain` usa `osThreadFlagsWait()` para aguardar por eventos. Quando um evento ocorre (por exemplo, um comando para desligar o sistema), a tarefa executa a ação correspondente. Essa abordagem permite que o sistema reaja a diferentes condições de forma eficiente, sem a necessidade de monitoramento contínuo ou polling.

5. **Encerramento de Tarefas**:  
   Quando o sistema está pronto para ser finalizado, a função `finishTaskScheduler()` é chamada para finalizar as tarefas e parar o agendador, encerrando a execução do sistema de forma controlada.

### Fluxo Geral:

- **Inicialização**: O sistema inicializa os periféricos e o FreeRTOS.
- **Execução Paralela**: FreeRTOS cria e executa múltiplas tarefas em paralelo, como o controle do LED e o gerenciamento de eventos.
- **Controle do LED**: A tarefa `taskBlink` alterna o LED periodicamente para indicar que o sistema está ativo.
- **Gerenciamento de Eventos**: A tarefa `taskMain` espera eventos (como **shutdown** ou **reset**) e executa ações apropriadas.
- **Finalização**: O sistema pode ser finalizado de forma controlada, apagando as tarefas e o FreeRTOS.

