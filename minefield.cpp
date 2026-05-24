#include "minefield.hpp"


Minefield::Minefield(int i, int j)
   : coord_x(i), coord_y(j), primeira_tentativa(true), tiles_revelados(0)
{
    for (int li = 0; li < coord_x; li++)
   {
       std::vector<Tiles> row;
       for (int lj = 0; lj < coord_y; lj++)
           row.emplace_back(false);
       matriz.push_back(row);
   }


    std::vector<std::pair<int,int>> posicoes_bombas = {
       {0, 5}, {1, 2}, {2, 7}, {3, 4},
       {4, 0}, {5, 3}, {6, 6}, {7, 1}
   };
    std::vector<std::pair<int,int>> posicoes_vida = { {2,3}, {5,1} };
    std::vector<std::pair<int,int>> posicoes_tempo = { {1,4}, {6,2} };
    std::vector<std::pair<int,int>> posicoes_bandeira = { {3,0}, {4,6} };

    for (auto& [bi, bj] : posicoes_bombas)
       matriz[bi][bj] = Tiles(true);
    
    for (auto& [bi, bj] : posicoes_vida)
       matriz[bi][bj].set_coletavel(Coletavel::vida);

    for (auto& [bi, bj] : posicoes_tempo)
       matriz[bi][bj].set_coletavel(Coletavel::tempo);

    for (auto& [bi, bj] : posicoes_bandeira)
       matriz[bi][bj].set_coletavel(Coletavel::bandeira);



   calcula_bombas_proximas();
}

void Minefield::calcula_bombas_proximas()
{
    const int di[] = {-1,-1,-1, 0, 0, 1, 1, 1};
    const int dj[] = {-1, 0, 1,-1, 1,-1, 0, 1};


    for (int i = 0; i < coord_x; i++)
    {
        for (int j = 0; j < coord_y; j++)
        {
            int contador = 0;
            for (int k = 0; k < 8; k++)
            {
                int ni = i + di[k];
                int nj = j + dj[k];
                if (ni >= 0 && ni < coord_x && nj >= 0 && nj < coord_y)
                {
                    if (matriz[ni][nj].get_tembomba())
                        contador++;
                }
            }
            matriz[i][j].set_bombasproximas(contador);
        }
    }
}

void Minefield::mover_bomba(int bomb_i, int bomb_j)
{
   for (int i = 0; i < coord_x; i++)
   {
       for (int j = 0; j < coord_y; j++)
       {
           if (!matriz[i][j].get_tembomba())
           {
               matriz[bomb_i][bomb_j] = Tiles(false);
               matriz[i][j] = Tiles(true);
               return;
           }
       }
   }
}



ResultadoEscavacao Minefield::escavar(int i, int j)
{
    Tipo_tile estado = matriz[i][j].get_estado_atual();
    Coletavel coletavel_tile = matriz[i][j].get_coletavel();

    // Checagem inicial (Não deixa cavar onde não deve)
    if (estado == Tipo_tile::bandeira)
        return ResultadoEscavacao::bandeirado;

    if (estado != Tipo_tile::coberto)
        return ResultadoEscavacao::ja_revelado;

    if (primeira_tentativa)
    {
        primeira_tentativa = false;
        if (matriz[i][j].get_tembomba())
        {
            mover_bomba(i, j);
            calcula_bombas_proximas();
        }
    }


    if (matriz[i][j].get_tembomba())
    {
        matriz[i][j].set_tipo_tile(Tipo_tile::bomba_explodida);
        tiles_revelados++;
        return ResultadoEscavacao::bomba;
    }


    if (matriz[i][j].get_bombasproximas() == 0)
        cascata(i, j);
    else
    {
        matriz[i][j].set_tipo_tile(Tipo_tile::revelado);
        tiles_revelados++;
    }

    // Tratamento dos coletaveis
    if (coletavel_tile != Coletavel::nenhum) 
    {
        // Remove o coletável do chão para não pegar de novo
        matriz[i][j].set_coletavel(Coletavel::nenhum); 

        // Retorna o aviso
        if (coletavel_tile == Coletavel::vida) return ResultadoEscavacao::coletou_vida;
        if (coletavel_tile == Coletavel::tempo) return ResultadoEscavacao::coletou_tempo;
        if (coletavel_tile == Coletavel::bandeira) return ResultadoEscavacao::coletou_bandeira;
    }


    return ResultadoEscavacao::livre;
}


void Minefield::cascata(int i, int j)
{
    matriz[i][j].set_tipo_tile(Tipo_tile::revelado);
    tiles_revelados++;


    if (matriz[i][j].get_bombasproximas() > 0)
        return;


    const int di[] = {-1,-1,-1, 0, 0, 1, 1, 1};
    const int dj[] = {-1, 0, 1,-1, 1,-1, 0, 1};


    for (int k = 0; k < 8; k++)
   {
        int ni = i + di[k];
        int nj = j + dj[k];
        if (ni >= 0 && ni < coord_x && nj >= 0 && nj < coord_y)
        {
            if (matriz[ni][nj].get_estado_atual() == Tipo_tile::coberto)
                cascata(ni, nj);
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
    for (int i = 0; i < coord_x; i++)
        for (int j = 0; j < coord_y; j++)
            if (!matriz[i][j].get_tembomba() && matriz[i][j].get_estado_atual() != Tipo_tile::revelado)
                return false;
    return true;
}

void Minefield::imprimir()
{
    std::cout << "campor minhado : " << std::endl;
    for(int i = 0; i < coord_x;i++)
    {
        for(int j = 0 ; j < coord_y; j++)
        {
            std::cout << matriz[i][j].get_conteudo_tile() << ' ';
        }
        std::cout << std::endl;
    }

}

Tipo_tile Minefield::get_tile_estado(int i, int j)
{
   return matriz[i][j].get_estado_atual();
}
