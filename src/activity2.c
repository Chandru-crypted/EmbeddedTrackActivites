/**
 * @file activity2.c
 * @author Chandrasekaran
 * @brief Activity2 source file
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
#include "activity2.h"


uint16_t ReadAdc_channel_input(uint8_t);

/**
 * @brief Initialise the Analog to digital converter
 * Steps followed
 * Decide the reference voltage -> AVCC with external capacitor at AREF pin
 * Switch on the ADC
 * Set the prescaler -> ADPS0 = 1, ADPS1 = HIGH, ADPS2 = HIGH, -> Division factor 128
 */
void init_ADC(void){
    ADMUX |= (1 << REFS0); // Decide the ref voltage
    ADCSRA = (1 << ADEN); // Switch on the ADC
    ADCSRA |= (7 << ADPS0); // set the prescaler
}

/**
 * @brief Read the Analog value from the specific channel
 * Steps followed
 * Clearing the mux bits, the mux bits are present in the last right most bits
 * Channel which was input to the function from that we select only the right most 3 bits  
 * Select channel
 * Start conversion
 * Wait for conversion 
 * Return ADC 
 * @param channel
 *		  the channel from which Analog value be read
 * @return uint16_t 
 * 		   The resolution of ADC is 10bits so return a 16 bit value 
 */
uint16_t ReadAdc_channel_input(uint8_t channel){
    ADMUX &= ~(7); // clearing the mux bits
    //the mux bits are present in the last right most bits
    channel = channel & 7; // make the channel bits proper
    ADMUX |= channel; // select the channel
    ADCSRA |= (1 << ADSC); // start conversion

    while (!(ADCSRA & (1 << ADIF))); // wait for conversion
    // i.e till ADIF in ADSCRA becomes 1

    ADCSRA &= ~(1 << ADIF);
    // clear ADIF

    return (ADC);
}

/**
 * @brief Read analog value from ADC_channnel
 * This uses the private function defined in activity2.c
 */
void ReadAdc(void){
	ADC_value = 0;
	ADC_value = ReadAdc_channel_input(ADC_channel);
}

/**
 * @brief Clear ADC reg
 * Clear ADCH
 * Clear ADCL
 */
void clear_ADC_value(void){
	ADC_value = 0;
}