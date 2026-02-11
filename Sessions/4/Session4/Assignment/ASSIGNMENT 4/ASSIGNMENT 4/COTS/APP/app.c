/*
 * app.c
 *
 * Created: 10/02/2026 21:16:11
 *  Author: maria
 */ 

#include "../LIB/STD_TYPES.h"
#include "../MCAL/GPIO.h"
#include "../HAL/Button.h"
#include "../HAL/traffic_light.h"  
#include "avr/io.h"
#include <util/delay.h>

int main(void)
{
    Button_init();   
    enable_pull_up();

    TrafficLight_init();
    TrafficLight_turnOffAll(); 

    while(1)
    {
        if(!(button1_pin_id & (1 << button1_pinx)))
        {
            TrafficLight_ON(RED);
            for(u16 i = 0; i < 100; i++)
            {
                if(button1_pin_id & (1 << button1_pinx)) 
                    break;
                _delay_ms(10);		// 100 iterations * 10ms = 1000ms delay
            }
            TrafficLight_OFF(RED);
			
            if(button1_pin_id & (1 << button1_pinx)) continue;		// Check if the button is OFF

            TrafficLight_ON(YELLOW);
            for(u16 i = 0; i < 50; i++)
            {
                if(button1_pin_id & (1 << button1_pinx)) 
                    break;
                _delay_ms(10);		// 50 iterations * 10ms = 500ms delay
            }
            TrafficLight_OFF(YELLOW);

            if(button1_pin_id & (1 << button1_pinx)) continue;		// Check if the button is OFF

            TrafficLight_ON(GREEN);
            for(u16 i = 0; i < 100; i++)
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

