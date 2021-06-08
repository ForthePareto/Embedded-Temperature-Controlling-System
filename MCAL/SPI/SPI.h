#ifndef SPI_H
#define SPI_H
#include <avr/io.h>
#include <util/delay.h>
#include "../std_types.h"
#include "../DIO/DIO.h"

#define MOSI 5
#define MISO 6
#define SS 4
#define SCK 7

#define SPE 6
#define MSTR 4
#define CPHA 2
#define SPR1 1
#define SPR0 0

#define SPIF 7

void SPI_InitMaster(void);
void SPI_InitSlave (void);
void SPI_Transmit(uint8 data);
uint8 SPI_Receive(void);

// todo: make a TC72 service
void TC72_Init(void);
uint8 * TC72_getTemp(uint8 *);

#endif // SPI_H
