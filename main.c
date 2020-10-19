
// CONFIG
#pragma config FOSC = INTOSCIO  // Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA4/OSC2/CLKOUT pin, I/O function on RA5/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // MCLR Pin Function Select bit (MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Detect (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)


#include <xc.h>

#include <stdio.h>
#include <stdint.h>        /* For uint8_t definition */
#include <stdbool.h>       /* For true/false definition */

#include <pic16f688.h>

#define _XTAL_FREQ 4000000UL

//lcd commands
#define DISPLAY_CLEAR (uint8_t)0x01


#define RS  RA5
#define E   RA4

#define D0  NULL
#define D1  NULL
#define D2  NULL
#define D3  NULL

#define D4  RC0
#define D5  RC1
#define D6  RC2
#define D7  RC3

void __lcd_en_pulse(void)
{
    __delay_us(10);
    PORTAbits.E  = 1;
    __delay_us(500);
    PORTAbits.E  = 0;
}

void __lcd_port_write(uint8_t data)
{
    if(data & 0x01)
		D4 = 1;
	else
		D4 = 0;

	if(data & 0x02)
		D5 = 1;
	else
		D5 = 0;

	if(data & 0x04)
		D6 = 1;
	else
		D6 = 0;
    
	if(data & 0x08)
		D7 = 1;
	else
		D7 = 0;
}

void __lcd_cmd(uint8_t cmd)
{
    RS = 0;
    __lcd_port_write(cmd);
    __lcd_en_pulse();
    
}
void __lcd_send_char(uint8_t ascii)
{
    RS = 1;
    
    uint8_t high = 0;
    uint8_t low  = 0;
    high = ascii >> 4;
    low  = ascii & 0x0F;    
    
    __lcd_port_write(high);
    __lcd_en_pulse();
    __lcd_port_write(low);
    __lcd_en_pulse();
}

void LCD_set_cursor(uint8_t row, uint8_t column)
{   
    if(row == 1)
    {
        __lcd_cmd(0x08);
    }
    else if(row == 2)
    {
        __lcd_cmd(0x0C);
    }
    uint8_t temp = column - 1;
    __lcd_cmd(temp);
}

void LCD_Init()
{
    __delay_ms(50);
    //set write command
    __lcd_cmd(0x03);
    __delay_ms(5);
    
    //function set, interface 8bit
    __lcd_cmd(0x03);
    __delay_us(120);
    
    //function set, interface 8bit
    __lcd_cmd(0x03);
    
    //function set, interface 8bit, setting to 4bit
    __lcd_cmd(0x02);
    
    // After this point commands are written in 2 bursts of 1 nibble
    //function set, interface 4bit 
    __lcd_cmd(0x02);
    __lcd_cmd(0x08);
    
    //display off 
    __lcd_cmd(0x00);
    __lcd_cmd(0x08);
    
    //display clear
    __lcd_cmd(0x00);
    __lcd_cmd(0x01);
    
    //entry mode
    __lcd_cmd(0x00);
    __lcd_cmd(0x06);
}

void main(void)
{
    ANSEL  = 0x00;
    CMCON0 = 0x07;
    
    TRISA  = 0x00;
    PORTA  = 0x00;
    
    TRISC  = 0x00;
    PORTC  = 0x00;
    ////////////////////////////////////////
    
    LCD_Init();
    
    __lcd_send_char('H');
    __lcd_send_char('e');
    __lcd_send_char('l');
    __lcd_send_char('l');
    __lcd_send_char('o');
    
    
    
    
    
    
     __delay_ms(50);
    PORTAbits.RS = 0;
    PORTCbits.D7 = 0;
    PORTCbits.D6 = 0;
    PORTCbits.D5 = 0;
    PORTCbits.D4 = 0;
    __delay_ms(5);
    PORTAbits.E  = 1;
    __delay_ms(50);
    PORTAbits.E  = 0;
    ////////////////////////////////////////
    __delay_ms(50);
    PORTAbits.RS = 0;
    PORTCbits.D7 = 1;
    PORTCbits.D6 = 1;
    PORTCbits.D5 = 1;
    PORTCbits.D4 = 1;
    __delay_ms(5);
    PORTAbits.E  = 1;
    __delay_ms(50);
    PORTAbits.E  = 0;

    LCD_set_cursor(2,10);
    
    __lcd_send_char('H');
    __lcd_send_char('e');
    __lcd_send_char('l');
    __lcd_send_char('l');
    __lcd_send_char('o');


    
    while(1);

}

