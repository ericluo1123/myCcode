/* 
 * File:   3_Remote_1_Key.h
 * Author: taianluo
 *
 * Created on 2015年3月9日, 下午 4:10
 */

#ifndef 3_REMOTE_1_KEY_H
#define	3_REMOTE_1_KEY_H

#ifdef	__cplusplus
extern "C" {
#endif

    /**
     * micro controller param
     */
#define chip_Select _PIC16F1516

#define _RA0    OverLoad1
#define _RA1    PIR1_VR
#define _RA2    CDS1_VR
#define _RA3    PIR_1
#define _RA4    Relay1
#define _RA5    SYSC1
#define _RA6    empty1
#define _RA7    DimmerReference1

#define _RB0    CDS_1
#define _RB1    Buzzer1
#define _RB2    Triac1
#define _RB3    ErrLED
#define _RB4    LED1
#define _RB5    LED2
#define _RB6    ICSPCLK
#define _RB7    ICSPAT

#define _RC0    empty2
#define _RC1    empty3
#define _RC2    empty4
#define _RC3    empty5
#define _RC4    empty6
#define _RC5    empty7
#define _RC6    TX
#define _RC7    RX

#define _TRISA 	0b11110111;
#define _TRISB 	0b00000100;
#define _TRISC 	0b00100110;

#define _LATA	0b00000000;
#define _LATB	0b00000000;
#define _LATC	0b00000000;

#define _ANSELA 0b00001110;
#define _ANSELB 0b00000000;
#define _ANSELC 0b00000000;

#define _PORTA 	0b11110111;
#define _PORTB 	0b00000100;
#define _PORTC 	0b00100110;

#define _WPUB   0b00000000;

    /**
     * chip properties
     */


    /**
     * product properties
     */



#ifdef	__cplusplus
}
#endif

#endif	/* 3_REMOTE_1_KEY_H */

