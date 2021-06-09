/*
#include "micro_config.h"

// SCREEN macros
#define WELCOME   0
#define IDLE      1

// STATE macros
#define STANDBY   0
#define OPERATION 1
#define NORMAL    2
#define ERROR     3

uint8 *defTemp = (uint8*)"25";

volatile uint8 STATE = 0;
volatile uint8 SCREEN = 0;

int main(void)
{
    Interrupt_Init();
    KEYPAD_Init();
    SPI_InitMaster();
    TC72_Init();
    LCD_Init();

    // WELCOME
    DISPLAY_Welcome();
    while (1)
    {
        // IdLEscreen()
        DSPLAY_IDLEscreen((uint8*)defTemp, (uint8)STATE);
        _delay_ms(100);
    }

    return 0;
}

ISR(INT0_vect)
{
    LCD_clearscreen();
    LCD_DispChar(KeyPad_GetKeyC0());
    STATE = OPERATION;
}

ISR(INT1_vect)
{
	LCD_clearscreen();
    LCD_DispChar(KeyPad_GetKeyC1());
    STATE = OPERATION;
}

ISR(INT2_vect)
{
    LCD_clearscreen();
    LCD_DispChar(KeyPad_GetKeyC2());
    STATE = OPERATION;
}

 */