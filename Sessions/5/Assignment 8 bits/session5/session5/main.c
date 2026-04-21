 /******************************************************************************
 *
 * Module: application
 *
 * File Name: app.c
 *
 * Description: Source file for the application layer
 *
 * Author: Mohamed Magdy
 *
 *******************************************************************************/
#include<avr/io.h>
#include<util/delay.h>
#include "HAL/keypad/keypad.h"
#include "HAL/LCD/LCD.h"


int main(){

	uint8 pressed;

	Lcd_Init8BitMode();
	LCD_GoToXY(1,6);
	Lcd_SendString((uint8 *)"IEEE");
	
	_delay_ms(1000);
	LCD_Clear();
	LCD_GoToXY(1,0);
	Lcd_SendString((uint8 *)"Embedded Systems");
	
	LCD_GoToXY(2,0);
	Lcd_SendString((uint8 *)"Session 5");
	_delay_ms(1000);
	LCD_Clear();
	while(1){

		pressed=KEYPAD_getPressedKey();

		_delay_ms(200); //de-bounce effect test
		if((pressed >=0) && (pressed <=9)){

			Lcd_SendData1(pressed+ '0');
		

		}
		else if(pressed == 13){

			LCD_Clear();

		}
		else{
			Lcd_SendData1(pressed);
			


		}



	}



}