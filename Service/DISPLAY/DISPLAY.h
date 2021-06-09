#ifndef DISPLAY_H
#define DISPLAY_H


#include "../../MCAL/micro_config.h"

#include "../../HAL/LCD/LCD.h"
#include "../TC72/TC72.h"


void DISPLAY_Welcome(void);
void DSPLAY_IDLEscreen(uint8 * defTemp, uint8 STATE);
void DISPLAY_PrintSTATE(uint8 state);

#endif  // DISPLAY_H
