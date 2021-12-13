#include "maquinas.h"
using namespace std;

 bool setnumMaquinas(int nMaquinas){
     if(nMaquinas>0 && nMaquinas<=8){
         nMaquinas_=nMaquinas;
         return true;
     }
     exit (0);
     return false;
 }


 void darAlta_Baja_Maquina(int maquinas){
     fstream f("Maquinas.txt", fstream::app);
    if(!f){
        cout<<"Ha ocurrido un error al intentar abrir el fichero 'Maquinas.txt' \n";
        exit(EXIT_FAILURE);
    }
    int numMaquinas;
    cout<<"Introduzca el numero de maquinas disponibles: "<<endl;
    for(int i=0;i<nMaquinas_;i++){
        cin>>numMaquinas;
        setnumMaquinas(numMaquinas);
        f<<getnumMaquinas()<<endl;
        
    }

    f.close();
 }