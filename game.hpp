#pragma once
#include <iostream>
#include <vector>
#include "minefield.hpp"
#include "player.hpp"

// Ações possíveis no nosso "roteiro" da simulação
enum class ActionType { DIG, FLAG };

// Representa uma jogada da simulação
struct Move {
    int row;
    int col;
    ActionType action;
};

// Estados da partida
enum class GameState { PLAYING, GAME_OVER, VICTORY };

class GameManager {
private:
    Minefield board;
    Player player;
    GameState state;

public:
    // Construtor inicializa o campo 8x8 e o player com 7 vidas e 10 bandeiras
    GameManager();

    void processar_jogada(const Move& move);
    void imprimir_status();
    void rodar_simulacao(const std::vector<Move>& script);
};