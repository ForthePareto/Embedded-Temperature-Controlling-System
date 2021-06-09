#include "MCAL/micro_config.h"

// SCREEN macros
#define WELCOME   0
#define IDLE      1

// STATE macros
#define STANDBY   0
#define OPERATION 1
#define NORMAL    2
#define ERROR     3

volatile uint8 defTemp[2] = "25";
uint8 crTemp[2] = "00";
volatile uint8 Compare[2] = "25";
volatile uint8 idx = 0x00;

volatile uint8 STATE = 0;
volatile uint8 SCREEN = 0;

void compareTemp(void);

int main(void)
{
    KEYPAD_Init();
    TC72_Init();
    DISPLAY_Init();

    while (1)
    {
        
        compareTemp();
		_delay_ms(200);
    }

    return 0;
}

void compareTemp(void)
{
    TC72_getTemp((uint8 *)crTemp);
    if((crTemp[0] != Compare[0]) & (crTemp[1] != Compare[1]))
    {
        Compare[0] = crTemp[0];
        Compare[1] = crTemp[1];
        DSPLAY_IDLEscreen((uint8*)defTemp, (uint8)STATE, crTemp);

    }
}

ISR(INT0_vect)
{
    defTemp[idx] = KeyPad_GetKeyC0();
    if(idx == 1) DSPLAY_IDLEscreen((uint8*)defTemp, (uint8)STATE, crTemp);
    TOGGLE_BIT(idx, 0);
    STATE = (uint8)OPERATION;
}

ISR(INT1_vect)
{
    defTemp[idx] = KeyPad_GetKeyC1();
    if(idx == 1) DSPLAY_IDLEscreen((uint8*)defTemp, (uint8)STATE, crTemp);
    TOGGLE_BIT(idx, 0);
    STATE = (uint8)OPERATION;
}

ISR(INT2_vect)
{
    defTemp[idx] = KeyPad_GetKeyC2();
    if(idx == 1) DSPLAY_IDLEscreen((uint8*)defTemp, (uint8)STATE, crTemp);
    TOGGLE_BIT(idx, 0);
    STATE = (uint8)OPERATION;
}