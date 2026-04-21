/*
 * LCD.h
 *
 * Created: 4/20/2026 12:10:35 PM
 *  Author: b
 */ 


#ifndef LCD_H_
#define LCD_H_



#include "../../MCAL/gpio/gpio.h"
#include "../../common/std_types.h"


/*******************************************************************************
 *                         Port & Pin Configuration                            *
 *******************************************************************************/

#define GroupCTl     PORTB_ID
#define GroupData    PORTA_ID

#define RSPin      PIN5_ID
#define RWPin      PIN6_ID
#define EPin       PIN7_ID


/*******************************************************************************
 *                         Private Definitions                                 *
 *******************************************************************************/
#define LCD_CMD_FUNCTION_SET      0x38   /* 8-bit mode, 2 lines, 5x8 font */
#define LCD_CMD_DISPLAY_ON        0x0E   /* Display ON, cursor ON          */
#define LCD_CMD_CLEAR             0x01   /* Clear display                  */
#define LCD_CMD_ENTRY_MODE        0x06   /* Auto-increment cursor          */
#define LCD_CMD_CGRAM_START       0x40   /* CGRAM base address             */


#define A          0b01000001
#define B          0b01000010
#define C          0b01000011
#define D          0b01000100
#define E          0b01000101
#define F          0b01000110
#define G          0b01000111
#define H          0b01001000
#define I          0b01001001
#define J          0b01001010
#define K          0b01001011
#define L          0b01001100
#define M          0b01001101
#define N          0b01001110
#define O          0b01001111
#define P          0b01010000
#define Q          0b01010001
#define R          0b01010010
#define S          0b01010011
#define T          0b01010100
#define U          0b01010101
#define V          0b01010110
#define W          0b01010111
#define X          0b01011000
#define Y          0b01011001
#define Z          0b01011010

#define a          0b01100001
#define b          0b01100010
#define c          0b01100011
#define d          0b01100100
#define e          0b01100101
#define f          0b01100110
#define g          0b01100111
#define h          0b01101000
#define i          0b01101001
#define j          0b01101010
#define k          0b01101011
#define l          0b01101100
#define m          0b01101101
#define n          0b01101110
#define o          0b01101111
#define p          0b01110000
#define q          0b01110001
#define r          0b01110010
#define s          0b01110011
#define t          0b01110100
#define u          0b01110101
#define v          0b01110110
#define w          0b01110111
#define x          0b01111000
#define y          0b01111001
#define z          0b01111010


/*******************************************************************************
 *                         Function Prototypes                                 *
 *******************************************************************************/
void Lcd_Init8BitMode(void);
void Lcd_SendInstruction(uint8 Command);
void LCD_GoToXY(uint8 XPOS, uint8 YPOS);
void Lcd_SendData1(uint8 Data);
void Lcd_SendString(uint8 *String);
void LCD_Clear(void);




#endif /* LCD_H_ */