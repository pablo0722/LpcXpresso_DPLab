/*
 * uninit_funcs.c
 *
 *  Created on: 7 de jun. de 2016
 *      Author: pablo
 */

#include "../mis_inc/board_funcs.h"


void UART_uninit()
{
	/* DeInitialize UART0 peripheral */
	NVIC_DisableIRQ(UART0_IRQn);
	Chip_UART_DeInit(LPC_UART0);
}
