/*
 * Button.h
 *
 * Created: 10/02/2026 21:00:30
 *  Author: maria
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include<avr/io.h>

#define button1_portx   PORTB
#define button1_ddrx    DDRB
#define button1_pinx     0
#define button1_pin_id  PINB

void Button_init(void);
void enable_pull_up(void);

#endif /* BUTTON_H_ */