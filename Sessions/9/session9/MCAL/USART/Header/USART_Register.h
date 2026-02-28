/*
 * USART_Register.h
 *
 *  Created on: Nov 2, 2024
 *      Author: DELL
 */

#ifndef MCAL_USART_HEADER_USART_REGISTER_H_
#define MCAL_USART_HEADER_USART_REGISTER_H_

#include"../../../LIB/StdType.h"
#include"../../../LIB/BitMath.h"
#include"../../../LIB/Definition.h"

#define USART_UDR 		*((volatile u8 *) 0X2C)
#define USART_UCSRA 	*((volatile u8 *) 0X2B)
#define USART_UCSRB     *((volatile u8 *) 0X2A)
#define USART_UCSRC     *((volatile u8 *) 0X40)//Data
#define USART_UBRRL     *((volatile u8 *) 0X29)
#define USART_UBRRH     *((volatile u8 *) 0X40)

#endif /* MCAL_USART_HEADER_USART_REGISTER_H_ */
