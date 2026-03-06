/*
 * app.c
 *
 * Created: 10/02/2026 21:16:11
 *  Author: maria
 */ 

#include "traffic_light.h"  
#include "avr/io.h"
#define F_CPU 16000000UL  // 16 MHz

#include <util/delay.h>

#define LED_COLMN	0
#define LED_RAW		1
#define LED_PERIOD  100
#define KEY_COLMN	8
#define KEY_RAW		1

int main(void)
{
    Button_init();   
    enable_pull_up();

    TrafficLight_init();
    TrafficLight_turnOffAll(); 
	
	LCD_init();
	LCD_clearScreen();

	LCD_displayStringRowColumn(0,0,"IEEE");
	_delay_ms(3000);
	
	uint8_t LCD_flag = 0; //to know when to update the LCD
		
	LCD_clearScreen();
	LCD_displayStringRowColumn(1,0,"System Off");
	
	//init the empty space
	char Led_space[KEY_COLMN+1];
	for (int i=0; i<=KEY_COLMN; i++)
	{
		Led_space[i]=' ';
	}
	Led_space[KEY_COLMN+1] = '\0';

	//key pad
	uint8_t key_pressed;
    while(1)
    {	
		if(KEYPAD_getPressedKey(&key_pressed))
		{
			_delay_ms(200);   // debounce

			if(key_pressed <= 9)
			{
				LCD_intgerToString(key_pressed);
			}
			else if(key_pressed == 13)
			{
				LCD_clearScreen();
			}
			else
			{
				LCD_displayCharacter(key_pressed);
			}
		}

        if(!(button1_pin_id & (1 << button1_pinx)))
        {
			if(LCD_flag==0)	//it was OFF
			{
				LCD_flag=1;
				LCD_clearScreen();
				LCD_displayStringRowColumn(0,0,"System ON");
				LCD_displayStringRowColumn(LED_RAW,LED_COLMN,Led_space);
								LCD_displayStringRowColumn(LED_RAW,LED_COLMN,Led_space);

			}
			
            TrafficLight_ON(RED);
			LCD_displayStringRowColumn(LED_RAW,LED_COLMN,Led_space);
			LCD_displayStringRowColumn(LED_RAW,LED_COLMN,"RED");

            for(uint16 i = 0; i < LED_PERIOD; i++)
            {
                if(button1_pin_id & (1 << button1_pinx)) 
                    break;
                _delay_ms(10);		// 100 iterations * 10ms = 1000ms delay
            }
            TrafficLight_OFF(RED);
			
            if(button1_pin_id & (1 << button1_pinx)) continue;		// Check if the button is OFF

            TrafficLight_ON(YELLOW);
			LCD_displayStringRowColumn(LED_RAW,LED_COLMN,Led_space);
			LCD_displayStringRowColumn(LED_RAW,LED_COLMN,"YELLOW");
			
            for(uint16 i = 0; i < LED_PERIOD; i++)
            {
                if(button1_pin_id & (1 << button1_pinx)) 
                    break;
                _delay_ms(10);		// 100 iterations * 10ms = 1000ms delay
            }
            TrafficLight_OFF(YELLOW);

            if(button1_pin_id & (1 << button1_pinx)) continue;		// Check if the button is OFF

            TrafficLight_ON(GREEN);
			LCD_displayStringRowColumn(LED_RAW,LED_COLMN,Led_space);
			LCD_displayStringRowColumn(LED_RAW,LED_COLMN,"GREEN");
			
            for(uint16 i = 0; i < LED_PERIOD; i++)
            {
                if(button1_pin_id & (1 << button1_pinx)) 
                    break;
                _delay_ms(10);		// 100 iterations * 10ms = 1000ms delay
            }
            TrafficLight_OFF(GREEN);
        }
        else
        {
            TrafficLight_turnOffAll();
			if(LCD_flag==1)	//it was ON
			{
				LCD_flag=0;
				LCD_clearScreen();
				LCD_displayStringRowColumn(0,0,"System Off");
			}
        }
    }
}

