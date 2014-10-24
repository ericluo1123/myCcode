
#ifndef _PIR_H_
#define _PIR_H_

#if PIR_use == 1
 
#define RangeMaximum	45
#define RangeMedium		25
#define RangeMinimum	8

struct PIR {
    //enable
    unsigned Enable : 1;

    //AD
    unsigned ADCGO : 1;
    unsigned char VRAD;
    unsigned char VRAD1;
    unsigned char SignalAD;
    unsigned char Time;
    unsigned char ADCount;
    unsigned char ADCount1;
    unsigned char ReferenceVoltage;
    unsigned char TenAverage[10];
    unsigned int TenAverageValue;
    unsigned char HundredAverage[10];
    unsigned int HundredAverageValue;

    //main
    unsigned GO : 1;
    unsigned OK : 1;
    unsigned Switch : 1;
    unsigned int Count;
    unsigned char Trigger;
    unsigned int CloseTime;
    unsigned int CloseTimeValue;

    //auto gain
    unsigned RangeRun : 1;
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

void selectPIRPoint(char);
void PIR_Initialization();
void PIR_Main();
void getPIR_AD(char, char, char);
#else
#define selectPIRPoint(char) ;
#define PIR_Initialization() ;
#define PIR_Main() ;
#define getPIR_AD(char,char,char) ;
#define setPIR_Initialization() ;
#define setPIR_Main() ;	

#endif


#endif