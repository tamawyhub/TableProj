/*
 * pwm.h
 *
 * Created: 11/20/2021 5:55:44 AM
 *  Author: ahmed
 */ 


#ifndef PWM_H_
#define PWM_H_


typedef enum {T0,T1,T2} Timer_t;
typedef enum {CHA=0x80,CHB=0x20} Channel_t;

void pwm_init(Timer_t timer);
void pwm_set_duty(Timer_t timer, Channel_t channel, uint8_t duty_percent);



#endif /* PWM_H_ */