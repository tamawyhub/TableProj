/*
 * TableProj.c
 *
 * Created: 11/20/2021 3:57:48 AM
 * Author : ahmed
 */ 
#include "stdint.h"
#include "avr/interrupt.h"
#include "neo6m.h"
#include "uart.h"
#include <avr/io.h>
#include "stdio.h"

static uint16_t counter=0;
static char buff[50];

ISR(PCINT0_vect){
	if (PINB&(1<<PORTB4))
		counter++;
}
void hall_test(){
	PCICR=7;
	PCMSK0=1<<PCINT4;
	sei();
}


int main(void)
{
	uart_init(9600);
	cli();
	hall_test();
    /* Replace with your application code */
    while (1) 
    {
		sprintf(buff,"%d\r\n",counter);
		uart_transmit_string(buff);
    }
}

