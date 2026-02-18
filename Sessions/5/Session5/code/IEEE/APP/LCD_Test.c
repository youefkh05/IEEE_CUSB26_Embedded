/*
 * LCD_Test.c
 *
 *  Created on: Feb 18, 2026
 *      Author: b
 */
#include "../HAL/LCD/Header/LCD_Interface.h"
#include <util/delay.h>

int main(void)
{
    Lcd_Init8BitMode();

    LCD_SendString("HELLO");

    LCD_GoToXY(2,0);

    LCD_SendString("LCD TEST");

    while(1)
    {

    }
}

