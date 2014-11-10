
// Includes
#include "Select_File.h"

#if OverLoad_use == 1

//*********************************************************

inline void Load_Initialization() {
    Load.OK = true;
    setLoad_AH_AL_Restore();
}
//*********************************************************

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
//*********************************************************

inline void Load_Main() {
    char i = 0, j = 0, error = 0;
    if (Load.Enable == true) {
        Load.GO = false;

        Load.GO = getMain_LightsStatus() == 1 && getMain_All_Error_Status(0) == 0 ? true : false;

        if (Load.OK == true) {
            if (getMain_LoadOK() == 1) {
                Load.OK = false;
                Load.Count = 0;
            }
        }
        //load main
        if (Load.GO == true) {
            Load.LightsON = true;

            if (Load.ADtoGO == true) {
                Load.Time++;
                if (Load.Time >= 5) {//*10ms
                    Load.Time = 0;
                    Load.ADtoGO = false;
                    Load.LightsCount = getMain_Lights_Count();

                    //get AD value
                    for (i = 0; i < 4; i++) {
                        Load.ADH += Load.AH[i];
                        Load.ADL += Load.AL[i];
                    }
                    setLoad_AH_AL_Restore();
                    Load.ADH /= 4;
                    Load.ADL /= 4;
                    ErrLED = 0;
                    if (Load.ADH > Load.ADL) {
                        Load.AD = (Load.ADH - Load.ADL);

                        Load.ADH = 0;
                        Load.ADL = 0;
                        if (Load.Count < 2) {
                            Load.Count++;
                            if (Load.Count == 1) {
                                Load.JudgeValue = FirstLimitValue;
                            } else if (Load.Count == 2) {
                                if (Load.LightsCount == 1) {
                                    Load.JudgeValue = SecondLimitValue;
                                } else {
                                    Load.JudgeValue = (SecondLimitValue + Load.TotalLoad) - 0x08;
                                }
                            }
                        }

                        if (Load.AD >= Load.JudgeValue) {
                            Load.ErrorCount++;
                            if (Load.ErrorCount > 2) {
                                Load.ErrorCount = 0;
                                //                                    setLoad_Exceptions(1);
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
                            if (Load.OK == false) {
                                Load.SafeCount++;
                                if (Load.SafeCount >= SafeCountValue) {
                                    Load.SafeCount = 0;
                                    Load.OK = true;
                                    Load.TotalLoad = Load.AD;
                                    if (Load.LightsCount == 1) {
                                        Load.JudgeValue = SecondLimitValue;
                                    } else {
                                        Load.JudgeValue = (SecondLimitValue + Load.TotalLoad) - 0x08;
                                    }
#if Load_Debug == 1
                                    Load.AD = 0;
                                    Load.JudgeValue = 0;
                                    Load.LightsCount = 0;
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
            } else {
                Load.ADtoGO = true;
            }
        } else {
            Load.OK = true;
            if (Load.LightsON == true) {
                Load.LightsON = false;

                Load.Time = 0;
                Load.ADtoGO = false;
                setLoad_AH_AL_Restore();
                Load.Count = 0;
                Load.ErrorCount = 0;
                Load.SafeCount = 0;

                Load.ADH = 0;
                Load.ADL = 0;

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
                if (Load.ErrorTime >= 1000)//*10ms
                {
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
//*****************************************************************************
//
//void setLoad_Exceptions(char command) {
//    char i = command == 1 ? 0 : 1;
//    Load.ERROR = command;
//    Load.Safe = i;
//    Load.ErrorStatus = command;
//
//    if (command == 1) {
//
//        DimmerLights_Exceptions(2);
//#if Switch_Class == 1 && Dimmer_use == 1
//        setLED(2, 1);
//#endif
//    }
//    setLED(99, command + 10);
//
//    setSw_Enable(i);
//#ifdef RadioFrequency1
//    setRF_Enable(i);
//#endif
//}
//*********************************************************

//void setLoad_Count(char command) {
//
//    Load.Count = command;
//    Load.SafeCount = command;
//}
//*********************************************************

//void setLoad_GO(char command) {
//
//    Load.GO = command;
//}

char getLoad_OK() {
    char ok = Load.OK == true ? 1 : 0;
    return ok;
}

void setLoad_OK() {

    Load.OK = false;
    Load.SafeCount = 0;
}
//
//void setLoad_StatusOn(char lights, char command) {
//    Load.GO = true;
//    Load.StatusOn = command;
//
//#ifdef use_1KEY
//    if (lights == 1) {
//        Load.Lights1Status = 1;
//    }
//#endif
//#ifdef use_2KEY
//    else if (lights == 2) {
//        Load.Lights2Status = 1;
//    }
//#endif
//#ifdef use_3KEY
//    else if (lights == 3) {
//        Load.Lights3Status = 1;
//    }
//#endif
//}
//
//void setLoad_StatusOff(char lights, char command) {
//    Load.StatusOff = command;
//    Load.SafeCount -= 2;
//
//#ifdef use_1KEY
//    if (lights == 1) {
//        Load.Lights1Status = 0;
//    }
//#endif
//#ifdef use_2KEY
//    else if (lights == 2) {
//        Load.Lights2Status = 0;
//    }
//#endif
//#ifdef use_3KEY
//    else if (lights == 3) {
//        Load.Lights3Status = 0;
//    }
//#endif
//}

//char getLoad_Safe() {
//    char result = Load.Safe;
//
//    return result;
//}

char getLoad_ERROR() {
    char result = Load.ERROR;

    return result;
}
//*********************************************************

void setLoad_AH_AL_Restore() {
    char i;
    for (i = 0; i < 5; i++) {
        Load.AH[i] = ADH_Restore;
        Load.AL[i] = ADL_Restore;
    }
}

#endif

//    if (Load.ERROR == true) {
//        Load.ErrorTime++;
//        if (Load.ErrorTime >= 1000)//*10ms
//        {
//            Load.ErrorTime = 0;
//            setLoad_Exceptions(0);
//        }
//    } else {
//        if (Load.ADtoGO == true) {
//            Load.Time++;
//            if (Load.Time >= 5)//*10ms
//            {
//                Load.Time = 0;
//                Load.ADtoGO = false;
//                Load.LightsCount = Load.Lights1Status + Load.Lights2Status + Load.Lights3Status;
//                for (i = 1; i < 4; i++) {
//                    Load.ADH += Load.AH[i];
//                    Load.ADL += Load.AL[i];
//                }
//                Load.ADH /= 3;
//                Load.ADL /= 3;
//                if (Load.ADH > Load.ADL) {
//                    Load.AD = (Load.ADH - Load.ADL);
//
//                    if (Load.Count < 2) {
//                        Load.Count++;
//                        if (Load.Count == 1) {
//                            Load.JudgeValue = 500;
//                        } else if (Load.Count == 2) {
//                            if (Load.LightsCount == 1) {
//                                Load.JudgeValue = LoadLimitValue;
//                            } else {
//                                Load.JudgeValue = (LoadLimitValue + Load.TotalLoad) - 0x08;
//                            }
//                        }
//                    }
//
//                    if (Load.AD >= Load.JudgeValue) {
//                        Load.ErrorCount++;
//                        if (Load.ErrorCount > 2) {
//                            Load.ErrorCount = 0;
//                            setLoad_Exceptions(1);
//#if Load_Debug == 1
//                            setProductData(4, (Load.AD >> 8));
//                            setProductData(5, Load.AD);
//                            setProductData(6, (Load.JudgeValue >> 8));
//                            setProductData(7, Load.JudgeValue);
//                            setProductData(8, Load.LightsCount);
//#endif
//                        }
//                    } else {
//                        //                        ErrLED = ErrLED == true ? false : true;
//                        Load.ErrorCount = 0;
//                        if (Load.SafeCount < SafeCountValue) {
//                            Load.SafeCount++;
//                        }
//                        if (Load.SafeCount >= SafeCountValue) {
//                            Load.Safe = 1;
//
//#ifdef use_1KEY
//#if Dimmer_use == 1
//                            setDimmerLights_Clear(1, 1);
//#endif
//
//#if LightsControl_use == 1
//                            setLights_Clear(1, 1);
//#endif
//#endif
//
//#ifdef use_2KEY
//#if Dimmer_use == 1
//                            setDimmerLights_Clear(2, 1);
//#endif
//
//#if LightsControl_use == 1
//                            setLights_Clear(2, 1);
//#endif
//#endif
//
//#ifdef use_3KEY
//#if Dimmer_use == 1
//                            setDimmerLights_Clear(3, 1);
//#endif
//
//#if LightsControl_use == 1
//                            setLights_Clear(3, 1);
//#endif
//#endif
//
//                            if (Load.StatusOn == true) {
//                                Load.StatusOn = 0;
//                                Load.TotalLoad = Load.AD;
//                                //Load.JudgeValue=LoadLimitValue*Load.LightsCount;
//                            }
//
//                            if (Load.StatusOff == true) {
//                                Load.StatusOff = 0;
//                                Load.TotalLoad = Load.AD;
//                                Load.JudgeValue = LoadLimitValue * Load.LightsCount;
//                            }
//                        }
//                    }
//                }
//                setLoad_AH_AL_Restore();
//#if Load_Debug == 1
//                setProductData(4, (Load.AD >> 8));
//                setProductData(5, Load.AD);
//                setProductData(6, (Load.JudgeValue >> 8));
//                setProductData(7, Load.JudgeValue);
//                setProductData(8, Load.LightsCount);
//                setProductData(10, Load.TotalLoad);
//                setProductData(18, Load.ErrorStatus);
//                setProductData(19, Load.Count);
//#endif
//
//            }
//        } else {
//            if (Load.GO == true) {
//                if (Load.LightsON == false) {
//                    Load.LightsON = true;
//                    Load.Safe = false;
//                }
//                if (getTemp_Safe() == 1 && getPF_Safe() == 1) {
//                    Load.ADtoGO = true;
//                }
//            } else {
//                if (Load.LightsON == true) {
//                    Load.LightsON = false;
//                    Load.Safe = true;
//                    Load.ErrorCount = 0;
//                    Load.Count = 0;
//                    Load.TotalLoad = 0;
//                    Load.StatusOn = 0;
//                    Load.StatusOff = 0;
//                    Load.AD = 0;
//                    setLoad_AH_AL_Restore();
//
//#ifdef use_1KEY
//#if Dimmer_use == 1
//                    setDimmerLights_Clear(1, 1);
//#endif
//
//#if LightsControl_use == 1
//                    setLights_Clear(1, 1);
//#endif
//#endif
//
//#ifdef use_2KEY
//#ifdef Dimmer_use == 1
//                    setDimmerLights_Clear(2, 1);
//#endif
//
//#ifdef LightsControl_use == 1
//                    setLights_Clear(2, 1);
//#endif
//#endif
//
//#ifdef use_3KEY
//#ifdef Dimmer_use == 1
//                    setDimmerLights_Clear(3, 1);
//#endif
//
//#ifdef LightsControl_use == 1
//                    setLights_Clear(3, 1);
//#endif
//
//#endif
//#if Load_Debug == 1
//                    setProductData(4, (Load.AD >> 8));
//                    setProductData(5, Load.AD);
//                    setProductData(6, (Load.JudgeValue >> 8));
//                    setProductData(7, Load.JudgeValue);
//                    setProductData(8, Load.Count);
//                    //setProductData(4,(Load.ADH >> 8));
//                    //setProductData(5,Load.ADH);
//                    //setProductData(6,(Load.ADL >> 8));
//                    //setProductData(7,Load.ADL);
//                    setProductData(10, Load.TotalLoad);
//
//                    setProductData(18, Load.ErrorStatus);
//
//#endif
//                }
//            }
//        }
//    }