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
#define	LENCOLA			4


/*****************************************************************************
 * Public types/enumerations/variables
 ****************************************************************************/
/*Defino los semáforos y el buffer*/
uint8_t buffercomun[LENCOLA];
uint8_t indice;
xSemaphoreHandle mutex;
xSemaphoreHandle llenos;
xSemaphoreHandle vacios;

/*****************************************************************************
 * Private functions
 ****************************************************************************/

static void prvSetupHardware(void)
{

   /* Generic Initialization */
	SystemCoreClockUpdate();
	Board_Init();

	/* Initial LED state is off */
	Board_LED_Set(LED0_GPIO_PORT_NUM,LED0_GPIO_BIT_NUM, true);
	Board_LED_Set(LED1_GPIO_PORT_NUM,LED1_GPIO_BIT_NUM, true);
	Board_LED_Set(LED2_GPIO_PORT_NUM,LED2_GPIO_BIT_NUM, false);
	Board_LED_Set(LED3_GPIO_PORT_NUM,LED3_GPIO_BIT_NUM, false);
	Board_LED_Set(LED4_GPIO_PORT_NUM,LED4_GPIO_BIT_NUM, false);
	Board_LED_Set(LED5_GPIO_PORT_NUM,LED5_GPIO_BIT_NUM, true);
	Board_LED_Set(LED6_GPIO_PORT_NUM,LED6_GPIO_BIT_NUM, true);
	Board_LED_Set(LED7_GPIO_PORT_NUM,LED7_GPIO_BIT_NUM, true);
}
//-----------------------------------------------------------------------------

void  RGBled(uint8_t i)
{
	switch(i)
	{
		case 0:
			Board_RGB_Set(RGB_GPIO_PORT_NUM,RED_GPIO_BIT_NUM,false);//Red_OFF;
			Board_RGB_Set(RGB_GPIO_PORT_NUM,GREEN_GPIO_BIT_NUM,false);//Green_OFF;
			Board_RGB_Set(RGB_GPIO_PORT_NUM,BLUE_GPIO_BIT_NUM,false);//Blue_OFF;
		break;

		case 1:
			Board_RGB_Set(RGB_GPIO_PORT_NUM,RED_GPIO_BIT_NUM,true);//Red_ON ;
			Board_RGB_Set(RGB_GPIO_PORT_NUM,GREEN_GPIO_BIT_NUM,false);//Green_OFF;
			Board_RGB_Set(RGB_GPIO_PORT_NUM,BLUE_GPIO_BIT_NUM,false);//Blue_OFF;
		break;

		case 2:
			Board_RGB_Set(RGB_GPIO_PORT_NUM,RED_GPIO_BIT_NUM,false);//Red_OFF;
			Board_RGB_Set(RGB_GPIO_PORT_NUM,GREEN_GPIO_BIT_NUM,true);//Green_ON ;
			Board_RGB_Set(RGB_GPIO_PORT_NUM,BLUE_GPIO_BIT_NUM,false);//Blue_OFF;
		break;
	}
}

//-----------------------------------------------------------------------------

 void TareaLed(void *pvParameters)
 {
		portTickType xWakeup;
		xWakeup = xTaskGetTickCount();

		while(1)
		{

			Board_LED_Toggle(LED0_GPIO_PORT_NUM,LED0_GPIO_BIT_NUM);
			vTaskDelayUntil(&xWakeup,100/portTICK_RATE_MS);
		}
 }

 //-----------------------------------------------------------------------------
 void Productor1(void *parametros)
 {
 	int debounce = 0,x=0;
 	for(;;)
 	{
 		vTaskDelay(20/portTICK_RATE_MS);
 		debounce<<=1;
 		x=Buttons_GetStatus(BUTTONS_BUTTON1_GPIO_PORT_NUM, BUTTONS_BUTTON1_GPIO_BIT_NUM);
 		if(x!=NO_BUTTON_PRESSED)
 		{
 					debounce|=1;
 		}
 		debounce&=0xF;
 		if(debounce == 0x03)
 		{
 			xSemaphoreTake(vacios,portMAX_DELAY);
 			xSemaphoreTake(mutex,portMAX_DELAY);
 			buffercomun[indice++]=1;
 			xSemaphoreGive(mutex);
 			xSemaphoreGive(llenos);
 		}
 	}
 }
 //-----------------------------------------------------------------------------
 void Productor2(void *parametros)
 {
 	int debounce = 0,x=0;
 		for(;;)
 		{
 			vTaskDelay(20/portTICK_RATE_MS);
 			debounce<<=1;
 			x=Buttons_GetStatus(BUTTONS_BUTTON2_GPIO_PORT_NUM, BUTTONS_BUTTON2_GPIO_BIT_NUM);
 			if(x!=NO_BUTTON_PRESSED)
 			{
 				debounce|=1;
 			}
 			debounce&=0xF;
 			if(debounce == 0x03)
 			{
 				xSemaphoreTake(vacios,portMAX_DELAY);
 				xSemaphoreTake(mutex,portMAX_DELAY);
 				buffercomun[indice++]=2;
 				xSemaphoreGive(mutex);
 				xSemaphoreGive(llenos);
 			}
 		}
 }
 //-----------------------------------------------------------------------------
 void Consumidor(void *parametros)
 {
 	for(;;)
 	{
 		vTaskDelay(50/portTICK_RATE_MS);
 		xSemaphoreTake(llenos,portMAX_DELAY);
 		xSemaphoreTake(mutex,portMAX_DELAY);
 		RGBled(buffercomun[--indice]);
 		xSemaphoreGive(mutex);
 		xSemaphoreGive(vacios);
 	}
 }

/*-----------------------------------------------------------*/

int main( void )
{
	uint8_t i;
	prvSetupHardware();

	indice = 0;
	for(i=0;i<LENCOLA;i++) buffercomun[i] = 0;
	mutex = xSemaphoreCreateMutex();
	vacios = xSemaphoreCreateCounting(LENCOLA,LENCOLA);
	llenos = xSemaphoreCreateCounting(LENCOLA,0);

	xTaskCreate(TareaLed,  "LED",230,NULL,tskIDLE_PRIORITY+2,NULL );
	xTaskCreate(Productor1,"PR1",230,NULL,tskIDLE_PRIORITY+1,NULL);
	xTaskCreate(Productor2,"PR2",230,NULL,tskIDLE_PRIORITY+1,NULL);
	xTaskCreate(Consumidor,"CON",230,NULL,tskIDLE_PRIORITY+1,NULL);

	vTaskStartScheduler();

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
