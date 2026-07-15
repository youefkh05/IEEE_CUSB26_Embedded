/*
 * LCD_I2C.c
 *  Author: fatma foley
 */

#include "lcd.h"

/*Generate Falling Edge*/
void toggle() {
	// Generate an Enable pulse (HIGH then LOW) to latch data into the LCD
	lcd_data |= 0x02;                // Set LCD Enable pin HIGH
	i2c_sendByte(lcd_data);          // Send updated data through I2C

	_delay_ms(1);

	lcd_data &= ~0x02;               // Set LCD Enable pin LOW to latch data
	i2c_sendByte(lcd_data);          // Send updated data through I2C
}

void lcd_cmd_high_nibble(char MSB_data) {
	/*OR lcd_data &=0x0E;*/

	// Select command mode (RS = 0)
	lcd_data &= ~0x01;
	// Clear the previous high nibble
	lcd_data &= 0x0F;

	// Load the command high nibble
	lcd_data |= (MSB_data & 0xF0);
	i2c_sendByte(lcd_data);

	// Generate Enable pulse to latch the command
	toggle();
}

void lcd_cmd(char cmd) {
	/* Select command mode (RS = 0) &
	   Clear the previous high nibble*/
	lcd_data &=0x0E;

	//Send high nibble
	lcd_data |= (cmd & 0xF0);
	i2c_sendByte(lcd_data);
	toggle();

	// Send low nibble
	lcd_data &= 0x0F;
	lcd_data |= ((cmd & 0x0F) << 4);
	i2c_sendByte(lcd_data);
	toggle();
}

void lcd_display_data(char data)
{
    // Select data mode (RS = 1)
    lcd_data |= 0x01;

    // Send high nibble
    lcd_data &= 0x0F;
    lcd_data |= (data & 0xF0);
    i2c_sendByte(lcd_data);
    toggle();

    // Send low nibble
    lcd_data &= 0x0F;
    lcd_data |= ((data & 0x0F) << 4);
    i2c_sendByte(lcd_data);
    toggle();
}

void lcd_init()
{
    // Initialize LCD in 8-bit mode
    lcd_cmd_high_nibble(0x30);

    // Repeat initialization for reliable startup
    lcd_cmd_high_nibble(0x30);

    // Switch to 4-bit mode
    lcd_cmd_high_nibble(0x20);

    // Configure LCD: 4-bit, 2 lines, 5x8 font
    lcd_cmd(0x28);

    // Display ON, cursor OFF
    lcd_cmd(0x0C);

    // Clear display
    lcd_cmd(0x01);

    // Auto-increment cursor
    lcd_cmd(0x06);

    // Move cursor to the beginning of the first line
    lcd_cmd(0x80);
}

void lcd_display_string(char *string) {
	while (*string != 0)                 //Wait till all String are passed to LCD
		lcd_display_data(*string++);		//Send the String to LCD
}
