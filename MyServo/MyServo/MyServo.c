/*
 * MyServo.c
 *
 * Created: 8/3/2014 12:04:10 PM
 *  Author: soumegho
 */ 

#include <avr/io.h>
#include "MeServo.h"

void Servo_init () {
	
	// Initialize timer 1 
	OCR1A = 97;
	TCCR1A |= (1 << COM1A1) | (1<< COM1A0) | (1<<WGM11);
	TCCR1A &= ~(1<<WGM10);
	TCCR1B |= (1<<WGM12) | (1<<WGM13) | (1<<CS11) | (1<<CS12);
	ICR1 = 4999;
	DDRD |= (1<<PD4) | (1<<PD5);
	
}

void Servo_move(int i) {
	
	OCR1A = i;
	
}