

// Includes
#include "Select_File.h"

#if OverTemperature_use == 1
//*********************************************************

inline void Temp_Initialization() {
#ifdef SYSC1
    setTemp_Initialization();
#endif
}
//*********************************************************

void setTemp_Enable(char command) {
    Temp.Enable = command;
}
//*********************************************************

char getTemp_Safe() {
    char result = Temp.Safe;
    return result;
}
//*********************************************************

char getTemp_ERROR() {
    char result = Temp.ERROR;
    return result;
}
//*********************************************************

void getTemp_AD(char channel) {
    if (Temp.ADtoGO == true) {
        Temp.ADRES = getAD(channel, ADCON1_VDD);
        if (Temp.ADH[0] < Temp.ADRES) {
            Temp.ADH[0] = Temp.ADRES;
        } else if (Temp.ADH[1] < Temp.ADRES) {
            Temp.ADH[1] = Temp.ADRES;
        }
    }
}
//*********************************************************

void setTemp_Initialization() {
    Temp.Safe = true;
}
//*********************************************************

inline void Temp_Main() {
#ifdef SYSC1
    setTemp_Main();
#endif	
}
//*********************************************************

void setTemp_Main() {
    if (Temp.Enable == true) {
        if (Temp.ADtoGO == false) {
            Temp.Time++;
            if (Temp.Time >= 500) {//*10ms
                if (getLoad_Safe() == 1) {
                    Temp.Time = 0;
                    Temp.ADtoGO = true;
                    Temp.Safe = false;

                } else {
                    Temp.Time = 500; //*10ms
                }
            }
        } else {
            Temp.Time++;
            if (Temp.Time >= 4) {//*10ms
                Temp.Time = 0;
                Temp.ADtoGO = false;
                Temp.AD = Temp.ADH[1];
                if (Temp.ERROR == true) {
                    if (Temp.AD >= TempSafeValue) {
                        Temp.Count++;
                        if (Temp.Count >= TempCountValue) {
                            Temp.Count = 0;
                            setOverTemp_Exceptions(0);
                        }
                    } else {
                        Temp.Count = 0;
                    }
                } else {
                    if (Temp.AD <= TempDangerValue) {
                        Temp.Count++;
                        if (Temp.Count >= TempCountValue) {
                            Temp.Count = 0;
                            setOverTemp_Exceptions(1);
                        }
                    } else {
                        Temp.Count = 0;
                    }
                }
                if (Temp.ERROR == 0) {
                    Temp.Safe = true;
                }
                setProductData(24, Temp.AD >> 8);
                setProductData(25, Temp.AD);
                //                setProductData(2, Temp1.AD >> 8);
                //                setProductData(3, Temp1.AD);
                Temp.ADH[0] = 0;
                Temp.ADH[1] = 0;
            }
        }
    }
}
//*********************************************************

void setOverTemp_Exceptions(char command) {
    char i = command == 1 ? false : true;
    Temp.ERROR = command;
    Temp.Safe = i;
    if (command == 1) {
        DimmerLights_Exceptions(1);
#if Switch_Class == 1 && Dimmer_use == 1
        setLED(2, 1);
#endif
    } else if (command == 0) {
        setBuz(2, BuzzerOnOffTime);
    }
    //Lights_ERROR();

    setLED(99, command + 10);

    setSw_Enable(i);
#ifdef RadioFrequency1
    setRF_Enable(i);
#endif

}
#endif