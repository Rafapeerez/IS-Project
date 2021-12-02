#include "reserva.h"
#include <vector>
#include <list>
#include <iostream>
#include <fstream>

void Reserva::setMaquinas(){
	std::ifstream f("maquinas.txt");
	if(!f){
		std::cout<<"Se ha producido un error al intentar abrir el fichero 'DNI.txt'\n";
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
	getline(f, cadena, ',');
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