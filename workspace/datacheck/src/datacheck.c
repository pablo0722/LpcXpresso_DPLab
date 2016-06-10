/*
===============================================================================
 Name        : datacheck.c
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
#include <arm_math.h>

// TODO: insert other include files here

// TODO: insert other definitions and declarations here

int main(void) {

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
    q15_t h;
    q31_t sen[1024];
    // TODO: insert code here
    for(h=0;h<128;h++)
    {
    	sen[h]=arm_sin_q31(h);
    }
    Chip_GPIO_SetPinDIROutput(LPC_GPIO,2,0);
    Chip_GPIO_SetPinDIROutput(LPC_GPIO,2,1);
    Chip_GPIO_SetPinDIROutput(LPC_GPIO,2,2);
    Chip_GPIO_SetPinDIROutput(LPC_GPIO,2,3);
    Chip_GPIO_SetPinDIROutput(LPC_GPIO,2,4);
    Chip_GPIO_SetPinDIROutput(LPC_GPIO,2,5);

    Chip_GPIO_SetPinOutHigh(LPC_GPIO,2,0);
    Chip_GPIO_SetPinOutHigh(LPC_GPIO,2,1);
    Chip_GPIO_SetPinOutHigh(LPC_GPIO,2,2);
    Chip_GPIO_SetPinOutHigh(LPC_GPIO,2,3);
    Chip_GPIO_SetPinOutHigh(LPC_GPIO,2,4);
    Chip_GPIO_SetPinOutHigh(LPC_GPIO,2,5);

    Chip_GPIO_SetPinOutLow(LPC_GPIO,2,0);
    Chip_GPIO_SetPinOutLow(LPC_GPIO,2,1);
    Chip_GPIO_SetPinOutLow(LPC_GPIO,2,2);
    Chip_GPIO_SetPinOutLow(LPC_GPIO,2,3);
    Chip_GPIO_SetPinOutLow(LPC_GPIO,2,4);
    Chip_GPIO_SetPinOutLow(LPC_GPIO,2,5);
    // Force the counter to be placed into memory
    volatile static int i = 0 ;
    // Enter an infinite loop, just incrementing a counter
    while(1) {
        i++ ;
    }
    return 0 ;
}
