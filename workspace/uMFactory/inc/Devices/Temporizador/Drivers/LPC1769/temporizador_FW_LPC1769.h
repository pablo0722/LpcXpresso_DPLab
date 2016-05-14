/*
 * header.h
 *
 *  Created on: 22/08/2014
 *      Author: Usuario
 */

#ifndef TEMPORIZADOR_FW_LPC1769_H_
#define TEMPORIZADOR_FW_LPC1769_H_


#include "Devices/Utiles/Primitivas/Utiles_PR.h"


/**************************************************************************************************/
/******************************************** FUNCIONES *******************************************/
/**************************************************************************************************/


	/*! \fn 		void Systick_start(uint32_t ms)
	 *  \brief 		PLL y Inicia Systick
	 *  \param 		ms 			Intervalo de interrupcion en milisegundos
	 *  \return 	void
	 */
	void Systick_start(uint32_t ms);

	/*! \fn 		void InitSysTick(uint8_t fuente, uint32_t reload_division, uint8_t interrupcion)
	 *  \brief 		Inicia Systick solamente
	 *  \param 		fuente 			ver <enum e_FUENTE>
	 *  \param 		reload_ms		Intervalo de interrupcion en milisegundos
	 *  \param 		interrupcion 	ver <enum e_INTERRUPCION>
	 *  \return 	void
	 */
	void InitSysTick(uint8_t fuente, uint32_t reload_ms, uint8_t interrupcion);

	/*! \fn 		void SetReloadSysTick(uint32_t reload_ms)
	 *  \brief 		Modifica el intervalo de interrupcion y reinicia la cuenta del Systick
	 *  \param 		reload_ms		Intervalo de interrupcion en milisegundos
	 *  \return 	void
	 */
	void SetReloadSysTick(uint32_t reload_ms);

	/*! \fn 		void SetIntSysTick(uint8_t interrupcion)
	 *  \brief 		Habilita/Deshabilita interrupcion del Systick
	 *  \param 		interrupcion 	ver <enum e_INTERRUPCION>
	 *  \return 	void
	 */
	void SetIntSysTick(uint8_t interrupcion);

	/*! \fn 		void CloseSysTick()
	 *  \brief 		Deshabilita Systick
	 *  \return 	void
	 */
	void CloseSysTick();


#endif /* HEADER_H_ */
