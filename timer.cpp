#include "timer.hpp"


Timer::Timer() : ativo(false) {}


void Timer::iniciar()
{
   inicio = std::chrono::steady_clock::now();
   ativo = true;
}


void Timer::parar()
{
   fim = std::chrono::steady_clock::now();
   ativo = false;
}


int Timer::segundos_decorridos() const
{
   auto ponto_final = ativo ? std::chrono::steady_clock::now() : fim;
   return std::chrono::duration_cast<std::chrono::seconds>(ponto_final - inicio).count();
}
