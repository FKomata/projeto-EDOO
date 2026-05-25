#include "game.hpp"

GameManager::GameManager() 
    : board(8, 8), player(7, 10), state(GameState::PLAYING) 
{
    // Opcional: define um tempo para demonstrar os coletáveis
    player.iniciar_timer(30); 
}

void GameManager::processar_jogada(const Move& move) 
{
    if (state != GameState::PLAYING) return;

    // Simula a passagem do tempo a cada jogada
    player.decrementar_tempo(1);

    std::cout << "\n>>> AÇÃO: ";

    if (move.action == ActionType::FLAG) 
    {
        std::cout << "Colocar bandeira em (" << move.row << ", " << move.col << ")\n";
        
        // Se a tile estiver coberta, gasta bandeira. Se já for bandeira, reembolsa.
        Tipo_tile estado = board.get_tile_estado(move.row, move.col);
        if (estado == Tipo_tile::coberto) {
            if (player.usar_bandeira()) {
                board.bandeira(move.row, move.col);
                player.pontuar(5);
            } else {
                std::cout << "Sem bandeiras disponiveis!\n";
            }
        } else if (estado == Tipo_tile::bandeira) {
            board.bandeira(move.row, move.col);
            player.recuperar_bandeira();
        }
    } 
    else if (move.action == ActionType::DIG) 
    {
        std::cout << "Escavar em (" << move.row << ", " << move.col << ")\n";
        
        ResultadoEscavacao res = board.escavar(move.row, move.col);

        if (res == ResultadoEscavacao::bomba) {
            std::cout << "BOOM! Pisou numa bomba!\n";
            player.tomar_dano();
            if (!player.esta_vivo()) state = GameState::GAME_OVER;
        } 
        else if (res == ResultadoEscavacao::coletou_vida) {
            std::cout << "+1 Vida!\n";
            player.curar_vida(1);
            player.pontuar(15);
        } 
        else if (res == ResultadoEscavacao::coletou_tempo) {
            std::cout << "+10 Segundos!\n";
            player.adicionar_tempo(10);
            player.pontuar(15);
        } 
        else if (res == ResultadoEscavacao::coletou_bandeira) {
            std::cout << "+1 Bandeira!\n";
            player.coletar_bandeira(1);
            player.pontuar(15);
        } 
        else if (res == ResultadoEscavacao::livre) {
            player.pontuar(5);
        } 
        else if (res == ResultadoEscavacao::ja_revelado || res == ResultadoEscavacao::bandeirado) {
            // Lógica consertada utilizando OU (||) para capturar ambas as situações inválidas
            std::cout << "Lugar inválido!\n";
        }
        // -------------------------------------------

        // Verifica se perdeu por tempo
        if (player.tempo_esgotado()) {
            std::cout << "Tempo Esgotado!\n";
            state = GameState::GAME_OVER;
        }

        // Verifica vitória se ainda estiver jogando
        if (state == GameState::PLAYING && board.verifica_vitoria()) {
            state = GameState::VICTORY;
            player.pontuar(1000);
        }
    }
}

void GameManager::imprimir_status() 
{
    std::cout << "========================================\n";
    std::cout << "Vidas: " << player.get_vidas() << "/" << player.get_vidas_max()
              << " | Bandeiras: " << player.get_bandeiras() << "/" << player.get_bandeiras_max()
              << " | Pontos: " << player.get_pontos() 
              << " | Tempo: " << player.get_tempo_restante() << "s\n";
    std::cout << "========================================\n";
    board.imprimir();
}

void GameManager::rodar_simulacao(const std::vector<Move>& script) 
{
    std::cout << "==== PURGATÓRIO ====\n";
    imprimir_status();

    for (const auto& move : script) {
        if (state != GameState::PLAYING) break; // Para o roteiro se o jogo já acabou

        processar_jogada(move);
        imprimir_status();
    }

    std::cout << "\n==== FIM DA SIMULACAO ====\n";
    if (state == GameState::VICTORY) {
        std::cout << "!!! VITORIA !!! O jogador limpou o campo!\n";
        std::cout << "Pontuacao Final: " << player.get_pontos() << "\n";
    } else if (state == GameState::GAME_OVER) {
        std::cout << "!!! GAME OVER !!! O jogador foi eliminado!\n";
    } else {
        std::cout << "Simulacao interrompida sem vencedor ou perdedor.\n";
    }
}