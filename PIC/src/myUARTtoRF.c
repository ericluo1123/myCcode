
// Includes
#include "Select_File.h"

#if myUARTtoRF_use == 1

void myUARTtoRF_Initialization() {
    u1.time_value = 0;
    PowerLED = 0;
    LED1 = 1;
    LED2 = 1;
}
//******************************************************************************

void myUARTtoRF_Main() {
    uartC_timer_strat(u1.time_value);

    if (TTPW == false) {
        if (u1.Switch_Status == false) {
            u1.Switch_Status = true;
            u1.Timer_Enable = true;
            u1.time_value = 100;
            u1.time = 0;
        }
    } else {
        if (u1.Switch_Status == true) {
            u1.Timer_Enable = true;
            u1.time_value = 100;
            u1.time = 0;
            u1.Switch_Status = false;
        }
    }

    if (u1.Switch_Enable_1 == true) {
        u1.Switch_Enable_1 = false;
        LED1 = LED1 == true ? false : true;
    }
}

void uartC_timer_strat(int time_ms) {

    if (u1.Timer_Enable == true) {
        u1.time++;
        if (u1.time == time_ms / Main_Time) {
            u1.time = 0;
            u1.Timer_Enable = false;
            u1.Switch_Enable_1 = u1.Switch_Status == true ? false : true;
        }
    }

}
#endif
