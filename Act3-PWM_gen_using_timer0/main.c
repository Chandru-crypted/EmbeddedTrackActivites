#include<avr/io.h>
#include<util/delay.h>
int main(){
    uint8_t volatile temp = 1;
    TCCR0A |= (1 << COM0A1); // selecting fast PWM
    TCCR0B |= (1 << CS01) | (1 << CS00); // set prescaler value to be 256
    TCCR0A |= (1 << WGM01) | (1 << WGM00); // set fast pwm using top value 0xFF
    DDRD |= (1 << PD6);
    PORTD |= (1 << PD6);
    OCR0A = 150;
    _delay_ms(3000);
    while(1){
    }
    return (0);
}
