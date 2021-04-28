/**
 * @file project_main.c
 * @author Chandrasekaran
 * @brief Project to switch on LED if both the switches are pressed using external interrupts
 * @version 0.1
 * @date 2021-04-27
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>
#include<project_config.h> 

int main(void)
{
	/**
	 * @brief Making the PD6 as LED output
	 * 
	 */
    DDRD |= (1 << PD6);

	/**
	 * @brief Making the ISC00 bit Low
	 * By making it low, the interrupt flag is raised when there is a level change in PD2
	 * 
	 */
    EICRA |= (1 << ISC00);
	/**
	 * @brief Masking register for intialising PD2 as external interrupt
	 * 
	 */
    EIMSK |= (1 << INT0); 
		/**
	 * @brief Making the ISC00 bit Low
	 * By making it low, the interrupt flag is raised when there is a level change in PD3
	 * 
	 */
	EICRA |= (1 << ISC10);
	/**
	 * @brief Masking register for intialising PD3 as external interrupt
	 * 
	 */
    EIMSK |= (1 << INT1);

	/**
	 * @brief Setting the global interrupt flag
	 * 
	 */
	sei(); 

    DDRD &= ~(1 << PD2);
    PORTD |= (1 << PD2);

    DDRD &= ~(1 << PD3);
    PORTD |= (1 << PD3);

    while(1){
        if ((1 == switch_state1) && (1 == switch_state2)){
            PORTD |= (1 << PD6);
            _delay_ms(500);
        }
        else{
            PORTD &= ~(1 << PD6);
            _delay_ms(200);
        }
    }
    return 0;
}

/**
 * @brief Change the state of the switch 1
 * Read the value in PD2, if it is High then the switch is open
 * If PD2 value is Low , then the switch is Closed
 * The value of PD2 is determined by reading the register PIND 
 */
void change_switch1_state(void){
	if (!(PIND&(1 << PD2))){
		switch_state1 = 1;
	}
	else{
		switch_state1 = 0;
	}
}

/**
 * @brief Change the state of the switch 2
 * Read the value in PD3, if it is High then the switch is open
 * If PD2 value is Low , then the switch is Closed
 * The value of PD3 is determined by reading the register PIND 
 */
void change_switch2_state(void){
	if (!(PIND&(1 << PD3))){
		switch_state2 = 1;
	}
	else{
		switch_state2 = 0;
	}
}

/**
 * @brief ISR for hadling the interrupt in PD2  
 * 
 */
ISR(INT0_vect){
	change_switch1_state();
}

/**
 * @brief ISR for hadling the interrupt in PD3  
 * 
 */
ISR(INT1_vect){
	change_switch2_state();
}


