
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
    if (lights == 2) {
        Lights = &Lights2;
    }
#endif

#ifdef use_3KEY
    if (lights == 3) {
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

    Lights_Close();
}
//*****************************************************************************

void Lights_Close() {
    if (LightsControl.Detect == true) {
        LightsControl.Detect = false;
        LightsControl.LoadGO = getMain_LightsStatus() == 0 ? false : true;
    }
}
//*****************************************************************************

void setLights_Main(char lights) {
    LightsPointSelect(lights);
    if (Lights->GO == false) {
        if (Lights->Trigger == true) {
            if (getMain_All_Error_Status(0) == 0) {
                if (LightsControl.LoadOK == true) {
                    LightsControl.LoadOK = getLoad_OK() == 1 ? false : LightsControl.LoadOK;
                }
            } else {
                LightsControl.LoadOK = false;
            }

            if (LightsControl.LoadOK == false) {
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

    LightsPointSelect(lights);

#if OverLoad_use == true
    LightsControl.LoadOK = getMain_All_Error_Status(0) == 0 ? true : false;
    LightsControl.LoadGO = status == 1 ? true : LightsControl.LoadGO;
#endif

    Lights->GO = true;
    if (status == 1) {
        if (Lights->Status == false) {
            Lights->Status = true;
            Lights->RelayValue = 10;
            Lights->TriacValue = 13;
            setLights_Line(lights);
        }
    } else {
        if (Lights->Status == true) {
            Lights->Status = false;
            Lights->RelayValue = 4;
            Lights->TriacValue = 7;
        }
    }
#ifdef use_1KEY
    if (lights == 1) {
        Triac1 = true;
    }
#endif
#ifdef use_2KEY
    else if (lights == 2) {
        Triac2 = true;
    }
#endif
#ifdef use_3KEY
    else if (lights == 3) {
        Triac3 = true;
    }
#endif
}
//*****************************************************************************

void Lights_Control(char lights) {
    LightsPointSelect(lights);
    if (Lights->GO == true) {
        Lights->Time++;
        if (Lights->Time >= Lights->RelayValue && Lights->RelaySet == false) {
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

        } else if (Lights->Time >= Lights->TriacValue) {
            Lights->Time = 0;
            Lights->GO = false;
            Lights->RelaySet = false;
#if OverLoad_use == true

            LightsControl.Detect = Lights->Status == false ? true : LightsControl.Detect;

#endif
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
#ifdef use_1KEY
    Lights1.Line = false;
#endif
#ifdef use_2KEY
    Lights2.Line = false;
#endif
#ifdef use_3KEY
    Lights3.Line = false;
#endif
    LightsPointSelect(lights);
    Lights->Line = true;
}
//*****************************************************************************

char getAll_Lights_Line() {
    char line = 0;
#ifdef use_1KEY
    LightsPointSelect(1);
    line = Lights->Line == true ? 1 : 0;
#endif
#ifdef use_2KEY
    LightsPointSelect(2);
    line = Lights->Line == true ? 1 : 0;
#endif
#ifdef use_3KEY
    LightsPointSelect(3);
    line = Lights->Line == true ? 1 : 0;
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

#endif

