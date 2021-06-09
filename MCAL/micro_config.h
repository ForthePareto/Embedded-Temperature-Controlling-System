/*
 * micro_config.h
 *
 *  Created on: Jun. 6, 2021
 *      Author: Eslam Khaled Korany
 */

#ifndef MCAL_MICRO_CONFIG_H_
#define MCAL_MICRO_CONFIG_H_

#ifndef F_CPU
#define F_CPU 4000000UL //4MHz Clock frequency
#endif

#include <avr/interrupt.h>
#include <util/delay.h>

#include "../MCAL/common_macros.h"
#include "../MCAL/std_types.h"
#include "../MCAL/registers.h"

#include "../MCAL/INTERRUPT/INTERRUPT.h"
#include "../HAL/KEYPAD/KEYPAD.h"
#include "../MCAL/SPI/SPI.h"
#include "../HAL/LCD/LCD.h"
#include "../Service/DISPLAY/DISPLAY.h"
#include "../Service/TC72/TC72.h"


#define ENABLE_GLOBAL_INTERRUPT() (SET_BIT(SREG,7))
#define DISABLE_GLOBAL_INTERRUPT() (CLEAR_BIT(SREG,7))

#endif /* MCAL_MICRO_CONFIG_H_ */
