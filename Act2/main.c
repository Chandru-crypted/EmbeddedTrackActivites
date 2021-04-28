#include<avr/io.h>
#include<util/delay.h>

void init_ADC(void){
    ADMUX |= (1 << REFS0); // Decide the ref voltage
    ADCSRA = (1 << ADEN); // Switch on the ADC
    ADCSRA |= (7 << ADPS0); // set the prescaler
}

uint16_t ReadAdc(uint8_t channel){
    ADMUX &= ~(7); // clearing the mux bits
    //the mux bits are present in the last right most bits
    channel = channel & 7; // make the channel bits proper
    ADMUX |= channel; // select the channel
    ADCSRA |= (1 << ADSC); // start conversion

    while (!(ADCSRA & (1 << ADIF))); // wait for conversion
    // i.e till ADIF in ADSCRA becomes 1

    ADCSRA &= ~(1 << ADIF);
    // clear ADIF

    return (ADC);
}

int main(void){
    init_ADC();
    uint16_t temp = 0;
    uint16_t channel = 0;
    while(1){
        temp = ReadAdc(channel);
        _delay_ms(200);
    }
}
