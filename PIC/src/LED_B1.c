
// Includes
#include "Select_File.h"

#if LED_use == 1

void LedPointSelect(char led) {
#ifdef LED1
    if (led == 1) {
        LED = &VarLED1;
    }
#endif
#ifdef LED2
    else if (led == 2) {
        LED = &VarLED2;
    }
#endif
#ifdef LED3
    else if (led == 3) {
        LED = &VarLED3;
    }
#endif
#ifdef ErrLED
    else if (led == 99) {
        LED = &VarErrLED;
    }
#endif
}
//*********************************************************

inline void LED_Initialization() {
#ifdef LED1
    setLED_Initialization(1);
#endif	
#ifdef LED2
    setLED_Initialization(2);
#endif	
#ifdef LED3
    setLED_Initialization(3);
#endif	
#ifdef ErrLED
    setLED_Initialization(99);
#endif	
}
//*********************************************************

inline void LED_Main() {
#ifdef LED1
    setLED_Main(1);
#endif
#ifdef LED2
    setLED_Main(2);
#endif
#ifdef LED3
    setLED_Main(3);
#endif
#ifdef ErrLED
    setLED_Main(99);
#endif
}
//*********************************************************

void setLED_Initialization(char led) {
    LedPointSelect(led);
    LED->Enable = true;
    setLED(led, 0);
}
//*********************************************************

void setLED(char led, char command) {
    LedPointSelect(led);
    if (command == 0) {
#ifdef LED1
        if (led == true) {
#if LED1_ON == true
            LED1 = false;
#else
            LED1 = true;
#endif
        }
#endif
#ifdef LED2
        else if (led == 2) {
#if LED2_ON == true
            LED2 = false;
#else
            LED2 = true;
#endif
        }
#endif
#ifdef LED3
        else if (led == 3) {
#if LED3_ON == true
            LED3 = false;
#else
            LED3 = true;
#endif
        }
#endif
#ifdef ErrLED
        else if (led == 99) {
#if ErrLED_ON == true
            ErrLED = false;
#else
            ErrLED = true;
#endif
        }
#endif
    } else if (command == 1) {
#ifdef LED1
        if (led == 1) {
#if LED1_ON == true
            LED1 = true;
#else
            LED1 = false;
#endif
        }
#endif
#ifdef LED2
        else if (led == 2) {
#if LED2_ON == true
            LED2 = true;
#else
            LED2 = false;
#endif
        }
#endif
#ifdef LED3
        else if (led == 3) {
#if LED3_ON == true
            LED3 = true;
#else
            LED3 = false;
#endif
        }
#endif
#ifdef ErrLED
        else if (led == 99) {
#if ErrLED_ON == true
            ErrLED = true;
#else
            ErrLED = false;
#endif
        }
#endif
    } else if (command == 10) {
        LED->GO = false;
        LED->Time = 0;
#ifdef LED1
        if (led == 1) {
#if LED1_ON == true
            LED1 = false;
#else
            LED1 = true;
#endif
        }
#endif
#ifdef LED2
        else if (led == 2) {
#if LED2_ON == true
            LED2 = false;
#else
            LED2 = true;
#endif
        }
#endif
#ifdef LED3
        else if (led == 3) {
#if LED3_ON == true
            LED3 = false;
#else
            LED3 = true;
#endif
        }
#endif
#ifdef ErrLED
        else if (led == 99) {
#if ErrLED_ON == true
            ErrLED = false;
#else
            ErrLED = true;
#endif
        }
#endif
    } else if (command == 11) {
        LED->GO = true;
    }
}

//*********************************************************

void setLED_Main(char led) {
    LedPointSelect(led);
    if (LED->GO == true) {
        LED->Time++;
        if (LED->Time >= LEDTime / 10) {
            LED->Time = 0;
#ifdef LED1
            if (led == 1) {
                LED1 = LED1 == true ? false : true;
            }
#endif
#ifdef LED2
            else if (led == 2) {
                LED2 = LED2 == true ? false : true;
            }
#endif
#ifdef LED3
            else if (led == 3) {
                LED3 = LED3 == true ? false : true;
            }
#endif
#ifdef ErrLED
            else if (led == 99) {
                ErrLED = ErrLED == true ? false : true;
            }
#endif
        }
    }
}
//*********************************************************	


//end file
#endif