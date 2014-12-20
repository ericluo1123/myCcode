
// Includes
#include "Select_File.h"


#if Switch_use == 1

#ifdef TTPW

void TouchPower() {
    if (myMain.PowerON == true) {
        if (TTPW == false) {
            while (TTPW == false && myMain.Timeout == false) {
                TTPW = true;
                Timeout_Counter();
            }
            set_TimeoutCleared();
        }
    }
}

#endif
//******************************************************************************

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
//******************************************************************************

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
//******************************************************************************

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

#ifdef TTPW
    TouchPower();
#endif
    //Sw_Detect();
}
//******************************************************************************

void setSw_Initialization(char sw) {
    setLED(sw, 1);
#if Switch_Class == 1 && Dimmer_use == 1
    setLED(sw + 1, 1);
#endif
}
//******************************************************************************

//void setSw_Enable(char command) {
//
//#ifdef use_1KEY
//    SwPointSelect(1);
//    Sw->Enable = command;
//#endif
//
//#ifdef use_2KEY
//    SwPointSelect(2);
//    Sw->Enable = command;
//#endif
//
//#ifdef use_3KEY
//    SwPointSelect(3);
//    Sw->Enable = command;
//#endif
//
//}
//******************************************************************************

void setSw_Main(char sw) {
    SwPointSelect(sw);
    if (Sw->Enable == true) {

        if (getMain_All_Error_Status(0) == 0) {
            Sw->Detect = false;
            Sw->Touch = getSw_KeyStatus(sw) == 1 ? true : false;
        } else {
            if (Sw->Detect == false) {
                Sw->Detect = true;

                Sw->Touch = false;
                Sw->Debounce = true;
            }
        }

        if (Sw->Touch == true) {
            if (Sw->Debounce == false) {
                Sw->DebounceTime++;
                if (Sw->DebounceTime >= DebounceTimeValue) {
                    Sw->DebounceTime = 0;
                    Sw->Debounce = true;

#if Dimmer_use == 1
                    setDimmerLights_SwOn(sw); //key on function
#endif

                }
            } else {
                if (Sw->Hold1 == false) {
                    Sw->Hold1Time++;
                    if (Sw->Hold1Time >= Hold1TimeValue) {
                        Sw->Hold1Time = 0;
#if Dimmer_use == 1
#if Dimmable_Func == 1
                        Sw->Hold1 = true;
                        setDimmerLights_AdjOn(sw); //key on function
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
                    setDimmerLights_SwOff(sw); //key on function

#endif
#if CC2500_use == 1
                    setRF_Learn(0);
#endif
                }
            }
        }
    } else {
        if (myMain.PowerON == true) {
            Sw->Enable = true;
        }
    }
}
//******************************************************************************

char getSw_KeyStatus(char sw) {
    char status = 0;
#if Switch_Class == 3
    if (sw == 1) {
        status = (Key1 == true) ? 1 : 0;
    } else if (sw == 2) {
        status = (Key2 == true) ? 1 : 0;
    } else if (sw == 3) {
        status = (Key3 == true) ? 1 : 0;
    }
#endif

#if Switch_Class == 2
    if (sw == 1) {
        status = Key1_1 == true || Key1_2 == true ? 1 : 0;
    } else if (sw == 2) {
        status = Key2_1 == true || Key2_2 == true ? 1 : 0;
    }
#endif

#if Switch_Class == 1
    status = Key1_1 == true || Key1_2 == true || Key1_3 == true || Key1_4 == true ? 1 : 0;
#endif

    return status;
}

//******************************************************************************
//void Sw_Detect() {
//    if (getLoad_ERROR() == false && getTemp_ERROR() == false && getPF_ERROR() == false && myMain.SelfTest == true) {
//#ifdef use_1KEY
//        SwPointSelect(1);
//        if (Sw->Enable == false) {
//            Sw->Enable = true;
//        }
//#endif
//
//#ifdef use_2KEY
//        SwPointSelect(2);
//        if (Sw->Enable == false) {
//            Sw->Enable = true;
//        }
//#endif
//
//#ifdef use_3KEY
//        SwPointSelect(3);
//        if (Sw->Enable == false) {
//            Sw->Enable = true;
//        }
//#endif
//
//    }
//}
#endif