#ifndef USUARIO_H
#define USUARIO_H

#include <string>

class Usuario{
    private:
        std::string nombre_;
        std::string correo_;
        std::string contraseña_;
        int ID_;

    public:
        Usuario(std::string nombre, std::string correo, std::string contraseña, int ID);

        inline void setNombre(std::string nombre) { nombre_ = nombre; }
        inline std::string getNombre() { return nombre_; }

        inline void setCorreo(std::string correo) { correo_ = correo; }
        inline std::string getCorreo() { return correo_; }
        

        inline void setContraseña(std::string contraseña) { contraseña_ = contraseña; }
        inline std::string getContraseña() { return contraseña_; }

        inline void setID(int ID) { ID_ = ID; }
        inline int getID() { return ID_; }

        void darAltaUsuario(int usuarios);
};

#endif