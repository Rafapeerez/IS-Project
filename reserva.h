//reserva.h
//it define the class reserva
#ifndef _RESERVA_H
#define _RESERVA_H
#include <iostream>
#include <vector>
#include <list>

struct Maquina{
    int numero_maq;
    std::vector<int> recur_totales;
    std::vector<int> recur_disp

    
};


class Reserva{
    private:
        int maquina_elegida;
        int recursos_;
        std::string fecha;
        std::list<maquina>=maquinas_

    public:
        inline void Reserva(std::string userID){userID_=getUserID();}
        void setinicioList(numero_maq=8; std::vector<int> recur_totales[numero_maq]={8, 8, 8, 8, 8, 8, 8, 8}; std::vector<int> recur_disp[numero_maq]={8, 8, 8, 8, 8, 8, 8, 8};);
        inline std::list<maquina> setinicioLista(){return maquinas_;}
        void getinicioLista();
        bool setReserva(int maquinas){};
        bool setReserva(int recursos){};
        


    
};
#endif