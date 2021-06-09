#include "KEYPAD.h"

void KEYPAD_Init(void)
{
    // Col.s are init. with the interrupt no need to bother with them (if INTS are initialized)
    // for Rows (init as outputs)
    DIO_setPINDir('D', R0, 1);
    DIO_setPINDir('D', R1, 1);
    DIO_setPINDir('D', R2, 1);
    DIO_setPINDir('D', R3, 1);

    // Clear all Rows
    DIO_write('D', R0, 0);
    DIO_write('D', R1, 0);
    DIO_write('D', R2, 0);
    DIO_write('D', R3, 0);
}

uint8 KeyPad_GetKeyC0(void)
{
    uint8 Rows[] = {R0, R1, R2, R3};
    uint8 Values[] = {'1', '4', '7', '*'};
    uint8 PressedKey = 'F';

    uint8 itr = 0;
    uint8 found = 0;
    while ((found == 0) & (itr < 4))
    {
        DIO_write('D', Rows[itr], 1);
        if(DIO_readPin('D',2) == 1)
        {
            PressedKey = Values[itr];
            found = 1;
        }
        DIO_write('D', Rows[itr], 0);
        itr += 1;
    }
    return PressedKey;
}

uint8 KeyPad_GetKeyC1(void)
{
    uint8 Rows[] = {R0, R1, R2, R3};
    uint8 Values[] = {'2', '5', '8', '0'};
    uint8 PressedKey = 'F';

    uint8 itr = 0;
    uint8 found = 0;
    while ((found == 0) & (itr < 4))
    {
        DIO_write('D', Rows[itr], 1);
        if(DIO_readPin('D',3) == 1)
        {
            PressedKey = Values[itr];
            found = 1;
        }
        DIO_write('D', Rows[itr], 0);
        itr += 1;
    }
    return PressedKey;
}

uint8 KeyPad_GetKeyC2(void)
{
    uint8 Rows[] = {R0, R1, R2, R3};
    uint8 Values[] = {'3', '6', '9', '#'};
    uint8 PressedKey = 'F';

    uint8 itr = 0;
    uint8 found = 0;
    while ((found == 0) & (itr < 4))
    {
        DIO_write('D', Rows[itr], 1);
        if(DIO_readPin('B',2) == 1)
        {
            PressedKey = Values[itr];
            found = 1;
        }
        DIO_write('D', Rows[itr], 0);
        itr += 1;
    }
    return PressedKey;
}
