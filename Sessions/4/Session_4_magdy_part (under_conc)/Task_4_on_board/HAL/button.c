/*
 * button.c
 *
 *  Created on: Feb 5, 2026
 *      Author: SIGMA
 */
#include"button.h"
#include "../common/common_macros.h"
#include<avr/io.h>
#include"../MCAL/gpio.h"

void button_init(void){
    GPIO_setupPinDirection(button1_portx , button1_pinx , PIN_INPUT);

}
void enable_pull_up(void){
	button1_portx|=(1<<button1_pinx);
}
