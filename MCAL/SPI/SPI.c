#include "SPI.h"

uint8 convertIntChar(uint8 num);

void SPI_InitMaster(void) 
{
	DIO_setPINDir('B', MOSI, 1);
	DIO_setPINDir('B', SS, 1);
	DIO_setPINDir('B', SCK, 1);
	
	// DIO_setPINDir('B', MISO, 0);

	SPCR |= (1 << SPE) | (1 << MSTR) | (1 << CPHA) | (1 << SPR1) | (1 << SPR0);

	SPSR &= ~(1<<SPI2X);
}

void SPI_InitSlave(void)
{
	DDRB |= (1<<MISO) ;//Set the port B miso(master in slave out ) pin as output
	SPCR |= (1<<SPE);//Enable the SPI
}

void SPI_Transmit(uint8 data)
{
	SPDR = data;//move the given data to SPI Data register
	
	//in case of master send data and wait till the data are fully transmitted
	//in case of slave wait the data to be transmitted by the master
	while (((SPSR&(1<<SPIF))>>SPIF)==0) {}	//wait till the transmitting is done

}

uint8 SPI_Receive(void){
	/*Wait for the SPI buffer's full*/
	while(!(SPSR&(1<<SPIF)));
	/*return SPI Buffer*/
	return SPDR;
}

void TC72_Init(void)
{
	DIO_write('B', SS, 1);
	/*Select Control Register*/
	SPI_Transmit(0x80);
	/*Select Continuous temperature Conversion*/
	SPI_Transmit(0x04);
	DIO_write('B', SS, 0);
	_delay_ms(150);
}

uint8 * TC72_getTemp(uint8 * str)
{
    uint8 msb = 0;
    uint8 lsb = 0;
    uint8 temp = 0;
    DIO_write('B', SS, 1);
    /*Read the MSB*/
    SPI_Transmit(0x02);
    /*Issue one more clock frame
    to force data out*/
    SPI_Transmit(0x00);
    DIO_write('B', SS, 0);

    _delay_ms(1);
    msb = SPI_Receive();

    DIO_write('B', SS, 1);
    /*Read The LSB*/
    SPI_Transmit(0x01);
    /*Issue one more clock frame
    to force data out*/
    SPI_Transmit(0x00);
    DIO_write('B', SS, 0);

    _delay_ms(1);
    lsb = SPI_Receive();

    // two's compliement

    if(msb & 0x80) // if odd (first bit is 1)
    {
        temp = ~(msb) + 1; // convert to unsigned char
		str[0] = '-';
    }
    else
    {
        temp = msb;
		str[0] = ' ';
    }

    str[1] = convertIntChar(temp / 10);
    str[2] = convertIntChar(temp % 10);
	str[3] = '.';
	switch(lsb)
	{
		case (uint8)0x00:
			str[4] = '0';
			str[5] = '0';
			break;

		case (uint8)0x80:
			str[4] = '5';
			str[5] = '0';
			break;
		
		case (uint8)0x40:
			str[4] = '2';
			str[5] = '5';
			break;
		
		case (uint8)0xc0:
			str[4] = '2';
			str[5] = '5';
			break;
		
		default:
			str[4] = '9';
			str[5] = '9';
			break;
	}

    return str;
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