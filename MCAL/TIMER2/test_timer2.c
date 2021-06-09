///*
// * test_timer2.c
// *
// *  Created on: Jun. 9, 2021
// *      Author: Eslam Khaled Korany
// */
//
//
//#include "../micro_config.h"
//#include "timer2.h"
//
////uint8 count = 0 ;
//void toggle_pin(){
////	  g_T2nOverflows++;
//	TOGGLE_BIT(PORTA,1) ;
//}
//
//int main(){
//	SET_BIT(DDRA,1) ;
//	DDRA =0xFF ;
//	TIMER2_config T2_config = {TIMER2_CTC_MODE,TIMER2_NORMAL_OUTPUT,TIMER2_F_CPU_1024,ENABLE,ENABLE,250,255} ; //square wave generation mode
//	TIMER2_init(&T2_config) ;
//	TIMER2_setCompareModeCallBack(&toggle_pin) ;
////	TIMER2_start(250) ;
//
//	while(1){
//
//	}
//
//}
