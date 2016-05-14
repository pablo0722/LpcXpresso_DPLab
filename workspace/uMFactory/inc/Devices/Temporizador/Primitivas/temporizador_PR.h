/*
 * systick_PR_header.h
 *
 *  Created on: 24/08/2014
 *      Author: Usuario
 */

#ifndef TEMPORIZADOR_PR_H
#define TEMPORIZADOR_PR_H



	#include "Devices/Utiles/Primitivas/Utiles_PR.h"



	/*! \fn 		void Temporizador_start(uint32_t ms)
	 *  \brief 		Inicia el PLL y luego el Temporizador
	 *  \param 		ms 	Interrumpe cada <ms> milisegundos
	 *  \return 	void
	 */
	void Temporizador_start(uint32_t ms);
	

	/*! \fn 		void Interrupt_Temporizador()
	 *  \brief 		Funcion interrupcion del temporizador.
	 *  			Atiende los distintos periféricos cada
	 *  			un cierto tiempo preestablecido
	 *  \return 	void
	 */
	void Interrupt_Temporizador();



#endif /* SYSTICK_PR_HEADER_H_ */
