/*	Author: jsand021 - Jeevan Sandhu
 *  Partner(s) Name: No Partner
 *	Lab Section: 23
 *	Assignment: Lab 4  Exercise 1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

typedef enum States {r0, p0, r1, p1} State;

int press(int);

int main(void) {
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFF; PORTB = 0x00;

    State state = r0;
    PORTB = 0x01;

    while (1) {
       state = press(state);
    }
    return 0;
}

int press(int state){
   static unsigned char b;
   unsigned char A0 = PINA & 0x01;
   switch(state){
      case r0:
         state = A0 ? p1 : r0;
         break;
      case p0:
         state = A0 ? p0 : r0;
         break;
      case r1:
         state = A0 ? p0 : r1;
         break;
      case p1:
         state = A0 ? p1 : r1;
         break;
      default:
         state = r0;
         break;
   }
   switch(state){
      case r0:
         b = 0x01;
         break;
      case p0:
         b = 0x01;
         break;
      case r1:
         b = 0x02;
         break;
      case p1:
         b = 0x02;
         break;
      default:
         break;
   }
   PORTB = b;
   return state;
}
