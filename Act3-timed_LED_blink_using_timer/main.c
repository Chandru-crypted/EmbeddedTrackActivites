#include<avr/io.h>
#include<avr/interrupt.h>

uint8_t volatile overflow = 0;

int main(void){
    DDRD |= (1 << PD6);
    PORTD |= (1 << PD6);
    TCCR0B |= (1 << CS02); // Setting the prescaler bit sets to divide by 256
    TIMSK0 |= (1 << TOIE0); // Setting up the Overflow interrupt enable
    overflow = 0;
    TCNT0 = 0;
    sei();
    while (1){
        if (overflow >= 12){
            if (TCNT0 >= 52){
                PORTD ^= (1 << PD6);
                TCNT0 = 0;
                overflow = 0;
            }
        }
    }
    return (0);
}


// got this overflow vector information from the lib
ISR(TIMER0_OVF_vect){
    overflow++;
}
