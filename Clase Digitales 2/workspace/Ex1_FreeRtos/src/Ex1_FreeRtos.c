/*
===============================================================================
 Name        : Ex1_FreeRtos.c
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
/* Used as a loop counter to create a very crude delay. */
#define USAR_TAREA_1
#define USAR_TAREA_2
/*****************************************************************************
 * Private functions
 ****************************************************************************/
/* The task functions. */
void vTask1		( void *pvParameters );
void vTask2		( void *pvParameters );
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
	/* Init the semi-hosting. */
	printf( "\n" );

#ifdef USAR_TAREA_1
	/* Create one of the two tasks. */
	xTaskCreate(	vTask1,		/* Pointer to the function that implements the task. */
					"Task 1",	/* Text name for the task.  This is to facilitate debugging only. */
					240,		/* Stack depth in words. */
					NULL,		/* We are not using the task parameter. */
					1,			/* This task will run at priority 1. */
					NULL );		/* We are not using the task handle. */
#endif

#ifdef USAR_TAREA_2
	/* Create the other task in exactly the same way. */
	xTaskCreate(	vTask2,		/* Pointer to the function that implements the task. */
					"Task 2",	/* Text name for the task.  This is to facilitate debugging only. */
					240,		/* Stack depth in words. */
					NULL,		/* We are not using the task parameter. */
					1,			/* This task will run at priority 1. */
					NULL );		/* We are not using the task handle. */
#endif



	/* Start the scheduler so our tasks start executing. */
	vTaskStartScheduler();


	for( ;; );
	return 0;
}
/*-----------------------------------------------------------*/

void vTask1( void *pvParameters )
{
	const char *pcTaskName = "Task 1 is running\n";
	volatile unsigned long ul;

		/* As per most tasks, this task is implemented in an infinite loop. */
		for( ;; )
		{
			/* Print out the name of this task. */
			vPrintString( pcTaskName );

			/* Delay for a period. */
			for( ul = 0; ul < mainDELAY_LOOP_COUNT; ul++ )
			{
				/* This loop is just a very crude delay implementation.  There is
				nothing to do in here.  Later exercises will replace this crude
				loop with a proper delay/sleep function. */
			}
		}
}
/*-----------------------------------------------------------*/

void vTask2( void *pvParameters )
{
	const char *pcTaskName = "Task 2 is running\n";
	volatile unsigned long ul;

	/* As per most tasks, this task is implemented in an infinite loop. */
	for( ;; )
	{
		/* Print out the name of this task. */
		vPrintString( pcTaskName );

		/* Delay for a period. */
		for( ul = 0; ul < mainDELAY_LOOP_COUNT; ul++ )
		{
			/* This loop is just a very crude delay implementation.  There is
			nothing to do in here.  Later exercises will replace this crude
			loop with a proper delay/sleep function. */
		}
	}
}
/*-----------------------------------------------------------*/



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
