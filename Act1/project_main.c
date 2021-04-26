/**
 * @file project_main.c
 * @author Chandrasekaran
 * @brief Project to switch on a LED if both the buttons are pressed
 * @version 0.1
 * @date 2021-04-26
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <avr/io.h>
#include<util/delay.h>
#include "project_config.h"

int main(void)
{	
	/**
	 * @brief Setting up the LED port to be output
	 * 
	 */
    DDRD |= (1 << PD6);

	/**
	 * @brief Setting up the Heater button port 
	 * 
	 */
    DDRD &= ~(1 << PD5); 
    PORTD |= (1 << PD5); 

	/**
	 * @brief Setting up the seat button port
	 * 
	 */
    DDRB &= ~(1 << PB1); 
	PORTB |= (1 << PB1);


    while(1){
        if ((!(PIND&(1 << PD5))) && (!(PINB & (1 << PB1)))){
            PORTD |= (1 << PD6);
            _delay_ms(200);
        }
        else{
            PORTD &= ~(1 << PD6);
            _delay_ms(200);
        }
    }
    return 0;
}
