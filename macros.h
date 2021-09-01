//macros file
//Tariq Dwekat


//LEDS
//------------------------------------------------------------------------------
#define RED_LED              (0x01) // RED LED 0
#define GRN_LED              (0x40) // GREEN LED 1
//------------------------------------------------------------------------------

//PORT 1
//------------------------------------------------------------------------------
#define RED_LED (0x01) // 0 RED LED 0
#define A1_SEEED (0x02) // 1 A1_SEEED
#define V_DETECT_L (0x04) // 2 V_DETECT_L
#define V_DETECT_R (0x08) // 3 V_DETECT_R
#define A4_SEEED (0x10) // 4 A4_SEEED
#define V_THUMB (0x20) // 5 V_THUMB
#define UCA0RXD (0x40) // 6 Back Channel UCA0RXD
#define UCA0TXD (0x80) // 7 Back Channel UCA0TXD
//------------------------------------------------------------------------------

//PORT 2
//------------------------------------------------------------------------------
#define P2_0 (0x01) // 0
#define IR_LED (0x02) // 1 IR LED on/off signal
#define P2_2 (0x04) // 2
#define SW2 (0x08) // 3 SW2
#define IOT_PROG_SEL (0x10) // 4
#define P2_5 (0x20) // 5
#define LFXOUT (0x40) // 6 XOUTR
#define LFXIN (0x80) // 7 XINR
//------------------------------------------------------------------------------

// Port 3 Pins
//------------------------------------------------------------------------------
#define TEST_PROBE (0x01) // 0 TEST PROBE
#define OPT_INT (0x02) // 1 CHECK_BAT
#define OA2N (0x04) // 2 Photodiode Circuit
#define OA2P (0x08) // 3 Photodiode Circuit
#define SMCLK_OUT (0x10) // 4 SMCLK
#define DAC_CNTL (0x20) // 5 DAC signal from Processor
#define IOT_LINK (0x40) // 6 IOT_LINK
#define IOT_RESET (0x80) // 7 P3_7
//------------------------------------------------------------------------------

// Port 4 Pins
//------------------------------------------------------------------------------
#define RESET_LCD (0x01) // 0 LCD Reset
#define SW1 (0x02) // 1 SW1
#define UCA1RXD (0x04) // 2 Back Channel UCA1RXD
#define UCA1TXD (0x08) // 3 Back Channel UCA1TXD
#define UCB1_CS_LCD (0x10) // 4 Chip Select
#define UCB1CLK (0x20) // 5 SPI mode - clock output—UCB1CLK
#define UCB1SIMO (0x40) // 6 UCB1SIMO
#define UCB1SOMI (0x80) // 7 UCB1SOMI
//------------------------------------------------------------------------------

// Port 5 Pins
//------------------------------------------------------------------------------
#define CHECK_BAT (0x01) // 
#define V_BAT (0x02) // 
#define V_DAC (0x04) // 
#define V_3_3 (0x08) // 
#define IOT_PROG_MODE (0x10) // 
//------------------------------------------------------------------------------

// Port 6 Pins
//------------------------------------------------------------------------------
#define R_FORWARD (0x01) // 
#define L_FORWARD (0x02) // 
#define R_REVERSE (0x04) // 
#define L_REVERSE (0x08) // 
#define LCD_Backlight (0x10) // 
#define P6_5 (0x20) // 
#define GRN_LED (0x40) // 
//------------------------------------------------------------------------------

//LCD display macros
//------------------------------------------------------------------------------
#define DispWide (4)
#define DispLong (11)
#define TopofDisplay (0)
#define MidP1Display (1)
#define MidP2Display (2)
#define BotofDisplay (3)
#define DispIterMax (11)
#define MAXDISPSIZE (10)
#define MAXDISPINDEX (10)
//------------------------------------------------------------------------------

//PWM motor stuff
//------------------------------------------------------------------------------
#define MOTOR_TIME (50000)
#define MOTOR_ON (1)
#define MOTOR_OFF (0)
#define ZeroStart (0)
#define ZeroStartmotor (0)
#define LeftRevSpeed (TB3CCR2)
#define RightRevSpeed  (TB3CCR1)
#define LeftFWDSpeed (TB3CCR4)
#define RightFWDSpeed  (TB3CCR3)
//------------------------------------------------------------------------------


//defined PWM speeds
//------------------------------------------------------------------------------
#define pwm_forwardR (5000)
#define pwm_forwardL (5000)
#define pwm_reverseR (13000)
#define pwm_reverseL (5050)
#define ccwR (25000)
#define ccwL (13000)
#define cwR (25000)
#define cwL (13000)
#define linefollowR (5000)
#define linefollowL (7000)
#define linefollowcR (6000)
#define linefollowcL (11000)
#define forwardr (20000)
#define forwardl (7500)
#define leftonR (9600)
#define leftonL (0)
//------------------------------------------------------------------------------


//IR sensor macros for Turtle
//------------------------------------------------------------------------------
#define black ('b')
#define white ('w')
#define TRUE (1)
#define NONE ('N')
#define STOP ('S')
//------------------------------------------------------------------------------

// States
//------------------------------------------------------------------------------
#define START                 ('S')
#define BEGINNING            (0)
#define END                   ('E')
#define NONE                  ('N')
#define ALWAYS                  (1)
#define WAIT                  ('W')
#define STRAIGHT              ('L')
#define RUN                   ('R')
#define RESET_STATE             (0)
#define ON              (1)
#define OFF             (0)
//------------------------------------------------------------------------------

//Baud Rates
//------------------------------------------------------------------------------
#define BAUD460BRW (1)        
#define BAUD460MCTLW (0x4A11)
#define BAUD115BRW (4)
#define BAUD115MCTLW (0x5551)
//------------------------------------------------------------------------------

//Arithmetic tables
//------------------------------------------------------------------------------
#define TB0CCR0_INTERVAL (25000)
#define TB0CCR1_INTERVAL (50000) 
#define StartonRcv          (50)  
#define SmlRing     (13)
#define white_space (0x00)
#define CmdSize (13)
#define LnFeed (0x0A)
#define Crt (0x0D)
//------------------------------------------------------------------------------




