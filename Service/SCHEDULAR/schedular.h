/*
 * schedular.h
 *
 *  Created on: Jun. 10, 2021
 *      Author: Eslam Khaled Korany
 */

#ifndef SERVICE_SCHEDULAR_SCHEDULAR_H_
#define SERVICE_SCHEDULAR_SCHEDULAR_H_

#include "../../MCAL/micro_config.h"
#include "../../MCAL/TIMER1/timer1.h"


void init_schedular(void (*periodic_func)(void)) ;



#endif /* SERVICE_SCHEDULAR_SCHEDULAR_H_ */
