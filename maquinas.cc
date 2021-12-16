#include "maquinas.h"
#include <fstream>
using namespace std;

bool Maquina::setnumMaquinas(int nMaquinas){
    if(nMaquinas_>0 && nMaquinas<=8){
        nMaquinas_=nMaquinas;
        return true;
    }
    return false;
}

bool Maquina::setMaquinasDisponibles(int identMaq){
    if(identMaq>0 && identMaq<=8){
        identMaq_=identMaq;
        return true;
    }
    return false;
}


void Maquina::darAlta_Baja_Maquina(){
    remove("Maquinas.txt");
    fstream f("Maquinas.txt", fstream::app);
    if(!f){
        cout<<"Ha ocurrido un error al intentar abrir el fichero 'Maquinas.txt' \n";
        exit(EXIT_FAILURE);
    }
    int numMaquinas;
    cout<<"Introduzca el numero de maquinas disponibles: "<<endl;
    for(int i=0;i<nMaquinas_;i++){
        cin>>numMaquinas;
        setMaquinasDisponibles(numMaquinas);
        f<<"Maquina "<<getMaquinasDisponibles()<<endl;
        
    }

    f.close();
}

void Maquina::mostrarDisponibilidad(){//Muestra el valor de las fechas ocupadas sin mostrar los usuarios que han realizado las reservas
    FILE* f;
    long medida;
	char* texto;	
    const char* nombre="Maquinas.txt";
	f=fopen(nombre, "r");
	fseek(f, 0, SEEK_END);
    medida=ftell(f);
    rewind(f);

   	texto=(char*)malloc (sizeof(char)*medida);
	fread(texto, medida+1, 1, f);
    std::cout<<texto<<std::endl;
    fclose(f);
}