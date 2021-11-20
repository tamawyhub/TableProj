/*
 * pwm.c
 *
 * Created: 11/20/2021 5:56:26 AM
 *  Author: ahmed
 */ 

#include "avr/io.h"
#include "pwm.h"

void pwm_init(Timer_t timer){
	switch (timer){
	case T0:
		TCCR0A=3;  //fast pwm
		TCCR0B=2;  //fast pwm, 8 prescaler
		break;
	case T1:
		TCCR1A=1; //fast pwm 8 bit
		TCCR1B=10;//fast pwm 8 bit, 8 prescaler
		break;
	case T2:
		TCCR2A=3;  //fast pwm
		TCCR2B=2;  //fast pwm, 8 prescaler
		break;
	}
}

void pwm_set_duty(Timer_t timer, Channel_t com, uint8_t duty_percent){
	switch(timer){
	case T0:
		TCCR0A|=com;
		OCR0A=(duty_percent<<1)+(duty_percent>>1)+duty_percent/20;
		break;
	case T1:
		TCCR1A|=com;
		OCR1AL=(duty_percent<<1)+(duty_percent>>1)+duty_percent/20;
		break;
	case T2:
		TCCR2A|=com;
		OCR2A=(duty_percent<<1)+(duty_percent>>1)+duty_percent/20;
		break;
	}
}
