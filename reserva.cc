#include "reserva.h"
#include <vector>
#include <list>
#include <iostream>
#include <fstream>

void Reserva::setMaquinas(){
	std::ifstream f("maquinas.txt");
	if(!f){
		std::cout<<"Se ha producido un error al intentar abrir el fichero 'maquinas.txt'\n";
		EXIT_FAILURE;
	}
    maquinas_.clear();
	Maquina m;
	std::string cadena;
	getline(f, cadena, ',');
	while(!f.eof()){
    		m.numero_maq=std::stoi(cadena);
	    	getline(f, cadena, ',');
		    m.recur_totales=std::stoi(cadena);
    		getline(f, cadena, '\n');
	    	m.recur_disp=std::stoi(cadena);
		    maquinas_.push_back(m);
		    getline(f, cadena, ',');
    }
}

void Reserva::mostrarMaquinas(){
    FILE* f;
    long medida;
    char* texto;
    f=fopen("maquinas.txt", "r");
    fseek(f, 0, SEEK_END);
    medida=ftell(f);
    rewind(f);

    texto=(char*)malloc (sizeof(char)*medida);
    fread(texto, medida+1, 1, f);
    std::cout<<texto<<std::endl;
    fclose(f);
}

bool Reserva::setElegirMaquina(int &maquina){
    if(maquina>0 && maquina<=8){
        maquina_elegida_=maquina;
        return true;
    }
    return false;
}

bool Reserva::setElegirRecursos(int &recursos){
	std::ifstream f("maquinas.txt");
	if(!f){
		std::cout<<"Se ha producido un error al intentar abrir el fichero 'DNI.txt'\n";
		EXIT_FAILURE;
	}

	maquinas_.clear();
	Maquina m;
    std::string cadena;
	std::getline(f, cadena, ',');
	while(!f.eof()){
        if(m.numero_maq==maquina_elegida_){
            if(recursos>0 && recursos<=m.recur_disp){
                recursos_=recursos;
                m.numero_maq=std::stoi(cadena);
	    	    getline(f, cadena, ',');
		        m.recur_totales=std::stoi(cadena);
    		    getline(f, cadena, '\n');
	    	    m.recur_disp=m.recur_disp-getElegirRecursos();
		        maquinas_.push_back(m);
		        getline(f, cadena, ',');
                return true;
            }
	    }
        m.numero_maq=std::stoi(cadena);
	    	getline(f, cadena, ',');
		    m.recur_totales=std::stoi(cadena);
    		getline(f, cadena, '\n');
	    	m.recur_disp=std::stoi(cadena);
		    maquinas_.push_back(m);
		    getline(f, cadena, ',');
    }
    return false;
}

bool Reserva::setConfirmacion(int confirmacion_op){
	if(confirmacion_op==1){
		confirmacion_op_=confirmacion_op;
		return true;
	}
	else{
		return false;
	}
}

void Reserva::setFecha(){
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

void Reserva::modificaFechasOcupadas(int fecha_maquina, std::string fecha_inicio, std::string hora_inicio, std::string fecha_final, std::string hora_final){
	std::ofstream out;
	std::string fecha_maq=std::to_string(fecha_maquina);
	out.open("fechas.txt", std::ios::app);
	std::string cadena= fecha_maq + ", " + fecha_inicio + ", " + hora_inicio + ", "  + fecha_final+ ", "  + hora_final + "\n";
	out<<cadena; 
	
}

void Reserva::mostrarFechasOcupadas(){
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



