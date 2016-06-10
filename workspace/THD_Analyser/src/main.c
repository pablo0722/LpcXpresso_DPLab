/*
 * main.c
 *
 *  Created on: 7 de jun. de 2016
 *      Author: pablo
 */

#include "funciones.h"


void Board_Init(void)
{
	/* Inicializa GPIO */
	Board_GPIO_Init();

	/* Inicializa LEDs */
	Board_LED_Init();

	/* Inicializa UART */
	Board_UART_Init();
}

void main_init()
{
	char Uart_init_msg[] = "\r\nHola mundo:\r\n";

	/* Envia mensaje inicial por UART*/
	Chip_UART_SendRB(LPC_UART0, &txring, Uart_init_msg, sizeof(Uart_init_msg) - 1);
}

void main_loop()
{
	loopback_UART0(); // Hace loopback de la UART0
}

void main_uninit()
{
	UART_uninit();
}
