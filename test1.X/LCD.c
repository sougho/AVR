/*
 * LCD Library for JHD204A
 * 20x4
 * NOTE: Uses Timer 2
 */

#include <stdio.h>
#include <stdlib.h>
#include<p18f2550.h>

#define COMMAND 1
#define DATA 0

void timer2_delay_us(int us);
void timer2_init_for_delay_us();

void lcd_send_char(unsigned char c, char flag) {

    // Send high byte
    LATA = (c >> 4);
    if (flag  == COMMAND) {
        LATBbits.LB7 = 0;
    } else {
        LATBbits.LB7 = 1;
    }
    LATBbits.LB6 = 0;

    LATBbits.LB5 = 1;
    timer2_delay_us(2);
    LATBbits.LB5 = 0;
    timer2_delay_us(1000);
    // Send Low Byte
    LATA = 0x0F & c;
    LATBbits.LB5 = 1;
    timer2_delay_us(2);
    LATBbits.LB5 = 0;
    timer2_delay_us(4000);
}

void lcd_init() {

    TRISBbits.RB7 = 0; //RS
    TRISBbits.RB6 = 0; //R/W
    TRISBbits.RB5 = 0; //EN

    TRISAbits.RA0 = 0; //DB4
    TRISAbits.RA1 = 0; //DB5
    TRISAbits.RA2 = 0; //DB6
    TRISAbits.RA3 = 0; //DB7
    // Set EN = 0
    LATBbits.LATB5 = 0;
    timer2_init_for_delay_us();
    lcd_send_char(0x33, 1);
    lcd_send_char(0x32, 1);
    lcd_send_char(0x2c, 1);
    lcd_send_char(0x0e, 1);
    lcd_send_char(0x01, 1);
    lcd_send_char(0x06, 1);
}

void lcd_print_string(char* s) {
	while (*s != 0) {
		lcd_send_char(*s++, 0);
	}
}