#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "tiles.hpp"

class Minefield
{
private:
    std::vector<std::vector<Tiles>> matriz;
    int coord_x;
    int coord_y;
    int q_bombas;
    bool primeira_tentativa;
    int tiles_revelados;

    //revelar caso os vizinhos tiverem 0 bombas ao redor
    void cascata(int i, int j);
public:
    Minefield(int coord_x,int coord_y,int q_bombas);
    void gera_matriz();
    void calcula_bombas_proximas();
    void escavar(int i , int j);
    void botar_bandeira(int i,int j);
    bool verifica_vitoria();
    void imprimir();

};