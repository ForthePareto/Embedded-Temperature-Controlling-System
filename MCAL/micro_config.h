/*
 * micro_config.h
 *
 *  Created on: Jun. 6, 2021
 *      Author: Eslam Khaled Korany
 */

#ifndef MCAL_MICRO_CONFIG_H_
#define MCAL_MICRO_CONFIG_H_

#ifndef F_CPU
#define F_CPU 1000000UL //1MHz Clock frequency
#endif

#include <avr/interrupt.h>
#include <util/delay.h>

#include <../MCAL/common_macros.h>
#include <../MCAL/std_types.h>
#include <../MCAL/registers.h>


#define ENABLE_GLOBAL_INTERRUPT() (SET_BIT(SREG,7))
#define DISABLE_GLOBAL_INTERRUPT() (CLEAR_BIT(SREG,7))

#endif /* MCAL_MICRO_CONFIG_H_ */
