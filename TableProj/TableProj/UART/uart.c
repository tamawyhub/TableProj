/*
 * uart.c
 *
 * Created: 11/20/2021 4:02:05 AM
 *  Author: ahmed
 */ 

#include "avr/io.h"
#include "uart.h"

void uart_init(uint32_t baudrate){
	uint16_t ubrr=(FOSC>>3)/baudrate-1;
	/*Set baud rate */
	UBRR0H = (uint8_t)(ubrr>>8);
	UBRR0L = (uint8_t)ubrr;
	UCSR0A|=(1<<U2X0);
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	/* Set frame format: 8data, 2stop bit */
	UCSR0C = (1<<USBS0)|(3<<UCSZ00);
}

void uart_transmit_byte(uint8_t data){
	/* Wait for empty transmit buffer */
	while (!(UCSR0A & (1<<UDRE0)));/* Put data into buffer, sends the data */
	UDR0 = data;
}

uint8_t uart_receive_byte(void){
	/* Wait for data to be received */
	while (!(UCSR0A & (1<<RXC0)));
	/* Get and return received data from buffer */
	return UDR0;
}

void uart_transmit_string(char *str){
	while(*str)
		uart_transmit_byte(*(str++));
}

void uart_receive_string(char *dst){
	*dst=1;
	while(*dst)
		*(dst++)=uart_receive_byte();
}
