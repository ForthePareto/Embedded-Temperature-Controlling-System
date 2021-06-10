/*
 * timer0.c
 *
 *  Created on: Jun. 7, 2021
 *      Author: Eslam Khaled Korany
 */
#include "timer0.h"

static void (*volatile g_T0CompareInterruptFunc_ptr)(void) = NULL;

static void (*volatile g_T0OverflowInterruptFunc_ptr)(void) = NULL;


// MISRA :note 9225: integral expression of underlying type 'signed char' cannot be implicitly converted to type 'volatile uint8' (aka 'volatile unsigned char') because it is not a wider integer type of the same signedness [MISRA 2004 Rule 10.1, required]
volatile uint16 g_T0nOverflows = (uint16)0 ;

void TIMER0_init(const TIMER0_config *configStruct) {
	/* Mode setting: {NORMAL , PWM_PHASE_CORRECT, CTC, FAST_PWM}*/
	TCCR0 = configStruct->mode;

	/*Setting compare match action {NORMAL, TOGGLE, CLEAR, SET}*/
	TCCR0 |= ((configStruct->compare_match_action) << COM00);
	/*Setting Counter registers initial values for normal and compare modes*/
	TCNT0 = configStruct->initial_value;
	TIMER0_setCompareValue(configStruct->compare_value);
	/* setting the force compare bit 0 according  to the mode of the timer*/
	// MISRA :note 9050: dependence placed on operator precedence (operators '||' and '==') [MISRA 2004 Rule 12.1, advisory]
	// MISRA :note 9240: left side of logical operator '||' is not a primary expression [MISRA 2004 Rule 12.5, required]
	if((configStruct->mode == TIMER0_NORMAL_MODE) || (configStruct->mode == TIMER0_CTC_MODE))
	{
		/* in case of non-pwm mode */
		SET_BIT(TCCR0, FOC0);
	} else {
		/* in case of a pwm mode */
		CLEAR_BIT(TCCR0, FOC0);
	}
	if (configStruct->compare_match_action != TIMER0_NORMAL_OUTPUT) {
		/* for the signal pwm output pin (if pwm mode configured only) */
		SET_BIT(DDRB, 3); //OC0
		CLEAR_BIT(PORTB, 3); //OC0
	}
	/* setting the interrupt modes */
	TIMSK |= (configStruct->overflow_interrupt << TOIE0)
			| ((configStruct->compare_interrupt) << OCIE0);

	/* starting the timer NOW after all settings is done*/
//	TCCR0 |=configStruct ->clock;
	SET_VALUE(TCCR0, CS00, READ_BIT(configStruct ->clock,CS00));
	SET_VALUE(TCCR0, CS01, READ_BIT(configStruct ->clock,CS01));
	SET_VALUE(TCCR0, CS02, READ_BIT(configStruct ->clock,CS02));
	/* enabling the global interrupt */
	ENABLE_GLOBAL_INTERRUPT();
}

void TIMER0_restart(uint8 initial_count, TIMER0_clock clk) {
	/* setting the pre-scaler(assuming their bits are initially zeros) and the initial value of the counter register 0:255 */
//	TIMER0_stop() ; //ensures clearing first 3 bits, TCNT0
	SET_VALUE(TCCR0, CS00, READ_BIT(clk,CS00));
	SET_VALUE(TCCR0, CS01, READ_BIT(clk,CS01));
	SET_VALUE(TCCR0, CS02, READ_BIT(clk,CS02));
	TCNT0 = initial_count;

}

void TIMER0_setCompareValue(uint8 value) {
	OCR0 = value;
}

void TIMER0_stop(void) {
	CLEAR_BIT(TCCR0, CS00);
	CLEAR_BIT(TCCR0, CS01);
	CLEAR_BIT(TCCR0, CS02);
	TCNT0 = 0;
}

void TIMER0_setCompareModeCallBack(void (*ptr)(void)) {
	g_T0CompareInterruptFunc_ptr = ptr;
}

void TIMER0_setOverflowModeCallBack(void (*ptr)(void)) {
	g_T0OverflowInterruptFunc_ptr = ptr;
}

ISR(TIMER0_COMP_vect) {
	/* the corresponding interrupt service routine function (IF EXIST) will be executed*/
	if (g_T0CompareInterruptFunc_ptr != NULL) {
		g_T0CompareInterruptFunc_ptr();
	}
}


// MISRA :note 9072: parameter 1 of function 'ISR()' has different name than previous declaration ('TIMER0_OVF_vect' vs 'TIMER0_COMP_vect') [MISRA 2004 Rule 16.4, required]
ISR(TIMER0_OVF_vect)
{
	/* the corresponding interrupt service routine function (IF EXIST) will be executed*/
	if (g_T0OverflowInterruptFunc_ptr != NULL) {
		g_T0OverflowInterruptFunc_ptr();
	}
}
