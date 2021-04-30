/**
 * @file activity3.c
 * @author Channdrasekaran
 * @brief Activity 3 source file
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
#include "activity3.h"

/**
 * Private Function prototypes
 */
void change_PWM_width(uint8_t);
/**
 * Function Definitions
 */

/**
 * @brief Intialise PWM generation using timer 0
 * Timer 0 is a 8 bit timer
 * Choose the prescaler value as 256
 * Choose the Fast PWM - non inverting mode
 */
void init_PWM_gen_timer0(void){
	TCCR0A |= (1 << COM0A1); // selecting fast PWM
    TCCR0B |= (1 << CS01) | (1 << CS00); // set prescaler value to be 256
    TCCR0A |= (1 << WGM01) | (1 << WGM00); // set fast pwm using top value 0xFF
    DDRD |= (1 << PWM_gen_PIN);
    PWM_gen_PORT |= (1 << PWM_gen_PIN);
}

/**
 * @brief Change the PWM width to the value passed
 * @param width 
 */
void change_PWM_width(uint8_t width){
	PWM_width = width;
}

/**
 * @brief Change the PWM width based on the value passed
 * The width of the PWM signal changes based on the value
 * @param value 
 */
void change_PWM_width_using_conditions(uint16_t value){
	if (value <= 210){
		change_PWM_width(width_20_per_cent);
	}
	else if ((value <= 510)){
		change_PWM_width(width_40_per_cent);
	}
	else if ((value <= 710)){
		change_PWM_width(width_70_per_cent);
	}
	else if (value < 1024){
		change_PWM_width(width_95_per_cent);
	}
}