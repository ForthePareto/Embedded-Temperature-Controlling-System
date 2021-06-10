/*
 * timer2.c
 *
 *  Created on: Jun. 8, 2021
 *      Author: Eslam Khaled Korany
 */

#include "timer2.h"

static void (*volatile g_T2CompareInterruptFunc_ptr)(void) = NULL;

static void (*volatile g_T2OverflowInterruptFunc_ptr)(void) = NULL;

volatile uint8 g_T2nOverflows = 0;

void TIMER2_init(const TIMER2_config *configStruct) {
	/* Mode setting: {NORMAL , PWM_PHASE_CORRECT, CTC, FAST_PWM}*/
	TCCR2 = configStruct->mode;
	/*Setting compare match action {NORMAL, TOGGLE, CLEAR, SET}*/
	TCCR2 |= ((configStruct->compare_match_action) << COM20);
	/*Setting Counter registers initial values for normal and compare modes*/
	TCNT2 = configStruct->initial_value;
	TIMER2_setCompareValue(configStruct->compare_value);

	/* setting the force compare bit 0 according  to the mode of the timer*/
	if (configStruct->mode == TIMER2_NORMAL_MODE
			|| configStruct->mode == TIMER2_CTC_MODE) {
		/* in case of non-pwm mode */
		SET_BIT(TCCR2, FOC2);
	} else {
		/* in case of a pwm mode */
		CLEAR_BIT(TCCR2, FOC2);
	}
	if (configStruct->compare_match_action != TIMER2_NORMAL_OUTPUT) {
		/* for the signal pwm output pin (if pwm mode configured only) */
		SET_BIT(DDRD, 7); //OC2
		CLEAR_BIT(PORTD, 7); //OC2
	}
	/* setting the interrupt modes */
	TIMSK |= (configStruct->overflow_interrupt << TOIE2)
			| ((configStruct->compare_interrupt) << OCIE2);

	/* starting the timer NOW after all settings is done*/
	SET_VALUE(TCCR2, CS00, READ_BIT(configStruct ->clock,CS20));
	SET_VALUE(TCCR2, CS00, READ_BIT(configStruct ->clock,CS21));
	SET_VALUE(TCCR2, CS00, READ_BIT(configStruct ->clock,CS22));
	/* enabling the global interrupt */
	ENABLE_GLOBAL_INTERRUPT();
}

void TIMER2_restart(uint8 initial_count, TIMER2_clock clk) {
	/* setting the pre-scaler (assuming their bits are initially zeros) and the initial value of the counter register 0:255 */
	SET_VALUE(TCCR2, CS00, READ_BIT(clk,CS20));
	SET_VALUE(TCCR2, CS00, READ_BIT(clk,CS21));
	SET_VALUE(TCCR2, CS00, READ_BIT(clk,CS22));
	TCNT2 = initial_count;
}

void TIMER2_setCompareValue(uint8 value) {
	OCR2 = value;
}

void TIMER2_stop(void) {
	CLEAR_BIT(TCCR2, CS20);
	CLEAR_BIT(TCCR2, CS21);
	CLEAR_BIT(TCCR2, CS22);
	TCNT0 = 0;

}

void TIMER2_setCompareModeCallBack(void (*ptr)(void)) {
	g_T2CompareInterruptFunc_ptr = ptr;
}

void TIMER2_setOverflowModeCallBack(void (*ptr)(void)) {
	g_T2OverflowInterruptFunc_ptr = ptr;
}

ISR(TIMER2_COMP_vect) {
	/* the corresponding interrupt service routine function (IF EXIST) will be executed*/
	if (g_T2CompareInterruptFunc_ptr != NULL) {
		g_T2CompareInterruptFunc_ptr();
	}
}

ISR(TIMER2_OVF_vect) {
	/* the corresponding interrupt service routine function (IF EXIST) will be executed*/
	if (g_T2OverflowInterruptFunc_ptr != NULL) {
		g_T2OverflowInterruptFunc_ptr();
	}
}
