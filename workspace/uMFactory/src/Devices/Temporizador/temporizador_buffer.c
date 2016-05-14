/*
 * temporizador_buffer.c
 *
 *  Created on: 10/10/2014
 *      Author: Usuario
 */


#include "Devices/Utiles/Primitivas/Utiles_PR.h"


		// Flags de leds para el temporizador
	__RW uint8_t F_temp_leds;		// Flag temporizador de los leds
	__RW uint8_t F_temp_teclado;	// Flag temporizador del teclado
	__RW uint8_t F_temp_7Seg;	// Flag temporizador del 7 segmentos
