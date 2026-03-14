/******************************************************************************
 *
 * Module: KEYPAD
 *
 * File Name: keypad.h
 *
 * Description: Header file for the Keypad driver
 *
 * Author: Mohamed Magdy
 *
 *******************************************************************************/

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "../MCAL/gpio.h"

/* Keypad size */
#define KEYPAD_NUM_COLS 4
#define KEYPAD_NUM_ROWS 4

/* Port configuration */
#define KEYPAD_ROW_PORT_ID PORTC_ID
#define KEYPAD_FIRST_ROW_PIN_ID PIN0_ID

#define KEYPAD_COL_PORT_ID PORTC_ID
#define KEYPAD_FIRST_COL_PIN_ID PIN4_ID

/* Button logic */
#define KEYPAD_BUTTON_PRESSED  LOGIC_HIGH
#define KEYPAD_BUTTON_RELEASED LOGIC_LOW

/* Functions */
void KEYPAD_init(void);

boolean KEYPAD_getPressedKey(char *key);

#endif /* KEYPAD_H_ */