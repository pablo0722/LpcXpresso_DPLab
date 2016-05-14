/*
 * teclado_buffer.h
 *
 *  Created on: 07/03/2015
 *      Author: Pablo
 */

#ifndef TECLADO_BUFFER_H_
#define TECLADO_BUFFER_H_


#include "Devices/Utiles/Primitivas/Utiles_PR.h"


		// Buffer estado teclas
	#if MAX_KEYS < 8
		extern __RW uint8_t B_estado_teclado;
	#elif MAX_KEYS < 16
		extern __RW uint16_t B_estado_teclado;
	#else
		extern __RW uint32_t B_estado_teclado;
	#endif


#endif /* TECLADO_BUFFER_H_ */
