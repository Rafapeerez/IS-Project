#ifndef MAQUINAS_H
#define MAQUINAS_H
#include <iostream>


class Maquina{
    private:
        int identMaq_;
        int nMaquinas_;
        
    public:
        inline Maquina(){};
        bool setnumMaquinas(int nMaquina);
        inline int getnumMaquinas(){return nMaquinas_;};
        bool setMaquinasDisponibles(int identMaq);
        inline int getMaquinasDisponibles(){return identMaq_;};
        void darAlta_Baja_Maquina();
        void mostrarDisponibilidad();
};
#endif