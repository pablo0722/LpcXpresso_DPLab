/*
 * mis_funciones.h
 *
 *  Created on: 14 de may. de 2016
 *      Author: pablo
 */

#ifndef MIS_FUNCIONES_H_
#define MIS_FUNCIONES_H_


#include "RegsLPC1769.h"
#include "KitInfo2_BaseBoard.h"



/************************************************/
/*					BASICS						*/
/************************************************/

    #define		ACTIVO_BAJO		0
    #define		ACTIVO_ALTO		1

		// dirección en FIODIR
	#define 	ENTRADA			0
	#define 	SALIDA			1

		// identificadores de los puertos
	#define 	PORT0			0
	#define 	PORT1			1
	#define 	PORT2			2
	#define 	PORT3			3
	#define 	PORT4			4
	void 		SetPINSEL 	( uint8_t  , uint8_t  ,uint8_t );
	void 		SetPINMODE	( uint8_t  , uint8_t  ,uint8_t );
	void 		SetDIR		( uint8_t  , uint8_t  , uint8_t  );
	void 		SetPIN		( uint8_t  , uint8_t  , uint8_t  );
	uint8_t 	GetPIN		( uint8_t  , uint8_t  , uint8_t );



/************************************************/
/*					UART						*/
/************************************************/

	#define TOPE 16	// largo del buffer de recepcion

	void InitUART0 (void);
	void UART0_IRQHandler (void);



/************************************************/
/*					PLL							*/
/************************************************/

	void InicPLL();



#endif /* MIS_FUNCIONES_H_ */
