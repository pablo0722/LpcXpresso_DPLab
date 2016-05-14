/**
 * systick_PR_func.c
 *
 *  Created on: 24/08/2014
 *      Author: Usuario
 **/


#include "Devices/LEDs/leds_buffer.h"
#include "Startup.h"

#ifdef MICRO_LPC1769
	#include "Devices/LEDs/Drivers/LPC1769/leds_FW_LPC1769.h"
#endif /* MICRO_LPC1769 */


	void leds_init()
	{
		uint8_t led;

		fw_init_buzzer();

		fw_init_leds();

		for(led = 0; led < MAX_LEDS; led++)
		{
			B_estado_led[led] = ESTADO_LED_OFF;	// Amanece apagado
			B_accion_led[led] = ESTADO_LED_NONE;	// No efectua ninguna accion
		}

		B_accion_led[MAX_LEDS] = ESTADO_LED_NONE;	// No efectua ninguna accion
	}

	void led_accion(uint8_t led, enum e_ESTADO_LED accion, uint16_t tiempo, enum e_OPCION_TIMER opcion)
	{
		if(led >= MAX_LEDS)
			return;

		B_accion_led[led] = estado;
		B_accion_led[MAX_LEDS] = 1;		// Aviso que se requiere aplicar una accion
		B_temp_led[led] = B_temp_led_fin[led] = tiempo;
		B_temp_led_opcion[led] = opcion;
	}

	void interrupt_led()
	{
		uint8_t led, aux=0;

		if(B_accion_led[MAX_LEDS] == ESTADO_LED_NONE)
			return;	//No hubo cambios en ningun led

		for(led=0; led<MAX_LEDS; led++)
		{
			if(B_accion_led[led] == ESTADO_LED_NONE)
				continue;

			else if(B_temp_led[led])	// NO se agotó el timer del led
			{
				B_temp_led[led]--;
				aux=1;
				continue;
			}
			else// SI se agotó el timer del led
			{
					// Aplico accion
				if(B_accion_led[led] == ESTADO_LED_ON)
				{
					fw_led_on(led);
				}
				else if(B_accion_led[led] == ESTADO_LED_OFF)
				{
					fw_led_off(led);
				}
				else if(B_accion_led[led] == ESTADO_LED_CHANGE)
				{
					if(B_estado_led[led] == ESTADO_LED_ON)
					{
						fw_led_off(led);
						B_estado_led[led] = ESTADO_LED_OFF;
					}
					else if(B_estado_led[led] == ESTADO_LED_OFF)
					{
						fw_led_on(led);
						B_estado_led[led] = ESTADO_LED_ON;
					}
				}

					// Recargo timer del led
				if(B_temp_led_opcion[led] == OPCION_TIMER_CONTINUO)
				{
					led_accion(led, B_accion_led[led], B_temp_led_fin[led], OPCION_TIMER_CONTINUO);
					B_temp_led[led]--;
					aux=1;
				}
				else if(B_temp_led_opcion[led] == OPCION_TIMER_UNICO)
				{
					B_accion_led[led] = ESTADO_LED_NONE;
				}
			}
		}

		if(!aux) B_accion_led[MAX_LEDS] = ESTADO_LED_NONE;
	}
