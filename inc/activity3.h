/**
 * @file activity3.h
 * @author Chandrasekaran
 * @brief Activity 3 contains macros and helper functions associated with PWM generation
 * @version 0.1
 * @date 2021-04-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __ACTIVITY3_H__
#define __ACTIVITY3_H__

/**
 * @brief PWM generation pin number
 */
#define PWM_gen_PIN (PORTD6)
/**
 * @brief PWM generation port
 */
#define PWM_gen_PORT (PORTD)
/**
 * @brief PWM width (Non inverting mode)
 */
#define PWM_width (OCR0A)
/**
 * @brief Width 20 per cent value (20 / 100) * (256)
 */
#define width_20_per_cent (52)
/**
 * @brief Width 40 per cent value (40 / 100) * (256)
 */
#define width_40_per_cent (103)
/**
 * @brief Width 70 per cent value (70 / 100) * (256)
 */
#define width_70_per_cent (180)
/**
 * @brief Width 95 per cent value (95 / 100) * (256)
 */
#define width_95_per_cent (244)

/**
 * @brief Include files
 * 
 */
#include<avr/io.h>

/**
 * @brief Intialise PWM generation using timer 0
 * Timer 0 is a 8 bit timer
 * Choose the prescaler value as 256
 * Choose the Fast PWM - non inverting mode
 */
void init_PWM_gen_timer0(void);
/**
 * @brief Change the PWM width based on the value passed
 * The width of the PWM signal changes based on the value
 * @param value 
 */
void change_PWM_width_using_conditions(uint16_t);
#endif