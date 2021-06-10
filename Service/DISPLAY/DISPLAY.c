#include "DISPLAY.h"

void DISPLAY_Init(void)
{
    LCD_Init();
}

void DISPLAY_Welcome(void)
{
    LCD_clearscreen();
    LCD_SendCommand(0x0c);
    for (uint8 itr = 0; itr < 16; itr++)
    {
        LCD_SendCommand(DECREMENT_CURSOR);
    }
    LCD_DispChar('W');
    LCD_SendCommand(SHIFT_LEFT);
    //LCD_SendCommand(0x14);
    LCD_DispChar('E');
    LCD_SendCommand(SHIFT_LEFT);
    _delay_ms(100);
    LCD_DispChar('L');
    LCD_SendCommand(SHIFT_LEFT);
    _delay_ms(100);
    LCD_DispChar('C');
    LCD_SendCommand(SHIFT_LEFT);
    _delay_ms(100);
    LCD_DispChar('O');
    LCD_SendCommand(SHIFT_LEFT);
    _delay_ms(100);
    LCD_DispChar('M');
    LCD_SendCommand(SHIFT_LEFT);
    _delay_ms(100);
    LCD_DispChar('E');
    LCD_SendCommand(SHIFT_LEFT);
    _delay_ms(100);
    for (uint8 i = 0; i < 3; i++)
    {
        for (uint8 itr = 0; itr < 9; itr++)
        {
            LCD_SendCommand(SHIFT_LEFT);
            _delay_ms(100);
        }
        for (uint8 itr = 0; itr < 9; itr++)
        {
            LCD_SendCommand(SHIFT_RIGHT);
            _delay_ms(100);
        }
    }
    LCD_SendCommand(DISPLAY_ON_CURSOR_ON);
}

void DSPLAY_IDLEscreen(uint8 * defTemp, uint8 STATE, uint8 * crTemp)
{
    LCD_clearscreen();
    LCD_Print((uint8 *)"SET:");
    LCD_PrintString((uint8 *)defTemp,2);
    for (uint8 itr = 0; itr < 4;itr++)
    {
        LCD_SendCommand(SHIFT_CURSOR_RIGHT);
    }
    LCD_Print((uint8 *)"CRT:");
    LCD_PrintString((uint8 *)crTemp,2);
    LCD_SendCommand(FORCE_ROW1);
    LCD_Print((uint8 *)"STATE:");
    DISPLAY_PrintSTATE(STATE);
}

void DISPLAY_PrintSTATE(uint8 state)
{
    switch (state)
    {
    case 0:
        LCD_Print((uint8 *)"STANDBY");
        break;
    
    case 1:
        LCD_Print((uint8 *)"OPERATION");
        break;

    case 2:
        LCD_Print((uint8 *)"NORMAL");
        break;

    case 3:
        LCD_Print((uint8 *)"ERROR");
        break;

    default:
        break;
    }
}