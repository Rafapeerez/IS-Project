#include "recursos.h"
#include <iostream>
#include <fstream>
using namespace std;


Recursos::Recursos(std::string maximo){
  	maximo_ = maximo;
}


bool Recursos::setcomprueba(int recursosmaquina){
	if(recursosmaquina>0 && recursosmaquina<=8){
		recursosmaquina_=recursosmaquina;
		return true;
	}
	else{
		return false;
	}
}

bool Recursos::setFichero(){
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
	return false;
}

void Recursos::restringe(){
	fstream fichero("restriccionUsuario.txt", fstream::app);
	const char* nombre="restriccionUsuario.txt";
    if((fopen(nombre, "w"))==NULL){
    	cout<<"Ha ocurrido un error al intentar abrir el fichero 'restriccionUsuario.txt' \n";
    	exit(EXIT_FAILURE);
    }

<<<<<<< HEAD
    	string maximo=std::to_string(getcomprueba());
        cin >> maximo;
        setMaximo(maximo);
=======
    string maximo;

    cout << "Como administrador elija el máximo de recursos que los usuarios pueden reservar" << endl;
    cin >> maximo;
    setMaximo(maximo);
>>>>>>> 8975ab12adffb79af0c455f77071132d906f5dbd

    fichero << getMaximo() << endl;

    fichero.close();
}

int Recursos::setmostrarrecursos(){
    ifstream f("restriccionUsuario.txt");
    if(!f){
        cout << "Error al abrir el fichero. \n";
        EXIT_FAILURE;
    }
    char recurs[256];
    char *ptr;
    f.getline(recurs, 255, '\n');
    int recursos=strtol(recurs,&ptr,10);
	return recursos;
}