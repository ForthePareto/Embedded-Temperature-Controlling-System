#ifndef __AVR_ATmega32__
    #define __AVR_ATmega32__
#endif

#ifndef F_CPU
    #define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>

void ADC_Init();

int ADC_Read(char);