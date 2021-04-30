/**
 * @file activity4.h
 * @author Chandrasekaran
 * @brief Activity 4 contains macros and helper functions associated with UART for communicatino with MC and computer
 * @version 0.1
 * @date 2021-04-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __ACTIVITY4_H__
#define __ACTIVITY4_H__

/**
 * @brief Include files
 * 
 */
#include<avr/io.h>

/**
 * @brief Initialize usart
 * 
 * @param ubrr_value 
 */
void USARTInit(uint16_t);
/**
 * @brief write to usart the char value passed
 * 
 * @param data 
 * 		  this is a character
 */
void UARTWriteChar(uint8_t);
/**
 * @brief Write to USART based on the condition 
 * 
 * @param value 
 * 		  this is a 16 bit value this is actually a 10 bit value to be supplied
 */
void USARTWriteChar_based_on_condition(uint16_t);
#endif