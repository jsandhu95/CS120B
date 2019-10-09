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
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFF; PORTB = 0x00;
    DDRC = 0xFF; PORTC = 0x00;

    while (1) {
      unsigned char tmpB = ((PINA & 0xF0) >> 4) | (PINB & 0xF0);
      unsigned char tmpC = ((PINA & 0x0F) << 4) | (PINC & 0x0F);
      PORTB = tmpB;
      PORTC = tmpC;
    }
    return 0;
}
