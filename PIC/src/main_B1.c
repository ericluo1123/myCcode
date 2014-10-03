
//include
#include "Select_File.h"

//main

int main(int argc, char** argv) {
    myMain_Initialization();
    Mcu_Initialization();
    Flash_Memory_Initialization();
    LED_Initialization();
    Buzzer_Initialization();

    SYSC_Initialization();
    Temp_Initialization();
    Load_Initialization();
    PowerFault_Initialization();
    DelayOff_Initialization();

    DimmerLights_Initialization();
    Lights_Initialization();
    CDS_Initialization();
    PIR_Initialization();

    Switch_Initialization();
    RF_Initialization();
    CC2500_PowerOnInitial();

    while (1) {
        if (myMain->PowerON) {
#ifdef SYSC1
            DetectSYSC_Signal(1);
#endif

#ifdef OverLoad1
            getLoad_AD(OverLoad_Channel);
#endif

#ifdef SYSC1
            getTemp_AD(OverTemp_Channel);
#endif

#ifdef PFV1
            getPowerFault_AD(PFV_Channel);
#endif

#ifdef CDS_1
            getCDS_AD(1, CDS_VR_Channel, CDS_Signal_Channel);
#endif

#ifdef PIR_1
            getPIR_AD(1, PIR_VR_Channel, PIR_Signal_Channel);
#endif

#if Buzzer_use == 1
            Buzzer_Main();
#endif
        }
        //TMR0
        if (myMain->T0_Timerout) //10ms
        {
            myMain->T0_Timerout = 0;
            myMain();
            WDT_Main();
            if (myMain->PowerON) {
                Flash_Memory_Main();

                LED_Main();

                SYSC_Main();
                Temp_Main();
                Load_Main();
                PowerFault_Main();

                Lights_Main();
                DimmerLights_Main();
                Switch_Main();
                CDS_Main();
                PIR_Main();

                RF_Main();
                DelayOff_Main();
            }
        }
    }
}

//Tmain initial

void myMain_Initialization() {
#ifndef _16F723A
    Product = &VarProduct;
    Product->Data[20] = KeyID;
#endif

    myMain = &VarTMain;
    //TMain->FirstOpen=1;
    //TMain->First=1;
}
//T main

void myMain() {
    //Power
    if (myMain->PowerON == false) {
        myMain->PowerCount++;
        if (myMain->PowerCount == 150)//*10ms
        {
            myMain->PowerCount = 0;
            myMain->PowerON = 1;

#ifdef SYSC1
            setTemp_Enable(1);
#endif

#ifdef OverLoad1
            setLoad_Enable(1);
#endif

#if Self_Test == true
            myMain->k = 1;
#else
            setBuz(3, BuzzerPowerOnTime);
            myMain->SelfTest = 1;

            setSw_Enable(1);

#ifdef RadioFrequency1
            setRF_Enable(1, 1);
#endif

#endif
        }
    } else {
#if Dimmer_use == 1 && Serial_Number == 1
        DimmerLightsOpenShow();
#endif



#if Debug == 1
        myMain->Count1++;
        if (myMain->Count1 == 100) //*10ms
        {
            myMain->Count1 = 0;

            //	setBuz(1,100);
            //	setTxData(1);
            //	ErrLED=~ErrLED;
            //	setProductData(2,Sw1->DebounceTime);
            //	setProductData(3,Sw1->Hold3);
            //	setProductData(4,Sw1->Hold2);
            //	setProductData(5,Sw1->Hold1);
            //	setProductData(6,Sw1->Debounce);
            //	setProductData(7,Sw1->Flag);
            //	setProductData(8,RF->Learn);
            //	TMain->Count3++;
            if (myMain->Flag) {
                myMain->Flag = 0;
                //	setLights(1,1);
                //	setLights_Trigger(1,1);
                //	setLights_Switch(1,1);

                //	setLED(1,1);
                //	setLED(2,0);
                //	setLED(3,1);
                //	setLED(99,1);
            } else {
                myMain->Flag = 1;
                //	setLights(1,0);
                //	setLights_Trigger(1,1);
                //	setLights_Switch(1,0);
                //	setLED(99,0);
                //	setLED(1,0);
                //	setLED(2,1);
                //	setLED(3,0);
                //	setLED(99,0);
            }
        }
#endif
    }
}


//End file

