/*
 * funciones.c
 *
 *  Created on: 22/08/2014
 *      Author: Usuario
 */



#include "Startup.h"

#ifdef MICRO_LPC1769

	#include "Devices/Utiles/Drivers/LPC1769/LPC1769_FW_reg.h"
	#include "Devices/PLL/Drivers/LPC1769/pll_FW_LPC1769.h"
	#include "Devices/Temporizador/Drivers/LPC1769/temporizador_FW_LPC1769_reg.h"
	#include "Devices/Temporizador/Primitivas/temporizador_PR.h"


	void InitSysTick(uint8_t fuente, uint32_t reload_ms, uint8_t interrupcion)
	{
		STRELOAD = ((STCALIB * reload_ms) / 10) - 1;
		STCURR = 0;

		CLKSOURCE = fuente;
		ENABLE = 0x01;	//!< Habilita timer
		TICKINT = interrupcion;
	}

	void Systick_start(uint32_t ms)
	{
		InitPLL();
		InitSysTick(FUENTE_CPUCLK, ms, INTERRUPCION_HABILITAR);	//!< tick cada <ms> milisegundos
	}

	void SetReloadSysTick(uint32_t reload_division)
	{
		STRELOAD = (STCALIB / reload_division) - 1;
		STCURR = 0;
	}

	void SetIntSysTick(uint8_t interrupcion)
	{
		TICKINT = interrupcion;
	}

	void CloseSysTick()
	{
		ENABLE = 0x00;	//!< Deshabilita timer
		STCURR = 0;
	}

	void SysTick_Handler(void)
	{
		Interrupt_Temporizador();
	}

#endif
