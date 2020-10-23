/*
 * RTOS_UART.c
 *
 * Created: 10/23/2020 6:28:12 PM
 * Author : Mohamed Nader
 */ 

#include <avr/io.h>
#include "FreeRTOS.h"
#include "task.h"
#include "Uart.h"
void UartPrint(void* string);
int main(void)
{
	UART_Init();
	xTaskCreate(UartPrint,"RtosUart1",50,(void*)"task1\r\n",0,NULL);
	xTaskCreate(UartPrint,"RtosUart2",50,(void*)"task2\r\n",0,NULL);
    /* Replace with your application code */
	vTaskStartScheduler();
    while (1) 
    {
    }
}
void UartPrint(void* string)
{
	
	while (1)
	{
		UART_Send_String((char*)string);
		vTaskDelay(2/portTICK_PERIOD_MS);
	}
	
}

