/*
===============================================================================
 Name        : testfft.c
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
//cosas necesarias para la libreria dsp
#include <board_api.h>
#ifndef ARM_MATH_CM3
#define ARM_MATH_CM3
#endif
#include <arm_math.h>
#include <arm_common_tables.h>
// TODO: insert other include files here

// TODO: insert other definitions and declarations here

/******************************************************************************************/
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

    // TODO: insert code here

    // Force the counter to be placed into memory
    volatile static int i = 0 ;
    // Enter an infinite loop, just incrementing a counter
/****************************************************************************/
   uint32_t a[9]={1,2,3,4,5,6,7,8,9};
   uint32_t max;

   uint32_t media;
   uint32_t posmax;
   uint32_t s[2048];
   float32_t index,t,aux;
   q31_t in,ind;

   ind=0x0000000f;
   arm_q31_to_float(&ind,&aux,1);
   arm_max_q31(&a,9,&max,&posmax);
   max;
   posmax;
   arm_mean_q31(&a,9,&media);
   media;
   for(t=0;t<2048;t++)
   {
	   index=aux*t;
	   arm_float_to_q31(&index,&in,1);
	   in;
	   // input de 0 a 0.9999 para punto fijo y de 0 a 2Pi para f32
	   s[(int)t]=arm_sin_q31(in);

   }
   s;
    while(1)
    {
        i++ ;
    }
    return 0 ;
}
