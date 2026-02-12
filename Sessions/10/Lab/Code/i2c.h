/*
 * i2c.h
 *  Author: fatma foley
 */ 

#include <avr/io.h>

#define  F_CPU 8000000UL  // CLK = 8 MHz

void i2c_init();

//Start condition
void i2c_start();

//I2C stop condition
void i2c_write(char x);

char i2c_read();