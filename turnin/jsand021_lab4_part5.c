/*	Author: jsand021 - Jeevan Sandhu
 *  Partner(s) Name: No Partner
 *	Lab Section: 23
 *	Assignment: Lab 4  Exercise 5
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

#define B0 (PORTB & 0x01)

typedef enum States {init, wait, lock, press, unlock} State;
typedef enum bool {false, true} bool;

unsigned char button[4];
bool flag;
bool initialized;

int deadBolt(int);

int main(void) {
    unsigned char i;
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFF; PORTB = 0x00;
    DDRC = 0xFF; PORTC = 0x00;

    for(i = 0; i < 4; i++){
       button[i] = 0;
    }

    State state = init;
    PORTC = 0x00;

    while (1) {
       state = deadBolt(state);
    }
    return 0;
}

int deadBolt(int state){
   unsigned char i;
   unsigned char A0 = PINA & 0x01;
   unsigned char A1 = (PINA & 0x02) >> 1;
   unsigned char A2 = (PINA & 0x04) >> 2;
   unsigned char A7 = (PINA & 0x80) >> 7;

   switch(state){
      case init:
         if(initialized){
            state = wait;
            initialized = false;
         }
         else{
            state = init;
         }
         break;
      case wait:
         if(((button[0] == '#' && button[1] == 'X' && button[2] == 'Y' && button[3] == 'X') && B0) || A7){
            state = lock;
         }
         else if((button[0] == '#' && button[1] == 'X' && button[2] == 'Y' && button[3] == 'X') && !B0){
            state = unlock;
         }
         else if(A0 || A1 || A2){
            state = press;
         } 
         else{
            state = wait;
         }
         break;
      case lock:
         if(!A7){
            state = wait;
         }
         else{
            state = lock;
         }
         break;
      case press:
         if(!(A0 || A1 || A2)){
            state = wait;
         }
         else{
            state = press;
         } 
         break;
      case unlock:
         state = wait;
         break;
      default:
         state = wait;
         break;
   }
   switch(state){
      case init:
         PORTB = 0x00;
         for(i = 0; i < 4; i++){
            button[i] = 0;
         }
         PORTC = 0x00;
         initialized = true;
         break;
      case wait:
         flag = 0;
         PORTC = 0x01;
         break;
      case lock:
         PORTB = PORTB & 0xFE;
         for(i = 0; i < 4; i++){
            button[i] = 0;
         }
         PORTC = 0x02;
         break;
      case press:
         if(flag == 0){
            button[0] = button[1];
            button[1] = button[2];
            button[2] = button[3];

            if(A0){
               button[3] = 'X';
            }
            else if(A1){
               button[3] = 'Y';
            }
            else if(A2){
               button[3] = '#';
            }
            flag = 1;
         }
         PORTC = 0x03;
         break;
      case unlock:
         PORTB = PORTB | 0x01;
         for(i = 0; i < 4; i++){
            button[i] = 0;
         }
         PORTC = 0x04;
         break;
      default:
         break;
   }
   return state;
}
