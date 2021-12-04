#include "reserva.h"
#include "reserva.cc"


int main(){
    Reserva r;
    Fecha f;
    int operacion=1, v;
    while(operacion!=0){
        std::cout<<"\n|______________________________________________|\n";
        std::cout<<"|                    MENU                      |\n";
        std::cout<<"|______________________________________________|\n";
        std::cout<<"|                                              |\n";
        std::cout<<"|0. Salir del menu                             |\n";
        std::cout<<"|1. Mostrar maquinas disponibles               |\n";
        std::cout<<"|2. Introducir Datos reserva                   |\n";
        std::cout<<"|3. Mostrar fechas ocupadas                    |\n";
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
                f.fecha_maquina=r.getElegirMaquina();
                int recursos;
                std::cout<<"Recursos seleccionados: ";
                std::cin>>recursos;
                r.setElegirMaquina(recursos);
                std::cout<<"Introduce el dia de inicio de la reserva: ";
                std::cin>>f.fecha_inicio;
                std::cout<<"Introduce la hora de inicio de la reserva: ";
                std::cin>>f.hora_inicio;
                std::cout<<"Introduce el dia de final de la reserva: ";
                std::cin>>f.fecha_final;
                std::cout<<"Introduce la hora de final de la reserva: ";
                std::cin>>f.hora_final;
                r.modificaFechasOcupadas(f.fecha_maquina, f.fecha_inicio, f.hora_inicio, f.fecha_final, f.hora_final);
                int confirmacion_op;
                std::cout<<"Si desea confirmar operacion pulse 1 para continuar\n";
                std::cin>>confirmacion_op;
                r.setConfirmacion(confirmacion_op);
            break;

            case 3:
                r.mostrarFechasOcupadas();
            break;

            default:
                std::cout<<"Valor Incorrecto, prueba de nuevo\n";
            break;
        }
    }
}