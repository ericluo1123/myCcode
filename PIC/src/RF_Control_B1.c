
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

inline void RF_Main() {
#ifdef RadioFrequency1
    setRF_Main();
#endif
}
//*********************************************************

void setRF_Learn(char command) {
    RF1.Learn = command == 1 ? true : false;
}
//*********************************************************

void setRF_ReceiveGO(char command) {
    if (RF1.RxStatus == true) {
        RF1.RxStatus = false;
        RF1.Run = true;
        RF1.ReceiveGO = command == 1 ? true : false;
    }
}
//*********************************************************

void setRF_RxStatus(char command) {
    RF1.RxStatus = command == 1 ? true : false;
}

//*********************************************************

void setRF_Initialization() {
#ifdef RadioFrequency1
    Tx_Length = 21;
    RF1.RunTime = 10;
    //    INTE = true;
#endif
}
//*********************************************************

void setRF_Main() {
    char loop_f = 0, Receive_OK = 0, error = 0;
    if (RF1.Enable == true) {

#if Sleep_Mode == 0

        if (getBuz_GO() == 0) {
            if (getMain_All_Error_Status(0) == 0) {
#if Switch_use == 1
                RF1.Key = getRF_KeyStatus() == 1 ? true : false;
#else
                RF1.Key = false;
#endif
            } else {
                //#if PIR_use == 0 && Switch_use == 0
                //                setMain_Exception(0);
                //#endif
                RF1.Key = false;
            }

            if (RF1.Key == true && RF1.Learn == false) {
                RF1.Count = 0;
                RF1.Run = true;
                RF1.RxStatus = false;
            } else {
                if (RF1.Run == true && RF1.Learn == false) {
                    RF1.Count++;
                    if (RF1.Count == RF1.RunTime) {
                        RF1.Count = 0;
                        RF1.Run = false;
                    }
                } else {
                    RF1.Count = 0;
                    RF1.Run = false;

                    if (RF1.TransceiveGO == true && RF1.Learn == false) {
                        RF1.TransceiveGO = false;
                        RF1.RxStatus = false;
                        RF1.ReceiveGO = false;
                        RF1.RunTime = 10;
#ifdef _UARTtoRF_H_ 
                        LED1 = LED1 == true ? false : true;
#endif
                        //                        CC2500_ReadStatus(CC2500_RXBYTES);
                        //                        if (s_data != 0) {
                        RF_RxDisable();
                        //                        if (RF1.RxStatus == true || RF1.ReceiveGO == true) {
                        //                            CC2500_WriteCommand(CC2500_SIDLE); // idle
                        //                            //                            CC2500_WriteCommand(CC2500_SFTX); // clear TXFIFO data
                        //                            CC2500_WriteCommand(CC2500_SFRX); // clear RXFIFO data
                        //                            //                        }
                        //                        }
                        CC2500_TxData();

                    } else {

                        if (RF1.RxStatus == true) { // Check whether have data
#if Rx_Enable == 1
                            CC2500_RxData();
#endif
                            if (RF1.ReceiveGO == true) {
                                RF1.ReceiveGO = false;
                                RF1.Correction = false;
                                RF1.CorrectionCounter = 0;
#if I2C_use == 1
                                I2C_SetData(1);
                                //LED2=~LED2; 
#elif UART_use == 1
                                //UART_SetData();
                                //LED2=~LED2;

#else
                                //                                getRxData();
#endif
                                getRxData();
                                RF1.Run = true;

                                if (RF1.Checked == true) {
                                    if (RF1.RunTime > 10) {
                                        RF1.RunTime = 10;
                                    }
                                    RF1.CheckCount = 0;
                                } else {
                                    RF1.CheckCount++;
                                    if (RF1.CheckCount == 2) {
                                        RF1.CheckCount = 0;
                                        RF1.CheckedCounter = 0;
                                        if (RF1.RunTime < 200) {
                                            RF1.RunTime += 10;
                                        }
                                    }
                                }
                            }
                        } else {
#if Rx_Enable == 1
                            if (RF1.RxStatus == false && RF1.ReceiveGO == false) {
                                RF1.RxStatus = true;
                                RF1.Correction = true;

                                CC2500_WriteCommand(CC2500_SIDLE); // idle
                                //                                CC2500_WriteCommand(CC2500_SFTX); // clear TXFIFO data
                                CC2500_WriteCommand(CC2500_SFRX); // clear RXFIFO data
                                CC2500_WriteCommand(CC2500_SRX); // set receive mode
                            }
#endif
                        }
                    }
                }
                if (RF1.RxStatus == true) {
                    RF1.CheckedCounter++;
                    if (RF1.CheckedCounter == 100) {
                        RF1.CheckedCounter = 0;
                        RF1.CheckCount = 0;
                        if (RF1.RunTime > 10) {
                            RF1.RunTime -= 10;
                        }
                    }
                }
                if (RF1.Correction == true) {
                    RF1.CorrectionCounter++;
                    if (RF1.CorrectionCounter >= 30000) {
                        RF1.CorrectionCounter = 0;
                        RF1.RxStatus = false;
                        RF1.ReceiveGO = false;
                    }
                }
            }
        }
#else
        if (!RF1.Sleep) {
            RF1.Sleep = 1;
            CC2500_WriteCommand(CC2500_SIDLE); // idle
        }
#endif
    } else {
        if (myMain.PowerON == true) {
            RF1.Enable = true;
        }
    }
}
//*********************************************************

char getRF_KeyStatus() {
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

void setTxData() {
    char i;
    if (RF1.Enable == true) {
#if Tx_Enable == 1
        if (RF1.TransceiveGO == false) {
            RF1.TransceiveGO = true;
            RF1.RunTime = 20;
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
    }
#endif
}
//*********************************************************

void setRF_Enable(char command) {
    RF1.Enable = command == 1 ? true : false;
    RF1.Learn = false;
    RF1.TransceiveGO = false;
    RF1.RxStatus = false;
    RF1.ReceiveGO = false;
    RF1.DebounceTime = 0;
    RF1.Debounce = false;
    //    setINT_GO(0);
}
//*********************************************************

void RF_RxDisable() {
    if (RF1.ReceiveGO == true || RF1.RxStatus == true) {
        RF1.RxStatus = false;
        RF1.ReceiveGO = false;
        CC2500_WriteCommand(CC2500_SIDLE); // idle
        //        CC2500_WriteCommand(CC2500_SIDLE); // idle
        CC2500_WriteCommand(CC2500_SFRX); // clear RXFIFO data
        //        CC2500_WriteCommand(CC2500_SFTX); // clear TXFIFO data
        //        setINT_GO(0);
    }
}
//*********************************************************

void getRxData() {
    char error = getMain_All_Error_Status(0);
    if (RF_Data[0] == 0xaa && RF_Data[1] == 0x01) {

        product->Data[2] = 0x55;
        setTxData();
        RF1.RunTime = 10;

#if myUARTtoRF_use_Value == 1
        LED1 = LED1 == true ? false : true;
#endif

    } else {

        if (error == 0) {
            if (RF1.Learn == true) {
                if (RF_Data[0] == 0x0 && RF_Data[1] == 0x64) { //login command
                    setLog_Code();
                    RF1.Checked = true;
                } else {
                    RF1.Checked = false;
                }
            } else {
                if (RF_Data[0] == 0x00 && RF_Data[1] == 0x02) {//lights control command

                    if (RF_Data[12] == 0xff && RF_Data[13] == 0xff && RF_Data[14] == 0xff) {
                        NOP();
                        RF1.Checked = false;
                    } else {
                        if (RF_Data[12] == product->Data[12] && RF_Data[13] == product->Data[13] && RF_Data[14] == product->Data[14]) {
                            setControl_Lights_Table();
                            RF1.Checked = true;
                        }
                    }
                } else if (RF_Data[0] == 0xff && RF_Data[1] == 0x02) { //Broadcasting command
                    NOP();
                } else if (RF_Data[0] == 0x0 && RF_Data[1] == 0x65) { //overload command
                    NOP();
                } else {
                    RF1.Checked = false;
                }
                /*	else if(RF_Data[0] == 0x63 && RF_Data[1] == 0x02){		//return command
                
                                ;
                        }*/
            }
        } else {
            ;
        }
    }
}
//*********************************************************

void setLog_Code() {
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

void setControl_Lights_Table() {
    switch (RF_Data[15]) {
        case 0x00:
#if Dimmer_use == 1
            setDimmerLights_ErrorClose(255);
#endif
            setProductData(9, 0);
            setProductData(11, 0);
            setProductData(15, 0);
            setProductData(17, 0);
            setBuz(1, BuzzerOnOffTime);
            //            setTxData();
            break;
        case 0x20:
            setProductData(9, 0);
            setProductData(11, 0); //Lights Status
            setProductData(17, 0);
            setTxData();
            break;
        case 0x01:
#ifdef  use_1KEY
            setRFSW_Control(1);
#endif
            break;
        case 0x02:
#ifdef  use_2KEY
            setRFSW_Control(2);
#endif
            break;
        case 0x03:
#ifdef use_3KEY
            setRFSW_Control(3);
#endif
            break;
        case 0x11:
#ifdef use_1KEY
#if Dimmer_use == 1 && Properties_Dimmer == 1
            setRFSW_AdjControl(1);
#endif
#endif
            break;
        case 0x21:
#ifdef  use_2KEY
#if Dimmer_use == 1 && Properties_Dimmer == 1
            setRFSW_AdjControl(2);
#endif
#endif
            break;
        case 0x31:
#ifdef  use_3KEY
#if Dimmer_use == 1 && Properties_Dimmer == 1
            setRFSW_AdjControl(3);
#endif
#endif
            break;
    }
}
//*****************************************************************************
//
//  Rf  Switch
//
//*****************************************************************************

//void RfSWPointSelect(char sw) {
//#ifdef use_1KEY
//    if (sw == 1) {
//        RFSW = &RFSW1;
//    }
//#endif
//#ifdef use_2KEY
//    if (sw == 2) {
//        RFSW = &RFSW2;
//    }
//#endif
//#ifdef use_3KEY
//    if (sw == 3) {
//        RFSW = &RFSW3;
//    }
//#endif
//}
//*********************************************************

void setRFSW_Control(char sw) {
    char status = 0;

    //    RfSWPointSelect(sw);
    if (RF_Data[16] == 0x80) {
        setDelayOff_GO(sw, 1, RF_Data[17]);
        if (getDimmerLights_Status(sw) == 1) {
            setBuz(1, BuzzerOnOffTime);
            status = 1;
            setRF_DimmerLights(sw, 1);
            setTxData();

        }
    } else {
#if DelayOff_use == 1
        if (getDelayOff_GO(sw) == 1) {
            setDelayOff_GO(sw, 0, 0);
        }
#endif
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
    //    RfSWPointSelect(sw);
    if (status == 1) {
        setMemory_Modify(1);
        setRF_DimmerValue(sw);
    } else {
        setProductData(9, product->Data[20 + sw]);
    }
    setProductData(17, product->Data[26 + sw]);
    setTxData();
}
//*********************************************************
#if Dimmer_use == 1

void setRF_DimmerValue(char lights) {
    if (RF_Data[9] > 0x64) {
        RF_Data[9] = 0x64;
    }
    setProductData(9, RF_Data[9]);
    setProductData(11, lights);
    setProductData((20 + lights), RF_Data[9]);
    setDimmerLights_AdjRF(lights);
}
//*********************************************************

void setRF_DimmerLights(char lights, char on) {
    char status = 1;
    status <<= (lights - 1);
    setProductData(11, lights);

    //#if DimmerValue_CloseLightsSave == 0 && DimmerValue_SaveMemory == 0
    //    setProductData((20 + lights), setPercentValue(DimmerLights->MaxmumValue));
    //#else
    //    setProductData((20 + lights), setPercentValue(Dimmer_Maxum));
    //#endif

    setProductData(9, product->Data[20 + lights]);
    setProductData(17, product->Data[26 + lights]);
    if (on == 1) {
        setProductData(15, (product->Data[15] | status)); //Lights Status
    } else {
        setProductData(15, (product->Data[15]&(~status))); //Lights Status
    }
}
//*********************************************************
#endif

//end
#endif