/*
 * MyUtils1.c
 *
 * Created: 7/29/2014 10:35:11 AM
 *  Author: soumegho
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/power.h>
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>


void UART_init(unsigned int baud_rate) {
	UBRRH = (unsigned char) baud_rate >> 8;
	UBRRL = (unsigned char) baud_rate;
	
	UCSRB = (1<<RXEN) | (1<<TXEN);
	
	UCSRC = (1<<URSEL)  | (0 << USBS) | (3<<UCSZ0);
}

void UART_send_char(unsigned char c) {
	while (!(UCSRA & (1<<UDRE)));
	UDR = c;
}

void UART_print_line(char *line) {
	
	while (*line != 0) {
		UART_send_char(*line++);
	}
	UART_send_char('\n');
}

float pin_high_time(volatile uint8_t * port, uint8_t pin, float unit_time_tick) {
	while (((PINB) & (1<< pin)));
	TCNT1H = 0;
	TCNT1L = 0;
	
	// Starts timer
	TCCR1A = 0x00;
	TCCR1B = 0x0d;
	
	while (!((PINB) & (1<< pin)));
	TCCR1B = 0;
	return (TCNT1 * (float)unit_time_tick);
}