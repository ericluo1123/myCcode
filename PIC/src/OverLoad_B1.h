
#ifndef _OverLoad_H_
#define _OverLoad_H_

#include "Activity_B1.h"


#if OverLoad_use == 1

#define Load_Debug 0

#if Dimmer_use == 1

#define FirstLimitValue (20*55)
#define SecondLimitValue (int)(LimitCurrent*55)

#endif

#if LightsControl_use == 1

#define FirstLimitValue 80
#define SecondLimitValue 0x42

#endif

#if PIR_use == 1

#define FirstLimitValue 80
#define SecondLimitValue 15

#endif



//Global extern variable declaration

struct OverLoad {

    union {

        struct {
            unsigned Enable : 1;
            unsigned GO : 1;
            unsigned LightsON : 1;
            unsigned Run : 1;
            unsigned ADtoGO : 1;
            unsigned ERROR : 1;
            unsigned Status : 1;
            unsigned OK : 1;
        };
    };

    unsigned int Time;
    unsigned int ErrorTime;
    //   unsigned char ErrorStatus;
    unsigned int ADH;
    unsigned int ADL;

    ADtype TotalLoad;
    ADtype AH[5];
    ADtype AL[5];
    ADtype AD;
    ADtype ADRES;

    unsigned int LightsJudgeValue;
    unsigned int JudgeValue;
    unsigned int Judge;

    unsigned char Count;
    unsigned char ErrorCount;
    unsigned char LightsCount;
    unsigned char SafeCount;
};

#ifdef OverLoad1
struct OverLoad Load;
#endif

#define DetectCountValue 30


inline void Load_Initialization();
inline void Load_Main();
inline void getLoad_AD(char channel);
void setLoad_Exceptions(char command);
void setLoad_AH_AL_Restore();
//	void setLoad_LightsStatus(char,char);
//void setLoad_Count(char command);
//void setLoad_StatusOn(char lights, char command);
//void setLoad_StatusOff(char lights, char command);
//char getLoad_Safe();
//char getLoad_ERROR();
char getLoad_OK();
void setLoad_OK();

#else
#define Load_Debug 0
#define Load_Initialization() ;
#define Load_Main() ;
#define getLoad_AD(char) ;
#define setLoad_Exceptions(char) ;
#define setLoad_AH_AL_Restore() ;
#define setLoad_Count(char) ;
#define setLoad_StatusOn(char,char) ;
#define setLoad_StatusOff(char,char) ; 
#define getLoad_Safe() 1
#define getLoad_ERROR() 0
#define  getLoad_OK() 1
#define  setLoad_OK() ;
#endif

#endif
