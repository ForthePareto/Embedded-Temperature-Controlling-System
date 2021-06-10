/*
 * timer1.c
 *
 *  Created on: Jun. 10, 2021
 *      Author: Eslam Khaled Korany
 */

#include "timer1.h"

static void (*volatile g_T1CompareInterruptFunc_ptr)(void) = NULL;

static void (*volatile g_T1OverflowInterruptFunc_ptr)(void) = NULL;

volatile uint8 g_T1nOverflows = 0;



void TIMER1_setCompareModeCallBack(void (*a_ptr)(void)) {
	g_T1CompareInterruptFunc_ptr = a_ptr;
}

void TIMER1_setOverflowModeCallBack(void (*a_ptr)(void)) {
	g_T1OverflowInterruptFunc_ptr = a_ptr;
}

void TIMER1_init(const TIMER1_configType *config_ptr) {
	TCCR1A = (1 << FOC1A) | (1 << FOC1B) | (config_ptr->mode & 0xFF);


	TCCR1B = (config_ptr->mode >> 8);

	TCNT1 = config_ptr->initial_value;


	OCR1A = config_ptr->compare_value;


	TIMSK |= (config_ptr->overflow_interrupt << TOIE1)
			| ((config_ptr->compare_interrupt) << OCIE1A);

	TCCR1B |= config_ptr->clock;

	ENABLE_GLOBAL_INTERRUPT();
}

void TIMER1_start(TIMER1_clock clk) {
	TCCR1B |= clk;
	TCNT1 = 0;
}

void TIMER1_setCompareValue(uint16 value) {
	OCR1A = value;
}

void TIMER1_stop(void) {
	CLEAR_BIT(TCCR1B, 0);
	CLEAR_BIT(TCCR1B, 1);
	CLEAR_BIT(TCCR1B, 2);
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
