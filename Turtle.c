//Turtle.c
//tariq dwekat

#include  "msp430.h"
#include  "functions.h"
#include  "macros.h"
#include <string.h>


//Variables
//------------------------------------------------------------------------------
extern int Check_Left_ADC;
extern int Check_Right_ADC;
extern unsigned char color;
int StartReadyFlag =0;
extern char display_line[4][11];
extern int Val_Container;
extern volatile unsigned int TimeSeq;
//------------------------------------------------------------------------------

//checking the colors
//------------------------------------------------------------------------------
void ColorChecker(void){
  
  if ((Check_Left_ADC < 650)){ 
  
color = white;

}
    if ((Check_Left_ADC > 651)){ 
  
color = black;

}
}
//------------------------------------------------------------------------------

//Turtle movement
//------------------------------------------------------------------------------
void IR_TurtleP2(void) {
  if(StartReadyFlag == 0){
     switch(color){
     case white:
       ForwardwPWM();
       strcpy(display_line[MidP2Display], "  SEARCHING ");
       break;
     
     case black:
       ShutDownPWM();
       Val_Container = 1;
       TimeSeq = 0;
       TimedMovement();
       Val_Container = 1;
       TimeSeq = 0;
       TimedMovement2();
       StartReadyFlag = 1;
       break;
     }
  }
   if (StartReadyFlag == 1)
   {
     IR_Turtle();
     strcpy(display_line[MidP2Display], " FOLLOWING");
   }
}
//------------------------------------------------------------------------------

