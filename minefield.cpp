#include "minefield.hpp"
#include <cstdlib>
#include <ctime>
#include <tuple>


//vector das coordenadas das bombas


Minefield::Minefield(int i, int j, int q) : coord_x(i), coord_y(j) , q_bombas(q) 
{
    this->primeira_tentativa = true;
    this->tiles_revelados = 0;
    
    gera_matriz();
    calcula_bombas_proximas();
}

void Minefield::gera_matriz()
{
    std::vector<std::tuple<int,int>> coord_bombas;
    srand(time(0));
    
    //logica de armazenamento de armazenamento de coordenadas de bombas
    //adicionar : verificar se x e y nao estao em coord_bombas + mudar o jeito que é sorteado 
    for(int i = 0 ; i < q_bombas ; i++)
    {
        int n = rand();
        int bomba_x = n % coord_x;
        int bomba_y = n % coord_y;
        std::tuple<int, int> tupla_coord = {bomba_x,bomba_y};
        coord_bombas.push_back(tupla_coord);
    }

    //gerar matriz espaços vazios + bombas
    for(int i = 0 ; i < coord_x; i++)
    {
        std::vector<Tiles> vector_temp;
        for(int j = 0; j < coord_y; j++)
        {
            Tiles tile(false);
            vector_temp.push_back(tile);
        }
        matriz.push_back(vector_temp);
    }
}

void Minefield::calcula_bombas_proximas()
{

}