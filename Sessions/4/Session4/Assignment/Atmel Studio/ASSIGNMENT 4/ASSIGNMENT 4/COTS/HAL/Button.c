/*
 * Button.c
 *
 * Created: 10/02/2026 21:00:45
 *  Author: maria
 */ 

#include "../LIB/BIT_MATH.h"
#include "../MCAL/GPIO.h"
#include "Button.h"



void Button_init(void){
	GPIO_setupPinDirection(button1_portx , button1_pinx , PIN_INPUT);

}
void enable_pull_up(void){
	SET_BIT(button1_portx, button1_pinx);
}