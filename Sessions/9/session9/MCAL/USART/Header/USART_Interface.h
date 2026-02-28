/*
 * USART_Interface.h
 *
 *  Created on: Nov 2, 2024
 *      Author: DELL
 */

#ifndef MCAL_USART_HEADER_USART_INTERFACE_H_
#define MCAL_USART_HEADER_USART_INTERFACE_H_

#include"../../../LIB/StdType.h"
#include"../../../LIB/BitMath.h"
#include"../../../LIB/definition.h"

#include"USART_Config.h"
#include"USART_Private.h"
#include"USART_Register.h"

void USART_Init (void);
void USART_SendData (u16 CData);
void USART_RecevieData (u16 *Data) ;

void USART_SendString(char *str);

void USART_SendNumber(u16 num);

#endif /* MCAL_USART_HEADER_USART_INTERFACE_H_ */
