/*
 * leds_PR_handler.c
 *
 *  Created on: 05/10/2014
 *      Author: Usuario
 */


#include "Devices/Temporizador/temporizador_buffer.h"

#include "Startup.h"
#include "header.h"

#ifdef MICRO_LPC1769
	#include "Devices/Temporizador/Drivers/LPC1769/temporizador_FW_LPC1769.h"
#endif // MICRO_LPC1769



void Temporizador_start(uint32_t ms)
{
	Systick_start(ms);
}


void Interrupt_Temporizador()
{
	#ifdef USANDO_LEDS
		F_temp_leds++;

		if( (!(F_temp_leds % TIEMPO_LEDs)) )
		{
			F_temp_leds=0;
			interrupt_led();
		}
	#endif	// USANDO_LEDS

	#ifdef USANDO_TECLADO
		F_temp_teclado++;

		if( (!(F_temp_teclado % TIEMPO_TECLADO)) )
		{
			F_temp_teclado=0;
			interrupt_teclado();
		}
	#endif	// USANDO_TECLADO

	#ifdef USANDO_SEG7
		F_temp_7Seg++;

		if( (!(F_temp_7Seg % TIEMPO_7SEG)) )
		{
			F_temp_7Seg=0;
			interrupt_7Segmentos();
		}
	#endif	// USANDO_SEG7
}
