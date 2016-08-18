/*
 * funciones.c
 *
 *  Created on: 10 de jun. de 2016
 *      Author: pablo
 */


#include "THD_Analyser.h"


void fft(q31_t Output_q31[FFT_LENGTH], q31_t Input_q31[WINDOW_LENGTH])
{
    arm_cfft_radix2_instance_q31 S = {FFT_LENGTH, IFFT, BIT_REVERSE};

    //status = ARM_MATH_SUCCESS;

    /* Initialize the CFFT/CIFFT module */
    //status =
    //arm_cfft_radix2_init_q31(&S, FFT_LENGTH, IFFT, BIT_REVERSE);

    /* Process the data through the CFFT/CIFFT module */
    //arm_cfft_radix2_q31(&S, Output_q31);

    arm_cfft_q31(&S, Input_q31, IFFT, BIT_REVERSE);

    /* Process the data through the Complex Magnitude Module for
    calculating the magnitude at each bin */
    arm_cmplx_mag_q31(Input_q31, Output_q31, FFT_LENGTH);

    /* Calculates maxValue and returns corresponding BIN value */
    //arm_max_q31(Output_q31, FFT_LENGTH, &maxValue, &testIndex);
}
