/*	Author: jsand021 - Jeevan Sandhu
 *  Partner(s) Name: No Partner 
 *	Lab Section: 23
 *	Assignment: Lab 3  Exercise 1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

unsigned char returnBit(unsigned char number, unsigned char position){
   return ((number & (0x01<<position)) != 0);
}

int main(void) {
    DDRA = 0x00; PORTA = 0xFF; DDRB = 0x00; PORTB = 0xFF;
    DDRC = 0xFF; PORTC = 0x00;

    while (1) {
      unsigned char tmpA = PINA;
      unsigned char tmpB = PINB;
      unsigned char count = 0;

      unsigned char i;
      for(i = 0; i <= 7; i++){
         count = count + returnBit(tmpA, i) + returnBit(tmpB, i);
      }

      PORTC = count;
    }
    return 1;
}
