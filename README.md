# Projeto EDOO: Adaptação do jogo Purgatório em C++

Este projeto é uma adaptação em C++ do jogo **Purgatório**, desenvolvido como parte da disciplina de Estrutura de Dados Orientada a Objetos. O jogo apresenta um sistema de gerenciamento de estado, mecânicas de coletáveis (vida, tempo e bandeiras) e um algoritmo de revelação em cascata.

## 🚀 Funcionalidades

* **Gerenciamento de Jogo:** Sistema de controle de turnos e estados (Jogando, Vitória, Game Over).
* **Mecânica de Coletáveis:** Possibilidade de coletar itens durante a escavação que alteram os atributos do jogador.
* **Algoritmo de Cascata:** Revelação automática de áreas vazias adjacentes ao clicar em uma célula segura.
* **Sistema de Bandeiras:** Mecânica para marcar bombas e gerenciar recursos limitados.
* **Simulação:** O jogo suporta a execução de scripts de jogadas predefinidas para testes automatizados.

## 🛠 Pré-requisitos

Para compilar este projeto, você precisará de:

* Um compilador C++ (recomendado **g++**).

## 💻 Como Compilar e Executar

### Via Terminal (Linux/macOS)

1. Clone este repositório para sua máquina.
2. Navegue até a pasta do projeto:
```bash
cd projeto-EDOO

```


3. Compile todos os arquivos `.cpp` gerando um executável chamado `main`:
```bash
g++ *.cpp -o main

```


4. Execute o programa:
```bash
./main

```



## 🎮 Estrutura do Projeto

* `game.hpp/cpp`: Controla a lógica principal e o fluxo de turnos.
* `minefield.hpp/cpp`: Gerencia a grade, a lógica de bombas e a revelação em cascata.
* `tiles.hpp/cpp`: Representa cada célula do campo.
* `player.hpp/cpp`: Armazena o estado do jogador (vidas, pontos, tempo, bandeiras).
* `main.cpp`: Ponto de entrada que executa o script de simulação.
