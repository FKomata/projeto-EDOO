#pragma once

class Player
{
private:
    // Atributos de vida e pontuacao
    int vidas;
    int vidas_max;
    int pontos;
    // Atributos de bandeira
    int bandeiras;
    int bandeiras_max;
    // Atributos de tempo
    int tempo_restante;
    int tempo_limite;
    bool timer_ativado;

public:
    Player(int vidas, int bandeiras);

    // Metodos de status geral
    void tomar_dano();
    void curar_vida(int quantidade = 1);
    void pontuar(int quantidade);
    bool esta_vivo() const;

    // Metodos bandeira
    bool usar_bandeira();
    void recuperar_bandeira();
    void coletar_bandeira(int quantidade = 1);
    
    // Metodos do timer integrado
    void iniciar_timer(int limite_segundos);
    void decrementar_tempo(int segundos = 1);
    void adicionar_tempo(int segundos);
    bool tempo_esgotado() const;
    void desativar_timer();
    
    // Getters
    int get_vidas() const;
    int get_vidas_max() const;
    int get_pontos() const;
    int get_bandeiras() const;
    int get_bandeiras_max() const;
    int get_tempo_restante() const;
    bool is_timer_ativado() const;
};
