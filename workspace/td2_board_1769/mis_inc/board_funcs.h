/*
 * funciones.h
 *
 *  Created on: 4 de may. de 2016
 *      Author: pablo
 */

#ifndef BOARD_FUNCS_H_
#define BOARD_FUNCS_H_

	#include "board.h"

	#include "board_leds.h"
	#include "board_uart.h"



	/* Funciones de inicializacion */
		void Board_GPIO_Init();
		void Board_LED_Init();
		void Board_UART_Init();


	/* Funciones de aplicacion*/
		void loopback_UART0();
		char buffer_32bits_UART0(uint32_t *buffer, int length, char init);
		void Board_LED_Set(uint8_t LEDNumber, bool On);
		bool Board_LED_Test(uint8_t LEDNumber);
		void Board_LED_Toggle(uint8_t LEDNumber);


	/* Funciones de desinicializacion */
		void UART_uninit();


#endif /* BOARD_FUNCS_H_ */
