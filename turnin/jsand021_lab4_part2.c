/*	Author: jsand021 - Jeevan Sandhu
 *  Partner(s) Name: No Partner
 *	Lab Section: 23
 *	Assignment: Lab 4  Exercise 2
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

typedef enum States {init, wait, pressA0, pressA1, reset} State;
typedef enum bool {false, true} bool;

int press(int, bool*);

int main(void) {
    DDRA = 0x00; PORTA = 0xFF;
    DDRC = 0xFF; PORTC = 0x00;

    State state = init;
    bool flag = false;

    while (1) {
       state = press(state, &flag);
    }
    return 0;
}

int press(int state, bool *flag){
   unsigned char A0 = PINA & 0x01;
   unsigned char A1 = (PINA & 0x02) >> 1;

   switch(state){
      case init:
         PORTC = 0x07;
         *flag = false;
         state = wait;
         break;
      case wait:
         if(A0 && A1){
            state = reset;
         }
         else if(A0){
            state = pressA0;
         }
         else if(A1){
            state = pressA1;
         } 
         else{
            state = wait;
         }
         break;
      case pressA0:
         if(A1){
            state = reset;
         }
         else if(A0){
            state = pressA0;
         }
         else if(!A0){
            state = wait;
         }
         break;
      case pressA1:
         if(A0){
            state = reset;
         }
         else if(A1){
            state = pressA1;
         }
         else if(!A1){
            state = wait;
         }
         break;
      case reset:
         state = (!A0 && !A1) ? wait : reset;
         break;
      default:
         break;
   }
   switch(state){
      case init:
         break;
      case wait:
         *flag = false;
         break;
      case pressA0:
         if(PORTC < 9 && (*flag) == false){
            PORTC++;
            *flag = true;
         }
         break;
      case pressA1:
         if(PORTC > 0 && (*flag) == false){
            PORTC--;
            *flag = true;
         }
         break;
      case reset:
         PORTC = 0x00;
         break;
      default:
         break;
   }
   return state;
}
