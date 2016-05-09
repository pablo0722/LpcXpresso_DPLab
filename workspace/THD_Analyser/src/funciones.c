/*
 * funciones.c
 *
 *  Created on: 4 de may. de 2016
 *      Author: pablo
 */

#include "funciones.h"



/* Reference index at which max energy of bin ocuurs */
uint32_t testIndex = 0;


void seno(q31_t *sin_out, uint16_t length, q31_t frecuencia)
{
	uint32_t t;
	q31_t angulo;

	for(t=0; t<length; t++)
	{
		if(t == 1030)
		{
			t = 1030;
		}
		if(t == 1040)
		{
			t = 1040;
		}
		angulo = frecuencia*((q31_t) t)*TS;
		// input de 0 a 0.9999 para punto fijo y de 0 a 2Pi para f32
		sin_out[t]=arm_sin_q31(angulo);
	}
}


uint8_t fft(fft_out fftOutput, fft_in fftInput)
{
	arm_status status;
    arm_cfft_radix4_instance_q15 S = {FFT_OUT_LENGTH, IFFT_FLAG, DO_BIT_REVERSE_FLAG};
    q15_t maxValue;

    status = ARM_MATH_SUCCESS;

    /* Initialize the CFFT/CIFFT module */
    status = arm_cfft_radix4_init_q15(&S, FFT_OUT_LENGTH, IFFT_FLAG, DO_BIT_REVERSE_FLAG);

    if(status != ARM_MATH_SUCCESS)
    {
    	return -1; // Error: largo no permitido
    }

    /* Process the data through the CFFT/CIFFT module */
    arm_cfft_radix4_q15(&S, fftInput);


    /* Process the data through the Complex Magnitude Module for
    calculating the magnitude at each bin */
    arm_cmplx_mag_q15(fftInput, fftOutput, FFT_OUT_LENGTH);

    /* Calculates maxValue and returns corresponding BIN value */
    arm_max_q15(fftOutput, FFT_OUT_LENGTH, &maxValue, &testIndex);

    return 0;
}
