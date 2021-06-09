#ifndef TC72_H
#define TC72_H

#include"std_types.h"
#include"SPI.h"

// todo: make a TC72 service
void TC72_Init(void);
uint8 * TC72_getTemp(uint8 *);
uint8 convertIntChar(uint8 num);

#endif //TC72_H