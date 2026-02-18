/*
 * LCD_Interface.h
 *
 *  Created on: Sep 27, 2024
 *      Author: b
 */

#ifndef HAL_LCD_HEADER_LCD_INTERFACE_H_
#define HAL_LCD_HEADER_LCD_INTERFACE_H_



#include "LCD_Private.h"
#include "LCD_Config.h"
void Lcd_Init8BitMode();

void Lcd_SendInstruction(u8 Command);
void LCD_GoToXY(u8 XPOS ,u8 YPOS);

void Lcd_SendData1(u8 Data);
void Lcd_SendString(u8 * String);
void Lcd_StoreSpecialChar1(u8 BLockNo,u8*Pattern);
void LCD_Clear() ;


#endif /* HAL_LCD_HEADER_LCD_INTERFACE_H_ */
