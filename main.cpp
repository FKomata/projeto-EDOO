#include "game.hpp"

int main()
{
    GameManager game;

    std::vector<Move> roteiro = {
        // 1. Primeira jogada exigida no 0,0 (Cascata pequena, pois há bombas próximas)
        {0, 0, ActionType::DIG},

        // 2 e 3. Usar bandeiras (Marcando as bombas do topo)
        {0, 4, ActionType::FLAG},
        {1, 4, ActionType::FLAG},

        // 4 e 5. Perder duas vidas (Pisando nas bombas isoladas da esquerda)
        {2, 2, ActionType::DIG}, // BOOM! (-1 vida)
        {3, 0, ActionType::DIG}, // BOOM! (-1 vida)

        // 6 a 11. Coletar Vidas e Itens
        {2, 3, ActionType::DIG}, // +1 Vida
        {5, 1, ActionType::DIG}, // +1 Vida
        {1, 5, ActionType::DIG}, // +10 Segundos
        {6, 2, ActionType::DIG}, // +10 Segundos
        {3, 1, ActionType::DIG}, // +1 Bandeira
        {4, 6, ActionType::DIG}, // +1 Bandeira

        // 12 a 14. Cliques em áreas vazias (0) para abrir as cascatas das bordas
        {2, 7, ActionType::DIG}, // Abre a direita inteira
        {7, 2, ActionType::DIG}, // Abre o fundo esquerdo
        {7, 7, ActionType::DIG}, // Abre o fundo direito

        // 15 em diante. Limpeza manual dos números restantes entre as bombas para VENCER
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