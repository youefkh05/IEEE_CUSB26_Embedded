/*
 * GPIO.h
 *
 * Created: 10/02/2026 20:55:44
 *  Author: maria
 */ 


#ifndef GPIO_H_
#define GPIO_H_

#include "../LIB/STD_TYPES.h"

#define NUM_OF_PORTS           4
#define NUM_OF_PINS_PER_PORT   8

#define PORTA_ID               0
#define PORTB_ID               1
#define PORTC_ID               2
#define PORTD_ID               3

#define PIN0_ID                0
#define PIN1_ID                1
#define PIN2_ID                2
#define PIN3_ID                3
#define PIN4_ID                4
#define PIN5_ID                5
#define PIN6_ID                6
#define PIN7_ID                7


typedef enum
{
	PIN_INPUT,PIN_OUTPUT
}GPIO_PinDirectionType;

typedef enum
{
	PORT_INPUT,PORT_OUTPUT=0xFF
}GPIO_PortDirectionType;


/* Pin Functions */
void GPIO_setupPinDirection(u8 port_num, u8 pin_num, GPIO_PinDirectionType direction);
void GPIO_writePin(u8 port_num, u8 pin_num, u8 value);
u8 GPIO_readPin(u8 port_num, u8 pin_num);

/* Port Functions */
void GPIO_setupPortDirection(u8 port_num, GPIO_PortDirectionType direction);
void GPIO_writePort(u8 port_num, u8 value);
u8 GPIO_readPort(u8 port_num);

#endif /* GPIO_H_ */