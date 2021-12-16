#ifndef USUARIO_H
#define USUARIO_H

#include <cstring>
#include <fstream>
#include <iostream>
#include <stdio.h>

class Usuario{
    private:
        std::string nombre_;
        std::string correo_;
        std::string contrasena_;
        int ID_;

    public:
        Usuario(std::string nombre, std::string correo, std::string contrasena, int ID);

        inline void setNombre(std::string nombre) { nombre_ = nombre; }
        inline std::string getNombre() { return nombre_; }

        bool setCorreo(std::string correo);
        inline std::string getCorreo() { return correo_; }

        bool setContrasena(std::string contrasena);
        inline std::string getContrasena() { return contrasena_; }

        bool setID(int ID);
        inline int getID() { return ID_; }

        void darAltaUsuario(int usuarios);
};

#endif