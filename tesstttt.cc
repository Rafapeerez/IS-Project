

Reserva();
EXPECT_TRUE(r.setElegirMaquina(5));
EXPECT_FALSE(r.setElegirMaquina(11));
EXPECT_TRUE(r.setElegirRecursos(5, 5));
EXPECT_FALSE(r.setElegirRecursos(7, 5));
EXPECT_TRUE(r.getConfirmacion(1));
EXPECT_TRUE(r.comprobacionHora(12.00));
EXPECT_FALSE(r.comprobacionHora(27.00));
EXPECT_TRUE(r.comprobacionFecha(15/12/2021));
EXPECT_FALSE(r.comprobacionFecha(15/12/1998));
EXPECT_TRUE(r.comprobacionHoraDiaIgual(13.00, 15.00));
EXPECT_FALSE(r.comprobacionHoraDiaIgual(16.00, 14.00));

