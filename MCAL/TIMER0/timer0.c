/*
 * timer0.c
 *
 *  Created on: Jun. 7, 2021
 *      Author: Eslam Khaled Korany
 */
#include "timer0.h"


static void (*volatile g_T0CompareInterruptFunc_ptr)(void) = NULL;

static void (*volatile g_T0OverflowInterruptFunc_ptr)(void) = NULL;

volatile uint8 g_T0nOverflows = 0 ;

void TIMER0_init(const TIMER0_config * configStruct)
{
	/* Mode setting: {NORMAL , PWM_PHASE_CORRECT, CTC, FAST_PWM}*/
	TCCR0 = configStruct->mode ;

	/*Setting compare match action {NORMAL, TOGGLE, CLEAR, SET}*/
	TCCR0 |= ((configStruct->compare_match_action) << COM00) ;
	/*Setting Counter registers initial values for normal and compare modes*/
	TIMER0_start(configStruct->initial_value) ;
	TIMER0_setCompareValue(configStruct->compare_value) ;
	/* setting the force compare bit 0 according  to the mode of the timer*/
	if(configStruct->mode == TIMER0_NORMAL_MODE || configStruct->mode == TIMER0_CTC_MODE)
	{
		/* in case of non-pwm mode */
		SET_BIT(TCCR0 , FOC0);
	}
	else
	{
		/* in case of a pwm mode */
		CLEAR_BIT(TCCR0 , FOC0);
	}
	if(configStruct->compare_match_action != TIMER0_NORMAL_OUTPUT )
	{
		/* for the signal pwm output pin (if pwm mode configured only) */
		SET_BIT(DDRB , 3); //OC0
		CLEAR_BIT(PORTB , 3); //OC0
	}
	/* setting the interrupt modes */
	TIMSK |= (configStruct->overflow_interrupt << TOIE0) | ((configStruct ->compare_interrupt)<<OCIE0);

	/* starting the timer NOW after all settings is done*/
	TCCR0 |=configStruct ->clock;

	/* enabling the global interrupt */
	ENABLE_GLOBAL_INTERRUPT();
}

void TIMER0_start(uint8 initial_count)
{
	/* setting the pre-scaler(assuming their bits are initially zeros) and the initial value of the counter register 0:255 */
//	TIMER0_stop() ; //ensures clearing first 3 bits, TCNT0
	TCNT0 = initial_count;
}


void TIMER0_setCompareValue(uint8 value)
{
	OCR0 = value;
}

void TIMER0_stop(void)
{
	CLEAR_BIT(TCCR0 , CS00);
	CLEAR_BIT(TCCR0 , CS01);
	CLEAR_BIT(TCCR0 , CS02);
	TCNT0 = 0 ;
}

void TIMER0_setCompareModeCallBack(void (*ptr)(void))
{
	g_T0CompareInterruptFunc_ptr = ptr;
}

void TIMER0_setOverflowModeCallBack(void (*ptr)(void))
{
	g_T0OverflowInterruptFunc_ptr = ptr;
}



ISR(TIMER0_COMP_vect)
{
	/* the corresponding interrupt service routine function (IF EXIST) will be executed*/
	if(g_T0CompareInterruptFunc_ptr != NULL)
	{
		g_T0CompareInterruptFunc_ptr();
	}
}


ISR(TIMER0_OVF_vect)
{
	/* the corresponding interrupt service routine function (IF EXIST) will be executed*/
	if(g_T0OverflowInterruptFunc_ptr != NULL)
	{
		g_T0OverflowInterruptFunc_ptr();
	}
}
