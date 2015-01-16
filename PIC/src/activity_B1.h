/**
 * activity header file
 */
#ifndef _Activity_B1_H_
#define _Activity_B1_H_

//Include
#include <stdio.h>
#include <stdlib.h>

//******************************************************************************
//setting

#define	Name_Version Name_Version_Value
#define Name_SerialNumber Name_SerialNumber_Value
#define Properties_Product Properties_Product_Value
#define Properties_Keys	Properties_Keys_Value
#define Properties_Country Properties_Country_Value
#define SeriesNumber SeriesNumber_Value             

#define Control_Method_Mosfet Control_Method_Mosfet_Value
#define Control_Method_Triac Control_Method_Triac_Value
#define Control_Method_Relay Control_Method_Relay_Value
#define Control_Method_TriacRelay Control_Method_TriacRelay_Value
#define Properties_Neutral Properties_Neutral_Value
#define Properties_Dimmer Properties_Dimmer_Value
#define Debug Debug_Value
//******************************************************************************
//Mcu Function Option

//ADC
#define ADC_use ADC_use_Value
//Timer0
//Main Time
#define Main_Time Main_Time_Value
#define Timer0_use Timer0_use_value
//Timer1
#define Timer1_use Timer1_use_Value
//Timer2
#define Timer2_use Timer2_use_Value
//INT
#define INT_use INT_use_Value
//UART
#define UART_use UART_use_Value
#define UART_Master UART_Master_Value
#define UART_Slave UART_Slave_Value
#define UART_Data_Length UART_Data_Length_Vallue
//I2C
#define I2C_use I2C_use_Value
#define Master_Mode Master_Mode_Value
#define Slave_Mode Slave_Mode_Value
//IOC
#define IOC_use IOC_use_Value
#define _IOCBP _IOCBP_Value  //Positive edge
#define _IOCBN _IOCBN_Value  //Negative edge
//Flash Memory
#define FlashMemory_use FlashMemory_use_Value
//Watch Dog
#define WDT_use WDT_use_Value

//******************************************************************************
//Function Option

//SYSC
#define SYSC_use SYSC_use_Value
//Over Tempeature
#define OverTemperature_use OverTemperature_use_Value


#define TempDangerValueH TempDangerValueH_Value
#define TempDangerValueL TempDangerValueL_Value
#define TempSafeValueH TempSafeValueH_Value
#define TempSafeValueL TempSafeValueL_Value

#define TempDangerValue	TempDangerValue_Value
#define TempSafeValue TempSafeValue_Value
//Over Load
#define OverLoad_use OverLoad_use_Value
#define LimitCurrent LimitCurrent_Value
#define LinearParam  LinearParam_Value
//LED
#define LED_use LED_use_Value
//Buzzer 
#define Buzzer_use Buzzer_use_Value
//Switch
#define Switch_use Switch_use_Value
//Lights Control
#define LightsControl_use LightsControl_use_Value
//CC2500
#define CC2500_use CC2500_use_Value
//Delay Off
#define DelayOff_use DelayOff_use_Value
//Power Fault
#define PowerFault_use PowerFault_use_Value
//Dimmer
#define Dimmer_use Dimmer_use_Value
#define Dimmer_Half_Wave Dimmer_Half_Wave_Value
#define Dimmer_Full_Wave Dimmer_Full_Wave_Value
//Segment Display
#define SegmentDisplay_use SegmentDisplay_use_Value
//CDS
#define CDS_use CDS_use_Value
//PIR
#define PIR_use PIR_use_Value
//UART to RFue
#define myUARTtoRF_use myUARTtoRF_use_Value
//******************************************************************************

#if Properties_Keys == 1
#define Switch_Class 1
#define use_1KEY
#if Properties_Dimmer == 1
#define KeyID 209
#else
#define KeyID 1
#endif
#endif

#if Properties_Keys == 2

#define Switch_Class 2
#define use_1KEY
#define use_2KEY

#if Properties_Dimmer == 1
#define KeyID 210
#else
#define KeyID 2
#endif

#endif


#if Properties_Keys == 3
#define Switch_Class 3
#define use_1KEY
#define use_2KEY
#define use_3KEY
#if Properties_Dimmer == 1
#define KeyID 211
#else
#define KeyID 3
#endif
#endif

#ifndef Switch_Class
#define Switch_Class 0
#endif

#ifndef KeyID
#define KeyID 0xaa
#endif
//ADC 
#if ADC_use == 1

#define _ADCON1	ADCON1_Fixed
#define _FVRCON FVRCON_1V		

#ifdef MCU_16F723A
typedef unsigned char ADtype;
#define ADH_Restore 0
#define ADL_Restore 0xff
#endif


#ifdef MCU_16F1516
typedef unsigned int ADtype;
#define ADH_Restore 0
#define ADL_Restore 0xffff
#endif

#ifdef MCU_16F1518
typedef unsigned int ADtype;
#define ADH_Restore 0
#define ADL_Restore 0xffff
#endif

#endif



//Timer0
#if Timer0_use	== 1

#endif

//Timer1
#if Timer1_use	== 1

#define Clock_Source_System			//_system
//_instruction
#endif

//Timer2
#if Timer2_use	== 1
#endif

//INT
#if INT_use == 1
#endif

//UART
#if UART_use == 1	
#endif

//I2C
#if I2C_use == 1
#endif 

//IOC
#if IOC_use == 1
#endif

//FlashMemory
#if FlashMemory_use == 1
#endif

//watchdog timer
#if WDT_use == 1
#endif

//MCU end

//Function Option	
//SYSC
#if SYSC_use == 1
#endif

//OverTemperature
#if OverTemperature_use == 1	
#endif

//OverLoad
#if OverLoad_use == 1
#if Properties_Dimmer == 1
#define SafeCountValue 3
#else
#define SafeCountValue 3
#endif
#endif

//LED
#if LED_use == 1

#define	ErrLED_ON			0

#define	LED1_ON				0

#define	LED2_ON				0

#define	LED3_ON				0

#define LEDTime				500//ms
#define PIRLEDTime                      500//ms
#endif

//Buzzer
#if Buzzer_use == 1
#endif
//Switch
#if Switch_use == 1
#endif
//Lights
#if LightsControl_use == 1
#endif
//RF cc2500
#if CC2500_use	== 1

#define RadioFrequency1
#define Sleep_Mode      0

#endif
//DelayOff
#if DelayOff_use == 1
#endif

//PowerFault
#if PowerFault_use == 1
#endif

//Dimmer Lights
#if Dimmer_use == 1

#define Dimmable_Func 				1	
#define Dimmer_Smooth				0
#define DimmerValue_SaveMemory			0
#define DimmerValue_CloseLightsSave		0
#define TriacTimeValue				1
/**
 * close mosfet delay time to allow recook
 */
#define MosfetOpenToCloseValue			10


//Percent define
#ifdef IntrTime_50us
#define TotalCount		166
#define One_Percent		1.5
#define Tune_Percent		40
/**
 * dimmer delay time
 */
#define DimmingDelayTime 3
#define TriacCountValue 87
#endif

#ifdef IntrTime_100us
#define TotalCount		86
#define One_Percent		0.8
#define Tune_Percent		40
/**
 * dimmer delay time
 */
#define DimmingDelayTime 7
#define TriacCountValue 60
#endif

#ifdef IntrTime_150us
#define TotalCount		55
#define One_Percent		0.55
#define Tune_Percent		40
#define TriacCountValue         45
/**
 * dimmer delay time
 */
#define DimmingDelayTime 10
#endif

#ifdef IntrTime_200us
#define TotalCount		41
#define One_Percent		0.4
#define Tune_Percent            40
/**
 * dimmer delay time
 */
#define DimmingDelayTime 12
#define TriacCountValue 30
#endif

//Tolerance

#define CorrectionValue 0//14
#define TriacTimeValue	1
#define DetectTime 50
#define DimmerTuneValue 157

#if Control_Method_Triac == 1  
//maxum 
#define Dimmer_Maxum 	((char)((100-Max_Percent)*One_Percent))

//medium
#define Dimmer_Medium 	((char)((100-Med_Percent)*One_Percent))

//minimun
#define Dimmer_Minimum	((char)((100-Mini_Percent)*One_Percent))
#endif 

#if Control_Method_Mosfet == 1
//maxum
#define Dimmer_Maxum 	((char)(Max_Percent*One_Percent))

//medium
#define Dimmer_Medium 	((char)(Med_Percent*One_Percent))

//minimun
#define Dimmer_Minimum	((char)(Mini_Percent*One_Percent))
#endif
#endif

//PIR
#if PIR_use == 1
#define PIRLED_use PIRLED_use_Value
#endif

//CDS
#if CDS_use == 1	 
#endif

//SegmentDisplay
#if SegmentDisplay_use == 1
#define Polarity        1
#define Display_Dec	1
#define	Display_Hex	0

#define ComValue PORTA
#define DisplayValue PORTB
#endif

#define Exception_Main_Mode Exception_Main_Value
//end file
#endif
