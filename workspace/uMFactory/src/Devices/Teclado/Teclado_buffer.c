/*
 * Teclado_buffer.c
 *
 *  Created on: 07/03/2015
 *      Author: Pablo
 */


#include "Devices/Utiles/Primitivas/Utiles_PR.h"


		// Buffer estado teclas
	#if MAX_KEYS < 8
		__RW uint8_t B_estado_teclado;
	#elif MAX_KEYS < 16
		__RW uint16_t B_estado_teclado;
	#else
		__RW uint32_t B_estado_teclado;
	#endif
