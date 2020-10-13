
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

//PORTA defines
#define RS  RA5
#define E   RA4

//PORTC defines
#define D4  RC0
#define D5  RC1
#define D6  RC2
#define D7  RC3

void main(void)
{
    ANSEL  = 0x00;
    CMCON0 = 0x07;
    
    TRISA  = 0x00;
    PORTA  = 0x00;
    
    TRISC  = 0x00;
    PORTC  = 0x00;
    ////////////////////////////////////////
    __delay_ms(50);
    PORTAbits.RS = 0;
    PORTCbits.D7 = 0;
    PORTCbits.D6 = 0;
    PORTCbits.D5 = 1;
    PORTCbits.D4 = 1;
    __delay_ms(5);
    PORTAbits.E  = 1;
    __delay_ms(50);
    PORTAbits.E  = 0;
    ////////////////////////////////////////
    __delay_ms(50);
    PORTAbits.RS = 0;
    PORTCbits.D7 = 0;
    PORTCbits.D6 = 0;
    PORTCbits.D5 = 1;
    PORTCbits.D4 = 1;
    __delay_ms(5);
    PORTAbits.E  = 1;
    __delay_ms(50);
    PORTAbits.E  = 0;
    ////////////////////////////////////////
    __delay_ms(50);
    PORTAbits.RS = 0;
    PORTCbits.D7 = 0;
    PORTCbits.D6 = 0;
    PORTCbits.D5 = 1;
    PORTCbits.D4 = 1;
    __delay_ms(5);
    PORTAbits.E  = 1;
    __delay_ms(50);
    PORTAbits.E  = 0;
    ////////////////////////////////////////
    __delay_ms(50);
    PORTAbits.RS = 0;
    PORTCbits.D7 = 0;
    PORTCbits.D6 = 0;
    PORTCbits.D5 = 1;
    PORTCbits.D4 = 0;
    __delay_ms(5);
    PORTAbits.E  = 1;
    __delay_ms(50);
    PORTAbits.E  = 0;
    ////////////////////////////////////////
    __delay_ms(50);
    PORTAbits.RS = 0;
    PORTCbits.D7 = 0;
    PORTCbits.D6 = 0;
    PORTCbits.D5 = 1;
    PORTCbits.D4 = 0;
    __delay_ms(5);
    PORTAbits.E  = 1;
    __delay_ms(50);
    PORTAbits.E  = 0;
    ////////////////////////////////////////
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
    PORTCbits.D7 = 0;
    PORTCbits.D6 = 0;
    PORTCbits.D5 = 0;
    PORTCbits.D4 = 0;
    __delay_ms(5);
    PORTAbits.E  = 1;
    __delay_ms(50);
    PORTAbits.E  = 0;
    
    __delay_ms(50);
    PORTAbits.RS = 0;
    PORTCbits.D7 = 1;
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
    PORTCbits.D7 = 0;
    PORTCbits.D6 = 0;
    PORTCbits.D5 = 0;
    PORTCbits.D4 = 1;
    __delay_ms(5);
    PORTAbits.E  = 1;
    __delay_ms(50);
    PORTAbits.E  = 0;
    ////////////////////////////////////////
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
    PORTCbits.D7 = 0;
    PORTCbits.D6 = 1;
    PORTCbits.D5 = 1;
    PORTCbits.D4 = 0;
    __delay_ms(5);
    PORTAbits.E  = 1;
    __delay_ms(50);
    PORTAbits.E  = 0;
    
    __delay_ms(50);
    PORTAbits.RS = 1;
    PORTCbits.D7 = 0;
    PORTCbits.D6 = 1;
    PORTCbits.D5 = 0;
    PORTCbits.D4 = 0;
    __delay_ms(5);
    PORTAbits.E  = 1;
    __delay_ms(50);
    PORTAbits.E  = 0;
    ////////////////////////////////////////
    __delay_ms(50);
    PORTAbits.RS = 1;
    PORTCbits.D7 = 1;
    PORTCbits.D6 = 0;
    PORTCbits.D5 = 0;
    PORTCbits.D4 = 0;
    __delay_ms(5);
    PORTAbits.E  = 1;
    __delay_ms(50);
    PORTAbits.E  = 0;
    
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
    
    __delay_ms(50);
    PORTAbits.RS = 0;
    PORTCbits.D7 = 1;
    PORTCbits.D6 = 1;
    PORTCbits.D5 = 0;
    PORTCbits.D4 = 0;
    __delay_ms(5);
    PORTAbits.E  = 1;
    __delay_ms(50);
    PORTAbits.E  = 0;
    
    while(1);

}

