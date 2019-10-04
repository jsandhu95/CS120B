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
       unsigned char temp = 0;

       if(PINA & 0x01){
          temp++;
       }  

       if(PINA & 0x02){
          temp++;
       }  

       if(PINA & 0x04){
          temp++;
       }  

       if(PINA & 0x08){
          temp++;
       }  

       cntavail = temp;
       PORTC = cntavail;
    }

    return 1;
}
