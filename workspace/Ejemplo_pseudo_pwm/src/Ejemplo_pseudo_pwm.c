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

#define PIN_BUZZER 0, 22

/* Transmit and receive ring buffer sizes */
#define UART_RRB_SIZE 4	/* Receive */


/* Transmit and receive buffers */
static uint8_t rxbuff[UART_RRB_SIZE];


/*****************************************************************************
 * Public types/enumerations/variables
 ****************************************************************************/
xSemaphoreHandle xBinSem_rx;
uint8_t dato_valido=0;
uint16_t frec=1;
uint8_t flag_rx=0;
uint8_t ii=0;
uint32_t matchVal;

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
	/* Enable receive data and line status interrupt */
	Chip_UART_IntEnable(LPC_UART0, (UART_IER_RBRINT | UART_IER_RLSINT));

	/* preemption = 1, sub-priority = 1 */
	NVIC_SetPriority(UART0_IRQn, 1);
	NVIC_EnableIRQ(UART0_IRQn);

	Chip_IOCON_PinMuxSet(LPC_IOCON, PIN_BUZZER, IOCON_MODE_INACT | IOCON_FUNC0);
	Chip_GPIO_WriteDirBit(LPC_GPIO, PIN_BUZZER, true);
	//Chip_GPIO_SetPinDIROutput(LPC_GPIO, PIN_BUZZER);
}

/**
 * @brief	UART 1 interrupt handler using ring buffers
 * @return	Nothing
 */
void UART0_IRQHandler(void)
{
	portBASE_TYPE xHigherPriorityTaskWoken = pdFALSE;
	if(Chip_UART_ReadLineStatus(LPC_UART0) & UART_LSR_RDR)
	{
		xSemaphoreGiveFromISR( xBinSem_rx, &xHigherPriorityTaskWoken );

		rxbuff[ii] = Board_UARTGetChar(LPC_UART0);
		ii++;
		if(ii==4)
		{
			flag_rx=1;
			ii = 0;
		}

	}
	portEND_SWITCHING_ISR( xHigherPriorityTaskWoken );

}

/*-----------------------------------------------------------*/
void TIMER0_IRQHandler(void)
{
	//Verificamos para el Timer 0, cual fué la fuente de interrupción.
	//En este ejemplo, la única habilitada es Match 0.

	if (Chip_TIMER_MatchPending(LPC_TIMER0, 1))
	{
		 Chip_TIMER_ClearMatch(LPC_TIMER0, 1);

		Chip_GPIO_SetPinToggle(LPC_GPIO, PIN_BUZZER);
		//Chip_GPIO_WriteDirBit(LPC_GPIO, PIN_BUZZER, true);
	}
}

/*-----------------------------------------------------------*/
void InitTimer0(uint8_t channel,uint32_t matchVal)
{
	/* Enable timer 1 clock */
		Chip_TIMER_Init(LPC_TIMER0);
	/* Timer setup for match and interrupt at TICKRATE_HZ */
		Chip_TIMER_Reset(LPC_TIMER0); 				//Resets the timer terminal and prescale counts to 0.

		Chip_TIMER_MatchEnableInt(LPC_TIMER0, channel);	//Enables a match interrupt that fires
													//when the terminal count matches the match counter value. Match1
		Chip_TIMER_SetMatch(LPC_TIMER0, channel, matchVal); //Sets a timer match value.

		Chip_TIMER_ResetOnMatchEnable(LPC_TIMER0, channel); //For the specific match counter,
													  //enables reset of the terminal count register when a match occurs
		Chip_TIMER_Enable(LPC_TIMER0);				  //Enables the timer (starts count)

		/* Enable timer interrupt */
		NVIC_ClearPendingIRQ(TIMER0_IRQn);
		NVIC_EnableIRQ(TIMER0_IRQn);
}

/*-----------------------------------------------------------*/
void vTask_validacion( void *pvParameters )
{
	static uint8_t dato_ant;
	 xSemaphoreTake( xBinSem_rx, 0 );

	for( ;; )
	{
		xSemaphoreTake( xBinSem_rx, portMAX_DELAY );

			// Si hay dato en el buffer:
		if (flag_rx)
		{
			flag_rx=0;

			frec &= ~(0xff00);
			frec |= rxbuff[1]<<7;
			frec &= ~(0x00ff);
			frec |= rxbuff[2];

				// Timer rate is system clock rate
			uint32_t timerFreq = Chip_Clock_GetSystemClockRate();
			matchVal=timerFreq / (4*frec);

			InitTimer0(1,matchVal);

			Board_UARTPutSTR(LPC_UART0, "lito\n");
		}
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

		xTaskCreate( vTask_validacion, "Handler_validacion", configMINIMAL_STACK_SIZE, NULL, (tskIDLE_PRIORITY + 1UL),
					(xTaskHandle *) NULL);


		/* Start the scheduler so the created tasks start executing. */
		vTaskStartScheduler();
	}
	Board_UARTPutSTR(LPC_UART0, "bienvenido\n");

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
