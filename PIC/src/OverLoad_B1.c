
// Includes
#include "Select_File.h"

#if OverLoad_use == 1

//******************************************************************************

inline void Load_Initialization() {
    //    Load.OK = true;
    setLoad_AH_AL_Restore();
}
//******************************************************************************

inline void getLoad_AD(char channel) {
    char i = 0, j = 0, k = 0;
    ADtype ADRES = 0;
    if (Load.ADtoGO == true) {
        //        Load.ADRES = getAD(channel, ADCON1_Fixed);
        ADRES = getAD(channel, ADCON1_Fixed);
        for (i = 0; i < 4; i++) {
            if (Load.AH[i] < ADRES && j == 0) {
                Load.AH[i] = ADRES;
                j = 1;
            }
        }
        if (j == 0) {
            for (i = 0; i < 4; i++) {
                if (Load.AL[i] > ADRES && k == 0) {
                    Load.AL[i] = ADRES;
                    k = 1;
                }
            }
        }
    }
}
//******************************************************************************

inline void Load_Main() {
    char error = getMain_All_Error_Status(0);
    char Load_Status = 0, ErrorCountValue = 0, LightsCount=0;
    ADtype JudgeValue = 0;
    if (Load.Enable == true) {

        if (getMain_All_LightsStatus() == 0) {
            Load.GO = false;
        } else {
#if Dimmer_use == true

            if (error == 0 && getAll_DimmerIntr_Dimming_Sw_RF() == 0) {
                Load.GO = true;

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
#if LightsControl_use == 1
            if (error == 0) {
                Load.GO = true;

                if (getLight_LoadGO() == 1) {
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
                if (Load.Time >= (40 / Main_Time)) {
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

                    if (Load.ADH >= Load.ADL) {
                        Load.AD = Load.ADH - Load.ADL;
                        Load.ADH = 0;
                        Load.ADL = 0;

                        if (Load.Run == true) {
                            if (Load.Count < 2) {
                                Load.Count++;
#if Dimmer_use == 1
                                Load_Status = getDimmer_Load_Status();
#endif
#if LightsControl_use == 1
                                Load_Status = getLight_Load_Status();
#endif
                                LightsCount = getMain_Lights_Count();

                                if (Load.Count == 1) {
                                    //                                    Load.ErrorCountValue = 2;
                                    JudgeValue = FirstLimitValue;
                                } else if (Load.Count == 2) {
                                    if (LightsCount == 1) {
                                        JudgeValue = SecondLimitValue;
                                    } else {
                                        if (Load_Status == 0) {
                                            JudgeValue = SecondLimitValue * LightsCount;
                                        } else if (Load_Status == 1) {
                                            JudgeValue = SecondLimitValue + Load.TotalLoad;
                                        }
                                    }
                                }
                            }
                        }

                        if (Load.AD >= JudgeValue) {
                            ErrorCountValue = LightsCount == 1 ? 2 : 3;
                            Load.ErrorCount++;
                            if (Load.ErrorCount > ErrorCountValue) {
                                Load.ErrorCount = 0;
                                Load.ERROR = true;
#if Load_Debug == 1
#if PIR_use == 1
#if UART_use == 1  
                                UART.Data[0] = (Load.AD >> 8);
                                UART.Data[1] = Load.AD;
                                UART.Data[2] = (JudgeValue >> 8);
                                UART.Data[3] = JudgeValue;
                                UART.Data[4] = LightsCount;
                                UART.Data[5] = 0;
                                UART.Data[6] = 0;
                                UART.Data[7] = 0;
#endif
#else
                                setProductData(4, (Load.AD >> 8));
                                setProductData(5, Load.AD);
                                setProductData(6, (JudgeValue >> 8));
                                setProductData(7, JudgeValue);
                                setProductData(8, LightsCount);
                                setProductData(10, getDimmer_LoadGO());
#endif
#endif
                            }
                        } else {
                            Load.ErrorCount = 0;
                            if (Load.Run == true) {
                                Load.SafeCount++;
                                if (Load.SafeCount >= SafeCountValue) {
                                    Load.SafeCount = 0;
                                    Load.OK = true;
                                    Load.Run = false;
                                    Load.Count = 0;
                                    Load.TotalLoad = Load.AD;
                                    //                                    Load.ErrorCountValue = 3;
                                    //                                    ErrLED = 0;
                                    //                                    ErrLED = ErrLED == true ? false : true;                           
                                }
                            }
#if Load_Debug == 1
#if PIR_use == 1

#if UART_use == 1
                            UART.Data[0] = (Load.AD >> 8);
                            UART.Data[1] = Load.AD;
                            UART.Data[2] = (JudgeValue >> 8);
                            UART.Data[3] = JudgeValue;
                            UART.Data[4] = LightsCount;
                            UART.Data[5] = 0;
                            UART.Data[6] = 0;
                            UART.Data[7] = 0;
#endif
#else
                            setProductData(4, (Load.AD >> 8));
                            setProductData(5, Load.AD);
                            setProductData(6, (JudgeValue >> 8));
                            setProductData(7, JudgeValue);
                            setProductData(8, LightsCount);
                            setProductData(10, getDimmer_LoadGO());
#endif
#endif
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

                Load.ErrorCount = 0;
                Load.SafeCount = 0;

                Load.ADH = 0;
                Load.ADL = 0;

                //                Load.AD = 0;
                //                Load.JudgeValue = 0;
                //                LightsCount = 0;

                Load.Run = false;
                Load.Count = 0;
                Load.OK = false;
#if Load_Debug == 1
#if PIR_use == 1
#if UART_use == 1
                UART.Data[0] = (Load.AD >> 8);
                UART.Data[1] = Load.AD;
                UART.Data[2] = (JudgeValue >> 8);
                UART.Data[3] = JudgeValue;
                UART.Data[4] = LightsCount;
                UART.Data[5] = 0;
                UART.Data[6] = 0;
                UART.Data[7] = 0;
#endif
#else
                setProductData(4, (Load.AD >> 8));
                setProductData(5, Load.AD);
                setProductData(6, (JudgeValue >> 8));
                setProductData(7, JudgeValue);
                setProductData(8, LightsCount);
                setProductData(10, getDimmer_LoadGO());
#endif
#endif
            }
            if (Load.ERROR == true) {
                Load.ErrorTime++;
                if (Load.ErrorTime >= (10000 / Main_Time)) {
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