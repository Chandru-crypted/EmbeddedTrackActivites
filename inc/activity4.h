/**
 * @file activity4.h
 * @author Chandrasekaran
 * @brief 
 * @version 0.1
 * @date 2021-04-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __ACTIVITY4_H__
#define __ACTIVITY4_H__

/**
 * @brief Macro definitions 
 * 
 */


/**
 * @brief Include files
 * 
 */
#include<avr/io.h>

/**
 * @brief Public Function Prototypes
 * 
 * 
 */
void USARTInit(uint16_t);
void UARTWriteChar(uint8_t);
void USARTWriteChar_based_on_condition(uint16_t);
#endif