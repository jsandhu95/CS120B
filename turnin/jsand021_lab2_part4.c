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
    DDRA = 0x00; PORTA = 0xFF; DDRB = 0x00; PORTB = 0xFF;
    DDRC = 0x00; PORTC = 0xFF; DDRD = 0xFF; PORTD = 0x00;

    while (1) {
      unsigned char totalWeight = 0x00;
      unsigned char approxWeight = 0x00;

      totalWeight = PINA + PINB + PINC;
      approxWeight = totalWeight / 10;       // Dividing by ten for approximate weight to fit into upper 6 bits

      PORTD = approxWeight << 2;

      if(totalWeight > 140){
         PORTD = PIND | 0x01;
      }

      if(PINA - PINC > 80 || PINC - PINA > 80){
         PORTD = PIND | 0x02;
      }
    }
    return 1;
}
