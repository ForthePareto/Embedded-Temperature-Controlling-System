#ifndef ADC_H
#define ADC_H

#ifndef __AVR_ATmega32__
    #define __AVR_ATmega32__
#endif

#ifndef F_CPU
    #define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>

#include "../../MCAL/DIO/DIO.h"
#include "../../MCAL/common_macros.h"
#include "../../MCAL/registers.h"
#include "../../MCAL/std_types.h"

void ADC_Init();

int ADC_Read(uint8);

#endif
