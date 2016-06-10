/*
 * IRQ_funcs.c
 *
 *  Created on: 7 de jun. de 2016
 *      Author: pablo
 */


#include "board_funcs.h"


void UART0_IRQHandler(void)
{
	// Lee y escribe la UART0 usando los buffers anillo
	Chip_UART_IRQRBHandler(LPC_UART0, &rxring, &txring);
}
