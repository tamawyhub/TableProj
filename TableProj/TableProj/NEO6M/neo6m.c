/*
 * neo6m.c
 *
 * Created: 11/20/2021 11:20:56 PM
 *  Author: ahmed
 */ 
#include "avr/io.h"
#include "avr/interrupt.h"
#include "uart.h"
#include <stdio.h>
#include "neo6m.h"

void gps_init(){
	uart_init(9600);
	const uint8_t init[]={0xB5,0x62,0x06,0x01,0x08,0x00,0xF0,0x04,0x00,0x00,0x00,0x00,0x00,0x01,0x04,0x40
						  //0xB5,0x62,0x06,0x08,0x06,0x00,0xC8,0x00,0x01,0x00,0x01,0x00,0xDE,0x6A
						  };
	for (uint8_t i = 0; i < 16; i++)
		uart_transmit_byte(init[i]);
}

static uint16_t longitude, latitude;

ISR(USART_RX_vect){
	if (uart_receive_byte()!='$') return;
	char resp[50];
	const char addr[]="$GPGGA";
	int i=6;
	while(i--){
		if (uart_receive_byte()!=addr[5-i]) return;
	}
	uart_receive_string(resp);
	uint16_t longit, latit;
	if (sscanf(resp,"%*[0-9.],%d.%*[0-9],%*[NS],%d.%*[0-9],%*[EW]",&latit,&longit)!=2) //error, return
	return;
	longitude=longit, latitude=latit;
}
