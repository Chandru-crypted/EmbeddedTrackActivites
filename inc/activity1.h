/**
 * @file activity1.h
 * @author Chandrasekaran
 * @brief Activity 1 contains the macro defintions and helper functions associated with LED, Heater button, Seater button
 * @version 0.1
 * @date 2021-04-27
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef __ACTIVITY1_H__
#define __ACTIVITY1_H__

/**
 * @brief Macro definitions 
 * 
 */
#define LED_ON 	(0x01)			/**< LED state HIGH */
#define LED_OFF	(0x00)			/**< LED state LOW */
#define LED_PORT (PORTC) /**< LED PORT*/
#define LED_PIN (PORTC5) /** < LED PIN */ 

#define SEAT_BUTTON_PORT (PORTD) /**< SEAT BUTTON PORT */
#define SEAT_BUTTON_PIN (PORTD2) /** < SEAT BUTTON PIN */
#define SEAT_BUTTON_PORT_INPUT (PIND) /** <SEAT BUTTON PORT FOR INPUT */
 
#define HEATER_BUTTON_PORT (PORTD) /** < HEATER BUTTON PORT */
#define HEATER_BUTTON_PIN (PORTD3) /** < HEATER BUTTON  PIN */
#define HEATER_BUTTON_PORT_INPUT (PIND) /** <HEATER BUTTON PORT FOR INPUT */

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
void intialise_seat_button(void);
void intialise_heater_button(void);
void intialise_LED(void);
void change_led_state(uint8_t state);
uint8_t check_if_both_switch_are_pressed(void);

#endif