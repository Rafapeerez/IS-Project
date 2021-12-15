// dados_unittest.cc: Juan A. Romero
// A sample program demonstrating using Google C++ testing framework.
//


// This sample shows how to write a more complex unit test for a class
// that has multiple member functions.
//
// Usually, it's a good idea to have one test for each method in your
// class.  You don't have to do that exactly, but it helps to keep
// your tests organized.  You may also throw in additional tests as
// needed.

#include "reserva.h"
#include "reserva.cc"
#include <stdio.h>
#include "usuario.h"
#include "usuario.cc"
#include "recursos.h"
#include "recursos.cc"
#include "maquinas.h"
#include "maquinas.cc"

bool compruebaReserva(){
  Reserva r;
  if(r.setElegirRecursos(5, 5)==true){
    return true;
  }
}