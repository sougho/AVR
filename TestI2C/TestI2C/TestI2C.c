/*
 * TestI2C.c
 *
 * Created: 8/7/2014 8:02:14 AM
 *  Author: ramtaru
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <MyI2CEEPROM.h>
#include <MySerial.h>
#include <MyLCD.h>
#include <stdio.h>
#include <MyHCSR04.h>

#define BAUDRATE 9600
#define BAUD_PRESCALE  (((F_CPU / (BAUDRATE * 16UL))) - 1)
#define UNIT_TIME_TICK_NS 62.5

uint8_t MyI2CEEPROM_test(uint8_t addr, uint8_t data) {
	MyI2CEEPROM_init();
	MyI2CEEPROM_write_byte(addr, 0x7f, 0xff, data);
	_delay_ms(10);
	uint8_t ret = MyI2CEEPROM_read_byte(addr, 0x7f, 0xff);
	return ret;
}

int main(void)
{
	LCD_init(&PORTA);
	LCD_gotoxy(1,1);
	LCD_print_string("AVR OK");
	UART_init(BAUD_PRESCALE);
	LCD_gotoxy(1,2);
	LCD_print_string("EEPROM Test:");
	UART_print_line("EEPROM Test\n");
	_delay_ms(1000);
	uint8_t data = MyI2CEEPROM_test(0b10100000, 0x65);
	if (data == 0x65) {
		data = MyI2CEEPROM_test(0b10100010, 0x99);
		if (data == 0x99) {
			LCD_print_string("OK");
		}
		else {
			LCD_print_string("FAILED EEPROM 2");
		}
	}
	else {
		LCD_print_string("FAILED EEPROM 1");
	}
	char *s = (char *)malloc (16 * sizeof(char));
    while(1)
    {
		int dist  = (int) MyHCSR04_measure_pulse();
		sprintf(s, "D: %d", dist);
		LCD_clear();
		LCD_print_string(s);
       _delay_ms(500);
    }
}