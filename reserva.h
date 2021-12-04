//reserva.h
//it define the class reserva
#ifndef _RESERVA_H
#define _RESERVA_H
#include <iostream>
#include <vector>
#include <list>

struct Maquina{ //Estructura de la maquina
    int numero_maq;
    int recur_totales;
    int recur_disp;
};

struct Fecha{ //Estructura de la fecha
    int fecha_maquina; 
    std::string fecha_inicio;
    std::string hora_inicio;
    std::string fecha_final;
    std::string hora_final;
};

class Reserva{ //CLASE RESERVA
    private:
        int maquina_elegida_; //Maquina elegida por el usuario
        int recursos_; //Recursos elegidos por el usuario
        int confirmacion_op_; //Confirmacion de la operacion
        std::list<Fecha> fecha_; //Lista para fecha
        std::list<Maquina> maquinas_; //Lista para maquinas

    public:
        inline Reserva(){};//Constructor
        void mostrarMenuReserva(); //Muestra el menu por pantalla
        void setMaquinas();//Genera el maquinas.txt
        inline std::list<Maquina> getMaquinas(){return maquinas_;}//Devuelve la lista maquina
        /*void modificaMaquinas(int maquina_ele, int numero_maq, int recur_totales, int recur_disp);*/ //NO DUNCIONA
        void mostrarMaquinas(); //Mostrar las maquinas junto con los recursos que se encuentran disponibles
        bool setElegirMaquina(int &maquina); //Booleano que se encarga de elegir un valor real dentro de la maquina, si se encuentra fuera del valor sale de la aplicacion
        inline int getElegirMaquina(){return maquina_elegida_;} //Retorna el valor de la maquina elegida
        bool setElegirRecursos(int &recursos); //Booleano que se encarga de elegir un valor real en los recursos disponibles, siempre que se encuentren disponibles, si se encuentra fuera del rango sale de la aplicacion
        inline int getElegirRecursos(){return recursos_;}//Retorna el valor de los recursos elegidos
        bool setConfirmacion(int confirmacion_op);//Si se obtiene el valor 1 se guardan los datos y se confirma la operacion
        inline int getConfirmacion(){return confirmacion_op_;};//Retorna el valor de la operacion
        void setFecha();//Se crea el fichero fechas.txt
        inline std::list<Fecha> getFecha(){return fecha_;};//Retorna el fichero fecha_
        void modificaFechasOcupadas(int fecha_maq, std::string fecha_inicio, std::string hora_inicio, std::string fecha_final, std::string hora_final);//Modifica fechas.txt colocando el valor correspondiente de la reserva que se acaba de introducir 
        void mostrarFechasOcupadas(); //Muestra el valor de las fechas ocupadas sin mostrar los usuarios que han realizado las reservas

};
#endif
