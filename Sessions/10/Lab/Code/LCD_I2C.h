/*
 * LCD_I2C.h
 *  Author: fatma foley
 */

#include <avr/io.h>
#include <util/delay.h>
#include "i2c.h"

char lcd_data;


void lcd_init();			                     //LCD Initializing Function
void toggle();				                     //Latching function of LCD
void lcd_cmd_high_nibble(char MSB_data);   //Function to send half byte command to LCD
void lcd_cmd(char cmd);		                 //Function to send Command to LCD
void lcd_display_data(char data);		       //Function to send data to LCD
void lcd_display_string(char *string);		 //Function to Send String to LCD

