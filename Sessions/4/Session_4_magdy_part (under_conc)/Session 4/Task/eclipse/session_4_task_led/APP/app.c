/*
 * app.c
 *
 *  Created on: Feb 5, 2026
 *      Author: Mohamed Magdy
 */
#include<avr/io.h>
#include<util/delay.h>
#include"../HAL/LED.h"
#include"../HAL/button.h"

void main(){
	LEDS_init();
	button_init();
	enable_pull_up();

	while(1){
		if(!(button1_pin_id&(1<<button1_pinx))){
			LED_on(LED_RED);
			_delay_ms(1000);
			LED_off(LED_RED);
			LED_on(LED_GREEN);
			_delay_ms(1000);
			LED_off(LED_GREEN);
			LED_on(LED_BLUE);
			_delay_ms(1000);
			LED_off(LED_BLUE);

		}
		else{
			LED_off(LED_RED);
			LED_off(LED_BLUE);
			LED_off(LED_GREEN);
		}

	}


}

