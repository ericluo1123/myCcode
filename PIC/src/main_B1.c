
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
            my_MainTimer();
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
            my_MainTimer();
            WDT_Main();
            I2C_Main();
            UART_Main();
            if (myMain.PowerON == true) {
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
            my_MainTimer();
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

inline void my_MainTimer() {
    //Power
    if (myMain.PowerON == false) {
        myMain.PowerCount++;
        if (myMain.PowerCount == 150)//*10ms
        {
            myMain.PowerCount = 0;
            myMain.PowerON = true;


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
    }
}
//*****************************************************************************

inline void set_TimeoutCleared() {
    myMain.Timeout = false;
    myMain.Timeout_Counter = 0;
}
//*****************************************************************************

void getMain_Exception(char command) {
    char status = 0;
    if (command == 3) {
        status = getAll_Lights_Line();
    } else {
        status = 255;
    }
#if LightsControl_use == true
#ifdef use_1KEY
    if (status == 1 || status == 255) {
        setLights_Trigger(1, 0);
    }
#endif
#ifdef use_2KEY
    if (status == 2 || status == 255) {
        setLights_Trigger(2, 0);
    }
#endif
#ifdef use_3KEY
    if (status == 3 || status == 255) {
        setLights_Trigger(3, 0);
    }
#endif

#endif
}
//*****************************************************************************

char getMain_AD_OK() {
    char result = 0;
    //#if OverTemperature_use == 1
    //    result = Temp.Safe == true ? 1 : 0;
    //#endif

#if OverLoad_use == 1  
    if (result == 0) {

    }
#endif
    return result;
}
//*****************************************************************************

char getMain_LightsStatus() {
    char status = 0;
#if LightsControl_use == 1
#ifdef use_1KEY
    if (status == 0) {
        status = getLights_Status(1) == true ? 1 : 0;
    }
#endif
#ifdef use_2KEY
    if (status == 0) {
        status = getLights_Status(2) == true ? 1 : 0;
    }
#endif
#ifdef use_3KEY
    if (status == 0) {
        status = getLights_Status(3) == true ? 1 : 0;
    }
#endif

#endif
    return status;
}
//*****************************************************************************

char getMain_All_Error_Status(char command) {
    char status = 0;
    if (command != 1) {
#if SYSC_use == true
        if (status == 0) {
            status = SYSC.ERROR == true ? 1 : 0;
        }
#endif 
    }
    if (command != 2) {
#if OverTemperature_use == true
        if (status == 0) {
            status = Temp.ERROR == true ? 2 : 0;
        }
#endif
    }

    if (command != 3) {
#if OverLoad_use == true
        if (status == 0) {
            status = Load.ERROR == true ? 3 : 0;
        }
#endif
    }

#if PowerFault_use == true
#endif

#if CDS_use == true
    if (status == 0) {
        status = getCDS_Status() == false ? 5 : 0;
    }
#endif
    return status;
}
//*****************************************************************************

char getMain_Lights_Count() {
    char status1 = 0, status2 = 0, status3 = 0, count = 0;
#if Dimmer_use == true
#endif

#if LightsControl_use == true
#ifdef use_1KEY
    status1 = Lights1.Status == true ? 1 : 0;
#endif
#ifdef use_2KEY
    status2 = Lights2.Status == true ? 1 : 0;
#endif
#ifdef use_3KEY
    status2 = Lights3.Status == true ? 1 : 0;
#endif
#endif
    return count = (status1 + status2 + status3);
}
//*****************************************************************************
//End file

