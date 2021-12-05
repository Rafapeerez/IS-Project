#include "reserva.h"
#include "reserva.cc"
#include <stdio.h>
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_RESET "\x1b[39m"
#define ANSI_COLOR_GREEN "\x1b[32m"


int main(){
    Reserva r;
    Fecha f;
    Maquina m;
    int operacion=1;
    r.mostrarMenuReserva();

    while(operacion!=0){
        
        std::cout<<"\nSu eleccion: ";
        std::cin>>operacion;
        std::cout<<"\n";

        switch(operacion){
            
            case 0:
                system("clear");
                r.mostrarMenuReserva();
                std::cout<<"Hasta pronto\n";
                std::cout<<"\n";
            break;

            
            case 1:
                system("clear");
                r.mostrarMenuReserva();
                r.mostrarMaquinas();
            break;


            case 2:
                system("clear");
                r.mostrarMenuReserva();
                r.mostrarFechasOcupadas();
            break;


            case 3: 
                system("clear");
                std::cout<<ANSI_COLOR_RED "¡¡¡CUIDADO!!! SI SE INTRODUCE UN DATO INCORRECTO, SE SALDRA DEL PROGRAMA Y NO SE GUARDARA LA RESERVA\n" ANSI_COLOR_RESET;
                int maq_elegida;//Introduce la maquina a seleccionar
                std::cout<<"Maquina seleccionada (MAX. 8): ";
                std::cin>>maq_elegida;
                r.setElegirMaquina(maq_elegida);

                int recursos;//Introduce los recursos a seleccionar de dicha maquina
                std::cout<<"Recursos seleccionados (MAX. TODAS 8): ";
                std::cin>>recursos;
                r.setElegirRecursos(recursos);
                
                std::cout<<ANSI_COLOR_RED "ATENCION: Las fechas se introducira DD/MM/AAAA y las horas HH.MM\n" ANSI_COLOR_RESET;
                std::cout<<"Introduce el dia de inicio de la reserva: ";
                std::cin>>f.fecha_inicio;
                r.comprobacionFecha(f.fecha_inicio);

                std::cout<<"Introduce la hora de inicio de la reserva: ";
                std::cin>>f.hora_inicio;
                r.comprobacionHora(f.hora_inicio);

                std::cout<<"Introduce el dia de final de la reserva: ";
                std::cin>>f.fecha_final;
                r.comprobacionFecha(f.fecha_final);
                
                if(f.fecha_inicio>f.fecha_final){
                    std::cout<<ANSI_COLOR_RED "ERROR al colocar el fecha. La fecha de inicio es posterior a la final\n" ANSI_COLOR_RESET;
                    exit(0);
                }

                std::cout<<"Introduce la hora de final de la reserva: ";
                std::cin>>f.hora_final;
                r.comprobacionHora(f.hora_final);
                r.comprobarHoraDiaIgual(f.fecha_inicio, f.hora_inicio, f.fecha_final, f.hora_final);

                int confirmacion_op;
                std::cout<<"¿Estas seguro de realizar la reserva? Si es asi pulse 1\n";
                std::cin>>confirmacion_op;
                r.setConfirmacion(confirmacion_op);

                std::cout<<ANSI_COLOR_GREEN "DATOS CORRECTOS, AÑADIDOS CORRECTAMENTE" ANSI_COLOR_RESET;
                f.fecha_maquina=r.getElegirMaquina();
                r.modificaFechasOcupadas(f.fecha_maquina, f.fecha_inicio, f.hora_inicio, f.fecha_final, f.hora_final);
                std::cout<<"\n";
                r.mostrarMenuReserva();
                
            break;

            default:
                std::cout<<ANSI_COLOR_RED "NUMERO INCORRECTO, prueba de nuevo\n" ANSI_COLOR_RESET;
            break;
        }
    }
}