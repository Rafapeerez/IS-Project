//recursos.h
//it define the class recursos
#ifndef _RECURSOS_H
#define _RECURSOS_H
#include <iostream>


class Recursos{ //CLASE RECURSOS
    private:
        int recursosmaquina_;
    public:
        inline Recursos(){recursosmaquina_=8;}
        bool setcomprueba(int recursosmaquina); 
        inline int getcomprueba()const {return recursosmaquina_;}


};
#endif