/*
 * funciones.h
 *
 *  Created on: 4 de may. de 2016
 *      Author: pablo
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

	#include "board_funcs.h"

	#ifndef ARM_MATH_CM3
		#define ARM_MATH_CM3
	#endif

	#include "arm_math.h"
	#include "arm_common_tables.h"


	/********* DEFINES DE LA FFT *********/
		#define WINDOW_LENGTH 	2048
		#define FFT_LENGTH 		1024

		#if FFT_LENGTH != (WINDOW_LENGTH/2)
			#error FFT_LENGTH Debe ser = WINDOW_LENGTH/2
		#endif

		#define IFFT			0
		#define BIT_REVERSE		1
	/********* DEFINES DE LA FFT *********/


		void fft(q31_t Output_q31[FFT_LENGTH], q31_t Input_q31[WINDOW_LENGTH]);



#endif /* FUNCIONES_H_ */
