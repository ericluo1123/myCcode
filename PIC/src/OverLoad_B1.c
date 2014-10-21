
// Includes
#include "Select_File.h"

#if OverLoad_use == 1

//*********************************************************

inline void Load_Initialization() {
    Load1.Safe = true;
    setLoad_AH_AL_Restore();
}
//*********************************************************

inline void getLoad_AD(char channel) {
    char i = 0, j = 0;

    if (Load1.ADtoGO == true) {
        Load1.ADRES = getAD(channel, FVRCON_1V);
        for (i = 0; i < 5; i++) {
            if (Load1.AH[i] < Load1.ADRES) {
                Load1.AH[i] = Load1.ADRES;
                j = 1;
                break;
            }
        }
        if (j == 0) {
            for (i = 0; i < 5; i++) {
                if (Load1.AL[i] > Load1.ADRES) {
                    Load1.AL[i] = Load1.ADRES;
                    break;
                }
            }
        }
    }
}
//*********************************************************

inline void Load_Main() {
    char i = 0;
    if (Load1.ERROR == true) {
        Load1.ErrorTime++;
        if (Load1.ErrorTime >= 1000)//*10ms
        {
            Load1.ErrorTime = 0;
            setLoad_Exceptions(0);
        }
    } else {
        if (Load1.ADtoGO == true) {
            Load1.Time++;
            if (Load1.Time >= 5)//*10ms
            {
                Load1.Time = 0;
                Load1.ADtoGO = false;
                Load1.LightsCount = Load1.Lights1Status + Load1.Lights2Status + Load1.Lights3Status;
                for (i = 1; i < 4; i++) {
                    Load1.ADH += Load1.AH[i];
                    Load1.ADL += Load1.AL[i];
                }
                Load1.ADH /= 3;
                Load1.ADL /= 3;
                if (Load1.ADH > Load1.ADL) {
                    Load1.AD = (Load1.ADH - Load1.ADL);

                    if (Load1.Count < 2) {
                        Load1.Count++;
                        if (Load1.Count == 1) {
                            Load1.JudgeValue = 500;
                        } else if (Load1.Count == 2) {
                            if (Load1.LightsCount == 1) {
                                Load1.JudgeValue = LoadLimitValue;
                            } else {
                                Load1.JudgeValue = (LoadLimitValue + Load1.TotalLoad) - 0x08;
                            }
                        }
                    }

                    if (Load1.AD >= Load1.JudgeValue) {
                        Load1.ErrorCount++;
                        if (Load1.ErrorCount > 2) {
                            Load1.ErrorCount = 0;
                            setLoad_Exceptions(1);
#if Load_Debug == 1
                            setProductData(4, (Load1.AD >> 8));
                            setProductData(5, Load1.AD);
                            setProductData(6, (Load1.JudgeValue >> 8));
                            setProductData(7, Load1.JudgeValue);
                            setProductData(8, Load1.LightsCount);
#endif
                        }
                    } else {
                        Load1.ErrorCount = 0;
                        if (Load1.SafeCount < SafeCountValue) {
                            Load1.SafeCount++;
                        }
                        if (Load1.SafeCount >= SafeCountValue) {
                            Load1.Safe = 1;

#ifdef use_1KEY			
#ifdef Dimmer_use == 1
                            setDimmerLights_Clear(1, 1);
#endif

#ifdef LightsControl_use == 1
                            setLights_Clear(1, 1);
#endif
#endif

#ifdef use_2KEY
#ifdef Dimmer_use == 1
                            setDimmerLights_Clear(2, 1);
#endif

#ifdef LightsControl_use == 1
                            setLights_Clear(2, 1);
#endif
#endif

#ifdef use_3KEY		
#ifdef Dimmer_use == 1
                            setDimmerLights_Clear(3, 1);
#endif	

#ifdef LightsControl_use == 1
                            setLights_Clear(3, 1);
#endif
#endif	

                            if (Load1.StatusOn == true) {
                                Load1.StatusOn = 0;
                                Load1.TotalLoad = Load1.AD;
                                //Load1.JudgeValue=LoadLimitValue*Load1.LightsCount;
                            }

                            if (Load1.StatusOff == true) {
                                Load1.StatusOff = 0;
                                Load1.TotalLoad = Load1.AD;
                                Load1.JudgeValue = LoadLimitValue * Load1.LightsCount;
                            }
                        }
                    }
                }
                setLoad_AH_AL_Restore();
#if Load_Debug == 1
                setProductData(4, (Load1.AD >> 8));
                setProductData(5, Load1.AD);
                setProductData(6, (Load1.JudgeValue >> 8));
                setProductData(7, Load1.JudgeValue);
                setProductData(8, Load1.LightsCount);
                setProductData(10, Load1.TotalLoad);
                setProductData(18, Load1.ErrorStatus);
                setProductData(19, Load1.Count);
#endif

            }
        } else {
            if (Load1.GO == true) {
                if (Load1.LightsON == false) {
                    Load1.LightsON = true;
                    Load1.Safe = false;
                }
                if (getTemp_Safe() == 1 && getPF_Safe() == 1) {
                    Load1.ADtoGO = true;
                }
            } else {
                if (Load1.LightsON == true) {
                    Load1.LightsON = false;
                    Load1.Safe = true;
                    Load1.ErrorCount = 0;
                    Load1.Count = 0;
                    Load1.TotalLoad = 0;
                    Load1.NumberCount = 0;
                    Load1.StatusOn = 0;
                    Load1.StatusOff = 0;
                    Load1.AD = 0;
                    setLoad_AH_AL_Restore();

#ifdef use_1KEY			
#ifdef Dimmer_use == 1
                    setDimmerLights_Clear(1, 1);
#endif

#ifdef LightsControl_use == 1
                    setLights_Clear(1, 1);
#endif
#endif

#ifdef use_2KEY	
#ifdef Dimmer_use == 1
                    setDimmerLights_Clear(2, 1);
#endif

#ifdef LightsControl_use == 1
                    setLights_Clear(2, 1);
#endif
#endif

#ifdef use_3KEY		
#ifdef Dimmer_use == 1
                    setDimmerLights_Clear(3, 1);
#endif	

#ifdef LightsControl_use == 1
                    setLights_Clear(3, 1);
#endif

#endif	
#if Load_Debug == 1
                    setProductData(4, (Load1.AD >> 8));
                    setProductData(5, Load1.AD);
                    setProductData(6, (Load1.JudgeValue >> 8));
                    setProductData(7, Load1.JudgeValue);
                    setProductData(8, Load1.Count);
                    //setProductData(4,(Load1.ADH >> 8));
                    //setProductData(5,Load1.ADH);
                    //setProductData(6,(Load1.ADL >> 8));
                    //setProductData(7,Load1.ADL);
                    //                    setProductData(8, Load1.NumberCount);
                    setProductData(10, Load1.TotalLoad);

                    setProductData(18, Load1.ErrorStatus);

#endif
                }
            }
        }
    }
}
//*********************************************************

void setLoad_Exceptions(char command) {
    char i = command == 1 ? 0 : 1;
    Load1.ERROR = command;
    Load1.Safe = i;
    Load1.ErrorStatus = command;

    if (command == 1) {
        DimmerLights_Exceptions(2);
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
//*********************************************************

void setLoad_Count(char command) {
    Load1.Count = command;
    Load1.SafeCount = command;
}
//*********************************************************

void setLoad_Enable(char command) {
    Load1.Enable = command;
    Load1.GO = false;
}

void setLoad_GO(char command) {
    Load1.GO = command;
}

void setLoad_StatusOn(char lights, char command) {
    Load1.GO = true;
    Load1.StatusOn = command;

    if (lights == 1) {
        Load1.Lights1Status = 1;
    }
    if (lights == 2) {
        Load1.Lights2Status = 1;
    }
    if (lights == 3) {
        Load1.Lights3Status = 1;
    }
}

void setLoad_StatusOff(char lights, char command) {
    Load1.StatusOff = command;
    Load1.SafeCount -= 2;
    if (lights == 1) {
        Load1.Lights1Status = 0;
    }
    if (lights == 2) {
        Load1.Lights2Status = 0;
    }
    if (lights == 3) {
        Load1.Lights3Status = 0;
    }
}

char getLoad_Safe() {
    char result = Load1.Safe;
    return result;
}

char getLoad_ERROR() {
    char result = Load1.ERROR;
    return result;
}
//*********************************************************

void setLoad_AH_AL_Restore() {
    char i;
    for (i = 0; i < 5; i++) {
        Load1.AH[i] = ADH_Restore;
        Load1.AL[i] = ADL_Restore;
    }
}

#endif