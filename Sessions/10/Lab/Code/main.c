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
#include "LCD_I2C.h"


int main(void)
{
    i2c_init();
	i2c_start();
	i2c_write(0x70);
	lcd_init();
	
    while (1) 
    {
		lcd_cmd(0x80);
		lcd_msg("IEEE LastSession");
		_delay_ms(1000);
		lcd_cmd(0xC0);
		_delay_ms(1000);
		lcd_msg("We are Using ");
		lcd_msg("I2");
		lcd_msg("C");
		_delay_ms(1000);
		lcd_cmd(0x01);
		_delay_ms(1000);
    }
}

