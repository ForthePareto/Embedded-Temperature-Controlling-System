#ifndef LCD_H
#define LCD_H

#include "DIO.h"
#include "common_macros.h"
#include "registers.h"
#include "std_types.h"
#include <util/delay.h>

#define CLR_SCREEN           0X01
#define DISPLAY_ON_CURSOR_ON 0X0E
#define FOUR_BIT_MODE_I      0X02
#define FOUR_BIT_MODE_II     0X28

#define LCD_PORT             'C'

#define LCD_RS               0
#define LCD_E                1

#define LCD_D4               2
#define LCD_D5               3
#define LCD_D6               4
#define LCD_D7               5

void LCD_Init(void);
void LCD_SendCommand(uint8);
void LCD_DispChar(uint8);
void LCD_Print(uint8 *);
void LCD_goto(uint8, uint8);
void LCD_clearscreen(void);

// todo: make Disp Manager service
void animateWelcome(void);

#endif  // LCD_H
