
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

inline void getTemp_AD(char channel) {
    //#if SYSC_use == 1
    //    if (SYSC1 == true) {
    if (Temp.ADtoGO == true) {
        Temp.ADRES = getAD(channel, ADCON1_VDD);
        if (Temp.ADRES > 0) {
            if (Temp.ADH[0] < Temp.ADRES) {
                Temp.ADH[0] = Temp.ADRES;
            } else if (Temp.ADH[1] < Temp.ADRES) {
                Temp.ADH[1] = Temp.ADRES;
            }
        }
    }
    //    }

    //#else
    //    if (Temp.ADtoGO == true) {
    //        Temp.GO = true;
    //        Temp.ADRES = getAD(channel, ADCON1_VDD);
    //        if (Temp.ADH[0] < Temp.ADRES) {
    //            Temp.ADH[0] = Temp.ADRES;
    //        } else if (Temp.ADH[1] < Temp.ADRES) {
    //            Temp.ADH[1] = Temp.ADRES;
    //        }
    //    }
    //#endif
}
//*********************************************************

void setTemp_Initialization() {

}
//*********************************************************

inline void Temp_Main() {
#ifdef SYSC1
    setTemp_Main();
#endif	 
}
//*********************************************************

void setTemp_Main() {
    char error = getMain_All_Error_Status(0);
    if (Temp.Enable == true) {
        //        if (error == 1 || error == 3) {
        //            Temp.Time = 0;
        //            Temp.ADtoGO = false;
        //            Temp.ADH[0] = 0;
        //            Temp.ADH[1] = 0;
        //        } else {
        if (Temp.ADtoGO == false) {
            Temp.Time++;
            if (Temp.Time >= (5000 / Main_Time)) {//*10ms
                Temp.Time = 0;
                Temp.ADtoGO = true;
            }
        } else {
            Temp.Time++;
            if (Temp.Time >= (40 / Main_Time)) {//*10ms
                Temp.Time = 0;

                if (Temp.ADH[0] > 0 && Temp.ADH[1] > 0) {
                    Temp.ADtoGO = false;
                    Temp.AD = (Temp.ADH[0] + Temp.ADH[1]) / 2;

#if PIR_use == 1 && Dimmer_use == 0
                    if (getMain_All_LightsStatus() == 1) {
                        Temp.SafeValue = TempSafeValueH;
                        Temp.DangerValue = TempDangerValueH;
                    } else {
                        Temp.SafeValue = TempSafeValueL;
                        Temp.DangerValue = TempDangerValueL;
                    }
#elif PIR_use == 1 && Dimmer_use == 1
                    Temp.SafeValue = TempSafeValue;
                    Temp.DangerValue = TempDangerValue;
#elif PIR_use == 0 && Dimmer_use == 1
                    Temp.SafeValue = TempSafeValue;
                    Temp.DangerValue = TempDangerValue;
#else
                    Temp.SafeValue = 0;
                    Temp.DangerValue = 0;
#endif

                    if (Temp.ERROR == true) {
                        if (Temp.AD >= Temp.SafeValue) {
                            Temp.Count++;
                            if (Temp.Count >= TempCountValue) {
                                Temp.Count = 0;
                                Temp.ERROR = false;
                                setBuz(2, 100);
                            }
                        } else {
                            Temp.Count = 0;
                        }
                    } else {
                        if (Temp.AD <= Temp.DangerValue) {
                            Temp.Count++;
                            if (Temp.Count >= TempCountValue) {
                                Temp.Count = 0;
                                Temp.ERROR = true;
                            }
                        } else {
                            Temp.Count = 0;
                        }
                    }
                    setProductData(24, Temp.AD >> 8);
                    setProductData(25, Temp.AD);
#if Temp_Debug == 1
#if PIR_use == 1  
#if UART_use == 1     
                    UART.Data[0] = (Temp.AD >> 8);
                    UART.Data[1] = Temp.AD;
                    UART.Data[2] = (Temp.DangerValue >> 8);
                    UART.Data[3] = Temp.DangerValue;
                    UART.Data[4] = (Temp.SafeValue >> 8);
                    UART.Data[5] = Temp.SafeValue;
#endif
#else
                    setProductData(2, Temp.AD >> 8);
                    setProductData(3, Temp.AD);
#endif
#endif
                }
                Temp.ADH[0] = 0;
                Temp.ADH[1] = 0;
            }
        }
        //        }
    } else {
        if (myMain.PowerON == true) {
            Temp.Enable = true;
        }
    }
}
//*********************************************************

//void setOverTemp_Exceptions(char command) {
//    char i = command == 1 ? false : true;
//    Temp.ERROR = command;
//    Temp.Safe = i;
//    if (command == 1) {
//        DimmerLights_Exceptions(1);
//#if Switch_Class == 1 && Dimmer_use == 1
//        setLED(2, 1);
//#endif
//    } else if (command == 0) {
//        setBuz(2, BuzzerOnOffTime);
//    }
//    //Lights_ERROR();
//
//#if PIR_use == 1
//    setLED(2, command + 10);
//#else
//    setLED(99, command + 10);
//#endif
//
//    setSw_Enable(i);
//#ifdef RadioFrequency1
//    setRF_Enable(i);
//#endif
//
//}
#endif