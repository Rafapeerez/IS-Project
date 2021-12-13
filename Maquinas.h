#ifndef MAQUINAS_H
#define MAQUINAS_H

#include <cstring>
#include <iostream>
#include <vector>

class Maquina{
    private:
        int identMaq_;
        int maquinasTotales_;
        int nMaquinas_;
        

    public:
       inline Maquina(){maquinasTotales_=8;}

        bool setnumMaquinas(int nMaquinas);
        inline int getnumMaquinas(){return nMaquinas_;}

        void darAlta_Baja_Maquina(int maquinas);
        
};

#endif