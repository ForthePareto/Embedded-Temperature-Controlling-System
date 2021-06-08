#include "ADC.h"

void ADC_Init() {
    DDRA = 0x0;
    ADCSRA = 0x87;
    ADMUX = 0x40;
}

int ADC_Read(uint8 channel) {
    uint16 Ain, AinLow;

    ADMUX = ADMUX | (channel & 0x0f);

    ADCSRA |= (1 << ADSC);

    while ((ADCSRA & (1 << ADIF)) == 0) {}

    _delay_us(10);
    AinLow = (uint16)ADCL;
    Ain = (uint16)ADCH * 256;
    Ain = Ain + AinLow;
    return (Ain);
}
