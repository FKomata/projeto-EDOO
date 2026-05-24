#include "player.hpp"

Player::Player(int vidas, int bandeiras)
    : vidas(vidas), vidas_max(vidas), pontos(0), 
      bandeiras(bandeiras), bandeiras_max(bandeiras), 
      tempo_restante(0), tempo_limite(0), timer_ativado(false)
{}

// Metodos de status geral

void Player::tomar_dano()
{
    if (vidas > 0)
        vidas--;
}

void Player::curar_vida(int quantidade)
{
    vidas += quantidade;
    if (vidas > vidas_max) 
        vidas = vidas_max; // Limita a cura ao máximo
}

void Player::pontuar(int quantidade)
{
    pontos += quantidade;
}

bool Player::esta_vivo() const
{
    return vidas > 0;
}

// Metodos de bandeira

bool Player::usar_bandeira()
{
    if (bandeiras > 0)
    {
        bandeiras--;
        return true;
    }
    return false;
}

void Player::recuperar_bandeira()
{
    if (bandeiras < bandeiras_max)
        bandeiras++;
}

void Player::coletar_bandeira(int quantidade)
{
    bandeiras += quantidade;
    if (bandeiras > bandeiras_max)
        bandeiras_max = bandeiras; // Coletável aumenta o limite máximo
}

// Metodos de tempo

void Player::iniciar_timer(int limite_segundos)
{
    tempo_limite = limite_segundos;
    tempo_restante = limite_segundos;
    timer_ativado = true;
}

void Player::decrementar_tempo(int segundos)
{
    if (timer_ativado)
    {
        tempo_restante -= segundos;
        if (tempo_restante <= 0)
        {
            tempo_restante = 0;
            timer_ativado = false;
        }
    }
}

void Player::adicionar_tempo(int segundos)
{
    if (timer_ativado)
    {
        tempo_restante += segundos;
        if (tempo_restante > tempo_limite)
        {
            tempo_restante = tempo_limite; // Não deixa passar do limite original
        }
    }
}

bool Player::tempo_esgotado() const
{
    return tempo_restante <= 0;
}

void Player::desativar_timer()
{
    timer_ativado = false;
}

// Getters

int Player::get_vidas() const
{
    return vidas;
}

int Player::get_vidas_max() const
{
    return vidas_max;
}

int Player::get_pontos() const
{
    return pontos;
}

int Player::get_bandeiras() const
{
    return bandeiras;
}

int Player::get_bandeiras_max() const
{
    return bandeiras_max;
}

int Player::get_tempo_restante() const { return tempo_restante; }

bool Player::is_timer_ativado() const { return timer_ativado; }
