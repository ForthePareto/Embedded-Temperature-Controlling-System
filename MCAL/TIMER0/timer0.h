/*
 * timer0.h
 *
 *  Created on: Jun. 7, 2021
 *      Author: Eslam Khaled Korany
 */

#ifndef MCAL_TIMER0_TIMER0_H_
#define MCAL_TIMER0_TIMER0_H_


#include "../micro_config.h"


/* Timer0 Registers BITs */
#define FOC0 7
#define WGM00 6
#define COM01  5
#define COM00 4
#define WGM01 3
#define CS02 2
#define CS01 1
#define CS00 0


#define OCIE0 1
#define TOIE0 0
extern volatile uint8 g_T0nOverflows;

typedef enum {
	TIMER0_NORMAL_MODE = 0x00,
	TIMER0_PWM_PHASE_CORRECT_MODE = 0x40,
	TIMER0_CTC_MODE = 0x08,
	TIMER0_FAST_PWM_MODE = 0x48,
} TIMER0_mode;

typedef enum {
	TIMER0_NORMAL_OUTPUT = 0x00,
	TIMER0_TOGGLE_OUTPUT = 0x01,
	TIMER0_CLEAR_OUTPUT = 0x02,
	TIMER0_SET_OUTPUT = 0x03,
} TIMER0_compare_match_action;

typedef enum {
	TIMER0_NO_CLOCK,
	TIMER0_F_CPU,
	TIMER0_F_CPU_8,
	TIMER0_F_CPU_64,
	TIMER0_F_CPU_256,
	TIMER0_F_CPU_1024,
	TIMER0_T0_FALLING_EDGE, /* T0 pin in the MCU*/
	TIMER0_T0_RAISING_EDGE, /* T0 pin in the MCU*/
} TIMER0_clock;

typedef struct {
	TIMER0_mode mode;
	TIMER0_compare_match_action compare_match_action;
	TIMER0_clock clock;
	uint8 overflow_interrupt; //ENABLE or DISABLE
	uint8 compare_interrupt; //ENABLE or DISABLE
	uint8 initial_value;     //0:255
	uint8 compare_value;	//0:255

} TIMER0_config;
/**************************************************
 * TIMER0 Module Dynamic configuration
 * [Members] :
 * 			mode: TIMER0_NORMAL or TIMER0_PWM_PHASE_CORRECT or TIMER0_CTC etc..
 * 			output_mode: TIMER0_NORMAL_OUTPUT or TIMER0_TOGGLE_OUTPUT etc..
 * 			clock: TIMER0_NON , F_CPU , 8 , 64 , 256 , 1024
 * 			compare_interrupt: enable or disable
 * 			overflow_interrupt: enable or disable
 * 			compare_value: 0:255
 * 			initial_value: 0:255
 ***************************************************/





/*********************************************************************************
 * 								Function Declarations							 *
 *********************************************************************************/
void TIMER0_init(const TIMER0_config *config_ptr);
/**********************************************************
 * [ARGS] :
 *	pointer to the configuration structure :
 *		indicating a constant configurations from the user in the main application
 ***********************************************************/
void TIMER0_start(uint8 initial_count);
/**********************************************************
 * setting the pre-scaler and the initial value of the counter register 0:255
 ***********************************************************/

void TIMER0_setCompareValue(uint8 value);
/**********************************************************
 * [ARGS] :
 * 	a 0:255 value that corresponds to the compare value to be set in the OCR0
 ***********************************************************/
void TIMER0_stop(void);
/**********************************************************
 * [TASK] : setting the pre-scaler of the timer clock as NON
 * 			which will disable the clock
 ***********************************************************/
void TIMER0_setCompareModeCallBack(void (*a_ptr)(void));
/**********************************************************
 * [ARGS] :
 * 	pointer to void function which takes void arguments :
 * 		indicating the code that will be executed in the ISR of the compare match
 ***********************************************************/
void TIMER0_setOverflowModeCallBack(void (*a_ptr)(void));
/**********************************************************
 * [ARGS] :
 * 	pointer to void function which takes void arguments :
 * 		indicating the code that will be executed in the ISR of the overflow
 ***********************************************************/

#endif /* MCAL_TIMER0_TIMER0_H_ */
