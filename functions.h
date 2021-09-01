//******************************************************************************
//
//  Description: This file contains the Function prototypes
//
//  Tariq Dwekat
//  Spring 2021
//******************************************************************************
// Functions

// Initializations
//------------------------------------------------------------------------------
void Init_Clocks(void);
void Init_Conditions(void);
void TimedMovement(void);
void Init_Conditions(void);
void Init_Serial_UCA0(void);
void Init_Serial_UCA1(void);
void Init_Ports(void);
void Init_Port1(void);
void Init_Port2(void);
void Init_Port3(void);
void Init_Port4(void);
void Init_Port5(void);
void Init_Port6(void);
//------------------------------------------------------------------------------

// Interrupts
//------------------------------------------------------------------------------
void enable_interrupts(void);
__interrupt void Timer0_B0_ISR(void);
__interrupt void switch_interrupt(void);
//------------------------------------------------------------------------------

// LED Configuration Functions
//------------------------------------------------------------------------------
void Init_LEDs(void);
void IR_LED_control(char selection);
void CtrlBackLight(char selection);
//------------------------------------------------------------------------------

// LCD Display functions
//------------------------------------------------------------------------------
void Display_Process(void);
void Display_Update(char p_L1,char p_L2,char p_L3,char p_L4);
void cleandisplay(void);
void enable_display_update(void);
void update_string(char *string_data, int string);
void Init_LCD(void);
void lcd_clear(void);
void lcd_putc(char c);
void lcd_puts(char *s);
void lcd_power_on(void);
void lcd_write_line1(void);
void lcd_write_line2(void);
void lcd_enter_sleep(void);
void lcd_exit_sleep(void);
void Write_LCD_Ins(char instruction);
void Write_LCD_Data(char data);
void ClrDisplay(void);
void ClrDisplay_Buffer_0(void);
void ClrDisplay_Buffer_1(void);
void ClrDisplay_Buffer_2(void);
void ClrDisplay_Buffer_3(void);
void lcd_write(unsigned char c);
void lcd_write_line1(void);
void lcd_write_line2(void);
void lcd_write_line3(void);
void SetPostion(char pos);
void DisplayOnOff(char data);
void lcd_BIG_mid(void);
void lcd_4line(void);
void lcd_out(char *s, char line, char position);
void lcd_rotate(char view);
void lcd_command( char data);
void LCD_test(void);
void LCD_iot_meassage_print(int nema_index);
//------------------------------------------------------------------------------

//Wheelies Functions for motors
//------------------------------------------------------------------------------
void IR_TurtleP2(void);
void ShutDownPWM(void);
void ForwardwPWM(void);
void ReversewPwm(void);
void IR_Turtle (void);
void LeftwPWM(void);
void RightwPWM(void);
void CarCMD(void);
void Motors_Off(void);
void Reverse_On(void);
void Left_Forward_On(void);
void Right_Reverse_On(void);
void Right_Forward_On(void);
void Left_Reverse_On(void);
//------------------------------------------------------------------------------

//LINES AND CONVERSION
//------------------------------------------------------------------------------
void HEX2DEC_CONV(int hex_value);
void Init_ADC(void);
void ColorChecker(void);
void TimedMovement(void);
void TimedMovement2(void);
//------------------------------------------------------------------------------


// Timers
//------------------------------------------------------------------------------
void Init_Timers(void);
void Init_Timer_B0(void);
void Init_Timer_B1(void);
void Init_Timer_B2(void);
void Init_Timer_B3(void);
//------------------------------------------------------------------------------

// Switches
//------------------------------------------------------------------------------
void Init_Switches(void);
void switch_control(void);
void enable_switch_SW1(void);
void enable_switch_SW2(void);
void disable_switch_SW1(void);
void disable_switch_SW2(void);
void Switches_Process(void);
void Init_Switch(void);
void Switch_Process(void);
void Switch1_Process(void);
void Switch2_Process(void);
void menu_act(void);
void menu_select(void);
void usleep(unsigned int usec);
void usleep10(unsigned int usec);
void five_msec_sleep(unsigned int msec);
void measure_delay(void);
void out_control_words(void);
//------------------------------------------------------------------------------

//Initialization functions
//------------------------------------------------------------------------------
void Init_Ports(void);
void Init_Port1(void);
void Init_Port2(void);
void Init_Port3(void);
void Init_Port4(void);
void Init_Port5(void);
void Init_Port6(void);
//------------------------------------------------------------------------------