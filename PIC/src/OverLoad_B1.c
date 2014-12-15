
// Includes
#include "Select_File.h"

#if OverLoad_use == 1

//******************************************************************************

inline void Load_Initialization() {
    Load.OK = true;
    setLoad_AH_AL_Restore();
}
//******************************************************************************

inline void getLoad_AD(char channel) {
    char i = 0, j = 0, k = 0;

    if (Load.ADtoGO == true) {
        Load.ADRES = getAD(channel, ADCON1_Fixed);

        for (i = 0; i < 4; i++) {
            if (Load.AH[i] < Load.ADRES && j == 0) {
                Load.AH[i] = Load.ADRES;
                j = 1;
            }
        }
        if (j == 0) {
            for (i = 0; i < 4; i++) {
                if (Load.AL[i] > Load.ADRES && k == 0) {
                    Load.AL[i] = Load.ADRES;
                    k = 1;
                }
            }
        }
    }
}
//******************************************************************************

inline void Load_Main() {
    char error = getMain_All_Error_Status(0);
    char Load_Status = 0;

    if (Load.Enable == true) {

        //#if Dimmer_use == 1
        //#if Switch_Class == 1
        //        char sw = 1;
        //#endif
        //#if Switch_Class == 2
        //        char sw = 3;
        //#endif
        //#if Switch_Class == 3
        //        char sw = 3;
        //#endif
        //        adjgo = getAll_DimmerLights_AdjGO(sw);
        //#endif
        //        Load.GO = getMain_LightsStatus() == 1 && error == 0 && adjgo == 0 ? true : false;
        //
        //        if (getMain_LoadOK() == 1 && Load.Run == false) {
        //            Load.Run = true;
        //            Load.OK = false;
        //        }

        if (getMain_LightsStatus() == 0) {
            Load.GO = false;
        } else {
#if Dimmer_use == true

            if (error == 0 && getAll_DimmerLights_AdjSw() == 0) {
                Load.GO = true;

                Load_Status = getDimmer_Load_Status();
                if (getDimmer_LoadGO() == 1) {
                    if (Load.Run == false && Load.OK == false) {
                        Load.Run = true;
                        Load.Count = 0;
                    }
                } else {
                    if (Load.OK == true) {
                        Load.OK = false;
                    }
                }
            } else {
                if (Load.GO == true) {
                    Load.GO = false;
                }
            }
#endif
        }

        //load main
        if (Load.GO == true) {
            Load.LightsON = true;

            if (Load.ADtoGO == true) {
                Load.Time++;
                if (Load.Time >= 5) {//*10ms
                    Load.Time = 0;
                    Load.ADtoGO = false;
                    //get AD value
                    for (int i = 1; i < 4; i++) {
                        Load.ADH += Load.AH[i];
                        Load.ADL += Load.AL[i];
                    }
                    Load.ADH /= 3;
                    Load.ADL /= 3;
                    setLoad_AH_AL_Restore();

                    if (Load.ADH > Load.ADL) {
                        Load.AD = Load.ADH - Load.ADL;
                        Load.ADH = 0;
                        Load.ADL = 0;
                        Load.LightsCount = getMain_Lights_Count();

                        if (Load.Run == true) {
                            if (Load.Count < 2) {
                                Load.Count++;
                                if (Load.Count == 1) {
                                    Load.ErrorCountValue = 2;
                                    Load.JudgeValue = FirstLimitValue;
                                } else if (Load.Count == 2) {
                                    if (Load.LightsCount == 1) {
                                        Load.JudgeValue = SecondLimitValue;
                                    } else {
                                        if (Load_Status == 0) {
                                            Load.JudgeValue = SecondLimitValue * Load.LightsCount;
                                        } else if (Load_Status == 1) {
                                            Load.JudgeValue = SecondLimitValue + Load.TotalLoad;
                                        }
                                    }
                                }
                            }
                        }

                        if (Load.AD >= Load.JudgeValue) {
                            Load.ErrorCount++;
                            if (Load.ErrorCount > Load.ErrorCountValue) {
                                Load.ErrorCount = 0;
                                Load.ERROR = true;
#if Load_Debug == 1
#if PIR_use == 1
#if UART_use == 1  
                                UART.Data[0] = (Load.AD >> 8);
                                UART.Data[1] = Load.AD;
                                UART.Data[2] = (Load.JudgeValue >> 8);
                                UART.Data[3] = Load.JudgeValue;
                                UART.Data[4] = Load.LightsCount;
                                UART.Data[5] = 0;
                                UART.Data[6] = 0;
                                UART.Data[7] = 0;
#endif
#else
                                setProductData(4, (Load.AD >> 8));
                                setProductData(5, Load.AD);
                                setProductData(6, (Load.JudgeValue >> 8));
                                setProductData(7, Load.JudgeValue);
                                setProductData(8, Load.LightsCount);
#endif
#endif
                            }
                        } else {
                            Load.ErrorCount = 0;
                            if (Load.Run == true) {
                                if (Load.OK == false) {
                                    Load.SafeCount++;
                                    if (Load.SafeCount >= SafeCountValue) {
                                        Load.SafeCount = 0;
                                        Load.OK = true;
                                        Load.Run = false;
                                        Load.TotalLoad = Load.AD;
                                        Load.ErrorCountValue = 3;

#if Load_Debug == 1
#if PIR_use == 1

#if UART_use == 1
                                        UART.Data[0] = (Load.AD >> 8);
                                        UART.Data[1] = Load.AD;
                                        UART.Data[2] = (Load.JudgeValue >> 8);
                                        UART.Data[3] = Load.JudgeValue;
                                        UART.Data[4] = Load.LightsCount;
                                        UART.Data[5] = 0;
                                        UART.Data[6] = 0;
                                        UART.Data[7] = 0;
#endif
#else
                                        setProductData(4, (Load.AD >> 8));
                                        setProductData(5, Load.AD);
                                        setProductData(6, (Load.JudgeValue >> 8));
                                        setProductData(7, Load.JudgeValue);
                                        setProductData(8, Load.LightsCount);

#endif
#endif
                                    }
                                }
                            }
                        }
                    }
                }
            } else {
                Load.ADtoGO = true;
            }
        } else {
            if (Load.LightsON == true) {
                Load.LightsON = false;

                Load.ADtoGO = false;
                Load.Time = 0;
                setLoad_AH_AL_Restore();
                Load.LightsCount = 0;

                Load.SafeCount = 0;

                Load.ADH = 0;
                Load.ADL = 0;

                Load.AD = 0;
                Load.JudgeValue = 0;
                Load.ErrorCount = 0;


                Load.Run = false;
                Load.OK = false;
#if Load_Debug == 1
#if PIR_use == 1
#if UART_use == 1
                UART.Data[0] = (Load.AD >> 8);
                UART.Data[1] = Load.AD;
                UART.Data[2] = (Load.JudgeValue >> 8);
                UART.Data[3] = Load.JudgeValue;
                UART.Data[4] = Load.LightsCount;
                UART.Data[5] = 0;
                UART.Data[6] = 0;
                UART.Data[7] = 0;
#endif
#else
                setProductData(4, (Load.AD >> 8));
                setProductData(5, Load.AD);
                setProductData(6, (Load.JudgeValue >> 8));
                setProductData(7, Load.JudgeValue);
                setProductData(8, Load.LightsCount);
#endif
#endif
            }
            if (Load.ERROR == true) {
                Load.ErrorTime++;
                if (Load.ErrorTime >= 1000) {//*10ms
                    Load.ErrorTime = 0;
                    Load.ERROR = false;
                }
            }
        }
    } else {
        if (myMain.PowerON == true) {
            Load.Enable = true;
        }
    }
}
//******************************************************************************

char getLoad_OK() {
    char ok = Load.OK == true ? 1 : 0;
    return ok;
}
//******************************************************************************

void setLoad_OK() {
    Load.OK = false;
    Load.SafeCount = 0;
}

//******************************************************************************

char getLoad_ERROR() {
    char result = Load.ERROR;

    return result;
}
//******************************************************************************

void setLoad_AH_AL_Restore() {
    char i;
    for (i = 0; i < 5; i++) {
        Load.AH[i] = ADH_Restore;
        Load.AL[i] = ADL_Restore;
    }
}

#endif

//end file
//******************************************************************************