
// Includes
#include "Select_File.h"

#if SYSC_use == 1

inline void SYSC_Initialization() {
#ifdef SYSC1
    setSYSC_Initialization();
#endif
}

void setSYSC_Initialization() {
    SYSC.Enable = true;
}

inline void SYSC_Main() {
#ifdef SYSC1
    setSYSC_Main();
#endif
}

void setSYSC_Main() {

    if (SYSC.Enable == true) {
        if (SYSC.ERROR == false) {
            SYSC.Timer++;
            if (SYSC.Timer >= 16)//*10ms
            {
                SYSC.Timer = 0;
                SYSC.ERROR = true;
                setLED(1, 11);
            }
        } else {
            if (getMain_All_Error_Status(1) == 0) {
                SYSC.Timer++;
                if (SYSC.Timer == 50) {//*10ms
                    SYSC.Timer = 0;
                    SYSC.Counter = 0;
                } else {
                    SYSC.Counter++;
                    if (SYSC.Counter == 1000) {
                        SYSC.Counter = 0;
                        SYSC.ERROR = false;
                        setLED(1, 10);
                    }
                }
            }
        }
    }
}

inline void DetectSYSC_Signal() {
    if (SYSC.Signal == false) {
        if (SYSC1 == true) {
            SYSC.Signal = true;
            SYSC.Timer = 0;
        }
    } else {
        if (SYSC1 == false) {
            SYSC.Signal = false;
        }
    }
}

#endif