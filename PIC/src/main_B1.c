
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
    SegmentDisplay_Initial();

    while (true) {

        if (myMain.PowerON == true) {
#if SYSC_use == 1
            DetectSYSC_Signal();
#endif

#if OverLoad_use == 1
            getLoad_AD(OverLoad_Channel);
#endif

#if OverTemperature_use == 1
            getTemp_AD(OverTemp_Channel);
#endif

#if PowerFault_use == 1
            getPowerFault_AD(PFV_Channel);
#endif

#if CDS_use == 1
            getCDS_AD(CDS_VR_Channel, CDS_Signal_Channel);
#endif

#if PIR_use == 1
            getPIR_AD(PIR_VR_Channel, PIR_Signal_Channel);
#endif

        }
        //TMR0
#if Timer0_use == 1
        if (Timer0.Timerout == true) {//10ms
            Timer0.Timerout = false;
            my_MainTime();
            WDT_Main();
            I2C_Main();
            UART_Main();
            if (myMain.PowerON) {
                Flash_Memory_Main();

                LED_Main();
                Buzzer_Main();

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
                SegmentDisplay_Main();
            }
        }

#endif

#if Timer1_use == 1
        //TMR1
        if (Timer1.Timeout == true) { //10ms
            Timer1.Timeout = false;
            my_MainTime();
            WDT_Main();
            I2C_Main();
            UART_Main();
            if (myMain.PowerON) {
                Flash_Memory_Main();

                LED_Main();
                Buzzer_Main();

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
                SegmentDisplay_Main();

                //            my_MainTime();
                //            if (myMain.PowerON) {
                //                RF_Main();
                //                I2C_Main();
                //                UART_Main();
                //                SegmentDisplay_Main();
            }
        }
#endif 

#if Timer2_use == 1
        if (Timer2.Timerout == true) {//10ms
            Timer2.Timerout = false;
            my_MainTime();
            WDT_Main();
            I2C_Main();
            UART_Main();
            if (myMain.PowerON) {
                Flash_Memory_Main();

                LED_Main();
                Buzzer_Main();

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
                SegmentDisplay_Main();
            }
        }

#endif
    }
    return (EXIT_SUCCESS);
}

//*****************************************************************************
//Tmain initial

inline void myMain_Initialization() {
#ifndef MCU_16F723A
    product = &_product;
    product->Data[20] = KeyID;
#endif

    //    myMain = &_myMain;
    //TMain->FirstOpen=1;
    //TMain->First=1;
}
//T main
//*****************************************************************************

inline void my_MainTime() {
    //Power
    if (myMain.PowerON == false) {
        myMain.PowerCount++;
        if (myMain.PowerCount == 150)//*10ms
        {
            myMain.PowerCount = 0;
            myMain.PowerON = 1;

#ifdef SYSC1
            setTemp_Enable(1);
#endif

#ifdef OverLoad1
            setLoad_Enable(1);
#endif

#if Self_Test == true
            myMain.k = 1;
#else
            setBuz(3, BuzzerPowerOnTime);
            myMain.SelfTest = 1;

            setSw_Enable(1);

#ifdef RadioFrequency1
            setRF_Enable(1);
#endif

#endif
        }
    } else {
#if Dimmer_use == 1 && Serial_Number == 1
        DimmerLightsOpenShow();
#endif



#if Debug == 1
        myMain.Count1++;
        if (myMain.Count1 == 100) //*10ms
        {
            myMain.Count1 = 0;
            //            setBuz(1, 100);
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
            if (myMain.Flag) {
                myMain.Flag = 0;
                //	setLights(1,1);
                //	setLights_Trigger(1,1);
                //	setLights_Switch(1,1);

                //                setLED(1, 1);
                //                setLED(2, 1);
                //                setLED(3, 1);
                //                setLED(99, 11);
            } else {
                myMain.Flag = 1;
                //	setLights(1,0);
                //	setLights_Trigger(1,1);
                //	setLights_Switch(1,0);

                //                setLED(1, 0);
                //                setLED(2, 0);
                //                setLED(3, 0);
                //                setLED(99, 0);
            }
        }
#endif
    }
#if Debug == true
    myMain.Count2++;
    if (myMain.Count2 == 50) {
        myMain.Count2 = 0;

    }
#endif
}
//*****************************************************************************

inline void Timeout_Counter() {
    myMain.Timeout_Counter++;
    if (myMain.Timeout_Counter == 10000) {
        myMain.Timeout_Counter = 0;
        myMain.Timeout = true;
        //        ErrLED = ErrLED == true ? false : true;
    }
}
//*****************************************************************************

inline void set_TimeoutCleared() {
    myMain.Timeout = false;
    myMain.Timeout_Counter = 0;
}
//*****************************************************************************

char getMain_Exception() {
    char result = 0;
#if SYSC_use == 1
    if (result == 0) {
        result = SYSC.ERROR == true ? 1 : 0;
    }
#endif

#if OverTemperature_use == 1
    if (result == 0) {
        result = Temp.ERROR == true ? 1 : 0;
    }
#endif
    return result;
}
//*****************************************************************************

char getMain_AD_Safe() {
    char result = 1;
    //#if OverTemperature_use == 1
    //    result = Temp.Safe == true ? 1 : 0;
    //#endif
 
#if OverLoad_use == 1 
    if (result == 1) {
        result = Load1.Safe == true ? 1 : 0;
    }
#endif
    return result;
}

char getMain_LightsStatus() {
    char result = 1, count = 0;
#if LightsControl_use == 1
#ifdef use_1KEY
    count = 1;
#endif
#ifdef use_2KEY
    count = 2;
#endif
#ifdef use_3KEY
    count = 3;
#endif
    for (int i = 0; i < count; i++) {
        if (result == 1) {
            LightsPointSelect(i + 1);
            result = Lights->Status == true ? 1 : 0;
        }
    }

#endif
    return result;
}
//End file

