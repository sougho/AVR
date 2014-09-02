#include<p18f2550.h>
#include "Uart.h"
#include "I2C.h"

unsigned int eep_write(unsigned char eep_addr, 
        unsigned int addr, unsigned char data) {
        i2c_start();
        i2c_send_byte(eep_addr);
        i2c_send_byte(addr >> 8);
        i2c_send_byte(addr & 0xFF);
        i2c_send_byte(data);
        i2c_stop();
        return 1;
}

unsigned char eep_read(unsigned char eep_addr,
        unsigned int addr) {
    i2c_start();
    i2c_send_byte(eep_addr);
    i2c_send_byte(addr >> 8);
    i2c_send_byte(addr & 0xFF);
    i2c_repeated_start();
    i2c_send_byte(eep_addr+1);
    char ch = i2c_receive_byte();
    i2c_stop();
    return ch;
}
