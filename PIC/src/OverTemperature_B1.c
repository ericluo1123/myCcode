

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
    Temp1.Enable = command;
}
//*********************************************************

char getTemp_Safe() {
    char result = Temp1.Safe;
    return result;
}
//*********************************************************

char getTemp_ERROR() {
    char result = Temp1.ERROR;
    return result;
}
//*********************************************************

void getTemp_AD(char channel) {
    if (Temp1.ADtoGO == true) {
        Temp1.ADRES = getAD(channel, ADCON1_VDD);
        if (Temp1.ADH[0] < Temp1.ADRES) {
            Temp1.ADH[0] = Temp1.ADRES;
        } else if (Temp1.ADH[1] < Temp1.ADRES) {
            Temp1.ADH[1] = Temp1.ADRES;
        }
    }
}
//*********************************************************

void setTemp_Initialization() {
    Temp1.Safe = true;
}
//*********************************************************

inline void Temp_Main() {
#ifdef SYSC1
    setTemp_Main();
#endif	
}
//*********************************************************

void setTemp_Main() {
    if (Temp1.Enable == true) {
        if (Temp1.ADtoGO == false) {
            Temp1.Time++;
            if (Temp1.Time >= 500)//*10ms
            {
                if (getLoad_Safe() == 1 && getPF_Safe() == 1) {
                    Temp1.Time = 0;
                    Temp1.ADtoGO = true;
                    Temp1.Safe = false;

                } else {
                    Temp1.Time = 1000; //*5
                }
            }
        } else {
            Temp1.Time++;
            if (Temp1.Time >= 4) {//*10ms
                Temp1.Time = 0;
                Temp1.ADtoGO = false;
                Temp1.AD = Temp1.ADH[1];
                if (Temp1.ERROR == true) {
                    if (Temp1.AD >= TempSafeValue) {
                        Temp1.Count++;
                        if (Temp1.Count >= TempCountValue) {
                            Temp1.Count = 0;
                            setOverTemp_Exceptions(0);
                        }
                    } else {
                        Temp1.Count = 0;
                    }
                } else {
                    if (Temp1.AD <= TempDangerValue) {
                        Temp1.Count++;
                        if (Temp1.Count >= TempCountValue) {
                            Temp1.Count = 0;
                            setOverTemp_Exceptions(1);
                        }
                    } else {
                        Temp1.Count = 0;
                    }
                }
                if (Temp1.ERROR == 0) {
                    Temp1.Safe = true;
                }
                setProductData(24, Temp1.AD >> 8);
                setProductData(25, Temp1.AD);
                //                setProductData(2, Temp1.AD >> 8);
                //                setProductData(3, Temp1.AD);
                Temp1.ADH[0] = 0;
                Temp1.ADH[1] = 0;
            }
        }
    }
}
//*********************************************************

void setOverTemp_Exceptions(char command) {
    char i = command == 1 ? false : true;
    Temp1.ERROR = command;
    Temp1.Safe = i;
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