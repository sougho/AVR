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
#include <MeServo.h>
#include <MyLCD.h>

//Simple Wait Function
void Wait()
{
	uint8_t i;
	for(i=0;i<50;i++)
	{
		_delay_loop_2(0);
		_delay_loop_2(0);
		_delay_loop_2(0);
	}

}

int main()
{
	Servo_init();
	LCD_init(&PORTC);

	while(1)
	{

		LCD_print_string("0");
		Servo_move(50);   //0 degree
		Wait();
		LCD_print_string("90");
		Servo_move(316);  //90 degree
		Wait();
		LCD_print_string("135");
		Servo_move(425);  //135 degree
		Wait();
		LCD_print_string("180");
		Servo_move(570);  //180 degree
		Wait();
	}
}
