//Adc.c
//Tariq Dwekat


#include  "msp430.h"
#include  "functions.h"
#include <string.h>
#include  "macros.h"


int ChannelADC;
int Check_Left_ADC;
int Check_Right_ADC;
int ThumbwheelADC;
extern char ADCchar[DispWide];


void Init_ADC(void){
//------------------------------------------------------------------------------
  
  
// ADCCTL0 Register
 ADCCTL0 = 0; // Reset
 ADCCTL0 |= ADCSHT_2; // 16 ADC clocks
 ADCCTL0 |= ADCMSC; // MSC
 ADCCTL0 |= ADCON; // ADC ON
 
 
// ADCCTL1 Register
 ADCCTL2 = 0; // Reset
 ADCCTL1 |= ADCSHS_0; // 00b = ADCSC bit
 ADCCTL1 |= ADCSHP; // ADC sample-and-hold SAMPCON signal from sampling timer.
 ADCCTL1 &= ~ADCISSH; // ADC invert signal sample-and-hold.
 ADCCTL1 |= ADCDIV_0; // ADC clock divider - 000b = Divide by 1
 ADCCTL1 |= ADCSSEL_0; // ADC clock MODCLK
 ADCCTL1 |= ADCCONSEQ_0; // ADC conversion sequence 00b = Single-channel single-conversion
 
 
// ADCCTL1 & ADCBUSY identifies a conversion is in process
// ADCCTL2 Register
 ADCCTL2 = 0; // Reset
 ADCCTL2 |= ADCPDIV0; // ADC pre-divider 00b = Pre-divide by 1
 ADCCTL2 |= ADCRES_2; // ADC resolution 10b = 12 bit (14 clock cycle conversion time)
 ADCCTL2 &= ~ADCDF; // ADC data read-back format 0b = Binary unsigned.
 ADCCTL2 &= ~ADCSR; // ADC sampling rate 0b = ADC buffer supports up to 200 ksps
 
 
// ADCMCTL0 Register
 ADCMCTL0 |= ADCSREF_0; // VREF - 000b = {VR+ = AVCC and VR� = AVSS }
 ADCMCTL0 |= ADCINCH_2; // V_THUMB (0x20) Pin 5 A5
 ADCIE |= ADCIE0; // Enable ADC conv complete interrupt
 ADCCTL0 |= ADCENC; // ADC enable conversion.
 ADCCTL0 |= ADCSC; // ADC start conversion.
}





#pragma vector=ADC_VECTOR
__interrupt void ADC_ISR(void){
 switch(__even_in_range(ADCIV,ADCIV_ADCIFG)){
 case ADCIV_NONE:
 break;
 case ADCIV_ADCOVIFG: // When a conversion result is written to the ADCMEM0
 // before its previous conversion result was read.
 break;
 case ADCIV_ADCTOVIFG: // ADC conversion-time overflow
 break;
 case ADCIV_ADCHIIFG: // Window comparator interrupt flags
 break;
 case ADCIV_ADCLOIFG: // Window comparator interrupt flag
 break;
 case ADCIV_ADCINIFG: // Window comparator interrupt flag
 break;
 case ADCIV_ADCIFG: // ADCMEM0 memory register with the conversion result
  ADCCTL0 &= ~ADCENC; // Disable ENC bit.
  
  switch (ChannelADC++){
  
  case 0x00: // Channel A2 Interrupt for left detect
  Check_Left_ADC = ADCMEM0; // Move result into Global
  Check_Left_ADC = Check_Left_ADC >> 2; // Divide the result by 4
  ADCMCTL0 &= ~ADCINCH_2; // Disable Last channel A2
  ADCMCTL0 |= ADCINCH_3; // Enable Next channel A3 for left detect
  
  HEX2DEC_CONV(Check_Left_ADC); // Convert result to String

  break;
  
  case 0x01: //for right detect
  Check_Right_ADC = ADCMEM0; // Move result into Global
  Check_Right_ADC = Check_Right_ADC >> 2; // Divide the result by 4
  ADCMCTL0 &= ~ADCINCH_3; // Disable Last channel A3
  ADCMCTL0 |= ADCINCH_5; // Enable Next channel A5
  
  HEX2DEC_CONV(Check_Right_ADC); // Convert result to String

  
  break;
  
  case 0x02: //for thumb
  ThumbwheelADC = ADCMEM0; // Move result into Global
  ThumbwheelADC = ThumbwheelADC >> 2; // Divide the result by 4
  ADCMCTL0 &= ~ADCINCH_5; // Disable Last channel A5
  ADCMCTL0 |= ADCINCH_2; // Enable Next channel A2 which is the beginning
  
  HEX2DEC_CONV(ThumbwheelADC); // Convert result to String

  ChannelADC=0;
  break;
 
  default:
  break;
  }
 
 ADCCTL0 |= ADCENC; // Enable Conversions
 ADCCTL0 |= ADCSC;
 
 default:
 break;
 }
}