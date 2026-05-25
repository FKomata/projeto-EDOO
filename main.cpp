#include "game.hpp"

int main() {
    GameManager game;

    // Criando o script da nossa simulação textual!
    // As coordenadas foram pensadas baseadas nas posições fixas do seu Minefield().
    std::vector<Move> roteiro = {
        // 1. Testa escavação segura (Cascata)
        {7, 7, ActionType::DIG},  
        
        // 2. Testa colocar uma bandeira (Bandeira em 0,5 onde sabemos que tem bomba)
        {0, 5, ActionType::FLAG}, 
        
        // 3. Testa pegar coletável de Vida (Posição 2,3)
        {2, 3, ActionType::DIG},  
        
        // 4. Testa tomar dano numa bomba (Bomba no 1,2)
        {1, 2, ActionType::DIG},  

        // 5. Pegar coletável de Tempo (Posição 1,4)
        {1, 4, ActionType::DIG}
        
        // Você e seu time podem adicionar mais jogadas aqui pra provar pro professor 
        // que o jogo roda até acabar as vidas ou até limpar o campo.
    };

    game.rodar_simulacao(roteiro);

    return 0;
}