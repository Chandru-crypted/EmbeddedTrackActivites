#ifndef __PROJECT_CONFIG_H__
#define __PROJECT_CONFIG_H__
/**
 * @file project_config.h
 * @author Chandrasekaran
 * @brief Configuration file to define pins and ports for the interfaced peripherals
 * @version 0.1
 * @date 2021-04-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */

/**
 * Macro Definitions
 */

#define F_CPU 16000000UL 	/**< Clock Frequency of MCU is 16 MHz */

// #define LED_PORT (PORTB)    /**< LED Port Number */
// #define LED_PIN  (PORTB0)   /**< LED Pin number  */

/* Using the variable to remember the state of switches*/
unsigned volatile switch_state1 = 0; 
unsigned volatile switch_state2 = 0;

/* Function for changing the switch states*/
void change_switch_state1(void);
void change_switch_state2(void);


#endif /* __PROJECT_CONFIG_H__ */