
// Includes
#include "../1.Switch_1Key_Dimmer.X/Select_File.h"

#if SYSC_use == 1

void selectSYSCPoint(char sysc) {
#ifdef SYSC_1
    if (sysc == 1) {
        SYSC = &_SYSC1;
    }
#endif
}

void SYSC_Initialization() {
#ifdef SYSC_1
    setSYSC_Initialization(1);
#endif
}

void setSYSC_Initialization(char sysc) {
    selectSYSCPoint(sysc);
    SYSC->Enable = 1;
}

void SYSC_Main() {
#ifdef SYSC_1
    setSYSC_Main(1);
#endif
}

void setSYSC_Main(char sysc) {
    selectSYSCPoint(sysc);
    if (SYSC->Enable) {
        if (!SYSC->ERROR) {
            if (!SYSC) {
                ErrLED = 0;
                SYSC->Time++;
                if (SYSC->Time >= 16)//*10ms
                {
                    SYSC->Time = 0;
                    SYSC->ERROR = 1;
                    setLED(99, 11);

#ifdef CDS_1
#endif

#ifdef PIR_1		
#endif	
                }
            }
        }
    }
}

void DetectSYSC_Signal(char sysc) {
    selectSYSCPoint(sysc);
    SYSC->Time = SYSC_1 ? 0 : SYSC->Time;
}
#endif