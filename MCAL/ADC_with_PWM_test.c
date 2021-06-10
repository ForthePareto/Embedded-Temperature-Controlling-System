///*
// * ADC_with_PWM_test.c
// *
// *  Created on: Jun. 9, 2021
// *      Author: Eslam Khaled Korany
// */
//
//#include "ADC/adc.h"
//#include "micro_config.h"
//#include "PWM0/PWM0.h"
//#include "TIMER2/timer2.h"
//
//
//static volatile float64 calibrator = 0;
//
//void update_calibrator(void) {
//
//	g_T2nOverflows++;
//	if (10 == g_T2nOverflows) {
//
//		calibrator = (float64)ADC_reading/1024.0 ;
//		g_T2nOverflows = 0;
//
//
//	}
//}
//
//int main() {
//
//	TIMER2_config T2_config = { TIMER2_CTC_MODE, TIMER2_NORMAL_OUTPUT,
//			TIMER2_F_CPU_1024, ENABLE, ENABLE, 0, 195 }; //square wave generation mode
//	TIMER2_init(&T2_config);
//	TIMER2_setCompareModeCallBack(&update_calibrator);
//
//	ADC_config adc_config  = { AVCC, POLLING , ADC_F_CPU_32 };
//	ADC_init(&adc_config);
//
//
//
//
//	PWM0_init(TIMER0_F_CPU_8, PWM_FAST_MODE);
//	while (1) {
//
//		ADC_readChannel(&adc_config  ,ADC0);
//		PWM0_start(calibrator);
//
//
//	}
//}
