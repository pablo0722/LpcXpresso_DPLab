/*
 * 7Seg_PR.h
 *
 *  Created on: 11/03/2015
 *      Author: Pablo
 */

#ifndef SEG7_PR_H_
#define SEG7_PR_H_


#include "Devices/Utiles/Primitivas/Utiles_PR.h"



	// Cada cuanto se llama al Timer_Led() dentro de la interrupcion del temporizador:
#define 	TIEMPO_7SEG				5		// Se llama cada X veces que entra a la interrupcion del temporizador



/*! \fn 		void init_7Segmentos()
 *  \brief 		Initializa puertos para utilizar display 7-segmentos
 *  \return 	void
 */
void Disp_7seg_init();


/*! \fn 		void set_7Segmentos(uint32_t val, uint8_t dp_idx)
 *  \brief 		Setea un número para mostrar en el Display 7-Segmentos
 *  \param 		val 	numero a mostrar
 *  \param 		dp_idx 	posición en donde poner el punto decimal, 0 <= dp_idx < MAX_DISP7S. si dp_idx >= MAX_DISP7S, no muestra punto decimal
 *  \return 	void
 */
void set_7Segmentos(uint32_t val, uint8_t dp_idx);


// Barrido Display
void interrupt_7Segmentos();



#endif /* 7SEG_PR_H_ */
