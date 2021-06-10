/*
 * timer1.h
 *
 *  Created on: Jun. 10, 2021
 *      Author: Eslam Khaled Korany
 */

#ifndef MCAL_TIMER1_TIMER1_H_
#define MCAL_TIMER1_TIMER1_H_
#include "../micro_config.h"
extern volatile uint8 g_T1nOverflows;
typedef enum {
	TIMER1_NORMAL = 0x0000, TIMER1_CTC = 0x0800,
} TIMER1_mode;

typedef enum {
	TIMER1_NON,
	TIMER1_F_CPU,
	TIMER1_F_CPU_8,
	TIMER1_F_CPU_64,
	TIMER1_F_CPU_256,
	TIMER1_F_CPU_1024,
	TIMER1_PIN_FALLING_EDGE,
	TIMER1_PIN_RAISING_EDGE,
} TIMER1_clock;

typedef struct {
	TIMER1_mode mode;
	TIMER1_clock clock;
	uint8 compare_interrupt;
	uint8 overflow_interrupt;
	uint16 compare_value;
	uint16 initial_value;
} TIMER1_configType;

/*********************************************************************************
 * 								Function Declarations							 *
 *********************************************************************************/
void TIMER1_init(const TIMER1_configType *config_ptr);

void TIMER1_setCompareValue(uint16 value);

void TIMER1_start(TIMER1_clock clk);
void TIMER1_stop(void);
void TIMER1_setCompareModeCallBack(void (*a_ptr)(void));
void TIMER1_setOverflowModeCallBack(void (*a_ptr)(void));

#endif /* MCAL_TIMER1_TIMER1_H_ */
