
#ifndef _UARTtoRF_H_
#define _UARTtoRF_H_

/**Version information
                Name_Version 			:	1~255

                Name_SerialNumber		:	1~255
 
                Properties_Product		:	1:Switch
                                                        2:PIR

                Properties_Keys			:	1:1key
                                                        2:2key
                                                        3:3key

                Properties_Country		:	1:USA
                                                        2:EP
                                                        3:TW
                                                        4:CHI
 **/

#define	Name_Version_Value 		0	//1
#define Name_SerialNumber_Value		0	//2
#define Properties_Product_Value	0	//3
#define Properties_Keys_Value		0	//4
#define Properties_Country_Value	0	//5

//Control Option
#define Control_Method_Mosfet_Value         0
#define Control_Method_Triac_Value          0
#define Control_Method_Relay_Value          0
#define Control_Method_TriacRelay_Value     0
#define Properties_Neutral_Value            0
#define Properties_Dimmer_Value             0
#define Debug_Value                         1

#define Create_Date "2014/11/26"
#define PCB_Name "Sample"

//MCU define
#define	PowerLED			RA0		//pin2  1
#define LED1    			RA1		//pin3	1
#define LED2				RA2		//pin4	1
#define	PinEmpty5        		RA3		//pin5	0
#define	Key1_2				RA4		//pin6 	1	
#define PFV1				RA5		//pin7	1
#define	Key1_1				RA6		//pin10 1			
#define	Key1_4                  	RA7		//pin9	1

#define TTPW    			RB0		//pin21 0
#define PinEmpty6			RB1		//pin22 0
#define DimmerReference1                RB2		//pin23 1
#define Buzzer1				RB3		//pin24	0
#define Mosfet1                         RB4		//pin25 0
#define ErrLED				RB5		//pin26	0
#define PinEmpty1			RB6		//pin27	0	
#define PinEmpty2			RB7		//pin28 0	

#define CC2500_CSN 			RC0		//pin11	0
#define CC2500_GDO0                     RC1		//pin12	1
#define CC2500_GDO2 			RC2		//pin13	1
#define	CC2500_SCK                  	RC3		//pin14	0
#define CC2500_SI   			RC4		//pin15	0
#define	CC2500_SO			RC5		//pin16	1
#define UART_TX                      	RC6		//pin17	0
#define	UART_RX                      	RC7		//pin18	0

//I/O
#define _TRISA 	0b00000000;
#define _TRISB 	0b00000000;
#define _TRISC 	0b11100110;
#define _LATA	0b00000000;
#define _LATB	0b00000000;
#define _LATC	0b00000000;
#define _ANSELA 0b00000000;
#define _ANSELB 0b00000000;
#define _ANSELC 0b00000000;
#define _PORTA 	0b00000000;
#define _PORTB 	0b00000000;
#define _PORTC 	0b11100110;

//ADC channel
#define OverLoad_Channel		AN1
#define OverTemp_Channel		AN2
#define PFV_Channel			AN4

//Mcu Function Option

//Oscillator (System FOSC)
#define	System_Fosc_16M
//MCU
#define MCU_16F1516
//interrupt time
#define IntrTime_100us
//ADC
#define ADC_use_Value 0
//Timer0
#define Timer0_use_Value	0
//Timer1
#define Timer1_use_Value	1
//Timer2 
#define Timer2_use_Value	0
//INT
#define INT_use_Value   0
//UART
#define UART_use_Value              1
#define UART_Master_Value           1
#define UART_Slave_Value            0
#define UART_Data_Length_Vallue     8
#define BAUD 19200
//I2C
#define I2C_use_Value       0
#define Master_Mode_Value   1
#define Slave_Mode_Value    0
//IOC
#define IOC_use_Value 0
//FlashMemory
#define FlashMemory_use_Value 0
//Watchdog timer 
#define WDT_use_Value 0


//Function Option

//SYSC
#define SYSC_use_Value 0
//OverTemperature
#define OverTemperature_use_Value   0
#define TempDangerValue_Value       415   //NTC 70度
#define TempSafeValue_Value         455   //NTC 61度
//OverLoad
#define OverLoad_use_Value 0
#define LimitCurrent_Value  1.8//A
#define LinearParam_Value   55
//LED
#define LED_use_Value 0
//Buzzer
#define Buzzer_use_Value 0
//Switch
#define Switch_use_Value 0
//Lights
#define LightsControl_use_Value 0
//RF cc2500
#define CC2500_use_Value        1
#define Tx_Enable 	1
#define Rx_Enable 	0
//DelayOff
#define DelayOff_use_Value      0
//PowerFault
#define PowerFault_use_Value    0
//Dimmer Lights
#define Dimmer_use_Value            0
#define Dimmer_Half_Wave_Value      1
#define Dimmer_Full_Wave_Value      0
//SegmentDisplay
#define SegmentDisplay_use_Value    0
//CDS
#define CDS_use_Value   0
//PIR
#define PIR_use_Value   0
//UART to RF
#define myUARTtoRF_use_Value 1

//include
#include "../src/Activity_B1.h"
#include "../src/MCU_B1.h"
#include "../src/Main_B1.h"
#include "../src/Switch_B1.h"
#include "../src/Buzzer_B1.h"
#include "../src/LED_B1.h"
#include "../src/OverTemperature_B1.h"
#include "../src/CC2500_B1.h"
#include "../src/RF_Control_B1.h"
#include "../src/OverLoad_B1.h"
#include "../src/Dimmer_B1.h"
#include "../src/DelayOff_B1.h"
#include "../src/PowerFault_B1.h"
#include "../src/CDS_B1.h"
#include "../src/PIR_B1.h"
#include "../src/SYSC_B1.h"
#include "../src/TriacRelay_B1.h"
#include "../src/SegmentDisplay_A2.h"
#include "../src/myUARTtoRF.h"
//end file
#endif