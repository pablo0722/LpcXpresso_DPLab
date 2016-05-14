/*
 * main.h
 *
 *  Created on: 22/08/2014
 *      Author: Usuario
 */

#ifndef HEADER_H_
#define HEADER_H_


#include "Startup.h"



/**********			DEFINES			**********/
	#define		PERIF_LEDS
	#define		PERIF_TECLADO
	#define		PERIF_SEG7



/**********			INCLUDES			**********/

	#include 	"Devices/Temporizador/Primitivas/temporizador_PR.h"

	#ifdef PERIF_LEDS
			#include 	"Devices/LEDs/Primitivas/leds_PR.h"
	#endif /* PERIF_LEDS */

	#ifdef PERIF_TECLADO
			#include 	"Devices/Teclado/Primitivas/teclado_PR.h"
	#endif /* PERIF_TECLADO */

	#ifdef PERIF_SEG7
			#include 	"Devices/Seg7/Primitivas/Seg7_PR.h"
	#endif /* PERIF_SEG7 */


/**********			FUNCIONES			**********/
	void init();


#endif /* MAIN_H_ */
