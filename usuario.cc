#include "usuario.h"
using namespace std;

Usuario::Usuario(string nombre, string correo=" ", string contrasena=" ", int ID=0){
    nombre_ = nombre;
    correo_ = correo;
    contrasena_ = contrasena;
    ID_ = ID;
}

bool Usuario::setCorreo(string correo){
    string at = "@";
    if(strstr(correo.c_str(), at.c_str())){
        correo_ = correo;
        return true;
    }
    cout << "El correo introducido es invalido. \n";
    return false;
}

bool Usuario::setID(int ID){
    ifstream f("Usuarios.txt");
    if(!f){
        cout << "Error al abrir el fichero. \n";
        EXIT_FAILURE;
    }

    char name[255], email[255], password[255], identifier[255];
    char *ptr;
    while (f.getline(name, 255, ' ')){
        f.getline(email, 255, ' ');
        f.getline(password, 255, ' ');
        f.getline(identifier, 255, '\n');
        if (strtol(identifier,&ptr,10) == ID){
            cout << "No se puede insertar el ID que acaba de introducir ya que se encuentra en la base de datos. \n";
            return false;
        }
    }

    ID_ = ID;
    return true;
}

bool Usuario::setContrasena(string contrasena){
    if(strlen(contrasena.c_str())>=6){
        contrasena_ = contrasena;
        return true;
    }

    cout << "Necesitas una contraseña de minimo 6 caracteres. \n";
    return false;
}

void Usuario::darAltaUsuario(int usuarios){
    
    fstream fichero("Usuarios.txt", fstream::app);
    if(!fichero){
        cout<<"Ha ocurrido un error al intentar abrir el fichero 'Usuarios.txt' \n";
        exit(EXIT_FAILURE);
    }

    std::string nombre, correo, contrasena;
    int ID;

    for (int cont = 0; cont < usuarios; cont++){
        cout << "¿Como se llama el usuario?" << endl;
        cin >> nombre;
        setNombre(nombre);

        cout << "¿Cual es el correo del usuario?" << endl;
        cin >> correo;
        if(setCorreo(correo) == false){
            exit(EXIT_FAILURE);
        }

        cout << "Determine una contraseña por defecto para el usuario." << endl;
        cin >> contrasena;
        setContrasena(contrasena);
        if(setContrasena(contrasena) == false){
            exit(EXIT_FAILURE);
        }

        cout << "Determine un ID para el usuario." << endl;
        cin >> ID;
        setID(ID);
        if(setID(ID) == false){
            exit(EXIT_FAILURE);
        }

        fichero << getNombre() << " " << getCorreo() << " " << getContrasena() << " " << getID() << endl;
    }
    fichero.close();
}