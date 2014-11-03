//
// Header File Name:CC2500_tx4.h
//----------------------------------------------------------------------------
// Project Name: 2.4 GHz RF transceiver �V CC2500
// Module Name: RTX_LCM_FSK (DataRate2.4k) v1.0
//----------------------------------------------------------------------------
//
// Company:RIFO Technology Co.Ltd. 
//         http://www.rifo.com.tw/
//
// Engineer: Dominic
// Create Date:04/15/2008 
// Revision: 1.0
//
// Description: CC2500 DataRate2.4k
//              Fixed Length, No Address ID
//                                           
// 
// Target Devcies: C8051F330
//
// Tool Chain: KEIL Eval 'c'
// Copyright RIFO Technology Co.Ltd.All Rights Reserved
//
//--------------------------------------------------------------------------------------------------------------------
// Header File Preprocessor Directive
//-----------------------------------------------------------------------------

#ifndef DEFINE_H
#define DEFINE_H
#if CC2500_use == 1

//-----------------------------------------------------------------------------
// CC2500 register address
//-----------------------------------------------------------------------------
#define CC2500_IOCFG2     0x00  // GDO2 output pin configuration Set register IOCFG2( 0x00 ) = 0x02�ASet CC2500 GDO2 TX Underflow ourput
#define CC2500_IOCFG1     0x01  // GDO1 output pin configuration 
#define CC2500_IOCFG0D    0x02  // GDO0 output pin configuration
#define CC2500_FIFOTHR    0x03  // Set register FIFOTHR( 0x03 ) = 0x0C�ATXFIFO Smaller than13 bytes Underflow 
#define CC2500_SYNC1      0x04  // SYNC1 ( 0x04 )  
#define CC2500_SYNC0      0x05  // SYNC0 ( 0x05 ) Set up the materials with register ( default )
#define CC2500_PKTLEN     0x06  // Packet length : Set CC250 PKTLEN ( 0x06 ) = Length of the materials received  ( Include address Length  )
#define CC2500_PKTCTRL1   0x07  // Packet automation control
#define CC2500_PKTCTRL0   0x08  // Packet automation control
#define CC2500_ADDR       0x09  // Device address
#define CC2500_CHANNR     0x0A  // Channel number: CHANNR ( 0x0A )register�ARevise the setting up value and change frequency promptly 
#define CC2500_FSCTRL1    0x0B  // Frequency synthesizer control.
#define CC2500_FSCTRL0    0x0C  // Frequency synthesizer control.
#define CC2500_FREQ2      0x0D  // Frequency control word, high byte
#define CC2500_FREQ1      0x0E  // Frequency control word, middle byte
#define CC2500_FREQ0      0x0F  // Frequency control word, low byte
#define CC2500_MDMCFG4    0x10  // Modem configuration
#define CC2500_MDMCFG3    0x11  // Modem configuration
#define CC2500_MDMCFG2    0x12  // Modem configuration
#define CC2500_MDMCFG1    0x13  // Modem configuration
#define CC2500_MDMCFG0    0x14  // Modem configuration
#define CC2500_DEVIATN    0x15  // Modem deviation setting (when FSK modulation is enabled).
#define CC2500_MCSM2      0x16  // Main Radio Control State Machine configuration
#define CC2500_MCSM1      0x17  // Main Radio Control State Machine configuration
#define CC2500_MCSM0      0x18  // Main Radio Control State Machine configuration
#define CC2500_FOCCFG     0x19  // Frequency Offset Compensation Configuration.
#define CC2500_BSCFG      0x1A  // Bit synchronization Configuration.
#define CC2500_AGCCTRL2   0x1B  // AGC control
#define CC2500_AGCCTRL1   0x1C  // AGC control
#define CC2500_AGCCTRL0   0x1D  // AGC control
#define CC2500_WOREVT1    0x1E  // High byte Event0 timeout
#define CC2500_WOREVT0    0x1F  // Low byte Event0 timeout
#define CC2500_WORCTRL    0x20  // Wake On Radio control
#define CC2500_FREND1     0x21  // // Front and TX configuration
#define CC2500_FREND0     0x22  // Front and TX configuration
#define CC2500_FSCAL3     0x23  // Frequency synthesizer calibration.
#define CC2500_FSCAL2     0x24  // Frequency synthesizer calibration.
#define CC2500_FSCAL1     0x25  // Frequency synthesizer calibration.
#define CC2500_FSCAL0     0x26  // Frequency synthesizer calibration.
#define CC2500_RCCTRL1    0x27
#define CC2500_RCCTRL0    0x28
#define CC2500_FSTEST     0x29  // Frequency synthesizer calibration.
#define CC2500_PTEST      0x2A
#define CC2500_AGCTEST    0x2B
#define CC2500_TEST2      0x2C  // Various test settings.
#define CC2500_TEST1      0x2D  // Various test settings.
#define CC2500_TEST0      0x2E  // Various test settings.
#define CC2500_PARTNUM    0x30
#define CC2500_VERSION    0x31
#define CC2500_FREQEST    0x32
#define CC2500_LQI        0x33
#define CC2500_RSSI       0x34  // Received signal strength indication
#define CC2500_MARCSTATE  0x35
#define CC2500_WORTIME1   0x36
#define CC2500_WORTIME0   0x37
#define CC2500_PKTSTATUS  0x38
#define CC2500_VCO_VC_DAC 0x39
#define CC2500_TXBYTES    0x3A
#define CC2500_RXBYTES    0x3B  // Overflow and number of bytes
#define CC2500_PATABLE    0x3E
#define CC2500_TXFIFO     0x3F
#define CC2500_RXFIFO     0x3F

//-----------------------------------------------------------------------------
//CC2500 command
//-----------------------------------------------------------------------------
#define CC2500_SRES       0x30  // Reset
#define CC2500_SFSTXON    0x31
#define CC2500_SXOFF      0x32
#define CC2500_SCAL       0x33  // Lock it frequently 
#define CC2500_SRX        0x34  // Receive MODE
#define CC2500_STX        0x35  // Transmission MODE
#define CC2500_SIDLE      0x36  // sidle MODE
#define CC2500_SAFC       0x37
#define CC2500_SWOR       0x38  // WOR MODE
#define CC2500_SPWD       0x39  // sleep MODE
#define CC2500_SFRX       0x3A  // REMOVE RXFIFO DATA
#define CC2500_SFTX       0x3B  // REMOVE TXFIFO DATA
#define CC2500_SWORRST    0x3C  // REMOVE WOR TIMER 
#define CC2500_SNOP       0x3D

//-----------------------------------------------------------------------------
//CC2500 setting Registers data
//-----------------------------------------------------------------------------
#define D_FSTEST          0x59  //FSTEST register value
#define D_PTEST           0x7F  //PTEST register value
#define D_AGCTEST         0x3F  //AGCTEST register value
#define D_TEST2           0x81  //TEST2 register value
#define D_TEST1           0x35  //TEST1 register value
#define D_TEST0           0x0B  //TEST0 register value
#define D_IOCFG0D         0x06  //IOCFG0D register value
#define D_MCSM2           0x00  //MCSM2 register value
#define D_WORCTRL         0x00  //WORCTRL register value
#define D_PKTLEN          0x30  //PKTLEN register value

//-----------------------------------------------------------------------------
//CC2500 register data table
//-----------------------------------------------------------------------------
/* Chipcon */
/* Product = CC2500 */
/* Chip version = E */
/* Crystal accuracy = 10 ppm */
/* X-tal frequency = 26 MHz */
/* RF output power = 0 dBm */
/* RX filterbandwidth = 541.666667 kHz */
/* Phase = 1 */
/* Datarate = 249.938965 kbps */
/* Modulation = (7) MSK */
/* Manchester enable = (0) Manchester disabled */
/* RF Frequency = 2432.999908 MHz */
/* Channel spacing = 199.951172 kHz */
/* Channel number = 0 */
/* Optimization = Sensitivity */
/* Sync mode = (3) 30/32 sync word bits detected */
/* Format of RX/TX data = (0) Normal mode, use FIFOs for RX and TX */
/* CRC operation = (1) CRC calculation in TX and CRC check in RX enabled */
/* Forward Error Correction = (0) FEC disabled */
/* Length configuration = (1) Fixed length packets, packet length configured by the first received byte after sync word. */
/* Packetlength = 9 */
/* Preamble count = (2)  4 bytes */
/* Append status = 1 */
/* Address check =  */
/* FIFO autoflush = 0 */
/* Device address = 2 */
/* GDO0 signal selection = ( 6) Asserts when sync word has been sent / received, and de-asserts at the end of the packet */
/* GDO2 signal selection = (11) Serial Clock */
const unsigned char CC2500_rfSettings[47] ={

    //Join by oneself CC2500 registers data
    0x07, //1* FIFOTHR
    0x07, //2* MCSM2
    0x30, //3* MCSM1
    0x87, //4* WOREVT1
    0x6B, //5* WOREVT0
    0xF8, //6* WORCTRL
    0x7F, //7* PTEST
    0x3F, //8* AGCTEST
    //SmartRF Conversion CC2500 registers data
    0x09, //9*  FSCTRL1   Frequency synthesizer control.
    0x00, //10* FSCTRL0   Frequency synthesizer control.
    0x5C, //11* FREQ2     Frequency control word, high byte.   	//92
    0xA7, //12* FREQ1     Frequency control word, middle byte. 	//167
    0x62, //13* FREQ0     Frequency control word, low byte.		//98
    0x86, //14* MDMCFG4   Modem configuration.
    0x83, //15* MDMCFG3   Modem configuration.
    0x03, //16* MDMCFG2   Modem configuration.
    0x22, //17* MDMCFG1   Modem configuration.
    0xF8, //18* MDMCFG0   Modem configuration.
    0x00, //19* CHANNR    Channel number.
    0x44, //20* DEVIATN   Modem deviation setting (when FSK modulation is enabled).
    0xB6, //B6 56 21* FREND1    Front end RX configuration.
    0x10, //22* FREND0    Front end RX configuration.
    0x18, //23* MCSM0     Main Radio Control State Machine configuration.
    0x1D, //1D 16 24* FOCCFG    Frequency Offset Compensation Configuration.
    0x1C, //1C 6c 25* BSCFG     Bit synchronization Configuration.
    0xC7, //C7 03 26* AGCCTRL2  AGC control.
    0x00, //00 40 27* AGCCTRL1  AGC control.
    0xB2, //B2 91 28* AGCCTRL0  AGC control.
    0xEA, //RA A9 29* FSCAL3    Frequency synthesizer calibration.
    0x0A, //30* FSCAL2    Frequency synthesizer calibration.
    0x00, //31* FSCAL1    Frequency synthesizer calibration.
    0x11, //32* FSCAL0    Frequency synthesizer calibration.
    0x59, //33* FSTEST    Frequency synthesizer calibration.
    0x88, //34* TEST2     Various test settings.
    0x31, //35* TEST1     Various test settings.
    0x0B, //36* TEST0     Various test settings.
    0x2F, //37* IOCFG2    GDO2 output pin configuration.
    0x2E, //38* IOCFG1	GDO1 output pin configuration.
    0x06, //39* IOCFG0D   GDO0 output pin configuration. Refer to SmartRF?Studio User Manual for detailed pseudo register explanation.
    0x04, //40* PKTCTRL1  Packet automation control.
    0x05, //41* PKTCTRL0  Packet automation control.
    0x00, //42* ADDR      Device address.
    0x30, //43* PKTLEN    Packet length.
    0xD3, //44* SYNC1 	( 0x04 )
    0x91, //45* SYNC0	 	( 0x05 ) Set up the materials with register ( default )
    0x41, //46* RCCTRL1
    0x00 //47* RCCTRL0

};
//-----------------------------------------------------------------------------
//CC2500 Registers address table
//-----------------------------------------------------------------------------
const unsigned char CC2500_registers_address[47] ={
    //Join by oneself CC2500 registers data As to registers address
    CC2500_FIFOTHR, //1
    CC2500_MCSM2, //2
    CC2500_MCSM1, //3
    CC2500_WOREVT1, //4
    CC2500_WOREVT0, //5
    CC2500_WORCTRL, //6
    CC2500_PTEST, //7
    CC2500_AGCTEST, //8
    //SmartRF Conversion CC2500 registers data As to registers address
    CC2500_FSCTRL1, //9
    CC2500_FSCTRL0, //10
    CC2500_FREQ2, //11
    CC2500_FREQ1, //12
    CC2500_FREQ0, //13
    CC2500_MDMCFG4, //14
    CC2500_MDMCFG3, //15
    CC2500_MDMCFG2, //16
    CC2500_MDMCFG1, //17
    CC2500_MDMCFG0, //18
    CC2500_CHANNR, //19
    CC2500_DEVIATN, //20
    CC2500_FREND1, //21
    CC2500_FREND0, //22
    CC2500_MCSM0, //23
    CC2500_FOCCFG, //24
    CC2500_BSCFG, //25
    CC2500_AGCCTRL2, //26
    CC2500_AGCCTRL1, //27
    CC2500_AGCCTRL0, //28
    CC2500_FSCAL3, //29
    CC2500_FSCAL2, //30
    CC2500_FSCAL1, //31
    CC2500_FSCAL0, //32
    CC2500_FSTEST, //33
    CC2500_TEST2, //34
    CC2500_TEST1, //35
    CC2500_TEST0, //36
    CC2500_IOCFG2, //37
    CC2500_IOCFG1, //38
    CC2500_IOCFG0D, //39
    CC2500_PKTCTRL1, //40
    CC2500_PKTCTRL0, //41
    CC2500_ADDR, //42
    CC2500_PKTLEN, //43
    CC2500_SYNC1, //44
    CC2500_SYNC0, //45
    CC2500_RCCTRL1, //46
    CC2500_RCCTRL0 //47
};

//-----------------------------------------------------------------------------
// Global VARIABLES
//-----------------------------------------------------------------------------
 
//bit CC2500_Enable;

//bit Transceive_GO, Receive_GO;
//bit TxStatus, RxStatus;
unsigned int RF_Count;
unsigned char SPI0Buffer;
unsigned char r_data; //register data
unsigned char s_data; //status data
unsigned char r_address;
unsigned char RF_Data[30];
unsigned char RSSI;
unsigned char CRC;
unsigned char Rx_Length;
unsigned char Tx_Length;
//-----------------------------------------------------------------------------
//CC2500 PA TABLE
//-----------------------------------------------------------------------------

const unsigned char CC2500_patable_vaule[8] = {0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE};

void CC2500_PowerOnInitial();
void CC2500_PowerRST(void);
void CC2500_InitSetREG(void);
void CC2500_InitPATable(void);
void CC2500_ClearTXFIFO(void);
void CC2500_ClearRXFIFO(void);
void CC2500_FrequencyCabr(void);
inline void CC2500_SIDLEMode(void);

inline void CC2500_WriteByte(void);
inline void CC2500_WriteREG(unsigned char addr, unsigned char value);
inline void CC2500_ReadByte(void);
inline void CC2500_ReadREG(unsigned char addr);
inline void CC2500_ReadStatus(unsigned char s_addr);
inline void CC2500_WriteCommand(unsigned char command);
inline void CC2500_TxData();
inline void CC2500_RxData(void);
void DelayTime_1us(int count);
#else
#define CC2500_PowerOnInitial() NOP()
#define CC2500_PowerRST(void) NOP()
#define CC2500_InitSetREG(void) NOP()
#define CC2500_InitPATable(void) NOP()
#define CC2500_ClearTXFIFO(void) NOP()
#define CC2500_ClearRXFIFO(void) NOP()
#define CC2500_FrequencyCabr(void) NOP()
#define CC2500_SIDLEMode(void) NOP()

#define CC2500_WriteByte(void) NOP()
#define CC2500_WriteREG char,char) NOP()
#define CC2500_ReadByte(void) NOP()
#define CC2500_ReadREG(char) NOP()
#define CC2500_ReadStatus(char) NOP()
#define CC2500_WriteCommand(char) NOP()
#define CC2500_TxData() NOP()
#define CC2500_RxData(void) NOP()
#define DelayTime_1us(int) NOP()

#endif 

//-----------------------------------------------------------------------------
// Function PROTOTYPES
//-----------------------------------------------------------------------------


#endif                               
//-----------------------------------------------------------------------------
// End Of File
//-----------------------------------------------------------------------------