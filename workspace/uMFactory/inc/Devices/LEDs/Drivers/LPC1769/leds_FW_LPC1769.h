/*
 * leds_FW_LPC1769_header.h
 *
 *  Created on: 11/09/2014
 *      Author: Usuario
 */

#ifndef LEDS_FW_LPC1769_H_
#define LEDS_FW_LPC1769_H_


#include "Devices/Utiles/Primitivas/Utiles_PR.h"



/*! \fn 		uint8_t buscar_pin(uint8_t led, uint8_t *puerto, uint8_t *pin)
 *  \brief 		Si existe el led 'led', devuelve el pin y puerto de ese led
 *  \param 		led 	numero de led cuyo pin y puerto se quiere averiguar
 *  \param 		puerto 	puntero donde guarda el puerto del led
 *  \param 		pin 	puntero donde guarda el pin del led
 *  \return 	devuelve 0 si no encontro el led ó 1 si lo encontró
 */
uint8_t buscar_pin(uint8_t led, uint8_t *puerto, uint8_t *pin);


/*! \fn 		void fw_init_buzzer()
 *  \brief 		Inicializa buzzer
 *  \return 	void
 */
void fw_init_buzzer();

/*! \fn 		void fw_init_leds()
 *  \brief 		Inicializa todos los leds
 *  \return 	void
 */
void fw_init_leds();

/*! \fn 		void fw_init_led(uint8_t led)
 *  \brief 		Inicializa el led 'led'
 *  \param 		led		led que se quiere inicializar
 *  \return 	void
 */
void fw_init_led(uint8_t led);


/*! \fn 		void fw_led_on(uint8_t led)
 *  \brief 		Prende un led
 *  \return 	void
 */
void fw_led_on(uint8_t led);

/*! \fn 		void fw_led_off(uint8_t led)
 *  \brief 		Apaga un led
 *  \return 	void
 */
void fw_led_off(uint8_t led);


#endif /* LEDS_FW_LPC1769_HEADER_H_ */
