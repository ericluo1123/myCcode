/**
 * PIR header
 */
#ifndef _PIR_H_
#define _PIR_H_

#if PIR_use == 1

//detect range
#define RangeMaximum	45
#define RangeMedium	25
#define RangeMinimum	15//8

struct PIR {

    union {

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
    };

#ifdef _16F723A
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
    unsigned char TenCount;
    unsigned char HundreCount;
    unsigned char ReferenceVoltage;
    unsigned char TenAverage[10];
    unsigned int TenAverageValue;
    unsigned char HundredAverage[10];
    unsigned int HundredAverageValue;

    //main

    unsigned int Count;
    unsigned char TriggerValue;
    unsigned int CloseTimeMinutes ;
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

void selectPIRPoint(char);
void PIR_Initialization();
void PIR_Main();
void getPIR_AD(char channel1, char channel2);
#else
#define selectPIRPoint(char);
#define PIR_Initialization();
#define PIR_Main();
#define getPIR_AD(char , char );

#endif


#endif