/*
 * LCD_Test.c
 *
 * Created: 4/20/2026 12:11:53 PM
 *  Author: b
 */ 
#include "../../HAL/LCD/LCD.h"
#include "LCD_Test.h"

void LCD_Test(void)    /* must match the prototype exactly */
{
	Lcd_Init8BitMode();
	Lcd_SendString((uint8 *)"Hello");
	LCD_GoToXY(2, 0);
	Lcd_SendString((uint8 *)"world");
	while(1)
	{
	}
}