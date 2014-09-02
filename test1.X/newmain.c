#include <stdio.h>
#include <stdlib.h>
#include<p18f2550.h>

#include "Eeprom.h"
#include "Uart.h"
#include "usb.h"

/*
#pragma config PLLDIV    = 5
#pragma config CPUDIV   = OSC2_PLL3
#pragma config FOSC        = INTOSC_HS
*/

// 4 Mhz crystal, plldiv: 000, cpudiv: 11
// USB: 48 MHZ, System clock: 16 Mhz
#pragma config CONFIG1L = 0x30; // 0b00110000
#pragma config CONFIG1H = 0X02; // 0b00000010

#pragma config WDT         = OFF
#pragma config LVP           = OFF
#pragma config BOR          = OFF
#pragma config MCLRE     = ON
#pragma config PWRT        = ON
#pragma config PBADEN   = OFF
#pragma config VREGEN = ON


volatile char oneSecTick = 0;

// Timer Utilities
void delay_onesec_int();

void lcd_print_string(char* s);
void lcd_init();

void delayz(void)
{
   int i, j;
   for(i=0;i<300;i++)
      {
                for(j=0;j<10;j++)
            {   /**Some delay***/   }
      }
}

void main(void)
 {
   //TRISB = 0;
    TRISBbits.TRISB4 = 0;
   uart_init();
   ei();
   delay_onesec_int();
   LATBbits.LATB4=0; 
   oneSecTick = 1;
   delay_onesec();
   i2c_init();
   lcd_init();
   lcd_print_string((unsigned char*)"Sarbani i Ghosh");

   /*
    * USB Setup
    */

   uart_printline("\nSetting up usb");
   usb_init();
   while(1)
   {
       /*
       if (oneSecTick == 1) {
           oneSecTick = 0;
           LATBbits.LATB4 = 1 ^ PORTBbits.RB4;
           uart_printline((unsigned char*)"Ghosh\r\n");
           lcd_init();
           lcd_print_string((unsigned char*)"Sarbani i Ghosh");
           i2c_start();
           eep_write(0b10100010, 0x0000, 'b');
           delayz();
           eep_write(0b10100010, 0x0001, 'o');
           delayz();
           eep_write(0b10100010, 0x0002, 'u');
           delayz();
           unsigned char byte1 = eep_read(0b10100010, 0x0000);
           unsigned char byte2 = eep_read(0b10100010, 0x0001);
           unsigned char byte3 = eep_read(0b10100010, 0x0002);
           uart_printline("\r\n--\r\n");
           uart_sendbyte(byte1);
           uart_sendbyte(byte2);
           uart_sendbyte(byte3);
           uart_printline("\r\n--\r\n");
            
       }
       */
    }
}

/* THE END */

