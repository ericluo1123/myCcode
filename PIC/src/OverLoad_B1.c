
// Includes
#include "../1.Switch_1Key_Dimmer.X/Select_File.h"

#if OverLoad_use == 1

//*********************************************************

void Load_Initialization() {
    Load = &Load1;
    Load->Safe = 1;
    setLoad_AH_AL_Restore();
}
//*********************************************************

void getLoad_AD(char channel) {
    char i = 0, j = 0;

    if (Load->ADtoGO) {
        Load->ADRES = getAD(channel, FVRCON_1V);
        for (i = 0; i < 5; i++) {
            if (Load->AH[i] < Load->ADRES) {
                Load->AH[i] = Load->ADRES;
                j = 1;
                break;
            }
        }
        if (!j) {
            for (i = 0; i < 5; i++) {
                if (Load->AL[i] > Load->ADRES) {
                    Load->AL[i] = Load->ADRES;
                    break;
                }
            }
        }
    }
}
//*********************************************************

void Load_Main() {
    char i;
    if (Load->ERROR) {
        Load->ErrorTime++;
        if (Load->ErrorTime >= 1000)//*10ms
        {
            Load->ErrorTime = 0;
            setLoad_Exceptions(0);
        }
    } else {
        if (Load->ADtoGO) {
            Load->Time++;
            if (Load->Time >= 5)//*10ms
            {
                Load->Time = 0;
                Load->ADtoGO = 0;
                Load->LightsCount = Load->Lights1Status + Load->Lights2Status + Load->Lights3Status;
                for (i = 1; i < 4; i++) {
                    Load->ADH += Load->AH[i];
                    Load->ADL += Load->AL[i];
                }
                Load->ADH /= 3;
                Load->ADL /= 3;
                if (Load->ADH > Load->ADL) {
                    Load->AD = (Load->ADH - Load->ADL);

                    if (Load->Count < 2) {
                        Load->Count++;
                        if (Load->Count == 1) {
                            Load->JudgeValue = 500;
                        } else if (Load->Count == 2) {
                            if (Load->LightsCount == 1) {
                                Load->JudgeValue = LoadLimitValue;
                            } else {
                                Load->JudgeValue = (LoadLimitValue + Load->TotalLoad) - 0x08;
                            }
                        }
                    }

                    if (Load->AD >= Load->JudgeValue) {
                        Load->ErrorCount++;
                        if (Load->ErrorCount > 2) {
                            Load->ErrorCount = 0;
                            setLoad_Exceptions(1);

                            //                            setProductData(4, (Load->AD >> 8));
                            //                            setProductData(5, Load->AD);
                            //                            setProductData(16, (Load->JudgeValue >> 8));
                            //                            setProductData(17, Load->JudgeValue);
                            //                            setProductData(8, Load->LightsCount);


                        }
                    } else {
                        Load->ErrorCount = 0;
                        if (Load->SafeCount < SafeCountValue) {
                            Load->SafeCount++;
                        }
                        if (Load->SafeCount >= SafeCountValue) {
                            Load->Safe = 1;

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

                            if (Load->StatusOn) {
                                Load->StatusOn = 0;
                                Load->TotalLoad = Load->AD;
                                //Load->JudgeValue=LoadLimitValue*Load->LightsCount;
                            }

                            if (Load->StatusOff) {
                                Load->StatusOff = 0;
                                Load->TotalLoad = Load->AD;
                                Load->JudgeValue = LoadLimitValue * Load->LightsCount;
                            }
                        }
                    }
                }
                setLoad_AH_AL_Restore();

                //                setProductData(2, (Load->AD >> 8));
                //                setProductData(3, Load->AD);
                //                setProductData(8, Load->LightsCount);
                //                setProductData(10, Load->TotalLoad);
                //                setProductData(16, (Load->JudgeValue >> 8));
                //                setProductData(17, Load->JudgeValue);
                //                setProductData(18, Load->ErrorStatus);
                //                setProductData(19, Load->Count);


            }
        } else {
            if (Load->GO) {
                if (!Load->LightsON) {
                    Load->LightsON = 1;
                    Load->Safe = 0;
                }
                if (getTemp_Safe() && getPF_Safe()) {
                    Load->ADtoGO = 1;
                }
            } else {
                if (Load->LightsON) {
                    Load->LightsON = 0;
                    Load->Safe = 1;
                    Load->ErrorCount = 0;
                    Load->Count = 0;
                    Load->TotalLoad = 0;
                    Load->NumberCount = 0;
                    Load->StatusOn = 0;
                    Load->StatusOff = 0;
                    Load->AD = 0;
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

                    //                    setProductData(2, (Load->AD >> 8));
                    //                    setProductData(3, Load->AD);
                    //setProductData(4,(Load->ADH >> 8));
                    //setProductData(5,Load->ADH);
                    //setProductData(6,(Load->ADL >> 8));
                    //setProductData(7,Load->ADL);
                    //                    setProductData(8, Load->NumberCount);
                    //                    setProductData(10, Load->TotalLoad);
                    //                    setProductData(16, (Load->JudgeValue >> 8));
                    //                    setProductData(17, Load->JudgeValue);
                    //                    setProductData(18, Load->ErrorStatus);
                    //                    setProductData(19, Load->Count);

                }
            }
        }
    }
}
//*********************************************************

void setLoad_Exceptions(char command) {
    Load->ERROR = command;
    Load->Safe = (~command) & 0x01;
    Load->ErrorStatus = command;

    if (command) {
        DimmerLights_Exceptions(2);
#if Switch_Class == 1 && Dimmer_use == 1
        setLED(2, 1);
#endif
    }
    setLED(99, command + 10);

    setSw_Enable((~command) & 0x01);
#ifdef RadioFrequency1
    setRF_Enable(1, (~command) & 0x01);
#endif


}
//*********************************************************

void setLoad_Count(char command) {
    Load->Count = command;
    Load->SafeCount = command;
}
//*********************************************************

void setLoad_Enable(char command) {
    Load->Enable = command;
    Load->GO = 0;
}

void setLoad_GO(char command) {
    Load->GO = command;
}

void setLoad_StatusOn(char lights, char command) {
    Load->GO = 1;
    Load->StatusOn = command;

    if (lights == 1) {
        Load->Lights1Status = 1;
    }
    if (lights == 2) {
        Load->Lights2Status = 1;
    }
    if (lights == 3) {
        Load->Lights3Status = 1;
    }
}

void setLoad_StatusOff(char lights, char command) {
    Load->StatusOff = command;
    Load->SafeCount -= 2;
    if (lights == 1) {
        Load->Lights1Status = 0;
    }
    if (lights == 2) {
        Load->Lights2Status = 0;
    }
    if (lights == 3) {
        Load->Lights3Status = 0;
    }
}

char getLoad_Safe() {
    return Load->Safe;
}

char getLoad_ERROR() {
    return Load->ERROR;
}
//*********************************************************

void setLoad_AH_AL_Restore() {
    char i;
    for (i = 0; i < 5; i++) {
        Load->AH[i] = ADH_Restore;
        Load->AL[i] = ADL_Restore;
    }
}

#endif