#ifndef DISPLAY_H
#define DISPLAY_H

#include "../../HAL/LCD/LCD.h"

void DISPLAY_Init(void);
void DISPLAY_Welcome(void);
void DSPLAY_IDLEscreen(uint8 * setTemp, uint8 STATE, uint8 * crTemp);
void DISPLAY_PrintSTATE(uint8 state);

#endif  // DISPLAY_H