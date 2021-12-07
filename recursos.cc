#include "recursos.h"
#include <iostream>
#include <fstream>


	bool Recursos::setcomprueba(int recursosmaquina){
		if(recursosmaquina>0 && recursosmaquina<=8){
			recursosmaquina_=recursosmaquina;
			return true;

		}
		else{
			return false;
		}
	}