/*
 * 7Seg_FW_LPC1769.c
 *
 *  Created on: 11/03/2015
 *      Author: Pablo
 */


#include "Startup.h"

#ifdef MICRO_LPC1769

	#include "Devices/Utiles/Primitivas/Utiles_PR.h"
	#include "Devices/Utiles/Drivers/LPC1769/LPC1769_FW_reg.h"
	#include "Devices/Seg7/Drivers/LPC1769/Seg7_FW_LPC1769.h"


		// Aca se pueden agregar/modificar/quitar Digitos del Display 7-Segmentos (Sin Driver, Expansion 2)
		// Digitos del display en el siguiente orden: CLK, RST, DP (Con Driver, Expansion 3)
	const uint8_t Seg7_Digito_PUERTO[MAX_DISP7S] = {2,1,4,1,1,0};
	const uint8_t Seg7_Digito_PIN[MAX_DISP7S] = {7,29,28,23,20,19};

		// Segmentos del display en el siguiente orden: a, b, c, d, e, f, g, dp. (Sin Driver, Expansion 2)
		// Segmentos del display en el siguiente orden: bcdA, bcdB, bcdC, bcdD (Con Driver, Expansion 3)
	const uint8_t Seg7_Segmento_PUERTO[8] = {3,1,1,1,1,3,0,1};
	const uint8_t Seg7_Segmento_PIN[8] = {26,18,21,24,27,25,20,19};


	/*! \fn 		void Set_Disp7Seg_Digito(uint8_t digito, uint8_t estado)
	 *  \brief 		[funcion auxiliar] Prende/Apaga un digito del display
	 *  \param 		digito 	Digito que se quiere setear
	 *  \param 		estado 	0: apaga; 1: prende
	 *  \param 		void
	 */
	void fw_Set_Disp7Seg_Digito(uint8_t digito, uint8_t estado)
	{
		if(digito >= MAX_DISP7S) return;

		SetPin(Seg7_Digito_PUERTO[digito], Seg7_Digito_PIN[digito], estado);
	}


	/*! \fn 		void Set_Disp7Seg_segmento(uint8_t segmento, uint8_t estado)
	 *  \brief 		[funcion auxiliar] Prende/Apaga un segmento del display
	 *  \param 		segmento 	Segmento que se quiere setear
	 *  \param 		estado 		0: apaga; 1: prende
	 *  \param 		void
	 */
	void fw_Set_Disp7Seg_segmento(uint8_t segmento, uint8_t estado)
	{
		if(segmento >= 8) return;

		SetPin(Seg7_Segmento_PUERTO[segmento], Seg7_Segmento_PIN[segmento], estado);
	}


	void fw_Disp7Seg_init()
	{
		uint8_t i;

		for(i=0; i<MAX_DISP7S; i++)
		{
			SetPinSel(Seg7_Digito_PUERTO[i], Seg7_Digito_PIN[i], FUNCION_GPIO);
			SetPinDir(Seg7_Digito_PUERTO[i], Seg7_Digito_PIN[i], SALIDA);
		}
	}

	#if (DRIVER_7SEG == 0)	// Sin Driver (expansion 2)

		uint8_t Tabla_Seg7_Digitos[] = {0x3f, 0x06, 0x5B, 0x4f, 0x66, 0x6D, 0x7C, 0x07, 0x7f, 0x67};

		void fw_set_7Segmentos(uint32_t val, uint8_t dp_idx)
		{
			uint8_t i;

			//* Convierto a 7 Seg.
			for(i = 0 ; i<MAX_DISP7S ; i++ )
			{
				B_valor_Seg7[i] = Tabla_Seg7_Digitos[val%10];

				val /= 10;
			}

			if(dp_idx < MAX_DISP7S)
				B_valor_Seg7[dp_idx] |= 0x80;	// Agrego punto decimal
		}

		void fw_interrupt_7Segmentos()
		{
			uint8_t i;
			static uint8_t	digito = 0;

			for(i=0; i<MAX_DISP7S; i++)
			{
				fw_Set_Disp7Seg_Digito(i, 0);	// Apaga todos los digitos del display
			}

			for(i=0; i<=7; i++)
			{
				fw_Set_Disp7Seg_segmento(i, (( B_valor_Seg7[digito] >> i ) & (uint8_t)0x01));	// Prende/apaga cada segmento de un digito
			}

			fw_Set_Disp7Seg_Digito(digito, 1);	// Prende un solo digito del display

			// Incremento el indice del display
			digito++;
			digito %= MAX_DISP7S;
		}

	#else	// Con Driver (expansion 3)

		void fw_set_7Segmentos(uint32_t val, uint8_t dp_idx)
		{
			uint8_t i;

			//* Convierto a 7 Seg.
			for(i = 0 ; i<MAX_DISP7S ; i++ )
			{
				B_valor_Seg7[i] = val % 10;
				val /= 10;
			}

			if(dp_idx < MAX_DISP7S)
				B_valor_Seg7[dp_idx] += 10;	// Agrego punto decimal
		}

		void fw_interrupt_7Segmentos( void )
		{
			uint8_t aux;
			static uint8_t	digito = 0;

			fw_Set_Disp7Seg_segmento(0, 1);	// Prende bcdA
			fw_Set_Disp7Seg_segmento(1, 1);	// Prende bcdB
			fw_Set_Disp7Seg_segmento(2, 1);	// Prende bcdC
			fw_Set_Disp7Seg_segmento(3, 1);	// Prende bcdD
			fw_Set_Disp7Seg_Digito(2, 0);			// Apaga DP

			if( !digito )
			{
					// Para resetear secuencia de digitos
				fw_Set_Disp7Seg_Digito(1, 1);	// Prende RST
				fw_Set_Disp7Seg_Digito(1, 0);	// Apaga RST
			}
			else
			{
					// Para elegir siguiente digito en la secuencia
				fw_Set_Disp7Seg_Digito(0, 0);	// Apaga CLK
				fw_Set_Disp7Seg_Digito(0, 1);	// Prende CLK
			}

			aux = B_valor_Seg7[digito] ;

			if(aux>=10)
			{
				fw_Set_Disp7Seg_Digito(2, 1);	// Prende DP
				aux -= 10;
			}
			fw_Set_Disp7Seg_segmento(0, (aux >> 0) & 0x01);	// Prende/apaga bcdA
			fw_Set_Disp7Seg_segmento(1, (aux >> 1) & 0x01);	// Prende/apaga bcdB
			fw_Set_Disp7Seg_segmento(2, (aux >> 2) & 0x01);	// Prende/apaga bcdC
			fw_Set_Disp7Seg_segmento(3, (aux >> 3) & 0x01);	// Prende/apaga bcdD

			// Incremento el indice del display
			digito++;
			digito %= MAX_DISP7S;
		}

	#endif

#endif
