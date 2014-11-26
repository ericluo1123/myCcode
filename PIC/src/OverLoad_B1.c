
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
    char i = 0, j = 0, error = getMain_All_Error_Status(0), adjgo = 0;

    if (Load.Enable == true) {

#if Dimmer_use == 1
        adjgo = getAll_DimmerLights_AdjGO();
#endif
        Load.GO = getMain_LightsStatus() == 1 && error == 0 && adjgo == 0 ? true : false;
        if (getMain_LoadOK() == 1 && Load.Run == false) {
            Load.Run = true;
            Load.OK = false;
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
                    for (i = 0; i < 4; i++) {
                        Load.ADH += Load.AH[i];
                        Load.ADL += Load.AL[i];
                    }
                    Load.ADH /= 4;
                    Load.ADL /= 4;
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
                                    Load.JudgeValue = FirstLimitValue;
                                } else if (Load.Count == 2) {
                                    if (Load.LightsCount == 1) {
                                        Load.JudgeValue = SecondLimitValue;
                                    } else {
                                        Load.JudgeValue = SecondLimitValue + Load.TotalLoad;
                                    }
                                }
                            }
                        }

                        if (Load.AD >= Load.JudgeValue) {
                            Load.ErrorCount++;
                            if (Load.ErrorCount > 2) {
                                Load.ErrorCount = 0;
                                Load.ERROR = true;
                                //#if PIR_use == true
                                //                                setLED(3, 111);
                                //#else
                                //                                setLED(1, 11);
                                //#endif
#if Load_Debug == 1
                                setProductData(4, (Load.AD >> 8));
                                setProductData(5, Load.AD);
                                setProductData(6, (Load.JudgeValue >> 8));
                                setProductData(7, Load.JudgeValue);
                                setProductData(8, Load.LightsCount);
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
                                        Load.Count = 0;
                                        Load.TotalLoad = Load.AD;

#if Load_Debug == 1
                                        setProductData(4, (Load.AD >> 8));
                                        setProductData(5, Load.AD);
                                        setProductData(6, (Load.JudgeValue >> 8));
                                        setProductData(7, Load.JudgeValue);
                                        setProductData(8, Load.LightsCount);

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
            if (Load.LightsON == true && error != 3) {
                Load.LightsON = false;

                Load.Time = 0;
                Load.ADtoGO = false;
                setLoad_AH_AL_Restore();
                Load.Count = 0;
                Load.ErrorCount = 0;
                Load.SafeCount = 0;

                Load.ADH = 0;
                Load.ADL = 0;
                Load.AD = 0;
                Load.JudgeValue = 0;
                Load.LightsCount = 0;
                Load.Run = false;
                Load.OK = true;
#if Load_Debug == 1
                setProductData(4, (Load.AD >> 8));
                setProductData(5, Load.AD);
                setProductData(6, (Load.JudgeValue >> 8));
                setProductData(7, Load.JudgeValue);
                setProductData(8, Load.LightsCount);
#endif
            }
            if (Load.ERROR == true) {
                Load.ErrorTime++;
                if (Load.ErrorTime >= 1000) {//*10ms
                    Load.ErrorTime = 0;
                    //                    setLoad_Exceptions(0);
                    //#if PIR_use == true
                    //                    setLED(3, 110);
                    //#else
                    //                    setLED(1, 10);
                    //#endif
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