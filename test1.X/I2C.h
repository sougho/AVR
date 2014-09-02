/* 
 * File:   I2C.h
 * Author: ramtaru
 *
 * Created on August 29, 2014, 6:25 PM
 */

#ifndef I2C_H
#define	I2C_H

#ifdef	__cplusplus
extern "C" {
#endif

void i2c_init();
void i2c_start();
void i2c_repeated_start();
void i2c_stop();
unsigned char i2c_send_byte(unsigned char byte);
unsigned char i2c_receive_byte_with_ack();
unsigned char i2c_receive_byte_wo_ack();


#ifdef	__cplusplus
}
#endif

#endif	/* I2C_H */

