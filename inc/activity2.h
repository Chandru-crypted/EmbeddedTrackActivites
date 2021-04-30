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
 * @brief ADC channel defined as channel 0
 * 
 */
#define ADC_channel (0) 

/**
 * @brief Include file used
 * 
 */
#include<avr/io.h>

/**
 * @brief Global variable ADC_value intialised as volatile
 * 
 */
extern uint16_t volatile ADC_value;

/**
 * @brief Initialise the Analog to digital converter
 * Steps followed
 * Decide the reference voltage -> AVCC with external capacitor at AREF pin
 * Switch on the ADC
 * Set the prescaler -> ADPS0 = 1, ADPS1 = HIGH, ADPS2 = HIGH, -> Division factor 128
 */
void init_ADC(void);
/**
 * @brief Read analog value from ADC_channnel
 * This uses the private function defined in activity2.c
 */
void ReadAdc(void);
/**
 * @brief Clear ADC reg
 * Clear ADCH
 * Clear ADCL
 */
void clear_ADC_value(void);

#endif