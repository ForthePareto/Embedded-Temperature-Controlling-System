/*
 * timer2.c
 *
 *  Created on: Jun. 8, 2021
 *      Author: Eslam Khaled Korany
 */

#include "timer2.h"

static void (*volatile g_T2CompareInterruptFunc_ptr)(void) = NULL;

static void (*volatile g_T2OverflowInterruptFunc_ptr)(void) = NULL;


// MISRA :note 9225: integral expression of underlying type 'signed char' cannot be implicitly converted to type 'volatile uint8' (aka 'volatile unsigned char') because it is not a wider integer type of the same signedness [MISRA 2004 Rule 10.1, required]
volatile uint8 g_T2nOverflows = 0 ;

void TIMER2_init(const TIMER2_config * configStruct)
{
	/* Mode setting: {NORMAL , PWM_PHASE_CORRECT, CTC, FAST_PWM}*/
	TCCR2 = configStruct->mode ;
	/*Setting compare match action {NORMAL, TOGGLE, CLEAR, SET}*/
	TCCR2 |= ((configStruct->compare_match_action) << COM20) ;
	/*Setting Counter registers initial values for normal and compare modes*/
	TIMER2_start(configStruct->initial_value);
	TIMER2_setCompareValue(configStruct->compare_value);

	/* setting the force compare bit 0 according  to the mode of the timer*/

	// MISRA :note 9050: dependence placed on operator precedence (operators '||' and '==') [MISRA 2004 Rule 12.1, advisory]
	// MISRA :note 9240: right side of logical operator '||' is not a primary expression [MISRA 2004 Rule 12.5, required]

	if(configStruct->mode == TIMER2_NORMAL_MODE || configStruct->mode == TIMER2_CTC_MODE)
	{
		/* in case of non-pwm mode */
		SET_BIT(TCCR2 , FOC2);
	}
	else
	{
		/* in case of a pwm mode */
		CLEAR_BIT(TCCR2 , FOC2);
	}
	if(configStruct->compare_match_action != TIMER2_NORMAL_OUTPUT )
	{
		/* for the signal pwm output pin (if pwm mode configured only) */
		SET_BIT(DDRD , 7); //OC2
		CLEAR_BIT(PORTD , 7); //OC2
	}
	/* setting the interrupt modes */
	TIMSK |= (configStruct->overflow_interrupt << TOIE2) | ((configStruct ->compare_interrupt)<<OCIE2);

	/* starting the timer NOW after all settings is done*/
	TCCR2 |=configStruct ->clock;

	/* enabling the global interrupt */
	ENABLE_GLOBAL_INTERRUPT();
}

 void TIMER2_start( uint8 initial_count)
{
	/* setting the pre-scaler (assuming their bits are initially zeros) and the initial value of the counter register 0:255 */
	TCNT2 = initial_count;
}


 void TIMER2_setCompareValue(uint8 value)
{
	OCR2 = value;
}

void TIMER2_stop(void)
{
	CLEAR_BIT(TCCR2 , CS20);
	CLEAR_BIT(TCCR2 , CS21);
	CLEAR_BIT(TCCR2 , CS22);
	TCNT0 = 0 ;

}

void TIMER2_setCompareModeCallBack(void (*ptr)(void))
{
	g_T2CompareInterruptFunc_ptr = ptr;
}

void TIMER2_setOverflowModeCallBack(void (*ptr)(void))
{
	g_T2OverflowInterruptFunc_ptr = ptr;
}



ISR(TIMER2_COMP_vect)
{
	/* the corresponding interrupt service routine function (IF EXIST) will be executed*/
	if(g_T2CompareInterruptFunc_ptr != NULL)
	{
		g_T2CompareInterruptFunc_ptr();
	}
}


ISR(TIMER2_OVF_vect)
{
	/* the corresponding interrupt service routine function (IF EXIST) will be executed*/
	if(g_T2OverflowInterruptFunc_ptr != NULL)
	{
		g_T2OverflowInterruptFunc_ptr();
	}
}
