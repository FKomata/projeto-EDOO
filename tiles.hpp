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
   Tiles(bool tem_bomba);


   void revelar_tile();
   void botar_bandeira();


   Tipo_tile get_estado_atual();
   char get_conteudo_tile();
   bool get_tembomba();
   int get_bombasproximas();


   void set_bombasproximas(int quantidade);
   void set_tipo_tile(Tipo_tile a);
};
