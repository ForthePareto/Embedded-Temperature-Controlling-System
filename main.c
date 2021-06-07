#include "MCAL/micro_config.h"

#include "HAL/LCD/LCD.h"


int main(void)
{

    // welcomescreen()
    // IdLEscreen()
    _delay_ms(200);
    LCD_Init();

    while(1)
    {
        LCD_DispChar('A');
        _delay_ms(1000);
        LCD_DispChar('B');
    }

    return 0;
}



