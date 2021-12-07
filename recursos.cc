#include "recursos.h"
#include <iostream>
#include <fstream>


	bool Reserva::setcomprueba(int recursosmaquina){
		if(recursosmaquina>0 && recursosmaquina<=8){
			recursosmaquina_=recursosmaquina;
			return true;

		}
		else{
			return false;
		}
	}