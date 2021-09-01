// InitializePorts.c
//Tariq Dwekat
// Spring 2021

#include  "msp430.h"
#include  "functions.h"
#include <string.h>
#include  "macros.h"


//Variables
//------------------------------------------------------------------------------
char SW1Deb;
char SW2Deb;
volatile unsigned int SW1DebCnt;
volatile unsigned int SW2DebCnt;
extern char display_line[4][11];
extern unsigned char event;
extern volatile unsigned int TimeSeq;
//------------------------------------------------------------------------------


//Interrupts
//------------------------------------------------------------------------------
#pragma vector=PORT2_VECTOR 
__interrupt void switchP2_interrupt(void){
  SW2DebCnt=OFF;
if (P2IFG & SW2) {

}
}


#pragma vector=PORT4_VECTOR 
__interrupt void switchP4_interrupt(void){
if (P4IFG & SW1) {


}
}
//------------------------------------------------------------------------------

