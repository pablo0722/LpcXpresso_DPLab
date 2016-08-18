/*
===============================================================================
 Name        : Ex7_FreeRtos.c
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


/* Used to hold the handle of Task2. */
xTaskHandle xTask2Handle;

/*****************************************************************************
 * Private functions
 ****************************************************************************/
/* The task functions. */
/* The two task functions. */
void vTask1( void *pvParameters );
void vTask2( void *pvParameters );
/* Sets up system hardware */

static void prvSetupHardware(void)
{
	SystemCoreClockUpdate();
	Board_Init();

	/* Initial LED0 state is off */
	Board_LED_Set(0, false);
}



/*-----------------------------------------------------------*/

int main( void )
{
	prvSetupHardware();
	/* Create the first task at priority 1.  This time the task parameter is
	not used and is set to NULL.  The task handle is also not used so likewise
	is also set to NULL. */
	xTaskCreate( vTask1, "Task 1", 240, NULL, 1, NULL );
         /* The task is created at priority 1 ^. */

	/* Start the scheduler so our tasks start executing. */
	vTaskStartScheduler();

	for( ;; );
	return 0;
}

/*-----------------------------------------------------------*/

void vTask1( void *pvParameters )
{
const portTickType xDelay100ms = 100 / portTICK_RATE_MS;

	for( ;; )
	{
		/* Print out the name of this task. */
		vPrintString( "Task1 is running\n" );

		/* Create task 2 at a higher priority.  Again the task parameter is not
		used so is set to NULL - BUT this time we want to obtain a handle to the
		task so pass in the address of the xTask2Handle variable. */
		xTaskCreate( vTask2, "Task 2", 240, NULL, 2, &xTask2Handle );
			/* The task handle is the last parameter ^^^^^^^^^^^^^ */

		/* Task2 has/had the higher priority, so for Task1 to reach here Task2
		must have already executed and deleted itself.  Delay for 100
		milliseconds. */
		vTaskDelay( xDelay100ms );
	}
}

/*-----------------------------------------------------------*/

void vTask2( void *pvParameters )
{
	/* Task2 does nothing but delete itself.  To do this it could call vTaskDelete()
	using a NULL parameter, but instead and purely for demonstration purposes it
	instead calls vTaskDelete() with its own task handle. */
	vPrintString( "Task2 is running and about to delete itself\n" );
	vTaskDelete( xTask2Handle);
	//vTaskDelete(NULL );
	//for( ;; );
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


