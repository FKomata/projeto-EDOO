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
    std::vector<std::pair<int,int>> coord_bombas;
    srand(time(0));
    
    int bombas_temp = 0;

    //logica de armazenamento de armazenamento de coordenadas de bombas
    //adicionar : verificar se x e y nao estao em coord_bombas + mudar o jeito que é sorteado 
    while(bombas_temp < q_bombas)
    {
        int n = rand();
        int bomba_x = n % coord_x; 
        int bomba_y = n % coord_y;
        std::pair<int, int> pair_coord = {bomba_x,bomba_y};
        bool esta_no_vector = false;
        for(int j = 0 ; j < coord_bombas.size(); j++)
        {
            if(coord_bombas[j] == pair_coord)
            {
                esta_no_vector = true;
            }
        }
        if(esta_no_vector == false)
        {
            coord_bombas.push_back(pair_coord);
            bombas_temp++;
        }
    }

    //gerar matriz com apenas os tiles sem bombas
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
    //loop para adicionar as bombas nas coordenadas
    for(int a = 0; a < q_bombas; a++)
    {
        int coord_i = coord_bombas[a].first;
        int coord_j = coord_bombas[a].second;
        
        matriz[coord_i][coord_j] = Tiles(true);
    }
}

void Minefield::calcula_bombas_proximas()
{
    int di[] = {-1,-1,-1, 0, 0, 1, 1, 1};
    int dj[] = {-1, 0, 1,-1, 1,-1, 0, 1};
    
    //pegar todas as coordenadas e ver o 3 x 3 se tem bomba nesses lados ou não
    for(int i = 0 ; i < coord_x ; i++)
    {
        for(int j = 0; j < coord_y ; j++)
        {
            int contador_bombas = 0;
            for(int k = 0; k < 8; k++)
            {
                //aqui ele faz a comparação com o 3x3 da coord i j atual
                int ni = i + di[k];
                int nj = j + dj[k];
                if(ni >= 0 && ni < coord_x && nj >= 0 && nj < coord_y)
                {   
                    if(matriz[ni][nj].get_tembomba())
                    {
                        contador_bombas++;
                    }
                }
            }
            matriz[i][j].set_bombasproximas(contador_bombas);

        }
    }
    
}

void Minefield::escavar(int i , int j)
{
    if(matriz[i][j].get_estado_atual() != Tipo_tile::coberto)
    {
        return;
    }
    else
    {

        if(primeira_tentativa == true)
        {
            matriz[i][j] = Tiles(false);
            calcula_bombas_proximas();
            primeira_tentativa = false;
        }

        if(matriz[i][j].get_tembomba() == true)
        {
            matriz[i][j].set_tipo_tile(Tipo_tile::bomba_explodida);
            //perder vida
            tiles_revelados++;
        }
        else
        {
            
            if(matriz[i][j].get_bombasproximas() == 0)
            {
                cascata(i,j);
            }
            else
            {
                matriz[i][j].set_tipo_tile(Tipo_tile::revelado);
                tiles_revelados++;
            }
        }
        
    }

}

void Minefield::cascata(int i,int j)
{
    matriz[i][j].set_tipo_tile(Tipo_tile::revelado);
    tiles_revelados++;
    
    if(matriz[i][j].get_bombasproximas() == 0)
    {
        int di[] = {-1,-1,-1, 0, 0, 1, 1, 1};
        int dj[] = {-1, 0, 1,-1, 1,-1, 0, 1};
    
        for(int k = 0; k < 8; k++)
        {
            int ni = i + di[k];
            int nj = j + dj[k];
            if(ni >= 0 && ni < coord_x && nj >= 0 && nj < coord_y)
            {
                if(matriz[ni][nj].get_estado_atual() == Tipo_tile::coberto)
                {
                    cascata(ni, nj);
                }
            }
        }
    }
}


void Minefield::bandeira(int i , int j)
{
    if(matriz[i][j].get_estado_atual() == Tipo_tile::bandeira || matriz[i][j].get_estado_atual() == Tipo_tile::coberto)
    {
        matriz[i][j].botar_bandeira();
    }

}

bool Minefield::verifica_vitoria()
{
    //deduzir que as matrizes vao ser quadraticas
    for(int i = 0;i < matriz.size() ; i++)
    {
        for(int j = 0; j < matriz[i].size(); j++)
        {
            if(matriz[i][j].get_estado_atual() == Tipo_tile::coberto && matriz[i][j].get_tembomba() == false)
            {
                return false;
            }
        }
    }

    return true;
}

void Minefield::imprimir()
{
    std::cout << "campor minhado : " << std::endl;
    for(int i = 0; i < coord_x;i++)
    {
        for(int j = 0 ; j < matriz[i].size(); j++)
        {
            std::cout << matriz[i][j].get_conteudo_tile() << ' ';
        }
        std::cout << std::endl;
    }

}