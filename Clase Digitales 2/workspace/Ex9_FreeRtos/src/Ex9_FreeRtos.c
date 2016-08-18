/*
===============================================================================
 Name        : Ex9_FreeRtos.c
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
#include "semphr.h"
#include <cr_section_macros.h>



/*****************************************************************************
 * Private types/enumerations/variables
 ****************************************************************************/
#define TICKRATE_HZ1 (8)	/* 8 ticks per second */
/*****************************************************************************
 * Public types/enumerations/variables
 ****************************************************************************/

#define mainDELAY_LOOP_COUNT		( 0xfffff )
xSemaphoreHandle xBinarySemaphore;

/*****************************************************************************
 * Private functions
 ****************************************************************************/
/* The task functions. */
/* The two task functions. */
void vHandlerTask_Timer0( void *pvParameters );
void vPeriodicTask( void *pvParameters );
void InitTimer0(uint8_t ,uint32_t);


/* Sets up system hardware */

static void prvSetupHardware(void){

	uint32_t timerFreq, matchVal;
	uint8_t channel=1;
/* Generic Initialization */
	SystemCoreClockUpdate();
	Board_Init();

	/* Initial LED0 state is off */
	Board_LED_Set(0, false);

		/* Timer rate is system clock rate */
	timerFreq = Chip_Clock_GetSystemClockRate();
	matchVal=timerFreq / TICKRATE_HZ1;

	InitTimer0(channel,matchVal);
}




/*-----------------------------------------------------------*/

int main( void )
{
	prvSetupHardware();

	 vSemaphoreCreateBinary( xBinarySemaphore );

	/* Check the semaphore was created successfully. */
	if( xBinarySemaphore != NULL )
	{

		xTaskCreate( vHandlerTask_Timer0, "Handler_Timer_0", 240, NULL, 1, NULL );

		xTaskCreate( vPeriodicTask, "Periodic", 240, NULL, 2, NULL );

		/* Start the scheduler so the created tasks start executing. */
		vTaskStartScheduler();
	}

	for( ;; );
	return 0;
}
/*-----------------------------------------------------------*/
void vPeriodicTask( void *pvParameters )
{

portTickType xLastWakeTime;

	xLastWakeTime = xTaskGetTickCount();

	/* As per most tasks, this task is implemented in an infinite loop. */
	for( ;; )
	{

		Board_LED_Toggle(0);
		vTaskDelayUntil( &xLastWakeTime, ( 1000 / portTICK_RATE_MS ) );
	}
}


/*-----------------------------------------------------------*/
void vHandlerTask_Timer0( void *pvParameters )
{

   xSemaphoreTake( xBinarySemaphore, 0 );

   for( ;; )
   {
       /* Use the semaphore to wait for the event.  The task blocks
       indefinitely meaning this function call will only return once the
       semaphore has been successfully obtained - so there is no need to check
       the returned value. */
       xSemaphoreTake( xBinarySemaphore, portMAX_DELAY );

       vPrintString( "Handler Task Timer 0\n" );
   }
}
/*-----------------------------------------------------------*/
void TIMER0_IRQHandler(void)
{
	portBASE_TYPE xHigherPriorityTaskWoken = pdFALSE;
	//Verificamos para el Timer 0, cual fué la fuente de interrupción.
	//En este ejemplo, la única habilitada es Match 0.

	if (Chip_TIMER_MatchPending(LPC_TIMER0, 1)) {

		/* 'Give' the semaphore to unblock the task. */
		 xSemaphoreGiveFromISR( xBinarySemaphore, &xHigherPriorityTaskWoken );

		 /* Giving the semaphore may have unblocked a task - if it did and the
		 unblocked task has a priority equal to or above the currently executing
		 task then xHigherPriorityTaskWoken will have been set to pdTRUE and
		 portEND_SWITCHING_ISR() will force a context switch to the newly unblocked
		 higher priority task.

		 NOTE: The syntax for forcing a context switch within an ISR varies between
		 FreeRTOS ports.  The portEND_SWITCHING_ISR() macro is provided as part of
		 the Cortex M3 port layer for this purpose.  taskYIELD() must never be called
		 from an ISR! */
		 portEND_SWITCHING_ISR( xHigherPriorityTaskWoken );
		 Chip_TIMER_ClearMatch(LPC_TIMER0, 1);
	}
}
/*-----------------------------------------------------------*/
void InitTimer0(uint8_t channel,uint32_t matchVal){
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