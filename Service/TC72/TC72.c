#include"TC72.h"

void TC72_Init(void)
{
    // Init SPI
    SPI_InitMaster();

    DIO_write('B', SS, 1);
	/*Select Control Register*/
	SPI_Transmit(0x80);
	/*Select Continuous temperature Conversion*/
	SPI_Transmit(0x04);
	DIO_write('B', SS, 0);
	_delay_us(100);
}

void TC72_getTemp(void)
{
    uint8 msb = 0;
    // uint8 lsb = 0;
    uint8 temp = 0;

    DIO_write('B', SS, 1);
    /*Read the MSB*/
    SPI_Transmit(0x02);
    /*Issue one more clock frame
    to force data out*/
    SPI_Transmit(0x00);
    DIO_write('B', SS, 0);

    _delay_us(100);
    msb = SPI_Receive();

    DIO_write('B', SS, 1);
    /*Read The LSB*/
    SPI_Transmit(0x01);
    /*Issue one more clock frame
    to force data out*/
    SPI_Transmit(0x00);
    DIO_write('B', SS, 0);

    _delay_us(100);
    // lsb = SPI_Receive();

    // two's compliement

    if(msb & 0x80) // if odd (first bit is 1)
    {
        temp = ~(msb) + 1; // convert to unsigned char
		// crTemp[0] = '-'; // sign disabled
    }
    else
    {
        temp = msb;
		// crTemp[0] = ' ';
    }

    crTemp[0] = convertIntChar(temp / 10);
    crTemp[1] = convertIntChar(temp % 10);
	// crTemp[3] = '.';
	/* switch(lsb)
	{
		case (uint8)0x00:
			crTemp[4] = '0';
			crTemp[5] = '0';
			break;

		case (uint8)0x80:
			crTemp[4] = '5';
			crTemp[5] = '0';
			break;
		
		case (uint8)0x40:
			crTemp[4] = '2';
			crTemp[5] = '5';
			break;
		
		case (uint8)0xc0:
			crTemp[4] = '2';
			crTemp[5] = '5';
			break;
		
		default:
			crTemp[4] = '9';
			crTemp[5] = '9';
			break;
	} */
    
    /* if((crTemp[0] != Compare[0]) & (crTemp[1] != Compare[1]))
    {
        Compare[0] = crTemp[0];
        Compare[1] = crTemp[1];
        changed = 1;
    } */
}

uint8 convertIntChar(uint8 num)
{
    uint8 value = 0;
    switch (num)
    {
    case 0:
        value = '0';
        break;

    case 1:
        value = '1';
        break;

    case 2:
        value = '2';
        break;

    case 3:
        value = '3';
        break;
    
    case 4:
        value = '4';
        break;

    case 5:
        value = '5';
        break;

    case 6:
        value = '6';
        break;

    case 7:
        value = '7';
        break;

    case 8:
        value = '8';
        break;

    case 9:
        value = '9';
        break;

    default:
        break;
    }
    return value;
}

uint8 convertCharInt(uint8 character)
{
    uint8 value = 0;
    switch (character)
    {
    case '0':
        value = 0;
        break;

    case '1':
        value = 1;
        break;

    case '2':
        value = 2;
        break;

    case '3':
        value = 3;
        break;
    
    case '4':
        value = 4;
        break;

    case '5':
        value = 5;
        break;

    case '6':
        value = 6;
        break;

    case '7':
        value = 7;
        break;

    case '8':
        value = 8;
        break;

    case '9':
        value = 9;
        break;

    default:
        break;
    }
    return value;
}
