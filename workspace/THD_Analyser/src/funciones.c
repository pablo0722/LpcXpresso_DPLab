/*
 * funciones.c
 *
 *  Created on: 4 de may. de 2016
 *      Author: pablo
 */

#include "funciones.h"

#define TEST_LENGTH_SAMPLES 2048


/* ------------------------------------------------------------------
* Global variables for FFT Bin Example
* ------------------------------------------------------------------- */
uint16_t fftSize = TEST_LENGTH_SAMPLES/2;
uint8_t ifftFlag = 0;
uint8_t doBitReverse = 1;

/* Reference index at which max energy of bin ocuurs */
uint32_t testIndex = 0;


void fft()
{
	q15_t testInput_f32_10khz[TEST_LENGTH_SAMPLES];
	q15_t testOutput[TEST_LENGTH_SAMPLES/2];

    arm_status status;
    arm_cfft_radix4_instance_f32 S = {fftSize, ifftFlag, doBitReverse};
    q15_t maxValue;
    int i;

    for(i=0; i<TEST_LENGTH_SAMPLES; i++)
    {
    	testInput_f32_10khz[i] = i;
    }

    status = ARM_MATH_SUCCESS;

    /* Initialize the CFFT/CIFFT module */
    status = arm_cfft_radix4_init_f32(&S, fftSize, ifftFlag, doBitReverse);

    /* Process the data through the CFFT/CIFFT module */
    arm_cfft_radix4_q15(&S, testInput_f32_10khz);


    /* Process the data through the Complex Magnitude Module for
    calculating the magnitude at each bin */
    arm_cmplx_mag_q15(testInput_f32_10khz, testOutput, fftSize);

    /* Calculates maxValue and returns corresponding BIN value */
    arm_max_q15(testOutput, fftSize, &maxValue, &testIndex);
}
