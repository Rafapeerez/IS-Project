#include "maquinas.h"
using namespace std;

 bool Maquina::setnumMaquinas(int nMaquinas){
     if(nMaquinas_>0 && nMaquinas<=8){
        nMaquinas_=nMaquinas;
        return true;
     }
     exit(0);
     return false;
 }

bool Maquina::setMaquinasDisponibles(int identMaq){
     if(identMaq>0 && identMaq<=8){
        identMaq_=identMaq;
        return true;
     }
     exit(0);
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
        f<<getMaquinasDisponibles()<<endl;
        
    }

    f.close();
 }