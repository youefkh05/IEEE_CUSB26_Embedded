/*
 * app.c
 *
 * Created: 10/02/2026 21:16:11
 *  Author: maria
 */ 

#include "../HAL/LED.h"  
#include "../MCAL/UART.h"
#include "avr/io.h"
//#define F_CPU 16000000UL  // 16 MHz

#include <util/delay.h>


int main(void)
{
	UART_init(9600);

	UART_sendString("System Started\r\n");
	_delay_ms(3000);
	
	uint8_t counter= '0';

    while(1)
    { 
		counter++;
		UART_sendString("Counter :");
		UART_sendByte(counter);
		UART_sendString(" num \r\n");
	    _delay_ms(1000);

		
    }
}

