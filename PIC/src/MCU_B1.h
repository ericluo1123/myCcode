
#ifndef _MCU_H_
#define _MCU_H_

//*********************************************************
//Include 
#include <xc.h>
void interrupt ISR(void);
//#pragma interrupt ISR nosave=section(".tmpdata")  //儲存 temp data 區的資料

//*********************************************************	
//Routine declaration
/**
 * void Mcu_Initialization()\n
 * MCU initialization\n
 */
void Mcu_Initialization();
/**
 * void IO_Set()\n
 * I/O value setting\n
 */
void IO_Set();

//*********************************************************
//oscillator
//System Clock Select=FOSC<2:0>

#ifdef MCU_16F723A
//PLLEN = 1
#ifdef System_Fosc_16M
#define _OSCCON 0x3c
#define _FOSC 16000000L
#define _PLLEN ON
#endif

#ifdef System_Fosc_8M									
#define _OSCCON 0x2c
#define _FOSC 8000000L
#define _PLLEN ON
#endif

#ifdef System_Fosc_4M
#define _OSCCON 0x1c
#define _FOSC 4000000L
#define _PLLEN ON
#endif

#ifdef System_Fosc_2M
#define _OSCCON 0x0c
#define _FOSC 2000000L
#define _PLLEN ON
#endif

//PLLEN = 0
#ifdef System_Fosc_500K
#define	_OSCCON	0x30
#define _FOSC 500000L
#define _PLLEN OFF
#endif 

#ifdef System_Fosc_250K
#define _OSCCON 0x20
#define _FOSC 250000L
#define _PLLEN OFF
#endif

#ifdef System_Fosc_125K
#define _OSCCON 0x10
#define _FOSC 125000L
#define _PLLEN OFF
#endif

#ifdef System_Fosc_62.5K	
#define _OSCCON 0x00
#define _FOSC 62500L
#define _PLLEN OFF
#endif

#endif

#ifdef MCU_16F1516
#ifdef System_Fosc_16M
#define _OSCCON 0x78
#define _FOSC 16000000L
#endif

#ifdef System_Fosc_8M									
#define _OSCCON 0x38
#define _FOSC 8000000L
#endif

#ifdef System_Fosc_4M
#define _OSCCON 0x68
#define _FOSC 4000000L
#endif

#ifdef System_Fosc_2M
#define _OSCCON 0x60
#define _FOSC 2000000L
#endif

#ifdef System_Fosc_1M
#define _OSCCON 0x58
#define _FOSC 1000000L
#endif

#ifdef System_Fosc_500K
#define	_OSCCON	0x50
#define _FOSC	500000L
#endif 

#ifdef System_Fosc_250K
#define _OSCCON 0x18
#define _FOSC	250000L
#endif

#ifdef System_Fosc_125K
#define _OSCCON 0x40
#define _FOSC	125000L
#endif

#ifdef System_Fosc_500K_Default
#define	_OSCCON	0x38
#define _FOSC	500000L
#endif  

#ifdef System_Fosc_250K_Default
#define _OSCCON 0x30
#define _FOSC	250000L
#endif

#ifdef System_Fosc_125K_Default
#define _OSCCON 0x28
#define _FOSC	125000L
#endif

#ifdef System_Fosc_62.5K_Default	
#define _OSCCON 0x20
#define _FOSC	62500L
#endif

#ifdef System_Fosc_31.25K_Default	
#define _OSCCON 0x02
#define _FOSC	31250L
#endif

#ifdef System_Fosc_31K_Default	
#define _OSCCON 0x00
#define _FOSC	31000L
#endif	

#endif

#ifdef MCU_16F1518
#ifdef System_Fosc_16M
#define _OSCCON 0x78
#define _FOSC 16000000L
#endif

#ifdef System_Fosc_8M									
#define _OSCCON 0x38
#define _FOSC 8000000L
#endif

#ifdef System_Fosc_4M
#define _OSCCON 0x68
#define _FOSC 4000000L
#endif

#ifdef System_Fosc_2M
#define _OSCCON 0x60
#define _FOSC 2000000L
#endif

#ifdef System_Fosc_1M
#define _OSCCON 0x58
#define _FOSC 1000000L
#endif

#ifdef System_Fosc_500K
#define	_OSCCON	0x50
#define _FOSC	500000L
#endif 

#ifdef System_Fosc_250K
#define _OSCCON 0x18
#define _FOSC	250000L
#endif

#ifdef System_Fosc_125K
#define _OSCCON 0x40
#define _FOSC	125000L
#endif

#ifdef System_Fosc_500K_Default
#define	_OSCCON	0x38
#define _FOSC	500000L
#endif 

#ifdef System_Fosc_250K_Default
#define _OSCCON 0x30
#define _FOSC	250000L
#endif

#ifdef System_Fosc_125K_Default
#define _OSCCON 0x28
#define _FOSC	125000L
#endif

#ifdef System_Fosc_62.5K_Default	
#define _OSCCON 0x20
#define _FOSC	62500L
#endif

#ifdef System_Fosc_31.25K_Default	
#define _OSCCON 0x02
#define _FOSC	31250L
#endif

#ifdef System_Fosc_31K_Default	
#define _OSCCON 0x00
#define _FOSC	31000L
#endif	
#endif

void Fosc_Set();

//*********************************************************
//ADC
#if ADC_use == 1
#define	ADGO	GO_nDONE

#define	AN0	0x01 	//RA0		
#define	AN1	0x05	//RA1		
#define	AN2	0x09	//RA2			
#define	AN3	0x0d	//RA3	
#define	AN4	0x11	//RA5	

#define	AN8	0x21	//RB2		
#define	AN9	0x25	//RB3		
#define	AN10	0x29	//RB1		
#define	AN11	0x2d	//RB4		
#define	AN12	0x31	//RB0		
#define	AN13	0x35	//RB5

#define	AN14	0x39	//RC2
#define	AN15	0x3d	//RC3
#define	AN16	0x41	//RC4
#define	AN17	0x45	//RC5
#define	AN18	0x4d	//RC6
#define	AN19	0x51	//RC7

//ADC Conversion Clock = 111 = FRC (clock supplied from a dedicated FRC oscillator)

#ifdef MCU_16F723A
#define	ADCON1_VDD		0x70 
#define	ADCON1_RA3		0x72
#define	ADCON1_Fixed		0x73

#define	FVRCON_Off		0x00
#define	FVRCON_1V		0xc1
#define	FVRCON_2V		0xc2
#define	FVRCON_4V		0xc3

#define ADC_ADRES               ADRES
#endif

#ifdef MCU_16F1516
#define	ADCON1_VDD		0xf0 
#define	ADCON1_RA3		0xf2
#define	ADCON1_Fixed		0xf3

#define	FVRCON_Off      	0xc0
#define	FVRCON_1V               0xc1
#define	FVRCON_2V		0xc2
#define	FVRCON_4V		0xc3

#define ADC_ADRES ((ADRESH*256)+ADRESL)
#endif

#ifdef MCU_16F1518
#define	ADCON1_VDD		0xf0 
#define	ADCON1_RA3		0xf2
#define	ADCON1_Fixed		0xf3

#define	FVRCON_Off      	0xc0
#define	FVRCON_1V               0xc1
#define	FVRCON_2V		0xc2
#define	FVRCON_4V		0xc3

#define ADC_ADRES ((ADRESH*256)+ADRESL)
#endif

void ADC_Set();
void setADCGO();
#ifdef MCU_16F723A
inline char getAD(char, char);
#endif
#ifdef MCU_16F1516
inline int getAD(char, char);
#endif
#ifdef MCU_16F1518
inline int getAD(char, char);
#endif
#else
//ADC NOP()
#define setADCON1(value) ;
#define setADCON0(value) ;
#define ADC_ADRES 0

#define ADC_Set() ;
#define getAD(char,char) ;
#define setADCGO() ;
#endif
//*********************************************************
//Timer0
#if Timer0_use == 1
//OPTION_REG
#define	T0PS_1x2		0x00
#define	T0PS_1x4		0x01
#define	T0PS_1x8		0x02
#define	T0PS_1x16		0x03
#define	T0PS_1x32		0x04
#define	T0PS_1x64		0x05
#define	T0PS_1x128		0x06
#define	T0PS_1x256		0x07

#ifdef System_Fosc_16M		
//TMR0 Clock Source Select Internal instruction cycle clock (FOSC/4)
//Prescaler is assigned to the Timer0 module

#ifdef IntrTime_50us	//interrupt time= (1/(System_Fosc/4)) * T0PS * TMR0_Count
#define  OPTION_REG_Value T0PS_1x2
#define TMR0_Count	90	
#define TMR0_1ms	20	
#define TMR0_5ms	100
#define TMR0_10ms	200
#endif

#ifdef IntrTime_100us
#define  OPTION_REG_Value T0PS_1x2
#define TMR0_Count	190
#define TMR0_1ms	10
#define TMR0_5ms	50
#define TMR0_10ms	100
#endif

#ifdef IntrTime_150us
#define  OPTION_REG_Value T0PS_1x4
#define TMR0_Count	140
#define TMR0_1ms	6
#define TMR0_5ms	33
#define TMR0_10ms	66
#endif

#ifdef IntrTime_200us
#define  OPTION_REG_Value T0PS_1x4
#define TMR0_Count	190
#define TMR0_1ms	5
#define TMR0_5ms	25
#define TMR0_10ms	50
#endif

#endif

#define TMR0_Value	(256-TMR0_Count)
//Virable declaration

struct Timer0 {

    struct {
        unsigned Timeout : 1;
        unsigned Reset : 1;
        unsigned empty : 5;
    };

    unsigned int Count;
    unsigned int Count1;

    unsigned int DimmerCount;
    unsigned char ResetCount;
};
//Virable declaration
struct Timer0 Timer0;
//struct Timer0 *Timer0;

void TMR0_Set();
inline void TMR0_ISR();
inline void setDimmerReClock();
#else
//TMR0 NOP()
#define TMR0_Set() ;
#define TMR0_ISR() ;
#endif

//*********************************************************
//Timer1
#if Timer1_use == 1

#define T1PS_1x1	0x00	
#define T1PS_1x2	0x10
#define T1PS_1x4	0x20
#define T1PS_1x8	0x30

#ifdef Clock_Source_System
#define _CS             0x40
#endif


#ifdef Clock_Source_instruction
#define _CS 0x00	
#endif

#ifdef System_Fosc_16M	
#define _CKPS T1PS_1x1

#ifdef IntrTime_50us	//interrupt time= (1/System_Fosc) * T1PS * TMR1_Count
#define TMR1_Count	700	
#define TMR1_1ms	20
#define TMR1_5ms	100
#endif

#ifdef IntrTime_100us

#define TMR1_Count	1480
 
#define TMR1_Time       (int)(Main_Time*10)
#define TMR1_1ms	10
#define TMR1_5ms	50
#define TMR1_10ms	100
#define TMR1_20ms	200
#endif

#ifdef IntrTime_500us
#define TMR1_Count	7500
#define TMR1_1ms	2
#endif

#define _TMR1ON 0x01
#define TMR1H_Value 	(int)((65536-TMR1_Count)/256)
#define TMR1L_Value  	(int)((65536-TMR1_Count)%256)
#endif	

//Virable declaration

struct Timer1 {

    struct {
        unsigned Timeout : 1;
        unsigned empty : 7;
    };
    unsigned int Count;
};
struct Timer1 Timer1;

inline void TMR1_Set();
inline void TMR1_ISR();
#else
//NOP()
#define TMR1_Set() ;
#define TMR1_ISR() ;
#endif
//*********************************************************
#if Timer2_use == 1
#define TOUTPS_1x1  0x00
#define TOUTPS_1x2  0x08
#define TOUTPS_1x3  0x10
#define TOUTPS_1x4  0x18
#define TOUTPS_1x5  0x20
#define TOUTPS_1x6  0x28
#define TOUTPS_1x7  0x30
#define TOUTPS_1x8  0x38
#define TOUTPS_1x9  0x40
#define TOUTPS_1x10 0x48
#define TOUTPS_1x11 0x50
#define TOUTPS_1x12 0x58
#define TOUTPS_1x13 0x60
#define TOUTPS_1x14 0x68
#define TOUTPS_1x15 0x70
#define TOUTPS_1x16 0x78

#define T2CKPS_1x1  0x01
#define T2CKPS_1x4  0x10
#define T2CKPS_1x16 0x11

#ifdef IntrTime_100us
#define _TMR2 168
#define _PR2 0
#define _TMR2ON 0x04
#define _TOUTPS TOUTPS_1x4
#define _T2CKPS T2CKPS_1x1
#define TMR2_1ms	10
#define TMR2_5ms	50
#define TMR2_10ms	100
#endif

struct Timer2 {

    struct {
        unsigned Timeout : 1;
        unsigned empty : 7;
    };
    unsigned int Count;
};

struct Timer2 Timer2;

inline void TMR2_Set();
inline void TMR2_ISR();
inline void setDimmerReClock();

#else
//NOP()
#define TMR2_Set() ;
#define TMR2_ISR() ;
#endif
//*********************************************************
//INT		
#if INT_use == 1
void INT_Set();
inline void INT_ISR();
void setINT_GO(char command);
#else
//INT NOP()
#define INT_Set() ;
#define INT_ISR() ;
#define setINT_GO(char) ;
#endif

//*********************************************************
//IOC
#if IOC_use == 1
void IOC_Set();
inline void IOC_ISR();
#else
//NOP
#define IOC_Set() ;
#define IOC_ISR() ;
#endif
//*********************************************************
#if I2C_use == 1

struct I2C {
    unsigned char BufferReader[32];
    unsigned char BufferWriter[32];
    unsigned char Count;
    unsigned char Address;

    struct {
        unsigned SlaveGO : 1;
        unsigned SlaveRxGO : 1;
        unsigned SlaveTxGO : 1;
        unsigned MasterTxGO : 1;
        unsigned MasterRxGO : 1;
        unsigned SS : 1;
        unsigned empty : 2;
    };

}
struct I2C VarI2C;
struct I2C *I2C;

void I2C_Set();
void I2C_ISR();
void I2C_Master_Transmission();
void I2C_Master_Reception();
void I2C_Slave_Mode();
void I2C_Main();
void I2C_SetData(char command);


#else
#define I2C_Set() ;
#define I2C_ISR() ;
#define I2C_Master_Transmission() ;
#define I2C_Master_Reception() ;
#define I2C_Slave_Mode() ;
#define I2C_Main() ; 
#define I2C_SetData(char) ;
#endif
//*********************************************************
//UART
#if UART_use == 1

//#define BAUD 19200			//19200   9600   

#define NINE	0                       /* Use 9bit communication? FALSE=8bit */

#define SYNC	0			//0		EUSART Mode
//1
#define BRG_16	0			//0		16-bit Baud Rate Generator
//1	
#define HIGH_SPEED 1                    //0		High Baud Rate Select
//1

//setup
#if(SYNC_BIT == 0 && BRG_16 == 0 && HIGH_SPEED == 0)		
#define DIVIDER_H 0	
#define DIVIDER ((int)(_FOSC/(64UL * BAUD) -1))
#endif

#if(SYNC_BIT == 0 && BRG_16 == 0 && HIGH_SPEED == 1)
#define DIVIDER_H 0
#define DIVIDER ((int)(_FOSC/(16UL * BAUD) -1))
#endif

#if(SYNC_BIT == 0 && BRG_16 == 1 && HIGH_SPEED == 0)
#define DIVIDER_H ((int)((_FOSC/(16UL * BAUD) -1)/256))
#define DIVIDER ((int)((_FOSC/(16UL * BAUD) -1)%256))
#endif

#if(SYNC_BIT == 0 && BRG_16 == 1 && HIGH_SPEED == 1)
#define DIVIDER_H ((int)((_FOSC/(16UL * BAUD) -1)/256))
#define DIVIDER ((int)((_FOSC/(16UL * BAUD) -1)%256))
#endif

#if NINE == 1
#define NINE_BITS 0x40
#else
#define NINE_BITS 0
#endif

#if HIGH_SPEED == 1
#define SPEED 0x4
#else
#define SPEED 0
#endif

#if defined(_16F87) || defined(_16F88)
#define RX_PIN TRISB2
#define TX_PIN TRISB5
#else
#define RX_PIN TRISC7
#define TX_PIN TRISC6
#endif

//Global extern varitable declaration

struct UART {
    //    unsigned char TxData[32];
    //    unsigned char RxData[32];
    unsigned char Data[UART_Data_Length];
    unsigned char Count;
    unsigned char Time;

    struct {
        unsigned TxGO : 1;
        unsigned RxGO : 1;
        unsigned TxRun : 1;
        unsigned RxRun : 1;
        unsigned RxAllow : 1;
        unsigned empty : 3;
    };

};
struct UART UART;

void putch(unsigned char);
unsigned char getch(void);
unsigned char getche(void);
void UART_Set();
void UART_ISR();
void UART_Main();
void UART_Transmit();
void UART_Receive();
void UART_SetData();
#else
//NOP
#define setUart_TxData(data) ;

#define putch() ;
#define getch(void) ;
#define getche(void) ;
#define UART_Set() ;
#define UART_ISR() ;
#define UART_Main() ;
#define UART_Transmit() ;
#define UART_Receive() ;
#define UART_SetData() ;
#endif

//*********************************************************
//Flash Memory
#if FlashMemory_use == 1
//Global extern varitable declaration

struct FlashMemory {
    unsigned char Data[32];
    unsigned char ReadDataH;
    unsigned char ReadDataL;
    unsigned int Time;

    struct {
        unsigned Modify : 1;
        unsigned GO : 1;
        unsigned LoopSave : 1;
        unsigned Runtime : 1;
        unsigned empty : 4;
    };
};
struct FlashMemory Memory = {
    {
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
    }
};
#define PMADRH_Value 0x30

//#define setMemoryData(address,data) Memory.Data[address]=data
//#define setMemory_Modify(command) Memory.Modify=command
//#define setMemory_LoopSave(command) Memory.LoopSave=command

void Flash_Memory_Initialization();
void Flash_Memory_Unlock();
char Flash_Memory_Read(char address);
void Flash_Memory_Write();
void Flash_Memory_Erasing();
void Flash_Memory_Modify();
void Flash_Memory_Main();
void setMemory_Modify(char command);
void setMemory_LoopSave(char command);
void setMemory_Data(char address, char data);
#else
//NOP
#define Flash_Memory_Set() ;
#define setMemoryData(address,data) ;
#define setMemory_GO(char) ;
#define setMemory_Modify(command) ;
#define setMemory_LoopSave(command) ;

#define Flash_Memory_Initialization() ;
#define Flash_Memory_Unlock() ;
#define Flash_Memory_Read(char) ;
#define Flash_Memory_Write() ;
#define Flash_Memory_Erasing() ;
#define Flash_Memory_Modify() ;
#define Flash_Memory_Main() ;
#endif 
//*********************************************************
//WDT(watchdog timer)
#if WDT_use == 1

struct WDT {

    struct {
        unsigned Enable : 1;
        unsigned empty : 7;
    };
    unsigned char Timer;
};
struct WDT WDT;
//controlled by the WDTE<1:0>
#define _WDTE ON                        //Configuration
#ifdef MCU_16F723A

//Time-out period is from 17 ms to 2.2 seconds
#define _PSA 1
#define _PS0 1
#define _PS1 1
#define _PS2 1

#else  
#define _WDTCON 0b00010111;		//WDTPS<4:0> =2s && WDT is turned on
#endif



void WDT_Set();
void WDT_Main();
void WDT_Clearing();
#else
//NOP()
#define _WDTE OFF	//Configuration
#define WDT_Set() ;
#define WDT_Main() ;
#define WDT_Clearing() ;		
#endif

//end file
#endif