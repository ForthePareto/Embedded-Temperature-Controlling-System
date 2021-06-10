/*
 * schedular.c
 *
 *  Created on: Jun. 10, 2021
 *      Author: Eslam Khaled Korany
 */

#include "schedular.h"

void init_schedular(void (*periodic_func)(void)) {

	TIMER1_config T1_config = { TIMER1_CTC, TIMER1_F_CPU_64, ENABLE, ENABLE, 0,
			6249 }; //square wave generation mode to tick every 100ms
	TIMER1_init(&T1_config);
	TIMER1_setCompareModeCallBack(periodic_func);
}
