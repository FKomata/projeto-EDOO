#include "game.hpp"

int main()
{
    GameManager game;

    std::vector<Move> roteiro = {
        // primeira jogada: testa cascata
        {0, 0, ActionType::DIG},

        // bandeiras na posicao
        {0, 4, ActionType::FLAG},
        {1, 4, ActionType::FLAG},

        // Perde duas vidas
        {2, 2, ActionType::DIG}, //-1 vida
        {3, 0, ActionType::DIG}, //-1 vida

        // coletáveis
        {2, 3, ActionType::DIG}, //+1 vida
        {5, 1, ActionType::DIG}, //+1 vida
        {1, 5, ActionType::DIG}, //+10 segundos
        {6, 2, ActionType::DIG}, //+10 segundos
        {3, 1, ActionType::DIG}, //+1 bandeira
        {4, 6, ActionType::DIG}, //+1 bandeira

        // 3 cascatas seguidas
        {2, 7, ActionType::DIG},
        {7, 2, ActionType::DIG},
        {7, 7, ActionType::DIG},

        // finaliza o jogo revelando o restante do campo
        {0, 3, ActionType::DIG},
        {0, 5, ActionType::DIG},
        {1, 2, ActionType::DIG},
        {1, 3, ActionType::DIG},
        {2, 1, ActionType::DIG},
        {2, 4, ActionType::DIG},
        {3, 2, ActionType::DIG},
        {3, 3, ActionType::DIG},
        {4, 1, ActionType::DIG},
        {4, 2, ActionType::DIG},
        {5, 0, ActionType::DIG},
        {5, 2, ActionType::DIG},
        {5, 4, ActionType::DIG},
        {5, 5, ActionType::DIG},
        {5, 7, ActionType::DIG},
        {6, 1, ActionType::DIG},
        {6, 3, ActionType::DIG},
        {7, 0, ActionType::DIG},
        {7, 4, ActionType::DIG},
        {7, 5, ActionType::DIG}};

    game.rodar_simulacao(roteiro);

    return 0;
}