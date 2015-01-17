
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
    ADtype ADRES = 0;
    //#if SYSC_use == 1
    //    if (SYSC1 == true) {
    if (Temp.ADtoGO == true) {
        //        Temp.ADRES = getAD(channel, ADCON1_VDD);
        ADRES = getAD(channel, ADCON1_VDD);
        //        if (ADRES > 0) {
        //            if (Temp.ADH[0] < ADRES) {
        //                Temp.ADH[0] = ADRES;
        //            } else if (Temp.ADH[1] < ADRES) {
        //                Temp.ADH[1] = ADRES;
        //            }
        //        }
        if (ADRES > 0) {
            if (Temp.ADV < ADRES) {
                Temp.ADV = ADRES;
            }
        }
    }
    //    }

    //#else
    //    if (Temp.ADtoGO == true) {
    //        Temp.GO = true;
    ////            Temp.ADRES = getAD(channel, ADCON1_VDD);
    ADRES = getAD(channel, ADCON1_VDD);
    //        if (Temp.ADH[0] < ADRES) {
    //            Temp.ADH[0] = ADRES;
    //        } else if (Temp.ADH[1] < ADRES) {
    //            Temp.ADH[1] = ADRES;
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
    ADtype SafeValue = 0, DangerValue = 0, AD;
    char TempGO = getMain_All_LightsStatus();

    if (Temp.Enable == true) {

        //        if (error == 1 || error == 3) {
        //            Temp.Time = 0;
        //            Temp.ADtoGO = false;
        //            Temp.ADH[0] = 0;
        //            Temp.ADH[1] = 0;
        //        } else {
        if (Temp.ADtoGO == false) {
            if ((TempGO == 1 && Temp.ERROR == false) || Temp.ERROR == true) {
                Temp.Time++;
                if (Temp.Time >= (5000 / Main_Time)) {//*10ms
                    Temp.Time = 0;
                    Temp.ADtoGO = true;
                }
            } else {
                Temp.Time = 0;
            }
        } else {
            Temp.Time++;
            if (Temp.Time >= (100 / Main_Time)) {
                Temp.Time = 0;

                //                if (Temp.ADH[0] > 0 && Temp.ADH[1] > 0) {
                //                    Temp.ADtoGO = false;
                //                    AD = (Temp.ADH[0] + Temp.ADH[1]) / 2;
                if (Temp.ADV > 0) {
                    Temp.ADtoGO = false;
                    AD = Temp.ADV;
#if PIR_use == 1 && Dimmer_use == 0
                    //                        if (getMain_All_LightsStatus() == 1) {
                    //                            SafeValue = TempSafeValueH;
                    //                            DangerValue = TempDangerValueH;
                    //                        } else {
                    //                            SafeValue = TempSafeValueL;
                    //                            DangerValue = TempDangerValueL;
                    //                        }
                    SafeValue = TempSafeValue;
                    DangerValue = TempDangerValue;
#elif PIR_use == 1 && Dimmer_use == 1
                    SafeValue = TempSafeValue;
                    DangerValue = TempDangerValue;
#elif PIR_use == 0 && Dimmer_use == 1
                    SafeValue = TempSafeValue;
                    DangerValue = TempDangerValue;
#else
                    SafeValue = 0;
                    DangerValue = 0;
#endif

                    if (Temp.ERROR == true) {
                        if (AD >= SafeValue) {
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
                        if (AD <= DangerValue) {
                            Temp.Count++;
                            if (Temp.Count >= TempCountValue) {
                                Temp.Count = 0;
                                Temp.ERROR = true;
                            }
                        } else {
                            Temp.Count = 0;
                        }
                    }
                    setProductData(24, AD >> 8);
                    setProductData(25, AD);
#if Temp_Debug == 1
#if PIR_use == 1  
#if UART_use == 1     
                    UART.Data[0] = (AD >> 8);
                    UART.Data[1] = AD;
                    UART.Data[2] = (Temp.DangerValue >> 8);
                    UART.Data[3] = Temp.DangerValue;
                    UART.Data[4] = (Temp.SafeValue >> 8);
                    UART.Data[5] = Temp.SafeValue;
#endif
#else
                    setProductData(2, AD >> 8);
                    setProductData(3, AD);
#endif
#endif
                }
                Temp.ADH[0] = 0;
                Temp.ADH[1] = 0;
                Temp.ADV = 0;
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