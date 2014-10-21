
// Includes
#include "Select_File.h"


#if Switch_use == 1

#ifdef TTPW

void TouchPower() {
    while (TTPW == false && myMain.Timeout == false) {
        TTPW = true;
        Timeout_Counter();
    }
    set_TimeoutCleared();
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

inline void Switch_Initialization() {
    TouchPower();
#ifdef use_1KEY
    WPUB1 = false;
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

inline void Switch_Main() {
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
    SwPointSelect(sw);
    if (Sw->Enable == true) {
#if	Switch_Class == 3
        if (sw == 1) {
            Sw->Touch = (Key1 == true) ? true : false;
        } else if (sw == 2) {
            Sw->Touch = (Key2 == true) ? true : false;
        } else if (sw == 3) {
            Sw->Touch = (Key3 == true) ? true : false;
        }
#endif

#if Switch_Class == 2
        if (sw == 1) {
            Sw->Touch = (Key1_1 == true || Key1_2 == true) ? true : false;
        } else if (sw == 2) {
            Sw->Touch = (Key2_1 == true || Key2_2 == true) ? true : false;
        }
#endif

#if Switch_Class == 1	
        Sw->Touch = (Key1_1 == true || Key1_2 == true || Key1_3 == true || Key1_4 == true) ? true : false;
#endif
        if (Sw->Touch == true) {
            if (Sw->Debounce == false) {
                Sw->DebounceTime++;
                if (Sw->DebounceTime >= DebounceTimeValue) {
                    Sw->DebounceTime = 0;
                    Sw->Debounce = true;

#if Dimmer_use == 1
                    Sw_DimmerOnFunc(sw); //key on function
#else
                    if (Sw->Status == false) {
                        Sw->Status = true;
                        if (sw == 1) {
                            setLED(1, 0);
                        } else if (sw == 2) {
                            setLED(2, 0);
                        } else if (sw == 3) {
                            setLED(3, 0);
                        }
                    } else {
                        Sw->Status = false;
                        if (sw == 1) {
                            setLED(1, 1);
                        } else if (sw == 2) {
                            setLED(2, 1);
                        } else if (sw == 3) {
                            setLED(3, 1);
                        }
                    }

                    setBuz(1, 100);
#endif
                }
            } else {
                if (Sw->Hold1 == false) {
                    Sw->Hold1Time++;
                    if (Sw->Hold1Time >= Hold1TimeValue) {
                        Sw->Hold1Time = 0;
#if Dimmer_use == 1 
#if Dimmable_Func == 1
                        Sw_DimmerAdjFunc(sw); //key on function
#endif
#endif
                    }
                } else {
                    if (Sw->Hold2 == false) {
                        Sw->Hold2Time++;
                        if (Sw->Hold2Time >= Hold2TimeValue) {
                            Sw->Hold2Time = 0;
                            Sw->Hold2 = true;
#if Dimmer_use == 1
#if CC2500_use == 1
                            setRF_Learn(1);
#endif
                            if (myMain.First == true) {
                                setBuz(2, BuzzerOnOffTime);
                            }
#endif
                        }
                    } else {
                        if (Sw->Hold3 == false) {
                            Sw->Hold3Time++;
                            if (Sw->Hold3Time >= Hold3TimeValue) {//ms
                                Sw->Hold3Time = 0;
                                Sw->Hold3 = true;
#if Dimmer_use == 1
#if CC2500_use == 1
                                setRF_Learn(0);
#endif
#endif
                            }
                        }
                    }
                }
            }
        } else {
            if (Sw->Debounce == true) {
                Sw->DebounceTime++;
                if (Sw->DebounceTime >= DebounceTimeValue) {
                    Sw->DebounceTime = 0;
                    Sw->Debounce = false;
                    Sw->Hold1Time = 0;
                    Sw->Hold1 = false;
                    Sw->Hold2Time = 0;
                    Sw->Hold2 = false;
                    Sw->Hold3Time = 0;
                    Sw->Hold3 = false;
#if Dimmer_use == 1
                    Sw_DimmerOffFunc(sw); //key on function
#endif
#if CC2500_use == 1
                    setRF_Learn(0);
#endif
                }
            }
        }
    }
}
//*********************************************************

void Sw_DimmerOnFunc(char sw) {
    char Idle = 1;
#if Dimmer_use == 1

#if Switch_Class == 3
    if (sw == 1) {
        Idle = (DimmerLights2.AdjGo == true || DimmerLights3.AdjGo == true) ? 0 : 1;
    } else if (sw == 2) {
        Idle = (DimmerLights1.AdjGo == true || DimmerLights3.AdjGo == true) ? 0 : 1;
    } else if (sw == 3) {
        Idle = (DimmerLights1.AdjGo == true || DimmerLights2.AdjGo == true) ? 0 : 1;
    }
#endif

#if Switch_Class == 2
    if (sw == 1) {
        Idle = (DimmerLights2.AdjGo == true) ? 0 : 1;
    } else if (sw == 2) {
        Idle = (DimmerLights1.AdjGo == true) ? 0 : 1;
    }
#endif
#endif
    if (Idle == 1) {
        Sw->Flag = 1;
        setBuz(1, BuzzerOnOffTime);
        if (Sw->Status == false) {
            Sw->Status = true;
            setRFSW_Status(sw, 1);

            setDimmerLights_Trigger(sw, 1);
            setDimmerLights_Switch(sw, 1);

            setRF_DimmerLights(sw, Sw->Status);
            setTxData();

        } else {
            Sw->Status = false;
            setRFSW_Status(sw, Sw->Status);
        }
    }
}
//*********************************************************

void Sw_DimmerOffFunc(char sw) {
    if (Sw->Flag == true) {
        Sw->Flag = false;
        if (Sw->Status == true) {
            if (Sw->Adj == true) {
                Sw->Adj = false;
                setDimmerLights_TriggerAdj(sw, 1);
                setDimmerLights_AdjGo(sw, 0);

                setProductData(17, product->Data[26 + sw]);
                setRF_DimmerLights(sw, Sw->Status);
                setTxData();

            }
        } else {
            setDimmerLights_Trigger(sw, 1);
            setDimmerLights_Switch(sw, 0);

            setDelayOff_GO(sw, 0, 0);
            setRF_DimmerLights(sw, Sw->Status);
            setTxData();

        }
    }
}
//*********************************************************

void Sw_DimmerAdjFunc(char sw) {
    char Idle = 1;
#if Dimmer_use == true
#if Switch_Class == 3
    if (sw == 1) {
        Idle = (DimmerLights2.AdjGo == true || DimmerLights3.AdjGo == true) ? 0 : 1;
    } else if (sw == 2) {
        Idle = (DimmerLights1.AdjGo == true || DimmerLights3.AdjGo == true) ? 0 : 1;
    } else if (sw == 3) {
        Idle = (DimmerLights1.AdjGo == true || DimmerLights2.AdjGo == true) ? 0 : 1;
    }
#endif

#if Switch_Class == 2
    if (sw == 1) {
        Idle = (DimmerLights2.AdjGo == true) ? 0 : 1;
    } else if (sw == 2) {
        Idle = (DimmerLights1.AdjGo == true) ? 0 : 1;
    }
#endif
#endif
    if (Idle == 1) {
        if (Sw->Flag == true) {
            Sw->Hold1 = true;
            Sw->Adj = true;
            Sw->Status = true;
            setRFSW_Status(sw, 1);

            setDimmerLights_TriggerAdj(sw, 1);
            setDimmerLights_AdjGo(sw, 1);
        }
    }
}
//*********************************************************

void Sw_Detect() {
    if (getLoad_ERROR() == false && getTemp_ERROR() == false && getPF_ERROR() == false && myMain.SelfTest == true) {
#ifdef use_1KEY
        SwPointSelect(1);
        if (Sw->Enable == false) {
            Sw->Enable = true;
        }
#endif

#ifdef use_2KEY
        SwPointSelect(2);
        if (Sw->Enable == false) {
            Sw->Enable = true;
        }
#endif

#ifdef use_3KEY
        SwPointSelect(3);
        if (Sw->Enable == false) {
            Sw->Enable = true;
        }
#endif

    }
}
#endif