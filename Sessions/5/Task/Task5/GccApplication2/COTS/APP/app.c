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


int main(void)
{
    Button_init();   
    enable_pull_up();

    TrafficLight_init();
    TrafficLight_turnOffAll(); 
	
	LCD_init();
	LCD_displayStringRowColumn(1,6," IEEE");
	_delay_ms(3000);

    while(1)
    {
        if(!(button1_pin_id & (1 << button1_pinx)))
        {
            TrafficLight_ON(RED);
            for(uint16 i = 0; i < 100; i++)
            {
                if(button1_pin_id & (1 << button1_pinx)) 
                    break;
                _delay_ms(10);		// 100 iterations * 10ms = 1000ms delay
            }
            TrafficLight_OFF(RED);
			
            if(button1_pin_id & (1 << button1_pinx)) continue;		// Check if the button is OFF

            TrafficLight_ON(YELLOW);
            for(uint16 i = 0; i < 50; i++)
            {
                if(button1_pin_id & (1 << button1_pinx)) 
                    break;
                _delay_ms(10);		// 50 iterations * 10ms = 500ms delay
            }
            TrafficLight_OFF(YELLOW);

            if(button1_pin_id & (1 << button1_pinx)) continue;		// Check if the button is OFF

            TrafficLight_ON(GREEN);
            for(uint16 i = 0; i < 100; i++)
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
        }
    }
}

