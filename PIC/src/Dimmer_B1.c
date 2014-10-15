
// Includes
#include "Select_File.h"

#if Dimmer_use == 1

/*****************************************************************************/
inline void DimmerIntrIOCPointSelect(char lights) {
#ifdef use_1KEY
    if (lights == 1) {
        DimmerLightsIntrIOC = &DimmerLights1;
    }
#endif
#ifdef use_2KEY
    if (lights == 2) {
        DimmerLightsIntrIOC = &DimmerLights2;
    }
#endif

#ifdef use_3KEY
    if (lights == 3) {
        DimmerLightsIntrIOC = &DimmerLights3;
    }
#endif
}

/*****************************************************************************/
inline void setDimmerLights_IntrIOC_GO(char lights) {

    DimmerIntrIOCPointSelect(lights);
#if Control_Method_Triac == true
    if (DimmerLightsIntrIOC->GO == false && DimmerLightsIntrIOC->TriacFlag == false) {
        DimmerLightsIntrIOC->GO = true;
        DimmerLightsIntrIOC->TriacFlag = true;
    }

#endif
#if Control_Method_Mosfet == true
    if (DimmerLightsIntrIOC->MosfetSignal == false) {
        DimmerLightsIntrIOC->MosfetSignal = true;
        //        ErrLED = true;

        DimmerLightsIntrIOC->GO = true;
        if (DimmerLightsIntrIOC->StatusFlag == true) {

#ifdef use_1KEY
            if (lights == 1) {
                Mosfet1 = true;
                ID_1KEY_1;
            }
#endif
#ifdef use_2KEY
            if (lights == 2) {

                Mosfet2 = true;
                F
            }
#endif
        }
    }
#endif
}

/*****************************************************************************/
inline void DimmerIntrPointSelect(char lights) {
#ifdef use_1KEY
    if (lights == 1) {
        DimmerLightsIntr = &DimmerLights1;
    }
#endif
#ifdef use_2KEY
    if (lights == 2) {
        DimmerLightsIntr = &DimmerLights2;
    }
#endif

#ifdef use_3KEY
    if (lights == 3) {
        DimmerLightsIntr = &DimmerLights3;
    }
#endif
}

/*****************************************************************************/


inline void setDimmerLights_IntrControl(char lights) {
#if Control_Method_Triac == 1
    DimmerIntrPointSelect(lights);
    if (DimmerLightsIntr->GO == true) {
        DimmerLightsIntr->Count++;
        if (DimmerLightsIntr->Count >= (DimmerLightsIntr->DimmingValue - Dimmer->Correction)) {
            DimmerLightsIntr->Count = 0;
            DimmerLightsIntr->GO = false;

            if (DimmerLightsIntr->StatusFlag == true) {
                DimmerLightsIntr->Flag = true;
                DimmerLightsIntr->Triac = true;
#ifdef use_1KEY
                if (lights == 1) {
                    Triac1 = 1;
                    ID_1KEY_1;
                }
#endif
#ifdef use_2KEY
                if (lights == 2) {
                    Triac2 = 1;
                }
#endif
#ifdef use_3KEY
                if (lights == 3) {
                    Triac3 = 1;
                }
#endif
            }
        }
    } else {
        if (DimmerLightsIntr->Flag == true) {
            DimmerLightsIntr->Flag = false;
            if (DimmerLightsIntr->Signal == true) {
                DimmerLightsIntr->DimmingTime++;
                if (DimmerLightsIntr->DimmingTime >= DimmerLightsIntr->DimmingTimeValue) {
                    DimmerLightsIntr->DimmingTime = 0;
                    if (DimmerLightsIntr->AdjFlag == true) {
                        if (DimmerLightsIntr->AdjStatus == false) {
                            if (DimmerLightsIntr->DimmingValue > Dimmer_Maxum) {
                                DimmerLightsIntr->DimmingValue--;
                            } else {
                                DimmerLightsIntr->AdjStatus = true;
                            }
                        } else {
                            if (DimmerLightsIntr->DimmingValue < Dimmer_Minimum) {
                                DimmerLightsIntr->DimmingValue++;
                            } else {
                                DimmerLightsIntr->AdjStatus = false;
                            }
                        }
                    } else if (DimmerLightsIntr->AdjRF == true) {
                        if (DimmerLightsIntr->DimmingValue > DimmerLightsIntr->MaxmumValue) {
                            DimmerLightsIntr->DimmingValue--;
                        } else if (DimmerLightsIntr->DimmingValue < DimmerLightsIntr->MaxmumValue) {
                            DimmerLightsIntr->DimmingValue++;
                        }
                        if (DimmerLightsIntr->DimmingValue == DimmerLightsIntr->MaxmumValue) {
                            DimmerLightsIntr->AdjRF = false;
                            DimmerLightsIntr->Signal = false;
                        }
                    } else {
                        if (DimmerLightsIntr->Status == true) {
                            DimmerLightsIntr->DimmingValue--;
                            if (DimmerLightsIntr->DimmingValue <= DimmerLightsIntr->MaxmumValue) {
                                DimmerLightsIntr->Signal = false;
                            }
                        } else {
                            DimmerLightsIntr->DimmingValue++;
                            if (DimmerLightsIntr->DimmingValue >= DimmerLightsIntr->MinimumValue) {
                                DimmerLightsIntr->Signal = false;
                                DimmerLightsIntr->StatusFlag = false;
                                DimmerLightsIntr->Clear = true;
                                Dimmer->Detect = true;
#ifdef use_1KEY
                                if (lights == 1) {
                                    LED1 = 0;
                                    setLED2(1);
                                }
#endif
#ifdef use_2KEY
                                if (lights == 2) {
                                    LED2 = 0;
                                }
#endif
#ifdef use_3KEY
                                if (lights == 3) {
                                    LED3 = 0;
                                }
#endif
                                setLoad_StatusOff(lights, 1);
                            }
                        }
                    }
                }
            }
        }
    }
    if (DimmerLightsIntr->Triac == true) {
        DimmerLightsIntr->TriacTime++;
        if (DimmerLightsIntr->TriacTime >= 5) {
            DimmerLightsIntr->TriacTime = 0;
            DimmerLightsIntr->Triac = false;

#ifdef use_1KEY
            if (lights == 1) {
                Triac1 = 0;
                ID_1KEY_0;
            }
#endif
#ifdef use_2KEY
            if (lights == 2) {
                Triac2 = 0;
            }
#endif
#ifdef use_3KEY
            if (lights == 3) {
                Triac3 = 0;
            }
#endif
        }
    }
    if (DimmerLightsIntr->TriacFlag == true) {
        DimmerLightsIntr->TriacCount++;
        if (DimmerLightsIntr->TriacCount == 70) {
            DimmerLightsIntr->TriacCount = 0;
            DimmerLightsIntr->TriacFlag = false;
        }
    }
#endif
#if dimmer_Control_Method_Mosfet == 1
#if Dimmer_Half_Wave == 1

    DimmerIntrPointSelect(lights);
    if (DimmerLightsIntr->GO == true) {
        DimmerLightsIntr->Count++;
        if (DimmerLightsIntr->Count
                >= (DimmerLightsIntr->DimmingValue - Dimmer->Correction)) {
            DimmerLightsIntr->Count = 0;
            DimmerLightsIntr->GO = false;
            DimmerLightsIntr->Flag = true;
            if (DimmerLightsIntr->StatusFlag) {
#ifdef use_1KEY
                if (lights == 1) {
                    Mosfet1 = 0;
                    ID_1KEY_0;
                }
#endif
#ifdef use_2KEY
                if (lights == 2) {
                    Mosfet2 = 0;
                }
#endif
                if (DimmerLightsIntr->MosfetClose) {
                    DimmerLightsIntr->MosfetClose = 0;
                    DimmerLightsIntr->StatusFlag = 0;
                    DimmerLightsIntr->Clear = 1;
#ifdef use_1KEY
                    if (lights == 1) {
                        LED1 = 0;
                        setLED2(1);
                    }
#endif
#ifdef use_2KEY
                    if (lights == 2) {
                        LED2 = 0;
                    }
#endif
                    Dimmer->Detect = 1;
                    setLoad_StatusOff(lights, 1);
                }
            }
        }
    } else {
        if (DimmerLightsIntr->Flag == true) {
            DimmerLightsIntr->Flag = false;
            if (DimmerLightsIntr->Signal) {
                DimmerLightsIntr->DimmingTime++;
                if (DimmerLightsIntr->DimmingTime >= DimmerLightsIntr->DimmingTimeValue) {
                    DimmerLightsIntr->DimmingTime = 0;
                    if (DimmerLightsIntr->AdjFlag) {
                        if (DimmerLightsIntr->AdjStatus == 0) {
                            if (DimmerLightsIntr->DimmingValue < Dimmer_Maxum) {
                                DimmerLightsIntr->DimmingValue++;
                            } else {
                                DimmerLightsIntr->AdjStatus = 1;
                            }
                        } else {
                            if (DimmerLightsIntr->DimmingValue > Dimmer_Minimum) {
                                DimmerLightsIntr->DimmingValue--;
                            } else {
                                DimmerLightsIntr->AdjStatus = 0;
                            }
                        }
                    } else if (DimmerLightsIntr->AdjRF) {
                        if (DimmerLightsIntr->DimmingValue < DimmerLightsIntr->MaxmumValue) {
                            DimmerLightsIntr->DimmingValue++;
                        } else if (DimmerLightsIntr->DimmingValue > DimmerLightsIntr->MaxmumValue) {
                            DimmerLightsIntr->DimmingValue--;
                        }
                        if (DimmerLightsIntr->DimmingValue == DimmerLightsIntr->MaxmumValue) {
                            DimmerLightsIntr->AdjRF = 0;
                            DimmerLightsIntr->Signal = 0;
                        }
                    } else {
                        DimmerLightsIntr->Signal = 0;
                    }
                }
            }
        }
    }
    if (DimmerLightsIntr->MosfetSignal == true) {
        DimmerLightsIntr->MosfetSignalCount++;
        if (DimmerLightsIntr->MosfetSignalCount == 110) {

            DimmerLightsIntr->MosfetSignalCount = 0;
            DimmerLightsIntr->MosfetSignal = false;
            //            ErrLED = 0;
        }
    }
#endif
#endif
}


/*****************************************************************************/

/******************************************************************************/
void DimmerLightsPointSelect(char lights) {
#ifdef use_1KEY
    if (lights == 1) {
        DimmerLights = &DimmerLights1;
    }
#endif
#ifdef use_2KEY
    if (lights == 2) {
        DimmerLights = &DimmerLights2;
    }
#endif
#ifdef use_3KEY
    if (lights == 3) {
        DimmerLights = &DimmerLights3;
    }
#endif		
}
//*********************************************************

void DimmerLights_Initialization() {
#ifdef use_1KEY

    DimmerLights11 = &DimmerLights1;
    setDimmerLights_Initialization(1);
#endif

#ifdef use_2KEY
    DimmerLights22 = &DimmerLights2;
    setDimmerLights_Initialization(2);
#endif

#ifdef use_3KEY
    DimmerLights33 = &DimmerLights3;
    setDimmerLights_Initialization(3);
#endif

#ifdef DimmerReference1
    Dimmer_Initialization();
#endif

}

void setDimmerLights_Initialization(char lights) {

    DimmerLightsPointSelect(lights);
    DimmerLights->Clear = 1;

#if FlashMemory_use == 1
#if DimmerValue_SaveMemory == 1
    DimmerLights->MaxmumValue = getPercentValue(product->Data[(20 + lights)]);
#else
    DimmerLights->MaxmumValue = Dimmer_Maxum;
    DimmerLights->MinimumValue = Dimmer_Minimum;
#endif
#else
    DimmerLights->MaxmumValue = Dimmer_Maxum;
    DimmerLights->MinimumValue = Dimmer_Minimum;
#endif


#if Dimmable_Func == 1
#if Control_Method_Triac == 1
    DimmerLights->DimmingValue = DimmerLights->MinimumValue;
#endif

#if Control_Method_Mosfet == 1
    DimmerLights->DimmingValue = DimmerLights->MaxmumValue;
#endif

#else
#if Control_Method_Triac == 1
    DimmerLights->DimmingValue = DimmerLights->MaxmumValue;
#endif	

#if Control_Method_Mosfet == 1
    DimmerLights->DimmingValue = DimmerLights->MinimumValue;
#endif											
#endif
}
//*********************************************************

void DimmerLights_Close() {
    if (Dimmer->Detect == true) {
        Dimmer->Detect = false;
        if (getDimmerLights_StatusFlag() == false) {
            setLoad_GO(0);
            setMemory_GO(1);
        }
    }
}
//*********************************************************

void DimmerLights_Main() {
#ifdef use_1KEY

    setDimmerLights_Main(1);
#endif

#ifdef use_2KEY
    setDimmerLights_Main(2);
#endif

#ifdef use_3KEY
    setDimmerLights_Main(3);
#endif

    DimmerLights_Close();
}
//*********************************************************

void setDimmerLights_Main(char lights) {
    char clear = 1;
    DimmerLightsPointSelect(lights);

#if Switch_Class == 3
    if (lights == 1) {
        clear = (DimmerLights2.Clear == false || DimmerLights3.Clear == false) ? 0 : 1;
    } else if (lights == 2) {
        clear = (DimmerLights1.Clear == false || DimmerLights3.Clear == false) ? 0 : 1;
    } else if (lights == 3) {
        clear = (DimmerLights1.Clear == false || DimmerLights2.Clear == false) ? 0 : 1;
    }
#endif

#if Switch_Class == 2
    if (lights == 1) {
        clear = (DimmerLights2.Clear == false) ? 0 : 1;
    } else if (lights == 2) {
        clear = (DimmerLights1.Clear == false) ? 0 : 1;
    }
#endif

    if (DimmerLights->Trigger == true) {
        if (clear == 1) {
            DimmerLights->Trigger = false;
            if (DimmerLights->Switch == true) {
                setDimmerLights(lights, 1);
            } else {
                setDimmerLights(lights, 0);
            }
#if OverLoad_use == 1
            DimmerLights->Clear = false;
#endif
        }
    } else {
        if (DimmerLights->TriggerAdj == true) {
            if (clear == 1) {
                DimmerLights->TriggerAdj = false;
                if (DimmerLights->AdjGo == true) {
                    setDimmerLights_Adj(lights, 1);
                    setBuz(1, BuzzerOnOffTime);
                } else {
                    setDimmerLights_Adj(lights, 0);
                }
            }
        }
    }
}
//*********************************************************

char getDimmerLights_StatusFlag() {
    char Status = 0;

#if Switch_Class == 3
    Status = (DimmerLights1.StatusFlag == true || DimmerLights2.StatusFlag == true || DimmerLights3.StatusFlag == true) ? 1 : 0;
#endif

#if Switch_Class == 2
    Status = (DimmerLights1.StatusFlag == true || DimmerLights2.StatusFlag == true) ? 1 : 0;
#endif

#if Switch_Class == 1
    Status = (DimmerLights1.StatusFlag == true) ? 1 : 0;
#endif

    return Status;
}
//*********************************************************

char getDimmerLights_Trigger() {
    char Status = 0;

#if Switch_Class == 3
    Status = (DimmerLights1.Trigger == true || DimmerLights2.Trigger == true || DimmerLights3.Trigger == true) ? 1 : 0;
#endif

#if Switch_Class == 2
    Status = (DimmerLights1.Trigger == true || DimmerLights2.Trigger == true) ? 1 : 0;
#endif

#if Switch_Class == 1
    Status = (DimmerLights1.Trigger) ? 1 : 0;
#endif

    return Status;
}
//*********************************************************

void DimmerLights_Exceptions(char status) {
    if (status == 1) {//temp
        if (getDimmerLights_StatusFlag() == true) {
            setBuz(10, BuzzerErrorTime);
        }

#ifdef use_1KEY
        setDimmerLights_ERROR(1);
#endif	
#ifdef use_2KEY		
        setDimmerLights_ERROR(2);
#endif	
#ifdef use_3KEY		
        setDimmerLights_ERROR(3);
#endif	
    } else if (status == 2)//Load
    {
        setBuz(5, BuzzerErrorTime);
        setDimmerLights_ERROR(Dimmer->Load);
    } else if (status == 3)//power fail
    {
#ifdef use_1KEY
        setDimmerLights_ERROR(1);
#endif	
#ifdef use_2KEY		
        setDimmerLights_ERROR(2);
#endif	
#ifdef use_3KEY			
        setDimmerLights_ERROR(3);
#endif	
    }

#ifdef use_1KEY
    setDimmerLights_TriggerERROR(1, 0);
#endif
#ifdef use_2KEY
    setDimmerLights_TriggerERROR(2, 0);
#endif
#ifdef use_3KEY
    setDimmerLights_TriggerERROR(3, 0);
#endif

    if (myMain->SelfTest == false) {
        myMain->i = false;
        myMain->j = false;
        myMain->k = true;
        myMain->Count2 = 0;
    }
}
//*********************************************************

void setDimmerLights_ERROR(char lights) {
    DimmerLightsPointSelect(lights);
    if (DimmerLights->Status == true) {

        DimmerLights->Signal = false;
        DimmerLights->AdjFlag = false;
        DimmerLights->AdjStatus = false;
        DimmerLights->StatusFlag = false;
        DimmerLights->DimmingTimeValue = DimmingDelayTime;
        DimmerLights->DimmingValue = DimmerLights->MinimumValue;
        Dimmer->Detect = true;
        setLoad_StatusOff(lights, 1);
        setLED(lights, 1);
        setSw_Status(lights, 0);
        setRFSW_Status(lights, 0);
    }
}

void setDimmerLights_TriggerERROR(char lights, char command) {

    DimmerLightsPointSelect(lights);
    DimmerLights->Trigger = command;
    DimmerLights->Switch = command;
    DimmerLights->TriggerAdj = command;
    DimmerLights->AdjGo = command;
}

//*********************************************************

void setDimmerLights(char lights, char status) {
    DimmerLightsPointSelect(lights);
    Dimmer->Load = lights;
    if (status == 1) {
        DimmerLights->Status = true;
        setLED(lights, 0);
        setLED2(0);
        setLoad_Count(0);
#if Dimmable_Func == true
        DimmerLights->Signal = true;
        DimmerLights->DimmingTimeValue = DimmingDelayTime;
#endif
        if (DimmerLights->StatusFlag == false) {
            DimmerLights->StatusFlag = true;
            setLoad_StatusOn(lights, 1);
            setMemory_GO(0);

#if Dimmer_Smooth == false
            DimmerLights->DimmingValue = DimmerLights->MaxmumValue;
#endif

#if DimmerValue_CloseLightsSave == false && DimmerValue_SaveMemory == false
            DimmerLights->DimmingValue = Dimmer_Maxum;
#endif
        }
    } else {
        DimmerLights->Status = false;
#if Dimmer_Smooth == false
        DimmerLights->DimmingValue = DimmerLights->MinimumValue;
#endif

#if Dimmable_Func == true
#if Control_Method_Mosfet == true
        DimmerLights->MosfetClose = true;
#endif
        DimmerLights->Signal = true;
        DimmerLights->AdjFlag = false;
        DimmerLights->AdjStatus = false;
        DimmerLights->DimmingTimeValue = DimmingDelayTime;

#else
        DimmerLights->StatusFlag = false;
        DimmerLights->Close = true;
        Dimmer->Detect = true;
        setLoad_StatusOff(lights, 1);
        setLED(lights, 1);
        setLED2(1);
#endif


    }
}

void setDimmerLights_Adj(char lights, char status) {
    DimmerLightsPointSelect(lights);
    if (status == 1) {
        DimmerLights->AdjFlag = true;
        DimmerLights->Signal = true;
    } else {
        if (DimmerLights->AdjFlag == true) {

            DimmerLights->Signal = false;
            DimmerLights->AdjFlag = false;
            setLoad_StatusOff(0, 1);
            DimmerLights->MaxmumValue = DimmerLights->DimmingValue;

#if DimmerValue_CloseLightsSave == true
            setProductData((20 + lights), setPercentValue(DimmerLights->MaxmumValue));
#if DimmerValue_SaveMemory == true
            setMemory_Modify(1);
#endif
#endif
            setRF_DimmerLights(lights, 1);
            setTxData(1);
        }
    }
}
//*********************************************************

void setDimmerLights_GO(char lights, char command) {

    DimmerLightsPointSelect(lights);
    DimmerLights->GO = command;
}
//*********************************************************

void setDimmerLights_AdjRF(char lights) {

    DimmerLightsPointSelect(lights);
    DimmerLights->AdjRF = true;
    DimmerLights->Signal = true;
    DimmerLights->MaxmumValue = getPercentValue(product->Data[9]);
}

void setDimmerLights_MaxmumValue(char lights, char data) {

    DimmerLightsPointSelect(lights);
    DimmerLights->MaxmumValue = data;
}

void setDimmerLights_Switch(char lights, char command) {

    DimmerLightsPointSelect(lights);
    DimmerLights->Switch = command;
}

void setDimmerLights_AdjGo(char lights, char command) {

    DimmerLightsPointSelect(lights);
    DimmerLights->AdjGo = command;
}

void setDimmerLights_Trigger(char lights, char command) {

    DimmerLightsPointSelect(lights);
    DimmerLights->Trigger = command;
}

void setDimmerLights_TriggerAdj(char lights, char command) {

    DimmerLightsPointSelect(lights);
    DimmerLights->TriggerAdj = command;
}

void setDimmerLights_Clear(char lights, char command) {

    DimmerLightsPointSelect(lights);
    DimmerLights->Clear = command;
}
/*	char getDimmerLights_Clear(char lights)
        {
                DimmerLightsPointSelect(lights);
                return DimmerLights->Clear;
        }*/

/*
        void setDimmerLights_Open(char lights,char command)
        {
                DimmerLightsPointSelect(lights);
                DimmerLights->Open=command;
        }
        char getDimmerLights_Open(char lights)
        {
                DimmerLightsPointSelect(lights);
                return DimmerLights->Open;
        }
        void setDimmerLights_Close(char lights,char command)
        {
                DimmerLightsPointSelect(lights);
                DimmerLights->Close=command;
        }
        char getDimmerLights_Close(char lights)
        {
                DimmerLightsPointSelect(lights);
                return DimmerLights->Close;
        }
 */
//*********************************************************

char getPercentValue(char value) {
#if Control_Method_Triac == 1
    float i = Dimmer_Minimum - Dimmer_Maxum;
    i /= 100;
    return (char) (((100 - value) * i) + Dimmer_Maxum);
#endif

#if Control_Method_Mosfet == 1
    float i = Dimmer_Maxum - Dimmer_Minimum;
    i /= 100;

    return (char) (((100 - value) * i) + Dimmer_Maxum);
#endif
}
//*********************************************************

char setPercentValue(char value) {
#if Control_Method_Triac == 1
    float i = Dimmer_Minimum - Dimmer_Maxum;
    i /= 100;
    return (100 - (char) ((value - Dimmer_Maxum) / i));
#endif

#if Control_Method_Mosfet == 1
    float i = Dimmer_Maxum - Dimmer_Minimum;
    i /= 100;

    return (100 - (char) ((value - Dimmer_Maxum) / i));
#endif
}


//*********************************************************

inline void Dimmer_Initialization() {

    Dimmer = &Dimmer1;
}
/*	void DimmerPointSelect(char dimmer)
        {

                #ifdef DimmerReference1
                        if(dimmer == 1)
                        {
                                Dimmer=&Dimmer1;
                        }
                #endif
        }
 */
/*	void setDimmer_TempERROR(char dimmer,char command)
        {
                DimmerPointSelect(dimmer);
                Dimmer->TempERROR=command;
        }
        void setDimmer_LoadERROR(char dimmer,char command)
        {
                DimmerPointSelect(dimmer);
                Dimmer->LoadERROR=command;
        }
        void setDimmer_PFERROR(char dimmer,char command)
        {
                DimmerPointSelect(dimmer);
                Dimmer->PFERROR=command;
        }
 */
/*	void setDimmer_Detect(char dimmer,char command)
        {
                DimmerPointSelect(dimmer);
                Dimmer->Detect=command;
        }*/
/*	char getDimmer_TempERROR(char dimmer)
        {
                DimmerPointSelect(dimmer);
                return Dimmer->TempERROR;
        }
        char getDimmer_LoadERROR(char dimmer)
        {
                DimmerPointSelect(dimmer);
                return Dimmer->LoadERROR;
        }
        char getDimmer_PFERROR(char dimmer)
        {
                DimmerPointSelect(dimmer);
                return Dimmer->PFERROR;
        }
 */
/*	char getDimmer_Detect(char dimmer)
        {
                DimmerPointSelect(dimmer);
                return Dimmer->Detect;
        }*/
#if Self_Test == true

void DimmerLightsOpenShow() {
    if (!getTemp_ERROR(1) && !getPF_ERROR(1) && !getLoad_ERROR(1)) {
        if (!myMain->r) {
            if (myMain->k) {
                myMain->k = 0;

                DimmerLightsPointSelect(1);
                DimmerLights->MaxmumValue = Dimmer_Maxum;
                DimmerLights->DimmingValue = Dimmer_Maxum;
                setDimmerLights_Trigger(1, 1);
                setDimmerLights_Switch(1, 1);

                setBuz(1, 1, BuzzerOnOffTime);
            }
            myMain->Count2++;
            if (myMain->Count2 == 150)//*10ms
            {
                myMain->Count2 = 0;

                if (!myMain->i) {

                    if (getTemp_Safe(1) && getPF_Safe(1) && getLoad_Safe(1)) {
                        myMain->i = 1;

                        DimmerLightsPointSelect(1);
                        DimmerLights->AdjRF = 1;
                        DimmerLights->Signal = 1;
                        DimmerLights->MaxmumValue = Dimmer_Maxum + 50;
                        //setProductData(21,setPercentValue(DimmerLights->MaxmumValue));

                        setBuz(1, 1, BuzzerOnOffTime);
                    } else {
                        myMain->Count2 = 150; //*10ms
                    }
                } else {
                    if (!myMain->j) {
                        myMain->j = 1;
                        myMain->r = 1;
                        myMain->SelfTest = 1;

                        DimmerLightsPointSelect(1);
                        setDimmerLights_Trigger(1, 1);
                        setDimmerLights_Switch(1, 0);
                        DimmerLights->MaxmumValue = getPercentValue(product->Data[(20 + 1)]);

                        setBuz(1, 3, BuzzerPowerOnTime);

                        setSw_Enable(1);

#ifdef RadioFrequency1
                        setRF_Enable(1, 1);
#endif

                    }
                }
            }
        }
    }
}
#endif
//end
#endif




