/*
 * MyApp1.c
 *
 * Created: 7/29/2014 10:41:58 AM
 *  Author: soumegho
 */ 

/*
 Connection: 
 PA0: D4
 PA1: D5
 PA2: D6
 PA3: D7
 PA4: EN
 PA5: R/W
 PA6: RS
 
 */

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include "MyLCD.h"

volatile uint8_t * port = 0;
volatile uint8_t * ddr = 0;
volatile uint8_t * in = 0;

#define PIN_EN 4
#define PIN_RW 5
#define PIN_RS 6

void LCD_init(volatile uint8_t *p_port) {
	_delay_ms(1000);
	port = p_port;
	ddr = p_port -1;
	in = p_port - 2;
	*ddr = 0xff;
	*port &= ~(1 << PIN_EN);
	LCD_send_char(0x33, 1);
	LCD_send_char(0x32, 1);
	LCD_send_char(0x2c, 1);
	LCD_send_char(0x0e, 1);
	LCD_send_char(0x01, 1);
	LCD_send_char(0x06, 1);
}

void LCD_send_char(char p_byte, char cmd_or_data) {
	
	*port = (p_byte  >> 4);
	
	if (cmd_or_data)
		*port &= ~(1 << PIN_RS); // RS=0
	else
		*port |= (1 << PIN_RS); // RS=1
	*port &= ~(1 << PIN_RW); // R/W=0
	
	*port |= (1 <<  PIN_EN); // EN = 1;
	_delay_us(2);
	*port &= ~(1 << PIN_EN); // High to low to EN
	_delay_us(1000);
	
	*port = (*(in) & 0xf0) | (p_byte & 0x0f);
	
	/*
	if (cmd_or_data)
		*port &= ~(1 << PIN_RS); // RS=0
	else
		*port |= (1 << PIN_RS); // RS=1
	*port &= ~(1 << PIN_RW); // R/W=0
	*/
	
	*port |= (1 <<  PIN_EN); // EN = 1;
	
	_delay_us(2);
	*port &= ~(1 << PIN_EN); // High to low to EN
	_delay_ms(10);
}

void LCD_print_string(char* s) {
	while (*s != 0) {
		LCD_send_char(*s++, 0);
	}
}

void LCD_gotoxy(unsigned char x, unsigned char y) {
	
	unsigned char first_char_addr[] = {0x80, 0xc0, 0x94, 0xd4};
	LCD_send_char(first_char_addr[y-1] + x -1, 1);
	_delay_us(100);
}

void LCD_clear() {
	LCD_send_char(0x01, 1);
}


void LCD_test20x4() {
	LCD_clear();
	LCD_gotoxy(1,1);
	LCD_print_string("Hattima Tim Tim");
	LCD_gotoxy(1,2);
	LCD_print_string("Tara Mathe Pare Dim");
	LCD_gotoxy(1,3);
	LCD_print_string("Tader Khara 2to Sing");
	LCD_gotoxy(1,4);
	LCD_print_string("Tara Hattima tim tim");
}