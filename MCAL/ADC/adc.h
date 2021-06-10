/*
 * adc.h
 *
 *  Created on: Jun. 10, 2021
 *      Author: Eslam Khaled Korany
 */

#ifndef MCAL_ADC_ADC_H_
#define MCAL_ADC_ADC_H_

#include"../micro_config.h"

extern volatile uint16 ADC_reading;

typedef enum
{
	AREF,
	AVCC,
	_2_56v = 3,
}ADC_voltage_reference;

typedef enum
{
	ADC0 ,
	ADC1 ,
	ADC2 ,
	ADC3 ,
	ADC4 ,
	ADC5 ,
	ADC6 ,
	ADC7 ,
}ADC_channel;

typedef enum
{
	POLLING , INTERRUPT ,
}ADC_conversion_complete_mode;

typedef enum
{
	ADC_F_CPU_2 , ADC_F_CPU_2_2 , ADC_F_CPU_4 , ADC_F_CPU_8 ,
	ADC_F_CPU_16 , ADC_F_CPU_32 , ADC_F_CPU_64 , ADC_F_CPU_128 ,
}ADC_prescaler; // choose one that makes fcpu/prescaler < 200khz

typedef struct
{
	ADC_voltage_reference 	ref;
	ADC_conversion_complete_mode type;
	ADC_prescaler			prescaler;
}ADC_config;


void ADC_setCallBack(void(*a_ptr)(void));

void ADC_init(const ADC_config * config_ptr);

void ADC_readChannel(const ADC_config * config_ptr , ADC_channel a_channel);

#endif /* MCAL_ADC_ADC_H_ */
