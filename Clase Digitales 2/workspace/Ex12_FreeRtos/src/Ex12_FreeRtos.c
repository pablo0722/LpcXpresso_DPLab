/*
===============================================================================
 Name        : Ex12_FreeRtos.c
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
#include "queue.h"
#include <cr_section_macros.h>

/*****************************************************************************
 * Private types/enumerations/variables
 ****************************************************************************/
#define TICKRATE_HZ1 (8)	/* 8 ticks per second */
/*****************************************************************************
 * Public types/enumerations/variables
 ****************************************************************************/
volatile uint8_t  X=0;
/* Declare a variable of type xSemaphoreHandle.  This is used to reference the
semaphore that is used to synchronize a task with an interrupt. */
xSemaphoreHandle xBinarySemaphore;
xQueueHandle xQueue;
/*****************************************************************************
 * Private functions
 ****************************************************************************/
/* The task functions. */
/* The two task functions. */
void vHandlerTask_Timer0( void *pvParameters );
void vPeriodicTask( void *pvParameters );
void InitTimer0(uint8_t ,uint32_t);

static void prvSetupHardware(void)
{
	uint32_t timerFreq, matchVal;
	uint8_t channel=1;

   /* Generic Initialization */
	SystemCoreClockUpdate();
	Board_Init();

	/* Initial LED state is off */
	Board_LED_Set(LED0_GPIO_PORT_NUM,LED0_GPIO_BIT_NUM, true);
	Board_LED_Set(LED1_GPIO_PORT_NUM,LED1_GPIO_BIT_NUM, true);
	Board_LED_Set(LED2_GPIO_PORT_NUM,LED2_GPIO_BIT_NUM, true);
	Board_LED_Set(LED3_GPIO_PORT_NUM,LED3_GPIO_BIT_NUM, true);
	Board_LED_Set(LED4_GPIO_PORT_NUM,LED4_GPIO_BIT_NUM, true);
	Board_LED_Set(LED5_GPIO_PORT_NUM,LED5_GPIO_BIT_NUM, true);
	Board_LED_Set(LED6_GPIO_PORT_NUM,LED6_GPIO_BIT_NUM, true);
	Board_LED_Set(LED7_GPIO_PORT_NUM,LED7_GPIO_BIT_NUM, true);

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
    xQueue = xQueueCreate( 1, sizeof( uint8_t ) );
    /* Check the semaphore was created successfully. */
    if( xQueue != NULL )
    {

        xTaskCreate( vHandlerTask_Timer0, "Handler_Timer_0", 240, NULL,2, NULL );

        xTaskCreate( vPeriodicTask, "Periodic", 240, NULL, 1, NULL );

        /* Start the scheduler so the created tasks start executing. */
        vTaskStartScheduler();
    }

    /* If all is well we will never reach here as the scheduler will now be
    running the tasks.  If we do reach here then it is likely that there was
    insufficient heap memory available for a resource to be created. */
    for( ;; );
    return 0;
}

/*-----------------------------------------------------------*/
void vPeriodicTask( void *pvParameters )
{
	xSemaphoreTake( xBinarySemaphore, 0 );

		for( ;; )
		  {
			/* LED state is off */
			Board_LED_Set(LED0_GPIO_PORT_NUM,LED0_GPIO_BIT_NUM, true);
			Board_LED_Set(LED1_GPIO_PORT_NUM,LED1_GPIO_BIT_NUM, true);
			Board_LED_Set(LED2_GPIO_PORT_NUM,LED2_GPIO_BIT_NUM, true);
			Board_LED_Set(LED3_GPIO_PORT_NUM,LED3_GPIO_BIT_NUM, true);
			Board_LED_Set(LED4_GPIO_PORT_NUM,LED4_GPIO_BIT_NUM, true);
			Board_LED_Set(LED5_GPIO_PORT_NUM,LED5_GPIO_BIT_NUM, true);
			Board_LED_Set(LED6_GPIO_PORT_NUM,LED6_GPIO_BIT_NUM, true);
			Board_LED_Set(LED7_GPIO_PORT_NUM,LED7_GPIO_BIT_NUM, true);
		    xSemaphoreTake( xBinarySemaphore, portMAX_DELAY );

		    }

}
/*-----------------------------------------------------------*/
void vHandlerTask_Timer0( void *pvParameters )
{

uint8_t lReceivedValue;

	xQueueReceive( xQueue, &lReceivedValue, 0 );
	for( ;; )
	{

		xQueueReceive( xQueue, &lReceivedValue, portMAX_DELAY );

		switch(lReceivedValue){

			case 0:
				Board_LED_Set(LED0_GPIO_PORT_NUM,LED0_GPIO_BIT_NUM, false);
			break;

			case 1:
				Board_LED_Set(LED1_GPIO_PORT_NUM,LED1_GPIO_BIT_NUM, false);
			break;

			case 2:
				Board_LED_Set(LED2_GPIO_PORT_NUM,LED2_GPIO_BIT_NUM, false);
			break;

			case 3:
				Board_LED_Set(LED3_GPIO_PORT_NUM,LED3_GPIO_BIT_NUM, false);
			break;

			case 4:
				Board_LED_Set(LED4_GPIO_PORT_NUM,LED4_GPIO_BIT_NUM, false);
			break;

			case 5:
				Board_LED_Set(LED5_GPIO_PORT_NUM,LED5_GPIO_BIT_NUM, false);
			break;

			case 6:
				Board_LED_Set(LED6_GPIO_PORT_NUM,LED6_GPIO_BIT_NUM, false);
			break;

			case 7:
				Board_LED_Set(LED7_GPIO_PORT_NUM,LED7_GPIO_BIT_NUM, false);
			break;
		}
	}
}
/*-----------------------------------------------------------*/
void TIMER0_IRQHandler(void)
{
	portBASE_TYPE xHigherPriorityTaskWoken = pdFALSE;
	//Verificamos para el Timer 0, cual fué la fuente de interrupción.
	//En este ejemplo, la única habilitada es Match 0.

	if (Chip_TIMER_MatchPending(LPC_TIMER0, 1)) {

		if(X==8){
			X=0;
			xSemaphoreGiveFromISR( xBinarySemaphore, &xHigherPriorityTaskWoken );
		}else{
			xQueueSendToBackFromISR( xQueue, &X, &xHigherPriorityTaskWoken );
			X++;
		}

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
