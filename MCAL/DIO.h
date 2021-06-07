#ifndef DIO_H_INCLUDED
#define DIO_H_INCLUDED


#include "../MCAL/micro_config.h"

void DIO_setPINDir(uint8 portname,uint8 pinnumber,uint8 direction);
void DIO_write(uint8 portname,uint8 pinnumber,uint8 outputvalue);
uint8 DIO_readPin(uint8 portname,uint8 pinnumber);
uint8 DIO_readPort(uint8 portname);
void DIO_togglePin(uint8 portname,uint8 pinnumber);
void DIO_writePort(uint8 portname,uint8 portvalue);
void clear_highNibble(uint8 portname) ;
void DIO_writeHighnibble(uint8 portname,uint8 value);
void DIO_connectPullup(uint8 portname ,uint8 pinnumber, uint8 connect_pullup);


#endif // DIO_H_INCLUDED
