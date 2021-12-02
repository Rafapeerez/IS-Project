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
