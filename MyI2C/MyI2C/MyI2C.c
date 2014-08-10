/*
 * MyI2C.c
 *
 * Created: 8/7/2014 7:46:28 AM
 *  Author: ramtaru
 */ 

#include <avr/io.h>
#include "MyI2C.h"

void wait_for_complete() {
	while ((TWCR & (1 << TWINT)) == 0);
}

void MyI2C_init(void) {
	// SCL is 400 Mhz
	TWSR = 0x00;
	TWBR = 32;
	// Enables I2c
	TWCR = (1<<TWEN);
}

void MyI2C_start(void) {
	TWCR = (1<< TWINT) | (1 << TWSTA) | (1 << TWEN);
	wait_for_complete();
}

void MyI2C_stop(void) {
	TWCR = (1<<TWINT) | (1<<TWSTO) | (1<<TWEN);
}

uint8_t MyI2C_status(void) {
	uint8_t status;
	status = TWSR & 0xF8;
	return status;
}

void MyI2C_write(uint8_t data) {
	TWDR = data;
	TWCR = (1<<TWINT) | (1<<TWEN);
	wait_for_complete();
}

uint8_t MyI2C_read(uint8_t  ack) {
	TWCR = (1<<TWINT) | (1<<TWEN) | (ack<<TWEA);
	wait_for_complete();
	return TWDR;
}








