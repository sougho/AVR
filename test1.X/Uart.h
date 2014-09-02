/* 
 * File:   Uart.h
 * Author: ramtaru
 *
 * Created on August 29, 2014, 6:34 PM
 */

#ifndef UART_H
#define	UART_H

#ifdef	__cplusplus
extern "C" {
#endif

void uart_init();
void uart_sendbyte(unsigned char ch);
unsigned char uart_readbyte();
void uart_printline(unsigned char *line);



#ifdef	__cplusplus
}
#endif

#endif	/* UART_H */

