/*
===============================================================================
 Name        : clase1_td_2.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/


#include "freeRTOS.h"
#include "Task.h"
#include "board.h"
#include "chip.h"
#include "semphr.h"


#include <cr_section_macros.h>


uint8_t rxBuff[8], idx_rxbuff = 0;

semaphoreHandle xBinSem_rx;
semaphoreHandle xBinSem_tx;

int main(void)
{
	// Read clock settings and update SystemCoreClock variable
	SystemCoreClockUpdate();
	// Set up and initialize all required blocks and
	// functions related to the board hardware
	Board_Init();



    while(1)
    {
    }


    return 0;
}
