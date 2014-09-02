/* 
 * File:   Eeprom.h
 * Author: ramtaru
 *
 * Created on August 29, 2014, 6:28 PM
 */

#ifndef EEPROM_H
#define	EEPROM_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "I2C.h"

unsigned int eep_write(unsigned char eep_addr,
        unsigned int addr, unsigned char data);
unsigned char eep_read(unsigned char eep_addr,
        unsigned int addr);



#ifdef	__cplusplus
}
#endif

#endif	/* EEPROM_H */

