
#include "pwm0.h"
//#include "MCAL/TIMER0/timer0.h"


int main(){
	PWM0_init(TIMER0_F_CPU_8,PWM_FAST_MODE);
	PWM0_start(0.25);
	while(1){

	}

}
