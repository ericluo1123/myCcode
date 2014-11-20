
#ifndef _OverTemperature_H_
#define _OverTemperature_H_

#if OverTemperature_use == 1
#define Temp_Debug 0
struct OverTemp {

    union {

        struct {
            unsigned Enable : 1;
            unsigned ERROR : 1;
            unsigned ADtoGO : 1;
            unsigned LoadADGO : 1;
            unsigned GO : 1;
            unsigned empty : 3;
        };
    };
    unsigned int Time;
    unsigned char Count;

    unsigned char AD1;
    unsigned char AD2;


    ADtype AD;
    ADtype ADH[2];
    ADtype ADRES;
    ADtype SafeValue;
    ADtype DangerValue;

};
#ifdef SYSC1
struct OverTemp Temp;
#endif

#ifdef MCU_16F723A
#define TempDangerValueH    140		//NTC 68 value 500
#define TempDangerValueL    70		//NTC 68 value 500

//NTC 71 value 490
//NTC 73.5 value 480	
//65,600
#define TempSafeValueH	170		//NTC 47 value 600
#define TempSafeValueL	100		//NTC 47 value 600
//NTC 61.2 value 540
//NTC 58 value 535
//51,700
#endif

#ifdef MCU_16F1516
#define TempDangerValue	550		//NTC 68 value 500
//NTC 71 value 490
//NTC 73.5 value 480
//65,600

#define TempSafeValue	600		//NTC 47 value 600
//NTC 61.2 value 540
//NTC 58 value 535
//51,700
#endif

#ifdef MCU_16F1518
#define TempDangerValue	390		//NTC 68 value 500
//NTC 71 value 490
//NTC 73.5 value 480
//65,600

#define TempSafeValue	430		//NTC 47 value 600
//NTC 61.2 value 540
//NTC 58 value 535
//51,700
#endif

#define TempCountValue 	3




/**
 * temp initialization
 */
inline void Temp_Initialization();
inline void Temp_Main();
void setTemp_Main();
void setTemp_Initialization();
inline void getTemp_AD(char channel);
void setOverTemp_Exceptions(char command); 
#else
//NOP
#define Temp_Main() ;
#define getTemp_Safe() 1
#define getTemp_ERROR() 0
#define TempPointSelect() ;
#define Temp_Initialization() ;
#define setTemp_Initialization() ;
#define getTemp_AD(char) ;
#define setOverTemp_Exceptions(char) ;

#endif

#endif

