/*
 * MyI2CEEPROM.c
 *
 * Created: 8/9/2014 7:59:14 PM
 *  Author: ramtaru
 */ 


#include <avr/io.h>
#include <MyI2C.h>




void MyI2CEEPROM_init() {
	MyI2C_init();
}

void MyI2CEEPROM_write_byte(
	uint8_t eeprom_wr_addr, uint8_t addr_high, uint8_t addr_low, uint8_t byte
	) 
{
	MyI2C_start();
	MyI2C_write(eeprom_wr_addr);
	MyI2C_write(addr_high);
	MyI2C_write(addr_low);
	MyI2C_write(byte);
	MyI2C_stop();
}

uint8_t MyI2CEEPROM_read_byte(
	uint8_t eeprom_wr_addr, uint8_t addr_high, uint8_t addr_low
	) 
{
	MyI2C_start();
	MyI2C_write(eeprom_wr_addr);
	MyI2C_write(addr_high);
	MyI2C_write(addr_low);
	MyI2C_start();
	MyI2C_write(eeprom_wr_addr + 1);
	uint8_t data = MyI2C_read(0);
	MyI2C_stop();
	return data;
}


