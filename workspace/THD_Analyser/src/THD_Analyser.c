/*
===============================================================================
 Name        : THD_Analyser.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/


#include <cr_section_macros.h>
#include "funciones.h"

#include "chip.h"
#include "board_funcs.h"
#include "string.h"


int main(void)
{
	// Read clock settings and update SystemCoreClock variable
	SystemCoreClockUpdate();

	// Inicializaciones
	Board_Init();

	main_init();

	// Loop principal
    while(1)
    {
    	main_loop();
    }

	// Desinicializaciones
	main_uninit();

    return 0;
}
