#ifndef _RECURSOS_H
#define _RECURSOS_H
#include <iostream>
#include <cstring>


class Recursos{ 
    private:
        int recursosmaquina_;
        std::string maximo_;

    public:
        Recursos(std::string maximo);
        inline Recursos(){recursosmaquina_;}
        bool setcomprueba(int recursosmaquina); 
        inline int getcomprueba()const {return recursosmaquina_;}
        inline void setMaximo(std::string maximo) { maximo_ = maximo; }
        inline std::string getMaximo() { return maximo_; }
        bool setFichero();
        void restringe();  
        int setmostrarrecursos();
};
#endif