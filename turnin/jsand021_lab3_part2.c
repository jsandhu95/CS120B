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
    DDRC = 0xFF; PORTC = 0x00;

    while (1) {
      unsigned char tmpA = PINA;
      unsigned char leds = 0x00;

      switch(tmpA){
        case 13:
        case 14:
        case 15:
           leds = leds | 0x01;
        case 10:
        case 11:
        case 12: 
           leds = leds | 0x02;
        case 7:
        case 8:
        case 9:
           leds = leds | 0x04;
        case 5:
        case 6:
           leds = leds | 0x08;
        case 3:
        case 4:
           leds = leds | 0x10;
        case 1:
        case 2:
           leds = leds | 0x20;

        default:
           break;
      }

      if(tmpA <= 4){
         leds = leds | 0x40;
      }
/*
      tmpA = PINA;
      if(((tmpA & 0x30) == 0x30) && (tmpA & 0x40) != 0x40){
         leds = leds | 0x80;
      }
*/
      PORTC = leds;
    }
    return 0;
}
