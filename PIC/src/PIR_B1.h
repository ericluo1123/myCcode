/**
 * PIR header
 */
#ifndef _PIR_H_
#define _PIR_H_

#if PIR_use == 1
#define PIR_Test_Mode 0
#define PIR_TestTime_Mode 0
//detect range
#define RangeMinimum	20
#define RangeMedium	(RangeMinimum+10)
#define RangeMaximum	(RangeMinimum+20)


#define Hunder_Average 1

struct PIR {

    struct {
        unsigned Enable : 1;
        unsigned ADtoGO : 1;
        unsigned GO : 1;
        unsigned OK : 1;
        unsigned Detect : 1;
        unsigned RangeRun : 1;
        unsigned Status : 1;
        unsigned Available : 1;
    };

#ifdef MCU_16F723A
    unsigned char SignalAD;
    unsigned char ADRES;
    unsigned char VRAD;
    unsigned char VRAD1;
#else
    unsigned int SignalAD;
    unsigned int ADRES;
    unsigned int VRAD;
    unsigned int VRAD1;
#endif


    unsigned char Time;
    unsigned char ReferenceVoltage;

    unsigned char TenCount;
    unsigned char TenAverage[10];
    unsigned int TenAverageValue;
#if Hunder_Average == 1
    unsigned char HundreCount;
    unsigned char HundredAverage[10];
    unsigned int HundredAverageValue;
#endif

    //main

    unsigned int Count;
    unsigned char TriggerValue;
    unsigned int CloseTimeMinutes;
    unsigned char CloseTimeSeconds;
    unsigned int CloseTimeValue;

    //auto gain

    unsigned char RangeTime;
    unsigned char RangeTime1;
    unsigned char RangeCount;
    unsigned char RangeValue;
    unsigned char RangeCount1;
    unsigned char Offset;
};

#ifdef PIR_1
struct PIR _PIR;
#endif

void PIR_Initialization();
void PIR_Main();
void getPIR_AD(char channel1, char channel2);
char getPIR_OK();
#else
#define selectPIRPoint(char) ;
#define PIR_Initialization() ;
#define PIR_Main() ;
#define getPIR_AD(char , char) ;
#define getPIR_OK() ;

#endif


#endif