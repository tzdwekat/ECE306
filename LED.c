//LED.c
//Tariq Dwekat

#include  "functions.h"
#include  "msp430.h"
#include "macros.h"
#include <string.h>

void Init_LEDs(void){
// Turns on both LEDs
  P1OUT &= ~RED_LED;
  P6OUT &= ~GRN_LED;
//------------------------------------------------------------------------------
}