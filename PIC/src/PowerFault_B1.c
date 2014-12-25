
// Includes
#include "Select_File.h"


#if PowerFault_use == 1

//*********************************************************

inline void PowerFault_Initialization() {
#ifdef PFV1
    setPowerFault_Initialization();
#endif
}
//*********************************************************

inline void PowerFault_Main() {
#ifdef PFV1
    setPowerFault_Main();
#endif
}
//*********************************************************

void setPowerFault_Initialization() {
    PF1.Enable = true;
    PF1.Safe = true;
}
//*********************************************************

void setPF_Enable(char command) {
    PF1.Enable = command;
}

char getPF_Safe() {
    char i = PF1.Safe;
    return i;
}

char getPF_ERROR() {
    char i = PF1.ERROR;
    return PF1.ERROR;
}
//*********************************************************

inline void getPowerFault_AD(char channel) {
    if (PF1.ADtoGO == true) {
        PF1.ADRES = getAD(channel, ADCON1_VDD);
        if (PF1.AD < PF1.ADRES) {
            PF1.AD = PF1.ADRES;
        }
    }
}
//*********************************************************

void setPowerFault_Main() {
    if (PF1.Enable == true) {
        if (PF1.ADtoGO == 0) {
            PF1.Time++;
            if (PF1.Time >= (700 / Main_Time)) {
                PF1.Time = 0;
                PF1.ADtoGO = true;
            }
        } else {
            PF1.Time++;
            if (PF1.Time >= (20 / Main_Time)) {
                PF1.Time = 0;
                PF1.ADtoGO = false;

                if (PF1.ERROR == true) {
                    if (PF1.AD <= (300 + 100) && PF1.AD >= (300 - 100)) {
                        PF1.Count++;
                        if (PF1.Count > 1) {
                            PF1.Count = 0;
                            setPowerFault_Exceptions(0);
                        }
                    } else {
                        PF1.Count = 0;
                    }
                } else {
                    if (PF1.AD >= (300 + 100) || PF1.AD <= (310 - 100)) {
                        PF1.Count++;
                        if (PF1.Count > 1) {
                            PF1.Count = 0;
                            setPowerFault_Exceptions(1);
                        }
                    } else {
                        PF1.Count = 0;
                    }

                }
                PF1.AD = 0;
            }
        }
    }
}

void setPowerFault_Exceptions(char command) {
    char i = command == 1 ? false : true;
    PF1.ERROR = command;
    PF1.Safe = i;
    if (command == 1) {
        DimmerLights_Exceptions(3);
#if Switch_Class == 1 && Dimmer_use == 1
        setLED(2, 1);
#endif
    }
    setLED(99, command + 10);

    setSw_Enable(i);
#ifdef RadioFrequency1
    setRF_Enable(i);
#endif

}
#endif