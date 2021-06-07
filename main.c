/*
 * main.c
 *
 *  Created on: Jun. 7, 2021
 *      Author: Eslam Khaled Korany
 */
#include "MCAL/micro_config.h"
#include "MCAL/TIMER0/timer0.h"

void toggle_pin(){

	TOGGLE_BIT(PORTA,1) ;
}

int main(){
	SET_BIT(DDRA,1) ;
	TIMER0_config T0_config = {TIMER0_NORMAL_MODE,TIMER0_NORMAL_OUTPUT,TIMER0_F_CPU_1024,ENABLE,DISABLE,0,250} ;
	TIMER0_init(&T0_config) ;
	TIMER0_setOverflowModeCallBack(toggle_pin) ;
	while(1){

	}

}
