/*
#include "MCAL/micro_config.h"
#include "HAL/LCD/LCD.h"
#include "MCAL/SPI/SPI.h"

int main(void)
{
    // welcomescreen()
    // IdLEscreen()
    SPI_InitMaster();
    TC72_Init();
    LCD_Init();

    while (1)
    {
        uint8 str[6];
        LCD_Print(TC72_getTemp(str));
        LCD_DispChar('E');
        _delay_ms(10);
        LCD_clearscreen();
        _delay_ms(10);
    }

    return 0;
}

 */