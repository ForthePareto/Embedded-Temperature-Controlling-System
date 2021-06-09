#include "SPI.h"

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
