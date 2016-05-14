/*
 * leds_buffer.c
 *
 *  Created on: 10/10/2014
 *      Author: Usuario
 */


#include "Devices/LEDs/leds_buffer.h"


__RW enum e_ESTADO_LED B_estado_led[MAX_LEDS];
__RW enum e_ESTADO_LED B_accion_led[MAX_LEDS+1]; // si B_accion_led[MAX_LEDS] es = a 0, entonces no hubo cambio en ningún led

__RW uint16_t B_temp_led[MAX_LEDS];	// Cuenta tiempo antes de aplicar un cambio de estado
__RW uint16_t B_temp_led_fin[MAX_LEDS];	// Tiempo final del contador (se usa para recargar el valor de B_temp_led[])
__RW enum e_OPCION_TIMER B_temp_led_opcion[MAX_LEDS]; // Define opcion de tiempo (continuo, disparo unico, etc.)
