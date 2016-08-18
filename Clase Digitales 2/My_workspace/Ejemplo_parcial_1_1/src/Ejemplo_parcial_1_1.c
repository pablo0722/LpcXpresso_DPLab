/*
===============================================================================
 Name        : Ex_UartRB_FreeRtosv3.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/
/* FreeRTOS.org includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "board.h"
#include "chip.h"
#include "semphr.h"
#include <cr_section_macros.h>


#define LPC_UARTx LPC_UART0
#define UARTx_IRQn UART0_IRQn
#define UARTx_IRQHandler UART0_IRQHandler
#define PORT_MAX_DELAY 100


uint8_t rxBuff[8], idx_rxBuff = 0, digito[5];
xSemaphoreHandle xBinSem_rx, xBinSem_tx;


static void HandInit()
{
	SystemCoreClockUpdate();
	Board_Init();
	Board_UART_Init(LPC_UART,115200);
	Chip_UART_IntEnable(LPC_UARTx, (UART_IER_RBRINT | UART_IER_RLSINT));
	NVIC_SetPriority(UARTx_IRQn, 1);
	NVIC_EnableIRQ(UARTx_IRQn);

		//Init GPIO-pin
	//Chip_IOCON_PinMuxSet(LPC_IOCON, PIN_BUZZER, IOCON_MODE_INACT | IOCON_FUNC0);
	//Chip_GPIO_WriteDirBit(LPC_GPIO, PIN_BUZZER, true);
	//Chip_GPIO_SetPinDIROutput(LPC_GPIO, PIN_BUZZER);
}

void UARTx_IRQHandler()
{
	portBASE_TYPE xHigherPriorityTaskWoken = pdFALSE;

	if(Chip_UART_ReadLineStatus(LPC_UART1) & UART_LSR_RDR)
	{
		rxBuff[idx_rxBuff] = Board_UARTGetChar(LPC_UART1);
		idx_rxBuff ++;
		if(rxBuff == 8)
		{
			idx_rxBuff = 0;
			xSemaphoreGiveFromISR(xBinSem_rx, &xHigherPriorityTaskWoken);
		}
	}
	portEND_SWITCHING_ISR(xHigherPriorityTaskWoken);
}

void vTask_UARTxTs(void *pvParameters)
{
	char stringoff[] = "OFF";
	xSemaphoreTake(xBinSem_tx, 0);

	while(1)
	{
		xSemaphoreTake(xBinSem_tx, PORT_MAX_DELAY);
		Board_UARTPutSTR(LPC_UARTx, stringoff);
	}
}

void vTask_Display7seg(void *pvParameters)
{
	portTickType pxPreviousWakeTime = xTaskGetTickCount();
	char N = 0, PesoDigito = 1;

	while(1)
	{
		board_DispCatodo_Set(false);
		board_DispAnodo_Set(digito[N]);
		board_DispCatodo_Set(PesoDigito);
		PesoDigito << 1;
		N++;

		if(PesoDigito == 0x20)
		{
			PesoDigito = 1;
			N = 0;
		}
		vTaskDelayUntil(&pxPreviousWakeTime, (4/portTICK_RATE_MS));	// Entro a la tarea cada 4 milisegundos
	}
}

void vTask_Button(void *pvParameters)
{
	// Leo el boton, si se queda presionado al menos 3 segundos,
	// disparar sirena y liberar el semaforo de Tx

	portTickType pxPreviousWakeTime = xTaskGetTickCount();
	uint8_t contadorTicks20ms = 0;

	while(1)
	{
		if(Button_getStatus(0,0))
		{
			contadorTicks20ms++;
			if(contadorTicks20ms == 150) //Si pasaron 3 segundos, entonces...
			{
				contadorTicks20ms = 0;
				board_Sirena_Set(false);
				xSemaphoreGive(xBinSem_tx);
			}
		}
		else
		{
			contadorTicks20ms = 0;
		}

		vTaskDelayUntil(&pxPreviousWakeTime, (20/portTICK_RATE_MS));	// Entro a la tarea cada 20 milisegundos
	}
}

void vTask_Trama(void *pvParameters)
{
	uint8_t i;
	const uint8_t TABLA_7SEG[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

	xSemaphoreTake(xBinSem_rx, 0);

	while(1)
	{
		xSemaphoreTake(xBinSem_rx, PORT_MAX_DELAY);

		// Si llega la trama, la analiso

		if( (rxBuff[0] == 0) && (rxBuff[7] == 0xFA) )
		{
			for(i=0; i<5; i++)
			{
				digito[i] = TABLA_7SEG[rxBuff[i+1]];
			}
			if(rxBuff[6] == 1)
			{
				Board_Sirena_Set(true);
			}
		}
	}
}

int main()
{
	Hardware_Init();

	prvSetupHardware();

	vSemaphoreCreateBinary(xBinSem_rx);
	vSemaphoreCreateBinary(xBinSem_tx);

	if( (xBinSem_rx != NULL) (xBinSem_tx != NULL) )
	{
		xTaskCreate(vTask_UARTxTs, "UART_TX", configMINIMAL_STACK_SIZE, NULL, 1, (xTaskHandle *) NULL);
		xTaskCreate(vTask_Display7seg, "Display_7Seg", configMINIMAL_STACK_SIZE, NULL, 2, (xTaskHandle *) NULL);
		xTaskCreate(vTask_Button, "Button", configMINIMAL_STACK_SIZE, NULL, 1, (xTaskHandle *) NULL);
		xTaskCreate(vTask_Trama, "Trama", configMINIMAL_STACK_SIZE, NULL, 1, (xTaskHandle *) NULL);

		vTaskStartScheduler();
	}

	return 0;
}

/*-----------------------------------------------------------*/

void vApplicationMallocFailedHook( void )
{
	/* This function will only be called if an API call to create a task, queue
	or semaphore fails because there is too little heap RAM remaining. */
	for( ;; );
}
/*-----------------------------------------------------------*/

void vApplicationStackOverflowHook( xTaskHandle *pxTask, signed char *pcTaskName )
{
	/* This function will only be called if a task overflows its stack.  Note
	that stack overflow checking does slow down the context switch
	implementation. */
	for( ;; );
}
/*-----------------------------------------------------------*/

void vApplicationIdleHook( void )
{
	/* This example does not use the idle hook to perform any processing. */
}
/*-----------------------------------------------------------*/

void vApplicationTickHook( void )
{
	/* This example does not use the tick hook to perform any processing. */
}