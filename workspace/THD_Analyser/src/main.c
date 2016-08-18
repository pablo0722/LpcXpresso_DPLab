/*
 * main.c
 *
 *  Created on: 7 de jun. de 2016
 *      Author: pablo
 */

#include "THD_Analyser.h"


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
	q31_t max_value;
	uint32_t max_idx;
	q31_t media_total;
	q31_t media_de_armonicos;
	q31_t THD;

	if(buffer_32bits_UART0((uint32_t *) input_fft, WINDOW_LENGTH, 0)) //Recibo Señal
	{
		fft(output_fft, input_fft); //Calculo FFT y modulo de la misma

		arm_max_q31(output_fft, FFT_LENGTH, &max_value, &max_idx); //Calculo maximo y su indice

			// Calculo la media total: ẍ = sum(x)/n
		arm_mean_q31(output_fft, FFT_LENGTH, &media_total);

			// Le saco la fundamental al espectro
		output_fft[max_idx] -= max_value;

			// Calculo la media de los armonicos: ẍ = sum(x)/n
		arm_mean_q31(output_fft, FFT_LENGTH, &media_de_armonicos);

			// THD = media_de_armonicos/media_total
			// la energia de los armonicos siempre es menor a la energia total entonces THD < 1 SIEMPRE
		THD = media_de_armonicos/media_total;
	}
}

void main_uninit()
{
	UART_uninit();
}
