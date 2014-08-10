/*
 * MyI2C.h
 *
 * Created: 8/7/2014 7:47:18 AM
 *  Author: ramtaru
 */ 


#ifndef MYI2C_H_
#define MYI2C_H_

void MyI2C_init(void);
void MyI2C_start(void);
uint8_t MyI2C_status(void);
void MyI2C_stop(void);
void MyI2C_write(uint8_t data);
uint8_t MyI2C_read(uint8_t  ack);


#endif /* MYI2C_H_ */