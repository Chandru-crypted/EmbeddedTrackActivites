/**
 * @file activity3.h
 * @author Chandrasekaran
 * @brief 
 * @version 0.1
 * @date 2021-04-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __ACTIVITY3_H__
#define __ACTIVITY3_H__

/**
 * @brief Macro definitions 
 * 
 */
#define PWM_gen_PIN (PORTD6)
#define PWM_gen_PORT (PORTD)
#define PWM_width (OCR0A)
#define width_20_per_cent (52)
#define width_40_per_cent (103)
#define width_70_per_cent (180)
#define width_95_per_cent (244)

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
void init_PWM_gen_timer0(void);
void change_PWM_width_using_conditions(uint16_t);
#endif