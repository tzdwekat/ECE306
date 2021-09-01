// Hex2DecConv
// Tariq Dwekat

#include  "msp430.h"
#include  "functions.h"
#include <string.h>
#include  "macros.h"


//Variables
//------------------------------------------------------------------------------
extern char display_line[4][11];
char ADCchar[DispWide];
extern volatile unsigned char ChangeDisp;
char ones_place;
char tens_place;
char hundredths_place;
char thousandths_place;
//------------------------------------------------------------------------------

//Clear up the display
//------------------------------------------------------------------------------
void cleandisplay(void) {
 strcpy(display_line[OFF], "          ");
  update_string(display_line[OFF], OFF);
  strcpy(display_line[ON], "          ");
  update_string(display_line[ON], ON);
  strcpy(display_line[2], "          ");
  update_string(display_line[2], 2);
  strcpy(display_line[3], "          ");
  update_string(display_line[3], 3);
  ChangeDisp = ON;
}
//------------------------------------------------------------------------------

//Conversion Function
//------------------------------------------------------------------------------
void HEX2DEC_CONV(int hex_value){ 
ADCchar[TopofDisplay] = '0';
ADCchar[MidP1Display] = '0';
ADCchar[MidP2Display] = '0';
ADCchar[BotofDisplay] = '0';
tens_place='0';
thousandths_place='0';
hundredths_place='0';
ones_place='0';

while (hex_value > 999){
hex_value = hex_value - 1000;
thousandths_place = thousandths_place + 1;
ADCchar[BotofDisplay] = 0x30 | thousandths_place; 
}
while (hex_value > 99){
hex_value = hex_value - 100;
hundredths_place = hundredths_place + 1;
ADCchar[MidP1Display] = 0x30 | hundredths_place; 
}
while (hex_value > 9){
hex_value = hex_value - 10;
tens_place = tens_place + 1;
ADCchar[MidP2Display] = 0x30 | tens_place; 
}
while (hex_value>0){
  hex_value=hex_value-1;
  ones_place=ones_place+1;
ADCchar[BotofDisplay] = 0x30 | ones_place; 
}
}
//------------------------------------------------------------------------------