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
       unsigned char cntavail = 0;

       if(PINA & 0x01){
          cntavail++;
       }  

       if(PINA & 0x02){
          cntavail++;
       }  

       if(PINA & 0x04){
          cntavail++;
       }  

       if(PINA & 0x08){
          cntavail++;
       }  

       PORTC = (PINC & 0x70) | cntavail;

       if(cntavail == 4){
          PORTC = PINC | 0x80;
       }
    }

    return 1;
}
