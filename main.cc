#include "recursos.h"
#include "recursos.cc"
#include <stdio.h>

    int main(){
    Reserva a;
    
        int recursos;
        std::cout<<"Introduzca el numero de recursos que quieres reservar\n";
        std::cin>>recursos;

        if(a.setcomprueba(recursos) ){
            std::cout<<"Se pueden reservar esos recursos!!!!\n";
        }
        else{
            std::cout<<"No se pueden resevar esos recursos\n";             
        }
    
    
    
    }