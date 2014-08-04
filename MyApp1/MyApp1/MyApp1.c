/*
 * MyApp1.c
 *
 * Created: 7/29/2014 10:41:58 AM
 *  Author: soumegho
 */ 



#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>
#include <avr/power.h>
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include <MySerial.h>
#include <MyLCD.h>
#include <MeServo.h>

#define BAUDRATE 9600
#define BAUD_PRESCALE  (((F_CPU / (BAUDRATE * 16UL))) - 1)
#define UNIT_TIME_TICK_NS 62.5


void roll_display(int);

int main(void)
{
	UART_init(BAUD_PRESCALE);
	
	LCD_init(&PORTC);
	LCD_test20x4();
	
	DDRD = 0xff;
	
	Servo_init();
	
	while (1) {
		
		UART_print_line("khuki");
		
	}
}

