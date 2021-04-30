/**
 * @file activity2.h
 * @author Chandrasekaran
 * @brief Activity 2 contains the macro defintions and helper functions associated with reading temperature value using ADC
 * @version 0.1
 * @date 2021-04-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __ACTIVITY2_H__
#define __ACTIVITY2_H__

/**
 * @brief Macro definitions 
 * 
 */
#define ADC_channel (0) 

/**
 * @brief Include files
 * 
 */
#include<avr/io.h>

/**
 * @brief Global variables 
 * 
 */
extern uint16_t volatile ADC_value;

/**
 * @brief Public Function Prototypes
 * 
 * 
 */
void init_ADC(void);
void ReadAdc(void);
void clear_ADC_value(void);

#endif