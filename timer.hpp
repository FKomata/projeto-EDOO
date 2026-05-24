#pragma once
#include <chrono>


class Timer
{
private:
   std::chrono::steady_clock::time_point inicio;
   std::chrono::steady_clock::time_point fim;
   bool ativo;


public:
   Timer();
   void iniciar();
   void parar();
   int segundos_decorridos() const;
};


