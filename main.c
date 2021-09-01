//------------------------------------------------------------------------------
//
//  Description: This file contains the Main Routine - "While" Operating System
//
//
//  Tariq Dwekat
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (7.11.2)
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
#include  "functions.h"
#include  "msp430.h"
#include "macros.h"
#include <string.h>

//Globals
//------------------------------------------------------------------------------

// Timing variables
//------------------------------------------------------------------------------
unsigned char event = NONE;
unsigned char color = NONE;
char state = WAIT;
unsigned cycle_time;
volatile unsigned int TimeSeq;
int Val_Container = 0;

//LCD Display Variables
//------------------------------------------------------------------------------
extern char display_line[4][11];
extern char *display[4];
unsigned char display_mode;
unsigned int display_write;
char displaystring[MAXDISPSIZE];
unsigned int Displaycount;
volatile unsigned char ChangeDisp;
volatile unsigned char DispUpdate;

//Serial Communication Variables
//------------------------------------------------------------------------------
volatile unsigned int UCA0write;
unsigned int UCA1write;
char tstCmd[CmdSize] = "";
volatile unsigned int IOTflag;
volatile unsigned int UCA0_array;
char processBuff[SmlRing];
char USB_Char[SmlRing];
char UCA1_Char[SmlRing];
//------------------------------------------------------------------------------


//Main Function
//------------------------------------------------------------------------------

void main(void){
//------------------------------------------------------------------------------
// Main Program
// This is the main routine for the program. Execution of code starts here.
// The operating system is Back Ground Fore Ground.
//
//------------------------------------------------------------------------------
// Disable the GPIO power-on default high-impedance mode to activate
// previously configured port settings
  PM5CTL0 &= ~LOCKLPM5;
  Init_Ports();                       // Initialize Ports
  Init_Clocks();                      // Initialize Clock System
  Init_Conditions();                  // Initialize Variables and Initial Conditions
  Init_LCD();                         // Initialize LCD
  Init_ADC();                         //Initialize ADC
  Init_Timer_B0();
  Init_Timer_B3();
  Init_Serial_UCA0();
  Init_Serial_UCA1();
  cleandisplay();
  Init_Timer_B3();

// Place the contents of what you want on the display, in between the quotes
// Limited to 10 characters per line
//------------------------------------------------------------------------------
// Begining of the "While" Operating System
//------------------------------------------------------------------------------
  while(ALWAYS) {                      
  P2OUT |= IR_LED;
  ColorChecker();
  CarCMD();
  Display_Process();
}
}
      
//------------------------------------------------------------------------------

void TimedMovement(void){
  while( Val_Container == 1 ){

    if (TimeSeq == 10)
    {
      Val_Container = 0;
    }
    
  }
 }

void TimedMovement2(void){
  while( Val_Container == 1 ){
  RightwPWM();
    if (TimeSeq == 10)
    {
      Val_Container = 0;
      
    }
    
  }
 }