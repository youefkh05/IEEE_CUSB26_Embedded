/*
 * app.c
 *
 * Created: 10/02/2026 21:16:11
 *  Author: maria
 */ 


#include "avr/io.h"
#include "../HAL/Button.h"
#include "../HAL/LED.h"
#define F_CPU 16000000UL  // 16 MHz

#include <util/delay.h>


int main(void)
{
    Button_init();   
    enable_pull_up();
	LEDS_init();

    while (1) {
	    if (!(button1_pin_id & (1 << button1_pinx))) {
		    LED_on(LED_RED);
		    } else {
		    LED_off(LED_RED);
	    }

	    _delay_ms(10);
    }
}

