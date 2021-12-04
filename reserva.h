//reserva.h
//it define the class reserva
#ifndef _RESERVA_H
#define _RESERVA_H
#include <iostream>
#include <vector>
#include <list>

struct Maquina{
    int numero_maq;
    int recur_totales;
    int recur_disp;
};

struct Fecha{
    int fecha_maquina;
    std::string fecha_inicio;
    std::string hora_inicio;
    std::string fecha_final;
    std::string hora_final;
};

class Reserva{
    private:
        int maquinas_totales_;
        int maquina_elegida_;
        int recursos_;
        int confirmacion_op_;
        std::list<Fecha> fecha_;
        std::list<Maquina> maquinas_;

    public:
        inline Reserva(){maquinas_totales_=8;}
        void setMaquinas();
        inline std::list<Maquina> getMaquinas(){return maquinas_;}
        void mostrarMaquinas();
        bool setElegirMaquina(int &maquina);
        inline int getElegirMaquina(){return maquina_elegida_;}
        bool setElegirRecursos(int &recursos);
        inline int getElegirRecursos(){return recursos_;}
        bool setConfirmacion(int confirmacion_op);
        inline int getConfirmacion(){return confirmacion_op_;};
        void setFecha();
        inline std::list<Fecha> getFecha(){return fecha_;};
        void modificaFechasOcupadas(int fecha_maq, std::string fecha_inicio, std::string hora_inicio, std::string fecha_final, std::string hora_final);
        void mostrarFechasOcupadas();

};
#endif
