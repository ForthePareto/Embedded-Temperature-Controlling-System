#ifndef TC72_H
#define TC72_H

#include "../../MCAL/SPI/SPI.h"

extern uint8 crTemp[2];

// todo: make a TC72 service
void TC72_Init(void);
void TC72_getTemp(void);
uint8 convertIntChar(uint8 num);
uint8 convertCharInt(uint8 character);

#endif //TC72_H