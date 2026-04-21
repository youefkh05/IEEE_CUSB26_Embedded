/*
 * LCD.c
 *
 * Created: 4/20/2026 12:10:01 PM
 *  Author: b
 */ 
#include <util/delay.h>
#include "../../common/std_types.h"
#include "../../common/common_macros.h"
#include "../../MCAL/gpio/gpio.h"
#include "../LCD/LCD.h"          /* Single combined header */

void Lcd_Init8BitMode(void)
{
	/* Set control pins as output */
	GPIO_setupPinDirection(GroupCTl, RSPin, PIN_OUTPUT);
	GPIO_setupPinDirection(GroupCTl, RWPin, PIN_OUTPUT);
	GPIO_setupPinDirection(GroupCTl, EPin,  PIN_OUTPUT);

	/* Set data port as output */
	GPIO_setupPortDirection(GroupData, PORT_OUTPUT);

	/* Initialization sequence */
	_delay_ms(35);
	Lcd_SendInstruction(LCD_CMD_FUNCTION_SET);
	Lcd_SendInstruction(LCD_CMD_DISPLAY_ON);
	Lcd_SendInstruction(LCD_CMD_CLEAR);
	Lcd_SendInstruction(LCD_CMD_ENTRY_MODE);
}

void Lcd_SendInstruction(uint8 Command)
{
	GPIO_writePin(GroupCTl, RSPin, LOGIC_LOW);  /* RS = 0 (Instruction) */
	GPIO_writePin(GroupCTl, RWPin, LOGIC_LOW);  /* RW = 0 (Write)       */
	GPIO_writePin(GroupCTl, EPin,  LOGIC_HIGH); /* E  = 1 (Enable)      */
	GPIO_writePort(GroupData, Command);            /* Put command on bus   */
	GPIO_writePin(GroupCTl, EPin,  LOGIC_LOW);  /* E  = 0 (Latch)       */
	_delay_ms(2);
}

void Lcd_SendData1(uint8 Data)
{
	GPIO_writePin(GroupCTl, RSPin, LOGIC_HIGH); /* RS = 1 (Data)  */
	GPIO_writePin(GroupCTl, RWPin, LOGIC_LOW);  /* RW = 0 (Write) */
	GPIO_writePin(GroupCTl, EPin,  LOGIC_HIGH); /* E  = 1 (Enable)*/
	GPIO_writePort(GroupData, Data);               /* Put data on bus*/
	GPIO_writePin(GroupCTl, EPin,  LOGIC_LOW);  /* E  = 0 (Latch) */
	_delay_ms(1);
}

void Lcd_SendString(uint8 *String)
{
	if (String != NULL_PTR)
	{
		uint8 counter = 0;
		while (String[counter] != '\0')
		{
			Lcd_SendData1(String[counter]);
			counter++;
		}
	}
}

void LCD_GoToXY(uint8 XPOS, uint8 YPOS)
{
	uint8 DDRAM_Address = 0;
	switch (XPOS)
	{
		case 1: DDRAM_Address = 0x00 + YPOS; break;
		case 2: DDRAM_Address = 0x40 + YPOS; break;
	}
	SET_BIT(DDRAM_Address, 7);
	Lcd_SendInstruction(DDRAM_Address);
}

void LCD_Clear(void)
{
	Lcd_SendInstruction(LCD_CMD_CLEAR);
	_delay_ms(2);
}