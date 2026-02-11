/*
 * button.h
 *
 *  Created on: Feb 5, 2026
 *      Author: SIGMA
 */

#ifndef HAL_BUTTON_H_
#define HAL_BUTTON_H_

#include "../common/common_macros.h"
#include<avr/io.h>
#include"../MCAL/gpio.h"

#define button1_portx   PORTB
#define button1_ddrx    DDRB
#define button1_pinx     0
#define button1_pin_id  PINB

void button_init(void);
void enable_pull_up(void);

#endif /* HAL_BUTTON_H_ */
