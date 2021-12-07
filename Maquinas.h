#ifndef MAQUINAS_H
#define MAQUINAS_H

#include <cstring>
#include <iostream>
#include <vector>

class Maquina{
    private:
        int ID_;
        int identMaq_;

    public:
        Maquina(int ID,int identMaq);

        bool setuserID(int ID){ID_=ID;}
        inline int getuserID(){return ID_;}

        bool setIdentificadorMaquina(int identMaq){identMaq_=identMaq;}
        inline int getIdentificadorMaquina(){return identMaq_;}

        void darAltaMaquina(int maquinas);
    
};

#endif