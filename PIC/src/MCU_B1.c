

// Includes
#include "Select_File.h"

//config
#ifdef MCU_16F723A
#pragma config FOSC = INTOSCIO , WDTE = _WDTE, BOREN = OFF , PLLEN = _PLLEN
#pragma config VCAPEN = DIS
//__CONFIG(FOSC_INTOSCIO & _WDTE & BOREN_OFF & PLEEN_Value); // v8.84
//__CONFIG(VCAPEN_DIS); // WRT_OFF
#endif

#ifdef MCU_16F1516
#pragma config FOSC = INTOSC , WDTE = _WDTE , BOREN=OFF
#pragma config VCAPEN = OFF,WRT = BOOT
//__CONFIG(FOSC_INTOSC & _WDTE); // v8.84
//__CONFIG(VCAPEN_OFF & WRT_BOOT); // WRT_OFF
#endif 

#ifdef MCU_16F1518
#pragma config FOSC = INTOSC,WDTE = _WDTE,BOREN=OFF
#pragma config VCAPEN = OFF,WRT = HALF
// __CONFIG(FOSC_INTOSC & _WDTE & BOREN_OFF); // v8.84
// __CONFIG(VCAPEN_OFF & WRT_HALF); // WRT_OFF WRT_BOOT WRT_HALF
#endif

//*********************************************************

void Mcu_Initialization() {
    //Fosc
    Fosc_Set();
    //I/O
    IO_Set();
    //Timer0
    TMR0_Set();
    //Timmer1
    TMR1_Set();
    //ADC
    ADC_Set();
    //Timmer2
    TMR2_Set();
    //INT
    INT_Set();
    //IOC
    IOC_Set();
    //I2C
    I2C_Set();
    //UART
    UART_Set();
    //Watch dog
    WDT_Set();
}
//*********************************************************

void Fosc_Set() {
    OSCCON = _OSCCON;
}

void IO_Set() {
#ifdef MCU_16F723A
    TRISA = _TRISA;
    TRISB = _TRISB;
    TRISC = _TRISC;
    ANSELA = _ANSELA;
    ANSELB = _ANSELB;
    PORTA = _PORTA;
    PORTB = _PORTB;
    PORTC = _PORTC;

    WPUB = _WPUB;
#endif

#ifdef MCU_16F1516
    TRISA = _TRISA;
    TRISB = _TRISB;
    TRISC = _TRISC;
    LATA = _LATA;
    LATB = _LATB;
    LATC = _LATC;
    ANSELA = _ANSELA;
    ANSELB = _ANSELB;
    ANSELC = _ANSELC;
    PORTA = _PORTA;
    PORTB = _PORTB;
    PORTC = _PORTC;

    WPUB = _WPUB;
#endif

#ifdef MCU_16F1518
    TRISA = _TRISA;
    TRISB = _TRISB;
    TRISC = _TRISC;

    LATA = _LATA;
    LATB = _LATB;
    LATC = _LATC;

    ANSELA = _ANSELA;
    ANSELB = _ANSELB;
    ANSELC = _ANSELC;

    PORTA = _PORTA;
    PORTB = _PORTB;
    PORTC = _PORTC;

    WPUB = _WPUB;
#endif
}

//*********************************************************

//ISR

void interrupt ISR(void) {// interrupt 0	// ISR (Interrupt Service Routines)


#if Timer0_use == 1
    else if (TMR0IE == true && TMR0IF == true) {
        TMR0_ISR();
    }
#endif
#if Timer1_use == 1
    if (TMR1IE == true && TMR1IF == true) {
        TMR1_ISR();
    }
#endif
#if Timer2_use == 1
    else if (TMR2IE == true && TMR2IF == true) {
        TMR2_ISR();
    }
#endif
#if INT_use == 1
    INT_ISR();
#endif
#if IOC_use == 1
    if (IOCIE == true && IOCIF == true && IOCBF2 == true) {
        IOC_ISR();
    }
#endif
#if UART_use == 1
    UART_ISR();
#endif
#if I2C_use == 1
    I2C_ISR();
#endif
    return;
}
//*********************************************************
#if Timer0_use == true

void TMR0_Set() {
    //  Timer0 = &_Timer0;
    OPTION_REG = OPTION_REG_Value;
    TMR0 = TMR0_Value;
    TMR0IE = true;
    GIE = true;
}
//*********************************************************

inline void TMR0_ISR() {
    if (TMR0IE == true && TMR0IF == true) {

        TMR0 = TMR0_Value;
        TMR0IF = false;

#if Dimmer_use == true

#ifdef use_1KEY
        setDimmerLights_IntrControl(1);
        // setDimmerLights_IntrControl(1);
#endif

#ifdef use_2KEY
        setDimmerLights_IntrControl(2);
        //setDimmerLights22_Control(2);
#endif

#ifdef use_3KEY
        setDimmerLights_IntrControl(3);
        // setDimmerLights33_Control(3);
#endif

#endif

        Timer0.Count++;
        if (Timer0.Count == TMR0_10ms) {
            Timer0.Count = 0;
            Timer0.Timerout = true;
        }
        //        ErrLED = ErrLED == true ? false : true;
    }
}
//*********************************************************

inline void setDimmerReClock() {

#if Dimmer_use == true

#ifdef use_1KEY
    setDimmerLights_IntrIOC_GO(1);
#endif

#ifdef use_2KEY
    setDimmerLights_IntrIOC_GO(2);
#endif

#ifdef use_3KEY
    setDimmerLights_IntrIOC_GO(3);
#endif

    //    TMR0 = 255;

#endif
}

//end Tim0
#endif
//*********************************************************


//*********************************************************
#if Timer1_use == 1

inline void TMR1_Set() {
    T1CON = (_CS | _CKPS | _TMR1ON);
    TMR1H = TMR1H_Value;
    TMR1L = TMR1L_Value;
    TMR1IE = true;
    PEIE = true;
    GIE = true;
}
//*********************************************************

inline void TMR1_ISR() {

#if Dimmer_use == true

#if PIR_use == 1
#ifdef use_1KEY
    DimmerLights_IOC_1();
#endif
#ifdef use_2KEY
    DimmerLights_IOC_2();
#endif
#ifdef use_3KEY
    DimmerLights_IOC_3();
#endif
#endif

#ifdef use_1KEY
    //    setDimmerIntr_TMR(1);
    DimmerLights_TMR_1();
#endif

#ifdef use_2KEY
    //    setDimmerIntr_TMR(2);
    DimmerLights_TMR_2();
#endif

#ifdef use_3KEY
    //    setDimmerIntr_TMR(3);
#endif

#endif

    Timer1.Count++;
    if (Timer1.Count == TMR1_Time) {
        Timer1.Count = 0;
        Timer1.Timeout = true;
    }

    TMR1H = TMR1H_Value;
    TMR1L = TMR1L_Value;
    TMR1IF = false;
}

#endif
//*********************************************************
#if Timer2_use == 1

inline void TMR2_Set() {
    T2CON = (_T2CKPS | _TOUTPS | _TMR2ON);
    TMR2 = _TMR2;
    PR2 = _PR2;
    TMR2IE = true;
    PEIE = true;
    GIE = true;
}

inline void TMR2_ISR() {
    if (TMR2IE == true && TMR2IF == true) {

        TMR2 = _TMR2;
        TMR2IF = false;

#if Dimmer_use == true

#ifdef use_1KEY
        setDimmerLights_IntrControl(1);
        // setDimmerLights_IntrControl(1);
#endif

#ifdef use_2KEY
        setDimmerLights_IntrControl(2);
        //setDimmerLights22_Control(2);
#endif

#ifdef use_3KEY
        setDimmerLights_IntrControl(3);
        // setDimmerLights33_Control(3);
#endif

#endif

        Timer2.Count++;
        if (Timer2.Count == TMR2_10ms) {
            Timer2.Count = 0;
            Timer2.Timeout = true;
        }
        //        ErrLED = ErrLED == true ? false : true;
    }
}

//*********************************************************

inline void setDimmerReClock() {

#if Dimmer_use == true

#ifdef use_1KEY
    setDimmerLights_IntrIOC_GO(1);
#endif

#ifdef use_2KEY
    setDimmerLights_IntrIOC_GO(2);
#endif

#ifdef use_3KEY
    setDimmerLights_IntrIOC_GO(3);
#endif

    //    TMR0 = 255;

#endif
}

#endif
//*********************************************************
#if INT_use == 1

void INT_Set() {
    WPUB0 = false;
    INTE = false;
    PEIE = true;
    GIE = true;
}
//*********************************************************

inline void INT_ISR() {
    if (INTE == true && INTF == true) {
        INTF = false;
        //        INTE = false;
        setRF_ReceiveGO(1);
    }
}
//*********************************************************

void setINT_GO(char command) {
    INTF = false;
    INTE = command;
}
#endif
//*********************************************************

//*********************************************************
#if IOC_use == 1

void IOC_Set() {

    IOCBP = _IOCBP; //Positive
    IOCBN = _IOCBN; //Negative

    IOCBF = 0b00000000;

    IOCIE = true;
    IOCIF = false;
    PEIE = true;
    GIE = true;

}
//*********************************************************

inline void IOC_ISR() {

    if (myMain.PowerON == true) {

#if Dimmer_use == true

#ifdef use_1KEY
        //        setDimmerIntr_IOC(1);
        DimmerLights_IOC_1();
#endif

#ifdef use_2KEY
        //        setDimmerIntr_IOC(2);
        DimmerLights_IOC_2();
#endif

#ifdef use_3KEY
        setDimmerIntr_IOC(3);
#endif

#endif
    }

    IOCBF2 = false;
    IOCIF = false;
}

#endif

//*********************************************************
#if ADC_use == 1

void ADC_Set() {
    ADCON1 = _ADCON1;
    FVRCON = _FVRCON;
}
//*********************************************************
#ifdef MCU_16F723A

inline char getAD(char adcon0, char adcon1) {
    ADCON0 = adcon0;
    ADCON1 = adcon1;
    ADGO = true;
    while (ADGO == true && myMain.Timeout == false) {
        Timeout_Counter();
    };
    set_TimeoutCleared();
    return ADC_ADRES;
}
#endif

#ifdef MCU_16F1516

inline int getAD(char adcon0, char adcon1) {
    ADCON1 = adcon1;
    ADCON0 = adcon0;
    ADGO = true;
    while (ADGO == true && myMain.Timeout == false) {
        Timeout_Counter();
    };
    set_TimeoutCleared();
    return ADC_ADRES;
}
#endif
#ifdef MCU_16F1518

inline int getAD(char adcon0, char adcon1) {
    ADCON0 = adcon0;
    ADCON1 = adcon1;
    ADGO = true;
    while (ADGO == true && myMain.Timeout == false) {
        Timeout_Counter();
    };
    set_TimeoutCleared();
    return ADC_ADRES;
}
#endif
#endif
//*********************************************************

//*********************************************************
#if I2C_use == true

void I2C_Set() {
    I2C = &VarI2C;
#if Master_Mode == true
    SSPADD = 0x09; // Configure I2C for 100kHz operation
    SSPSTAT = 0x80; // Disable slew rate control and SMBus specific inputs
    SSPCON2 = 0; // Disable general call address
    //	SSPCON1 = 0x28;		// Enable serial port and I2C Master Mode
    SSPCON1 = 0b101000; //Enable serial port,I2C Master mode, clock = FOSC / (4 * (SSPADD+1))(4)
#endif

#if Slave_Mode == true
    SSPADD = 0x10;
    //	SSPOV=1;
    SSPSTAT = 0x80; // Disable slew rate control and disable SMBus specific inputs
    SSPCON2 = 0x80; // Enable general call address and disable clock stretching
    SSPCON1 = 0b100110; //Enable serial port,I2C Slave mode, 7-bit address

    SEN = true;
    AHEN = false;
    DHEN = false;
    SSPIE = true;
    PEIE = true;
    GIE = true;
#endif
}
//*********************************************************

void I2C_ISR() {
    if (SSPIE == true && SSPIF == true) {
        SSPIE = false;
        I2C->SlaveGO = true;
        //	I2C_Slave_Mode();
        //	while(SSPIE==false)
        //		SSPIE=true;
        //	SS1=false;
        //	I2C->SS=false;
    }
}
//*********************************************************

void I2C_Main() {
    char i = 0;
#if Slave_Mode == true
    if (I2C->SlaveGO == true) {
        I2C->SlaveGO = false;
        I2C_Slave_Mode();
        SSPIE = true;

        if (I2C->SlaveTxGO == true) {
            I2C->SlaveTxGO = false;
            SS1 = false;
            I2C->SS = false;
        }
        if (I2C->SlaveRxGO == true) {
            I2C->SlaveRxGO = false;
            I2C_SetData(0);
        }
        LED2 = LED2 == true ? true : false;
    }
#endif

#if Master_Mode == true

    if (I2C->MasterRxGO == true) {
        I2C->MasterRxGO = false;
        I2C_Master_Reception();
        myMain.Test = true;
        LED2 = LED2 == true ? true : false;
#if UART_use == true
        for (i = 0; i < 32; i++) {
            UART.TxData[i] = I2C->BufferReader[i];
        }
        UART.TxGO = true;
#endif
    } else {
        if (SS1 == true) {
            if (I2C->SS == false) {
                I2C->SS = true;
                I2C->MasterRxGO = true;
            }
        } else {
            if (I2C->SS == true) {
                I2C->SS = false;
            }
            if (I2C->MasterTxGO == true) {
                I2C->MasterTxGO = false;
                I2C_Master_Transmission();
            }
        }
    }

#endif
}

void I2C_SetData(char command)//for slave mode
{
#if CC2500_use == true
    char i = 0;
    if (command == true) {
        if (I2C->SS == false) {
            I2C->SS = true;
            for (i = 0; i < 21; i++) {
                I2C->BufferWriter[i + 1] = RF_Data[i];
            }
            I2C->BufferWriter[0] = Tx_Length;
            I2C->BufferWriter[22] = RSSI;
            I2C->BufferWriter[23] = CRC;
            SS1 = true;
        }
    } else {
#if CC2500_use == true
        for (i = 0; i < 21; i++) {
            RF_Data[i] = I2C->BufferReader[i];
        }
        RF->TransceiveGO = true;
#endif
    }
#endif

}
//*********************************************************

void I2C_Master_Transmission() {
    char i;
    while (SEN == true);
    SEN = true;

    while (SEN == true);
    //while(SSPIF==false);
    //	SSPIF=false;
    SSPBUF = 0x10;
    while (BF == true);
    //	while(SSPIF==false);
    //	SSPIF=false;
    while (ACKSTAT == true);

    for (i = 0; i < 32; i++) {
        while (SEN == true);
        SSPBUF = I2C->BufferWriter[i];
        while (BF == true);
        //	while(SSPIF==false);
        //	SSPIF=false;
        while (ACKSTAT == true);
    }

    while (SEN == true);
    while (PEN == false)
        PEN = true;
    while (PEN == true);
    //	while(SSPIF == false);
    //	SSPIF=false;
}
//*********************************************************

void I2C_Master_Reception() {
    char i = 0;
    while (SEN == true);
    SEN = true;
    while (SEN == true);
    //	while(SSPIF==false);
    //	SSPIF=false;
    SSPBUF = 0x11;
    //	while(SSPIF==false);
    //	SSPIF=false;
    while (BF == true);
    while (ACKSTAT == true);

    while (RCEN == true);
    RCEN = true;
    while (RCEN == true);
    I2C->Address = SSPBUF;
    while (ACKEN == false)
        ACKEN = true;
    while (ACKEN == true);
    while (RCEN == true);
    for (i = 0; i < 32; i++) {
        while (SEN == true);
        while (RCEN == true);
        RCEN = true;
        while (RCEN == true);
        I2C->BufferReader[i] = SSPBUF;
        while (ACKEN == false)
            ACKEN = true;
        while (ACKEN == true);

    }
    /*	while(RCEN==true);
            RCEN=true;
            while(RCEN==true);
            while(ACKEN==false)
                    ACKEN=true;
            while(ACKEN==true);
            while(RCEN==true);*/
    RCEN = true;
    while (RCEN == true);

    while (SEN == true);
    while (PEN == false)
        PEN = true;
    while (PEN == true);
    //	while(SSPIF==false);
    //	SSPIF=false;
}
//*********************************************************

void I2C_Slave_Mode() {
    char i = 0;
    SSPIF = false;
    I2C->Address = SSPBUF;

    if (R_nW == true)//write to master
    {
        SSPOV = false;

        for (i = 0; i < 32; i++) {
            SSPBUF = I2C->BufferWriter[i];
            //SSPOV=false;
            CKP = true;
            while (SSPIF == false);
            SSPIF = false;
            while (ACKSTAT == true);
        }
        CKP = true;
        //SSPOV=false;
        I2C->SlaveTxGO = true;
    } else {//read from master
        CKP = true;
        for (i = 0; i < 32; i++) {
            while (SSPIF == false);
            SSPIF = false;
            I2C->BufferReader[i] = SSPBUF;
            //SSPOV=false;
            CKP = true;
        }
        //SSPOV=false;
        CKP = true;
        I2C->SlaveRxGO = true;
    }

    //SPIE=true;
}
#endif
//*********************************************************


//*********************************************************
#if UART_use == true

void UART_Set() {
    //    UART = &VarUart;
    RX_PIN = 1;
    TX_PIN = 1;
    SPBRG = DIVIDER;
#ifndef MCU_16F723A
    SPBRGH = DIVIDER_H;
    BRG16 = BRG_16;
#endif
    RCSTA = (NINE_BITS | 0x90);
    TXSTA = (SPEED | NINE_BITS | 0x20);
    TX9 = 0;
    RX9 = 0;
    TXIE = false;
#if  UART_Rx_Enable_bit == 1
    RCIE = true;
    RCIF = false;
#endif

    PEIE = true;
    GIE = true;
}
//*********************************************************

void UART_ISR() {
    if (RCIE == true && RCIF == true) {
        RCIF = false;
        UART.RxAllow = true;
        if (UART.RxGO == false && UART.Count < UART_Data_Length) {
            UART.Data[UART.Count] = getch();
            UART.Count++;
            if (UART.Count == UART_Data_Length && UART.Data[UART_Data_Length - 1] == 0xed) {
                UART.Count = 0;
                UART.RxGO = true;
                UART.RxAllow = false;
            }
            UART.Time = 0;
        }


        //        for (int i = 0; i < UART_Data_Length; i++) {
        //            UART.Data[i] = getch();
        //        }

        //        UART.Data[UART.Count] = getch();
        //        UART.Count++;
        //        if (UART.Count == UART_Data_Length - 1) {
        //            UART.Count = 0;
        //            UART.RxGO = true;
        //        }
        //        LED1 = LED1 == true ? false : true;


    }
}

void UART_Main() {
    if (UART.RxGO == true) {
        UART.RxGO = false;
        UART_Receive();
        //        setSegmentDisplayNumber(UART.RxData[5]);
        //        ErrLED = ErrLED == true ? false : true;
        //        LED1 = LED1 == true ? false : true;
    } else {
        if (UART.TxGO == true) {
            UART.TxGO = false;
            UART_Transmit();
        }
    }
    if (UART.RxAllow == true) {
        UART.Time++;
        if (UART.Time == 5) {
            UART.Time = 0;
            UART.RxAllow = false;
            UART.Count = 0;
        }
    }
}

void UART_Transmit() {

    //    printf("%d,", UART.Data[0]);
    //    putch(UART.Data[0]);
    for (int i = 0; i < UART_Data_Length; i++) {
        //        printf("%d,", UART.Data[i]);
        putch(UART.Data[i]);
        //	while(!TRMT);
        //	while(!TXIF)	/* set when register is empty */
        //		continue;
        //	printf("%d,",i);
        //	TXREG = UART.TxData[i];
        //	TXREG=UART.TxData[i];
        //	printf(",");
    }
    //#ifdef _PIR_Ceiling_Embed_V1.1.2.1.3_H_
    //    ErrLED = ErrLED == true ? false : true;
    //#endif
    //    LED1 = LED1 == true ? false : true;

}

void UART_Receive() {
#ifdef  _UARTtoRF_H_ 
#if CC2500_use == 1
    //    for (int i = 0; i < UART_Data_Length; i++) {
    //        product->Data[2 + i] = UART.Data[i];
    //    }
    for (int i = 0; i < UART_Data_Length - 1; i++) {
        product->Data[i + 2] = UART.Data[i];
    }
    //#if UART_Data_Length == 8
    //    product->Data[2] = UART.Data[0];
    //    product->Data[3] = UART.Data[1];
    //    product->Data[4] = UART.Data[2];
    //    product->Data[5] = UART.Data[3];
    //    product->Data[6] = UART.Data[4];
    //    product->Data[7] = UART.Data[5];
    //    product->Data[8] = UART.Data[6];
    //    product->Data[9] = UART.Data[7];
    //#endif

    setTxData();

    LED1 = LED1 == true ? false : true;

#endif
#endif 
#if UART_Master == 1
    myMain.Test = 1;
#if I2C_use == 1
    for (i = 0; i < 32; i++) {
        I2C->BufferWriter[i] = UART.RxData[i];
    }
    I2C->MasterTxGO = 1;
#endif
#endif

#if UART_Slave == 1
    for (i = 0; i < 21; i++) {
        RF_Data[i] = UART.RxData[i];
    }
#endif
}

void UART_SetData() {
#if UART_Slave == 1
    for (int = 0; i < 21; i++) {
        UART.TxData[i] = RF_Data[i];
    }
    UART.TxGO = 1;
    LED2 = ~LED2;
#endif

#ifdef _UARTtoRF_H_
    UART.Data[0] = 1;
    UART.Data[UART_Data_Length - 1] = 0xed;
    UART.TxGO = true;
#endif

#ifdef _PIR_Ceiling_Embed_V1.1.2.1.3_H_
    if (UART.TxGO == false) {
        //        UART.Data[0] = 1;
        //        UART.Data[1] = 2;
        //        UART.Data[2] = 3;
        //        UART.Data[3] = 4;
        //        UART.Data[4] = 5;
        //        UART.Data[5] = 6;
        //        UART.Data[6] = 7;
        //        UART.Data[7] = 8;
        //        ErrLED = ErrLED == true ? false : true;
        UART.Data[UART_Data_Length - 1] = 0xed;
        UART.TxGO = true;
    }
#endif
}
//*********************************************************

void putch(unsigned char byte) {
    /* output one byte */
    while (!TXIF) /* set when register is empty */
        continue;
    TXREG = byte;
}
//*********************************************************

unsigned char getch() {
    /* retrieve one byte */
    while (!RCIF) /* set when register is not empty */
        continue;
    return RCREG;
}
//*********************************************************

unsigned char getche(void) {
    unsigned char c;
    putch(c = getch());
    return c;
}
#endif
//*********************************************************


//*********************************************************
#if FlashMemory_use == 1
//flash memry control

void Flash_Memory_Initialization() {
    char value = 0;
    if (Flash_Memory_Read(31) == 0xaa) {
        product->Data[12] = Flash_Memory_Read(0);
        product->Data[13] = Flash_Memory_Read(1);
        product->Data[14] = Flash_Memory_Read(2);
#if DimmerValue_SaveMemory == 1

        product->Data[21] = Flash_Memory_Read(3);
        product->Data[22] = Flash_Memory_Read(4);
        product->Data[23] = Flash_Memory_Read(5);
        //#else
        //        value = getDimmerLights_ValueToPercent(Dimmer_Maxum);
        //        product->Data[21] = value;
        //        product->Data[22] = value;
        //        product->Data[23] = value
#endif
        if (product->Data[12] == 0xff && product->Data[13] == 0xff && product->Data[14] == 0xff) {
            myMain.FirstOpen = true;
            myMain.First = true;
        }
    } else {

        setMemory_Data(0, 0xff);
        setMemory_Data(1, 0xff);
        setMemory_Data(2, 0xff);
        setMemory_Data(3, 0xff);
        setMemory_Data(4, 0xff);
        setMemory_Data(5, 0xff);
        setMemory_Data(31, 0xaa);
        //        value = getDimmerLights_ValueToPercent(Dimmer_Maxum);
        //        product->Data[21] = value;
        //        product->Data[22] = value;
        //        product->Data[23] = value;
        GIE = false;
        Flash_Memory_Write();
        GIE = true;
        myMain.FirstOpen = true;
        myMain.First = true;
        myMain.InitDimmer = true;
    }
}
//*********************************************************

void Flash_Memory_Main() {
    char key_Status = 0;
#if Switch_use == 1
    key_Status = getAll_Sw_KeyStatus();
#endif
    if (Memory.Modify == true) {
        Memory.GO = getMain_All_LightsStatus() == 0 && key_Status == 0 ? true : false;
        if (Memory.GO == true) {
            Memory.Runtime = true;
            Memory.Time++;
            if (Memory.Time == (200 / Main_Time)) {
                Memory.Time = 0;
                Memory.Modify = false;
                Memory.GO = false;
                Flash_Memory_Modify();
            }
        } else {
            if (Memory.Runtime == true) {
                Memory.Runtime = false;
                Memory.Time = 0;
            }
        }
    }
}
//*********************************************************

void Flash_Memory_Unlock() {
    PMCON2 = 0x55;
    PMCON2 = 0xaa;
    WR = true;
    NOP();
    NOP();
}
//*********************************************************

char Flash_Memory_Read(char address) {
    char i = 0, ret = 0;
    PMADRH = PMADRH_Value;
    PMADRL = address;
    CFGS = false;
    RD = true;
    i = PMDATH;
    ret = PMDATL;
    return ret;
}
//*********************************************************

void Flash_Memory_Write() {
    char i = 0;
    CFGS = false;
    PMADRH = PMADRH_Value;
    PMDATH = 0;
    FREE = false;
    LWLO = true;
    WREN = true;
    for (i = 0; i < 32; i++) {
        PMADRL = i;
        PMDATL = Memory.Data[i];
        Flash_Memory_Unlock();
    }
    LWLO = false;
    Flash_Memory_Unlock();
    WREN = false;
}
//*********************************************************

void Flash_Memory_Erasing() {
    CFGS = false;
    PMADRH = PMADRH_Value;
    PMADRL = 0x00;
    FREE = true;
    WREN = true;
    Flash_Memory_Unlock();
    WREN = false;
}
//*********************************************************

void Flash_Memory_Modify() {
    char i = 0;
    for (i = 0; i < 32; i++) {
        Memory.Data[i] = Flash_Memory_Read(i);
    }
    setMemory_Data(0, product->Data[12]);
    setMemory_Data(1, product->Data[13]);
    setMemory_Data(2, product->Data[14]);
#if DimmerValue_SaveMemory  == true
    setMemory_Data(3, product->Data[21]);
    setMemory_Data(4, product->Data[22]);
    setMemory_Data(5, product->Data[23]);
    if (myMain.SaveDimmer == true) {
        myMain.SaveDimmer = false;
        setMemory_Data(30, 0xaa);
    }
#endif
    if (Memory.LoopSave == true) {
        Memory.LoopSave = false;
        myMain.FirstOpen = false;
        myMain.First = false;
        //setMemory_Data(30,1);
    }
    GIE = false;
    Flash_Memory_Erasing();
    Flash_Memory_Write();
    GIE = true;
}
//*********************************************************

void setMemory_Modify(char command) {
    Memory.Modify = command == 1 ? true : false;
    Memory.Time = 0;
}
//*********************************************************

void setMemory_LoopSave(char command) {
    Memory.LoopSave = command == 1 ? true : false;
}
//*********************************************************

void setMemory_Data(char address, char data) {
    Memory.Data[address] = data;
}
#endif

//*********************************************************
#if WDT_use == 1

void WDT_Set() {
#ifdef MCU_16F723A
    PSA = _PSA;
    PS0 = _PS0;
    PS1 = _PS1;
    PS2 = _PS2;
#else
    WDTCON = _WDTCON;
#endif
    WDT.Enable = true;
    WDT.Timer = 10;
}
//*********************************************************

void WDT_Main() {
    if (WDT.Enable == true) {
        if (WDT.Timer-- > 0) {
            WDT.Timer = 100;
            WDT_Clearing();
        }
    }
}
//*********************************************************

void WDT_Clearing() {
    CLRWDT();
}
#endif
//*********************************************************

//end file


