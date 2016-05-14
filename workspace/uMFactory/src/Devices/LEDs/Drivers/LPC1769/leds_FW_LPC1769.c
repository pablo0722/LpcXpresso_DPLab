/*
 * leds_FW_LPC1769_func.c
 *
 *  Created on: 11/09/2014
 *      Author: Usuario
 */



#include "Startup.h"

#ifdef MICRO_LPC1769

	#include "Devices/Utiles/Drivers/LPC1769/LPC1769_FW_reg.h"
	#include "Devices/LEDs/Drivers/LPC1769/leds_FW_LPC1769_reg.h"


		// Aca se pueden agregar o modificar Leds
	const uint8_t LED_PUERTO[MAX_LEDS] = {0, 2, 0, 0, 0, 2, 2, 2};
	const uint8_t LED_PIN[MAX_LEDS] = {22, 0, 21, 23, 27, 2, 3, 1};


	uint8_t buscar_pin(uint8_t led, uint8_t *puerto, uint8_t *pin)
	{
		if(led >= MAX_LEDS) return 0;

		(*puerto) = LED_PUERTO[led];
		(*pin ) = LED_PIN[led];

		return 1;
	}

	void fw_init_buzzer()
	{
		SetPinSel(INFO_BUZZER, FUNCION_GPIO);
		SetPinDir(INFO_BUZZER, SALIDA);
		SetPin(INFO_BUZZER, INFO_BUZZ_ON);
	}

	void fw_init_led(uint8_t led)
	{
		uint8_t puerto;
		uint8_t pin;

		if(!buscar_pin(led, &puerto, &pin))
			return;

		SetPinSel(puerto, pin, FUNCION_GPIO);
		SetPinDir(puerto, pin, SALIDA);
		SetPin(puerto, pin, INFO_LED_OFF);
	}

	void fw_init_leds()
	{
		uint8_t i;

		for(i=0; i<MAX_LEDS; i++)
		{
			fw_init_led(i);
		}
	}

	void fw_led_on(uint8_t led)
	{
		uint8_t puerto = 0;
		uint8_t pin = 0;

		if(!buscar_pin(led, &puerto, &pin))
			return;

		SetPin(puerto, pin, INFO_LED_ON);
	}

	void fw_led_off(uint8_t led)
	{
		uint8_t puerto = 0;
		uint8_t pin = 0;

		if(!buscar_pin(led, &puerto, &pin))
			return;

		SetPin(puerto, pin, INFO_LED_OFF);
	}

#endif
