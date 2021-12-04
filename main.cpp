#include "usuario.h"
#include "usuario.cpp"

int main(){
    int numeroUsuarios = 0;
    std::cout << "¿Cuantos usuarios quiere dar de alta?" << endl;
    std::cin >> numeroUsuarios;

    darAltaUsuario(numeroUsuarios);
    
    return 0;
}
