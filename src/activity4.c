/**
 * @file activity4.c
 * @author Channdrasekaran
 * @brief 
 * @version 0.1
 * @date 2021-04-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */

/**
 * @brief Include files
 * 
 */
#include <avr/io.h>
#include "activity4.h"

/**
 * Private Function prototypes
 */

/**
 * Function Definitions
 */

/**
 * @brief Initialize usart
 * 
 * @param ubrr_value 
 */
void USARTInit(uint16_t ubrr_value){
	// for example the ubrr value must be 103 for 9600 baud rate
	UBRR0L = ubrr_value;
	UBRR0H = ((ubrr_value >> 8)&(0x0ff));

	// set the async bit
	UCSR0C |= (1 << UMSEL00);
	// setting the character size - 8 bit
	UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00); 

	// set the Rx enable and Tx enable
	UCSR0B |= (1<<TXEN0) | (1 << RXEN0);
}

/**
 * @brief write to usart the char value passed
 * 
 * @param data 
 * 		  this is a character
 */
void UARTWriteChar(uint8_t data){
	// wait for data reg to be empty
	while (!(UCSR0A & (1<<UDRE0)));
	UDR0 = data;
	while (!(UCSR0A & (1<<UDRE0)));
}

/**
 * @brief Write to USART based on the condition 
 * 
 * @param value 
 * 		  this is a 16 bit value this is actually a 10 bit value to be supplied
 */
void USARTWriteChar_based_on_condition(uint16_t value){
	if (value <= 210){
		UARTWriteChar('2');
        UARTWriteChar('0');
        UARTWriteChar('C');
        UARTWriteChar('\n');	
	}
	else if ((value <= 510)){
		UARTWriteChar('2');
        UARTWriteChar('5');
        UARTWriteChar('C');
        UARTWriteChar('\n');
	}
	else if ((value <= 710)){
		UARTWriteChar('2');
        UARTWriteChar('9');
        UARTWriteChar('C');
        UARTWriteChar('\n');
	}
	else if (value < 1024){
		UARTWriteChar('3');
        UARTWriteChar('3');
        UARTWriteChar('C');
        UARTWriteChar('\n');
	}
}
