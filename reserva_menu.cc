#include "reserva.h"
#include <stdio.h>
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_RESET "\x1b[39m"
#define ANSI_COLOR_GREEN "\x1b[32m"


int main(){
    int ID;
    std::string nombre;
    std::string contrasena;
    std::cout<<"Introduce el ID: ";
    std::cin>>ID;
    std::cout<<"Introduce el nombre: ";
    std::cin>>nombre;
    std::cout<<"Introduce la contraseña: ";
    std::cin>>contrasena;
    
    if(ID>=0 && ID<=4){
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

                case 1:
                    char confirmacion1;
                    std::cout<<ANSI_COLOR_RED "¿Estas seguro de que tienes acceso al control de los usuarios? y/n \n" ANSI_COLOR_RESET; 
                    std::cin>>confirmacion1;
                    if(confirmacion1!='y'){
                        exit(0);
                    }
                    //CODIGO RAFA
                break;

                case 2:
                char confirmacion2;
                    std::cout<<ANSI_COLOR_RED "¿Estas seguro de que tienes acceso al control de las maquinas? y/n \n" ANSI_COLOR_RESET; 
                    std::cin>>confirmacion2;
                    if(confirmacion1!='y'){
                        exit(0);
                    }
                    //CODIGO ANTONIO
                break;

                case 3:
                    //CODIGO CHEMA
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

                case 0:
                    system("clear");
                    std::cout<<"Hasta pronto\n";
                    std::cout<<"\n";
                    exit(0);
                break;

                case 1:{
                    Reserva r;
                    r.menu();    
                break;}
                
                case 2:
                    std::cout<<ANSI_COLOR_RED "ESTE HISTORIA DE USUARIO NO ESTA IMPLEMENTADA\n" ANSI_COLOR_RESET; 
                break;

                case 3:
                    std::cout<<ANSI_COLOR_RED "ESTE HISTORIA DE USUARIO NO ESTA IMPLEMENTADA\n" ANSI_COLOR_RESET; 
                break;
                                
                default:
                    std::cout<<ANSI_COLOR_RED "NUMERO INCORRECTO, prueba de nuevo\n" ANSI_COLOR_RESET;
                break;        
            }
        }
    }
}