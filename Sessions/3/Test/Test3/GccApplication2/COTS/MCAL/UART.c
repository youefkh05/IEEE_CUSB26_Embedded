#include "uart.h"
#include <avr/io.h>


void UART_init(uint16 baud_rate)
{
	uint16 ubrr = (F_CPU / (16UL * baud_rate)) - 1;

	UBRRH = (uint8)(ubrr >> 8);
	UBRRL = (uint8)ubrr;

	UCSRB = (1<<TXEN);          // Enable TX
	UCSRC = (1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1); // 8-bit
}

void UART_sendByte(uint8 data)
{
	while(!(UCSRA & (1<<UDRE))); // wait
	UDR = data;
}

void UART_sendString(const char *str)
{
	while(*str)
	{
		UART_sendByte(*str++);
	}
}