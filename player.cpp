#include "player.hpp"

Player::Player(int vidas, int bandeiras)
    : vidas(vidas), vidas_max(vidas), pontos(0), bandeiras(bandeiras), bandeiras_max(bandeiras)
{}

void Player::tomar_dano()
{
    if (vidas > 0)
        vidas--;
}

void Player::pontuar(int quantidade)
{
    pontos += quantidade;
}

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

bool Player::esta_vivo() const
{
    return vidas > 0;
}

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
