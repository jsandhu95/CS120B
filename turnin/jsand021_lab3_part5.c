/*	Author: jsand021
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    DDRD = 0x00; PORTD = 0xFF;
    DDRB = 0xFE; PORTB = 0x01;

    while (1) {
       short weight = (PIND << 1) | (PINB & 0x01);
       unsigned char airbag = 0;

       if(weight >= 70){
          airbag = airbag | 0x02;
       }
       else if(weight > 5){
          airbag = airbag | 0x04;
       }

       PORTB = airbag; 
    }
    return 0;
}
