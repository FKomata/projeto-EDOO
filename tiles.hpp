#pragma once
#include <iostream>
#include <string>
#include "tipo_tile.hpp"

class Tiles
{
private:
    bool tem_bomba;
    Tipo_tile tipo_tile = Tipo_tile::coberto;
    int bombas_proximas;
public:
    //construtor
    Tiles(bool tem_bomba);

    //metodos de mudar o estado de oculto -> revelado/bandeira/bomba_explodida
    void revelar_tile();
    void botar_bandeira();
    
    //metodos get
    Tipo_tile get_estado_atual();
    char get_conteudo_tile();
    bool get_tembomba();
    int get_bombasproximas();

    //metodos set
    void set_bombasproximas(int quantidade);
    void set_tipo_tile(Tipo_tile a);
};