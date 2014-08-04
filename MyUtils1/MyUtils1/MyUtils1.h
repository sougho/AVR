/*
 * MyUtils1.h
 *
 * Created: 7/29/2014 10:50:01 AM
 *  Author: soumegho
 */ 


#ifndef MYUTILS1_H_
#define MYUTILS1_H_

void UART_init(unsigned int baud_rate);
void UART_send_char(unsigned char c);
void UART_print_line(char *line);
float pin_high_time(volatile uint8_t * port, uint8_t pin, float unit_time_tick);




#endif /* MYUTILS1_H_ */