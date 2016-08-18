/*
===============================================================================
 Name        : Ex8_FreeRtos.c
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

/*****************************************************************************
 * Public types/enumerations/variables
 ****************************************************************************/

#define mainDELAY_LOOP_COUNT		( 0xfffff )

/*****************************************************************************
 * Private functions
 ****************************************************************************/
/* The task functions. */
/* The two task functions. */
void vTaskFunction( void *pvParameters );
void vTask1		( void *pvParameters );
/* Sets up system hardware */

static void prvSetupHardware(void)
{
	SystemCoreClockUpdate();
	Board_Init();

	/* Initial LED0 state is off */
	Board_LED_Set(0, false);
}

const char *pcTextForTask1 = "Task 1 is running\n";
const char *pcTextForTask2 = "Task 2 is running\n";
xSemaphoreHandle xBinarySemaphore;

/*-----------------------------------------------------------*/

int main( void )
{
	prvSetupHardware();

	vSemaphoreCreateBinary( xBinarySemaphore );

	xTaskCreate( vTaskFunction, "Task 2", 240, (void*)pcTextForTask2, 1, NULL );
	xTaskCreate( vTask1, "Task 1", 240, NULL, 1, NULL );

	/* Start the scheduler so our tasks start executing. */
	vTaskStartScheduler();

	for( ;; );
	return 0;
}

/*-----------------------------------------------------------*/

void vTaskFunction( void *pvParameters )
{
char *pcTaskName;


	pcTaskName = ( char * ) pvParameters;

	/* As per most tasks, this task is implemented in an infinite loop. */
	for( ;; )
	{
		/* Print out the name of this task. */
		vPrintString( pcTaskName );
		xSemaphoreGive(xBinarySemaphore);
		vTaskDelay( 250 / portTICK_RATE_MS );
	}
}

void vTask1( void *pvParameters )
{
const char *pcTaskName = "Task 1 is running\n";


	xSemaphoreTake( xBinarySemaphore, 0 );

	for( ;; )
	  {
	        /* Use the semaphore to wait for the event.  The task blocks
	        indefinitely meaning this function call will only return once the
	        semaphore has been successfully obtained - so there is no need to check
	        the returned value. */
	        xSemaphoreTake( xBinarySemaphore, portMAX_DELAY );

	        /* To get here the event must have occurred.  Process the event (in this
	        case we just print out a message). */
	        vPrintString( pcTaskName );
	    }
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

