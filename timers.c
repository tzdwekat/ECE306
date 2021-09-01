//timers.c
//Tariq Dwekat

#include  "msp430.h"
#include  "functions.h"
#include <string.h>
#include  "Macros.h"


//Variables
//------------------------------------------------------------------------------
extern volatile unsigned int SW1DebCnt;
extern volatile unsigned int TimeSeq;
unsigned int IsrCntr;
int flagger;
extern volatile unsigned char DispUpdate;
extern volatile unsigned int UCA0_array;
extern unsigned int CMD_send;



//Timer B0 Initialization
//------------------------------------------------------------------------------
void Init_Timer_B0(void) {
TB0CTL = TBSSEL__SMCLK; // SMCLK source
TB0CTL |= TBCLR; // Resets TB0R, clock divider, count direction
TB0CTL |= MC__CONTINOUS; // Continuous up counting of TB0R Count Register

TB0CTL |= ID__2; // Divide clock by 2
TB0EX0 = TBIDEX__8; // Divide clock by an additional 8

TB0CCR0 = TB0CCR0_INTERVAL; // CCR0 REGISTER 0
TB0CCTL0 &= ~CCIFG; // cleandisplay possible pending interrupt
TB0CCTL0 |= CCIE; // CCR0 enable interrupt STARTS timer

TB0CCR1 = TB0CCR1_INTERVAL; // CCR1 REGISTER 1
TB0CCTL1 &= ~CCIFG; // cleandisplay possible pending interrupt
TB0CCTL1 |= CCIE; // CCR1 enable interrupt

TB0CTL &= ~TBIE; // Disable Overflow Interrupt
TB0CTL &= ~TBIFG; // cleandisplay Overflow Interrupt flag
}
//Timer B3 Initialization
//------------------------------------------------------------------------------
void Init_Timer_B3(void) {
  //------------------------------------------------------------------------------
  // SMCLK source, up count mode, PWM Right Side
  // TB3.1 P6.0 R_FORWARD
  // TB3.2 P6.1 L_FORWARD 
  // TB3.3 P6.2 R_REVERSE
  // TB3.4 P6.3 L_REVERSE
  //------------------------------------------------------------------------------
  TB3CTL = TBSSEL__SMCLK;              // SMCLK
  TB3CTL |= MC__UP;                    // Up Mode
  TB3CTL |= TBCLR;                     // cleandisplay TAR
  
  TB3CCR0 = MOTOR_TIME;              // PWM Period
  
  TB3CCTL1 = OUTMOD_7;                 // CCR1 reset/set
  RightFWDSpeed = MOTOR_OFF;     // P6.0 Right Forward PWM duty cycle
  
  TB3CCTL2 = OUTMOD_7;                 // CCR2 reset/set
  LeftFWDSpeed = MOTOR_OFF;      // P6.1 Left Forward PWM duty cycle
  
  TB3CCTL3 = OUTMOD_7;                 // CCR3 reset/set
  RightRevSpeed = MOTOR_OFF;     // P6.2 Right Reverse PWM duty cycle
  
  TB3CCTL4 = OUTMOD_7;                 // CCR4 reset/set
  LeftRevSpeed = MOTOR_OFF;      // P6.3 Left Reverse PWM duty cycle
  //------------------------------------------------------------------------------
}

#pragma vector = TIMER0_B0_VECTOR
__interrupt void Timer0_B0_ISR(void){
// TimerB0 0 Interrupt handler
//----------------------------------------------------------------------------
  
 TimeSeq++;
 IsrCntr++;
 DispUpdate = TRUE;
TB0CCR0 += TB0CCR0_INTERVAL; // Add Offset to TBCCR0
switch(IsrCntr){
    case 2:
   P3OUT |= IOT_RESET; //INITIAL CONDITION = 1
    //CMD_send = ON;
    break;
  case 250:
   UCA0_array = 0;
   UCA0IE |= UCTXIE;                    // Enable TX interrupt U
   CMD_send = ON;
   flagger = 1;
   UCA0TXBUF = '\r';
    break;
case 350:
  IsrCntr = 0;
  flagger = 0;
  break;
  } 
//----------------------------------------------------------------------------
}


#pragma vector=TIMER0_B1_VECTOR
__interrupt void TIMER0_B1_ISR(void){
//----------------------------------------------------------------------------
// TimerB0 1-2, Overflow Interrupt Vector (TBIV) handler
//----------------------------------------------------------------------------
switch(__even_in_range(TB0IV,14)) {
  case OFF:
    break;
  case 2: //CCR1 INTERRUPT
    SW1DebCnt++;
      if(SW1DebCnt == 16){
        TB0CCTL1 &= ~CCIE; //CCR1 Disabled
        
        P4IE |= SW1; //SW1 Interrupt disabled
        P2IE |= SW2; //SW2 Interrupt disabled
        
        P6OUT |= LCD_Backlight;
        //turn backlite off
        SW1DebCnt = OFF;
      }
      //P4IE |= SW1; //SW1 Interrupt disabled
      //P2IE |= SW2; //SW2 Interrupt disabled      
  TB0CCR1 += TB0CCR0_INTERVAL; // Add Offset to TBCCR1
  break;
  case 4: // CCR2 not used
  TB0CCR2 += TB0CCR0_INTERVAL; // Add Offset to TBCCR2
  break;
  case 16: // overflow
  break;
  default: break;
}
}
