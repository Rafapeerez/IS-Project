//reserva.h
//it define the class reserva
#ifndef _RESERVA_H
#define _RESERVA_H
#include <iostream>
#include <vector>
#include <list>

struct Maquina{
    int numero_maq;
    int recur_totales;
    int recur_disp;
};


class Reserva{
    private:
        int maquinas_totales_;
        int maquina_elegida_;
        int recursos_;
        std::list<Maquina> maquinas_;

    public:
        inline Reserva(){maquinas_totales_=8;}
        void setMaquinas();
        inline std::list<Maquina> getMaquinas(){return maquinas_;}
        void mostrarMaquinas();   
};
#endif