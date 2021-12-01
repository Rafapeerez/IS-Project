#include "reserva.h"
#define maquinas 8

bool Reserva::setMaquinas(int &maquina){
    if(maquina_>=0 && maquina>=8){
        maquina_=maquina
        return true;
    }
    return false;
}

bool Reserva::setReserva(int recursos){
    if(recursos>0 && recursos<=recurs_disp[maquina_]){
        recursos_=recursos;
        recurs_disp[maquina_]=recursos_;
        return true;
    }
    return false;
};

void Reserva::escribeMaquinas(){
    std::ofstream f("maquinas.txt");
    if(!f){
        std::cout<<"ERROR al abrir el archivo\n"
        EXIT_FAILURE;
    }
    std::
}

void Reserva::getinicioLista(){
    std::ofstream
    if(!f){
        std::cout
        EXIT_FAILURE;
    }
    std::list<Maquinas>:iterator j;
    j=Maquinas_.begin();
    for(int i=0; i<maquinas)
}