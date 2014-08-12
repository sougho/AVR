/*
 * MyHCSR04.c
 *
 * Created: 8/11/2014 8:49:20 PM
 *  Author: ramtaru
 */ 
#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include "MyHCSR04.h"
#include <MySerial.h>

#define UNIT_TIME_TICK_NS 62.5
#define TRIGGER_TICK (int)(10000 / 62.5) + 1


float MyHCSR04_measure_pulse(void) {
	DDRD &= ~(1<<PD6);   //ICP1 Input
	DDRB |= (1 << PB1 ); // Trigger
	PORTB |= (1<<PB1);
	TCNT1H = 0;
	TCNT1L = 0;
	TCCR1A = 0x80;
	TCCR1B = 0x09;
	OCR1A = TRIGGER_TICK;
	while (!(TIFR & (1<< OCF1A)));
	TIFR |= (1 << OCF1A);
	TCCR1A = 0x00;
	TCCR1B = 0x00;
	PORTB &= ~(1 << PB1);
	_delay_us(200);
	TIFR |= (1<< ICF1);
	while (!(PIND & (1 << PIND6)));
	TCNT1H = 0;
	TCNT1L = 0;
	TCCR1A = 0x08;
	TCCR1B = 0x04;
	while (!(TIFR & (1<<ICF1)));
	uint16_t l_icr = ICR1;
	TCCR1A = 0x00;
	TCCR1B = 0x00;
	TIFR |= (1<< ICF1);
	return ((float)l_icr * 16) / (58 );
}
