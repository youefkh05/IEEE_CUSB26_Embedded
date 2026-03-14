 /******************************************************************************
 *
 * Module: KEYPAD
 *
 * File Name: keypad.c
 *
 * Description: Source file for the Keypad driver
 *
 * Author: Mohamed Magdy
 *
 *******************************************************************************/
#include "keypad.h"
#include <util/delay.h>

/* Private function */
static char KEYPAD_4x4_adjustKeyNumber(uint8 button_number);

/*------------------------------------------------*/
void KEYPAD_init(void)
{
	uint8 i;

	/* Rows as output */
	for(i=0;i<KEYPAD_NUM_ROWS;i++)
	{
		GPIO_setupPinDirection(KEYPAD_ROW_PORT_ID,
		KEYPAD_FIRST_ROW_PIN_ID+i,
		PIN_OUTPUT);

		GPIO_writePin(KEYPAD_ROW_PORT_ID,
		KEYPAD_FIRST_ROW_PIN_ID+i,
		KEYPAD_BUTTON_RELEASED);
	}

	/* Columns as input with pull DOWN */
	for(i=0;i<KEYPAD_NUM_COLS;i++)
	{
		GPIO_setupPinDirection(KEYPAD_COL_PORT_ID,
		KEYPAD_FIRST_COL_PIN_ID+i,
		PIN_INPUT);
		
		_delay_us(5);

		GPIO_writePin(KEYPAD_COL_PORT_ID,
		KEYPAD_FIRST_COL_PIN_ID+i,
		KEYPAD_BUTTON_RELEASED);   // enable pull-up
	}
}

/*------------------------------------------------*/
boolean KEYPAD_getPressedKey(char *key)
{
	uint8 row,col;

	for(row=0 ; row<KEYPAD_NUM_ROWS ; row++)
	{
		/* Activate row */
		GPIO_writePin(KEYPAD_ROW_PORT_ID,
		KEYPAD_FIRST_ROW_PIN_ID+row,
		KEYPAD_BUTTON_PRESSED);

		for(col=0 ; col<KEYPAD_NUM_COLS ; col++)
		{
			if(GPIO_readPin(KEYPAD_COL_PORT_ID,
			KEYPAD_FIRST_COL_PIN_ID+col)
			== KEYPAD_BUTTON_PRESSED)
			{
				*key = KEYPAD_4x4_adjustKeyNumber(
				(row*KEYPAD_NUM_COLS)+col+1);

				/* deactivate row */
				GPIO_writePin(KEYPAD_ROW_PORT_ID,
				KEYPAD_FIRST_ROW_PIN_ID+row,
				KEYPAD_BUTTON_RELEASED);

				return TRUE;
			}
		}

		/* deactivate row */
		GPIO_writePin(KEYPAD_ROW_PORT_ID,
		KEYPAD_FIRST_ROW_PIN_ID+row,
		KEYPAD_BUTTON_RELEASED);
	}

	return FALSE;
}

/*------------------------------------------------*/
static char KEYPAD_4x4_adjustKeyNumber(uint8 button_number)
{
	switch(button_number)
	{
		case 1: return '7';
		case 2: return '8';
		case 3: return '9';
		case 4: return '%';

		case 5: return '4';
		case 6: return '5';
		case 7: return '6';
		case 8: return '*';

		case 9: return  '1';
		case 10: return '2';
		case 11: return '3';
		case 12: return '-';

		case 13: return '@';   // Enter
		case 14: return '0';
		case 15: return '=';
		case 16: return '+';
	}

	return 0;
}
