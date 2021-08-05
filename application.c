#include "MCAL/micro_config.h"
#include "MCAL/TIMER1/timer1.h"
#include "MCAL/ADC/adc.h"
#include "MCAL/PWM0/PWM0.h"
#include "Service/SCHEDULAR/schedular.h"

// STATE macros
#define STATE_STANDBY   0
#define STATE_OPERATION 1
#define STATE_NORMAL    2
#define STATE_ERROR     3

volatile uint8 usrInput[2] = "25";
uint8 setTemp[2] = "25"; //default 25
uint8 crTemp[2] = "FF";
volatile uint8 Compare[2] = "25";
volatile uint8 idx = 0x00;

volatile uint8 pressedBtn = 'F';

volatile uint8 CURRENT_STATE = 0;
uint8 SET_TEMP = 25;
uint8 CURRENT_TEMP = 25;
volatile uint8 CHECK_TEMP = ENABLE;
volatile uint8 CHECK_ADC = DISABLE;
volatile uint8 NOT_HEATING = FALSE;

volatile uint16 NOT_HEATING_watcher = (uint16) 0;
ADC_config adc_config = { AVCC, POLLING, ADC_F_CPU_32 };

volatile float64 CALIBRATOR = (float64) 0;

void updateTemp(void);
void updateCalibrator(void);
void setPWM(void);
void string_to_int_temp(uint8 *temp, uint8 *TEMP);

void update_time(void) {
	//one tick means 100ms passed
	g_T1nOverflows++;
	if ((g_T1nOverflows % 2 == 0)
			&& ((CURRENT_STATE == STATE_NORMAL)
					|| (CURRENT_STATE == STATE_OPERATION))) {
		CHECK_TEMP = ENABLE;
	}
	if ((g_T1nOverflows % 5 == 0)
			&& ((CURRENT_STATE == STATE_NORMAL)
					|| (CURRENT_STATE == STATE_OPERATION))) {
		CHECK_ADC = ENABLE;
	}

	if ( (CURRENT_STATE == STATE_OPERATION) && ((SET_TEMP > CURRENT_TEMP) && ((SET_TEMP - CURRENT_TEMP) > 5))) {
		NOT_HEATING_watcher++;
	}
	else{
		NOT_HEATING_watcher = 0 ;
	}
	if ((NOT_HEATING_watcher >= (uint16)1800) && (CURRENT_STATE == STATE_OPERATION)) //ERROR STATE
	{
			CURRENT_STATE = STATE_ERROR;
			DSPLAY_IDLEscreen((uint8*) setTemp, (uint8) CURRENT_STATE, crTemp);
			g_T1nOverflows = 0 ; //reset clock
	}

}

int main(void) {
	init_schedular(update_time);
	KEYPAD_Init();
	TC72_Init();
	DISPLAY_Init();
	ADC_init(&adc_config);
	PWM0_init(TIMER0_F_CPU_8, PWM_FAST_MODE);

	DISPLAY_Welcome();
	DSPLAY_IDLEscreen((uint8*) setTemp, (uint8) CURRENT_STATE, crTemp);
	while (1) {
		updateTemp(); // every 200ms
		setPWM();
		updateCalibrator();  //500ms
		if (CURRENT_STATE == STATE_OPERATION) {
			if ((CURRENT_TEMP > SET_TEMP) && ((CURRENT_TEMP - SET_TEMP) <= 5)) {
				CURRENT_STATE = STATE_NORMAL;
				DSPLAY_IDLEscreen((uint8*) setTemp, (uint8) CURRENT_STATE,
						crTemp);
				NOT_HEATING_watcher = 0 ;
			} else if ((CURRENT_TEMP < SET_TEMP)
					&& ((SET_TEMP - CURRENT_TEMP) <= 5)) {
				CURRENT_STATE = STATE_NORMAL;
				NOT_HEATING_watcher = 0 ;
				DSPLAY_IDLEscreen((uint8*) setTemp, (uint8) CURRENT_STATE,
						crTemp);

			} else if ((CURRENT_TEMP > SET_TEMP)
					&& ((CURRENT_TEMP - SET_TEMP) > 10)) {

				CURRENT_STATE = STATE_ERROR;
				DSPLAY_IDLEscreen((uint8*) setTemp, (uint8) CURRENT_STATE,
						crTemp);
			}

//			else if ((SET_TEMP > CURRENT_TEMP)
//					&& ((SET_TEMP - CURRENT_TEMP) > 5)) {
//				NOT_HEATING = TRUE;
//				// for 3 minutes
//				//CURRENT_STATE = STATE_ERROR;
//				//DSPLAY_IDLEscreen((uint8*) setTemp, (uint8) CURRENT_STATE, crTemp);
//			}
		}
		if (CURRENT_STATE == STATE_NORMAL) {
			if ((CURRENT_TEMP > SET_TEMP) && ((CURRENT_TEMP - SET_TEMP) > 5)) {
				CURRENT_STATE = STATE_OPERATION;
				NOT_HEATING_watcher = 0 ;
				DSPLAY_IDLEscreen((uint8*) setTemp, (uint8) CURRENT_STATE,
						crTemp);
			} else if ((CURRENT_TEMP < SET_TEMP)
					&& ((SET_TEMP - CURRENT_TEMP) > 5)) {
				CURRENT_STATE = STATE_OPERATION;
				NOT_HEATING_watcher = 0 ;
				DSPLAY_IDLEscreen((uint8*) setTemp, (uint8) CURRENT_STATE,
						crTemp);
			}
		}


	}
	return 0;

}

void updateTemp(void) {
	if (CHECK_TEMP == ENABLE) {
		TC72_getTemp();
		if ((crTemp[0] != Compare[0]) || (crTemp[1] != Compare[1])) {
			Compare[0] = crTemp[0];
			Compare[1] = crTemp[1];
			DSPLAY_IDLEscreen((uint8*) setTemp, (uint8) CURRENT_STATE, crTemp);
			string_to_int_temp(crTemp, &CURRENT_TEMP);
		}
		CHECK_TEMP = DISABLE;
	}
}

void updateCalibrator(void) {
	if (CHECK_ADC == ENABLE) {
		ADC_readChannel(&adc_config, ADC0);
		CALIBRATOR = (float64) ADC_reading / 1024.0; //0-1
		CHECK_ADC = DISABLE;
	}
}
void setPWM(void) {
	if (CURRENT_STATE == STATE_OPERATION) {
		float64 vt = (((float64) SET_TEMP - CURRENT_TEMP) / 10.0); //0-1
		float64 duty = (vt * CALIBRATOR);
		PWM0_restart(duty, TIMER0_F_CPU_8);
		//PWM0_restart(0.5,TIMER0_F_CPU_8);
	} else {
		PWM0_stop();
	}
}

void string_to_int_temp(uint8 *temp, uint8 *TEMP) {
	uint8 x = convertCharInt(temp[0]);
	uint8 y = convertCharInt(temp[1]);
	*TEMP = y + (10 * x);
}

// MISRA: Special function
ISR(INT0_vect) {
	pressedBtn = KeyPad_GetKeyC0();
	if ((pressedBtn == '*')
			&& ((CURRENT_STATE == STATE_OPERATION)
					|| (CURRENT_STATE == STATE_NORMAL))) {
		if (idx == 1) {
			setTemp[0] = '0';
			setTemp[1] = usrInput[0];
			TOGGLE_BIT(idx, 0);
			DSPLAY_IDLEscreen((uint8*) setTemp, (uint8) CURRENT_STATE, crTemp);
			string_to_int_temp(setTemp, &SET_TEMP);
		} else if (idx == 0) {
			setTemp[0] = usrInput[0];
			setTemp[1] = usrInput[1];
			DSPLAY_IDLEscreen((uint8*) setTemp, (uint8) CURRENT_STATE, crTemp);
			string_to_int_temp(setTemp, &SET_TEMP);
		}
	} else if ((CURRENT_STATE == STATE_OPERATION)
			|| (CURRENT_STATE == STATE_NORMAL)) {
		usrInput[idx] = pressedBtn;
		TOGGLE_BIT(idx, 0);
	}
}

// MISRA: Special function can be redifined
ISR(INT1_vect) {
	if ((CURRENT_STATE == STATE_OPERATION) || (CURRENT_STATE == STATE_NORMAL)) {
		pressedBtn = KeyPad_GetKeyC1();
		usrInput[idx] = pressedBtn;
		TOGGLE_BIT(idx, 0);
	}

}


// MISRA: Special function can be redifined
ISR(INT2_vect) {
	pressedBtn = KeyPad_GetKeyC2();
	if (pressedBtn == (uint8) '#') {
		if (CURRENT_STATE == STATE_STANDBY) {
			CURRENT_STATE = (uint8) STATE_OPERATION;
		} else if (CURRENT_STATE == STATE_OPERATION) {
			CURRENT_STATE = (uint8) STATE_STANDBY;
		}
		DSPLAY_IDLEscreen((uint8*) setTemp, (uint8) CURRENT_STATE, crTemp);
	} else if ((CURRENT_STATE == STATE_OPERATION)
			|| (CURRENT_STATE == STATE_NORMAL)) {
		usrInput[idx] = pressedBtn;
		TOGGLE_BIT(idx, 0);
	}
}
