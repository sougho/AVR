/*
 * MyServo.c
 *
 * Created: 8/3/2014 12:04:10 PM
 *  Author: soumegho
 */ 

#include <avr/io.h>
#include "MeServo.h"

void Servo_init () {
	
	//Configure TIMER1
	TCCR1A|=(1<<COM1A1)|(1<<COM1B1)|(1<<WGM11);        //NON Inverted PWM
	TCCR1B|=(1<<WGM13)|(1<<WGM12)|(1<<CS11)|(1<<CS10); //PRESCALER=64 MODE 14(FAST PWM)

	ICR1=4999;  //fPWM=50Hz (Period = 20ms Standard).

	DDRD|=(1<<PD4)|(1<<PD5);   //PWM Pins as Out
}

void Servo_move(int i) {
	OCR1A = i;
}