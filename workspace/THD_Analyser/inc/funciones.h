/*
 * funciones.h
 *
 *  Created on: 4 de may. de 2016
 *      Author: pablo
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

	#ifndef ARM_MATH_CM3
		#define ARM_MATH_CM3
	#endif


	#include "arm_math.h"
	#include "arm_common_tables.h"


	#define FS			 			44100					// en Hz por segundo
	#define TS			 			((q31_t) 0x0000BE37)	// en segundos, en Q31

		// Flags para la fft
	#define IFFT_FLAG 				0
	#define DO_BIT_REVERSE_FLAG 	1

	#define WINDOW_LENGTH 			2048
	#define FFT_IN_LENGTH 			WINDOW_LENGTH
	#define FFT_OUT_LENGTH 			1024 // FFT_OUT_LENGTH = WINDOW_LENGTH/2

		// si (FFT_OUT_LENGTH != WINDOW_LENGTH/2): error
	#if FFT_OUT_LENGTH != WINDOW_LENGTH/2
		#error FFT_OUT_LENGTH != WINDOW_LENGTH/2
	#endif


	typedef q15_t fft_in[FFT_IN_LENGTH];
	typedef q15_t fft_out[FFT_OUT_LENGTH];


	void seno(q31_t *sin_out, uint16_t length, q31_t frecuencia);
	uint8_t fft(fft_out fftOutput, fft_in fftInput);


#endif /* FUNCIONES_H_ */
