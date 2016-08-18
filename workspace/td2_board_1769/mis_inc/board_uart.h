/*
 * board_uart.h
 *
 *  Created on: 7 de jun. de 2016
 *      Author: pablo
 */

#ifndef BOARD_UART_H_
#define BOARD_UART_H_


	/* Tamaños de buffers "anillo" de transmision y recepcion */
	#define UART_SRB_SIZE 2048*4*2	/* transmision */
	#define UART_RRB_SIZE 2048*4*2	/* recepcion */

	extern RINGBUFF_T txring, rxring; //Buffers anillo


#endif /* BOARD_UART_H_ */
