#include<avr/io.h>

int main(void){
    // SET OUTPUT AS DIRECTION
    DDRB |= (1 << PB1);

    // TIMER INTIALISATION
    // connected to PB1, timer 1 (16 BIT), channel A
    TCCR1A |= (1 << COM1A1); // Fast PWM operation

    // SETTING THE FAST PWM OPERATION 10 BIT
    TCCR1A |= (1 << WGM11) | (1 << WGM10);
    TCCR1B |= (1 << WGM12);

    // SET THE PRESCALER
    TCCR1B |= (1 << CS11)| (0 << CS10);

    OCR1A = 700;
    while (1){
    }

    return(0);
}
