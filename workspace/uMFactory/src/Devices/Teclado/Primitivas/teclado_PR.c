/*
 * teclado_PR.c
 *
 *  Created on: 07/03/2015
 *      Author: Pablo
 */



#include "Devices/Teclado/teclado_buffer.h"
#include "Startup.h"

#ifdef MICRO_LPC1769
	#include "Devices/Teclado/Drivers/LPC1769/teclado_FW_LPC1769.h"
#endif /* MICRO_LPC1769 */



#define REBOTE_MAX	5	// Cantidad de veces que analiza el estado de una tecla antes de validarla


void teclado_init()
{
	fw_teclado_init();
}

uint8_t teclado_get(uint8_t key)
{
	if(key >= MAX_KEYS) return 2;

	return !((B_estado_teclado >> key) & 1);
}

void interrupt_teclado()
{
	#if MAX_KEYS < 8
		uint8_t tecla_actual=0, cambios;
	#elif MAX_KEYS < 16
		uint16_t tecla_actual=0, cambios;
	#else
		uint32_t tecla_actual=0, cambios;
	#endif

	uint8_t j;
	static uint8_t Cont_Estado[MAX_KEYS];

	for(j=0; j<MAX_KEYS; j++)
	{
		tecla_actual |= (fw_teclado_get(j) << j);
	}

	cambios = tecla_actual ^ B_estado_teclado;

	if(cambios)
	{
		for(j=0; j<MAX_KEYS; j++)
		{
			if(cambios & (1 << j))
			{
				Cont_Estado[j]++;

				if(Cont_Estado[j] >= REBOTE_MAX)
				{
					Cont_Estado[j] = 0;

					B_estado_teclado ^= (1<<j);
				}
			}
		}
	}
	else
	{
		for(j=0; j<MAX_KEYS; j++)
		{
			Cont_Estado[j] = 0;
		}
	}
}
