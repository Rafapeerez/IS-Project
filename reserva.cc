#include "reserva.h"
#include <vector>
#include <list>
#include <iostream>
#include <fstream>
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_RESET "\x1b[39m"
#define ANSI_COLOR_GREEN "\x1b[32m"

void Reserva::mostrarMenuReserva(){//Muestra el menu reserva por pantalla
	std::cout<<"\n ______________________________________________\n";
        std::cout<<"|                    MENU                      |\n";
        std::cout<<"|______________________________________________|\n";
        std::cout<<"|                                              |\n";
		std::cout<<"|Consejo: Antes de reserva, ver disponibilidad |\n"; 
		std::cout<<"|           de las maquinas y fechas           |\n"; 
		std::cout<<"|______________________________________________|\n";
        std::cout<<"|0. Salir del menu                             |\n";
        std::cout<<"|1. Mostrar maquinas disponibles               |\n";
        std::cout<<"|2. Mostrar fechas ocupadas                    |\n";
		std::cout<<"|3. Mostrar maquinas disponibles               |\n";
        std::cout<<"|4. Introducir Datos reserva                   |\n";
        std::cout<<"|______________________________________________|\n\n";
}

void Reserva::mostrarMaquinas(){//Muestra las maquinas junto con los recursos totales + disponibles
    std::cout<<"___________________________________________________\n";
	std::cout<<"|Maquina X| RECURSOS_TOTALES| RECURSOS_DISPONIBLES|\n";
	std::cout<<"___________________________________________________\n";
	int j=0;
	for(int i=1; i<=8; i++){
		std::cout<<"|Maquina "<<i<<"|	    "<<8<<"       |		"<<vector_recur_disp[j]<<"	   |\n";
		j++;
	}
	std::cout<<"|__________________________________________________|\n";
}

bool Reserva::setElegirMaquina(int &maquina){//Booleano que se encarga de elegir un valor real dentro de la maquina, si se encuentra fuera del valor sale del programa
    if(maquina>0 && maquina<=8){
        maquina_elegida_=maquina;
        return true;
    }
    return false;
}

bool Reserva::setElegirRecursos(int recursos, int maximo){
	int maq_elegida=getElegirMaquina();
	if(recursos>0 && vector_recur_disp[maq_elegida-1]>=recursos && maximo>=recursos){
		recursos_=recursos;
		vector_recur_disp[maq_elegida-1]=vector_recur_disp[maq_elegida-1]-recursos;
		return true;
	}
	return false;
}

bool Reserva::setConfirmacion(int confirmacion_op){//Se confirma operacion, si se obtiene un valor distinto a 1, retorna un valor falso
	if(confirmacion_op==1){
		confirmacion_op_=confirmacion_op;
		return true;
	}
	else{
		std::cout<<ANSI_COLOR_RED "No se incluyo la reserva\n" ANSI_COLOR_RESET;
		exit(0);
		return false;
	}
}

void Reserva::setFecha(){//Se genera fechas.txt que muestra las fechas que se encuentra ocupadas
    std::ifstream f("fechas.txt");
	if(!f){
		std::cout<<"Se ha producido un error al intentar abrir el fichero 'fechas.txt'\n";
		EXIT_FAILURE;
	}
	fecha_.clear();
	Fecha fec;
	std::string cadena;
	getline(f, cadena, ',');
	while(!f.eof()){
		fec.fecha_maquina=std::stoi(cadena);
		getline(f, cadena, ',');
    	fec.fecha_inicio=cadena;
	    getline(f, cadena, ',');
		fec.hora_inicio=cadena;
	    getline(f, cadena, ',');
		fec.fecha_final=cadena;
		getline(f, cadena, ',');
		fec.hora_final=cadena;
		fecha_.push_back(fec);
		getline(f, cadena, ',');
    }
}

void Reserva::modificaFechasOcupadas(int fecha_maquina, std::string fecha_inicio, std::string hora_inicio, std::string fecha_final, std::string hora_final){//Modifica fechas.txt colocando el valor correspondiente de la reserva que se acaba de introducir 
	std::ofstream out;
	std::string fecha_maq=std::to_string(fecha_maquina);
	out.open("fechas.txt", std::ios::app);
	std::string cadena= fecha_maq + ", " + fecha_inicio + ", " + hora_inicio + ", "  + fecha_final+ ", "  + hora_final + "\n";
	out<<cadena; 
	
}

void Reserva::mostrarFechasOcupadas(){//Muestra el valor de las fechas ocupadas sin mostrar los usuarios que han realizado las reservas
    FILE* f;
    long medida;
    char* texto;
	const char* nombre="fechas.txt";
  	f=fopen(nombre, "r");
    fseek(f, 0, SEEK_END);
    medida=ftell(f);
    rewind(f);

	texto=(char*)malloc (sizeof(char)*medida);
   	fread(texto, medida+1, 1, f);
    std::cout<<texto<<std::endl;
    fclose(f);
}

bool Reserva::comprobacionHora(std::string hora){
	if(stoi(hora)>=00.00 && stoi(hora)<=24.00){
		return true;
	}
	return false;
}

bool Reserva::comprobacionFecha(std::string fecha){//Comprueba que la fecha es correcta
	std::string cadena="01/01/2021";
	std::string cadena2="31/12/2030";
	if(fecha>cadena && fecha<=cadena2){
		return true;
	}
	return false;
}

bool Reserva::comprobarHoraDiaIgual(std::string fecha_inicio, std::string hora_inicio, std::string fecha_final, std::string hora_final){
	if(fecha_inicio==fecha_final){
        if(hora_inicio<hora_final){
            return true;
        }
		else{
    		return false;
		}
    }
	return true;
}






