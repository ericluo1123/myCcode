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


    void uartC_timer1(int time_ms);
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
                unsigned Timer1_start : 1;
                unsigned Switch_Enable_1 : 1;
                unsigned switch_status : 1;
                unsigned switch_status2 : 1;
                unsigned switch_already_press : 1;
                unsigned LED_Mode1 : 1;
                unsigned switch_already_release : 1;
                unsigned switch_debounce : 1;
                unsigned siwtch_debounce1 : 1;
                unsigned switch_function : 1;
                unsigned LED_GO : 1;
                unsigned switch_Mode1 : 1;
                unsigned switch_Mode2 : 1;
                unsigned switch_learn : 1;
                unsigned switch_dimming:1;
            };
        };
        int time1;
        int timer1_value;

        int time2;
        int time3;

        int LED_Time;
        int LED_Time_Value;

        int LED_Time2;



    };

    struct uartC u1;

#ifdef	__cplusplus
}
#endif

#endif	/* MYUARTTORF_H */

