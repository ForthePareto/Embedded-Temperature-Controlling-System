/*
 * pwm0.c
 *
 *  Created on: Jun. 8, 2021
 *      Author: Eslam Khaled Korany
 */

#include "pwm0.h"

void PWM0_init(TIMER0_clock prescaler, uint8 PWM_MODE) {
	TIMER0_mode pwm_modes[2] = { TIMER0_PWM_PHASE_CORRECT_MODE,
			TIMER0_FAST_PWM_MODE };

	TIMER0_config T0_config = { pwm_modes[PWM_MODE], TIMER0_CLEAR_OUTPUT,
			prescaler, DISABLE, DISABLE, 0, 127 }; //square wave generation mode
	TIMER0_init(&T0_config);

}

void PWM0_start(float64 duty) {

	float64 reg_val = 256* duty ;
	TIMER0_setCompareValue((uint8)reg_val) ;

}

void PMW0_stop(void) {
	TIMER0_stop() ;
	TIMER0_setCompareValue(0) ;
}
