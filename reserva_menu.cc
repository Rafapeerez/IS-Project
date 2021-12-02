#include "reserva.h"
#include "reserva.cc"

int main(){
    Reserva r;
    int operacion=1, v;
    while(operacion!=0){
        std::cout<<"\n|______________________________________________|\n";
        std::cout<<"|                    MENU                      |\n";
        std::cout<<"|______________________________________________|\n";
        std::cout<<"|                                              |\n";
        std::cout<<"|0. Salir del menu                             |\n";
        std::cout<<"|1. Mostrar maquinas disponibles               |\n";
        std::cout<<"|----------------------------------------------|\n";
        std::cout<<"|----------------------------------------------|\n";
        std::cout<<"|----------------------------------------------|\n";
        std::cout<<"|----------------------------------------------|\n";
        std::cout<<"|----------------------------------------------|\n";
        std::cout<<"|______________________________________________|\n";
        std::cout<<"\nSu eleccion: ";
        std::cin>>operacion;
        std::cout<<"\n";

        switch(operacion){
            case 0:
                std::cout<<"Hasta pronto\n";
                std::cout<<"\n";
            break;

            case 1:
                r.mostrarMaquinas();
            break;

            default:
                std::cout<<"Valor Incorrecto, prueba de nuevo\n";
            break;
        }
    }
}