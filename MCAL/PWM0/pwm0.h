/*
 * pwm0.h
 *
 *  Created on: Jun. 8, 2021
 *      Author: Eslam Khaled Korany
 */

#ifndef MCAL_PWM0_PWM0_H_
#define MCAL_PWM0_PWM0_H_

#include "../TIMER0/timer0.h"

#define PWM_PHASE_CORRECT_MODE (0u)
#define PWM_FAST_MODE (1u)


void PWM0_init(TIMER0_clock prescaler,uint8 PWM_MODE); /* f_wave = F_CPU/(prescaler*256) */
void PWM0_restart(float64 duty,TIMER0_clock prescaler); /*duty is a fraction real number 0:1*/
void PWM0_stop(void);


#endif /* MCAL_PWM0_PWM0_H_ */
