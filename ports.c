//ports.c
//Tariq Dwekat


#include  "msp430.h"
#include  "functions.h"
#include "macros.h"


void Init_Ports(void){
  
Init_Port1();
Init_Port2();
Init_Port3();
Init_Port4();
Init_Port5();
Init_Port6();
}
void Init_Port1(void){
 P1DIR = 0xFF;
 P1OUT=0x00;
  
//P1 Pin 0
  P1SEL0 &= ~RED_LED; 
  P1SEL1 &= ~RED_LED; 
  P1DIR |= RED_LED;   
  P1OUT &= ~RED_LED;    
    
//P1 Pin 1
  P1SEL0 |= A1_SEEED; 
  P1SEL1 |= A1_SEEED; 

//P1 Pin 2
P1SEL0 |= V_DETECT_L;
P1SEL1 |= V_DETECT_L;

//P1 Pin 3    
P1SEL0 |= V_DETECT_R;
P1SEL1 |= V_DETECT_R;
    
//P1 Pin 4
P1SEL0 |= A4_SEEED; 
P1SEL1 |= A4_SEEED;
    
//P1 Pin 5
P1SEL0 |= V_THUMB; 
P1SEL1 |= V_THUMB;    

//P1 Pin 6
P1SEL0 |= UCA0RXD; 
P1SEL1 &= ~UCA0RXD; 
//P1 Pin 7
P1SEL0 |= UCA0TXD; 
P1SEL1 &= ~UCA0TXD; 
  
  
  
}

void Init_Port2(void){
 P2DIR = 0xFF;
 P2OUT=0x00;
  
//P2 Pin 0  
P2SEL0 &= ~P2_0; 
P2SEL1 &= ~P2_0; 
P2DIR &= ~P2_0; 
//P2 Pin 1
P2SEL0 &= ~IR_LED; 
P2SEL1 &= ~IR_LED; 
P2OUT &= ~IR_LED; 
P2DIR |= IR_LED; 
//P2 Pin 2
P2SEL0 &= ~P2_2; 
P2SEL1 &= ~P2_2; 
P2DIR &= ~P2_2; 
//P2 Pin 3
P2SEL0 &= ~SW2; 
P2SEL1 &= ~SW2; 
P2DIR &= ~SW2; 
P2OUT |= SW2; 
P2REN |= SW2; 
P2IES |= SW2; 
P2IFG &= ~SW2; 
P2IE |= SW2; 

//P2 Pin 4
  P2SEL0 &= ~IOT_PROG_SEL; 
  P2SEL1 &= ~IOT_PROG_SEL; 
  P2DIR &= ~IOT_PROG_SEL;  
//P2 Pin 5
P2SEL0 &= ~P2_5;
P2SEL1 &= ~P2_5; 
P2DIR &= ~P2_5; 
//P2 Pin 6
P2SEL0 &= ~LFXOUT; 
P2SEL1 |= LFXOUT; 
//P2 Pin 7
P2SEL0 &= ~LFXIN; 
P2SEL1 |= LFXIN; 
}

void Init_Port3(void){
 P3DIR = 0xFF;
 P3OUT=0x00;
  
//P3 Pin 0
  P3SEL0 &= ~TEST_PROBE; 
  P3SEL1 &= ~TEST_PROBE; 
    
//P3 Pin 1
P3SEL0 |= OPT_INT;
P3SEL1 |= OPT_INT;
     
//P3 Pin 2
    P3SEL0 |= OA2N; 
    P3SEL1 |= OA2N; 
 //P3 Pin 3
    P3SEL0 |= OA2P; 
    P3SEL1 |= OA2P;
//P3 Pin 4
    P3SEL0 |= SMCLK_OUT; 
    P3SEL1 &= ~SMCLK_OUT; 
//P3 Pin 5
    P3SEL0 &= ~DAC_CNTL;
    P3SEL1 &= ~DAC_CNTL;
//P3 Pin 6
    P3SEL0 &= ~IOT_LINK; 
    P3SEL1 &= ~IOT_LINK;
    P3DIR  &= ~IOT_LINK; 
    P3OUT  &= ~IOT_LINK; 
//P3 Pin 7
    P3SEL0 &= ~IOT_RESET; 
    P3SEL1 &= ~IOT_RESET;
    P3DIR |= IOT_RESET;
    P3OUT &= ~IOT_RESET;
}

void Init_Port4(void){
  //------------------------------------------------------------------------------
  P4OUT=0x00;            
  P4DIR=0x00;          
    
// P4 Pin 0
P4SEL0 &= ~RESET_LCD; 
P4SEL1 &= ~RESET_LCD; 
P4DIR |= RESET_LCD; 
P4OUT |= RESET_LCD; 

// P4 PIN 1
P4SEL0 &= ~SW1; 
P4SEL1 &= ~SW1; 
P4OUT |= SW1; 
P4DIR &= ~SW1; 
P4REN |= SW1; 
P4IES |= SW1; 
P4IFG &= ~SW1; 
P4IE |= SW1; 

// P4 PIN 2
P4SEL0 |= UCA1TXD; 
P4SEL1 &= ~UCA1TXD; 


// P4 PIN 3
P4SEL0 |= UCA1RXD; 
P4SEL1 &= ~UCA1RXD; 

// P4 PIN 4
P4SEL0 &= ~UCB1_CS_LCD; 
P4SEL1 &= ~UCB1_CS_LCD; 
P4OUT |= UCB1_CS_LCD; 
P4DIR |= UCB1_CS_LCD; 

// P4 PIN 5
P4SEL0 |= UCB1CLK; 
P4SEL1 &= ~UCB1CLK; 

// P4 PIN 6
P4SEL0 |= UCB1SIMO; 
P4SEL1 &= ~UCB1SIMO; 

// P4 PIN 7
P4SEL0 |= UCB1SOMI; 
P4SEL1 &= ~UCB1SOMI; 
  
//------------------------------------------------------------------------------    
  
      
}

void Init_Port5(void){
  P5DIR = 0xFF;
 P5OUT=0x00;
  
  //P5 Pin 0
P5SEL0 &= ~CHECK_BAT; 
  P5SEL1 &= ~CHECK_BAT; 
  
//P5 Pin 1
  P5SEL0 &= ~V_BAT; 
  P5SEL1 &= ~V_BAT; 
  
//P5 Pin 2
  P5SEL0 &= ~V_DAC; 
  P5SEL1 &= ~V_DAC; 
//P5 Pin 3
  P5SEL0 &= ~V_3_3; 
  P5SEL1 &= ~V_3_3; 
  
//P5 Pin 4
  P5SEL0 &= ~IOT_PROG_MODE; 
  P5SEL1 &= ~IOT_PROG_MODE; 
  P5DIR &= ~IOT_PROG_MODE; 
}

void Init_Port6(void){
  P6DIR = 0xFF;
 P6OUT=0x00;
  
//P6 Pin 0
P6SEL0 |= R_FORWARD; 
P6SEL1 &= ~R_FORWARD; 
P6DIR |= R_FORWARD; 


//P6 Pin 1
P6SEL0 |= L_FORWARD; 
P6SEL1 &= ~L_FORWARD;
P6DIR |= L_FORWARD;


//P6 Pin 2
P6SEL0 |= R_REVERSE; 
P6SEL1 &= ~R_REVERSE; 
P6DIR |= R_REVERSE; 


//P6 Pin 3
P6SEL0 |= L_REVERSE; 
P6SEL1 &= ~L_REVERSE; 
P6DIR |= L_REVERSE; 

  
//P6 Pin 4
  P6SEL0 &= ~LCD_Backlight; 
  P6SEL1 &= ~LCD_Backlight;
  P6OUT |= LCD_Backlight; 
  P6DIR |= LCD_Backlight;
    
//P6 Pin 5
  P6SEL0 &= ~P6_5; 
  P6SEL1 &= ~P6_5;
    
//P6 Pin 6
  P6SEL0 &= ~GRN_LED; 
  P6SEL1 &= ~GRN_LED; 
  P6OUT &= ~GRN_LED; 
  P6DIR |= GRN_LED;
  
}














