/*
 * funciones.c
 *
 *  Created on: 4 de may. de 2016
 *      Author: pablo
 */

#include "../mis_inc/board_funcs.h"


void loopback_UART0()
{
	/* Poll the receive ring buffer */
	uint8_t key = 0;
	int bytes = Chip_UART_ReadRB(LPC_UART0, &rxring, &key, 1);
	if (bytes > 0)
	{
		/* Wrap value back around */
		if (Chip_UART_SendRB(LPC_UART0, &txring, (const uint8_t *) &key, 1) != 1)
		{
			Board_LED_Toggle(0);/* Toggle LED if the TX FIFO is full */
		}
	}
}

char buffer_32bits_UART0(uint32_t *buffer, int length, char init)
{
	static uint32_t i = 0;
	const uint8_t cant_bytes = 4;
	int bytes_leidos;

	if(init) i = 0;

	uint8_t key = 0;
	bytes_leidos = Chip_UART_ReadRB(LPC_UART0, &rxring, &key, 1);
	if (bytes_leidos > 0)
	{
		buffer[i/cant_bytes] &= ~(0xFF<<((i%cant_bytes)*8) );
		buffer[i/cant_bytes] |= (key<<((i%cant_bytes)*8) );
		i++;
		if(i == length*cant_bytes)
		{
			i = 0;
			return 1;
		}
	}

	return 0;
}

/* Sets the state of a board LED to on or off */
void Board_LED_Set(uint8_t LEDNumber, bool On)
{
	/* There is only one LED */
	if (LEDNumber == 0) {
		Chip_GPIO_WritePortBit(LPC_GPIO, LED0, On);
	}
}

/* Returns the current state of a board LED */
bool Board_LED_Test(uint8_t LEDNumber)
{
	bool state = false;

	if (LEDNumber == 0) {
		state = Chip_GPIO_ReadPortBit(LPC_GPIO, LED0);
	}

	return state;
}

void Board_LED_Toggle(uint8_t LEDNumber)
{
	if (LEDNumber == 0) {
		Board_LED_Set(LEDNumber, !Board_LED_Test(LEDNumber));
	}
}
