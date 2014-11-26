/* 
 * File:   myUARTtoRF.h
 * Author: taianluo
 *
 * Created on 2014年11月26日, 下午 2:04
 */

#ifndef MYUARTTORF_H
#define	MYUARTTORF_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#if myUARTtoRF_use == 1
#define UARTtoRF_Debug 1

void myUARTtoRF_Initialization();
void myUARTtoRF_Main();
#else
#define myUARTtoRF_Initialization() ;
#define myUARTtoRF_Main() ;
#endif
#endif	/* MYUARTTORF_H */

