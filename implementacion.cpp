#include <fstream>
#include <iostream>
using namespace std;

void darAltaUsuario(int usuarios){
    ofstream fichero("Usuarios.txt");

    if(!fichero){
        cout<<"Ha ocurrido un error al intentar abrir el fichero 'BaseDatos.txt' \n";
        exit(EXIT_FAILURE);
    }

    char nombre[256], correo[256], contraseña[256];
    int ID;

    for (int cont = 0; cont < usuarios; cont++){
        cout << "¿Como se llama el usuario?" << endl;
        cin >> nombre;
        cout << "¿Cual es el correo del usuario?" << endl;
        cin >> correo;
        cout << "Determine una contraseña por defecto para el usuario." << endl;
        cin >> contraseña;
        cout << "Determine un ID para el usuario." << endl;
        cin >> ID;

        fichero << nombre << " " << correo << " " << contraseña << " " << ID << endl;
    }

    fichero.close();
}

int main(){
    int numeroUsuarios = 0;
    cout << "¿Cuantos usuarios quiere dar de alta?" << endl;
    cin >> numeroUsuarios;

    darAltaUsuario(numeroUsuarios);

    return 0;
}
