//recursos.h
//it define the class recursos
#ifndef _RECURSOS_H
#define _RECURSOS_H
#include <iostream>
#include <cstring>


class Reserva{ 
    private:
        int recursosmaquina_;
        std::string maximo_;

    public:
    Reserva(std::string maximo);

    inline Reserva(){recursosmaquina_;}

        bool setcomprueba(int recursosmaquina); 
        inline int getcomprueba()const {return recursosmaquina_;}

        inline void setMaximo(std::string maximo) { maximo_ = maximo; }
        inline std::string getMaximo() { return maximo_; }

        bool setFichero();

        void restringe();   


};
#endif