#ifndef __AVR_ATmega32__
    #define __AVR_ATmega32__
#endif

#ifndef F_CPU
    #define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>

#define LCD_DIR  DDRB
#define LCD_PORT PORTB
#define RS       PB0
#define EN       PB1

void LCD_Command(unsigned char);

void LCD_Char(unsigned char);

void LCD_Init(void);

void LCD_String(char *);

void LCD_String_XY(char, char, char *);

void LCD_Clear();