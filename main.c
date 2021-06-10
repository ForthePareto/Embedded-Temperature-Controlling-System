#include "MCAL/micro_config.h"

// SCREEN macros
#define WELCOME   0
#define IDLE      1

// STATE macros
#define STATE_STANDBY   0
#define STATE_OPERATION 1
#define STATE_NORMAL    2
#define STATE_ERROR     3

volatile uint8 usrInput[2] = "00";
volatile uint8 setTemp[2] = "25"; //default 25
uint8 crTemp[2] = "FF";
volatile uint8 Compare[2] = "25";
volatile uint8 idx = 0x00;

volatile uint8 pressedBtn = 'F';

volatile uint8 STATE = 0;
volatile uint8 SCREEN = 0;

void updateTemp(void);

int main(void)
{
    KEYPAD_Init();
    TC72_Init();
    DISPLAY_Init();

    // DISPLAY_Welcome();
    DSPLAY_IDLEscreen((uint8*)setTemp, (uint8)STATE, crTemp);
    while (1)
    {
        if(STATE == STATE_OPERATION)
        {
            updateTemp();
            _delay_ms(200);
        }
    }

    return 0;
}

void updateTemp(void)
{
    TC72_getTemp();
    if((crTemp[0] != Compare[0]) || (crTemp[1] != Compare[1]))
    {
        Compare[0] = crTemp[0];
        Compare[1] = crTemp[1];
        DSPLAY_IDLEscreen((uint8*)setTemp, (uint8)STATE, crTemp);
    }
}

// MISRA :warning 601: expected a type, int assumed [MISRA 2004 Rule 8.2, required]
// MISRA :warning 533: function 'ISR' should return a value [MISRA 2004 Rule 16.8, required]
ISR(INT0_vect)
{
    pressedBtn = KeyPad_GetKeyC0();
    if((pressedBtn == '*') && (STATE == STATE_OPERATION))
    {
        if(idx == 1)
        {
            setTemp[0] = '0';
            setTemp[1] = usrInput[0];
            TOGGLE_BIT(idx, 0);
            DSPLAY_IDLEscreen((uint8*)setTemp, (uint8)STATE, crTemp);
        }
        else if(idx == 0)
        {
            setTemp[0] = usrInput[0];
            setTemp[1] = usrInput[1];
            DSPLAY_IDLEscreen((uint8*)setTemp, (uint8)STATE, crTemp);
        }
    }
    else if (STATE == STATE_OPERATION)    
    {
        usrInput[idx] = pressedBtn;
        TOGGLE_BIT(idx, 0);
    }
}

// MISRA :error 31: redefinition of symbol 'ISR'
ISR(INT1_vect)
{
    if(STATE == STATE_OPERATION)
    {
        pressedBtn = KeyPad_GetKeyC1();
        usrInput[idx] = pressedBtn;
        TOGGLE_BIT(idx, 0);
    }
    
}

ISR(INT2_vect)
{
    pressedBtn = KeyPad_GetKeyC2();
    if(pressedBtn == (uint8)'#')
    {
        if(STATE == STATE_STANDBY)
        {
            STATE = (uint8)STATE_OPERATION;
        }
        else if(STATE == STATE_OPERATION)
        {
            STATE = (uint8)STATE_STANDBY;
        }
        DSPLAY_IDLEscreen((uint8*)setTemp, (uint8)STATE, crTemp);
    }
    else if(STATE == STATE_OPERATION)
    {
        usrInput[idx] = pressedBtn;
        TOGGLE_BIT(idx, 0);
    }
}
