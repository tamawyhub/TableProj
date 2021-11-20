/*
 * uart.h
 *
 * Created: 11/20/2021 4:02:25 AM
 *  Author: ahmed
 */ 


#ifndef UART_H_
#define UART_H_


#ifndef FOSC
#define FOSC 1843200 // Clock Speed
#endif

void uart_init(uint32_t baudrate);
void uart_transmit_byte(uint8_t data);
uint8_t uart_receive_byte(void);
void uart_transmit_string(char *str);
void uart_receive_string(char *dst);


#endif /* UART_H_ */