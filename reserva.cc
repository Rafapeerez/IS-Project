#include "reserva.h"
#include <vector>
#include <list>
#include <iostream>
#include <fstream>



void Reserva::mostrarMenuReserva(){//Muestra el menu reserva por pantalla
	std::cout<<"\n|______________________________________________|\n";
        std::cout<<"|                    MENU                      |\n";
        std::cout<<"|______________________________________________|\n";
        std::cout<<"|                                              |\n";
        std::cout<<"|0. Salir del menu                             |\n";
        std::cout<<"|1. Mostrar maquinas disponibles               |\n";
        std::cout<<"|2. Mostrar fechas ocupadas                    |\n";
        std::cout<<"|3. Introducir Datos reserva                   |\n";
		std::cout<<"|Consejo: Antes de reserva, ver disponibilidad |\n"; 
        std::cout<<"|______________________________________________|\n\n";
}

void Reserva::mostrarMaquinas(){//Muestra las maquinas junto con los recursos totales + disponibles
    std::cout<<"Maquina X, RECURSOS_TOTALES, RECURSOS_DISPONIBLES\n";
	int j=0;
	for(int i=1; i<=8; i++){
		std::cout<<"Maquina "<<i<<", "<<8<<", "<<vector_recur_disp[j]<<"\n";
		j++;
	}
}

bool Reserva::setElegirMaquina(int &maquina){//Booleano que se encarga de elegir un valor real dentro de la maquina, si se encuentra fuera del valor sale del programa
    if(maquina>0 && maquina<=8){
        maquina_elegida_=maquina;
        return true;
    }
	exit(0);//Sale del programa si se produce un error
    return false;
}

bool Reserva::setElegirRecursos(int recursos){
	int maq_elegida=getElegirMaquina();
	if(vector_recur_disp[maq_elegida-1]>=recursos){
		recursos_=recursos;
 		vector_recur_disp[maq_elegida-1]=vector_recur_disp[maq_elegida-1]-recursos_;
		return true;
	}
    exit(0);
	return false;
}

bool Reserva::setConfirmacion(int confirmacion_op){//Se confirma operacion, si se obtiene un valor distinto a 1, retorna un valor falso
	if(confirmacion_op==1){
		confirmacion_op_=confirmacion_op;
		return true;
	}
	else{
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
	std::cout<<"ERROR al introducir la fecha\n";
	exit(0);
	return false;
}

bool Reserva::comprobarHoraDiaIgual(std::string fecha_inicio, std::string hora_inicio, std::string fecha_final, std::string hora_final){
	if(fecha_inicio==fecha_final){
        if(hora_inicio<hora_final){
            return true;
        }
		else{
			std::cout<<"ERROR al introducir una hora final menor que la hora inicial en el mismo dia\n";
			exit(0);
    		return false;
		}
    }
	return true;
}

