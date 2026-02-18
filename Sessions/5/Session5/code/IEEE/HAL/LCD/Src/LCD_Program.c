/*
 * LCD_Program.c
 *
 *  Created on: Sep 27, 2024
 *      Author: b
 */




#include <util/delay.h>
#include "../../../Lib/Definition.h"
#include "../../../Lib/BitMath.h"
#include "../../../Lib/StdType.h"

#include "../../../MCAL/DIO/DIO_Interface.h"

#include "../Header/LCD_Config.h"
#include "../Header/LCD_Interface.h"
#include"../Header/LCD_Private.h"


void Lcd_Init8BitMode()
{
	DIO_SelectDirectionForPin(GroupCTl,RSPin,Output);
	DIO_SelectDirectionForPin(GroupCTl,RWPin, Output);
	DIO_SelectDirectionForPin(GroupCTl,EPin,Output);
	DIO_SelectDirectionForGroup(GroupData,0xFF);
//	-----------------------------------------------------
	_delay_ms(35);
	Lcd_SendInstruction(0x38);
	Lcd_SendInstruction(0x0E);
	Lcd_SendInstruction(0x01);
	Lcd_SendInstruction(0x06);

}
void Lcd_SendInstruction(u8 Command)
{
	//RS -> LOw
	DIO_SelectOutputValueForPin(GroupCTl,RSPin,Low);
	//RW -> Low
	DIO_SelectOutputValueForPin(GroupCTl,RWPin,Low);
	//E -> High
	DIO_SelectOutputValueForPin(GroupCTl,EPin,High);
	//Command
	DIO_SelectOutputValueForGroup(GroupData,Command);
	//E-> Low
	DIO_SelectOutputValueForPin(GroupCTl,EPin,Low);
	//Delay 2ms
	_delay_ms(2);
}
void Lcd_SendData1(u8 Data)
{
	//RS -> High
	DIO_SelectOutputValueForPin(GroupCTl,RSPin,High);
	//RW -> Low
	DIO_SelectOutputValueForPin(GroupCTl,RWPin,Low);
	//E -> High
	DIO_SelectOutputValueForPin(GroupCTl,EPin,High);
	//Data
	DIO_SelectOutputValueForGroup(GroupData,Data);
	//E-> Low
	DIO_SelectOutputValueForPin(GroupCTl,EPin,Low);


}
void LCD_SendString(u8 * String)
{
	if(String!=NULL)
	{
		u8 counter = 0 ;
		while(String[counter]!='\0')
		{
			Lcd_SendData1(String[counter]);
			counter++;
		}
	}
	else
	{

	}
}

void LCD_GoToXY(u8 XPOS ,u8 YPOS)
{
	u8 DDRAM_Address = 0 ;
	switch(XPOS)
	{
	case 1 : DDRAM_Address = 0x00 +YPOS; break;
	case 2 : DDRAM_Address = 0x40 +YPOS; break;
	}
	SetBit(DDRAM_Address,7);
	Lcd_SendInstruction(DDRAM_Address);

}
void Lcd_StoreSpecialChar1(u8 BLockNo,u8*Pattern)
{
	u8 CGRAMAddress=BLockNo*8;
	Lcd_SendInstruction(0x40|CGRAMAddress);
	u8 counter=0;
	for (counter=0;counter<8;counter++)
	{
		Lcd_SendData1(Pattern[counter]);
	}
	LCD_GoToXY(0,0);
}
void LCD_Clear() {
    Lcd_SendInstruction(0x01); // Send the command to clear the display
    _delay_ms(200);      // Delay for the command to execute
}


