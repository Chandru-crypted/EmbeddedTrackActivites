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
#include "activity1.h"
#include "activity2.h"
#include "activity3.h"

uint16_t volatile ADC_value = 0;

int main(void){
	intialise_heater_button();
	intialise_seat_button();
	intialise_LED();
	init_ADC();
	init_PWM_gen_timer0();
	while (1){
		if(check_if_both_switch_are_pressed()){
			change_led_state(LED_ON);
			ReadAdc();
			change_PWM_width_using_conditions(ADC_value);
		}
		else{
			change_led_state(LED_OFF);
			clear_ADC_value();
			PWM_width = 50;
		}
		_delay_ms(500);
	}
    return 0;
}
