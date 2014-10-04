
// Includes
#include "Select_File.h"


#if Switch_use == 1

#ifdef TTPW

void TouchPower() {
    while (!TTPW)
        TTPW = 1;
}
#endif
//*********************************************************

void SwPointSelect(char sw) {

#ifdef use_1KEY
    if (sw == 1) {
        Sw = &Sw1;
    }
#endif
#ifdef use_2KEY
    else if (sw == 2) {
        Sw = &Sw2;
    }
#endif
#ifdef use_3KEY
    else if (sw == 3) {
        Sw = &Sw3;
    }
#endif
}
//*********************************************************

void Switch_Initialization() {
    TouchPower();
#ifdef use_1KEY
    WPUB1 = 0;
#else
#ifdef use_2KEY
    WPUB1 = 0;
#endif
#endif


#ifdef use_1KEY
    setSw_Initialization(1);
#endif
#ifdef use_2KEY
    setSw_Initialization(2);
#endif
#ifdef use_3KEY
    setSw_Initialization(3);
#endif

}
//*********************************************************

void Switch_Main() {
#ifdef use_1KEY
    setSw_Main(1);
#endif

#ifdef use_2KEY
    setSw_Main(2);
#endif

#ifdef use_3KEY
    setSw_Main(3);
#endif
    //Sw_Detect();
}
//*********************************************************

void setSw_Initialization(char sw) {
    setLED(sw, 1);
#if Switch_Class == 1 && Dimmer_use == 1
    setLED(sw + 1, 1);
#endif
}
//*********************************************************

void setSw_Enable(char command) {

#ifdef use_1KEY
    SwPointSelect(1);
    Sw->Enable = command;
#endif

#ifdef use_2KEY
    SwPointSelect(2);
    Sw->Enable = command;
#endif

#ifdef use_3KEY
    SwPointSelect(3);
    Sw->Enable = command;
#endif

}
//*********************************************************

void setSw_Status(char sw, char command) {
    SwPointSelect(sw);
    Sw->Status = command;
}
//*********************************************************

void setSw_Main(char sw) {
    if (Sw->Enable) {
        SwPointSelect(sw);
#if	Switch_Class == 3
        if (sw == 1) {
            Sw->Touch = (Key1) ? 1 : 0;
        } else if (sw == 2) {
            Sw->Touch = (Key2) ? 1 : 0;
        } else if (sw == 3) {
            Sw->Touch = (Key3) ? 1 : 0;
        }
#endif

#if Switch_Class == 2
        if (sw == 1) {
            Sw->Touch = (Key1_1 || Key1_2) ? 1 : 0;
        } else if (sw == 2) {
            Sw->Touch = (Key2_1 || Key2_2) ? 1 : 0;
        }
#endif

#if Switch_Class == 1	
        Sw->Touch = (Key1_1 || Key1_2 || Key1_3 || Key1_4) ? 1 : 0;
#endif


        if (Sw->Touch) {
            if (!Sw->Debounce) {
                Sw->DebounceTime++;
                if (Sw->DebounceTime >= DebounceTimeValue) {
                    Sw->DebounceTime = 0;
                    Sw->Debounce = 1;
#if Dimmer_use == 1

                    Sw_DimmerOnFunc(sw); //key on function

#endif
                }
            } else {
                if (!Sw->Hold1) {
                    Sw->Hold1Time++;
                    if (Sw->Hold1Time >= Hold1TimeValue) {
                        Sw->Hold1Time = 0;
                        Sw->Hold1 = 1;
#if Dimmer_use == 1 
#if Dimmable_Func == 1
                        Sw_DimmerAdjFunc(sw); //key on function
#endif
#endif
                    }
                } else {
                    if (!Sw->Hold2) {
                        Sw->Hold2Time++;
                        if (Sw->Hold2Time >= Hold2TimeValue) {
                            Sw->Hold2Time = 0;
                            Sw->Hold2 = 1;

#if Dimmer_use == 1
#if CC2500_use == 1
                            setRF_Learn(1, 1);
#endif
                            if (myMain->First) {
                                setBuz(2, BuzzerOnOffTime);
                            }
#endif
                        }
                    } else {
                        if (!Sw->Hold3) {
                            Sw->Hold3Time++;
                            if (Sw->Hold3Time >= Hold3TimeValue)//ms
                            {
                                Sw->Hold3Time = 0;
                                Sw->Hold3 = 1;
#if Dimmer_use == 1
#if CC2500_use == 1
                                setRF_Learn(1, 0);
#endif
#endif
                            }
                        }
                    }
                }
            }
        } else {
            if (Sw->Debounce) {
                Sw->DebounceTime++;
                if (Sw->DebounceTime >= DebounceTimeValue) {
                    Sw->DebounceTime = 0;
                    Sw->Debounce = 0;
                    Sw->Hold1Time = 0;
                    Sw->Hold1 = 0;
                    Sw->Hold2Time = 0;
                    Sw->Hold2 = 0;
                    Sw->Hold3Time = 0;
                    Sw->Hold3 = 0;
#if Dimmer_use == 1

                    Sw_DimmerOffFunc(sw); //key on function

#endif

#if CC2500_use == 1
                    setRF_Learn(1, 0);
#endif
                }
            }
        }
    }
}
//*********************************************************

void Sw_DimmerOnFunc(char sw) {
    char Idle = 1;
#if Switch_Class == 3
    if (sw == 1) {
        Idle = (DimmerLights22->AdjGo || DimmerLights33->AdjGo) ? 0 : 1;
    } else if (sw == 2) {
        Idle = (DimmerLights11->AdjGo || DimmerLights33->AdjGo) ? 0 : 1;
    } else if (sw == 3) {
        Idle = (DimmerLights11->AdjGo || DimmerLights22->AdjGo) ? 0 : 1;
    }
#endif

#if Switch_Class == 2
    if (sw == 1) {
        Idle = (DimmerLights22->AdjGo) ? 0 : 1;
    } else if (sw == 2) {
        Idle = (DimmerLights11->AdjGo) ? 0 : 1;
    }
#endif

    if (Idle) {
        Sw->Flag = 1;
        setBuz(1, BuzzerOnOffTime);
        if (!Sw->Status) {
            Sw->Status = 1;
            setRFSW_Status(sw, 1);

            setDimmerLights_Trigger(sw, 1);
            setDimmerLights_Switch(sw, 1);

            setRF_DimmerLights(sw, Sw->Status);
            setTxData(1);

        } else {
            Sw->Status = 0;
            setRFSW_Status(sw, Sw->Status);
        }
    }
}
//*********************************************************

void Sw_DimmerOffFunc(char sw) {
    if (Sw->Flag) {
        Sw->Flag = 0;
        if (Sw->Status) {
            if (Sw->Adj) {
                Sw->Adj = 0;
                setDimmerLights_TriggerAdj(sw, 1);
                setDimmerLights_AdjGo(sw, 0);

                setProductData(17, product->Data[26 + sw]);
                setRF_DimmerLights(sw, Sw->Status);
                setTxData(1);

            }
        } else {
            setDimmerLights_Trigger(sw, 1);
            setDimmerLights_Switch(sw, 0);

            setDelayOff_GO(sw, 0, 0);
            setRF_DimmerLights(sw, Sw->Status);
            setTxData(1);

        }
    }
}
//*********************************************************

void Sw_DimmerAdjFunc(char sw) {
    char Idle = 1;
#if Switch_Class == 3
    if (sw == 1) {
        Idle = (DimmerLights22->AdjGo || DimmerLights33->AdjGo) ? 0 : 1;
    } else if (sw == 2) {
        Idle = (DimmerLights11->AdjGo || DimmerLights33->AdjGo) ? 0 : 1;
    } else if (sw == 3) {
        Idle = (DimmerLights11->AdjGo || DimmerLights22->AdjGo) ? 0 : 1;
    }
#endif

#if Switch_Class == 2
    if (sw == 1) {
        Idle = (DimmerLights22->AdjGo) ? 0 : 1;
    } else if (sw == 2) {
        Idle = (DimmerLights11->AdjGo) ? 0 : 1;
    }
#endif

    if (Idle) {
        if (Sw->Flag) {
            Sw->Adj = 1;
            Sw->Status = 1;
            setRFSW_Status(sw, 1);

            setDimmerLights_TriggerAdj(sw, 1);
            setDimmerLights_AdjGo(sw, 1);

        }
    }
}
//*********************************************************

void Sw_Detect() {
    if (!getLoad_ERROR() && !getTemp_ERROR() && !getPF_ERROR() && myMain->SelfTest) {
#ifdef use_1KEY
        SwPointSelect(1);
        if (Sw->Enable == 0) {
            Sw->Enable = 1;
        }
#endif

#ifdef use_2KEY
        SwPointSelect(2);
        if (Sw->Enable == 0) {
            Sw->Enable = 1;
        }
#endif

#ifdef use_3KEY
        SwPointSelect(3);
        if (Sw->Enable == 0) {
            Sw->Enable = 1;
        }
#endif

    }
}
#endif