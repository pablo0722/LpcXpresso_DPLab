/*
 * funciones.c
 *
 *  Created on: 22/08/2014
 *      Author: Usuario
 */


#include "header.h"


	void init()
	{
		Temporizador_start(10);
		leds_init();
		teclado_init();
		Disp_7seg_init();
	}
