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
        std::cout<<"|2. Introducir Datos reserva                   |\n";
        std::cout<<"|3. Confirmar operacion                        |\n";
        std::cout<<"|                                              |\n";
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

            case 2: 
                int maq_elegida;
                std::cout<<"Maquina seleccionada: ";
                std::cin>>maq_elegida;
                r.setElegirMaquina(maq_elegida);
                int recursos;
                std::cout<<"Recursos seleccionados: ";
                std::cin>>recursos;
                r.setElegirMaquina(recursos);
                std::string fecha[7];
                std::cout<<"Fecha: ";
                std::cin>>fecha;
                r.setFecha(fecha);
                int confirmacion_op;
                cout<<"Si desea confirmar operacion pulse 1 para continuar"
                cin>>confirmacion_op;
                r.setConfirmacion(confirmacion_op);
            break;

            default:
                std::cout<<"Valor Incorrecto, prueba de nuevo\n";
            break;
        }
    }
}