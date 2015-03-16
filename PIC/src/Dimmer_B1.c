
// Includes
#include "Select_File.h"

#if Dimmer_use == 1 

void DimmerIntr_Initialization() {

#ifdef use_1KEY 
    DimmerIntr1.TuneTimeValue = 3; //7
    DimmerIntr1.MaxmumValue = Dimmer_Maxum;
    DimmerIntr1.MinimumValue = Dimmer_Minimum;
    DimmerIntr1.Tune = false;

#ifndef MCU_16F723A
#if DimmerValue_SaveMemory == 1
    if (myMain.InitDimmer == true) {
        product->Data[21] = getDimmerLights_ValueToPercent(Dimmer_Maxum);
    }

    DimmerIntr1.DimmingValue = getDimmerLights_PercentToValue(product->Data[21]);


#else
    product->Data[21] = getDimmerLights_ValueToPercent(Dimmer_Maxum);
#endif

    DimmerIntr1.TuneValue2 = Division(Dimmer_Maxum, 2);
    DimmerIntr1.TuneValue3 = DimmerIntr1.TuneValue2 + (TotalCount - Dimmer_Maxum);
    DimmerIntr1.TuneValue4 = DimmerIntr1.TuneValue3 + DimmerIntr1.TuneValue2;
    DimmerIntr1.TuneEnd = DimmerIntr1.TuneValue4 + 1;
#endif

#endif

#ifdef use_2KEY
    DimmerIntr2.TuneTimeValue = 3; //7
    DimmerIntr2.MaxmumValue = Dimmer_Maxum;
    DimmerIntr2.MinimumValue = Dimmer_Minimum;
    DimmerIntr2.Tune = false;

#ifndef MCU_16F723A
#if DimmerValue_SaveMemory == 1
    if (myMain.InitDimmer == true) {
        product->Data[22] = getDimmerLights_ValueToPercent(Dimmer_Maxum);
    }

    DimmerIntr2.DimmingValue = getDimmerLights_PercentToValue(product->Data[22]);


#else
    product->Data[22] = getDimmerLights_ValueToPercent(Dimmer_Maxum);
#endif

    DimmerIntr2.TuneValue2 = Division(Dimmer_Maxum, 2);
    DimmerIntr2.TuneValue3 = DimmerIntr2.TuneValue2 + (TotalCount - Dimmer_Maxum);
    DimmerIntr2.TuneValue4 = DimmerIntr2.TuneValue3 + DimmerIntr2.TuneValue2;
    DimmerIntr2.TuneEnd = DimmerIntr2.TuneValue4 + 1;
#endif

#endif


#ifdef use_3KEY
    DimmerIntr3.TuneTimeValue = 7;
    DimmerIntr3.MaxmumValue = Dimmer_Maxum;
    DimmerIntr3.MinimumValue = Dimmer_Minimum;
#if DimmerValue_SaveMemory == 1
    if (myMain.InitDimmer == true) {
        product->Data[23] = getDimmerLights_ValueToPercent(Dimmer_Maxum);
    } else {
        DimmerIntr3.DimmingValue = getDimmerLights_PercentToValue(product->Data[23]);
    }
#else
    product->Data[23] = getDimmerLights_ValueToPercent(Dimmer_Maxum);
#endif
#endif

#if DimmerValue_SaveMemory == 1
    if (myMain.InitDimmer == true) {
        myMain.InitDimmer = false;
        myMain.SaveDimmer = true;
        setMemory_Modify(1);
    }
#endif
}

void setDimmerIntr_ControlStatus(char lights, char command) {
#ifdef use_1KEY
    if (lights == 1) {
        DimmerIntr1.ControlStatus = command == 1 ? true : false;
    }
#endif
#ifdef use_2KEY
    else if (lights == 2) {
        DimmerIntr2.ControlStatus = command == 1 ? true : false;
    }
#endif
#ifdef use_3KEY
    else if (lights == 3) {
        DimmerIntr3.ControlStatus = command == 1 ? true : false;
    }
#endif
}

void setDimmerIntr_DimmingValue(char lights, char value) {
#ifdef use_1KEY
    if (lights == 1) {
        DimmerIntr1.DimmingValue = value;
    }
#endif
#ifdef use_2KEY
    else if (lights == 2) {
        DimmerIntr2.DimmingValue = value;
    }
#endif
#ifdef use_3KEY
    else if (lights == 3) {
        DimmerIntr3.DimmingValue = value;
    }
#endif
}

char getDimmerIntr_DimmingValue(char lights) {
    char value = 0;
#ifdef use_1KEY
    if (lights == 1) {
        value = DimmerIntr1.DimmingValue;
    }
#endif
#ifdef use_2KEY
    else if (lights == 2) {
        value = DimmerIntr2.DimmingValue;
    }
#endif
#ifdef use_3KEY
    else if (lights == 3) {
        value = DimmerIntr3.DimmingValue;
    }
#endif
    return value;
}

#if CC2500_use == 1 || PIR_use == 1

void setDimmerIntr_MaxmumValue(char lights, char value) {
#ifdef use_1KEY
    if (lights == 1) {
        DimmerIntr1.MaxmumValue = value;
    }
#endif
#ifdef use_2KEY
    else if (lights == 2) {
        DimmerIntr2.MaxmumValue = value;
    }
#endif
#ifdef use_3KEY
    else if (lights == 3) {
        DimmerIntr3.MaxmumValue = value;
    }
#endif
}

char getDimmerIntr_MaxmumValue(char lights) {
    char value = 0;
#ifdef use_1KEY
    if (lights == 1) {
        value = DimmerIntr1.MaxmumValue;
    }
#endif
#ifdef use_2KEY
    else if (lights == 2) {
        value = DimmerIntr2.MaxmumValue;
    }
#endif
#ifdef use_3KEY
    else if (lights == 3) {
        value = DimmerIntr3.MaxmumValue;
    }
#endif
    return value;
}
#endif

void setDimmerIntr_MinimumValue(char lights, char value) {
#ifdef use_1KEY
    if (lights == 1) {
        DimmerIntr1.MinimumValue = value;
    }
#endif
#ifdef use_2KEY
    else if (lights == 2) {
        DimmerIntr2.MinimumValue = value;
    }
#endif
#ifdef use_3KEY
    else if (lights == 3) {
        DimmerIntr3.MinimumValue = value;
    }
#endif
}

char getDimmerIntr_MinimumValue(char lights) {
    char value = 0;
#ifdef use_1KEY
    if (lights == 1) {
        value = DimmerIntr1.MinimumValue;
    }
#endif
#ifdef use_2KEY
    else if (lights == 2) {
        value = DimmerIntr2.MinimumValue;
    }
#endif
#ifdef use_3KEY
    else if (lights == 3) {
        value = DimmerIntr3.MinimumValue;
    }
#endif
    return value;
}

void setDimmerIntr_Dimming_Sw(char lights, char command) {
#ifdef use_1KEY
    if (lights == 1) {
        DimmerIntr1.Dimming_Sw = command == 1 ? true : false;
    }
#endif
#ifdef use_2KEY
    else if (lights == 2) {
        DimmerIntr2.Dimming_Sw = command == 1 ? true : false;
    }
#endif
#ifdef use_3KEY
    else if (lights == 3) {
        DimmerIntr3.Dimming_Sw = command == 1 ? true : false;
    }
#endif
}

char getDimmerIntr_Dimming_Sw(char lights) {
    char status = 0;
#ifdef use_1KEY
    if (lights == 1) {
        status = DimmerIntr1.Dimming_Sw == true ? 1 : 0;
    }
#endif
#ifdef use_2KEY
    if (lights == 2) {
        status = DimmerIntr2.Dimming_Sw == true ? 1 : 0;
    }
#endif
#ifdef use_3KEY
    if (lights == 3) {
        status = DimmerIntr3.Dimming_Sw == true ? 1 : 0;
    }
#endif

    return status;
}

void setDimmerIntr_Dimming_RF(char lights, char command) {
#ifdef use_1KEY
    if (lights == 1) {
        DimmerIntr1.Dimming_RF = command == 1 ? true : false;
    }
#endif
#ifdef use_2KEY
    else if (lights == 2) {
        DimmerIntr2.Dimming_RF = command == 1 ? true : false;
    }
#endif
#ifdef use_3KEY
    else if (lights == 3) {
        DimmerIntr3.Dimming_RF = command == 1 ? true : false;
    }
#endif
}
//*********************************************************

char getAll_DimmerIntr_ControlStatus() {
    char status = 0;

#if Switch_Class == 3
    status = (DimmerIntr1.ControlStatus == true || DimmerIntr2.ControlStatus == true || DimmerIntr3.ControlStatus == true) ? 1 : 0;
#endif

#if Switch_Class == 2
    status = (DimmerIntr1.ControlStatus == true || DimmerIntr2.ControlStatus == true) ? 1 : 0;
#endif

#if Switch_Class == 1
    status = (DimmerIntr1.ControlStatus == true) ? 1 : 0;
#endif

    return status;
}
//******************************************************************************

char getAll_DimmerIntr_Dimming_Sw() {
    char status = 0;

#if Switch_Class == 3
    status = (DimmerIntr1.Dimming_Sw == true || DimmerIntr2.Dimming_Sw == true || DimmerIntr3.Dimming_Sw == true) ? 1 : 0;
#endif

#if Switch_Class == 2
    status = (DimmerIntr1.Dimming_Sw == true || DimmerIntr2.Dimming_Sw == true) ? 1 : 0;
#endif

#if Switch_Class == 1
    status = (DimmerIntr1.Dimming_Sw == true) ? 1 : 0;
#endif

    return status;
}

//*****************************************************************************

char getAll_DimmerIntr_Dimming_Sw_RF() {
    char status = 0;

#if Switch_Class == 3
    status = (DimmerIntr1.Dimming_Sw == true || DimmerIntr2.Dimming_Sw == true || DimmerIntr3.Dimming_Sw == true) ? 1 : 0;
#endif

#if Switch_Class == 2
    status = (DimmerIntr1.Dimming_Sw == true || DimmerIntr2.Dimming_Sw == true) ? 1 : 0;
#endif

#if Switch_Class == 1
    status = (DimmerIntr1.Dimming_Sw == true) ? 1 : 0;
#endif

#if CC2500_use == 1
    if (status == 0) {
#if Switch_Class == 3
        status = (DimmerIntr1.Dimming_RF == true || DimmerIntr2.Dimming_RF == true || DimmerIntr3.Dimming_RF == true) ? 1 : 0;
#endif

#if Switch_Class == 2
        status = (DimmerIntr1.Dimming_RF == true || DimmerIntr2.Dimming_RF == true) ? 1 : 0;
#endif

#if Switch_Class == 1
        status = (DimmerIntr1.Dimming_RF == true) ? 1 : 0;
#endif
    }
#endif
    return status;
}

//*****************************************************************************

//inline void setDimmerIntr_IOC(char lights) {
//    //    DimmerIntrIOCPointSelect(lights);
//#ifdef use_1KEY
//    if (lights == 1) {
//        DimmerIntr = &DimmerIntr1;
//    }
//#endif
//#ifdef use_2KEY
//    else if (lights == 2) {
//        DimmerIntr = &DimmerIntr2;
//    }
//#endif
//#ifdef use_3KEY
//    else if (lights == 3) {
//        DimmerIntr = &DimmerIntr3;
//    }
//#endif
//#if Control_Method_Triac == 1
//    if (DimmerLightsIntrIOC->GO == false && DimmerLightsIntrIOC->TriacFlag == false) {
//        DimmerLightsIntrIOC->GO = true;
//        DimmerLightsIntrIOC->TriacFlag = true;
//        if (DimmerReference1 == true) {
//            Dimmer.Correction = 1;
//        } else {
//            Dimmer.Correction = 0;
//        }
//        //        if (lights == 1) {
//        //            ErrLED = ErrLED == true ? false : true;
//        //        }
//    }
//#endif
//#if Control_Method_Mosfet == 1
//    if (DimmerIntr->Start == false && DimmerReference1 == true) {
//        DimmerIntr->Start = true;
//        DimmerIntr->GO = true;
//
//        if (DimmerIntr->ControlStatus == true) {
//#ifdef use_1KEY
//            if (lights == 1) {
//                Mosfet1 = true;
//                //                ID_1KEY_1;
//            }
//#endif
//#ifdef use_2KEY
//            else if (lights == 2) {
//                Mosfet2 = true;
//            }
//#endif
//        }
//    }
//#endif
//}

/*****************************************************************************/

//inline void setDimmerIntr_TMR(char lights) {
//
//#ifdef use_1KEY
//    if (lights == 1) {
//        DimmerIntr = &DimmerIntr1;
//    }
//#endif
//#ifdef use_2KEY
//    else if (lights == 2) {
//        DimmerIntr = &DimmerIntr2;
//    }
//#endif
//#ifdef use_3KEY
//    else if (lights == 3) {
//        DimmerIntr = &DimmerIntr3;
//    }
//#endif
//
//#ifdef use_1KEY
//    if (lights == 1) {
//        DimmerIntr = &DimmerIntr1;
//    }
//#endif
//#ifdef use_2KEY
//    else if (lights == 2) {
//        DimmerIntr = &DimmerIntr2;
//    }
//#endif
//#ifdef use_3KEY
//    else if (lights == 3) {
//        DimmerIntr = &DimmerIntr3;
//    }
//#endif
//
//#if Control_Method_Triac == 1
//    DimmerIntrPointSelect(lights);
//    if (DimmerLightsIntr->GO == true) {
//        DimmerLightsIntr->Count++;
//        if (DimmerLightsIntr->Count >= (DimmerLightsIntr->DimmingValue + Dimmer.Correction)) {
//            DimmerLightsIntr->Count = 0;
//            DimmerLightsIntr->GO = false;
//
//            if (DimmerLightsIntr->StatusFlag == true) {
//                DimmerLightsIntr->Flag = true;
//                DimmerLightsIntr->Triac = true;
//#ifdef use_1KEY
//                if (lights == 1) {
//                    Triac1 = 1;
//                    ID_1KEY_1;
//                }
//#endif
//#ifdef use_2KEY
//                if (lights == 2) {
//                    Triac2 = 1;
//                }
//#endif
//#ifdef use_3KEY
//                if (lights == 3) {
//                    Triac3 = 1;
//                }
//#endif
//            }
//        }
//    } else {
//        if (DimmerLightsIntr->Flag == true) {
//            DimmerLightsIntr->Flag = false;
//            if (DimmerLightsIntr->Signal == true) {
//                DimmerLightsIntr->DimmingTime++;
//                if (DimmerLightsIntr->DimmingTime >= DimmerLightsIntr->DimmingTimeValue) {
//                    DimmerLightsIntr->DimmingTime = 0;
//                    if (DimmerLightsIntr->AdjSw == true) {
//                        if (DimmerLightsIntr->AdjStatus == false) {
//                            if (DimmerLightsIntr->DimmingValue > Dimmer_Maxum) {
//                                DimmerLightsIntr->DimmingValue--;
//                            }
//                            if (DimmerLightsIntr->DimmingValue == Dimmer_Maxum) {
//                                DimmerLightsIntr->AdjStatus = true;
//                            }
//                        } else {
//                            if (DimmerLightsIntr->DimmingValue < Dimmer_Minimum) {
//                                DimmerLightsIntr->DimmingValue++;
//                            }
//                            if (DimmerLightsIntr->DimmingValue == Dimmer_Minimum) {
//                                DimmerLightsIntr->AdjStatus = false;
//                            }
//                        }
//                    } else if (DimmerLightsIntr->AdjRF == true) {
//                        if (DimmerLightsIntr->DimmingValue > DimmerLightsIntr->MaxmumValue) {
//                            DimmerLightsIntr->DimmingValue--;
//                        } else if (DimmerLightsIntr->DimmingValue < DimmerLightsIntr->MaxmumValue) {
//                            DimmerLightsIntr->DimmingValue++;
//                        }
//                        if (DimmerLightsIntr->DimmingValue == DimmerLightsIntr->MaxmumValue) {
//                            DimmerLightsIntr->AdjRF = false;
//                            DimmerLightsIntr->Signal = false;
//                        }
//                    } else {
//                        if (DimmerLightsIntr->Status == true) {
//                            DimmerLightsIntr->DimmingValue--;
//                            if (DimmerLightsIntr->DimmingValue <= DimmerLightsIntr->MaxmumValue) {
//                                DimmerLightsIntr->Signal = false;
//                            }
//                        }
//                        //                        else {
//                        //                            //                            DimmerLightsIntr->DimmingValue++;
//                        //                            //                            if (DimmerLightsIntr->DimmingValue >= DimmerLightsIntr->MinimumValue) {
//                        //                            DimmerLightsIntr->Signal = false;
//                        //                            DimmerLightsIntr->StatusFlag = false;
//                        //                            DimmerLights->Loop = false;
//                        //#ifdef use_1KEY
//                        //                            if (lights == 1) {
//                        //                                setLED(1, 0);
//                        //                                setLED2(1);
//                        //                            }
//                        //#endif
//                        //#ifdef use_2KEY
//                        //                            if (lights == 2) {
//                        //                                LED2 = 0;
//                        //                            }
//                        //#endif
//                        //#ifdef use_3KEY
//                        //                            if (lights == 3) {
//                        //                                LED3 = 0;
//                        //                            }
//                        //#endif
//                        //                        }
//                        //                        }
//                    }
//                }
//            }
//        }
//    }
//    if (DimmerLightsIntr->Triac == true) {
//        DimmerLightsIntr->TriacTime++;
//        if (DimmerLightsIntr->TriacTime >= 5) {
//            DimmerLightsIntr->TriacTime = 0;
//            DimmerLightsIntr->Triac = false;
//
//#ifdef use_1KEY
//            if (lights == 1) {
//                Triac1 = 0;
//                ID_1KEY_0;
//                NOP();
//                NOP();
//            }
//#endif
//#ifdef use_2KEY
//            if (lights == 2) {
//                Triac2 = 0;
//                NOP();
//                NOP();
//            }
//#endif
//#ifdef use_3KEY
//            if (lights == 3) {
//                Triac3 = 0;
//                NOP();
//                NOP();
//            }
//#endif
//        }
//    } else {
//        if (DimmerLightsIntr->TriacFlag == true && DimmerLightsIntr->GO == false) {
//            DimmerLightsIntr->TriacCount++;
//            if (DimmerLightsIntr->TriacCount == 5) {//TriacCountValue
//                DimmerLightsIntr->TriacCount = 0;
//                DimmerLightsIntr->TriacFlag = false;
//                //                if (lights == 1) {
//                //                    ErrLED = ErrLED == true ? false : true;
//                //                }
//            }
//        }
//    }
//
//#endif
//#if Control_Method_Mosfet == 1
//
//    if (DimmerIntr->Start == true) {
//        DimmerIntr->Count++;
//        if (DimmerIntr->Count >= Dimmer_Maxum + 1) {
//            DimmerIntr->Count = 0;
//            DimmerIntr->Start = false;
//        }
//    }
//
//    if (DimmerIntr->GO == true) {
//        if (DimmerIntr->Count >= DimmerIntr->DimmingValue) {
//            DimmerIntr->GO = false;
//            DimmerIntr->Tune = true;
//
//            if (DimmerIntr->ControlStatus == true) {
//#ifdef use_1KEY
//                if (lights == 1) {
//                    Mosfet1 = false;
//                    //                    ID_1KEY_0;
//                }
//#endif
//#ifdef use_2KEY
//                else if (lights == 2) {
//                    Mosfet2 = false;
//                }
//#endif
//            }
//        }
//    } else {
//        if (DimmerIntr->Tune == true) {
//            DimmerIntr->Tune = false;
//            DimmerIntr->TuneTime++;
//            if (DimmerIntr->TuneTime >= DimmerIntr->TuneTimeValue) {
//                DimmerIntr->TuneTime = 0;
//                if (DimmerIntr->Dimming_Sw == true) {
//                    if (DimmerIntr->Dimming_Status == false) {
//                        if (DimmerIntr->DimmingValue < Dimmer_Maxum) {
//                            DimmerIntr->DimmingValue++;
//                        } else {
//                            DimmerIntr->Dimming_Status = true;
//                        }
//                    } else {
//                        if (DimmerIntr->DimmingValue > Dimmer_Minimum) {
//                            DimmerIntr->DimmingValue--;
//                        } else {
//                            DimmerIntr->Dimming_Status = false;
//                        }
//                    }
//                } else if (DimmerIntr->Dimming_RF == true) {
//                    if (DimmerIntr->DimmingValue < DimmerIntr->MaxmumValue) {
//                        DimmerIntr->DimmingValue++;
//                    } else if (DimmerIntr->DimmingValue > DimmerIntr->MaxmumValue) {
//                        DimmerIntr->DimmingValue--;
//                    } else {
//                        DimmerIntr->Dimming_RF = false;
//                    }
//                }
//            }
//        }
//    }
//#endif
//}

//******************************************************************************
//******************************************************************************
//******************************************************************************
//******************************************************************************

inline void DimmerLights_SelectPointer(char lights) {
#ifdef use_1KEY
    if (lights == 1) {
        DimmerLights = &DimmerLights1;
    }
#endif
#ifdef use_2KEY
    else if (lights == 2) {
        DimmerLights = &DimmerLights2;
    }
#endif
#ifdef use_3KEY
    else if (lights == 3) {
        DimmerLights = &DimmerLights3;
        NOP();
        NOP();
    }
#endif		
}
//******************************************************************************

void DimmerLights_Initialization() {
#ifdef use_1KEY
    setDimmerLights_Initialization(1);
#endif

#ifdef use_2KEY
    setDimmerLights_Initialization(2);
#endif

#ifdef use_3KEY
    setDimmerLights_Initialization(3);
#endif
    DimmerIntr_Initialization();
}
//******************************************************************************

void setDimmerLights_Initialization(char lights) {

    //    DimmerLights_SelectPointer(lights);
    //
    ////    DimmerLights->DimmingTimeValue = 7;
    //#if FlashMemory_use == 1
    //#if DimmerValue_SaveMemory == 1
    //    DimmerLights->MaxmumValue = getPercentValue(product->Data[(20 + lights)]);
    //#else
    //    DimmerLights->MaxmumValue = Dimmer_Maxum;
    //    DimmerLights->MinimumValue = Dimmer_Minimum;
    //#endif
    //#else
    //    DimmerLights->MaxmumValue = Dimmer_Maxum;
    //    DimmerLights->MinimumValue = Dimmer_Minimum;
    //#endif
    //
    //
    //#if Dimmable_Func == 1
    //#if Control_Method_Triac == 1
    //    DimmerLights->DimmingValue = DimmerLights->MinimumValue;
    //#endif
    //
    //#if Control_Method_Mosfet == 1
    //    DimmerLights->DimmingValue = DimmerLights->MaxmumValue;
    //#endif
    //
    //#else
    //#if Control_Method_Triac == 1
    //    DimmerLights->DimmingValue = DimmerLights->MaxmumValue;
    //#endif
    //
    //#if Control_Method_Mosfet == 1
    //    DimmerLights->DimmingValue = DimmerLights->MinimumValue;
    //#endif
    //#endif
}

//******************************************************************************

void setDimmerLights_SwOn(char sw) {
    char idle = 0;
#if Dimmable_Func == 1
    char dimmingStatus = 0;
    dimmingStatus = getDimmerIntr_Dimming_Sw(sw);
#endif

#if Switch_Class == 2
    if (idle == 0) {
        if (sw == 1) {
            idle = DimmerLights2.DimmingTrigger == true || DimmerIntr2.Dimming_Sw == true ? 1 : 0;
        } else if (sw == 2) {
            idle = DimmerLights1.DimmingTrigger == true || DimmerIntr1.Dimming_Sw == true ? 1 : 0;
        }
    }
#endif
#if Switch_Class == 3
    if (idle == 0) {
        if (sw == 1) {
            idle = DimmerLights2.DimmingTrigger == true || DimmerLights3.DimmingTrigger == true
                    || DimmerIntr2.Dimming_Sw == true || DimmerIntr3.Dimming_Sw == true ? 1 : 0;
        } else if (sw == 2) {
            idle = DimmerLights1.DimmingTrigger == true || DimmerLights3.DimmingTrigger == true
                    || DimmerIntr1.Dimming_Sw == true || DimmerIntr3.Dimming_Sw == true ? 1 : 0;
        } else if (sw == 3) {
            idle = DimmerLights1.DimmingTrigger == true || DimmerLights2.DimmingTrigger == true
                    || DimmerIntr1.Dimming_Sw == true || DimmerIntr2.Dimming_Sw == true ? 1 : 0;
        }
    }

#endif
    DimmerLights_SelectPointer(sw);
    if (idle == 0) {

        if (dimmingStatus == 0) {
            DimmerLights->SwFlag = true;
            if (DimmerLights->Status == false) {
                DimmerLights->Status = true;
                DimmerLights->Trigger = true;
                DimmerLights->Switch = true;
            } else {
                DimmerLights->Status = false;
            }
        } else {
            DimmerLights->DimmingTrigger = true;
            DimmerLights->DimmingSwitch = false;
        }
        setBuz(1, BuzzerOnOffTime);
    }
}
//*********************************************************

void setDimmerLights_SwOff(char sw) {

    DimmerLights_SelectPointer(sw);

    if (DimmerLights->SwFlag == true) {
        DimmerLights->SwFlag = false;
        if (DimmerLights->Status == true) {
            if (DimmerLights->DimmingSwFlag == true) {
                DimmerLights->DimmingSwFlag = false;

                DimmerLights->DimmingTrigger = true;
                DimmerLights->DimmingSwitch = false;
            }
        } else {
            DimmerLights->Trigger = true;
            DimmerLights->Switch = false;
        }
    }
}
//******************************************************************************

void setDimmerLights_DimmingOn(char sw) {
    //Condition
    //1.其他的開燈完成階段(overload判斷ok)
    //2.其他的燈未進入開燈階段
    //3.其他燈未在調光階段
    //4.本身如進入開燈階段需先完成開燈階段
    DimmerLights_SelectPointer(sw);
    if (DimmerLights->Trigger == false) {
        if (DimmerLights->SwFlag == true) {
            DimmerLights->Status = true;

            DimmerLights->DimmingSwFlag = true;
            DimmerLights->DimmingTrigger = true;
            DimmerLights->DimmingSwitch = true;
            //            ErrLED = ErrLED == true ? false : true;
        }
    }
}

//******************************************************************************

void DimmerLights_Main() {

#if OverLoad_use == 1
    if (Dimmer.LoadGO == true) {
        if (getLoad_OK() == 1 || getMain_All_Error_Status(0) != 0 || getMain_All_LightsStatus() == 0) {
            Dimmer.LoadGO = false;
        }
    }
#endif

#ifdef use_1KEY

    setDimmerLights_Main(1);

#if Dimmable_Func == 1
    DimmerLights_DimmingFunction(1);
#endif

#endif

#ifdef use_2KEY
    setDimmerLights_Main(2);
#if Dimmable_Func == 1
    DimmerLights_DimmingFunction(2);
#endif
#endif

#ifdef use_3KEY
    setDimmerLights_Main(3);
#endif
    //    DimmerLights_Close();
#if Properties_Product == 2
    DimmerLights_PIR_Control();
#endif

}
//******************************************************************************

void setDimmerLights_Main(char lights) {

    DimmerLights_SelectPointer(lights);
    if (DimmerLights->Trigger == true) {
        if (getDimmerLights_Allow_Condition(lights) == 0) {
            DimmerLights->Trigger = false;
            if (DimmerLights->Switch == true) {
                setDimmerLights_OnOff(lights, 1);
            } else {
                setDimmerLights_OnOff(lights, 0);
            }
        }
    } else {
        if (getMain_All_LightsStatus() == 1) {
            if (DimmerLights->DimmingTrigger == true) {
                if (getDimmerLights_Allow_Condition(lights) == 0) {
                    DimmerLights->DimmingTrigger = false;
                    if (DimmerLights->DimmingSwitch == true) {
                        setDimmerLights_Dimming(lights, 1);
                    } else {
                        setDimmerLights_Dimming(lights, 0);
                    }
                }
            }
        } else {
            if (DimmerLights->DimmingTrigger == true) {
                DimmerLights->DimmingTrigger = false;
            }
        }
    }
}

//******************************************************************************

void setDimmerLights_OnOff(char lights, char command) {

    if (command == 1) {

        setDimmerIntr_ControlStatus(lights, 1);

#if OverLoad_use == 1
        Dimmer.Load_Status = true;
        setDimmerLights_Line(lights);
#endif

#if Properties_Product == 2
        Dimmer.PIR_Open_Status = true;
#else
        setLED(lights, 0);
        setLED2(0);

#if DimmerValue_SaveMemory == 0
        //調光值在關燈後不記錄而且不存入記憶體，開燈後恢復最大值
        setDimmerIntr_DimmingValue(lights, Dimmer_Maxum);

#if CC2500_use == 1
        //RF set
        if (DimmerLights->DimmingRun == true) {
            DimmerLights->DimmingRun = false;
            setDimmerIntr_MaxmumValue(lights, getDimmerLights_PercentToValue(product->Data[20 + lights]));
            setDimmerIntr_Dimming_RF(lights, 1);
        } else {
            setDimmerIntr_MaxmumValue(lights, Dimmer_Maxum);
            setProductData((20 + lights), getDimmerLights_ValueToPercent(Dimmer_Maxum));
        }
#endif
#else

        //RF set
        if (DimmerLights->DimmingRun == true) {
            DimmerLights->DimmingRun = false;
            setDimmerIntr_MaxmumValue(lights, getDimmerLights_PercentToValue(product->Data[20 + lights]));
            setDimmerIntr_Dimming_RF(lights, 1);
        } else {
            setDimmerIntr_DimmingValue(lights, getDimmerLights_PercentToValue(product->Data[20 + lights]));
            //            setDimmerIntr_MaxmumValue(lights, getDimmerLights_PercentToValue(product->Data[20 + lights]));
            //            setProductData((20 + lights), getDimmerLights_ValueToPercent(Dimmer_Maxum));
        }

        if (lights == 1) {
#ifdef use_1KEY
            DimmerIntr1.TuneGO = true;
#endif
        } else if (lights == 2) {
#ifdef use_2KEY
            DimmerIntr2.TuneGO = true;
#endif
        }


#endif

#endif
    } else if (command == 0) {

        setDimmerIntr_ControlStatus(lights, 0);
#if OverLoad_use == 1
        Dimmer.Load_Status = false;
        setDimmerLights_Line(0);
#endif

#if DelayOff_use == 1
        if (getDelayOff_GO(lights) == 1) {
            setDelayOff_GO(lights, 0, 0);
        }
#endif

#if Properties_Product == 2
#else
        setLED(lights, 1);
        setLED2(1);

#if Control_Method_Mosfet == 1
#ifdef use_1KEY
        if (lights == 1) {
            Mosfet1 = false;
            //                    ID_1KEY_0;
        }
#endif
#ifdef use_2KEY
        else if (lights == 2) {
            Mosfet2 = false;
        }
#endif
#endif

#endif

    }

    setDimmerLights_DimmingClose();
    //set RF transmit data and allow transmit
    setRF_DimmerLights(lights, command);

    if (getCmd_Status(1) == 1) {
        if (getMain_All_LightsStatus() == 0) {
            setCmd_Status(1, 0);
            setProductData(11, 0);
            setProductData(17, 0);
            setTxData();
        }
    } else {
        setTxData();
    }
}

//*****************************************************************************

void setDimmerLights_Dimming(char lights, char status) {
    setDimmerIntr_Dimming_Sw(lights, status);
    if (status == 1) {
#if CC2500_use == 1
        setRF_TransceiveGO(0);
#endif
        setBuz(1, BuzzerOnOffTime);
    } else if (status == 0) {

#if OverLoad_use == 1
        Dimmer.Load_Status = false;
        setDimmerLights_Line(lights);
#endif
        char value = getDimmerIntr_DimmingValue(lights);
        setDimmerIntr_MaxmumValue(lights, value);
        setProductData((20 + lights), getDimmerLights_ValueToPercent(value));

        //#if DimmerValue_CloseLightsSave == 1
        //        setProductData((20 + lights), getDimmerLights_ValueToPercent(getDimmerIntr_DimmingValue(lights)));
        //#endif

#if DimmerValue_SaveMemory == 1
        setMemory_Modify(1);
#endif

        //set RF transmit data and allow transmit
        setRF_DimmerLights(lights, 1);
        setTxData();

    }
}
//******************************************************************************

char getDimmerLights_Allow_Condition(char lights) {
    char allow = 0;
    //Condition
    //1.其他的開燈完成階段(overload判斷ok)
    //2.其他的燈未進入開燈階段
    //3.其他燈未在調光階段
#if OverLoad_use == 1
    allow = getLoad_OK() == 0 && Dimmer.LoadGO == false ? 0 : 1;
#endif

#if Switch_Class == 2
    if (allow == 0) {
        if (lights == 1) {
            allow = DimmerLights2.DimmingTrigger == true || DimmerIntr2.Dimming_Sw == true ? 1 : 0;
        } else if (lights == 2) {
            allow = DimmerLights1.DimmingTrigger == true || DimmerIntr1.Dimming_Sw == true ? 1 : 0;
        }
    }
#endif
#if Switch_Class == 3
    if (allow == 0) {
        if (sw == 1) {
            idle = DimmerLights2.DimmingTrigger == true || DimmerLights3.TriggerAdj == true
                    || DimmerIntr2.Dimming_Sw == true || DimmerIntr3.Dimming_Sw == true ? 1 : 0;
        } else if (sw == 2) {
            idle = DimmerLights1.DimmingTrigger == true || DimmerLights3.TriggerAdj == true
                    || DimmerIntr1.Dimming_Sw == true || DimmerIntr3.Dimming_Sw == true ? 1 : 0;
        } else if (sw == 3) {
            idle = DimmerLights1.DimmingTrigger == true || DimmerLights2.DimmingTrigger == true
                    || DimmerIntr1.Dimming_Sw == true || DimmerIntr2.Dimming_Sw == true ? 1 : 0;
        }
    }
#endif

    return allow;
}

//*********************************************************

void setDimmerLights_Line(char lights) {
    Dimmer.LoadGO = true;
#ifdef use_1KEY
    DimmerLights1.Line = false;
    if (lights == 1 && lights != 0) {
        DimmerLights1.Line = true;
    }
#endif
#ifdef use_2KEY
    DimmerLights2.Line = false;
    if (lights == 2 && lights != 0) {
        DimmerLights2.Line = true;
    }
#endif
#ifdef use_3KEY
    DimmerLights3.Line = false;
    if (lights == 3 && lights != 0) {
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
///******************************************************************************

void setDimmerLights_Status(char lights, char command) {

    DimmerLights_SelectPointer(lights);
    DimmerLights->Status = command == 1 ? true : false;
}
//******************************************************************************

char getDimmerLights_Status(char lights) {
    DimmerLights_SelectPointer(lights);
    char status = DimmerLights->Status == true ? 1 : 0;
    return status;
}

void setDimmerLights_DimmingRun(char lights, char command) {
    DimmerLights_SelectPointer(lights);
    DimmerLights->DimmingRun = command == 1 ? true : false;
}
//*********************************************************

char getAll_DimmerLights_Trigger() {
    char status = 0;

#if Switch_Class == 3
    status = (DimmerLights1.Trigger == true || DimmerLights2.Trigger == true || DimmerLights3.Trigger == true) ? 1 : 0;
#endif

#if Switch_Class == 2
    status = (DimmerLights1.Trigger == true || DimmerLights2.Trigger == true) ? 1 : 0;
#endif

#if Switch_Class == 1
    status = (DimmerLights1.Trigger) ? 1 : 0;
#endif

    return status;
}

//*********************************************************
#if CC2500_use == 1

char getDimmerLights_PercentToValue(char value) {
#if Control_Method_Triac == 1
    float i = Dimmer_Minimum - Dimmer_Maxum;
    i /= 100;
    return (char) (((100 - value) * i) + Dimmer_Maxum);
#endif

#if Control_Method_Mosfet == 1
    float i = Dimmer_Maxum - Dimmer_Minimum;
    i /= 100;

    return (char) (Dimmer_Maxum - ((100 - value) * i));
#endif
}
//*********************************************************

char getDimmerLights_ValueToPercent(char value) {
#if Control_Method_Triac == 1
    float i = Dimmer_Minimum - Dimmer_Maxum;
    i /= 100;
    return (100 - (char) ((value - Dimmer_Maxum) / i));
#endif

#if Control_Method_Mosfet == 1
    float i = Dimmer_Maxum - Dimmer_Minimum;
    i /= 100;

    return (char) (100 - ((Dimmer_Maxum - value) / i));
#endif
}

#endif
//******************************************************************************

inline void Dimmer_Initialization() {

}
//******************************************************************************

char getDimmer_LoadGO() {
    char loadgo = Dimmer.LoadGO == true ? 1 : 0;
    return loadgo;
}
//******************************************************************************

char getDimmer_Load_Status() {
    char status = Dimmer.Load_Status == true ? 1 : 0;
    return status;
}

//******************************************************************************

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

                DimmerLights_SelectPointer(1);
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

                        DimmerLights_SelectPointer(1);
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

                        DimmerLights_SelectPointer(1);
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


//******************************************************************************
#if Control_Method_Triac == 1

#ifdef use_1KEY

inline void DimmerLights_TMR_1() {
    if (DimmerIntr1.Start == true) {
        DimmerIntr1.Count++;
        if (DimmerIntr1.Count >= Dimmer_Minimum + 1) {
            DimmerIntr1.Count = 0;
            DimmerIntr1.Start = false;
        }
    }

    if (DimmerIntr1.GO == true) {
        if (DimmerIntr1.Count >= DimmerIntr1.DimmingValue) {
            DimmerIntr1.GO = false;
            DimmerIntr1.Tune = true;

            if (DimmerIntr1.ControlStatus == true) {
                Triac1 = true;
                //                    ID_1KEY_0;                
            }
        }
    } else {
        if (DimmerIntr1.Tune == true) {
            DimmerIntr1.Tune = false;
            DimmerIntr1.TuneTime++;
            if (DimmerIntr1.TuneTime >= DimmerIntr1.TuneTimeValue) {
                DimmerIntr1.TuneTime = 0;
                if (DimmerIntr1.Dimming_Sw == true) {
                    if (DimmerIntr1.Dimming_Status == false) {
                        if (DimmerIntr1.DimmingValue > Dimmer_Maxum) {
                            DimmerIntr1.DimmingValue--;
                        } else {
                            DimmerIntr1.Dimming_Status = true;
                        }
                    } else {
                        if (DimmerIntr1.DimmingValue < Dimmer_Minimum) {
                            DimmerIntr1.DimmingValue++;
                        } else {
                            DimmerIntr1.Dimming_Status = false;
                        }
                    }
                } else if (DimmerIntr1.Dimming_RF == true) {
                    if (DimmerIntr1.DimmingValue > DimmerIntr1.MaxmumValue) {
                        DimmerIntr1.DimmingValue--;
                    } else if (DimmerIntr1.DimmingValue < DimmerIntr1.MaxmumValue) {
                        DimmerIntr1.DimmingValue++;
                    } else {
                        DimmerIntr1.Dimming_RF = false;
                    }
                }
            }
        }
    }
    if (Triac1 == true) {
        if (DimmerIntr1.Count >= Dimmer_Minimum - 10) {
            Triac1 = false;
            //            ID_1KEY_0;
        }
    }
}

inline void DimmerLights_IOC_1() {

#if PIR_use == 1
    if (DimmerReference1 == true) {
        if (Dimmer.PIR_DimmerSignal == true) {
            Dimmer.PIR_DimmerSignal = false;
        }
    } else {
        if (Dimmer.PIR_DimmerSignal == false) {
            Dimmer.PIR_DimmerSignal = true;

            if (DimmerIntr1.Start == false) {
                DimmerIntr1.Start = true;
                DimmerIntr1.GO = true;
            }
        }
    }
#else
    if (DimmerIntr1.Start == false && DimmerReference1 == true) {
        DimmerIntr1.Start = true;
        DimmerIntr1.GO = true;
    }

#endif
}

#endif

#ifdef use_2KEY

inline void DimmerLights_TMR_2() {

}

inline void DimmerLights_IOC_2() {

}
#endif


#endif

#if Control_Method_Mosfet == 1

#ifdef use_1KEY

inline char Division(char value, char num) {
    char result = (char) (value / num);
    return result;
}

inline void DimmerLights_TMR_1() {

    if (DimmerIntr1.Start == true) {
        DimmerIntr1.Count++;

        if (DimmerIntr1.Count == DimmerIntr1.TuneEnd) {
            DimmerIntr1.Count = 0;
            DimmerIntr1.Start = false;
        }

#if Dimmer_Trigger_Mode == 3

        //        if (DimmerIntr1.Count == DimmerIntr1.TuneValue) {
        //            //            DimmerIntr1.Trigger1 = false;
        //            //            DimmerIntr1.Trigger2 = true;
        //            if (DimmerIntr1.ControlStatus == true) {
        //                Mosfet1 = true;
        //                //                ID_1KEY_1;
        //            }
        //        }


        if (DimmerIntr1.Count == DimmerIntr1.TuneValue2) {
            if (DimmerIntr1.ControlStatus == true) {
                Mosfet1 = false;
            }
        }


        if (DimmerIntr1.Count == DimmerIntr1.TuneValue3) {
            if (DimmerIntr1.ControlStatus == true) {
                Mosfet1 = true;
            }
        }
#endif

        if (DimmerIntr1.Count == DimmerIntr1.TuneValue4) {
            if (DimmerIntr1.ControlStatus == true) {
                Mosfet1 = false;
            }
            //            DimmerIntr1.Count = 0;
            //            DimmerIntr1.Start = false;
        }

    } else {
        if (DimmerIntr1.GO == true) {
            DimmerIntr1.Count++;
            if (DimmerIntr1.Count == TuneTime1) {
                DimmerIntr1.Count = 0;
                DimmerIntr1.GO = false;
                DimmerIntr1.Start = true;

                if (DimmerIntr1.ControlStatus == true) {
                    Mosfet1 = true;
                }
            }
        }
    }
    /*
    #if Dimmable_Func == 1
        if (DimmerIntr1.Tune == true) {
            DimmerIntr1.Tune = false;
            DimmerIntr1.TuneTime++;
            if (DimmerIntr1.TuneTime >= DimmerIntr1.TuneTimeValue) {
                DimmerIntr1.TuneTime = 0;
                DimmerIntr1.TuneGO = true;
                if (DimmerIntr1.Dimming_Sw == true) {
                    if (DimmerIntr1.Dimming_Status == false) {
                        if (DimmerIntr1.DimmingValue < Dimmer_Maxum) {
                            DimmerIntr1.DimmingValue++;
                        } else {
                            DimmerIntr1.Dimming_Status = true;
                        }
                    } else {
                        if (DimmerIntr1.DimmingValue > Dimmer_Minimum) {
                            DimmerIntr1.DimmingValue--;
                        } else {
                            DimmerIntr1.Dimming_Status = false;
                        }
                    }
                } else if (DimmerIntr1.Dimming_RF == true) {
                    if (DimmerIntr1.DimmingValue < DimmerIntr1.MaxmumValue) {
                        DimmerIntr1.DimmingValue++;
                    } else if (DimmerIntr1.DimmingValue > DimmerIntr1.MaxmumValue) {
                        DimmerIntr1.DimmingValue--;
                    } else {
                        DimmerIntr1.Dimming_RF = false;
                    }
                }
            }
        }
    #endif
     */
}

inline void DimmerLights_IOC_1() {

#if Dimmer_Trigger_Mode == 1

    if (DimmerIntr1.Start == false) {
        DimmerIntr1.Start = true;
        DimmerIntr1.Count = 0;

        if (DimmerIntr1.ControlStatus == true) {
            DimmerIntr1.Trigger4 = true;
            Mosfet1 = true;
        }
    }
#elif Dimmer_Trigger_Mode == 3
    if (DimmerIntr1.Start == false && DimmerIntr1.GO == false) {

        if (DimmerReference1 != DimmerIntr1.Status) {
            //            ErrLED = ErrLED == true ? false : true;
            //            DimmerIntr1.Start = true;
            DimmerIntr1.Count = 0;
            DimmerIntr1.GO = true;

            if (DimmerIntr1.Dimming_Sw == true || DimmerIntr1.Dimming_RF == true) {
                DimmerIntr1.Tune = true;
            }

            if (DimmerIntr1.TuneGO == true) {
                DimmerIntr1.TuneGO = false;

                //                DimmerIntr1.TuneValue = TuneValue1;
                DimmerIntr1.TuneValue2 = Division(DimmerIntr1.DimmingValue, 2);
                DimmerIntr1.TuneValue3 = DimmerIntr1.TuneValue2 + (TotalCount - DimmerIntr1.DimmingValue);
                DimmerIntr1.TuneValue4 = DimmerIntr1.TuneValue3 + DimmerIntr1.TuneValue2;
                DimmerIntr1.TuneEnd = DimmerIntr1.TuneValue4 + 1;
            }
#if Properties_Keys == 1
#if Properties_Neutral == 0
            //            DimmerIntr1.Status = false;
            DimmerIntr1.Status = DimmerReference1 == true ? true : false;
#else
            DimmerIntr1.Status = DimmerReference1 == true ? true : false;
#endif
#elif Properties_Keys == 2
            DimmerIntr1.Status = DimmerReference1 == true ? true : false;
#endif
        }
        //        if (DimmerIntr1.ControlStatus == true) {
        //            DimmerIntr1.Trigger1 = true;
        //        }
    }
    //    if (DimmerReference1 == true) {
    //        if (Dimmer.PIR_DimmerSignal == true) {
    //            Dimmer.PIR_DimmerSignal = false;
    //        }
    //    } else {
    //        if (Dimmer.PIR_DimmerSignal == false) {
    //            Dimmer.PIR_DimmerSignal = true;
    //
    //            if (DimmerIntr1.Start == false) {
    //                DimmerIntr1.Start = true;
    //                //                DimmerIntr1.GO = true;
    //                if (DimmerIntr1.ControlStatus == true) {
    //                    Mosfet1 = true;
    //                }
    //            }
    //        }
    //    }

#endif
}

#endif


#ifdef use_2KEY

inline void DimmerLights_TMR_2() {

    if (DimmerIntr2.Start == true) {
        DimmerIntr2.Count++;

        if (DimmerIntr2.Count == DimmerIntr2.TuneEnd) {
            DimmerIntr2.Count = 0;
            DimmerIntr2.Start = false;
        }

#if Dimmer_Trigger_Mode == 3

        //        if (DimmerIntr2.Count == DimmerIntr2.TuneValue) {
        //            //            DimmerIntr2.Trigger1 = false;
        //            //            DimmerIntr2.Trigger2 = true;
        //            if (DimmerIntr2.ControlStatus == true) {
        //                Mosfet2 = true;
        //                //                ID_1KEY_1;
        //            }
        //        }


        if (DimmerIntr2.Count == DimmerIntr2.TuneValue2) {
            if (DimmerIntr2.ControlStatus == true) {
                Mosfet2 = false;
            }
        }


        if (DimmerIntr2.Count == DimmerIntr2.TuneValue3) {
            if (DimmerIntr2.ControlStatus == true) {
                Mosfet2 = true;
            }
        }
#endif

        if (DimmerIntr2.Count == DimmerIntr2.TuneValue4) {
            if (DimmerIntr2.ControlStatus == true) {
                Mosfet2 = false;
            }
            //            DimmerIntr2.Count = 0;
            //            DimmerIntr2.Start = false;
        }

    } else {
        if (DimmerIntr2.GO == true) {
            DimmerIntr2.Count++;
            if (DimmerIntr2.Count == TuneTime1) {
                DimmerIntr2.Count = 0;
                DimmerIntr2.GO = false;
                DimmerIntr2.Start = true;

                if (DimmerIntr2.ControlStatus == true) {
                    Mosfet2 = true;
                }
            }
        }
    }


    //    if (DimmerIntr2.Tune == true) {
    //        DimmerIntr2.Tune = false;
    //        DimmerIntr2.TuneTime++;
    //        if (DimmerIntr2.TuneTime >= DimmerIntr2.TuneTimeValue) {
    //            DimmerIntr2.TuneTime = 0;
    //            DimmerIntr2.TuneGO = true;
    //            if (DimmerIntr2.Dimming_Sw == true) {
    //                if (DimmerIntr2.Dimming_Status == false) {
    //                    if (DimmerIntr2.DimmingValue < Dimmer_Maxum) {
    //                        DimmerIntr2.DimmingValue++;
    //                    } else {
    //                        DimmerIntr2.Dimming_Status = true;
    //                    }
    //                } else {
    //                    if (DimmerIntr2.DimmingValue > Dimmer_Minimum) {
    //                        DimmerIntr2.DimmingValue--;
    //                    } else {
    //                        DimmerIntr2.Dimming_Status = false;
    //                    }
    //                }
    //            } else if (DimmerIntr2.Dimming_RF == true) {
    //                if (DimmerIntr2.DimmingValue < DimmerIntr2.MaxmumValue) {
    //                    DimmerIntr2.DimmingValue++;
    //                } else if (DimmerIntr2.DimmingValue > DimmerIntr2.MaxmumValue) {
    //                    DimmerIntr2.DimmingValue--;
    //                } else {
    //                    DimmerIntr2.Dimming_RF = false;
    //                }
    //            }
    //        }
    //    }
}

inline void DimmerLights_IOC_2() {
#if Dimmer_Trigger_Mode == 1
    if (DimmerIntr2.Start == false) {
        DimmerIntr2.Start = true;
        DimmerIntr2.GO = true;

        if (DimmerIntr2.ControlStatus == true) {
            DimmerIntr2.Trigger4 = true;
            Mosfet2 = true;
            //                ID_1KEY_1;
        }
    }

#elif Dimmer_Trigger_Mode == 3

    if (DimmerIntr2.Start == false && DimmerIntr2.GO == false) {

        if (DimmerReference1 != DimmerIntr2.Status) {
            //            ErrLED = ErrLED == true ? false : true;
            //            DimmerIntr2.Start = true;
            DimmerIntr2.Count = 0;
            DimmerIntr2.GO = true;

            if (DimmerIntr2.Dimming_Sw == true || DimmerIntr2.Dimming_RF == true) {
                DimmerIntr2.Tune = true;
            }

            if (DimmerIntr2.TuneGO == true) {
                DimmerIntr2.TuneGO = false;

                //                DimmerIntr1.TuneValue = TuneValue1;
                DimmerIntr2.TuneValue2 = Division(DimmerIntr2.DimmingValue, 2);
                DimmerIntr2.TuneValue3 = DimmerIntr2.TuneValue2 + (TotalCount - DimmerIntr2.DimmingValue);
                DimmerIntr2.TuneValue4 = DimmerIntr2.TuneValue3 + DimmerIntr2.TuneValue2;
                DimmerIntr2.TuneEnd = DimmerIntr2.TuneValue4 + 1;
            }
#if Properties_Keys == 1
#if Properties_Neutral == 0
            //            DimmerIntr1.Status = false;
            DimmerIntr2.Status = DimmerReference1 == true ? true : false;
#else
            DimmerIntr2.Status = DimmerReference1 == true ? true : false;
#endif
#elif Properties_Keys == 2
            DimmerIntr2.Status = DimmerReference1 == true ? true : false;
#endif
        }
        //        if (DimmerIntr2.ControlStatus == true) {
        //            DimmerIntr2.Trigger1 = true;
        //        }
    }

    //    if (DimmerIntr2.Start == false) {
    //        DimmerIntr2.Start = true;
    //        DimmerIntr2.Count = 0;
    //
    //        if (DimmerIntr2.ControlStatus == true) {
    //            DimmerIntr2.Trigger1 = true;
    //        }
    //    }
#endif
}


#endif
#endif

//******************************************************************************

void setDimmerLights_DimmingClose() {
#ifdef use_1KEY
    setDimmerIntr_Dimming_Sw(1, 0);
#endif

#ifdef use_2KEY
    setDimmerIntr_Dimming_Sw(2, 0);
#endif

#ifdef use_3KEY
    setDimmerIntr_Dimming_Sw(3, 0);
#endif
}
//******************************************************************************

void DimmerLights_DimmingFunction(char lights) {
#ifdef use_1KEY
    if (lights == 1) {
        if (DimmerIntr1.Tune == true) {
            DimmerIntr1.Tune = false;
            DimmerIntr1.TuneTime++;
            if (DimmerIntr1.TuneTime >= DimmerIntr1.TuneTimeValue) {
                DimmerIntr1.TuneTime = 0;
                DimmerIntr1.TuneGO = true;
                if (DimmerIntr1.Dimming_Sw == true) {
                    if (DimmerIntr1.Dimming_Status == false) {
                        if (DimmerIntr1.DimmingValue < Dimmer_Maxum) {
                            DimmerIntr1.DimmingValue++;
                        } else {
                            DimmerIntr1.Dimming_Status = true;
                        }
                    } else {
                        if (DimmerIntr1.DimmingValue > Dimmer_Minimum) {
                            DimmerIntr1.DimmingValue--;
                        } else {
                            DimmerIntr1.Dimming_Status = false;
                        }
                    }
                } else if (DimmerIntr1.Dimming_RF == true) {
                    if (DimmerIntr1.DimmingValue < DimmerIntr1.MaxmumValue) {
                        DimmerIntr1.DimmingValue++;
                    } else if (DimmerIntr1.DimmingValue > DimmerIntr1.MaxmumValue) {
                        DimmerIntr1.DimmingValue--;
                    } else {
                        DimmerIntr1.Dimming_RF = false;
                    }
                }
            }
        }
    }
#endif

#ifdef use_2KEY
    if (lights == 2) {
        if (DimmerIntr2.Tune == true) {
            DimmerIntr2.Tune = false;
            DimmerIntr2.TuneTime++;
            if (DimmerIntr2.TuneTime >= DimmerIntr2.TuneTimeValue) {
                DimmerIntr2.TuneTime = 0;
                DimmerIntr2.TuneGO = true;
                if (DimmerIntr2.Dimming_Sw == true) {
                    if (DimmerIntr2.Dimming_Status == false) {
                        if (DimmerIntr2.DimmingValue < Dimmer_Maxum) {
                            DimmerIntr2.DimmingValue++;
                        } else {
                            DimmerIntr2.Dimming_Status = true;
                        }
                    } else {
                        if (DimmerIntr2.DimmingValue > Dimmer_Minimum) {
                            DimmerIntr2.DimmingValue--;
                        } else {
                            DimmerIntr2.Dimming_Status = false;
                        }
                    }
                } else if (DimmerIntr2.Dimming_RF == true) {
                    if (DimmerIntr2.DimmingValue < DimmerIntr2.MaxmumValue) {
                        DimmerIntr2.DimmingValue++;
                    } else if (DimmerIntr2.DimmingValue > DimmerIntr2.MaxmumValue) {
                        DimmerIntr2.DimmingValue--;
                    } else {
                        DimmerIntr2.Dimming_RF = false;
                    }
                }
            }
        }
    }
#endif
}
//******************************************************************************
#if PIR_use == 1

void DimmerLights_PIR_Control() {

    if (Dimmer.PIR_Trigger == true) {
        Dimmer.PIR_Trigger = false;
        if (Dimmer.PIR_Sw == true) {

            if (getDimmerLights_Status(1) == 0) {
                setDimmerIntr_DimmingValue(1, Dimmer_Minimum);
                setDimmerLights_SwOn(1); //key on function
                setDimmerLights_SwOff(1); //key on function
            } else {
                if (Dimmer.PIR_Lights_Status == true) {
                    Dimmer.PIR_Lights_Status = false;
                    Dimmer.PIR_Close_Status = false;
                    DimmerLights1.Trigger = false;
                    //                    DimmerLights1.
                    setDimmerIntr_MaxmumValue(1, Dimmer_Maxum);
                    setDimmerIntr_Dimming_RF(1, 1);
                }
            }
        } else if (Dimmer.PIR_Sw == false) {
            if (getDimmerLights_Status(1) == 1) {
                if (Dimmer.PIR_Lights_Status == false) {
                    Dimmer.PIR_Lights_Status = true;
                    setDimmerIntr_MaxmumValue(1, Dimmer_Medium);
                    setDimmerIntr_Dimming_RF(1, 1);
                } else {
                    Dimmer.PIR_Lights_Status = false;
                    setDimmerIntr_MaxmumValue(1, Dimmer_Minimum);
                    setDimmerIntr_Dimming_RF(1, 1);
                    Dimmer.PIR_Close_Status = true;
                }
            }
        }
    }
    if (Dimmer.PIR_Open_Status == true) {
        Dimmer.PIR_Open_Status = false;
        setDimmerIntr_MaxmumValue(1, Dimmer_Maxum);
        setDimmerIntr_Dimming_RF(1, 1);
    }
    if (Dimmer.PIR_Close_Status == true && DimmerIntr1.Dimming_RF == false) {
        Dimmer.PIR_Close_Status = false;
        setDimmerLights_SwOn(1); //key on function
        setDimmerLights_SwOff(1); //key on function
    }
}

#endif




//end
#endif




