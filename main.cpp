#include "usuario.h"
#include "usuario.cpp"

int main(){
    Usuario user(" ");

    int numeroUsuarios = 0;
    std::cout << "¿Cuantos usuarios quiere dar de alta?" << endl;
    std::cin >> numeroUsuarios;

    user.darAltaUsuario(numeroUsuarios);

    return 0;
}
