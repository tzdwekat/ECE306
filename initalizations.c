//initializations.c
//tariq dwekat


#include  "functions.h"
#include  "msp430.h"
#include  "macros.h"
#include <string.h>


//Variables
//------------------------------------------------------------------------------
extern char display_line[4][11];
extern char *display[4];
extern volatile unsigned char ChangeDisp;
extern volatile unsigned char DispUpdate;
extern volatile unsigned int TimeSeq;
//------------------------------------------------------------------------------

//Initialization Function
//------------------------------------------------------------------------------
void Init_Conditions(void){
//------------------------------------------------------------------------------
  int i;

  for(i=0;i<11;i++){
    display_line[0][i] = RESET_STATE;
    display_line[1][i] = RESET_STATE;
    display_line[2][i] = RESET_STATE;
    display_line[3][i] = RESET_STATE;
  }
  display_line[0][10] = 0;
  display_line[1][10] = 0;
  display_line[2][10] = 0;
  display_line[3][10] = 0;

  display[0] = &display_line[0][0];
  display[1] = &display_line[1][0];
  display[2] = &display_line[2][0];
  display[3] = &display_line[3][0];
  DispUpdate = 0;

  enable_interrupts();
//------------------------------------------------------------------------------
}