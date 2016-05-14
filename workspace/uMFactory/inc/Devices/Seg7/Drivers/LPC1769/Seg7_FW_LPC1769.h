/*
 * 7Seg_FW_LPC1769.h
 *
 *  Created on: 11/03/2015
 *      Author: Pablo
 */

#ifndef SEG7_FW_LPC1769_H_
#define SEG7_FW_LPC1769_H_


#include "Devices/Utiles/Primitivas/Utiles_PR.h"


	// Buffer estado displays 7segmentos
__RW uint8_t B_valor_Seg7[MAX_DISP7S];


#define 	DRIVER_7SEG				1		// 0: El display no tiene driver (Espansion 2)
											// 1: El display tiene driver (Expansion 3)


/*! \fn 		void Disp7Seg_init()
 *  \brief 		Inicializa los puertos usados para los displays 7-segmentos
 *  \param 		void
 */
void fw_Disp7Seg_init();


/*! \fn 		void fw_set_7Segmentos(uint32_t val, uint8_t dp_idx)
 *  \brief 		Setea un valor numerico para mostrar en el display
 *  \param 		val 		Valor a mostrar
 *  \param 		dp_idx 		Indice del digito en donde se quiere agregar el punto decimal. si es >= MAX_DISP7S, no lo agrega
 *  \param 		void
 */
void fw_set_7Segmentos(uint32_t val, uint8_t dp_idx);


/*! \fn 		void fw_interrupt_7Segmentos()
 *  \brief 		Funcion de interrupcion del display 7 segmentos
 *  \param 		void
 */
void fw_interrupt_7Segmentos();



#endif /* 7SEG_FW_LPC1769_H_ */
