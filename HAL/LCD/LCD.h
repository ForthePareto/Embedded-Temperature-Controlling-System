#ifndef LCD_H
#define LCD_H


#include "../../MCAL/micro_config.h"

#include "../../MCAL/DIO/DIO.h"


#define CLR_SCREEN           0X01
#define RETURN_HOME          0X02
#define DECREMENT_CURSOR     0X04
#define INCREMENT_CURSOR     0X06
#define DISPLAY_ON_CURSOR_ON 0X0E
#define SHIFT_CURSOR_LEFT    0X10
#define SHIFT_CURSOR_RIGHT   0X15
#define SHIFT_LEFT           0X18
#define SHIFT_RIGHT          0X1c
#define FORCE_ROW1           0Xc0
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

#endif  // LCD_H
