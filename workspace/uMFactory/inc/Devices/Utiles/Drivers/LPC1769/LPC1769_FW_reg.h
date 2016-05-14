#ifndef LPC1769_FW_REG_H
#define LPC1769_FW_REG_H



	#include "Devices/Utiles/Primitivas/Utiles_PR.h"


	/**************************************************************************************************/
	/***************************************** ENUMS ****************************************/
	/**************************************************************************************************/

	enum e_FUENTE
	{
		FUENTE_STCLK,
		FUENTE_CPUCLK
	};

	enum e_INTERRUPCION
	{
		INTERRUPCION_DESHABILITAR,
		INTERRUPCION_HABILITAR
	};




	/******************************************************************************************************/
	/***************************************** DEFINES Y REGISTROS ****************************************/
	/******************************************************************************************************/


	#define			P0					(uint8_t) 0	//Puerto 0
	#define			P1					(uint8_t) 1	//Puerto 1
	#define			P2					(uint8_t) 2	//Puerto 2
	#define			P3					(uint8_t) 3	//Puerto 3

		//Para SetMask (habilita la mascara en los pines, para poder usar SetPin y GetPin)
	#define			ENABLE_MASK				(uint8_t) 0x00

		//Para SetDir (setea la direccion de un pin)
	#define 		ENTRADA					(uint8_t) 0x00
	#define 		SALIDA					(uint8_t) 0x01

	//#define 		PIN(a)				(a>31) ? (uint8_t) 31 : (uint8_t) a
	//#define		PUERTO(a)			(a>3) ? (uint8_t) 3 : (uint8_t) a

		//Para SetPinSel (setea la funcion de un pin)
	#define 		FUNCION_GPIO			(uint8_t) 0x00
	#define 		FUNCION_1				(uint8_t) 0x01
	#define 		FUNCION_2				(uint8_t) 0x02
	#define 		FUNCION_3				(uint8_t) 0x03

		//Para SetPinModeIn (setea el tipo de entrada de un pin)
	#define 		PULL_UP 				(uint8_t) 0x00
	#define 		AMBOS 					(uint8_t) 0x01
	#define 		NINGUNO 				(uint8_t) 0x02
	#define 		PULL_DOWN 				(uint8_t) 0x03

		//Para SetPinModeOut (setea el tipo de salida de un pin)
	#define 		NORMAL 					(uint8_t) 0x00
	#define 		OPEN_DRAIN 				(uint8_t) 0x01

		//Para GetPin (define si el pin es de estado alto o estado bajo)
	#define 		BAJO 					(uint8_t) 0x00	//Estado bajo
	#define 		ALTO 					(uint8_t) 0x01	//Estado alto

		//Modo de interrupcion: se activa por nivel
	#define 		INT_NIVEL 				(uint8_t) 0x00
		//Modo de interrupcion: se activa por flanco
	#define 		INT_FLANCO 				(uint8_t) 0x01

		//Polaridad de interrupcion: se activa por flanco descendente
	#define 		INT_DESCENDENTE 		(uint8_t) 0x00
		//Polaridad de interrupcion: se activa por flanco ascendente
	#define 		INT_ASCENDENTE 			(uint8_t) 0x01

		//Polaridad de interrupcion: se activa por nivel bajo
	#define 		INT_BAJO 				(uint8_t) 0x00
		//Polaridad de interrupcion: se activa por nivel alto
	#define 		INT_ALTO 				(uint8_t) 0x01

		//Polaridad de interrupcion: se activa por flanco descendente
	#define 		INT_GPIO_DESCENDENTE 		(uint8_t) 0x00
		//Polaridad de interrupcion: se activa por flanco ascendente
	#define 		INT_GPIO_ASCENDENTE 		(uint8_t) 0x02
	//Polaridad de interrupcion: se activa por flanco ascendente
	#define 		INT_GPIO_BIPOLAR 			(uint8_t) 0x01

		//Polaridad de interrupcion: se activa por nivel bajo
	#define 		INT_BAJO 				(uint8_t) 0x00
		//Polaridad de interrupcion: se activa por nivel alto
	#define 		INT_ALTO 				(uint8_t) 0x01



/**************************************************************************************************/
/******************************************* PIN Connect ******************************************/
/**************************************************************************************************/

	//4 funciones para cada puerto
	#define 		PINSEL 				((__RW uint32_t*) 0x4002C000UL)
	//	0(FUNCION_GPIO): GPIO
	//	1(FUNCION_1): Primer funcion alternativa
	//	2(FUNCION_2): Segunda funcion alternativa
	//	3(FUNCION_3): Tercer funcion alternativa
	#define 		PINSEL0 			PINSEL[0]
	#define 		PINSEL1 			PINSEL[1]
	#define 		PINSEL2 			PINSEL[2]
	#define 		PINSEL3 			PINSEL[3]
	#define 		PINSEL4 			PINSEL[4]
	#define 		PINSEL5 			PINSEL[5]	//!< Not used
	#define 		PINSEL6 			PINSEL[6]	//!< Not used
	#define 		PINSEL7 			PINSEL[7]
	#define 		PINSEL8 			PINSEL[8]	//!< Not used
	#define 		PINSEL9 			PINSEL[9]

	//4 opciones para cada puerto(Entrada)
	#define 		PINMODE 			((__RW uint32_t*) 0x4002C040UL)
	//	0(PULL_UP): Pull-Up
	//	1(AMBOS): Si el nivel de señal es alto se activa Pull-Up, si es bajo se activa Pull-Down (evita que este flotante)
	//	2(NINGUNO): Ni Pull-Up ni Pull-Down
	//	3(PULL_DOWN): Pull-Down
	#define 		PINMODE0 			PINMODE[0]
	#define 		PINMODE1 			PINMODE[1]
	#define 		PINMODE2 			PINMODE[2]
	#define 		PINMODE3 			PINMODE[3]
	#define 		PINMODE4 			PINMODE[4]
	#define 		PINMODE5 			PINMODE[5]
	#define 		PINMODE6 			PINMODE[6]
	#define 		PINMODE7 			PINMODE[7]
	#define 		PINMODE8 			PINMODE[8]
	#define 		PINMODE9 			PINMODE[9]

	//2 opciones para cada puerto(Salida)
	#define 		PINMODE_OD 			((__RW uint32_t*) 0x4002C068UL)
	//	0(NORMAL): Normal (no Open-Drain)
	//	1(OPEN_DRAIN): Open-Drain
	#define 		PINMODE_OD0 			PINMODE_OD[0]
	#define		 	PINMODE_OD1 			PINMODE_OD[1]
	#define 		PINMODE_OD2 			PINMODE_OD[2]
	#define 		PINMODE_OD3 			PINMODE_OD[3]
	#define 		PINMODE_OD4 			PINMODE_OD[4]



/**************************************************************************************************/
/******************************* GPIO (General Purpose Input Output) ******************************/
/**************************************************************************************************/

	#define 		GPIO 				((__RW uint32_t*)0x2009C000UL)

	/*	*						*
		*************************
		*		FIODIR			*	0x2009C000
		*************************
		*		RESERVED		*	0x2009C004
		*************************
		*		RESERVED		*	0x2009C008
		*************************
		*		RESERVED		*	0x2009C00C
		*************************
		*		FIOMASK			*	0x2009C010
		*************************
		*		FIOPIN			*	0x2009C014
		*************************
		*		FIOSET			*	0x2009C018
		*************************
		*		FIOCLR			*	0x2009C01C
		*************************
		*						*
		*						*/

	//	0(ENTRADA): Entrada
	//	1(SALIDA): Salida
	#define 		FIO0DIR				GPIO[0]
	#define 		FIO1DIR				GPIO[8]
	#define 		FIO2DIR				GPIO[16]
	#define 		FIO3DIR				GPIO[24]
	#define 		FIO4DIR				GPIO[32]

	//	0(ENABLE_MASK): Enable
	#define 		FIO0MASK			GPIO[4]
	#define 		FIO1MASK			GPIO[12]
	#define 		FIO2MASK			GPIO[20]
	#define			FIO3MASK			GPIO[28]
	#define 		FIO4MASK			GPIO[36]

	//	Lectura/Escritura
	#define 		FIO0PIN				GPIO[5]
	#define 		FIO1PIN				GPIO[13]
	#define 		FIO2PIN				GPIO[21]
	#define 		FIO3PIN				GPIO[29]
	#define 		FIO4PIN				GPIO[37]

	//Escribe un 1
	#define 		FIO0SET				GPIO[6]
	#define 		FIO1SET				GPIO[14]
	#define 		FIO2SET				GPIO[22]
	#define 		FIO3SET				GPIO[30]
	#define 		FIO4SET				GPIO[38]

	//Escribe un 0
	#define 		FIO0CLR				GPIO[7]
	#define 		FIO1CLR				GPIO[15]
	#define 		FIO2CLR				GPIO[23]
	#define 		FIO3CLR				GPIO[31]
	#define 		FIO4CLR				GPIO[39]

	//!< ///////////////////   NVIC   //////////////////////////
	//!< Nested Vectored Interrupt Controller (NVIC)
	//!< 0xE000E100UL : Direccion de inicio de los registros de habilitación (set) de interrupciones en el NVIC:
	#define		ISER		( ( __RW uint32_t  * ) 0xE000E100UL )
	//!< 0xE000E180UL : Direccion de inicio de los registros de deshabilitacion (clear) de interrupciones en el NVIC:
	#define		ICER		( ( __RW uint32_t  * ) 0xE000E180UL )

	//!< Registros ISER:
	#define		ISER0		ISER[0]
	#define		ISER1		ISER[1]

	//!< Registros ICER:
	#define		ICER0		ICER[0]
	#define		ICER1		ICER[1]


	//!< ///////////////////   PCONP   //////////////////////////
	//!<  Power Control for Peripherals register (PCONP - 0x400F C0C4) [pag. 62 user manual LPC1769]
	//!< 0x400FC0C4UL : Direccion de inicio del registro de habilitación de dispositivos:
	#define 	PCONP	(* ( ( __RW uint32_t  * ) 0x400FC0C4UL ))


	//!< ///////////////////   PCLKSEL   //////////////////////////
	//!< Peripheral Clock Selection registers 0 and 1 (PCLKSEL0 -0x400F C1A8 and PCLKSEL1 - 0x400F C1AC) [pag. 56 user manual]
	//!< 0x400FC1A8UL : Direccion de inicio de los registros de seleccion de los CLKs de los dispositivos:
	#define		PCLKSEL		( ( __RW uint32_t * ) 0x400FC1A8UL )

	//!< Registros PCLKSEL
	#define		PCLKSEL0	PCLKSEL[0]
	#define		PCLKSEL1	PCLKSEL[1]

	#define		PCLK_CCLK		0x01	//PCLK=CCLK
	#define		PCLK_CCLK2		0x02	//PCLK=CCLK/2
	#define		PCLK_CCLK4		0x00	//PCLK=CCLK/4
	#define		PCLK_CCLK8		0x03	//PCLK=CCLK/8


#endif
