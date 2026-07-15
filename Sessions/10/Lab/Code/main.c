/*
 * LCD_I2C.c
 *
 * Created: 2/9/2026 7:34:37 PM
 * Author : fatma foley
 */

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "i2c.h"
#include "lcd.h"

int main(void)
{
    // Initialize the I2C peripheral
    i2c_init();

    // Generate I2C start condition
    i2c_start();

    // Send the PCF8574A slave address
    i2c_sendByte(0x70);

    // Initialize the LCD
    lcd_init();

    while (1)
    {
        // Move cursor to the first row
        lcd_cmd(0x80);
        lcd_display_string("IEEE LastSession");
        _delay_ms(1000);

        // Move cursor to the second row
        lcd_cmd(0xC0);
        _delay_ms(1000);

        // Display text on the second row
        lcd_display_string("We are Using I2C");
        _delay_ms(1000);

        // Clear the LCD
        lcd_cmd(0x01);
        _delay_ms(1000);
    }
}
