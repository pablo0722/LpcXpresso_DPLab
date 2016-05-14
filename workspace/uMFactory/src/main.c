/*
===============================================================================
 Name        : main.c
 Author      :
 Version     :
 Copyright   : Copyright (C)
 Description : main definition
===============================================================================
*/

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif



/**********			INCLUDES			**********/
	#include 	"header.h"
	#include 	"maquina_de_estados.h"


/**********			MAIN			**********/


	int main(void)
	{
		init();

		while(1)
		{
			Maquina_de_estados();
		}

		return 0;
	}
