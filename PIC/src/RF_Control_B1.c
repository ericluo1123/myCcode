
// Includes
#include "Select_File.h"

#if CC2500_use == 1

void RfPointSelect(char rf) {
#ifdef RadioFrequency1
    if (rf == 1) {
        RF = &RF1;
    }
#endif	
}
//*********************************************************

void RF_Initialization() {
#ifdef RadioFrequency1
    setRF_Initialization(1);
#endif
}
//*********************************************************

void RF_Main() {
#ifdef RadioFrequency1
    setRF_Main(1);
#endif
}
//*********************************************************

void setRF_Learn(char rf, char command) {
    RfPointSelect(rf);
    RF->Learn = command;
}
//*********************************************************

void setRF_ReceiveGO(char rf, char command) {
    RfPointSelect(rf);
    RF->ReceiveGO = command;
}
//*********************************************************

void setRF_RxStatus(char rf, char command) {
    RfPointSelect(rf);
    RF->RxStatus = command;
}

//*********************************************************

void setRF_Initialization(char rf) {
#ifdef RadioFrequency1
    //RfPointSelect(rf);
    Tx_Length = 21;
#endif
}
//*********************************************************

void setRF_Main(char rf) {
    RfPointSelect(rf);
    if (RF->Enable == true) {
#if Sleep_Mode == 0

        if (Buz->GO == false) {
#if	Switch_Class == 3
            RF->Key = (Key1 == true || Key2 == true || Key3 == true) ? true : false;
#endif

#if	Switch_Class == 2
            RF->Key = (Key1_1 == true || Key1_2 == true || Key2_1 == true || Key2_2 == true) ? true : false;
#endif

#if	Switch_Class == 1
            RF->Key = (Key1_1 == true || Key1_2 == true || Key1_3 == true || Key1_4 == true) ? true : false;
#endif
            if (RF->Key == true && RF->Learn == false) {
                RF->Run = true;
                RF_RxDisable(1);
                //                if (RF->TransceiveGO == true) {
                //                    RF->TransceiveGO = false;
                //                    CC2500_TxData();
                //                }
            } else {
                if (RF->Run == true && RF->Learn == false) {
                    RF->Count++;
                    if (RF->Count == 25) {
                        RF->Count = 0;
                        RF->Run == false;
                    }
                } else {
                    RF->Count = 0;
                    RF->Run == false;

                    if (RF->ReceiveGO == true) {
                        RF->ReceiveGO = false;
                        CC2500_RxData();
                        //                        RF->Run = true;
#if I2C_use == 1
                        I2C_SetData(1);
                        //LED2=~LED2;
#elif UART_use == 1
                        UART_SetData();
#else
                        getRxData(1);
#endif
                        //ErrLED=~ErrLED;
                    } else {
                        if (RF->Learn == false) {
                            if (RF->TransceiveGO == true) {
                                RF->TransceiveGO = false;
                                RF_RxDisable(1);
                                CC2500_TxData();
                                //                            RF->Run = true;
                            } else {
#if Rx_Enable == 1
                                if (RF->TransceiveGO == false && RF->ReceiveGO == false && RF->RxStatus == false) {
                                    CC2500_WriteCommand(CC2500_SRX); // set receive mode
                                    setINT_GO(1);
                                }
                            }
                        }
                    }
                }
            }
        }
    }

#else
                                if (!RF->Sleep) {
                                    RF->Sleep = 1;
                                    CC2500_WriteCommand(CC2500_SIDLE); // idle
                                }
#endif
}


//*********************************************************

void setTxData(char rf) {
    char i;
    RfPointSelect(rf);
    if (RF->Enable == true) {
#if Tx_Enable == 1
        if (RF->TransceiveGO == false) {
            RF->TransceiveGO = true;
            /*	Product->Data[0]=0x63;		//Command
                    Product->Data[1]=0x02;		//Command
                    Product->Data[20]=KeyID;	//Key ID*/
            /*	for(i=2 ;i< 20 ;i++)
                    {
                            RF_Data[i]=Product->Data[i];
                    }*/

            RF_Data[0] = 0x63; //Product->Data[0];		//Command
            RF_Data[1] = 0x02; //Product->Data[1];		//Command
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
}
//*********************************************************

void setRF_Enable(char rf, char command) {
    RfPointSelect(rf);
    RF->Enable = command;
    RF->Learn = 0;
    RF->TransceiveGO = 0;
    RF->RxStatus = 0;
    RF->ReceiveGO = 0;
    RF->DebounceTime = 0;
    RF->Debounce = 0;
    setINT_GO(0);
}
//*********************************************************

void RF_RxDisable(char rf) {
    RfPointSelect(rf);

    if (RF->ReceiveGO == true || RF->RxStatus == true) {
        RF->RxStatus = false;
        RF->ReceiveGO = false;
        CC2500_WriteCommand(CC2500_SIDLE); // idle
        setINT_GO(0);
        if (RF->ReceiveGO == true) {
            CC2500_WriteCommand(CC2500_SFRX); // clear RXFIFO data
        }
    }
}
//*********************************************************

void getRxData(char rf) {
    unsigned char i;
    RfPointSelect(rf);
    if (RF->Learn) {
        if (RF_Data[0] == 0x0 && RF_Data[1] == 0x64) //login command
        {
            setLog_Code(1);
        }
    } else {
        if (RF_Data[0] == 0x00 && RF_Data[1] == 0x02) //lights control command
        {
            if (RF_Data[12] == 0xff && RF_Data[13] == 0xff && RF_Data[14] == 0xff) {
                NOP();
            } else {
                if (RF_Data[12] == product->Data[12] && RF_Data[13] == product->Data[13] && RF_Data[14] == product->Data[14]) {
                    setControl_Lights_Table(1);
                }
            }
        } else if (RF_Data[0] == 0xff && RF_Data[1] == 0x02) //Broadcasting command
        {
            ;
        } else if (RF_Data[0] == 0x0 && RF_Data[1] == 0x65) //overload command
        {
            ;
        }
        /*	else if(RF_Data[0] == 0x63 && RF_Data[1] == 0x02)		//return command
                {
                        ;
                }*/
    }
}
//*********************************************************

void setLog_Code(char rf) {
    RfPointSelect(rf);
    setProductData(12, RF_Data[12]);
    setProductData(13, RF_Data[13]);
    setProductData(14, RF_Data[14]);
    setBuz(1, BuzzerOnOffTime);
    RF->Learn = 0;
    if (myMain->First) {
        setMemory_LoopSave(1);
    }
    setMemory_Modify(1);
}
//*********************************************************

void setControl_Lights_Table(char rf) {
    RfPointSelect(rf);
    if (RF_Data[15] == 0x00) {
#ifdef use_1KEY
        setDimmerLights(1, 0);
        setRFSW_Status(1, 0);
        setSw_Status(1, 0);
#endif
#ifdef use_2KEY
        setDimmerLights(2, 0);
        setRFSW_Status(2, 0);
        setSw_Status(2, 0);
#endif
#ifdef use_3KEY
        setDimmerLights(3, 0);
        setRFSW_Status(3, 0);
        setSw_Status(3, 0);
#endif

        setProductData(9, 0);
        setProductData(11, 0);
        setProductData(15, 0);
        setProductData(17, 0);
        setBuz(1, BuzzerOnOffTime);
        setTxData(1);
    } else if (RF_Data[15] == 0x20) {
        setProductData(9, 0);
        setProductData(11, 0); //Lights Status
        setProductData(17, 0);
        setTxData(1);
    }
#ifdef use_1KEY
    else if (RF_Data[15] == 0x01) {
        setRFSW_Control(1);
    }
#if Dimmable_Func == 1
    else if (RF_Data[15] == 0x11) {
        setRFSW_AdjControl(1);
    }
#endif
#endif

#ifdef use_2KEY
    else if (RF_Data[15] == 0x02) {
        setRFSW_Control(2);
    }
#if Dimmable_Func == 1
    else if (RF_Data[15] == 0x21) {
        setRFSW_AdjControl(2);
    }
#endif
#endif

#ifdef use_3KEY
    else if (RF_Data[15] == 0x03) {
        setRFSW_Control(3);
    }
#if Dimmable_Func == 1
    else if (RF_Data[15] == 0x31) {
        setRFSW_AdjControl(3);
    }
#endif
#endif
}
//*********************************************************

void RfSWPointSelect(char sw) {
#ifdef use_1KEY
    if (sw == 1) {
        RFSW = &RFSW1;
    }
#endif	
#ifdef use_2KEY
    if (sw == 2) {
        RFSW = &RFSW2;
    }
#endif
#ifdef use_3KEY
    if (sw == 3) {
        RFSW = &RFSW3;
    }
#endif
}
//*********************************************************

void setRFSW_Control(char sw) {
    RfSWPointSelect(sw);
    if (!RFSW->Status) {
        if (RF_Data[16] == 0x80) {
            setDelayOff_GO(sw, 1, RF_Data[17]);
        }
        RFSW->Status = 1;
        setSw_Status(sw, 1);

        setDimmerLights_Trigger(sw, 1);
        setDimmerLights_Switch(sw, 1);

        setRF_DimmerLights(sw, RFSW->Status);
    } else {
        if (RF_Data[16] == 0x80) {
            setDelayOff_GO(sw, 1, RF_Data[17]);
            setRF_DimmerLights(sw, 1);
        } else {
            RFSW->Status = 0;
            setSw_Status(sw, 0);

            setDimmerLights_Trigger(sw, 1);
            setDimmerLights_Switch(sw, RFSW->Status);

            setDelayOff_GO(sw, 0, 0);
            setRF_DimmerLights(sw, 0);
        }
    }
    setBuz(1, BuzzerOnOffTime);
    setTxData(1);
}
//*********************************************************

void setRFSW_AdjControl(char sw) {
    RfSWPointSelect(sw);
    if (RFSW->Status) {
        setMemory_Modify(1);
        setRF_DimmerValue(sw);
    } else {
        setProductData(9, product->Data[20 + sw]);
    }
    setProductData(17, product->Data[26 + sw]);
    setTxData(1);
}
//*********************************************************

void setRFSW_Status(char sw, char command) {
    RfSWPointSelect(sw);
    RFSW->Status = command;
}
//*********************************************************
#if Dimmer_use == 1

void setRF_DimmerValue(char lights) {
    if (RF_Data[9] > 0x64) {
        RF_Data[9] = 0x64;
    }
    setProductData(9, RF_Data[9]);
    setProductData(11, lights);
    setProductData((20 + lights), product->Data[9]);
    setDimmerLights_AdjRF(lights);
}
//*********************************************************

void setRF_DimmerLights(char lights, char on) {
    char status;
    status = 1;
    status <<= (lights - 1);
    setProductData(11, lights);

#if DimmerValue_CloseLightsSave == 0 && DimmerValue_SaveMemory == 0
    setProductData((20 + lights), setPercentValue(Dimmer_Maxum));
#endif

    setProductData(9, product->Data[20 + lights]);
    setProductData(17, product->Data[26 + lights]);
    if (on) {
        setProductData(15, (product->Data[15] | status)); //Lights Status
    } else {
        setProductData(15, (product->Data[15]&(~status))); //Lights Status
    }
}
//*********************************************************
#endif

//end
#endif