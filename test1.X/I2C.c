#include<p18f2550.h>
#include "Uart.h"

unsigned char is_initialized = 0;

void i2c_wait() {
    while ((SSPCON2 & 0x1F ) || ( SSPSTAT & 0x04 ) );
}

void i2c_ack() {
    ACKDT = 0;
    ACKEN = 1;
    while (ACKEN);
}

void i2c_nack() {
    ACKDT = 1;
    ACKEN = 1;
    while (ACKEN);
}

void i2c_init() {

    if (is_initialized == 1) return;

    is_initialized = 1;
    // Enable SSP

     
    SSPSTAT |= 0x80;
    SSPCON1bits.SSPEN = 1;

    // Mode Select : 1000 (Master)
    // clock = Fosc/(4 * (SSPADD +1))

    /*
    SSPCON1bits.SSPM3 = 1;
    SSPCON1bits.SSPM2 = 0;
    SSPCON1bits.SSPM1 = 0;
    SSPCON1bits.SSPM0 = 0;
    */
    SSPCON1 = 0x28;

    // Clock = 100Khz

    SSPADD = 0x28;

    uart_printline("Initialized");

}

void i2c_start() {

    
    // Set Start Condition
    SSPIF = 0;
    SSPCON2bits.SEN = 1;
    // Check for completion
    
    //while (SSPCON2bits.SEN);
    while (SSPIF == 0);
    SSPIF =0; 
}

void i2c_repeated_start() {
    SSPIF = 0;
    SSPCON2bits.RSEN = 1;
    //while (SSPCON2bits.RSEN);
    while (SSPIF == 0);
    SSPIF =0;
}

void i2c_stop() {
    SSPIF = 0;
    SSPCON2bits.PEN = 1;
    //while (SSPCON2bits.PEN == 0);
    while (SSPIF == 0);
    SSPIF =0;
    i2c_wait();
}

unsigned char i2c_send_byte(unsigned char byte) {
    SSPIF = 0;
    SSPBUF = byte;
    //while (BF);
    while (SSPIF == 0);
    SSPIF =0;
    i2c_wait();
    return (SSPCON2bits.ACKSTAT == 1 ? 1 : 0);
}
unsigned char i2c_receive_byte() {
    // Receive Enalbe
    unsigned char ch;
    SSPIF = 0;
    SSPCON2bits.RCEN = 1;
    //while (!BF);
    while (SSPIF == 0);
    SSPIF =0;
    ch = SSPBUF;
    i2c_wait();
    return ch;
}

unsigned char i2c_receive_byte_with_ack() {
    // Receive Enalbe
    unsigned char ch;
    SSPCON2bits.RCEN = 1;
    while (!BF);
    ch = SSPBUF;
    i2c_wait();
    i2c_ack();
    return ch;
}

unsigned char i2c_receive_byte_wo_ack() {
    // Receive Enalbe
    unsigned char ch;
    SSPCON2bits.RCEN = 1;
    while (!BF);
    ch = SSPBUF;
    i2c_wait();
    i2c_nack();
    return ch;
}


