
/*****************************************/
/*             LCD APP                   */
/*             PINS                      */
/*
 0: D4
 1: D5
 2: D6
 3: D7
 4: EN
 5: R/W
 6: RS
 */


#pragma once

#ifndef __MYLCD_H_
#define __MYLCD_H_

#include <avr/io.h>
#include <util/delay.h>
#include <avr/power.h>
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>

void LCD_init(volatile uint8_t *p_port);
void LCD_send_char(char p_byte, char direction);
void LCD_gotoxy(unsigned char x, unsigned char y);
void LCD_print_string(char* s);
void LCD_clear();

// Make sure init is called before this

void LCD_test20x4();

#endif
