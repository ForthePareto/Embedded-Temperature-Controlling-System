/*
 * main.c
 *
 *  Created on: Jun. 7, 2021
 *      Author: Eslam Khaled Korany
 */
#include "MCAL/micro_config.h"
#include "MCAL/TIMER0/timer0.h"
//uint8 count = 0 ;
void toggle_pin(){
//	  g_T0nOverflows++;
	TOGGLE_BIT(PORTA,1) ;
}

int main(){
	SET_BIT(DDRA,1) ;
	DDRA =0xFF ;
	TIMER0_config T0_config = {TIMER0_CTC_MODE,TIMER0_TOGGLE_OUTPUT,TIMER0_F_CPU_1024,DISABLE,ENABLE,0,128} ; //square wave generation mode
	TIMER0_init(&T0_config) ;
//	TIMER0_setOverflowModeCallBack(&toggle_pin) ;
//	TIMER0_start(TIMER0_F_CPU_1024 , 0) ;

	while(1){

	}

}
