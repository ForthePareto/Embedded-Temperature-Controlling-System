#include "INTERRUPT.h"

void Interrupt_Init(void)
{
    //Pin 2,3 in D input, Pin 2 in B input
	DIO_setPINDir('D',2,0);
    DIO_setPINDir('D',3,0);
    DIO_setPINDir('B',2,0);
	//Pin 2,3 in D pull up, Pin 2 in B pull up
    DIO_write('D', 2, 1);
    DIO_write('D', 3, 1);
    DIO_write('B', 2, 1);
    //Service Control Low Level ... The low level (not only Negative-Edge) of INT0 generates an interrupt request.
	//INT2 is only edge-trigger (less-stable)
    CLEAR_BIT(MCUCR,1); //INT0
	CLEAR_BIT(MCUCR,0);

    CLEAR_BIT(MCUCR,2); //INT1
	CLEAR_BIT(MCUCR,3);

    CLEAR_BIT(MCUCSR, 6); //INT2
    //Enable Global Interrupt ... Enable GIE
	SET_BIT(SREG,7);
	//External Interrupt Enable ... Enable PIE
	SET_BIT(GICR,7); //INT1
    SET_BIT(GICR,6); //INT0
    SET_BIT(GICR,5); //INT2
}
