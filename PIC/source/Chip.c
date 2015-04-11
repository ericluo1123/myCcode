/* 
 * File:   Chip.c
 * Author: Patrick
 *
 * Created on 2015年4月11日, 上午 11:33
 */

#include "Main.h"

//config
#ifdef MCU_16F723A

#if Use_XC8 ==1
#pragma config FOSC = INTOSCIO , WDTE = _WDTE, BOREN = OFF , PLLEN = _PLLEN
#pragma config VCAPEN = DIS , CP = ON
#endif
//__CONFIG(FOSC_INTOSCIO & _WDTE & BOREN_OFF & PLEEN_Value); // v8.84
//__CONFIG(VCAPEN_DIS); // WRT_OFF
#endif

#ifdef MCU_16F1516
#pragma config FOSC = INTOSC , WDTE = _WDTE , BOREN = OFF
#pragma config VCAPEN = OFF,WRT = BOOT , CP = ON
//__CONFIG(FOSC_INTOSC & _WDTE); // v8.84
//__CONFIG(VCAPEN_OFF & WRT_BOOT); // WRT_OFF
#endif

#ifdef MCU_16F1518
#pragma config FOSC = INTOSC,WDTE = _WDTE , BOREN = OFF
#pragma config VCAPEN = OFF,WRT = HALF , CP = ON
// __CONFIG(FOSC_INTOSC & _WDTE & BOREN_OFF); // v8.84
// __CONFIG(VCAPEN_OFF & WRT_HALF); // WRT_OFF WRT_BOOT WRT_HALF
#endif

/*
 * Chip Instance
 */


