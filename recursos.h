//recursos.h
//it define the class recursos
#ifndef _RECURSOS_H
#define _RECURSOS_H
#include <iostream>


class Reserva{ //CLASE RECURSOS
    private:
        int recursosmaquina_;

    public:
    Reserva(int recursosmaquina = 0);

        bool setcomprueba(int recursosmaquina); 
        inline int getcomprueba()const {return recursosmaquina_;}


};
#endif