#pragma once
#include <iostream>
#include <vector>
#include "tiles.hpp"
#include "tipo_tile.hpp"
#include "coletavel.hpp"


enum class ResultadoEscavacao { livre, bomba, ja_revelado, bandeirado, coletou_vida, coletou_tempo, coletou_bandeira };


class Minefield
{
private:
   std::vector<std::vector<Tiles>> matriz;
   int coord_x;
   int coord_y;
   bool primeira_tentativa;
   int tiles_revelados;


   void calcula_bombas_proximas();
   void mover_bomba(int i, int j);
   void cascata(int i, int j);


public:
   Minefield(int coord_x, int coord_y);


   ResultadoEscavacao escavar(int i, int j);
   void bandeira(int i, int j);
   bool verifica_vitoria();
   void imprimir();
   Tipo_tile get_tile_estado(int i, int j);
};
