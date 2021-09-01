//RCcontrol.c
//Tariq Dwekat


#include  "functions.h"
#include <string.h>
#include "macros.h"
#include  "msp430.h"


//Variables
//------------------------------------------------------------------------------
extern char display_line[4][11];
extern char ArrayCMD[20];
extern unsigned char event;
extern int StartReadyFlag;
//------------------------------------------------------------------------------



void CarCMD(void){
  
  switch(ArrayCMD[2]){
      
//Movement
//------------------------------------------------------------------------------
  case 'F':  // F
    cleandisplay();
    strcpy(display_line[MidP2Display], " Straight ");
    update_string(display_line[MidP2Display], MidP2Display);
    ForwardwPWM();
    break;
    
  case 'L':
    cleandisplay();
    strcpy(display_line[MidP2Display], "  Turn Left  ");
    update_string(display_line[MidP2Display], MidP2Display);
    LeftwPWM();
    break;
    
  case 'R':
    cleandisplay();
    strcpy(display_line[MidP2Display], " Turn Right  ");
    update_string(display_line[MidP2Display], MidP2Display);
    RightwPWM();
    break;
    
  case 'B':
    cleandisplay();
    strcpy(display_line[MidP2Display], " Reverse ");
    update_string(display_line[MidP2Display], MidP2Display);
    ReversewPwm();
    break;
    
  case 'S':
    cleandisplay();
    strcpy(display_line[MidP2Display], " FREEZE    ");
    update_string(display_line[MidP2Display], MidP2Display);
    ShutDownPWM();
    break;
//------------------------------------------------------------------------------
    
    
// Circle Tracking
//------------------------------------------------------------------------------
  case'H': //reset IR sensor
    StartReadyFlag = 0;
    break;
    
  case 'C': //start IR turtle
    cleandisplay();
    strcpy(display_line[MidP2Display], " Turtle Time ");
    update_string(display_line[MidP2Display], MidP2Display);
    IR_TurtleP2();
    break;
//------------------------------------------------------------------------------   

 
    
    
    
// Display Number of track on display
//------------------------------------------------------------------------------
  case '1':
    cleandisplay();
    strcpy(display_line[MidP1Display], "    #1    ");
    update_string(display_line[MidP1Display], MidP1Display);
    break;
    
  case '2':
    cleandisplay();
    strcpy(display_line[MidP1Display], "    #2    ");
    update_string(display_line[MidP1Display], MidP1Display);
    break;
    
   case '3':
    cleandisplay();
    strcpy(display_line[MidP1Display], "    #3    ");
    update_string(display_line[MidP1Display], MidP1Display);
    break;
   
    case '4':
    cleandisplay();
    strcpy(display_line[MidP1Display], "    #4    ");
    update_string(display_line[MidP1Display], MidP1Display);
    break;
    
    case '5':
    cleandisplay();
    strcpy(display_line[MidP1Display], "    #5    ");
    update_string(display_line[MidP1Display], MidP1Display);
    break;
    
    case '6':
    cleandisplay();
    strcpy(display_line[MidP1Display], "    #6    ");
    update_string(display_line[MidP1Display], MidP1Display);
    break;
    
    case '7':
    cleandisplay();
    strcpy(display_line[MidP1Display], "    #7    ");
    update_string(display_line[MidP1Display], MidP1Display);
    break;
    
    case '8':
    cleandisplay();
    strcpy(display_line[MidP1Display], "    #8    ");
    update_string(display_line[MidP1Display], MidP1Display);
    break;
    
  default:
    cleandisplay();
    strcpy(display_line[MidP2Display], "    RTC    ");
    update_string(display_line[MidP2Display], MidP2Display);
    ShutDownPWM();
    break;
  }
//------------------------------------------------------------------------------
}
    
    