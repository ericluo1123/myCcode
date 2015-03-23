
// Includes
#include "Select_File.h"

#if myUARTtoRF_use == 1

void myUARTtoRF_Initialization() {
    PowerLED = 0;
    LED1 = 1;
    LED2 = 1;

}

void uartC_timer1_start(int time_ms);
void uartC_timer1_reset();
void uartC_timer1_close();
void uartC_Button();
void uartC_switch_control();
void uartC_LED();
void uartC_LED_start(char time_ms);
void uartC_LED_close();

//******************************************************************************

void myUARTtoRF_Main() {

    uartC_LED();
    uartC_Button();

    if (u1.switch_Mode2 == true) {
        u1.time3++;
        if (u1.time3 >= 3000 / Main_Time) {
            u1.time3 = 0;
            u1.switch_Mode2 = false;
            u1.LED_Mode1 = true;
            setRF_Learn(0);
        }
    }
}

void uartC_LED() {

    if (u1.LED_GO == true) {
        u1.LED_Time++;
        if (u1.LED_Time == u1.LED_Time_Value / Main_Time) {
            u1.LED_Time = 0;
            LED1 = LED1 == true ? false : true;
            if (u1.switch_Mode1 == true) {
                u1.switch_Mode1 = false;
                u1.LED_GO = false;
            }

            if (u1.LED_Mode1 == true) {
                u1.LED_Mode1 = false;
                u1.LED_GO = false;
                LED1 = true;
            }
        }
    }
}

void uartC_LED_start(char time_ms) {
    u1.LED_Time_Value = time_ms;
    u1.LED_GO = true;
    u1.LED_Time = 0;
    LED1 = false;
}

void uartC_LED_close() {
    u1.LED_GO = false;
    u1.LED_Time = 0;
    LED1 = true;
}

void uartC_Button() {

    if (TTPW == false) {//press

        if (u1.switch_debounce == false) {
            uartC_timer1(100);
        } else if (u1.siwtch_debounce1 == false) {
            uartC_timer1(1500);
        }

    } else {//release
        if (u1.switch_debounce == true) {
            u1.time2++;
            if (u1.time2 >= 100 / Main_Time) {
                u1.time2 = 0;
                u1.switch_debounce = false;
                u1.siwtch_debounce1 = false;
            }
        }
        uartC_timer1_reset();
    }
}

void uartC_switch_control() {
    if (u1.switch_Mode1 == true) {
        if (u1.switch_Mode2 == true) {
            u1.switch_Mode2 = false;
            u1.time3 = 0;
            uartC_LED_close();
            setRF_Learn(0);
            u1.switch_dimming = true;
        }
        setTxData();
        uartC_LED_start(100);

    } else if (u1.switch_Mode2 == true) {
        uartC_LED_start(300);
        setRF_Learn(1);
    }
}

void uartC_timer1(int time_ms) {

    u1.time1++;
    if (u1.time1 == time_ms / Main_Time) {
        u1.time1 = 0;

        if (u1.switch_debounce == false) {
            u1.switch_debounce = true;
            u1.switch_Mode1 = true;
        } else if (u1.siwtch_debounce1 == false) {
            u1.siwtch_debounce1 = true;
            u1.switch_Mode2 = true;
        }

        uartC_switch_control();

        u1.time2 = 0;
    }
}

void uartC_timer1_start(int time_ms) {
    u1.Timer1_start = true;
    u1.timer1_value = time_ms;
    u1.time1 = 0;
}

void uartC_timer1_reset() {
    u1.time1 = 0;
}

void uartC_timer1_close() {
    u1.Timer1_start = false;
    u1.time1 = 0;
}
#endif
