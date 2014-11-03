
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

void setLights_Initialization(char lights) {
    LightsPointSelect(lights);
    Lights->Open = true;
    Lights->Close = true;
}

void Lights_Main() {
#ifdef use_1KEY
    setLights_Main(1);
#endif

#ifdef use_2KEY
    setLights_Main(2);
#endif

#ifdef use_3KEY
    setLights_Main(3);
#endif

#ifdef use_1KEY
    Lights_Control(1);
#endif

#ifdef use_2KEY
    Lights_Control(2);
#endif

#ifdef use_3KEY
    Lights_Control(3);
#endif

    Lights_Close();
}

void Lights_Close() {
    char status = 0;
    if (LightsControl.Detect == true) {
        LightsControl.Detect = false;
        status = getMain_LightsStatus();
        //#ifdef use_1KEY
        //        if (status == 0) {
        //            status = getLights_Status(1) == 1 ? 1 : 0;
        //        }
        //#endif
        //#ifdef use_2KEY
        //        if (status == 0) {
        //            status = getLights_Status(2) == 1 ? 1 : 0;
        //        }
        //#endif
        //#ifdef use_3KEY
        //        if (status == 0) {
        //            status = getLights_Status31) == 1 ? 1 : 0;
        //        }
        //#endif

        //        if (status == 0) {
        //            setLoad_GO(0);
        //        }
    }
}

void setLights_Main(char lights) {
    char clear = 1;
    LightsPointSelect(lights);
    if (Lights->GO == false) {

#if Switch_Class == 3
        if (lights == 1) {
            clear = (Lights22.Clear == false || Lights33.Clear == false) ? 0 : 1;
        } else if (lights == 2) {
            clear = (Lights11->Clear == false || Lights33->Clear == false) ? 0 : 1;
        } else if (lights == 3) {
            clear = (Lights11->Clear == false || Lights22->Clear == false) ? 0 : 1;
        }
#endif

#if Switch_Class == 2
        if (lights == 1) {
            clear = (Lights22->Clear == false) ? 0 : 1;
        } else if (lights == 2) {
            clear = (Lights11->Clear == false) ? 0 : 1;
        }
#endif

        if (Lights->Trigger == true) {
            if (clear == 1) {
                if (Lights->Switch == true) {
                    Lights->Trigger = false;

                    setLights(lights, 1);


#if OverLoad_use == 1
                    Lights->Clear = 0;
#endif
                } else {
                    Lights->Trigger = false;

                    setLights(lights, 0);

#if OverLoad_use == 1
                    Lights->Clear = 0;
#endif
                }
            }
        }
    }
}

char getLights_Status(char lights) {
    LightsPointSelect(lights);
    char result = Lights->Status == true ? 1 : 0;
    return result;
}

//char getAll_Lights_Status() {
//    char status = 0;
//#ifdef use_1KEY
//    if (status == 0) {
//        status = getLights_Status(1) == 1 ? 1 : 0;
//    }
//#endif
//
//#ifdef use_2KEY
//    if (status == 0) {
//        status = getLights_Status(2) == 1 ? 1 : 0;
//    }
//#endif
//
//#ifdef use_3KEY
//    if (status == 0) {
//        status = getLights_Status31) == 1 ? 1 : 0;
//    }
//#endif
//    return status;
//}

void setLights_Clear(char lights, char command) {
    LightsPointSelect(lights);
    Lights->Clear = command;
}

void setLights_Trigger(char lights, char command) {
    LightsPointSelect(lights);
    Lights->Trigger = true;
    Lights->Switch = command == 1 ? true : false;
}

void setLights_Open(char lights, char command) {
    LightsPointSelect(lights);
    Lights->Open = command;
}

char getLights_Open(char lights) {
    LightsPointSelect(lights);
    char result = 0;
    result = Lights->Open;
    return result;
}

void setLights_Close(char lights, char command) {
    LightsPointSelect(lights);
    Lights->Close = command;
}

char getLights_Close(char lights) {
    LightsPointSelect(lights);
    char result;
    result = Lights->Close;
    return result;

}

void setLights(char lights, char status) {

    LightsPointSelect(lights);
    LightsControl.Load = lights;
    Lights->GO = true;
    if (status == 1) {
        if (Lights->Status == false) {
            Lights->Status = true;
            Lights->RelayValue = 7;
            Lights->TriacValue = 14;
            //            setLoad_StatusOn(lights, 1);
            //            setLoad_Count(0);
        }
    } else {
        if (Lights->Status == true) {
            Lights->Status = false;
            Lights->RelayValue = 4;
            Lights->TriacValue = 7;
            //            setLoad_StatusOff(lights, 1);
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

void Lights_Control(char lights) {
    LightsPointSelect(lights);
    if (Lights->GO == true) {
        Lights->Time++;
        if (Lights->Time >= Lights->RelayValue && Lights->RelaySet == false) {
            Lights->RelaySet = true;
#ifdef use_1KEY
            if (lights == 1) {

                Relay1 = Lights->Status ? true : false;

            }
#endif
#ifdef use_2KEY
            else if (lights == 2) {

                Relay2 = Lights->Status ? true : false;

            }
#endif
#ifdef use_3KEY
            else if (lights == 3) {
                Relay3 = Lights->Status ? true : false;
            }
#endif

        } else if (Lights->Time >= Lights->TriacValue) {
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

void Lights_ERROR() {
}

#endif

