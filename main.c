/*
#include "micro_config.h"


int main(void)
{
    Interrupt_Init();
    KEYPAD_Init();
    SPI_InitMaster();
    TC72_Init();
    LCD_Init();

    // welcomescreen()
    // IdLEscreen()
    while (1)
    {

    }

    return 0;
}

ISR(INT0_vect)
{
    LCD_clearscreen();
    LCD_DispChar(KeyPad_GetKeyC0());
}

ISR(INT1_vect)
{
	LCD_clearscreen();
    LCD_DispChar(KeyPad_GetKeyC1());
}

ISR(INT2_vect)
{
    LCD_clearscreen();
    LCD_DispChar(KeyPad_GetKeyC2());
}

 */