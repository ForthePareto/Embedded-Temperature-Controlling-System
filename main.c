/*
#include "MCAL/micro_config.h"
#include "HAL/LCD/LCD.h"

void animateWelcome(void);

int main(void)
{

    // welcomescreen()
    // IdLEscreen()
    _delay_ms(15);
    LCD_Init();


        // LCD_DispChar('A');
        // LCD_Print((uint8 *)"bit math > linear algebra");
        // LCD_SendCommand(0xc0);
        // LCD_Print((uint8 *)"bit math > linear algebra");
        // _delay_ms(1000);
        // LCD_clearscreen();
        // LCD_DispChar('B');
        // _delay_ms(100);
        // LCD_clearscreen();
        // animateWelcome();

    return 0;
}

void animateWelcome(void)
{
    LCD_clearscreen();
    LCD_SendCommand(0x0c);
    for (uint8 itr = 0; itr < 16; itr++)
    {
        LCD_SendCommand(0x14);
    }
    LCD_DispChar('W');
    LCD_SendCommand(0x18);
    //LCD_SendCommand(0x14);
    LCD_DispChar('E');
    LCD_SendCommand(0x18);
    _delay_ms(10);
    LCD_DispChar('L');
    LCD_SendCommand(0x18);
    _delay_ms(10);
    LCD_DispChar('C');
    LCD_SendCommand(0x18);
    _delay_ms(10);
    LCD_DispChar('O');
    LCD_SendCommand(0x18);
    _delay_ms(10);
    LCD_DispChar('M');
    LCD_SendCommand(0x18);
    _delay_ms(10);
    LCD_DispChar('E');
    LCD_SendCommand(0x18);
    _delay_ms(10);
    for (uint8 i = 0; i < 3; i++)
    {
        for (uint8 itr = 0; itr < 9; itr++)
        {
            LCD_SendCommand(0x18);
            _delay_ms(10);
        }
        for (uint8 itr = 0; itr < 9; itr++)
        {
            LCD_SendCommand(0x1c);
            _delay_ms(10);
        }
    }
    LCD_SendCommand(0x0e);
} 

 */