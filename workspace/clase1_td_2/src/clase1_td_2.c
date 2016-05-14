/*
===============================================================================
 Name        : clase1_td_2.c
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
		#endif
	#endif

	volatile unsigned int i=1;

    while(1)
    {
    	Board_LED_Set(0, true);
    	for(i=0; i<5000000; i++);
		Board_LED_Set(0, false);
    	for(i=0; i<5000000; i++);
    }


    return 0;
}
