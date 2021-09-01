//SerialComms.c
//Tariq Dwekat


#include  "functions.h"
#include <string.h>
#include "macros.h"
#include  "msp430.h"

//Variables
//------------------------------------------------------------------------------
extern volatile unsigned int UCA0_array;
extern volatile unsigned int UCA0write;
extern unsigned int UCA1write;
volatile unsigned int USB_ringread;
extern char USB_Char[SmlRing];
extern char UCA1_Char[SmlRing];
extern char tstCmd[CmdSize];
extern int flagger;
unsigned int CMD_send;
unsigned int CMD_rcvd;
unsigned int CMD_CNT = 0;
char ArrayCMD[20];
unsigned int time;
unsigned moveCar = OFF;
extern volatile unsigned int SelBaudrt;
extern volatile unsigned int IOTflag;
extern volatile unsigned int TimeSeq;
//------------------------------------------------------------------------------


//Initialize interrupts
//------------------------------------------------------------------------------
void Init_Serial_UCA0(void){ 
  int i; 
  for(i=BEGINNING; i<SmlRing; i++){ 
    USB_Char[i] = white_space;                  
  } 
  UCA0write = BEGINNING; 
  USB_ringread = BEGINNING;
  
  // Configure UART 0 
  UCA0CTLW0 = OFF;                            
  UCA0CTLW0 |= UCSWRST;                      
  UCA0CTLW0 |= UCSSEL__SMCLK;               
  
  //115200 Baud Rate
  UCA0BRW = BAUD115BRW;
  UCA0MCTLW = BAUD115MCTLW;
  
  UCA0CTLW0 &= ~ UCSWRST;          
  UCA0IE |= UCRXIE;               
  }

void Init_Serial_UCA1(void){ 
  int i; 
  for(i=BEGINNING; i<SmlRing; i++){ 
    UCA1_Char[i] = white_space;                  
  } 
  UCA1write = BEGINNING; 
  USB_ringread = BEGINNING;
  
  
  // Configure UART 0 
  UCA1CTLW0 = OFF;                            
  UCA1CTLW0 |= UCSWRST;                     
  UCA1CTLW0 |= UCSSEL__SMCLK;               
  
  //115200 Baud Rate
  UCA1BRW = BAUD115BRW;
  UCA1MCTLW = BAUD115MCTLW;
  
  UCA1CTLW0 &= ~ UCSWRST;          
  UCA1IE |= UCRXIE;               
  }
//------------------------------------------------------------------------------

//Interrupt vectors
//------------------------------------------------------------------------------
#pragma vector=EUSCI_A0_VECTOR
__interrupt void eUSCI_A0_ISR(void){
  unsigned int temp; 
  switch(__even_in_range(UCA0IV,0x08)){ 
  case 0:                                     
    break;
  case 2:                                     
      temp = UCA0write++;
      USB_Char[temp] = UCA0RXBUF;//  
      UCA1TXBUF = USB_Char[temp];
      
            if(!(CMD_rcvd)) {
        if(USB_Char[temp] == '&') {
          CMD_rcvd = ON;
        }
      }
      
      if(CMD_rcvd) {
        switch(CMD_CNT++) {
        case 0:
          ArrayCMD[CMD_CNT] = USB_Char[temp];
          break;
        case 1:
          ArrayCMD[CMD_CNT] = USB_Char[temp];
          break;
        case 2:
          ArrayCMD[CMD_CNT] = USB_Char[temp];
          break;
        case 3:
          ArrayCMD[CMD_CNT] = USB_Char[temp];
          break;
        case 4:
          ArrayCMD[CMD_CNT] = USB_Char[temp];
          break;
        case 5:
          ArrayCMD[CMD_CNT] = USB_Char[temp];
          CMD_rcvd = OFF;
          CMD_CNT = OFF;
          moveCar = ON;
          time = OFF;
          break;
        }
      }
      
      if(UCA0write >= sizeof(USB_Char)){ 
        UCA0write = BEGINNING;             
      }
      
     if(USB_Char[temp]=='\n'){ 
     UCA0write = BEGINNING;
     USB_Char[temp]=' '; 
      }    
    break; 
  case 4:                                  
    if(CMD_send){
      switch(UCA0_array++){ 
      case 0:
        UCA0TXBUF = 'A'; 
        break;
      case 1:     
        UCA0TXBUF = 'T';
        break;
      case 2:
        UCA0TXBUF = '+';
        break;
      case 3:
        UCA0TXBUF = 'N';
        break;
      case 4: 
        UCA0TXBUF = 'S';
        break;
      case 5: 
        UCA0TXBUF = 'T';
        break;
      case 6: 
        UCA0TXBUF = 'C';
        break;
      case 7:  
        UCA0TXBUF = 'P';
        break;
      case 8: 
        UCA0TXBUF = '=';
        break;
      case 9:
        UCA0TXBUF = '6';
        break;
      case 10:
        UCA0TXBUF = '9';
        break;
      case 11:
        UCA0TXBUF = '6';
        break;
      case 12:
        UCA0TXBUF = '9';
        break;
      case 13:
        UCA0TXBUF = ',';
        break;
      case 14:
        UCA0TXBUF = '1';
        break;
      case 15:
        UCA0TXBUF = '\r'; 
        break; 
      case 16:   
        UCA0TXBUF = Crt; 
        break; 
      case 17:                                
        UCA0TXBUF = LnFeed; //line
        break; 
      default: 
        UCA0IE &= ~UCTXIE;                     
      break;
      }
    }
  IOTflag = ON; 
}
}


#pragma vector=EUSCI_A1_VECTOR
__interrupt void eUSCI_A1_ISR(void){
  unsigned int temp; 
  switch(__even_in_range(UCA1IV,0x08)){ 
  case 0:                                      
    break;
  case 2:                                     
      temp = UCA1RXBUF;
      UCA0TXBUF = temp;
     if(UCA1_Char[temp]=='\n'){ 
     
     UCA1write = BEGINNING;
     UCA1_Char[temp]=' '; 
      }
     break; 
  default: 
      UCA0IE &= ~UCTXIE;                    
    break;
    }
 IOTflag = ON;   
} 

//------------------------------------------------------------------------------