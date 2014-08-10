/*
 * MyI2CEEPROM.h
 *
 * Created: 8/9/2014 8:17:12 PM
 *  Author: ramtaru
 */ 


#ifndef MYI2CEEPROM_H_
#define MYI2CEEPROM_H_

void MyI2CEEPROM_init();
void MyI2CEEPROM_write_byte(
uint8_t eeprom_wr_addr, uint8_t addr_high, uint8_t addr_low, uint8_t byte
);
uint8_t MyI2CEEPROM_read_byte(
uint8_t eeprom_wr_addr, uint8_t addr_high, uint8_t addr_low
);




#endif /* MYI2CEEPROM_H_ */