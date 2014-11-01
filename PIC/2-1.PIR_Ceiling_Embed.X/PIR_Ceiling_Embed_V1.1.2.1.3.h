
#ifndef _PIR_Ceiling_Embed_V1.1.2.1.3_H_	
#define	_PIR_Ceiling_Embed_V1.1.2.1.3_H_		

//Include
#include <stdio.h>


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

#define	Name_Version 			1	//1
#define Name_SerialNumber		1	//2
#define Properties_Product		2	//3
#define Properties_Keys			1	//4
#define Properties_Country		3	//5

//Control Option
#define Control_Method_Mosfet		0
#define Control_Method_Triac		0
#define Control_Method_Relay		0
#define Control_Method_TriacRelay	1
#define Properties_Neutral		0
#define Properties_Dimmer		0
#define Debug                           0
#define Create_Date "2014/10/20"
#define PCB_Name "TH-302PV11-1-Dim(20140722)"

#define MCU_16F723A
//MCU define
#define	OverLoad1			RA0		//pin2  1
#define PIR1_VR				RA1		//pin3	1	
#define CDS1_VR				RA2		//pin4	1		
#define	PIR_1				RA3		//pin5	1
#define	Relay1                    	RA4		//pin6 	0
#define SYSC1				RA5		//pin7	1
//#define Dimmer_Clock                  RA6		//pin10 0
//#define DimmerReference1              RA7		//pin9	0

#define CDS_1				RB0		//pin21 1
#define Buzzer1				RB1		//pin22 0
#define Triac1 				RB2		//pin23 0
#define ErrLED				RB3		//pin24	0
#define LED1				RB4		//pin25 0	LED pin2
#define LED2				RB5		//pin26	0	LED pin3
//#define 				RB6		//pin27	0	
//#define 				RB7		//pin28 0	

#define TLED1				RC0		//pin11	0	
#define TLED2				RC1		//pin12	0	
#define TLED3				RC2		//pin13	0		
#define	TLED4				RC3		//pin14	0	
//#define 				RC4		//pin15	0	
//#define	TestPoint		RC5		//pin16	0	
#define TX				RC6		//pin17	0	
#define	RX				RC7		//pin18	0


//I/O
#define _TRISA 	0b00101111;
#define _TRISB 	0b00000001;
#define _TRISC 	0b00000000;
#define _ANSELA 0b00000111;
#define _ANSELB 0b00000001;
#define _PORTA 	0b10101111;
#define _PORTB 	0b00000001;
#define _PORTC 	0b00000000;


//ADC channel
#define CDS_Signal_Channel		AN12
#define CDS_VR_Channel			AN2
#define PIR_Signal_Channel		AN3
#define PIR_VR_Channel			AN1
#define OverLoad_Channel		AN0
#define OverTemp_Channel		AN4

//Mcu Function Option

//ADC
#define ADC_use true
//Oscillator (System FOSC)
#define	System_Fosc_16M		//_16M
//Timer0
#define Timer0_use	false
#define TMR0_IntrTime_100us
//Timer1
#define Timer1_use	true
#define TMR1_IntrTime_100us
//Timer2
#define Timer2_use	false
#define TMR2_IntrTime_100us
//INT
#define INT_use false
//UART
#define UART_use false
#define UART_Master true
#define UART_Slave false
//I2C
#define I2C_use false
#define Master_Mode true
#define Slave_Mode false
//IOC
#define IOC_use false
//FlashMemory
#define FlashMemory_use false
//watchdog timer
#define WDT_use true

//Function Option

//SYSC
#define SYSC_use true
//OverTemperature
#define OverTemperature_use true
#define Cut_Off_electricity true
//OverLoad
#define OverLoad_use true
//LED
#define LED_use true
//Buzzer
#define Buzzer_use false
//Switch
#define Switch_use false
//Lights
#define LightsControl_use 	true
//RF cc2500
#define CC2500_use	false
//DelayOff
#define DelayOff_use false
//PowerFault
#define PowerFault_use false
//Dimmer Lights
#define Dimmer_use 	false
#define Dimmer_Half_Wave	true
#define Dimmer_Full_Wave	false
//SegmentDisplay
#define SegmentDisplay_use false
//PIR
#define  PIR_use  true
//CDS
#define CDS_use  true


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

//end file
#endif