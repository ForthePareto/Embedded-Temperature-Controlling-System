#ifndef MCAL_MICRO_CONFIG_H_
#define MCAL_MICRO_CONFIG_H_

#undef F_CPU
#define F_CPU 4000000UL //4MHz Clock frequency

#include <avr/interrupt.h>
#include <util/delay.h>

#include "../MCAL/common_macros.h"
#include "../MCAL/std_types.h"

#include "../HAL/KEYPAD/KEYPAD.h"
#include "../Service/TC72/TC72.h"
#include "../Service/DISPLAY/DISPLAY.h"


#define ENABLE_GLOBAL_INTERRUPT() (SET_BIT(SREG,7))
#define DISABLE_GLOBAL_INTERRUPT() (CLEAR_BIT(SREG,7))

#endif /* MCAL_MICRO_CONFIG_H_ */
