
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
#if Control_Method_Triac == 1
    if (DimmerLightsIntrIOC->GO == false && DimmerLightsIntrIOC->TriacFlag == false) {
        DimmerLightsIntrIOC->GO = true;
        DimmerLightsIntrIOC->TriacFlag = true;
        if (DimmerReference1 == true) {
            Dimmer.Correction = 1;
        } else {
            Dimmer.Correction = 0;
        }
        //        if (lights == 1) {
        //            ErrLED = ErrLED == true ? false : true;
        //        }
    }
#endif
#if Control_Method_Mosfet == 1
    if (DimmerLightsIntrIOC->GO == false && DimmerLightsIntrIOC->MosfetSignal == false) {
        DimmerLightsIntrIOC->GO = true;
        DimmerLightsIntrIOC->MosfetSignal = true;
        if (DimmerLightsIntrIOC->StatusFlag == true) {
            DimmerLightsIntrIOC->MOSFET = true;
#ifdef use_1KEY
            if (lights == 1) {
                Mosfet1 = true;
                ID_1KEY_1;
            }
#endif
#ifdef use_2KEY
            if (lights == 2) {
                Mosfet2 = true;
            }
#endif
        }
        //        if (lights == 1) {
        //            ErrLED = ErrLED == true ? false : true;
        //        }
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
        if (DimmerLightsIntr->Count >= (DimmerLightsIntr->DimmingValue + Dimmer.Correction)) {
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
                        }
                        //                        else {
                        //                            //                            DimmerLightsIntr->DimmingValue++;
                        //                            //                            if (DimmerLightsIntr->DimmingValue >= DimmerLightsIntr->MinimumValue) {
                        //                            DimmerLightsIntr->Signal = false;
                        //                            DimmerLightsIntr->StatusFlag = false;
                        //                            DimmerLights->Loop = false;
                        //#ifdef use_1KEY
                        //                            if (lights == 1) {
                        //                                setLED(1, 0);
                        //                                setLED2(1);
                        //                            }
                        //#endif
                        //#ifdef use_2KEY
                        //                            if (lights == 2) {
                        //                                LED2 = 0;
                        //                            }
                        //#endif
                        //#ifdef use_3KEY
                        //                            if (lights == 3) {
                        //                                LED3 = 0;
                        //                            }
                        //#endif
                        //                        }
                        //                        }
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
    } else {
        if (DimmerLightsIntr->TriacFlag == true && DimmerLightsIntr->GO == false) {
            DimmerLightsIntr->TriacCount++;
            if (DimmerLightsIntr->TriacCount == 5) {//TriacCountValue
                DimmerLightsIntr->TriacCount = 0;
                DimmerLightsIntr->TriacFlag = false;
                //                if (lights == 1) {
                //                    ErrLED = ErrLED == true ? false : true;
                //                }
            }
        }
    }

#endif
#if Control_Method_Mosfet == 1

    DimmerIntrPointSelect(lights);
    if (DimmerLightsIntr->GO == true) {
        DimmerLightsIntr->Count++;
        if (DimmerLightsIntr->Count
                >= (DimmerLightsIntr->DimmingValue - Dimmer.Correction)) {
            DimmerLightsIntr->Count = 0;
            DimmerLightsIntr->GO = false;
            DimmerLightsIntr->Flag = true;
            if (DimmerLightsIntr->MOSFET == true) {
                DimmerLightsIntr->MOSFET = false;
#ifdef use_1KEY
                if (lights == 1) {
                    Mosfet1 = false;
                    ID_1KEY_0;
                }
#endif
#ifdef use_2KEY
                if (lights == 2) {
                    Mosfet2 = false;
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
                            if (DimmerLightsIntr->DimmingValue < Dimmer_Maxum) {
                                DimmerLightsIntr->DimmingValue++;
                            } else {
                                DimmerLightsIntr->AdjStatus = true;
                            }
                        } else {
                            if (DimmerLightsIntr->DimmingValue > Dimmer_Minimum) {
                                DimmerLightsIntr->DimmingValue--;
                            } else {
                                DimmerLightsIntr->AdjStatus = false;
                            }
                        }
                    } else if (DimmerLightsIntr->AdjRF == true) {
                        if (DimmerLightsIntr->DimmingValue < DimmerLightsIntr->MaxmumValue) {
                            DimmerLightsIntr->DimmingValue++;
                        } else if (DimmerLightsIntr->DimmingValue > DimmerLightsIntr->MaxmumValue) {
                            DimmerLightsIntr->DimmingValue--;
                        }
                        if (DimmerLightsIntr->DimmingValue == DimmerLightsIntr->MaxmumValue) {
                            DimmerLightsIntr->AdjRF = false;
                            DimmerLightsIntr->Signal = false;
                        }
                    }

                    //                    else {
                    //                        DimmerLightsIntr->Signal = false;
                    //                        DimmerLightsIntr->StatusFlag = false;
                    //                        DimmerLights->Loop = false;
                    //#ifdef use_1KEY
                    //                        if (lights == 1) {
                    //                            setLED(1, 0);
                    //                            setLED2(1);
                    //                        }
                    //#endif
                    //#ifdef use_2KEY
                    //                        if (lights == 2) {
                    //                            LED2 = 0;
                    //                        }
                    //#endif
                    //                    }
                }
            }
        }

        if (DimmerLightsIntr->MosfetSignal == true) {
            DimmerLightsIntr->MosfetSignalCount++;
            if (DimmerLightsIntr->MosfetSignalCount == 5) {
                DimmerLightsIntr->MosfetSignalCount = 0;
                DimmerLightsIntr->MosfetSignal = false;
                //            if (lights == 1) {
                //                ErrLED = ErrLED == true ? false : true;
                //            }
            }
        }
    }

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
//******************************************************************************

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
//******************************************************************************

void setDimmerLights_Initialization(char lights) {

    DimmerLightsPointSelect(lights);

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

void DimmerLights_Main() {
#if OverLoad_use == 1
    if (getMain_All_Error_Status(0) == 0) {
        if (Dimmer.LoadOK == true) {
            Dimmer.LoadOK = getLoad_OK() == 1 || getMain_LightsStatus() == 0 ? false : Dimmer.LoadOK;
        }
    } else {
        Dimmer.LoadOK = false;
    }
#endif

#ifdef use_1KEY
    setDimmerLights_Main(1);
#endif

#ifdef use_2KEY
    setDimmerLights_Main(2);
#endif

#ifdef use_3KEY
    setDimmerLights_Main(3);
#endif
    //    DimmerLights_Close();
}
//*********************************************************

void setDimmerLights_Main(char lights) {
    DimmerLightsPointSelect(lights);
    if (DimmerLights->Trigger == true) {

        if (Dimmer.LoadOK == false) {
            DimmerLights->Trigger = false;

            if (DimmerLights->Switch == true) {
                setDimmerLights(lights, 1);
            } else {
                setDimmerLights(lights, 0);
            }
        }
    } else {
        if (DimmerLights->TriggerAdj == true) {
            if (Dimmer.LoadOK == false) {
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

char getDimmerLights_Status(char lights) {
    DimmerLightsPointSelect(lights);
    char status = DimmerLights->Status == true ? 1 : 0;
    return status;
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
//******************************************************************************

char getAll_DimmerLights_AdjGO() {
    char adjgo = 0;
#if Switch_Class == 3
    adjgo = DimmerLights1.AdjGo == true || DimmerLights2.AdjGo == true || DimmerLights3.AdjGo == true ? 1 : 0;
#endif
#if Switch_Class == 2
    adjgo = DimmerLights1.AdjGo == true || DimmerLights2.AdjGo == true ? 1 : 0;
#endif
#if Switch_Class == 1
    adjgo = DimmerLights1.AdjGo == true;
#endif
    return adjgo;
}
//******************************************************************************

void setDimmerLights_SwOn(char sw) {
    DimmerLightsPointSelect(sw);
    char idle = 0;
#if Dimmer_use == 1
    idle = getAll_DimmerLights_AdjGO() == 1 ? 1 : 0;
#endif
    if (idle == 0) {
        DimmerLights->SwFlag = true;
        setBuz(1, BuzzerOnOffTime);
        if (DimmerLights->Status == false) {
            DimmerLights->Status = true;
            setDimmerLights_Trigger(sw, 1);
            setRF_DimmerLights(sw, 1);
            setTxData();
        } else {
            DimmerLights->Status = false;
        }
    }
}
//*********************************************************

void setDimmerLights_SwOff(char sw) {
    DimmerLightsPointSelect(sw);
    char command = DimmerLights->Status == true ? 1 : 0;
    if (DimmerLights->SwFlag == true) {
        DimmerLights->SwFlag = false;
        if (DimmerLights->Status == true) {
            if (DimmerLights->SwAdj == true) {
                DimmerLights->SwAdj = false;
                setDimmerLights_TriggerAdj(sw, 0);
                setProductData(17, product->Data[26 + sw]);
                //                setRF_DimmerLights(sw, command);
                //                setTxData();
            }
        } else {
            setDimmerLights_Trigger(sw, 0);
            setDelayOff_GO(sw, 0, 0);
            //                setRF_DimmerLights(sw, command);
            //                setTxData();
        }
        setRF_DimmerLights(sw, command);
        setTxData();
    }
}
//******************************************************************************

void setDimmerLights_AdjControl(char sw) {
    DimmerLightsPointSelect(sw);
    char idle = 0;
#if Dimmer_use == true
    idle = getAll_DimmerLights_AdjGO() == 1 && Dimmer.LoadOK == true ? 1 : 0;
#endif
    if (idle == 0) {
        if (DimmerLights->SwFlag == true) {
            DimmerLights->SwAdj = true;
            DimmerLights->Status = true;
            setDimmerLights_TriggerAdj(sw, 1);
        }
    }
}
//******************************************************************************

void setDimmerLights_ErrorClose(char lights) {
    if (lights == 255) {
#if Switch_Class == 1
        char count = 1;
#endif
#if Switch_Class == 2
        char count = 2;
#endif
#if Switch_Class == 3
        char count = 3;
#endif
        for (int i = 0; i < count; i++) {
            DimmerLightsPointSelect(i + 1);
            if (getDimmerLights_Status(i + 1) == 1) {
                DimmerLights->SwFlag = true;
                DimmerLights->Status = false;
                setDimmerLights_SwOff(i + 1);
            }
        }
    } else {
        DimmerLightsPointSelect(lights);
        if (getDimmerLights_Status(lights) == 1) {
            DimmerLights->SwFlag = true;
            DimmerLights->Status = false;
            setDimmerLights_SwOff(lights);
        }
    }

    //    if (DimmerLights->SwAdj == true) {
    //        DimmerLights->SwFlag = true;
    //        setDimmerLights_SwOff(lights);
    //    }
    //    DimmerLights->SwFlag = true;
    //    DimmerLights->Status = false;
    //    setDimmerLights_SwOff(lights);
}

char getDimmer_LoadOK() {
    char status = Dimmer.LoadOK == true ? 1 : 0;
    return status;
}
//******************************************************************************

void setDimmerLights_Status(char lights, char command) {
    DimmerLightsPointSelect(lights);
    DimmerLights->Status = command == 1 ? true : false;
}
//******************************************************************************

void setDimmerLights(char lights, char status) {
    DimmerLightsPointSelect(lights);

#if OverLoad_use == true
    Dimmer.LoadOK = getMain_All_Error_Status(0) == 0 ? true : false;
    //    Dimmer.LoadGO = status == 1 ? true : Dimmer.LoadGO;
#endif

    if (status == 1) {
        DimmerLights->Loop = true;
        setLED(lights, 0);
        setLED2(0);
        setDimmerLights_Line(lights);
        DimmerLights->StatusFlag = true;
#if Dimmer_Smooth == 0
        DimmerLights->DimmingValue = DimmerLights->MaxmumValue;
#endif

#if DimmerValue_CloseLightsSave == 0 && DimmerValue_SaveMemory == 0
        DimmerLights->DimmingValue = Dimmer_Maxum;
#endif

#if Dimmable_Func == 1
        //#if Control_Method_Triac == 1
        //        DimmerLights->Signal = 1;
        //#endif
        DimmerLights->DimmingTimeValue = DimmingDelayTime;
#endif
    } else {
        DimmerLights->StatusFlag = false;
        DimmerLights->Loop = false;
        setLED(lights, 1);
        setLED2(1);
        //#ifdef use_1KEY
        //        if (lights == 1) {
        //            setLED(1, 0);
        //        }
        //#endif
        //#ifdef use_2KEY
        //        if (lights == 2) {
        //            LED2 = 0;
        //        }
        //#endif
        //#ifdef use_3KEY
        //        if (lights == 3) {
        //            LED3 = 0;
        //        }
        //#endif
#if Dimmer_Smooth == 0
        DimmerLights->DimmingValue = DimmerLights->MinimumValue;
#endif

#if Dimmable_Func == 1
#if Control_Method_Mosfet == 1
        DimmerLights->MosfetClose = true;
#endif
        //        DimmerLights->Signal = true;
        DimmerLights->AdjFlag = false;
        DimmerLights->AdjStatus = false;
        DimmerLights->AdjRF = false;
        DimmerLights->DimmingTimeValue = DimmingDelayTime;
#else
        DimmerLights->StatusFlag = false;
        DimmerLights->Close = true;
        setLoad_StatusOff(lights, 1);
        setLED(lights, 1);
        setLED2(1);
#endif
    }
}
//*********************************************************

void setDimmerLights_Line(char lights) {
#ifdef use_1KEY
    DimmerLights1.Line = false;
#endif
#ifdef use_2KEY
    DimmerLights2.Line = false;
#endif
#ifdef use_3KEY
    DimmerLights3.Line = false;
#endif
#ifdef use_1KEY
    if (lights == 1) {
        DimmerLights1.Line = true;
    }
#endif
#ifdef use_2KEY
    else if (lights == 2) {
        DimmerLights2.Line = true;
    }
#endif
#ifdef use_3KEY
    else if (lights == 3) {
        DimmerLights3.Line = true;
    }
#endif
}
//*********************************************************

char getDimmerLights_Line() {
    char line = 0;
#ifdef use_1KEY
    if (DimmerLights1.Line == true) {
        line = 1;
    }
#endif
#ifdef use_2KEY
    else if (DimmerLights2.Line == true) {
        line = 2;
    }
#endif
#ifdef use_3KEY
    else if (DimmerLights3.Line == true) {
        line = 3;
    }
#endif
    return line;
}
//*********************************************************

void setDimmerLights_Adj(char lights, char status) {
    DimmerLightsPointSelect(lights);
    if (status == 1) {
        DimmerLights->AdjFlag = true;
        DimmerLights->Signal = true;
    } else {
        if (DimmerLights->AdjFlag == true) {
            DimmerLights->Signal = false;
            DimmerLights->AdjFlag = false;
            DimmerLights->MaxmumValue = DimmerLights->DimmingValue;

#if DimmerValue_CloseLightsSave == true
            setProductData((20 + lights), setPercentValue(DimmerLights->MaxmumValue));
#if DimmerValue_SaveMemory == true
            setMemory_Modify(1);
#endif
#endif

#if OverLoad_use == true
            Dimmer.LoadOK = getMain_All_Error_Status(0) == 0 ? true : false;
            //    Dimmer.LoadGO = status == 1 ? true : Dimmer.LoadGO;
#endif
            setRF_DimmerLights(lights, 1);
            setTxData();
        }
    }
}
//*********************************************************

void setDimmerLights_AdjRF(char lights) {
    DimmerLightsPointSelect(lights);
    DimmerLights->AdjRF = true;
    DimmerLights->Signal = true;
    DimmerLights->MaxmumValue = getPercentValue(product->Data[9]);
}
//*********************************************************

void setDimmerLights_GO(char lights, char command) {

    DimmerLightsPointSelect(lights);
    DimmerLights->GO = command == 1 ? true : false;
}
//*********************************************************

void setDimmerLights_MaxmumValue(char lights, char data) {

    DimmerLightsPointSelect(lights);
    DimmerLights->MaxmumValue = data;
}

void setDimmerLights_Trigger(char lights, char command) {
    DimmerLightsPointSelect(lights);
    DimmerLights->Trigger = true;
    DimmerLights->Switch = command == 1 ? true : false;
}

void setDimmerLights_TriggerAdj(char lights, char command) {
    DimmerLightsPointSelect(lights);
    DimmerLights->TriggerAdj = true;
    DimmerLights->AdjGo = command == 1 ? true : false;
}

//*********************************************************

//void DimmerLights_Exceptions(char status) {
//    if (status == 1) {//temp
//        if (getDimmerLights_StatusFlag() == true) {
//            setBuz(10, BuzzerErrorTime);
//        }
//
//#ifdef use_1KEY
//        setDimmerLights_ERROR(1);
//#endif
//#ifdef use_2KEY
//        setDimmerLights_ERROR(2);
//#endif
//#ifdef use_3KEY
//        setDimmerLights_ERROR(3);
//#endif
//    } else if (status == 2)//Load
//    {
//        setBuz(5, BuzzerErrorTime);
//        setDimmerLights_ERROR(Dimmer.Load);
//    } else if (status == 3)//power fail
//    {
//#ifdef use_1KEY
//        setDimmerLights_ERROR(1);
//#endif
//#ifdef use_2KEY
//        setDimmerLights_ERROR(2);
//#endif
//#ifdef use_3KEY
//        setDimmerLights_ERROR(3);
//#endif
//    }
//
//#ifdef use_1KEY
//    setDimmerLights_TriggerERROR(1, 0);
//#endif
//#ifdef use_2KEY
//    setDimmerLights_TriggerERROR(2, 0);
//#endif
//#ifdef use_3KEY
//    setDimmerLights_TriggerERROR(3, 0);
//#endif
//
//    if (myMain.SelfTest == false) {
//        myMain.i = false;
//        myMain.j = false;
//        myMain.k = true;
//        myMain.Count2 = 0;
//    }
//}
//*********************************************************

//void setDimmerLights_ERROR(char lights) {
//    DimmerLightsPointSelect(lights);
//    if (DimmerLights->Status == true) {
//
//        DimmerLights->Signal = false;
//        DimmerLights->AdjFlag = false;
//        DimmerLights->AdjStatus = false;
//        DimmerLights->StatusFlag = false;
//        DimmerLights->DimmingTimeValue = DimmingDelayTime;
//        DimmerLights->DimmingValue = DimmerLights->MinimumValue;
//        setLoad_StatusOff(lights, 1);
//        setLED(lights, 1);
//        setSw_Status(lights, 0);
//    }
//}
//*********************************************************
//void setDimmerLights_TriggerERROR(char lights, char command) {
//
//    DimmerLightsPointSelect(lights);
//    DimmerLights->Trigger = command;
//    DimmerLights->Switch = command;
//    DimmerLights->TriggerAdj = command;
//    DimmerLights->AdjGo = command;
//}
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
                Dimmer.TempERROR=command;
        }
        void setDimmer_LoadERROR(char dimmer,char command)
        {
                DimmerPointSelect(dimmer);
                Dimmer.LoadERROR=command;
        }
        void setDimmer_PFERROR(char dimmer,char command)
        {
                DimmerPointSelect(dimmer);
                Dimmer.PFERROR=command;
        }
 */
/*	char getDimmer_TempERROR(char dimmer)
        {
                DimmerPointSelect(dimmer);
                return Dimmer.TempERROR;
        }
        char getDimmer_LoadERROR(char dimmer)
        {
                DimmerPointSelect(dimmer);
                return Dimmer.LoadERROR;
        }
        char getDimmer_PFERROR(char dimmer)
        {
                DimmerPointSelect(dimmer);
                return Dimmer.PFERROR;
        }
 */
#if Self_Test == true

void DimmerLightsOpenShow() {
    if (!getTemp_ERROR(1) && !getPF_ERROR(1) && !getLoad_ERROR(1)) {
        if (!myMain.r) {
            if (myMain.k) {
                myMain.k = 0;

                DimmerLightsPointSelect(1);
                DimmerLights->MaxmumValue = Dimmer_Maxum;
                DimmerLights->DimmingValue = Dimmer_Maxum;
                setDimmerLights_Trigger(1, 1);
                setDimmerLights_Switch(1, 1);

                setBuz(1, 1, BuzzerOnOffTime);
            }
            myMain.Count2++;
            if (myMain.Count2 == 150)//*10ms
            {
                myMain.Count2 = 0;

                if (!myMain.i) {

                    if (getTemp_Safe(1) && getPF_Safe(1) && getLoad_Safe(1)) {
                        myMain.i = 1;

                        DimmerLightsPointSelect(1);
                        DimmerLights->AdjRF = 1;
                        DimmerLights->Signal = 1;
                        DimmerLights->MaxmumValue = Dimmer_Maxum + 50;
                        //setProductData(21,setPercentValue(DimmerLights->MaxmumValue));

                        setBuz(1, 1, BuzzerOnOffTime);
                    } else {
                        myMain.Count2 = 150; //*10ms
                    }
                } else {
                    if (!myMain.j) {
                        myMain.j = 1;
                        myMain.r = 1;
                        myMain.SelfTest = 1;

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




