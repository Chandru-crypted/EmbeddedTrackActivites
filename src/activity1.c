/**
 * @file activity1.c
 * @author Chandrasekaran
 * @brief Activity 1 source file
 * @version 0.1
 * @date 2021-04-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */

/**
 * @brief Include files
 * 
 */
#include <avr/io.h>
#include "activity1.h"

/**
 * Private Function prototypes
 */
uint8_t seat_button_state(void);
uint8_t heater_button_state(void);

/**
 * Function Definitions
 */

/**
 * @brief Intialise seat button
 * Set the data direction register to low, so it is made as an input
 * Set the Pin to be in pull up configuration
 */
void intialise_seat_button(void){
	DDRD &= ~(1 << SEAT_BUTTON_PIN);
    SEAT_BUTTON_PORT |= (1 << SEAT_BUTTON_PIN);
}

/**
 * @brief Intialise heater button
 * Set the data direction register to low, so it is made as an input
 * Set the Pin to be in pull up configuration
 */
void intialise_heater_button(void){
	DDRD &= ~(1 << HEATER_BUTTON_PIN);
    HEATER_BUTTON_PORT |= (1 << HEATER_BUTTON_PIN);
}

/**
 * @brief Intialise LED
 * Set the data direction register to be High, so it is made as output
 */
void intialise_LED(void){
	DDRC |= (1 << LED_PIN);
}


/**
 * @brief Change the state of the LED Pin according to the value of state
 * 
 * @param state Pin level to which the LED Pin should be set
 */
void change_led_state(uint8_t state){
	LED_PORT = (state << LED_PIN);
}

/**
 * @brief Checks the state of seat button
 * The switches are in a pull up configuration , that means when there is not input it is read as High
 * When the switch is pressed the port will change to Low
 * So to check if the switch is pressed we are negating the content in the port and checking whether both the switches are high
 * 
 * @return uint8_t 
 */
uint8_t seat_button_state(void){
	return (!(SEAT_BUTTON_PORT_INPUT & (1 << SEAT_BUTTON_PIN)));
}

/**
 * @brief Checks the state of heater button
 * The switches are in a pull up configuration , that means when there is not input it is read as High
*  When the switch is pressed the port will change to Low
*  So to check if the switch is pressed we are negating the content in the port and checking whether both the switches are high
 * 
 * @return uint8_t 
 */
uint8_t heater_button_state(void){
	return (!(HEATER_BUTTON_PORT_INPUT & (1 << HEATER_BUTTON_PIN)));
}

/**
 * @brief Checks if both switches are pressed at the time when the function is called
 * call heater_button state and seat_button_state to get the states of the buttons
 * And then check if both are pressed then return 1 or else return 0
 * @return uint8_t 
 * 		   check if both are pressed then return 1 or else return 0
 */
uint8_t check_if_both_switch_are_pressed(void){
	if (heater_button_state() && seat_button_state()){
		return (1);
	}
	else{
		return (0);
	}
}