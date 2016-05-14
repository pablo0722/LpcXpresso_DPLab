/*
 * systick_PR_header.h
 *
 *  Created on: 24/08/2014
 *      Author: Usuario
 */

#ifndef LEDS_PR_H_
#define LEDS_PR_H_


#include "Devices/Utiles/Primitivas/Utiles_PR.h"
#include "Devices/LEDs/leds_buffer.h"



// Cada cuanto se llama al Timer_Led() dentro de la interrupcion del temporizador:
#define 	TIEMPO_LED				5		// Se llama cada X veces que entra a la interrupcion del temporizador



/*! \fn 		void leds_init()
 *  \brief 		Inicializa los leds
 *  \return 	void
 */
void leds_init();


/*! \fn 		void led_accion(uint8_t led, enum e_ESTADO_LED estado, uint16_t tiempo, enum e_OPCION_TIMER opcion)
 *  \brief 		Aplica una accion (prender, apagar o "togglear") a un led cada cierto tiempo
 *  \param 		led 	numero del led
 *  \param 		accion	accion que se quiere aplicar (ESTADO_LED_NONE, ESTADO_LED_ON, ESTADO_LED_OFF, ESTADO_LED_TOGGLE)
 *  \param 		tiempo	Tiempo de recarga del temporizador
 *  \param 		opcion	Tipo de temporizacion (OPCION_TIMER_UNICO, OPCION_TIMER_CONTINUO)
 *  \return 	void
 */
void led_accion(uint8_t led, enum e_ESTADO_LED accion, uint16_t tiempo, enum e_OPCION_TIMER opcion);


/*! \fn 		void interrupt_led()
 *  \brief 		Funcion de interrupcion de los leds llamada por la interrupcion del systick
 *  \return 	void
 */
void interrupt_led();



#endif /* SYSTICK_PR_HEADER_H_ */