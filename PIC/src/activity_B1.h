#ifndef _Activity_B1_H_
#define _Activity_B1_H_

#include "Buzzer_B1.h"



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

//ADC 
#if ADC_use == 1

#define _ADCON1	ADCON1_RA3		
#define _FVRCON FVRCON_1V		

#ifdef _16F723A
//typedef char ADtype;
#define ADH_Restore 0
#define ADL_Restore 0xff
#endif

#ifdef _16F1516
//typedef int ADtype;
#define ADH_Restore 0
#define ADL_Restore 0xffff
#endif

#ifdef _16F1518
//typedef int ADtype;
#define ADH_Restore 0
#define ADL_Restore 0xffff
#endif

#endif



//Timer0
#if Timer0_use	== 1
#define TMR0_IntrTime_50us			//_50us
//_100us
#endif

//Timer1
#if Timer1_use	== 1
#define TMR1_IntrTime_50us			//_50us
//_100us

#define Clock_Source_System			//_system
//_instruction
#endif



//INT
#if INT_use == 1
#endif

//UART
#if UART_use == 1
#define BAUD 19200	
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
#define SafeCountValue 10
#else
#define SafeCountValue 10
#endif
#endif

//LED
#if LED_use == 1

#define	ErrLED_ON			0

#define	LED1_ON				0

#define	LED2_ON				0

#define	LED3_ON				0

#define LEDTime				500//ms
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
#define Tx_Enable 	1
#define Rx_Enable 	1
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
#define Dimmer_Half_Wave			1 
#define Dimmer_Full_Wave			0
#define TriacTimeValue				1
#define MosfetOpenToCloseValue			10  //close mosfet delay time to allow recook

//dimmer define 	
#define DimmingDelayTime 3 //3


#if Properties_Neutral == 1
#define Max_Percent 90	
#define Med_Percent 35
#define Mini_Percent 15 
#else
#if Control_Method_Mosfet == 1
#if Switch_Class == 1
#define Max_Percent 65	
#endif
#if Switch_Class == 2
#define Max_Percent 65	
#endif
#if Switch_Class == 3
#define Max_Percent 65	
#endif
#endif

#if Control_Method_Triac == 1
#if Switch_Class == 1
#define Max_Percent 55	
#endif
#if Switch_Class == 2
#define Max_Percent 55	
#endif
#if Switch_Class == 3
#define Max_Percent 55	
#endif
#endif
#endif

#define Med_Percent             35
#define Mini_Percent            20


//Percent define
#define TotalCount		166
#define One_Percent		1.5
#define Tune_Percent		40


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


//end file
#endif
