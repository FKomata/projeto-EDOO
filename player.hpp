#pragma once

class Player
{
private:
    int vidas;
    int vidas_max;
    int pontos;
    int bandeiras;
    int bandeiras_max;

public:
    Player(int vidas, int bandeiras);

    void tomar_dano();
    void pontuar(int quantidade);
    bool usar_bandeira();
    void recuperar_bandeira();

    bool esta_vivo() const;

    int get_vidas() const;
    int get_vidas_max() const;
    int get_pontos() const;
    int get_bandeiras() const;
    int get_bandeiras_max() const;
};
