
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

void setLights_Clear(char lights, char command) {
    LightsPointSelect(lights);
    Lights->Clear = command;
}

void setLights_Trigger(char lights, char command) {
    LightsPointSelect(lights);
    Lights->Trigger = command;
}

void setLights_Switch(char lights, char command) {
    LightsPointSelect(lights);
    Lights->Switch = command;
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

char getLights_Status(char lights) {
    LightsPointSelect(lights);
    char result = Lights->Status;
    return result;
}

void setLights(char lights, char command) {

    LightsPointSelect(lights);

    Lights->GO = true;
    if (command == 1) {
        if (Lights->Status == false) {
            Lights->Status = true;
            Lights->RelayValue = 7;
            Lights->TriacValue = 14;
        }
    } else {
        if (Lights->Status == true) {
            Lights->Status = false;
            Lights->RelayValue = 4;
            Lights->TriacValue = 8;
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

void Lights_Close() {
}
#endif



/*
void Lights_Initial()
{
        Lights1=&VarLights1;
        Lights2=&VarLights2;

        Lights1->Enable=1;
        Lights2->Enable=1;
}

//setting
void Lights_Setting(char number)
{
	
        if(number==10 || number==11)
        {
                Lights=&VarLights1;
                Lights->Triac=Triac1;
                Lights->Relay=Relay1;
        }
        else if(number==20 || number==21)
        {
                Lights=&VarLights2;
                Lights->Triac=Triac2;
                Lights->Relay=Relay2;
        }
	
        if(Lights->Enable==1)
        {
                if(number==10 || number==20)
                {
                        if(Lights->Status==1)
                        {
                                Lights->Time=0;
                                Lights->Status=0;
                                if(Lights->GO==1)
                                {
                                        if(Lights->Relay==0 && Lights->Triac==0)
                                                Lights->GO==0;
                                        else if(Lights->Relay==1 && Lights->Triac==1)
                                        {
                                                Lights->TriacTimeValue=3;
                                                Lights->RelayTimeValue=1;
                                        }
                                        else if(Lights->Relay==0 && Lights->Triac==1)
                                        {
                                                Lights->TriacTimeValue=1;
                                                Lights->RelayTimeValue=1;
                                        }
                                }
                                else
                                {
                                        Lights->GO=1;
                                        Lights->TriacTimeValue=8;
                                        Lights->RelayTimeValue=6;
                                        if(number==10)
                                                Triac1=1;
                                        else if(number==20)
                                                Triac2=1;
                                }
                        }
                }
                else
                {
                        if(Lights->Status==0)
                        {
                                Lights->Time=0;
                                Lights->Status=1;
                                if(Lights->GO==1)
                                {
                                        if(Lights->Relay==1 && Lights->Triac==0)
                                                Lights->GO==0;
                                        else if(Lights->Relay==1 && Lights->Triac==1)
                                        {
                                                Lights->TriacTimeValue=1;
                                                Lights->RelayTimeValue=1;
                                        }
                                        else if(Lights->Relay==0 && Lights->Triac==1)
                                        {
                                                Lights->TriacTimeValue=3;
                                                Lights->RelayTimeValue=1;
                                        }
                                }
                                else
                                {
                                        Lights->GO=1;
                                        Lights->TriacTimeValue=8;
                                        Lights->RelayTimeValue=6;
                                        if(number==11)
                                                Triac1=1;
                                        else if(number==21)
                                                Triac2=1;
                                }
                        }
                }
        }
}
//main
void Lights_Main()
{
        if(Lights1->GO==1)
        {
                Lights1->Time++;
                if(Lights1->Time>=Lights1->TriacTimeValue)
                {
                        Lights1->Time=0;
                        Lights1->GO=0;
                        Triac1=0;
                }
                else if(Lights1->Time==Lights1->RelayTimeValue)
                {
                        if(Lights1->Status==1)
                        {
                                Relay1=1;
				
                        }
                        else
                        {
                                Relay1=0;
		
                        }
                }
        }
	
        if(Lights2->GO==1)
        {
                Lights2->Time++;
                if(Lights2->Time>=Lights2->TriacTimeValue)
                {
                        Lights2->Time=0;
                        Lights2->GO=0;
                        Triac2=0;
                }
                else if(Lights2->Time==Lights2->RelayTimeValue)
                {
                        if(Lights2->Status==1)
                        {
                                Relay2=1;
                        }
                        else
                        {
                                Relay2=0;
                        }
                }
        }
}
 */
/***End file***/
