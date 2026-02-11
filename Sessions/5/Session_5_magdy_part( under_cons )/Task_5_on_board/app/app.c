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
#include"../hal/keypad.h"
#include"../hal/lcd.h"
#define F_CPU 16000000UL

int main(){

	uint8 pressed;

	LCD_init();
	LCD_displayStringRowColumn(0,6,"IEEE");
	_delay_ms(3000);
	LCD_clearScreen();
	LCD_displayStringRowColumn(0,0,"Embedded Systems");
	LCD_displayStringRowColumn(1,3,"Session 5");
	_delay_ms(5000);
	LCD_clearScreen();
	while(1){

		pressed=KEYPAD_getPressedKey();

		_delay_ms(200); //de-bounce effect test
		if((pressed >=0) && (pressed <=9)){

			LCD_intgerToString(pressed);

		}
		else if(pressed == 13){

			LCD_clearScreen();

		}
		else{
			LCD_displayCharacter(pressed);


		}



	}



}
