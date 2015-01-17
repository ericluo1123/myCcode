
#ifndef _myDevelopoment_B_H_	
#define	_myDevelopoment_B_H_		

#ifndef _myDevelopoment_B_H_
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
#define Name_SerialNumber		3	//2
#define Properties_Product		1	//3
#define Properties_Keys			1	//4
#define Properties_Country		1	//5

//Control Option
#define Control_Method_Mosfet		0
#define Control_Method_Triac		1
#define Control_Method_Relay		0
#define Control_Method_TriacRelay	0
#define Properties_Neutral			0
#define Properties_Dimmer			1
#define Debug 1
#define Create_Date "2014/9/25"
#define PCB_Name "TH-302PV11-1-Dim(20140722)"
#else
#define KeyID 0
#endif

//MCU
 	#define	LED1				RA0		//pin2  1
  	#define LED2				RA1		//pin3	0	
// 	#define 					RA2		//pin4	0		
// 	#define						RA3		//pin5	1
//	#define						RA4		//pin6 	0
//	#define 					RA5		//pin7	0
//	#define						RA6		//pin10 0			
//	#define						RA7		//pin9	0		
		
	#define CC2500_GDO0			RB0		//pin21 1	
	#define CC2500_SI			RB1		//pin22 0
	#define CC2500_SCK			RB2		//pin23 0
	#define CC2500_SO			RB3		//pin24	1
	#define CC2500_GDO2			RB4		//pin25 1
	#define CC2500_CSN			RB5		//pin26	0
//	#define 					RB6		//pin27	0	
//	#define 					RB7		//pin28 0	
		
	#define SS1					RC0		//pin11	0	
//	#define 					RC1		//pin12	0 	
//	#define						RC2		//pin13	1		
	#define	SCK					RC3		//pin14	1	
	#define SDA					RC4		//pin15	1
//	#define						RC5		//pin16	0	
	#define Tx					RC6		//pin17	0
	#define	Rx					RC7		//pin18	0	

	//I/O
	#define _TRISA 	0b00000000;
	#define _TRISB 	0b00011001;
	#define _TRISC 	0b00011000;
	#define _LATA	0b00000000;
	#define _LATB	0b00000000;
	#define _LATC	0b00000000;
	#define _ANSELA 0b00000000;
	#define _ANSELB 0b00000000;
	#define _ANSELC 0b00000000;
	#define _PORTA 	0b00000000;
	#define _PORTB 	0b00011001;
	#define _PORTC 	0b00011000;
		

//ADC channel
#define OverLoad_Channel		AN1
#define OverTemp_Channel		AN2
#define PFV_Channel			AN4

//Mcu Function Option

//ADC
#define ADC_use 0
//Oscillator (System FOSC)
#define	System_Fosc_16M				//_16M
//Timer0
#define Timer0_use	0
//Timer1
#define Timer1_use	1
//INT
#define INT_use 1
//UART
#define UART_use 0
#define UART_Master 1
#define UART_Slave 0
//38400
//I2C
#define I2C_use 1
#define Master_Mode 0
#define Slave_Mode 1
//IOC
#define IOC_use 0
//FlashMemory
#define FlashMemory_use 0
//watchdog timer
#define WDT_use 0



//Function Option

//SYSC
#define SYSC_use 0
//OverTemperature
#define OverTemperature_use 0
//OverLoad
#define OverLoad_use 0
//LED
#define LED_use 0
#define PIRLED_use_Value 0
//Buzzer
#define Buzzer_use 0
//Switch
#define Switch_use 0
//Lights
#define LightsControl_use 	0
#define setLights_SwOn_Value 1
#define setLights_SwOff_Value 1
#define setLights_Value 1
//RF cc2500
#define CC2500_use	1
//DelayOff
#define DelayOff_use 0
//PowerFault
#define PowerFault_use 0
//Dimmer Lights
#define Dimmer_use 	0
//SegmentDisplay
#define SegmentDisplay_use 0
 //CDS
#define CDS_use_Value   0
//PIR
#define PIR_use_Value   0
//UART to RF
#define myUARTtoRF_use_Value 0
//Main
#define Exception_Main_Value 2

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