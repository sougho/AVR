
#ifndef F_CPU
#define F_CPU 16000000UL
#endif


#include "MySerial.h"

void UART_init(unsigned int baud_rate) {
	UBRRH = (unsigned char) baud_rate >> 8;
	UBRRL = (unsigned char) baud_rate;
	
	UCSRB = (1<<RXEN) | (1<<TXEN);
	
	UCSRC = (1<<URSEL)  | (0 << USBS) | (3<<UCSZ0);
}

void UART_send_char(unsigned char c) {
	while (!(UCSRA & (1<<UDRE)));
	UDR = c;
}

void UART_print_line(char *line) {
	
	while (*line != 0) {
		UART_send_char(*line++);
	}
}
