/*
===============================================================================
 Name        : THD_Analyser.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#if defined (__USE_LPCOPEN)
	#if defined(NO_BOARD_LIB)
		#include "chip.h"
	#else
		#include "board.h"
	#endif
#endif


#include <cr_section_macros.h>
#include "funciones.h"


int main(void)
{
	#if defined (__USE_LPCOPEN)
		// Read clock settings and update SystemCoreClock variable
		SystemCoreClockUpdate();
		#if !defined(NO_BOARD_LIB)
			// Set up and initialize all required blocks and
			// functions related to the board hardware
			Board_Init();
			// Set the LED to the state of "On"
			Board_LED_Set(0, true);
		#endif
	#endif

	fft(); //Prueba fft

    while(1)
    {
    }

    return 0;
}
