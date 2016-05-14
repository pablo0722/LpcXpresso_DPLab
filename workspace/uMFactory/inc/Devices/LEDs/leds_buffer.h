/*
 * leds_buffer.h
 *
 *  Created on: 10/10/2014
 *      Author: Usuario
 */

#ifndef LEDS_BUFFER_H_
#define LEDS_BUFFER_H_


#include "Devices/Utiles/Primitivas/Utiles_PR.h"



enum e_ESTADO_LED
{
	ESTADO_LED_NONE,	// Mantiene el estado anterior del led
	ESTADO_LED_ON,		// Prende el led
	ESTADO_LED_OFF,		// Apaga el led
	ESTADO_LED_TOGGLE	// Cambia el estado del led
};


	//Buffer que guarda el estado actual de cada led
extern __RW enum e_ESTADO_LED B_estado_led[MAX_LEDS];

	//Buffer que guarda la acción que se quiere aplicar a cada led
extern __RW enum e_ESTADO_LED B_accion_led[MAX_LEDS+1];	// En la ultima posicion guardo un '1' si hubo cambios

	// Cuenta tiempo antes de aplicar un cambio de estado
extern __RW uint16_t B_temp_led[MAX_LEDS];

	// Tiempo final del contador (se usa para recargar el valor de B_temp_led[])
extern __RW uint16_t B_temp_led_fin[MAX_LEDS];

	// Define opcion de tiempo (continuo, disparo unico, etc.)
extern __RW enum e_OPCION_TIMER B_temp_led_opcion[MAX_LEDS];

#endif /* LEDS_BUFFER_H_ */