///*
// * main.c
// *
// *  Created on: Jun. 7, 2021
// *      Author: Eslam Khaled Korany
// */
//#include "MCAL/micro_config.h"
//#include "MCAL/TIMER0/timer0.h"
//#include "MCAL/TIMER2/timer2.h"
//
////uint8 count = 0 ;
//void toggle_pin(){
////	  g_T0nOverflows++;
//	TOGGLE_BIT(PORTA,1) ;
//}
//
//int main(){
//	SET_BIT(DDRA,1) ;
//	DDRA =0xFF ;
//	TIMER2_config T2_config = {TIMER2_CTC_MODE,TIMER2_TOGGLE_OUTPUT,TIMER2_F_CPU_1024,DISABLE,ENABLE,0,255} ; //square wave generation mode
//	TIMER2_init(&T2_config) ;
////	TIMER0_setOverflowModeCallBack(&toggle_pin) ;
////	TIMER0_start(TIMER0_F_CPU_1024 , 0) ;
//
//	while(1){
//
//	}
//
//}

//
//#include "MCAL/PWM0/pwm0.h"
////#include "MCAL/TIMER0/timer0.h"
//
//
//int main(){
//	PWM0_init(TIMER0_F_CPU_8,PWM_FAST_MODE);
//	PWM0_start(0.25);
////	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS00);
////	DDRB|=(1<<PB3);  /*set OC0 pin as output*/
////	TIMER0_config T0_config = {TIMER0_FAST_PWM_MODE,TIMER0_SET_OUTPUT,TIMER0_F_CPU_256,DISABLE,DISABLE,0,63} ; //square wave generation mode
////		TIMER0_init(&T0_config) ;
////	TIMER0_start(TIMER0_F_CPU_64 , 0) ;
//	while(1){
//
//	}
//
//}
