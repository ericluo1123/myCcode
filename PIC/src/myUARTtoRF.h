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

#if myUARTtoRF_use == 1
#define UARTtoRF_Debug 1


    void uartC_timer_strat(int time_ms);
    void uartC_switch_function_1();
    void myUARTtoRF_Initialization();
    void myUARTtoRF_Main();
    
#else
#define myUARTtoRF_Initialization() ;
#define myUARTtoRF_Main() ;
#endif

    struct uartC {

        union {

            struct {
                unsigned Timer_Enable : 1;
                unsigned Switch_Enable_1:1;
                unsigned Switch_Status:1;
            };
        };
        int time;
        int time_value;
    };

    struct uartC u1;

#ifdef	__cplusplus
}
#endif

#endif	/* MYUARTTORF_H */

