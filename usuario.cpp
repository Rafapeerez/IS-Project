#include <fstream>
#include <iostream>
#include "usuario.h"
using namespace std;

Usuario::Usuario(string nombre, string correo=" ", string contraseña=" ", int ID=0){
    nombre_ = nombre;
    correo_ = correo;
    contraseña_ = contraseña;
    ID_ = ID;
}

void Usuario::darAltaUsuario(int usuarios){
    ofstream fichero("Usuarios.txt");
    if(!fichero){
        cout<<"Ha ocurrido un error al intentar abrir el fichero 'BaseDatos.txt' \n";
        exit(EXIT_FAILURE);
    }

    std::string nombre, correo, contraseña;
    int ID;

    for (int cont = 0; cont < usuarios; cont++){
        cout << "¿Como se llama el usuario?" << endl;
        cin >> nombre;
        setNombre(nombre);
        cout << "¿Cual es el correo del usuario?" << endl;
        cin >> correo;
        setCorreo(correo);
        cout << "Determine una contraseña por defecto para el usuario." << endl;
        cin >> contraseña;
        setContraseña(contraseña);
        cout << "Determine un ID para el usuario." << endl;
        cin >> ID;
        setID(ID);

        fichero << getNombre() << " " << getCorreo() << " " << getContraseña() << " " << getID() << endl;
    }

    fichero.close();
}


