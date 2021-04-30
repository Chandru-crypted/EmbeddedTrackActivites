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
 * @brief LED state HIGH 
 */
#define LED_ON 	(0x01)					
/**
 * @brief LED state LOW 
 */
#define LED_OFF	(0x00)
/**
 * @brief LED PORT Specify the LED port
 * 
 */
#define LED_PORT (PORTC)
/**
 * @brief LED PIN  
 */			
#define LED_PIN (PORTC5) 
/**
 * @brief SEAT BUTTON PORT Specify the seat button port 
 */
#define SEAT_BUTTON_PORT (PORTD) 		
/**
 * @brief SEAT BUTTON PIN
 */
#define SEAT_BUTTON_PIN (PORTD2) 		
/**
 * @brief SEAT BUTTON PORT FOR INPUT
 */
#define SEAT_BUTTON_PORT_INPUT (PIND) 	
/**
 * @brief HEATER BUTTON PORT 
 */
#define HEATER_BUTTON_PORT (PORTD) 		
/**
 * @brief HEATER BUTTON  PIN
 */
#define HEATER_BUTTON_PIN (PORTD3) 		
/**
 * @brief HEATER BUTTON PORT FOR INPUT
 */
#define HEATER_BUTTON_PORT_INPUT (PIND) 

/**
 * @brief Include file used 
 * 
 */
#include<avr/io.h>


/**
 * @brief Intialise seat button
 * Set the data direction register to low, so it is made as an input
 * Set the Pin to be in pull up configuration
 */
void intialise_seat_button(void);
/**
 * @brief Intialise heater button
 * Set the data direction register to low, so it is made as an input
 * Set the Pin to be in pull up configuration
 */
void intialise_heater_button(void);
/**
 * @brief Intialise LED
 * Set the data direction register to be High, so it is made as output
 */
void intialise_LED(void);
/**
 * @brief Change the state of the LED Pin according to the value of state
 * 
 * @param state Pin level to which the LED Pin should be set
 */
void change_led_state(uint8_t state);
/**
 * @brief Checks if both switches are pressed at the time when the function is called
 * call heater_button state and seat_button_state to get the states of the buttons
 * And then check if both are pressed then return 1 or else return 0
 * @return uint8_t 
 * 		   check if both are pressed then return 1 or else return 0
 */
uint8_t check_if_both_switch_are_pressed(void);

#endif