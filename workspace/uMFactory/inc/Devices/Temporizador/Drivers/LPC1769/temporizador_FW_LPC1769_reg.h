/*
 * registros.h
 *
 *  Created on: 22/08/2014
 *      Author: Usuario
 */

#ifndef TEMPORIZADOR_FW_LPC1769_REG_H_
#define TEMPORIZADOR_FW_LPC1769_REG_H_



#include "Devices/Utiles/Primitivas/Utiles_PR.h"

	//!< Tipo de dato específico para manejar el SYSTICK
typedef struct
{
	union
	{
		__RW uint32_t _STCTRL;
		struct{
			__RW uint32_t _ENABLE:1;
			__RW uint32_t _TICKINT:1;
			__RW uint32_t _CLKSOURCE:1;
			__RW uint32_t _RESERVED0:13;
			__RW uint32_t _COUNTFLAG:1;
			__RW uint32_t _RESERVED1:16;
		}bits;
	};
	__RW uint32_t _STRELOAD;
	__RW uint32_t _STCURR;
	__R uint32_t  _STCALIB;
} systick_t;

	//!< 0xE000E010UL: Registro de control del SysTick:
#define 		DIR_SYSTICK		( (systick_t *) 0xE000E010UL )

	//!< Control del SysTick
#define		STCTRL					(*((__RW uint32_t *) 0xE000E010UL ))

		/*!< 0(DESHABILITAR): Deshabilita conteo del SysTick
		 *	 1(HABILITAR): Habilita conteo del SysTick
		 */
	#define		ENABLE					(DIR_SYSTICK->bits._ENABLE)

		/*!< 0(DESHABILITAR): Deshabilita interrupcion del SysTick
		 *	 1(HABILITAR): Habilita interrupcion del SysTick
		 */
	#define		TICKINT					(DIR_SYSTICK->bits._TICKINT)

		/*!< 0(STCLK): Setea el STCLK como la fuente del clock del SysTick
		 *	 1(CPUCLK): Setea el clock del CPU como la fuente del clock del SysTick
		 */
	#define		CLKSOURCE				(DIR_SYSTICK->bits._CLKSOURCE)

		//!< Se pone en "1" cuando el clock del SysTick llega a "0". Se limpia leyendo el bit
	#define		COUNTFLAG				(DIR_SYSTICK->bits._COUNTFLAG)

	//!< Valor que se carga cuando el clock del SysTick llega a "0" (0x0F423F)
#define		STRELOAD				(*((__RW uint32_t *) 0xE000E014UL ))

	//!< Devuelve el valor actual de la cuenta del clock del SysTick
#define		STCURR					(*((__RW uint32_t *) 0xE000E018UL ))

	//!< Contiene el valor que permite generar interrupciones cada 10 ms (a 100Mhz)
#define		STCALIB					(*((__R uint32_t *) 0xE000E01CUL ))






#endif /* REGISTROS_H_ */
