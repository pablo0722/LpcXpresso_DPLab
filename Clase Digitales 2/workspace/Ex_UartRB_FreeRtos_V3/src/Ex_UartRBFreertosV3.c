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
#include "queue.h"
#include <cr_section_macros.h>

/*****************************************************************************
 * Private types/enumerations/variables
 ****************************************************************************/
/* Transmit and receive ring buffers */
STATIC RINGBUFF_T  rxring;

/* Transmit and receive ring buffer sizes */

#define UART_RRB_SIZE 32	/* Receive */

/* Transmit and receive buffers */
static uint8_t rxbuff[UART_RRB_SIZE];


/*****************************************************************************
 * Public types/enumerations/variables
 ****************************************************************************/
xSemaphoreHandle xBinSem_rx;

/*****************************************************************************
 * Private functions
 ****************************************************************************/
/*****************************************************************************
 * Public functions
 ****************************************************************************/
static void prvSetupHardware(void)
{

   /* Generic Initialization */
	SystemCoreClockUpdate();
	Board_Init();
	Board_UART_Init(LPC_UART0,115200);
	RingBuffer_Init(&rxring, rxbuff, 1, UART_RRB_SIZE);
	/* Enable receive data and line status interrupt */
	Chip_UART_IntEnable(LPC_UART0, (UART_IER_RBRINT | UART_IER_RLSINT));

	/* preemption = 1, sub-priority = 1 */
	NVIC_SetPriority(UART0_IRQn, 1);
	NVIC_EnableIRQ(UART0_IRQn);
}

/**
 * @brief	UART 1 interrupt handler using ring buffers
 * @return	Nothing
 */
void UART1_IRQHandler(void)
{
	portBASE_TYPE xHigherPriorityTaskWoken = pdFALSE;
	if(Chip_UART_ReadLineStatus(LPC_UART0) & UART_LSR_RDR) {
		xSemaphoreGiveFromISR( xBinSem_rx, &xHigherPriorityTaskWoken );
		Chip_UART_RXIntHandlerRB(LPC_UART0, &rxring);
	}
	portEND_SWITCHING_ISR( xHigherPriorityTaskWoken );

}

/*-----------------------------------------------------------*/
void vTask_UART1Tx( void *pvParameters )
{
	const char inst1[] = "LPC17xx UART example with FreeRtos\r\n";

	uint8_t data=0;
	/* Send initial messages */
	Board_UARTPutSTR(LPC_UART0,inst1);

	 xSemaphoreTake( xBinSem_rx, 0 );

	for( ;; )
	{
		 xSemaphoreTake( xBinSem_rx, portMAX_DELAY );
		 RingBuffer_Pop(&rxring, &data);
		 Board_UARTPutChar(LPC_UART0,data);
		}

}
/*-----------------------------------------------------------*/
int main( void )
{

	prvSetupHardware();
	//vSemaphoreCreateBinary( xBinSem_tx );
	vSemaphoreCreateBinary( xBinSem_rx );
	/* Check the semaphore was created successfully. */

	if( xBinSem_rx != NULL )
	{

		xTaskCreate( vTask_UART1Tx, "Handler_Uart1tx", configMINIMAL_STACK_SIZE, NULL, (tskIDLE_PRIORITY + 1UL),
					(xTaskHandle *) NULL);

		/* Start the scheduler so the created tasks start executing. */
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