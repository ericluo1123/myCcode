
// Includes
#include "Select_File.h"



//Routine main
#if LightsControl_use == 1

void LightsPointSelect(char lights) {

#ifdef use_1KEY
    if (lights == 1) {
        Lights = &Lights1;
    }
#endif

#ifdef use_2KEY
    else if (lights == 2) {
        Lights = &Lights2;
    }
#endif

#ifdef use_3KEY
    else if (lights == 3) {
        Lights = &Lights3;
    }
#endif
}
//*****************************************************************************

void Lights_Initialization() {
#ifdef use_1KEY
    setLights_Initialization(1);
#endif

#ifdef use_2KEY
    setLights_Initialization(2);
#endif

#ifdef use_3KEY
    setLights_Initialization(3);
#endif
}
//*****************************************************************************

void setLights_Initialization(char lights) {
    LightsPointSelect(lights);
}
//*****************************************************************************

void Lights_Main() {

    //#if OverLoad_use == 1
    //    if (getMain_All_Error_Status(0) == 0) {
    //        if (LightsControl.LoadOK == true) {
    //            LightsControl.LoadOK = getLoad_OK() == 1 || getMain_All_LightsStatus() == 0 ? false : LightsControl.LoadOK;
    //        }
    //    } else {
    //        LightsControl.LoadOK = false;
    //    }
    //#endif

#if OverLoad_use == 1
    if (Light.LoadGO == true) {
        if (getLoad_OK() == 1 || getMain_All_Error_Status(0) != 0 || getMain_All_LightsStatus() == 0) {
            Light.LoadGO = false;
        }
    }
#endif

#ifdef use_1KEY
    setLights_Main(1);
    Lights_Control(1);
#endif

#ifdef use_2KEY
    setLights_Main(2);
    Lights_Control(2);
#endif

#ifdef use_3KEY
    setLights_Main(3);
    Lights_Control(3);
#endif

}

//*****************************************************************************

void setLights_Main(char lights) {
    LightsPointSelect(lights);
    if (Lights->GO == false) {
        if (Lights->Trigger == true) {
            if (getLights_Allow_Condition(lights) == 0) {
                Lights->Trigger = false;
                if (Lights->Switch == true) {
                    setLights(lights, 1);
                } else {
                    setLights(lights, 0);
                }
            }
        }
    }
}
//*****************************************************************************

void setLights(char lights, char status) {
    //#if OverLoad_use == true
    //    LightsControl.LoadOK = getMain_All_Error_Status(0) == 0 ? true : false;
    //    //    LightsControl.LoadGO = status == 1 ? true : LightsControl.LoadGO;
    //#endif
    //    LightsPointSelect(lights);


    if (status == 1) {
#if PIR_use == 1
        if (lights == 2) {
            setLED(1, 0);
            setLED(2, 1);
        }
#endif
#if CC2500_use == 1
        setRF_TransceiveGO(0);
#endif

        if (Lights->Status == false) {
            Lights->Status = true;
#ifdef use_1KEY
            if (lights == 1) {
                Triac1 = true;
                Lights->RelayValue = 100;
                Lights->TriacValue = 140;
                Lights->Time = 0;
                Lights->GO = true;
            }
#endif
#ifdef use_2KEY
            else if (lights == 2) {
#if setLights_Mode == 1
                Triac2 = true;
                Lights->RelayValue = 100;
                Lights->TriacValue = 140;
                Lights->Time = 0;
                Lights->GO = true;
#elif setLights_Mode == 2
                Triac2 = true; 
#elif setLights_Mode == 3
                Relay2 = true;
#endif
            }
#endif
#ifdef use_3KEY
            else if (lights == 3) {
                Triac3 = true;
                Lights->RelayValue = 100;
                Lights->TriacValue = 140;
                Lights->Time = 0;
                Lights->GO = true;
            }
#endif
        }
#if OverLoad_use == 1
        Light.Load_Status = true;
        setLights_Line(lights);
#endif
    } else {

#if PIR_use == 1
        if (lights == 2) {
            setLED(1, 1);
            setLED(2, 0);
        }
#endif
        if (Lights->Status == true) {
            Lights->Status = false;
#ifdef use_1KEY
            if (lights == 1) {
                Triac1 = true;
                Lights->RelayValue = 40;
                Lights->TriacValue = 80;
                Lights->Time = 0;
                Lights->GO = true;
            }
#endif
#ifdef use_2KEY
            else if (lights == 2) {
#if setLights_Mode == 1
                Triac2 = true;
                Lights->RelayValue = 40;
                Lights->TriacValue = 80;
                Lights->Time = 0;
                Lights->GO = true;
#elif setLights_Mode == 2
                Triac2 = false;
#elif setLights_Mode == 3
                Relay2 = false;
#endif
            }
#endif
#ifdef use_3KEY
            else if (lights == 3) {
                Triac3 = true;
                Lights->RelayValue = 40;
                Lights->TriacValue = 80;
                Lights->Time = 0;
                Lights->GO = true;
            }
#endif

        }
#if OverLoad_use == 1
        Light.Load_Status = false;
        setLights_Line(0);
#endif
    }
}
//*****************************************************************************

void Lights_Control(char lights) {
    LightsPointSelect(lights);
    if (Lights->GO == true) {
        Lights->Time++;
        if (Lights->RelaySet == false) {
            if (Lights->Time >= (Lights->RelayValue / Main_Time)) {
                Lights->RelaySet = true;
#ifdef use_1KEY
                if (lights == 1) {
                    Relay1 = Lights->Status == true ? true : false;
                }
#endif
#ifdef use_2KEY
                else if (lights == 2) {
                    Relay2 = Lights->Status == true ? true : false;
                }
#endif
#ifdef use_3KEY
                else if (lights == 3) {
                    Relay3 = Lights->Status == true ? true : false;
                }
#endif
            }
        } else {
            if (Lights->Time >= (Lights->TriacValue / Main_Time)) {
                Lights->Time = 0;
                Lights->GO = false;
                Lights->RelaySet = false;

#ifdef use_1KEY
                if (lights == 1) {
                    Triac1 = false;
                }
#endif
#ifdef use_2KEY
                else if (lights == 2) {
                    Triac2 = false;
                }
#endif

#ifdef use_3KEY
                else if (lights == 3) {
                    Triac3 = false;
                }
#endif
            }
        }
    }
}
//*****************************************************************************

char getLights_Status(char lights) {
    LightsPointSelect(lights);
    char status = Lights->Status == true ? 1 : 0;
    return status;
}
//*****************************************************************************

void setLights_Trigger(char lights, char command) {
    LightsPointSelect(lights);
    Lights->Trigger = true;
    Lights->Switch = command == 1 ? true : false;
}
//*****************************************************************************

void setLights_Line(char lights) {
    Light.LoadGO = true;
#ifdef use_1KEY
    Lights1.Line = false;
    if (lights == 1 && lights != 0) {
        Lights1.Line = true;
    }
#endif
#ifdef use_2KEY
    Lights2.Line = false;
    if (lights == 2 && lights != 0) {
        Lights2.Line = true;
    }
#endif
#ifdef use_3KEY
    Lights3.Line = false;
    if (lights == 3 && lights != 0) {
        Lights3.Line = true;
    }
#endif
    //    LightsPointSelect(lights);
    //    Lights->Line = true;
}
//*****************************************************************************

char getAll_Lights_Line() {
    char line = 0;
#ifdef use_1KEY
    if (Lights1.Line == true) {
        line = 1;
    }
#endif
#ifdef use_2KEY
    else if (Lights2.Line == true) {
        line = 2;
    }
#endif
#ifdef use_3KEY
    else if (Lights3.Line == true) {
        line = 3;
    }
#endif
    return line;
}
//*****************************************************************************

char getLightsControl_GO() {
    char loadgo = LightsControl.LoadGO == true ? 1 : 0;
    return loadgo;
}
//*****************************************************************************

char getLightsControl_OK() {
    char loadok = LightsControl.LoadOK == true ? 1 : 0;
    return loadok;
}
//*****************************************************************************

void setLights_ErrorClose(char lights) {
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
            if (getLights_Status(i + 1) == 1) {
                setLights_Trigger(i + 1, 0);
            }
        }
    } else {
        if (getLights_Status(lights) == 1) {
            setLights_Trigger(lights, 0);
        }
    }
}
//*****************************************************************************

char getLights_Allow_Condition(char lights) {
    char allow = 0;

#if OverLoad_use == 1
    allow = getLoad_OK() == 0 && Light.LoadGO == false ? 0 : 1;
#endif

    //#if Switch_Class == 2
    //    if (allow == 0) {
    //        if (lights == 1) {
    //            allow = Lights2.Trigger == true ? 1 : 0;
    //        } else if (lights == 2) {
    //            allow = Lights1.Trigger == true ? 1 : 0;
    //        }
    //    }
    //#endif
    //#if Switch_Class == 3
    //    if (allow == 0) {
    //        if (lights == 1) {
    //            allow = Lights2.Trigger == true || Lights3.Trigger == true ? 1 : 0;
    //        } else if (lights == 2) {
    //            allow = ights1.Trigger == true || Lights3.Trigger == true ? 1 : 0;
    //        } else if (lights == 3) {
    //            allow = ights1.Trigger == true || Lights2.Trigger == true ? 1 : 0;
    //        }
    //
    //    }
    //#endif

    return allow;
}
//*****************************************************************************

char getLight_LoadGO() {
    char loadgo = Light.LoadGO == true ? 1 : 0;
    return loadgo;
}

char getLight_Load_Status() {
    char loadstatus = Light.Load_Status == true ? 1 : 0;
    return loadstatus;
}

void setLights_SwOn(char sw) {
    LightsPointSelect(sw);

#if setLights_SwOn_Mode == 1
    Lights->SwFlag = true;
    if (getLights_Status(sw) == 0) {
        Lights->SwStatus = true;
        setLights_Trigger(sw, 1);
    } else {
        Lights->SwStatus = false;
    }
#elif setLights_SwOn_Mode == 2
    Lights->SwFlag = true;
    if (sw == 1) {
        if (getLights_Status(sw) == 0) {
            Lights->SwStatus = true;
            setLights_Trigger(sw, 1);
        } else {
            Lights->SwStatus = false;
        }
    } else if (sw == 2) {
        if (getLights_Status(sw) == 0) {
            setLights_Trigger(sw, 1);
        }
    }
#endif
}

void setLights_SwOff(char sw) {

    LightsPointSelect(sw);
#if setLights_SwOff_Mode == 1
    if (Lights->SwFlag == true) {
        Lights->SwFlag = false;
        if (Lights->SwStatus == false) {
            setLights_Trigger(sw, 0);
        }
    }
#elif setLights_SwOff_Mode == 2
    if (sw == 1) {
        if (Lights->SwFlag == true) {
            Lights->SwFlag = false;
            if (Lights->SwStatus == false) {
                setLights_Trigger(sw, 0);
            }
        }
    } else if (sw == 2) {
        if (getLights_Status(sw) == 1) {
            setLights_Trigger(sw, 0);
        }
    }
#endif
}

#endif

