/*
 * i2c.c
 *  Author: fatma foley
 */

 /* Polling Version */

#include "i2c.h"


void i2c_init(){
	TWSR = 0x00;		//Prescaler set to 1 (0x00 instead of TWSR & 0xFC as the other bits are read only and reserved)
	TWBR = 0x02;		//Baud rate is set by calculating = 100 KHz Standard Mode
	TWCR = (1<<TWEN);	//Enable I2C or TWCR | 0x04 TO set TWEN = 1
}

//Start condition
void i2c_start(){
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTA);	//start condition

	/* TWINT is set by hardware when the TWI operation finishes.
	   Writing 1 to TWINT clears the flag and starts the next TWI operation.*/

	while (!(TWCR & (1<<TWINT)));				//check for start condition

}

//I2C stop condition
void i2c_sendByte(char data){
	TWDR = data;						//Move value to I2C
	TWCR = (1<<TWINT) | (1<<TWEN);	//Enable I2C and clear interrupt
	while  (!(TWCR &(1<<TWINT)));	//check for sending
}

char i2c_recieveByte(){
	TWCR  = (1<<TWEN) | (1<<TWINT);	//Enable I2C and clear interrupt
	while (!(TWCR & (1<<TWINT)));	//Read successful with all data received in TWDR
	return TWDR;
}
