
// Includes
#include "Select_File.h"

#if CC2500_use == 1 

//*********************************************************

inline void RF_Initialization() {
#ifdef RadioFrequency1
    setRF_Initialization();
#endif
}

//*********************************************************

inline void setRF_Initialization() {
#ifdef RadioFrequency1
    Tx_Length = 21;
    RF1.RunTime = RF_RunTime_Value;
    //    INTE = true;
#endif
}
//*********************************************************

inline void RF_Main() {
#ifdef RadioFrequency1
    setRF_Main();
#endif
}
//*********************************************************

inline void setRF_Learn(char command) {
    RF1.Learn = command == 1 ? true : false;
}
//*********************************************************

//inline void setRF_ReceiveGO(char command) {
//    if (RF1.RxStatus == true) {
//        RF1.RxStatus = false;
//        RF1.Run = true;
//        RF1.ReceiveGO = command == 1 ? true : false;
//    }
//}
//*********************************************************

inline void setRF_RxStatus(char command) {
    RF1.RxStatus = command == 1 ? true : false;
}

//*********************************************************

inline void setRF_Main() {
    char error = 0;
    if (RF1.Enable == true) {
        if (getBuz_GO() == 0) {

#if Switch_use == 1
            RF1.Key = getRF_KeyStatus() == 1 ? true : false;
#else
            RF1.Key = false;
#endif

            if (RF1.Key == false || RF1.Learn == true) {

                if (RF1.TransceiveGO == true) {
                    if (RF1.Learn == false) {
                        RF1.Count++;
                        if (RF1.Count >= (RF1.RunTime / Main_Time)) {
                            RF1.Count = (RF1.RunTime / Main_Time);

                            RF1.TransceiveGO = false;
                            RF1.CorrectionCounter = 0;
                            RF_RxDisable();
                            CC2500_TxData();
                            //                    ErrLED = ErrLED == true ? false : true;
                        }
                    } else {
                        RF1.Count = 0;
                        RF1.TransceiveGO = false;
                    }
                } else {
                    if (RF1.RxStatus == true) {
#if Rx_Enable == 1
                        CC2500_RxData();
#endif
                        if (RF1.ReceiveGO == true) {
                            RF1.ReceiveGO = false;
                            RF1.CorrectionCounter = 0;
#if I2C_use == 1
                            I2C_SetData(1);
                            //LED2=~LED2;
#elif UART_use == 1
                            //UART_SetData();
                            //LED2=~LED2;
#else
                            getRxData();
                            //                                ErrLED = ErrLED == true ? false : true;
#endif    
                        }
                    } else {
                        RF1.Count++;
                        if (RF1.Count >= (RF1.RunTime / Main_Time)) {
                            RF1.Count = 0;
#if Rx_Enable == 1
                            RF1.RxStatus = true;
                            CC2500_WriteCommand(CC2500_SIDLE); // idle
                            CC2500_WriteCommand(CC2500_SFRX); // clear RXFIFO data
                            CC2500_WriteCommand(CC2500_SRX); // set receive mode
#endif
                        }
                    }
                }
            }
        }

        RF1.CorrectionCounter++;
        if (RF1.CorrectionCounter > (60000 / Main_Time)) {
            RF1.CorrectionCounter = 0;

            RF1.RxStatus = false;
            RF1.ReceiveGO = false;
            CC2500_WriteCommand(CC2500_SIDLE); // idle
            CC2500_WriteCommand(CC2500_SFRX); // clear RXFIFO data
        }

        if (RF1.Timeout == true) {
            RF1.Timeout = false;
            CC2500_PowerOnInitial();
        }

    } else {
        if (myMain.PowerON == true) {
            RF1.Enable = true;
        }
    }
}

//*****************************************************************************

inline void RF_Timeout_Counter() {
    RF1.TimeoutCount++;
    if (RF1.TimeoutCount == 25000) {
        RF1.TimeoutCount = 0;
        RF1.Timeout = true;
    }
}

inline void setRF_TimeoutCleared() {
    RF1.TimeoutCount = 0;
}
//*********************************************************

inline void RF_RxDisable() {
    if (RF1.ReceiveGO == true || RF1.RxStatus == true) {
        RF1.RxStatus = false;
        RF1.ReceiveGO = false;
        CC2500_WriteCommand(CC2500_SIDLE); // idle
        CC2500_WriteCommand(CC2500_SFRX); // clear RXFIFO data
        //        CC2500_WriteCommand(CC2500_SFTX); // clear TXFIFO data
        //        setINT_GO(0);
    }
}
//*********************************************************

inline char getRF_KeyStatus() {
    char key = 0;
#if	Switch_Class == 3
    key = (Key1 == true || Key2 == true || Key3 == true) ? 1 : 0;
#endif

#if	Switch_Class == 2
    key = (Key1_1 == true || Key1_2 == true || Key2_1 == true || Key2_2 == true) ? 1 : 0;
#endif

#if	Switch_Class == 1
    key = (Key1_1 == true || Key1_2 == true || Key1_3 == true || Key1_4 == true) ? 1 : 0;
#endif
    return key;
}
//*********************************************************

inline void setTxData() {
    char i;
    if (RF1.Enable == true) {
#if Tx_Enable == 1
        RF1.TransceiveGO = true;
        RF1.Count = 0;
        //ErrLED = 0;
        //        	Product->Data[0]=0x63;		//Command
        //                Product->Data[1]=0x02;	//Command
        //                Product->Data[20]=KeyID;	//Key ID*/
        //        for (i = 0; i < 20; i++) {
        //            RF_Data[i] = product->Data[i];
        //        }
#if myUARTtoRF_use == 1
        RF_Data[0] = 0xAA; //Product->Data[0];		//Command
        RF_Data[1] = 0x01; //Product->Data[1];		//Command
#else
        RF_Data[0] = 0x63; //Product->Data[0];		//Command
        RF_Data[1] = 0x02; //Product->Data[1];		//Command
#endif
        RF_Data[2] = product->Data[2]; //Temperature
        RF_Data[3] = product->Data[3]; //Temperature
        RF_Data[4] = product->Data[4]; //Humidity
        RF_Data[5] = product->Data[5]; //Humidity
        RF_Data[6] = product->Data[6]; //Barometric pressure
        RF_Data[7] = product->Data[7]; //Barometric pressure
        RF_Data[8] = product->Data[8]; //Electricity
        RF_Data[9] = product->Data[9]; //Dimmer
        RF_Data[10] = product->Data[10]; //Electric  current
        RF_Data[11] = product->Data[11]; //Year
        RF_Data[12] = product->Data[12]; //Week
        RF_Data[13] = product->Data[13]; //Serial  Number
        RF_Data[14] = product->Data[14]; //Serial  Number
        RF_Data[15] = product->Data[15]; //Lights Status
        RF_Data[16] = product->Data[16]; //Timmer Command
        RF_Data[17] = product->Data[17]; //Timmer Time
        RF_Data[18] = product->Data[18]; //Reserved
        RF_Data[19] = product->Data[19]; //Reserved
        RF_Data[20] = KeyID; //Product->Data[20];	//Key ID
    }
#endif
}
//******************************************************************************

inline void getRxData() {
    //0xaa,0x01
    if (RF_Data[0] == 0xaa && RF_Data[1] == 0x01) {
        product->Data[2] = 0x55;
        setTxData();
#if myUARTtoRF_use_Value == 1
        LED1 = LED1 == true ? false : true;
#endif
    } else {
        char error = getMain_All_Error_Status(0);
        if (error == 0) {
            if (RF1.Learn == true) {
                //0x00,0x64
                if (RF_Data[0] == 0x00 && RF_Data[1] == 0x64) {
                    setLog_Code();
                }
            } else {
                if (RF_Data[20] == KeyID || RF_Data[20] == 0x0a) {
                    //0x00,0x02
                    if (RF_Data[0] == 0x00 && RF_Data[1] == 0x02) {
                        //loop code
                        if (RF_Data[12] == 0xff && RF_Data[13] == 0xff && RF_Data[14] == 0xff) {
                            NOP();
                        } else {
                            if (RF_Data[12] == product->Data[12] && RF_Data[13] == product->Data[13] && RF_Data[14] == product->Data[14]) {
                                setControl_Lights_Table();
                            }
                        }
                        //0xff,0x02
                    } //else if (RF_Data[0] == 0xff && RF_Data[1] == 0x02) {
                    //                    NOP(); //Broadcasting command
                    //0x00.0x65
                    //                } else if (RF_Data[0] == 0x00 && RF_Data[1] == 0x65) {
                    //                    //overload command
                    //                    NOP();
                    //0x63,0x02
                    //                } else if (RF_Data[0] == 0x63 && RF_Data[1] == 0x02) {
                    //                    //return command
                    //                    NOP();
                    //                }
                }
            }
        } else {
            NOP();
        }
    }
}
//*********************************************************

inline void setLog_Code() {
    RF1.Learn = false;
    setProductData(12, RF_Data[12]);
    setProductData(13, RF_Data[13]);
    setProductData(14, RF_Data[14]);
    setBuz(1, BuzzerOnOffTime);
    if (myMain.First == true) {
        setMemory_LoopSave(1);
    }
    setMemory_Modify(1);
}
//*********************************************************

inline void setControl_Lights_Table() {
    switch (RF_Data[15]) {

        case 0x00://all lights close code
            if (getMain_All_LightsStatus() == 1) {
#if Dimmer_use == true
#ifdef use_1KEY
                if (getDimmerLights_Status(1) == 1) {
                    setDimmerLights_SwOn(1);
                    setDimmerLights_SwOff(1);
                }
#endif
#ifdef use_2KEY
                if (getDimmerLights_Status(2) == 1) {
                    setDimmerLights_SwOn(2);
                    setDimmerLights_SwOff(2);
                }
#endif
#ifdef use_3KEY
                if (getDimmerLights_Status(3) == 1) {
                    setDimmerLights_SwOn(3);
                    setDimmerLights_SwOff(3);
                }
#endif
#endif
                setCmd_Status(1, 1);
            } else {
                setProductData(9, 0);
                setProductData(11, 0);
                setProductData(15, 0);
                setProductData(17, 0);
                setTxData();
            }
            break;

        case 0x20: //state back code
            setProductData(9, 0);
            setProductData(11, 0); //Lights Status
            setProductData(15, product->Data[15]);
            setProductData(17, 0);
            setTxData();
            break;

#ifdef  use_1KEY
        case 0x01://first lights control code
            setRFSW_Control(1);
            break;

#if Dimmer_use == 1 && Properties_Dimmer == 1

        case 0x11://first lights dimmer control code
            setRFSW_AdjControl(1);
            break;
#endif
#endif

#ifdef  use_2KEY
        case 0x02://second lights control code
            setRFSW_Control(2);
            break;

#if Dimmer_use == 1 && Properties_Dimmer == 1
        case 0x21: //second lights dimmer control code
            setRFSW_AdjControl(2);
            break;
#endif
#endif

#ifdef use_3KEY

        case 0x03://third lights contorl code
            setRFSW_Control(3);
            break;

#if Dimmer_use == 1 && Properties_Dimmer == 1

        case 0x31://third lights dimmer control code
            setRFSW_AdjControl(3);
            break;
#endif
#endif
    }
}
//*****************************************************************************
//
//  Rf  Switch
//
//*****************************************************************************

void setRFSW_Control(char sw) {
    char status = 0;

    if (RF_Data[16] == 0x80) {
        setDelayOff_GO(sw, 1, RF_Data[17]);
        if (getDimmerLights_Status(sw) == 1) {
            setBuz(1, BuzzerOnOffTime);
            setRF_DimmerLights(sw, 1);
            setTxData();
            status = 1;
        }
    }

    if (status == 0) {
#if Dimmer_use == true
        setDimmerLights_SwOn(sw);
        setDimmerLights_SwOff(sw);
#endif
    }
}
//*********************************************************

void setRFSW_AdjControl(char sw) {
    char status = 0;
#if Dimmer_use == 1
    status = getDimmerLights_Status(sw);
#endif
    if (RF_Data[9] > 0x64) {
        RF_Data[9] = 0x64;
    } else if (RF_Data[9] < 0x01) {
        RF_Data[9] = 0x01;
    }
    setProductData(9, RF_Data[9]);
    setProductData((20 + sw), RF_Data[9]);

    if (status == 1) {
        setDimmerIntr_MaxmumValue(sw, getDimmerLights_PercentToValue(RF_Data[9]));
        setDimmerIntr_Dimming_RF(sw, 1);
        setTxData();
        //        setRF_DimmerValue(sw);
    } else if (status == 0) {
        //        setProductData(9, product->Data[20 + sw]);
        //        setProductData((20 + sw), 0x00);
        //        setProductData(9, 0x00);
        setDimmerLights_DimmingRun(sw, 1);
        setDimmerLights_SwOn(sw);
        setDimmerLights_SwOff(sw);
    }

    setProductData(11, sw);
    setProductData(17, product->Data[26 + sw]);

    setMemory_Modify(1);
}
//*********************************************************
#if Dimmer_use == 1

//inline void setRF_DimmerValue(char lights) {
//    if (RF_Data[9] > 0x64) {
//        RF_Data[9] = 0x64;
//    }
//    setProductData(9, RF_Data[9]);
//    setProductData(11, lights);
//    setProductData((20 + lights), RF_Data[9]);
//
//    setDimmerIntr_Dimming_RF(lights, 1);
//    //    setDimmerIntr_
//}
//*********************************************************

inline void setRF_DimmerLights(char lights, char on) {
    char status = 1;
    status <<= (lights - 1);
    setProductData(11, lights);
    setProductData(17, product->Data[26 + lights]);
    if (on == 1) {
        setProductData(9, product->Data[20 + lights]);
        setProductData(15, (product->Data[15] | status));
    } else {
        setProductData(9, 0x00);
        setProductData(15, (product->Data[15]&(~status)));
    }
}
//******************************************************************************

inline void setRF_TransceiveGO(char command) {
    RF1.TransceiveGO = command == 1 ? true : false;
}
//******************************************************************************
#endif

//end
#endif