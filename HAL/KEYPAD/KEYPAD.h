#ifndef KEYPAD_H
#define KEYPAD_H

#include "../../MCAL/micro_config.h"
#include "../../MCAL/DIO/DIO.h"

#define R0 4
#define R1 5
#define R2 6
#define R3 7

void KEYPAD_Init(void);
uint8 KeyPad_GetKeyC0(void);
uint8 KeyPad_GetKeyC1(void);
uint8 KeyPad_GetKeyC2(void);

#endif  // KEYPAD_H
