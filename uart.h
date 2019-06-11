/*
 * uart.h
 *
 * Created: 5/9/2019 9:53:41 PM
 *  Author: Admin
 */ 


#ifndef UART_H_
#define UART_H_
#define F_CPU 16000000UL			/* Define frequency here its 8MHz */
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//#define USART_BAUDRATE 9600
#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)


void UART_init(long USART_BAUDRATE);

unsigned char UART_RxChar();

void UART_TxChar(char ch);

void UART_SendString(unsigned char *str);

#endif /* UART_H_ */