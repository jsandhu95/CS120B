/*	Author: jsand021 - Jeevan Sandhu
 *  Partner(s) Name: No Partner
 *	Lab Section: 23
 *	Assignment: Lab 4  Exercise 4
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

typedef enum States {wait, lock, unlock1, unlock2, unlock} State;

int deadBolt(int);

int main(void) {
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFF; PORTB = 0x00;
    DDRC = 0xFF; PORTC = 0x00;

    State state = wait;
    PORTC = 0x00;

    while (1) {
       state = deadBolt(state);
    }
    return 0;
}

int deadBolt(int state){
   unsigned char A0 = PINA & 0x01;
   unsigned char A1 = (PINA & 0x02) >> 1;
   unsigned char A2 = (PINA & 0x04) >> 2;
   unsigned char A7 = (PINA & 0x80) >> 7;

   switch(state){
      case wait:
         if(A7 && !(A0 || A1 || A2)){
            state = lock;
         }
         else if(A2 && !(A0 || A1 || A7)){
            state = unlock1;
         }
         else{
            state = wait;
         } 
         break;
      case lock:
         if(A7){
            state = lock;
         }
         else if(!A7){
            state = wait;
         }
         break;
      case unlock1:
         if(!A1 && !(A0 || A1 || A7)){
            state = unlock2;
         }
         else{
            state = unlock1;
         } 
         break;
      case unlock2:
         if(A1 && !(A0 || A2 || A7) && !(PORTB & 0x01)){
            state = unlock;
         }
         else if((A7 && !(A0 || A1 || A2)) || (A1 && !(A0 || A2 || A7) && (PORTB & 0x01))){
            state = lock;
         }
         else if((A0 && !(A1 || A2 || A7)) || (A2 && !(A0 || A1 || A7))){
            state = wait;
         }
         else{
            state = unlock2;
         } 
         break;
      case unlock:
         if(A1){
            state = unlock;
         }
         else if(!A1){
            state = wait;
         }
         break;
      default:
         break;
   }
   switch(state){
      case wait:
         PORTC = 0x00;
         break;
      case lock:
         PORTB = PORTB & 0xFE;
         PORTC = 0x01;
         break;
      case unlock1:
         PORTC = 0x02;
         break;
      case unlock2:
         PORTC = 0x03;
         break;
      case unlock:
         PORTB = PORTB | 0x01;
         PORTC = 0x04;
         break;
      default:
         break;
   }
   return state;
}
