#include "DIO.h"

void DIO_setPINDir(uint8 portname, uint8 pinnumber, uint8 direction) {
    switch (portname) {
        case 'A':
            // MISRA :note 9225: integral expression of underlying type 'signed char' cannot be implicitly converted to type 'uint8' (aka 'unsigned char') because it is not a wider integer type of the same signedness [MISRA 2004 Rule 10.1, required]
            //#1393-D (MISRA-C:2004 10.1/R) The value of an expression of integer type shall not be implicitly converted to a different underlying type if it is not a conversion to a wider integer type of the same signedness
            if (direction == (uint8)1) {
                //#1400-D (MISRA-C:2004 11.3/A) A cast should not be performed between a pointer type and an integral type
                SET_BIT(DDRA, pinnumber);  //Set the direction of the given pin in port A as output
            } else {
                //#1397-D (MISRA-C:2004 10.5/R) If the bitwise operators ~ and << are applied to an operand of underlying type unsigned char or unsigned short, the result shall be immediately cast to the underlying type of the operand
                //#1400-D (MISRA-C:2004 11.3/A) A cast should not be performed between a pointer type and an integral type
                CLEAR_BIT(DDRA, pinnumber);  //Set the direction of the given pin in port A as input
            }
            break;
        case 'B':
            // #1393-D (MISRA-C:2004 10.1/R) The value of an expression of integer type shall not be implicitly converted to a different underlying type if it is not a conversion to a wider integer type of the same signedness
            if (direction == (uint8)1) {
                //#1400-D (MISRA-C:2004 11.3/A) A cast should not be performed between a pointer type and an integral type
                SET_BIT(DDRB, pinnumber);  //Set the direction of the given pin in port B as output
            } else {
                //#1397-D (MISRA-C:2004 10.5/R) If the bitwise operators ~ and << are applied to an operand of underlying type unsigned char or unsigned short, the result shall be immediately cast to the underlying type of the operand
                //#1400-D (MISRA-C:2004 11.3/A) A cast should not be performed between a pointer type and an integral type
                CLEAR_BIT(DDRB, pinnumber);  //Set the direction of the given pin in port B as input
            }
            break;
        case 'C':
            // #1393-D (MISRA-C:2004 10.1/R) The value of an expression of integer type shall not be implicitly converted to a different underlying type if it is not a conversion to a wider integer type of the same signedness
            if (direction == (uint8)1) {
                //#1400-D (MISRA-C:2004 11.3/A) A cast should not be performed between a pointer type and an integral type
                SET_BIT(DDRC, pinnumber);  //Set the direction of the given pin in port C as output
            } else {
                //#1397-D (MISRA-C:2004 10.5/R) If the bitwise operators ~ and << are applied to an operand of underlying type unsigned char or unsigned short, the result shall be immediately cast to the underlying type of the operand
                //#1400-D (MISRA-C:2004 11.3/A) A cast should not be performed between a pointer type and an integral type
                CLEAR_BIT(DDRC, pinnumber);  //Set the direction of the given pin in port C as input
            }
            break;
        case 'D':
            // #1393-D (MISRA-C:2004 10.1/R) The value of an expression of integer type shall not be implicitly converted to a different underlying type if it is not a conversion to a wider integer type of the same signedness
            if (direction == (uint8)1) {
                //#1400-D (MISRA-C:2004 11.3/A) A cast should not be performed between a pointer type and an integral type
                SET_BIT(DDRD, pinnumber);  //Set the direction of the given pin in port D as output
            } else {
                //#1397-D (MISRA-C:2004 10.5/R) If the bitwise operators ~ and << are applied to an operand of underlying type unsigned char or unsigned short, the result shall be immediately cast to the underlying type of the operand
                //#1400-D (MISRA-C:2004 11.3/A) A cast should not be performed between a pointer type and an integral type
                CLEAR_BIT(DDRD, pinnumber);  //Set the direction of the given pin in port D as input
            }
            break;
        default:
            break;
    }
}

void DIO_write(uint8 portname, uint8 pinnumber, uint8 outputvalue) {
    switch (portname) {
        case 'A':
            // #1393-D (MISRA-C:2004 10.1/R) The value of an expression of integer type shall not be implicitly converted to a different underlying type if it is not a conversion to a wider integer type of the same signedness
            if (outputvalue == (uint8)1) {
                //#1400-D (MISRA-C:2004 11.3/A) A cast should not be performed between a pointer type and an integral type
                SET_BIT(PORTA, pinnumber);  //Set the value of the given pin in port A as High
            } else {
                //#1397-D (MISRA-C:2004 10.5/R) If the bitwise operators ~ and << are applied to an operand of underlying type unsigned char or unsigned short, the result shall be immediately cast to the underlying type of the operand
                //#1400-D (MISRA-C:2004 11.3/A) A cast should not be performed between a pointer type and an integral type
                CLEAR_BIT(PORTA, pinnumber);  //Set the value of the given pin in port A as Low
            }
            break;
        case 'B':
            // #1393-D (MISRA-C:2004 10.1/R) The value of an expression of integer type shall not be implicitly converted to a different underlying type if it is not a conversion to a wider integer type of the same signedness
            if (outputvalue == (uint8)1) {
                //#1400-D (MISRA-C:2004 11.3/A) A cast should not be performed between a pointer type and an integral type
                SET_BIT(PORTB, pinnumber);  //Set the value of the given pin in port B as High
            } else {
                //#1397-D (MISRA-C:2004 10.5/R) If the bitwise operators ~ and << are applied to an operand of underlying type unsigned char or unsigned short, the result shall be immediately cast to the underlying type of the operand
                //#1400-D (MISRA-C:2004 11.3/A) A cast should not be performed between a pointer type and an integral type
                CLEAR_BIT(PORTB, pinnumber);  //Set the value of the given pin in port B as Low
            }
            break;
        case 'C':
            // #1393-D (MISRA-C:2004 10.1/R) The value of an expression of integer type shall not be implicitly converted to a different underlying type if it is not a conversion to a wider integer type of the same signedness
            if (outputvalue == (uint8)1) {
                //#1400-D (MISRA-C:2004 11.3/A) A cast should not be performed between a pointer type and an integral type
                SET_BIT(PORTC, pinnumber);  //Set the value of the given pin in port C as High
            } else {
                //#1397-D (MISRA-C:2004 10.5/R) If the bitwise operators ~ and << are applied to an operand of underlying type unsigned char or unsigned short, the result shall be immediately cast to the underlying type of the operand
                //#1400-D (MISRA-C:2004 11.3/A) A cast should not be performed between a pointer type and an integral type
                CLEAR_BIT(PORTC, pinnumber);  //Set the value of the given pin in port C as Low
            }
            break;
        case 'D':
            // #1393-D (MISRA-C:2004 10.1/R) The value of an expression of integer type shall not be implicitly converted to a different underlying type if it is not a conversion to a wider integer type of the same signedness
            if (outputvalue == (uint8)1) {
                //#1400-D (MISRA-C:2004 11.3/A) A cast should not be performed between a pointer type and an integral type
                SET_BIT(PORTD, pinnumber);  //Set the value of the given pin in port D as High
            } else {
                //#1397-D (MISRA-C:2004 10.5/R) If the bitwise operators ~ and << are applied to an operand of underlying type unsigned char or unsigned short, the result shall be immediately cast to the underlying type of the operand
                //#1400-D (MISRA-C:2004 11.3/A) A cast should not be performed between a pointer type and an integral type
                CLEAR_BIT(PORTD, pinnumber);  //Set the value of the given pin in port D as Low
            }
            break;
        default:
            break;
    }
}

uint8 DIO_readPin(uint8 portname, uint8 pinnumber) {
    uint8 return_value = 0;
    switch (portname) {
        case 'A':
            //#1400-D (MISRA-C:2004 11.3/A) A cast should not be performed between a pointer type and an integral type
            return_value = (uint8)READ_BIT(PINA, pinnumber);  //Read the value from the given pin in port A
            break;

        case 'B':
            //#1400-D (MISRA-C:2004 11.3/A) A cast should not be performed between a pointer type and an integral type
            return_value = (uint8)READ_BIT(PINB, pinnumber);  //Read the value from the given pin in port B
            break;

        case 'C':
            //#1400-D (MISRA-C:2004 11.3/A) A cast should not be performed between a pointer type and an integral type
            return_value = (uint8)READ_BIT(PINC, pinnumber);  //Read the value from the given pin in port C
            break;

        case 'D':
            //#1400-D (MISRA-C:2004 11.3/A) A cast should not be performed between a pointer type and an integral type
            return_value = (uint8)READ_BIT(PIND, pinnumber);  //Read the value from the given pin in port D
            break;
        default:
            break;
    }
    return return_value;
}

uint8 DIO_readPort(uint8 portname) {
    uint8 return_value = 0;
    uint8 itr;

    switch (portname) {
        case 'A':
            // #1393-D (MISRA-C:2004 10.1/R) The value of an expression of integer type shall not be implicitly converted to a different underlying type if it is not a conversion to a wider integer type of the same signedness
            for (itr = (uint8)0; itr < (uint8)8; itr++) {
                // #1393-D (MISRA-C:2004 10.1/R) The value of an expression of integer type shall not be implicitly converted to a different underlying type if it is not a conversion to a wider integer type of the same signedness
                //#1400-D (MISRA-C:2004 11.3/A) A cast should not be performed between a pointer type and an integral type
                if (READ_BIT(PINA, itr) == 1) {
                    //#1400-D (MISRA-C:2004 11.3/A) A cast should not be performed between a pointer type and an integral type
                    // MISRA :note 9233: bitwise operator |= may not be applied to operand with signed underlying type [MISRA 2004 Rule 12.7, required]
                    // MISRA :note 9226: integral expression of underlying type 'signed char' cannot be implicitly converted to type 'uint8' (aka 'unsigned char') because it is a complex expression [MISRA 2004 Rule 10.1, required]
                    // MISRA :note 9233: bitwise operator << may not be applied to operand with signed underlying type [MISRA 2004 Rule 12.7, required]
                    return_value |= ((uint8)1 << itr);

                } else {
                    //#1397-D (MISRA-C:2004 10.5/R) If the bitwise operators ~ and << are applied to an operand of underlying type unsigned char or unsigned short, the result shall be immediately cast to the underlying type of the operand
                    return_value &= (~((uint8)1 << itr));
                }
            }
            break;

        case 'B':
            // #1393-D (MISRA-C:2004 10.1/R) The value of an expression of integer type shall not be implicitly converted to a different underlying type if it is not a conversion to a wider integer type of the same signedness
            for (itr = (uint8)0; itr < (uint8)8; itr++) {
                // #1393-D (MISRA-C:2004 10.1/R) The value of an expression of integer type shall not be implicitly converted to a different underlying type if it is not a conversion to a wider integer type of the same signedness
                //#1400-D (MISRA-C:2004 11.3/A) A cast should not be performed between a pointer type and an integral type
                if (READ_BIT(PINB, itr) == 1) {
                    //#1400-D (MISRA-C:2004 11.3/A) A cast should not be performed between a pointer type and an integral type
                    return_value |= ((uint8)1 << itr);
                } else {
                    //#1397-D (MISRA-C:2004 10.5/R) If the bitwise operators ~ and << are applied to an operand of underlying type unsigned char or unsigned short, the result shall be immediately cast to the underlying type of the operand
                    return_value &= (~((uint8)1 << itr));
                }
            }
            break;

        case 'C':
            // #1393-D (MISRA-C:2004 10.1/R) The value of an expression of integer type shall not be implicitly converted to a different underlying type if it is not a conversion to a wider integer type of the same signedness
            for (itr = (uint8)0; itr < (uint8)8; itr++) {
                // #1393-D (MISRA-C:2004 10.1/R) The value of an expression of integer type shall not be implicitly converted to a different underlying type if it is not a conversion to a wider integer type of the same signedness
                //#1400-D (MISRA-C:2004 11.3/A) A cast should not be performed between a pointer type and an integral type
                if ((uint8)READ_BIT(PINC, itr) == (uint8)1) {
                    return_value |= ((uint8)1 << itr);
                } else {
                    //#1397-D (MISRA-C:2004 10.5/R) If the bitwise operators ~ and << are applied to an operand of underlying type unsigned char or unsigned short, the result shall be immediately cast to the underlying type of the operand
                    return_value &= (~((uint8)1 << itr));
                }
            }
            break;

        case 'D':
            // #1393-D (MISRA-C:2004 10.1/R) The value of an expression of integer type shall not be implicitly converted to a different underlying type if it is not a conversion to a wider integer type of the same signedness
            for (itr = (uint8)0; itr < (uint8)8; itr++) {
                // #1393-D (MISRA-C:2004 10.1/R) The value of an expression of integer type shall not be implicitly converted to a different underlying type if it is not a conversion to a wider integer type of the same signedness
                if ((uint8)READ_BIT(PIND, itr) == (uint8)1) {
                    return_value |= ((uint8)1 << itr);
                } else {
                    //#1397-D (MISRA-C:2004 10.5/R) If the bitwise operators ~ and << are applied to an operand of underlying type unsigned char or unsigned short, the result shall be immediately cast to the underlying type of the operand
                    return_value &= (~(1 << itr));
                }
            }
            break;

        default:
            break;
    }
    return return_value;
}

void DIO_togglePin(uint8 portname, uint8 pinnumber) {
    switch (portname) {
        case 'A':
            TOGGLE_BIT(PORTA, pinnumber);  //Toggle the value of the given pin in port A
            break;
        case 'B':
            TOGGLE_BIT(PORTB, pinnumber);  //Toggle the value of the given pin in port B
            break;
        case 'C':
            TOGGLE_BIT(PORTC, pinnumber);  //Toggle the value of the given pin in port C
            break;
        case 'D':
            TOGGLE_BIT(PORTD, pinnumber);  //Toggle the value of the given pin in port D
            break;
        default:
            break;
    }
}

void DIO_writePort(uint8 portname, uint8 portvalue) {
    switch (portname) {
        case 'A':
            PORTA = portvalue;  //Write the given value to the port A
            break;
        case 'B':
            PORTB = portvalue;  //Write the given value to the port B
            break;
        case 'C':
            PORTC = portvalue;  //Write the given value to the port C
            break;
        case 'D':
            PORTD = portvalue;  //Write the given value to the port D
            break;
        default:
            break;
    }
}

void DIO_writeHighnibble(uint8 portname, uint8 value) {
    switch (portname) {
        case 'A':
            // #1393-D (MISRA-C:2004 10.1/R) The value of an expression of integer type shall not be implicitly converted to a different underlying type if it is not a conversion to a wider integer type of the same signedness
            // #1393-D (MISRA-C:2004 10.1/R) The value of an expression of integer type shall not be implicitly converted to a different underlying type if the expression is complex
            PORTA |= (value & (uint8)0xf0);  //Set only the high nibble of the port A by the given value
            break;
        case 'B':
            // #1393-D (MISRA-C:2004 10.1/R) The value of an expression of integer type shall not be implicitly converted to a different underlying type if it is not a conversion to a wider integer type of the same signedness
            //#1393-D (MISRA-C:2004 10.1/R) The value of an expression of integer type shall not be implicitly converted to a different underlying type if the expression is complex
            PORTB |= (value & (uint8)0xf0);  //Set only the high nibble of the port B by the given value
            break;
        case 'C':
            //#1393-D (MISRA-C:2004 10.1/R) The value of an expression of integer type shall not be implicitly converted to a different underlying type if it is not a conversion to a wider integer type of the same signedness
            //#1393-D (MISRA-C:2004 10.1/R) The value of an expression of integer type shall not be implicitly converted to a different underlying type if the expression is complex
            PORTC |= (value & (uint8)0xf0);  //Set only the high nibble of the port C by the given value
            break;
        case 'D':
            // #1393-D (MISRA-C:2004 10.1/R) The value of an expression of integer type shall not be implicitly converted to a different underlying type if it is not a conversion to a wider integer type of the same signedness
            //#1393-D (MISRA-C:2004 10.1/R) The value of an expression of integer type shall not be implicitly converted to a different underlying type if the expression is complex
            PORTD |= (value & (uint8)0xf0);  //Set only the high nibble of the port D by the given value
            break;
        default:
            break;
    }
}

void clear_highNibble(uint8 portname) {
    switch (portname) {
        case 'A':
            //#1393-D (MISRA-C:2004 10.1/R) The value of an expression of integer type shall not be implicitly converted to a different underlying type if it is not a conversion to a wider integer type of the same signedness
            PORTA &= (uint8)0x0f;  //set the value of the high nibble of the port A as low
            break;
        case 'B':
            // #1393-D (MISRA-C:2004 10.1/R) The value of an expression of integer type shall not be implicitly converted to a different underlying type if it is not a conversion to a wider integer type of the same signedness
            PORTB &= (uint8)0x0f;  //set the value of the high nibble of the port B as low
            break;
        case 'C':
            // #1393-D (MISRA-C:2004 10.1/R) The value of an expression of integer type shall not be implicitly converted to a different underlying type if it is not a conversion to a wider integer type of the same signedness
            PORTC &= (uint8)0x0f;  //set the value of the high nibble of the port C as low
            break;
        case 'D':
            //#1393-D (MISRA-C:2004 10.1/R) The value of an expression of integer type shall not be implicitly converted to a different underlying type if it is not a conversion to a wider integer type of the same signedness
            PORTD &= (uint8)0x0f;  //set the value of the high nibble of the port D as low
            break;
        default:
            break;
    }
}

void DIO_connectPullup(uint8 portname, uint8 pinnumber, uint8 connect_pullup) {
    switch (portname) {
        /* Connect or disconnect the pull up resistance to the given pin in port A */
        case 'A':
            //#1393-D (MISRA-C:2004 10.1/R) The value of an expression of integer type shall not be implicitly converted to a different underlying type if it is not a conversion to a wider integer type of the same signedness
            if (connect_pullup == (uint8)1) {
                //#1393-D (MISRA-C:2004 10.1/R) The value of an expression of integer type shall not be implicitly converted to a different underlying type if it is not a conversion to a wider integer type of the same signedness
                CLEAR_BIT(SFIOR, 4);
                //#1397-D (MISRA-C:2004 10.5/R) If the bitwise operators ~ and << are applied to an operand of underlying type unsigned char or unsigned short, the result shall be immediately cast to the underlying type of the operand
                CLEAR_BIT(DDRA, pinnumber);
                SET_BIT(PORTA, pinnumber);
            } else {
                //#1397-D (MISRA-C:2004 10.5/R) If the bitwise operators ~ and << are applied to an operand of underlying type unsigned char or unsigned short, the result shall be immediately cast to the underlying type of the operand
                CLEAR_BIT(PORTA, pinnumber);
            }
            break;
            /* Connect or disconnect the pull up resistance to the given pin in port B */
        case 'B':
            //#1393-D (MISRA-C:2004 10.1/R) The value of an expression of integer type shall not be implicitly converted to a different underlying type if it is not a conversion to a wider integer type of the same signedness
            if (connect_pullup == (uint8)1) {
                //#1393-D (MISRA-C:2004 10.1/R) The value of an expression of integer type shall not be implicitly converted to a different underlying type if it is not a conversion to a wider integer type of the same signedness
                CLEAR_BIT(SFIOR, 4);
                //#1397-D (MISRA-C:2004 10.5/R) If the bitwise operators ~ and << are applied to an operand of underlying type unsigned char or unsigned short, the result shall be immediately cast to the underlying type of the operand
                CLEAR_BIT(DDRB, pinnumber);
                SET_BIT(PORTB, pinnumber);
            } else {
                //#1397-D (MISRA-C:2004 10.5/R) If the bitwise operators ~ and << are applied to an operand of underlying type unsigned char or unsigned short, the result shall be immediately cast to the underlying type of the operand
                CLEAR_BIT(PORTB, pinnumber);
            }
            break;
            /* Connect or disconnect the pull up resistance to the given pin in port C */
        case 'C':
            //#1393-D (MISRA-C:2004 10.1/R) The value of an expression of integer type shall not be implicitly converted to a different underlying type if it is not a conversion to a wider integer type of the same signedness
            if (connect_pullup == (uint8)1) {
                //#1393-D (MISRA-C:2004 10.1/R) The value of an expression of integer type shall not be implicitly converted to a different underlying type if it is not a conversion to a wider integer type of the same signedness
                CLEAR_BIT(SFIOR, 4);
                //#1397-D (MISRA-C:2004 10.5/R) If the bitwise operators ~ and << are applied to an operand of underlying type unsigned char or unsigned short, the result shall be immediately cast to the underlying type of the operand
                CLEAR_BIT(DDRC, pinnumber);
                SET_BIT(PORTC, pinnumber);
            } else {
                //#1397-D (MISRA-C:2004 10.5/R) If the bitwise operators ~ and << are applied to an operand of underlying type unsigned char or unsigned short, the result shall be immediately cast to the underlying type of the operand
                CLEAR_BIT(PORTC, pinnumber);
            }
            break;
            /* Connect or disconnect the pull up resistance to the given pin in port D */
        case 'D':
            //#1393-D (MISRA-C:2004 10.1/R) The value of an expression of integer type shall not be implicitly converted to a different underlying type if it is not a conversion to a wider integer type of the same signedness
            if (connect_pullup == (uint8)1) {
                // #1393-D (MISRA-C:2004 10.1/R) The value of an expression of integer type shall not be implicitly converted to a different underlying type if it is not a conversion to a wider integer type of the same signedness
                CLEAR_BIT(SFIOR, 4);
                //#1397-D (MISRA-C:2004 10.5/R) If the bitwise operators ~ and << are applied to an operand of underlying type unsigned char or unsigned short, the result shall be immediately cast to the underlying type of the operand
                CLEAR_BIT(DDRD, pinnumber);
                SET_BIT(PORTD, pinnumber);
            } else {
                //#1397-D (MISRA-C:2004 10.5/R) If the bitwise operators ~ and << are applied to an operand of underlying type unsigned char or unsigned short, the result shall be immediately cast to the underlying type of the operand
                CLEAR_BIT(PORTD, pinnumber);
            }
            break;
    }
}
