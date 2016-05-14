/*
 * teclado_PR.h
 *
 *  Created on: 07/03/2015
 *      Author: Pablo
 */

#ifndef TECLADO_PR_H_
#define TECLADO_PR_H_


void teclado_init();

uint8_t teclado_get(uint8_t key);	// Devuelve: 0=activado, 1=desactivado, 2=no existe


// Cada cuanto se llama al Timer_Led() dentro de la interrupcion del temporizador:
#define 	TIEMPO_TECLADO				1		// Se llama cada X veces que entra a la interrupcion del temporizador


void interrupt_teclado();



#endif /* TECLADO_PR_H_ */
