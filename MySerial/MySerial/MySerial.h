/*
 * MySerial.h
 *
 * Created: 8/2/2014 10:28:38 AM
 *  Author: soumegho
 */ 


#ifndef MYSERIAL_H_
#define MYSERIAL_H_

#include <avr/io.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/power.h>
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>

void UART_init(unsigned int baud_rate);
void UART_send_char(unsigned char c);
void UART_print_line(char *line);

#endif /* MYSERIAL_H_ */