#ifndef UART_H_
#define UART_H_


#include "../LIB/BIT_MATH.h" /* To use the macros like SET_BIT */
#include "../LIB/std_types.h"
#define F_CPU 16000000UL

void UART_init(uint16 baud_rate);
void UART_sendByte(uint8 data);
void UART_sendString(const char *str);

#endif