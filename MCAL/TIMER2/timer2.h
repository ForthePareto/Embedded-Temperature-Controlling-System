/*
 * timer2.h
 *
 *  Created on: Jun. 8, 2021
 *      Author: Eslam Khaled Korany
 */

#ifndef MCAL_TIMER2_TIMER2_H_
#define MCAL_TIMER2_TIMER2_H_


#include "../micro_config.h"


/* TIMER2 Registers BITs */
#define FOC2 7
#define WGM20 6
#define COM21  5
#define COM20 4
#define WGM21 3
#define CS22 2
#define CS21 1
#define CS20 0


#define OCIE2 7
#define TOIE2 6

extern volatile uint16 g_T2nOverflows;

typedef enum {
	TIMER2_NORMAL_MODE = 0x00,
	TIMER2_PWM_PHASE_CORRECT_MODE = 0x40,
	TIMER2_CTC_MODE = 0x08,
	TIMER2_FAST_PWM_MODE = 0x48,
} TIMER2_mode;

typedef enum {
	TIMER2_NORMAL_OUTPUT = 0x00,
	TIMER2_TOGGLE_OUTPUT = 0x01,
	TIMER2_CLEAR_OUTPUT = 0x02,
	TIMER2_SET_OUTPUT = 0x03,
} TIMER2_compare_match_action;

typedef enum {
	TIMER2_NO_CLOCK,
	TIMER2_F_CPU,
	TIMER2_F_CPU_8,
	TIMER2_F_CPU_64,
	TIMER2_F_CPU_256,
	TIMER2_F_CPU_1024,
	TIMER2_T0_FALLING_EDGE, /* T0 pin in the MCU*/
	TIMER2_T0_RAISING_EDGE, /* T0 pin in the MCU*/
} TIMER2_clock;

typedef struct {
	TIMER2_mode mode;
	TIMER2_compare_match_action compare_match_action;
	TIMER2_clock clock;
	uint8 overflow_interrupt; //ENABLE or DISABLE
	uint8 compare_interrupt; //ENABLE or DISABLE
	uint8 initial_value;     //0:255
	uint8 compare_value;	//0:255

} TIMER2_config;
/**************************************************
 * TIMER2 Module Dynamic configuration
 * [Members] :
 * 			mode: TIMER2_NORMAL or TIMER2_PWM_PHASE_CORRECT or TIMER2_CTC etc..
 * 			output_mode: TIMER2_NORMAL_OUTPUT or TIMER2_TOGGLE_OUTPUT etc..
 * 			clock: TIMER2_NON , F_CPU , 8 , 64 , 256 , 1024
 * 			compare_interrupt: enable or disable
 * 			overflow_interrupt: enable or disable
 * 			compare_value: 0:255
 * 			initial_value: 0:255
 ***************************************************/





/*********************************************************************************
 * 								Function Declarations							 *
 *********************************************************************************/
void TIMER2_init(const TIMER2_config *config_ptr);
/**********************************************************
 * [ARGS] :
 *	pointer to the configuration structure :
 *		indicating a constant configurations from the user in the main application
 ***********************************************************/
void TIMER2_setCompareValue(uint8 value);
/**********************************************************
 * [ARGS] :
 * 	a 0:255 value that corresponds to the compare value to be set in the OCR0
 ***********************************************************/
 void TIMER2_restart(uint8 initial_count, TIMER2_clock clk);
/**********************************************************
 * setting the pre-scaler and the initial value of the counter register 0:255
 ***********************************************************/
 void TIMER2_stop(void);
/**********************************************************
 * [TASK] : setting the pre-scaler of the timer clock as NON
 * 			which will disable the clock
 ***********************************************************/
void TIMER2_setCompareModeCallBack(void (*a_ptr)(void));
/**********************************************************
 * [ARGS] :
 * 	pointer to void function which takes void arguments :
 * 		indicating the code that will be executed in the ISR of the compare match
 ***********************************************************/
void TIMER2_setOverflowModeCallBack(void (*a_ptr)(void));
/**********************************************************
 * [ARGS] :
 * 	pointer to void function which takes void arguments :
 * 		indicating the code that will be executed in the ISR of the overflow
 ***********************************************************/


#endif /* MCAL_TIMER2_TIMER2_H_ */
