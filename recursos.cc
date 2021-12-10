#include "recursos.h"
#include <iostream>
#include <fstream>
using namespace std;


		Reserva::Reserva(std::string maximo){
  			maximo_ = maximo;
		}


	bool Reserva::setcomprueba(int recursosmaquina){
		if(recursosmaquina>0 && recursosmaquina<=8){
			recursosmaquina_=recursosmaquina;
			return true;

		}
		else{
			return false;
		}
	}

	bool Reserva::setFichero(){
    ifstream f("restriccionUsuario.txt");
    if(!f){
        cout << "Error al abrir el fichero. \n";
        EXIT_FAILURE;
    }

 		char name[255];
  		char *ptr;
   		while (f.getline(name, 255, ' ')){
   			return true;
		}
	}

	void Reserva::restringe(){
    
		 fstream fichero("restriccionUsuario.txt", fstream::app);
		 const char* nombre="restriccionUsuario.txt";
    	if((fopen(nombre, "w"))==NULL){
        	cout<<"Ha ocurrido un error al intentar abrir el fichero 'restriccionUsuario.txt' \n";
        	exit(EXIT_FAILURE);
 	    }

    string maximo;

        cout << "Como administrador elija el máximo de recursos que los usuarios pueden reservar" << endl;
        cin >> maximo;
        setMaximo(maximo);

        fichero << getMaximo() << endl;

    fichero.close();
}
