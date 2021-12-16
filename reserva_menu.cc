#include "reserva.h"
#include "reserva.cc"
#include <stdio.h>
#include "usuario.h"
#include "usuario.cc"
#include "recursos.h"
#include "recursos.cc"
#include "maquinas.h"
#include "maquinas.cc"
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_RESET "\x1b[39m"
#define ANSI_COLOR_GREEN "\x1b[32m"


int main(){
    int ID;
    std::string nombre;
    std::string contrasena;
    std::cout<<"Introduce el ID: ";
    std::cin>>ID;
    if(ID<=0){
        exit(0);
    }
    std::cout<<"Introduce el nombre: ";
    std::cin>>nombre;
    std::cout<<"Introduce la contraseña: ";
    std::cin>>contrasena;
    
    if(ID>0 && ID<=4){
        std::cout<<ANSI_COLOR_GREEN "ACCESO PERMITIDO, ADMINISTRADOR\n" ANSI_COLOR_RESET;
        int operacion_admin=1;
        while(operacion_admin!=0){
    	    std::cout<<"\n ______________________________________________\n";
            std::cout<<"|                    MENU                      |\n";
            std::cout<<"|______________________________________________|\n";
            std::cout<<"|0. Salir del menu                             |\n";
            std::cout<<"|1. Crear/Eliminar Usuarios (Admin Usuario)    |\n";
            std::cout<<"|2. Dar alta/baja maquina (Admin Maquinas)     |\n";
            std::cout<<"|3. Restringir Recursos Máximos                |\n";
            std::cout<<"|______________________________________________|\n\n";
            std::cout<<"\nSu eleccion: ";
            std::cin>>operacion_admin;
            std::cout<<"\n";
            switch(operacion_admin){

                case 0:
                    system("clear");
                    std::cout<<"Hasta pronto\n";
                    std::cout<<"\n";
                    exit(0);
                break;

                case 1:{
                    if(ID>3){
                    std::cout<<ANSI_COLOR_RED "No tiene permiso para acceder a este menu\n" ANSI_COLOR_RESET; 
                    exit(0);
                    }
                    std::cout<<ANSI_COLOR_GREEN "ACCESO PERMITIDO, ADMINISTRADOR DE USUARIOS\n" ANSI_COLOR_RESET;
                    Usuario user(" ");
                    int numeroUsuarios = 0;
                    std::cout << "¿Cuantos usuarios quiere dar de alta?" << endl;
                    std::cin >> numeroUsuarios;
                    user.darAltaUsuario(numeroUsuarios);
                }break;

                case 2:{
                    if(ID<3){
                    std::cout<<ANSI_COLOR_RED "No tiene permiso para acceder a este menu\n" ANSI_COLOR_RESET; 
                    exit(0);
                    }
                    std::cout<<ANSI_COLOR_GREEN "ACCESO PERMITIDO, ADMINISTRADOR DE MAQUINAS\n" ANSI_COLOR_RESET;
                    Maquina m;
                    int maq;
                    std::cout<<ANSI_COLOR_RED "Si introduces un valor incorrecto, se saldra del programa \n" ANSI_COLOR_RESET; 
                    std::cout<<"Introduce el numero de maquinas que desea que esten disponibles: ";
                    std::cin>>maq;
                    m.setnumMaquinas(maq);
                    if(m.setnumMaquinas(maq)==false){
                        exit(0);
                    }
                    m.darAlta_Baja_Maquina();
                } break;

                case 3:
                    Recursos a;
                    a.restringe();   
                    break;
            }
 
        }
    }
    else{
        std::cout<<ANSI_COLOR_GREEN "ACCESO PERMITIDO, USUARIO\n" ANSI_COLOR_RESET;
        int operacion_usuario=1;
        while(operacion_usuario!=0){
            std::cout<<"\n ______________________________________________\n";
            std::cout<<"|                    MENU                      |\n";
            std::cout<<"|______________________________________________|\n";
            std::cout<<"|0. Salir del menu                             |\n";
            std::cout<<"|1. Realizar un reserva                        |\n";
            std::cout<<"|2. Modificar una reserva                      |\n";
            std::cout<<"|3. Eliminar una reserva                       |\n";
            std::cout<<"|______________________________________________|\n\n";
            std::cout<<"\nSu eleccion: ";
            std::cin>>operacion_usuario;
            std::cout<<"\n";
            switch(operacion_usuario){

                case 0:{
                    system("clear");
                    std::cout<<"Hasta pronto\n";
                    std::cout<<"\n";
                    exit(0);
                }break;

                case 1:{
                    Recursos a;
                    int valor=a.setmostrarrecursos();
                    Reserva r;
                    Fecha f;
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

            case 3:{
                system("clear");
                Maquina m;
                r.mostrarMaquinas();
                cout<<"\n";
                m.mostrarDisponibilidad();
            }break;

            case 4: 
                system("clear");
                std::cout<<ANSI_COLOR_RED "¡¡¡CUIDADO!!! SI SE INTRODUCE UN DATO INCORRECTO, SE SALDRA DEL PROGRAMA Y NO SE GUARDARA LA RESERVA\n" ANSI_COLOR_RESET;
                int maq_elegida;//Introduce la maquina a seleccionar
                std::cout<<"Maquina seleccionada (MAX. 8): ";
                std::cin>>maq_elegida;
                r.setElegirMaquina(maq_elegida);
                if(r.setElegirMaquina(maq_elegida)==false){
                    std::cout<<ANSI_COLOR_RED "ERROR MAQUINA NO DISPONIBLE\n" ANSI_COLOR_RESET;
                    exit(0);
                }

                int recursos;//Introduce los recursos a seleccionar de dicha maquina
                std::cout<<ANSI_COLOR_RED "EL MAXIMO DE RECURSOS A RESERVAR SERA DE "<<valor<<"\n" ANSI_COLOR_RESET;
                std::cout<<"Recursos seleccionados (MAX. TODAS 8): ";
                std::cin>>recursos;
                if(r.setElegirRecursos(recursos, valor)==false){
                    std::cout<<ANSI_COLOR_RED "ERROR RECURSOS NO DISPONIBLES PARA DICHA MAQUINA, TEN EN CUENTA LA DISPONIBILIDAD\n" ANSI_COLOR_RESET;
                    exit(0);
                }

                std::cout<<ANSI_COLOR_RED "ATENCION: Las fechas se introducira DD/MM/AAAA y las horas HH.MM\n" ANSI_COLOR_RESET;
                std::cout<<"Introduce el dia de inicio de la reserva: ";
                std::cin>>f.fecha_inicio;
                r.comprobacionFecha(f.fecha_inicio);
                if(r.comprobacionFecha(f.fecha_inicio)==false){
                    std::cout<<ANSI_COLOR_RED "ERROR al introducir la fecha\n" ANSI_COLOR_RESET;
                    exit(0);
                }


                std::cout<<"Introduce la hora de inicio de la reserva: ";
                std::cin>>f.hora_inicio;
                r.comprobacionHora(f.hora_inicio);
                if(r.comprobacionHora(f.hora_inicio)==false){
                    std::cout<<ANSI_COLOR_RED "ERROR al introducir la hora\n" ANSI_COLOR_RESET;
                    exit(0);
                }
                

                std::cout<<"Introduce el dia de final de la reserva: ";
                std::cin>>f.fecha_final;
                r.comprobacionFecha(f.fecha_final);
                if(r.comprobacionFecha(f.fecha_final)==false){
                    std::cout<<ANSI_COLOR_RED "ERROR al introducir la fecha\n" ANSI_COLOR_RESET;
                    exit(0);
                }
                
                if(f.fecha_inicio>f.fecha_final){
                    std::cout<<ANSI_COLOR_RED "ERROR al colocar el fecha. La fecha de inicio es posterior a la final\n" ANSI_COLOR_RESET;
                    exit(0);
                }

                std::cout<<"Introduce la hora de final de la reserva: ";
                std::cin>>f.hora_final;
                r.comprobacionHora(f.hora_final);
                if(r.comprobacionHora(f.hora_inicio)==false){
                    std::cout<<ANSI_COLOR_RED "ERROR al introducir la hora\n" ANSI_COLOR_RESET;
                    exit(0);
                }
                
                r.comprobarHoraDiaIgual(f.fecha_inicio, f.hora_inicio, f.fecha_final, f.hora_final);
                if(r.comprobarHoraDiaIgual(f.fecha_inicio, f.hora_inicio, f.fecha_final, f.hora_final)==false){
                    std::cout<<ANSI_COLOR_RED "ERROR al introducir una hora final menor que la hora inicial en el mismo dia\n" ANSI_COLOR_RESET;
                    exit(0);
                }

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
                }break;
                
                case 2:{
                    std::cout<<ANSI_COLOR_RED "ESTE HISTORIA DE USUARIO NO ESTA IMPLEMENTADA\n" ANSI_COLOR_RESET; 
                }break;

                case 3:{
                    std::cout<<ANSI_COLOR_RED "ESTE HISTORIA DE USUARIO NO ESTA IMPLEMENTADA\n" ANSI_COLOR_RESET; 
                }break;
                                
                default:{
                    std::cout<<ANSI_COLOR_RED "NUMERO INCORRECTO, prueba de nuevo\n" ANSI_COLOR_RESET;
                }break;        
            }
        }
    }
}