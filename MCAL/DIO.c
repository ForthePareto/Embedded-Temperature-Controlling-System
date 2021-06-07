#include "DIO.h"

void DIO_setPINDir(uint8 portname, uint8 pinnumber, uint8 direction) {
	switch (portname) {

	case 'A':
		if (direction == 1) {
			SET_BIT(DDRA, pinnumber); //Set the direction of the given pin in port A as output
		} else {
			CLEAR_BIT(DDRA, pinnumber); //Set the direction of the given pin in port A as input
		}
		break;
	case 'B':
		if (direction == 1) {
			SET_BIT(DDRB, pinnumber); //Set the direction of the given pin in port B as output
		} else {
			CLEAR_BIT(DDRB, pinnumber); //Set the direction of the given pin in port B as input
		}
		break;
	case 'C':
		if (direction == 1) {
			SET_BIT(DDRC, pinnumber); //Set the direction of the given pin in port C as output
		} else {
			CLEAR_BIT(DDRC, pinnumber); //Set the direction of the given pin in port C as input
		}
		break;
	case 'D':
		if (direction == 1) {
			SET_BIT(DDRD, pinnumber); //Set the direction of the given pin in port D as output
		} else {
			CLEAR_BIT(DDRD, pinnumber); //Set the direction of the given pin in port D as input
		}
		break;
	default:
		break;
	}
}

void DIO_write(uint8 portname, uint8 pinnumber, uint8 outputvalue) {
	switch (portname) {
	case 'A':

		if (outputvalue == 1) {
			SET_BIT(PORTA, pinnumber); //Set the value of the given pin in port A as High
		} else {
			CLEAR_BIT(PORTA, pinnumber); //Set the value of the given pin in port A as Low
		}
		break;
	case 'B':

		if (outputvalue == 1) {
			SET_BIT(PORTB, pinnumber); //Set the value of the given pin in port B as High
		} else {
			CLEAR_BIT(PORTB, pinnumber); //Set the value of the given pin in port B as Low
		}
		break;
	case 'C':

		if (outputvalue == 1) {
			SET_BIT(PORTC, pinnumber); //Set the value of the given pin in port C as High
		} else {
			CLEAR_BIT(PORTC, pinnumber); //Set the value of the given pin in port C as Low
		}
		break;
	case 'D':

		if (outputvalue == 1) {
			SET_BIT(PORTD, pinnumber); //Set the value of the given pin in port D as High
		} else {
			CLEAR_BIT(PORTD, pinnumber); //Set the value of the given pin in port D as Low
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
		return_value = READ_BIT(PINA, pinnumber); //Read the value from the given pin in port A
		break;

	case 'B':
		return_value = READ_BIT(PINB, pinnumber); //Read the value from the given pin in port B
		break;

	case 'C':
		return_value = READ_BIT(PINC, pinnumber); //Read the value from the given pin in port C
		break;

	case 'D':
		return_value = READ_BIT(PIND, pinnumber); //Read the value from the given pin in port D
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
		for (itr = 0; itr < 8; itr++) {
			if (READ_BIT(PINA, itr) == 1) {
				return_value |= (1 << itr);
			} else {
				return_value &= (~(1 << itr));
			}
		}
		break;

	case 'B':
		for (itr = 0; itr < 8; itr++) {
			if (READ_BIT(PINB, itr) == 1) {
				return_value |= (1 << itr);
			} else {
				return_value &= (~(1 << itr));
			}
		}
		break;

	case 'C':
		for (itr = 0; itr < 8; itr++) {
			if (READ_BIT(PINC, itr) == 1) {
				return_value |= (1 << itr);
			} else {
				return_value &= (~(1 << itr));
			}
		}
		break;

	case 'D':
		for (itr = 0; itr < 8; itr++) {
			if (READ_BIT(PIND, itr) == 1) {
				return_value |= (1 << itr);
			} else {
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
		TOGGLE_BIT(PORTA, pinnumber); //Toggle the value of the given pin in port A
		break;
	case 'B':
		TOGGLE_BIT(PORTB, pinnumber); //Toggle the value of the given pin in port B
		break;
	case 'C':
		TOGGLE_BIT(PORTC, pinnumber); //Toggle the value of the given pin in port C
		break;
	case 'D':
		TOGGLE_BIT(PORTD, pinnumber); //Toggle the value of the given pin in port D
		break;
	default:
		break;
	}
}

void DIO_writePort(uint8 portname, uint8 portvalue) {
	switch (portname) {
	case 'A':
		PORTA = portvalue; //Write the given value to the port A
		break;
	case 'B':
		PORTB = portvalue; //Write the given value to the port B
		break;
	case 'C':
		PORTC = portvalue; //Write the given value to the port C
		break;
	case 'D':
		PORTD = portvalue; //Write the given value to the port D
		break;
	default:
		break;
	}
}

void DIO_writeHighnibble(uint8 portname, uint8 value) {
	switch (portname) {
	case 'A':
		PORTA |= (value & 0xf0); //Set only the high nibble of the port A by the given value
		break;
	case 'B':
		PORTB |= (value & 0xf0); //Set only the high nibble of the port B by the given value
		break;
	case 'C':
		PORTC |= (value & 0xf0); //Set only the high nibble of the port C by the given value
		break;
	case 'D':
		PORTD |= (value & 0xf0); //Set only the high nibble of the port D by the given value
		break;
	default:
		break;

	}
}

void clear_highNibble(uint8 portname) {
	switch (portname) {
	case 'A':
		PORTA &= 0x0f; //set the value of the high nibble of the port A as low
		break;
	case 'B':
		PORTB &= 0x0f; //set the value of the high nibble of the port B as low
		break;
	case 'C':
		PORTC &= 0x0f; //set the value of the high nibble of the port C as low
		break;
	case 'D':
		PORTD &= 0x0f; //set the value of the high nibble of the port D as low
		break;
	default:
		break;

	}
}

void DIO_connectPullup(uint8 portname, uint8 pinnumber, uint8 connect_pullup) {
	switch (portname) {
	/* Connect or disconnect the pull up resistance to the given pin in port A */
	case 'A':
		if (connect_pullup == 1) {
			CLEAR_BIT(SFIOR, 4);
			CLEAR_BIT(DDRA, pinnumber);
			SET_BIT(PORTA, pinnumber);
		} else {
			CLEAR_BIT(PORTA, pinnumber);
		}
		break;
		/* Connect or disconnect the pull up resistance to the given pin in port B */
	case 'B':
		if (connect_pullup == 1) {
			CLEAR_BIT(SFIOR, 4);
			CLEAR_BIT(DDRB, pinnumber);
			SET_BIT(PORTB, pinnumber);
		} else {
			CLEAR_BIT(PORTB, pinnumber);
		}
		break;
		/* Connect or disconnect the pull up resistance to the given pin in port C */
	case 'C':
		if (connect_pullup == 1) {
			CLEAR_BIT(SFIOR, 4);
			CLEAR_BIT(DDRC, pinnumber);
			SET_BIT(PORTC, pinnumber);
		} else {
			CLEAR_BIT(PORTC, pinnumber);
		}
		break;
		/* Connect or disconnect the pull up resistance to the given pin in port D */
	case 'D':
		if (connect_pullup == 1) {
			CLEAR_BIT(SFIOR, 4);
			CLEAR_BIT(DDRD, pinnumber);
			SET_BIT(PORTD, pinnumber);
		} else {
			CLEAR_BIT(PORTD, pinnumber);
		}
		break;

	}
}

