
#ifndef _Switch_1Key_Dimmer_V1.0.1.2.1_H_	
#define	_Switch_1Key_Dimmer_V1.0.1.2.1_H_		

//Include
#include <stdio.h>

/**Version information
        Name_Version 			:	1~255

        Name_SerialNumber		:	0~255
 
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
#define Name_SerialNumber		0	//2
#define Properties_Product		1	//3
#define Properties_Keys			2	//4
#define Properties_Country		1	//5

//Control Option
#define Control_Method_Mosfet		1
#define Control_Method_Triac		0
#define Control_Method_Relay		0
#define Control_Method_TriacRelay	0
#define Properties_Neutral		0
#define Properties_Dimmer		1
#define Debug 1
#define PCB_Name "TH-302PV11-1-Dim(20140722)"

//MCU define
#define	Key2_1				RA0		//pin2  1	
#define OverLoad1			RA1		//pin3	1	
#define SYSC1				RA2		//pin4	1		
#define	LED1				RA3		//pin5	0	
#define	Key1_2				RA4		//pin6 	1	
#define PFV1				RA5		//pin7	1
#define	Key1_1				RA6		//pin10 1			
#define	Mosfet1				RA7		//pin9	0			

#define CC2500_GDO0			RB0		//pin21 1	
#define Key2_2				RB1		//pin22 1	
#define DimmerReference1                RB2		//pin23 1
#define Buzzer1				RB3		//pin24	0
#define Mosfet2				RB4		//pin25 0	
#define ErrLED				RB5		//pin26	0
#define PinEmpty1			RB6		//pin27	0	
#define PinEmpty2			RB7		//pin28 0	

#define CC2500_SI			RC0		//pin11	0	
#define CC2500_SCK			RC1		//pin12	0 	
#define CC2500_SO			RC2		//pin13	1		
#define	CC2500_GDO2			RC3		//pin14	1	
#define CC2500_CSN			RC4		//pin15	0	
#define	TTPW				RC5		//pin16	0	
//#define LED3				RC6		//pin17	0
#define	LED2				RC7		//pin18	0	

//I/O
#define _TRISA 	0b01110111;
#define _TRISB 	0b00000111;
#define _TRISC 	0b00001100;
#define _LATA	0b00000000;
#define _LATB	0b00000010;
#define _LATC	0b00000000;
#define _ANSELA 0b00100010;
#define _ANSELB 0b00000000;
#define _ANSELC 0b00000000;
#define _PORTA 	0b01110111;
#define _PORTB 	0b00000111;
#define _PORTC 	0b00001100;

//ADC channel
#define OverLoad_Channel		AN1
#define OverTemp_Channel		AN2
#define PFV_Channel			AN4	

//Mcu Function Option

//Oscillator (System FOSC)
#define	System_Fosc_16M     //_16M
//ADC 
#define ADC_use             true											
//Timer0
#define Timer0_use          true
//Timer1
#define Timer1_use          false
//INT
#define INT_use             true
//UART
#define UART_use            false
#define UART_Master         true
#define UART_Slave          false
//I2C
#define I2C_use             false
#define Master_Mode         true
#define Slave_Mode          false
//IOC
#define IOC_use             true
//FlashMemory_use
#define FlashMemory_use     true
//watchdog timer
#define WDT_use             true

//Function Option

//SYSC
#define SYSC_use            false
//OverTemperature
#define OverTemperature_use false
//OverLoad
#define OverLoad_use        false
//LED
#define LED_use             true
//Buzzer
#define Buzzer_use          true
//Switch
#define Switch_use          true
//Lights
#define LightsControl_use   false
//RF cc2500
#define CC2500_use          true//false
//DelayOff
#define DelayOff_use        true
//PowerFault
#define PowerFault_use      false
//Dimmer Lights
#define Dimmer_use          true
//SegmentDisplay
#define SegmentDisplay_use  false
//CDS
#define CDS_use             false
//PIR
#define PIR_use             false



//include


#include "../src/Main_B1.h"
#include "../src/Activity_B1.h"
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
#include "../src/MCU_B1.h"
#include "../src/SegmentDisplay_A2.h"

//end file
#endif