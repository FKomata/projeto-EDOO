#pragma once
#include <iostream>
#include <vector>
#include "minefield.hpp"
#include "player.hpp"

// ações possíveis
enum class ActionType
{
    DIG,
    FLAG
};

// representa uma jogada da simulação
struct Move
{
    int row;
    int col;
    ActionType action;
};

// estados da partida
enum class GameState
{
    PLAYING,
    GAME_OVER,
    VICTORY
};

class GameManager
{
private:
    Minefield board;
    Player player;
    GameState state;

public:
    // construtor inicializa o campo 8x8 e o player com 5 vidas e 5 bandeiras
    GameManager();

    void processar_jogada(const Move &move);
    void imprimir_status();
    void rodar_simulacao(const std::vector<Move> &script);
};