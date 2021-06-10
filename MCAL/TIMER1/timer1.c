/*
 * timer1.c
 *
 *  Created on: Jun. 10, 2021
 *      Author: Eslam Khaled Korany
 */

#include "timer1.h"

static void (*volatile g_T1CompareInterruptFunc_ptr)(void) = NULL;

static void (*volatile g_T1OverflowInterruptFunc_ptr)(void) = NULL;

volatile uint16 g_T1nOverflows = (uint16) 0;

void TIMER1_init(const TIMER1_config *configStruct) {
	TCCR1A = (1 << FOC1A) | (1 << FOC1B) | (configStruct->mode & 0xFF);

	TCCR1B = (configStruct->mode >> 8);

	TCNT1 = configStruct->initial_value;

	OCR1A = configStruct->compare_value;

	TIMSK |= (configStruct->overflow_interrupt << TOIE1)
			| ((configStruct->compare_interrupt) << OCIE1A);

	TCCR1B |= configStruct->clock;

	SET_VALUE(TCCR1B, 0, READ_BIT(configStruct ->clock,0));
	SET_VALUE(TCCR1B, 1, READ_BIT(configStruct ->clock,1));
	SET_VALUE(TCCR1B, 2, READ_BIT(configStruct ->clock,2));

	ENABLE_GLOBAL_INTERRUPT();
}

void TIMER1_restart(uint16 initial_count,TIMER1_clock clk) {
	TCCR1B |= clk;
	TCNT1 =  initial_count;
}

void TIMER1_setCompareValue(uint16 value) {
	OCR1A = value;
}

void TIMER1_stop(void) {
	CLEAR_BIT(TCCR1B, 0);
	CLEAR_BIT(TCCR1B, 1);
	CLEAR_BIT(TCCR1B, 2);
	TCNT1 = 0;
}

void TIMER1_setCompareModeCallBack(void (*a_ptr)(void)) {
	g_T1CompareInterruptFunc_ptr = a_ptr;
}

void TIMER1_setOverflowModeCallBack(void (*a_ptr)(void)) {
	g_T1OverflowInterruptFunc_ptr = a_ptr;
}

ISR(TIMER1_COMPA_vect) {
	TCNT1 = 0;
	if (g_T1CompareInterruptFunc_ptr != NULL) {
		g_T1CompareInterruptFunc_ptr();
	}
}

ISR(TIMER1_OVF_vect) {
	if (g_T1OverflowInterruptFunc_ptr != NULL) {
		g_T1OverflowInterruptFunc_ptr();
	}
}
