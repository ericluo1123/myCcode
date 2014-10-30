/* 
 * File:   timer1 example.c
 * Author: taianluo
 *
 * Created on 2014年10月30日, 下午 1:05
 */

#include <stdio.h>
#include <stdlib.h>
#include <pic.h>

/**
 * 函式宣告
 */
void TMR1_Set();
void TMR1_ISR();
int Count, Counter;

/**
 * Timer初始化
 */
void TMR1_Init() {
    /*
     * FOSC:
     *      16MHZ
     * T1CON:
     *      TMR1CS:Timer1 Clock Source = Timer1 clock source is system clock (FOSC)
     *      T1CKPS:Timer1 Input Clock Prescale = 1:8 Prescale value
     *      TMR1ON:Timer1 On = Enable
     *      
     * Interrupt time :
     *      Time=(1/FOSC)*T1CKPS
     *      Time=((1/16)*8)
     *      Time=0.5us
     *
     */

    OSCCON = 0x78;
    T1CON = 0x71;
    TMR1H = (65536 - 2000) / 256;
    TMR1L = (65536 - 2000) % 256;
    TMR1IE = 1;
    PEIE = 1;
    GIE = 1;
}

/**
 * 主程式
 */
void main() {
    TRISB = 0x00;
    LATB = 0x00;
    ANSELA = 0x00;
    PORTB = 0x00;
    
    TMR1_Init();

    while (1); //wait interrupt
}

/**
 * 中斷指向函式，無需宣告
 */
void interrupt ISR(void) {
    if (TMR1IE == 1 && TMR1IF == 1) {

        //restore count
        TMR1H = (65536 - 2000) / 256;
        TMR1L = (65536 - 2000) % 256;
        TMR1IF = 0;

        //TODO
        Counter++;
        if (Counter == 1000) {
            Counter = 0;
            RB5 = RB5 == 1 ? 0 : 1;
        }
    }
}


