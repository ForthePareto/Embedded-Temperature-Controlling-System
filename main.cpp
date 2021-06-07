#include <micro_config.h>

#include "LCD.h"


int main(void)
{

    // welcomescreen()
    // IdLEscreen()
    _delay_ms(10);
    LCD_Init();

    while(1)
    {
        LCD_DispChar('A');
        _delay_ms(1000);
        LCD_DispChar('B');
    }

    return 0;
}
