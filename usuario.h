#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>


class Usuario{
    private:
        std::string nombre_, correo_, contraseña_;
        int ID_;

    public:
        Usuario(std::string nombre,std::string correo, std::string contraseña, int ID=0);

        inline void setNombre(char nombre) { nombre_ = nombre; }
        inline std::string getNombre() { return nombre_; }

        inline void setNombre(char nombre) { nombre_ = nombre; }
        inline std::string getNombre() { return nombre_; }
        

        inline void setNombre(char nombre) { nombre_ = nombre; }
        inline std::string getNombre() { return nombre_; }

};

#endif