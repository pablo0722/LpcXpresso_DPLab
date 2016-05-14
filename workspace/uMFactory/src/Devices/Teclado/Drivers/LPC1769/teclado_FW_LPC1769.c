/*
 * teclado_FW_LPC1769.c
 *
 *  Created on: 07/03/2015
 *      Author: Pablo
 */


#include "Startup.h"


#ifdef MICRO_LPC1769

	#include "Devices/Utiles/Drivers/LPC1769/LPC1769_FW_reg.h"



		// Aca se pueden agregar o modificar Leds
	const uint8_t KEY_PUERTO[MAX_KEYS] = {2, 0, 0, 2, 1};
	const uint8_t KEY_PIN[MAX_KEYS] = {10, 18, 11, 13, 26};



	void fw_teclado_init()
	{
		uint8_t i;

		for(i=0; i<MAX_KEYS; i++)
		{
			SetPinSel(KEY_PUERTO[i], KEY_PIN[i], FUNCION_GPIO);
			SetPinDir(KEY_PUERTO[i], KEY_PIN[i], ENTRADA);
		}
	}

	uint8_t fw_teclado_get(uint8_t key)
	{
		if(key >= MAX_KEYS) return 0;

		return GetPin(KEY_PUERTO[key], KEY_PIN[key], 0);
	}

#endif
