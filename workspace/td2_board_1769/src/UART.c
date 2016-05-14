/*
 * UART.c
 *
 *  Created on: 14 de may. de 2016
 *      Author: pablo
 */


#include "board.h"


uint8_t buffer [TOPE];	//buffer de recepción
uint8_t inx_out;		//índice de transmisión
uint8_t inx_in;			//índice de recepción
uint8_t enviando;		//variable auxiliar para disparar Tx


void InitUART0 (void)
{
		// Inicio PLL
	InicPLL();


	//1.- Registro PCONP (0x400FC0C4) - bit 3 en 1 prende la UART:
	PCONP |= 0x01<<3;
	//2.- Registro PCLKSEL0 (0x400FC1A8) - bits 6 y 7 en 0 seleccionan que el clk de la UART0 sea CCLK/4:
	PCLKSEL0 &= ~(0x03<<6);	//con un CCLOK=100Mhz, nos queda PCLOCK=25Mhz
	//3.- Registro U1LCR (0x4001000C) - transmision de 8 bits, 1 bit de stop, sin paridad, sin break cond, DLAB = 1:
	U0LCR = 0x00000083;
	//4.- Registros U1DLL (0x40010000) y U1DLM (0x40010004) - 9600 baudios:
	U0DLM = 0;
	U0DLL = 0xA3;//0xA3 para 9600
	//5.- Registros PINSEL0 (0x4002C000) y PINSEL1 (0x4002C004) - habilitan las funciones especiales de los pines:
	//TX1D : PIN ??	-> 		P0[2]	-> PINSEL0: 04:05
	SetPINSEL(TX0,PINSEL_FUNC1);
	//RX1D : PIN ??	-> 		P0[3]	-> PINSEL1: 06:07
	SetPINSEL(RX0,PINSEL_FUNC1);
	//6.- Registro U1LCR, pongo DLAB en 0:
	U0LCR = 0x03;
	//7. Habilito las interrupciones (En la UART -IER- y en el NVIC -ISER)
	U0IER = 0x03;
	ISER0 |= (1<<5);


	// Inicializo indices de buffers
	inx_out = inx_in = 0;  	//por profiláxis....
	enviando = 0;
}

void UART0_IRQHandler (void)
{
	uint8_t iir, aux;

	do
	{
		//IIR es reset por HW, una vez que lo lei se resetea.
		iir = U0IIR;

		if ( iir & 0x04 ) //Data ready
		{
			buffer[inx_in++] = (uint8_t) U0RBR;   	//guardo en buffer e incremento índice
			inx_in %= TOPE;					//garantizo el buffer circular
			if (!enviando) 		//si no estoy enviando....fuerzo la Tx.
				iir |= 0x02;	//simulando a la fuerza la existencia de b1 de IIR = 1.
		}

		if ( iir & 0x02 ) //THRE
		{
			if (inx_in != inx_out)		//Cada vea que saco un dato, vuelve a interrumpir.
			{//Cuando saque el último...y los índices queden empatados...hay que cortar la Tx
				enviando = 1;	 		//aviso que estoy enviando

					//hago loopback
				U0THR = buffer[inx_out++];
				U0THR = (uint8_t) ' ';	//imprimo un espacio entre cada par de caracteres

				inx_out %= TOPE; 		//garantizo el buffer circular
			}
			else
				enviando = 0;  //aviso que terminé de transmitir.
		}
	}
	while( ! ( iir & 0x01 ) ); /* me fijo si cuando entre a la ISR habia otra
						     	int. pendiente de atencion: b0=1 (ocurre unicamente si dentro del mismo
								espacio temporal lleguan dos interrupciones a la vez) */
}
