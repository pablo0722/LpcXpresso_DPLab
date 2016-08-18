/*
===============================================================================
 Name        : Ex4_FreeRtos.c
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

void vTaskFunction( void *pvParameters );
/* Sets up system hardware */
static void prvSetupHardware(void)
{
	SystemCoreClockUpdate();
	Board_Init();

	/* Initial LED0 state is off */
	Board_LED_Set(0, false);
}


/* Define the strings that will be passed in as the task parameters.  These are
defined const and off the stack to ensure they remain valid when the tasks are
executing. */
const char *pcTextForTask1 = "Task 1 is running\n";
const char *pcTextForTask2 = "Task 2 is running\n";


/*-----------------------------------------------------------*/

int main( void )
{
	prvSetupHardware();
	/* Create the first task at priority 1... */
	xTaskCreate( vTaskFunction, "Task 1", 240, (void*)pcTextForTask1, 1, NULL );

	/* ... and the second task at priority 2.  The priority is the second to
	last parameter. */
	xTaskCreate( vTaskFunction, "Task 2", 240, (void*)pcTextForTask2, 1, NULL );

	/* Start the scheduler so our tasks start executing. */
	vTaskStartScheduler();


	for( ;; );
	return 0;
}


/*-----------------------------------------------------------*/

void vTaskFunction( void *pvParameters )
{
char *pcTaskName;
portTickType xLastWakeTime;

	/* The string to print out is passed in via the parameter.  Cast this to a
	character pointer. */
	pcTaskName = ( char * ) pvParameters;

	/* The xLastWakeTime variable needs to be initialized with the current tick
	count.  Note that this is the only time we access this variable.  From this
	point on xLastWakeTime is managed automatically by the vTaskDelayUntil()
	API function. */
	xLastWakeTime = xTaskGetTickCount();

	/* As per most tasks, this task is implemented in an infinite loop. */
	for( ;; )
	{
		/* Print out the name of this task. */
		vPrintString( pcTaskName );

		/* We want this task to execute exactly every 250 milliseconds.  As per
		the vTaskDelay() function, time is measured in ticks, and the
		portTICK_RATE_MS constant is used to convert this to milliseconds.
		xLastWakeTime is automatically updated within vTaskDelayUntil() so does not
		have to be updated by this task code. */
		vTaskDelayUntil( &xLastWakeTime, ( 250 / portTICK_RATE_MS ) );
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