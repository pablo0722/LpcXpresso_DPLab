/*
 * init_funcs.c
 *
 *  Created on: 7 de jun. de 2016
 *      Author: pablo
 */

#include "../mis_inc/board_funcs.h"


/* Initializes board LED(s) */
void Board_GPIO_Init()
{
	Chip_GPIO_Init(LPC_GPIO);
	Chip_IOCON_Init(LPC_IOCON);
}

/* Initializes board LED(s) */
void Board_LED_Init()
{
	/* Set the PIO_22 as output */
	Chip_GPIO_WriteDirBit(LPC_GPIO, LED0, true);

	// Set the LED to the state of "Off"
	Board_LED_Set(0, false);	// apaga el led P0.22

	Chip_GPIO_SetPinDIROutput(LPC_GPIO, RGBR);
	Chip_GPIO_SetPinDIROutput(LPC_GPIO, RGBG);
	Chip_GPIO_SetPinDIROutput(LPC_GPIO, RGBB);

	Chip_GPIO_SetPinOutLow(LPC_GPIO, RGBR);
	Chip_GPIO_SetPinOutLow(LPC_GPIO, RGBG);
	Chip_GPIO_SetPinOutLow(LPC_GPIO, RGBB);
}

void Board_UART_Init()
{
	/* buffers "anillo" de transmision y recepcion */
	static uint8_t rxbuff[UART_RRB_SIZE], txbuff[UART_SRB_SIZE];

	InitUART0(); // Inicializa UART (funcion de Info 2)

	/* Inicializa buffers anillo */
	RingBuffer_Init(&rxring, rxbuff, 1, UART_RRB_SIZE);
	RingBuffer_Init(&txring, txbuff, 1, UART_SRB_SIZE);

	/* preemption = 1, sub-priority = 1 */
	NVIC_SetPriority(UART0_IRQn, 1);
	NVIC_EnableIRQ(UART0_IRQn);
}
