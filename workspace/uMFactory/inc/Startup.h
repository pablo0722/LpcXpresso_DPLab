/*
 * Startup.h
 *
 *  Created on: 10/09/2014
 *      Author: Usuario
 */

#ifndef STARTUP_H_
#define STARTUP_H_



	/**********			Micro			**********/
		#define		MICRO_LPC1769
//		#define		MICRO_8051



	/**********			Control de errores			**********/
		#if defined(MICRO_LPC1769) && defined(MICRO_8051)
			#error "Se ha definido más de un microcontrolador simultáneamente"
		#endif




#endif /* MICRO_H_ */
