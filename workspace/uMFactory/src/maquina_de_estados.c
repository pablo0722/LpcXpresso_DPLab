/*
 * handler.c
 *
 *  Created on: 22/08/2014
 *      Author: Usuario
 */


#include "maquina_de_estados.h"
#include "header.h"


/* Maquinas de estado definidas por entorno grafico mediante uModel
 */
void Maquina_de_estados_leds(enum e_MAQUINA_ESTADO_LEDS *Estado_led);
void Maquina_de_estados_teclado(enum e_MAQUINA_ESTADO_TEC *Estado_teclado);



	///*** MAQUINA DE ESTADOS PRINCIPAL ***///
	/* Maquina de estados, "invisible" al usuario, que inicializa y controla
	 * las otras maquinas de estado y las vincula entre si.
	 */
void Maquina_de_estados()
{
	// Variables estaticas del estado de las máquinas de estado en paralelo.
	static enum e_MAQUINA_ESTADO Estado = MAQUINA_ESTADO_RESET;	// Estado de maquina de estado principal
	static enum e_MAQUINA_ESTADO_LEDS Estado_led = MAQUINA_ESTADO_LEDS_OFF; // Estado de maquina de estado de leds
	static enum e_MAQUINA_ESTADO_TEC Estado_teclado = MAQUINA_ESTADO_TEC_KEY4_SUELTA; // Estado de maquina de estado de teclado


	// Mientras no esté el estado en Reset o en un estado inexistente de la máquina de estados principal,
	// Corre otras máquinas de estados "en paralelo" independientemente del estado de la maquina de estados principal.
	if(Estado > MAQUINA_ESTADO_RESET && Estado < E_MAX_MAQUINA_ESTADO)
	{
		// Lama a las otras maquinas de estado pasandole su estado como argumento
		Maquina_de_estados_leds(&Estado_led);
		Maquina_de_estados_teclado(&Estado_teclado);

		// Otras máquinas de estado que se requieran correr en "paralelo"
	}

	// Vinculacion de las maquinas de estado entre si
	switch(Estado)
	{
		case MAQUINA_ESTADO_RESET:
		{
			Estado = MAQUINA_ESTADO_1;
		  break;
		}

		case MAQUINA_ESTADO_1:
		{
				// Vinculo ambas maquinas de estado
			if(Estado_teclado==MAQUINA_ESTADO_TEC_KEY4_SUELTA)
			{
				Estado_led = MAQUINA_ESTADO_LEDS_OFF;
			}
			else if(Estado_teclado==MAQUINA_ESTADO_TEC_KEY4_APRIETA)
			{
				Estado_led = MAQUINA_ESTADO_LEDS_CHANGE;
			}
		  break;
		}

		default:
		{
			Estado = MAQUINA_ESTADO_RESET;
		  break;
		}
	}
}




	///*** MAQUINAS DE ESTADOS SECUNDARIAS (corren en paralelo) ***///

void Maquina_de_estados_leds(enum e_MAQUINA_ESTADO_LEDS *Estado_led)
{
	switch((* Estado_led))
	{
		case MAQUINA_ESTADO_LEDS_OFF:
		{
			(* Estado_led) = MAQUINA_ESTADO_LEDS_NONE;

				// Apaga todos los leds
			led_accion(LED_1, ESTADO_LED_OFF, 0, OPCION_TIMER_UNICO);
			led_accion(LED_2, ESTADO_LED_OFF, 0, OPCION_TIMER_UNICO);
			led_accion(LED_3, ESTADO_LED_OFF, 0, OPCION_TIMER_UNICO);
			led_accion(LED_4, ESTADO_LED_OFF, 0, OPCION_TIMER_UNICO);
			led_accion(LED_STICK, ESTADO_LED_OFF, 0, OPCION_TIMER_UNICO);
			led_accion(RGB_R, ESTADO_LED_OFF, 0, OPCION_TIMER_UNICO);
			led_accion(RGB_G, ESTADO_LED_OFF, 0, OPCION_TIMER_UNICO);
			led_accion(RGB_B, ESTADO_LED_OFF, 0, OPCION_TIMER_UNICO);

		  break;
		}

		case MAQUINA_ESTADO_LEDS_NONE:
		{

		  break;
		}

		case MAQUINA_ESTADO_LEDS_CHANGE:
		{
			(* Estado_led) = MAQUINA_ESTADO_LEDS_NONE;

			led_accion(LED_1, ESTADO_LED_CHANGE, 20, OPCION_TIMER_CONTINUO);	// Cada 1 segundo (20 * Tick * TIEMPO_LEDs = 20 * 10ms * 5 = 1000ms)
			led_accion(LED_2, ESTADO_LED_CHANGE, 40, OPCION_TIMER_CONTINUO);	// Cada 2 segundos (40 * 10ms * 5)
			led_accion(LED_3, ESTADO_LED_CHANGE, 80, OPCION_TIMER_CONTINUO);	// Cada 4 segundos (80 * 10ms * 5)
			led_accion(LED_4, ESTADO_LED_CHANGE, 160, OPCION_TIMER_CONTINUO);	// Cada 8 segundos (160 * 10ms * 5)
			led_accion(LED_STICK, ESTADO_LED_CHANGE, 30, OPCION_TIMER_CONTINUO);// Cada 1,5 segundos (30 * 10ms * 5)
			led_accion(RGB_R, ESTADO_LED_CHANGE, 60, OPCION_TIMER_CONTINUO);	// Cada 3 segundos (60 * 10ms * 5)
			led_accion(RGB_G, ESTADO_LED_CHANGE, 120, OPCION_TIMER_CONTINUO);	// Cada 6 segundos (120 * 10ms * 5)
			led_accion(RGB_B, ESTADO_LED_CHANGE, 180, OPCION_TIMER_CONTINUO);	// Cada 9 segundos (180 * 10ms * 5)

		  break;
		}

		default:
		{
			(* Estado_led) = MAQUINA_ESTADO_LEDS_OFF;
		  break;
		}
	}
}



void Maquina_de_estados_teclado(enum e_MAQUINA_ESTADO_TEC *Estado_teclado)
{
switch((* Estado_teclado))
{
	case MAQUINA_ESTADO_TEC_KEY4_SUELTA:
	{
		(* Estado_teclado) = MAQUINA_ESTADO_TEC_KEY4_SOLTADO;

	  break;
	}

	case MAQUINA_ESTADO_TEC_KEY4_SOLTADO:
	{
		if(!teclado_get(KEY0))	// Devuelve: 0=activado, 1=desactivado, 2=no existe
		{
			led_accion(LED_1, ESTADO_LED_ON, 0, OPCION_TIMER_UNICO);
		}
		else
		{
			led_accion(LED_1, ESTADO_LED_OFF, 0, OPCION_TIMER_UNICO);
		}

		if(!teclado_get(KEY1))
		{
			led_accion(LED_2, ESTADO_LED_ON, 0, OPCION_TIMER_UNICO);
		}
		else
		{
			led_accion(LED_2, ESTADO_LED_OFF, 0, OPCION_TIMER_UNICO);
		}

		if(!teclado_get(KEY2))
		{
			led_accion(LED_3, ESTADO_LED_ON, 0, OPCION_TIMER_UNICO);
		}
		else
		{
			led_accion(LED_3, ESTADO_LED_OFF, 0, OPCION_TIMER_UNICO);
		}

		if(!teclado_get(KEY3_RC))
		{
			led_accion(LED_4, ESTADO_LED_ON, 0, OPCION_TIMER_UNICO);
		}
		else
		{
			led_accion(LED_4, ESTADO_LED_OFF, 0, OPCION_TIMER_UNICO);
		}


		if(!teclado_get(KEY4_RC))
		{
			(* Estado_teclado) = MAQUINA_ESTADO_TEC_KEY4_APRIETA;
		}

	  break;
	}

	case MAQUINA_ESTADO_TEC_KEY4_APRIETA:
	{
		(* Estado_teclado) = MAQUINA_ESTADO_TEC_KEY4_APRETADO;

		if(teclado_get(KEY4_RC))
		{
			(* Estado_teclado) = MAQUINA_ESTADO_TEC_KEY4_SUELTA;
		}

	  break;
	}

	case MAQUINA_ESTADO_TEC_KEY4_APRETADO:
	{
		if(teclado_get(KEY4_RC))
		{
			(* Estado_teclado) = MAQUINA_ESTADO_TEC_KEY4_SUELTA;
		}

	  break;
	}

	default:
	{
		(* Estado_teclado) = MAQUINA_ESTADO_TEC_KEY4_SUELTA;
	  break;
	}
}
}
