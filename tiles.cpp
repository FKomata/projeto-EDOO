#include "tiles.hpp"


Tiles::Tiles(bool valor) : tem_bomba(valor), bombas_proximas(0), coletavel(Coletavel::nenhum) {}


void Tiles::revelar_tile()
{
   this->tipo_tile = Tipo_tile::revelado;
}


void Tiles::botar_bandeira()
{
    if (tipo_tile == Tipo_tile::coberto)
    {
        this->tipo_tile = Tipo_tile::bandeira;
    }
    else if (tipo_tile == Tipo_tile::bandeira)
    {
        this->tipo_tile = Tipo_tile::coberto;
    }
}


Tipo_tile Tiles::get_estado_atual()
{
   return this->tipo_tile;
}


bool Tiles::get_tembomba()
{
   return this->tem_bomba;
}


int Tiles::get_bombasproximas()
{
   return this->bombas_proximas;
}


void Tiles::set_bombasproximas(int quantidade)
{
   this->bombas_proximas = quantidade;
}


void Tiles::set_tipo_tile(Tipo_tile a)
{
   this->tipo_tile = a;
}


char Tiles::get_conteudo_tile()
{
    if (tipo_tile == Tipo_tile::coberto)
    {
        return '#';
    }
    if (tipo_tile == Tipo_tile::bomba_explodida)
    {
        return '*';
    }
    if (tipo_tile == Tipo_tile::bandeira)
    {
        return 'F';
    }
    if (tipo_tile == Tipo_tile::revelado)
    {
        if (bombas_proximas == 0)
        {
            return '.';
        }
        else
        {
            return '0' + bombas_proximas;
        }
    }

    return '?'; //return de segurança, garante que a função sempre retorna um char, mesmo que o estado seja inesperado
}

Coletavel Tiles::get_coletavel()
{
    return this->coletavel;
}
void Tiles::set_coletavel(Coletavel c)
{
    this->coletavel = c;
}




