#include "usuario.h"
#include "reserva.h"
#include "recursos.h"
#include "maquinas.h"
#include "gtest/gtest.h"

#include <cstdlib>

TEST(Usuario, Correo){ //Comprobamos en este test si el formato del correo es correcto
    Usuario usuario("Pepee"," "," ",0);

    EXPECT_TRUE(usuario.setCorreo("pepe@uco.es"));
    EXPECT_FALSE(usuario.setCorreo("pepe12.es"));

}

TEST(Usuario, Contrasena){ //Comprobamos en este test si el formato de la contrasena es correcto
    Usuario usuario("Pepee"," "," ",0);

    EXPECT_FALSE(usuario.setContrasena("1"));
    EXPECT_FALSE(usuario.setContrasena("12"));
    EXPECT_FALSE(usuario.setContrasena("123"));
    EXPECT_FALSE(usuario.setContrasena("1234"));
    EXPECT_FALSE(usuario.setContrasena("12345"));
    EXPECT_TRUE(usuario.setContrasena("123456"));
    EXPECT_TRUE(usuario.setContrasena("1234567"));
}

TEST(Reserva, fecha){ //Comprobamos en este test si el formato de la hora es correcto
    Reserva r;

    EXPECT_TRUE(r.comprobacionHora("12.00"));
    EXPECT_FALSE(r.comprobacionHora("27.00"));
}

TEST(Reserva, fecha2){ //Comprobamos en este test si el formato de la fecha/hora es correcto
    Reserva r;

    EXPECT_TRUE(r.comprobacionFecha("15/12/2021"));
    EXPECT_TRUE(r.comprobarHoraDiaIgual("15/12/2021", "16.00", "15/12/2021","17.00"));
    EXPECT_FALSE(r.comprobarHoraDiaIgual("15/12/2021", "16.00", "15/12/2021","14.00"));

}

TEST(Recursos, comprobacionrecursos){ //Comprobamos en este test si el rango de los recursos para reservar es correcto
    Recursos a;

    EXPECT_TRUE(a.setcomprueba(7));
    EXPECT_FALSE(a.setcomprueba(9));

}

TEST(Recursos, comprobacionfichero){ //Comprobamos en este test si se abre el fichero
    Recursos a;
    EXPECT_TRUE(a.setFichero());
}

TEST(Maquina, maquinastotales){ //Comprobamos en este test si el numero de maquinas disponibles es correcto
    Maquina m;
    EXPECT_TRUE(m.setnumMaquinas(4));
    EXPECT_FALSE(m.setnumMaquinas(9));
}

TEST(Maquina, maquinasDisponibles){
    Maquina m;
    EXPECT_TRUE( m.setMaquinasDisponibles(3));
}