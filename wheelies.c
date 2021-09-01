//wheelies.c
//Tariq Dwekat

#include  "msp430.h"
#include  "functions.h"
#include <string.h>
#include  "macros.h"

//Variables
//------------------------------------------------------------------------------
extern unsigned char color;
extern int Val_Container;
extern volatile unsigned int TimeSeq;
//------------------------------------------------------------------------------


//Forward with PWM
//------------------------------------------------------------------------------
void ForwardwPWM(void) {
ShutDownPWM(); 
RightFWDSpeed = MOTOR_ON; // P6.0 Right Forward PWM OFF
LeftFWDSpeed = MOTOR_ON; // P6.1 Left Forward PWM OFF  
  
RightFWDSpeed = pwm_forwardR ; // P6.0 Right Forward PWM ON amount 
LeftFWDSpeed = pwm_forwardL; // P6.1 Left Forward PWM ON amount 
}
//------------------------------------------------------------------------------


//Reverse with PWM
//------------------------------------------------------------------------------
void ReversewPwm(void) {
ShutDownPWM(); 
RightRevSpeed = MOTOR_ON; // P6.0 Right Forward PWM OFF
LeftRevSpeed = MOTOR_ON; // P6.1 Left Forward PWM OFF  
  
RightRevSpeed =  pwm_reverseR;// P6.0 Right Forward PWM ON amount 
LeftRevSpeed  =  pwm_reverseL;// P6.1 Left Forward PWM ON amount 
}
//------------------------------------------------------------------------------

//Turn Left with PWM
//------------------------------------------------------------------------------
void LeftwPWM(void){
ShutDownPWM();


RightFWDSpeed = MOTOR_ON; // P6.2 Right Reverse PWM OFF
LeftFWDSpeed = MOTOR_ON; // P6.1 Left Forward PWM OFF

RightFWDSpeed = ccwR; // P6.2 Right Reverse PWM ON amount
LeftFWDSpeed = MOTOR_OFF; // P6.1 Left Forward PWM ON amount

}
//------------------------------------------------------------------------------

//Turn Right with PWM
//------------------------------------------------------------------------------
void RightwPWM(void){
ShutDownPWM();


RightRevSpeed = MOTOR_ON; // P6.2 Right Reverse PWM OFF
LeftFWDSpeed = MOTOR_ON; // P6.1 Left Forward PWM OFF

RightRevSpeed =  cwR; // P6.2 Right Reverse PWM ON amount
LeftFWDSpeed = cwL; // P6.1 Left Forward PWM ON amount

}
//------------------------------------------------------------------------------

//Shut off all motors
//------------------------------------------------------------------------------
void ShutDownPWM(void) {

RightFWDSpeed = MOTOR_OFF; // P6.0 Right Forward PWM OFF
LeftFWDSpeed = MOTOR_OFF; // P6.1 Left Forward PWM OFF

RightRevSpeed = MOTOR_OFF; // P6.2 Right Reverse PWM OFF
LeftRevSpeed = MOTOR_OFF; // P6.3 Left Reverse PWM OFF
 
}
//------------------------------------------------------------------------------

//Turtle movement on line
//------------------------------------------------------------------------------
void IR_Turtle (void) {
  
//If on black drive along it
if (color == black){ 
ShutDownPWM();
RightFWDSpeed = MOTOR_ON; // P6.0 Right Forward PWM OFF
LeftFWDSpeed = MOTOR_ON; // P6.1 Left Forward PWM OFF  
    
RightFWDSpeed =  linefollowR;// P6.0 Right Forward PWM ON amount 
LeftFWDSpeed = linefollowL; // P6.1 Left Forward PWM ON amount 

}

// If on white turn to the right
if (color == white){
ShutDownPWM(); 
RightFWDSpeed = MOTOR_ON; // P6.0 Right Forward PWM On
LeftRevSpeed = MOTOR_ON; // P6.1 Left Forward PWM On
    
RightFWDSpeed = linefollowcR; // P6.0 Right Forward PWM ON amount 
LeftRevSpeed =  linefollowcL;// P6.1 Left Forward PWM ON amount 


 }  

}
//------------------------------------------------------------------------------




