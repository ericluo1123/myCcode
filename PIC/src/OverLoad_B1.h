
#ifndef _OverLoad_H_
#define _OverLoad_H_

#if OverLoad_use == 1
#define Load_Debug 0
#if Dimmer_use == 1

#if Max_Percent == 45
#if Switch_Class == 3
#define LoadLimitValue 0x22
#endif

#if Switch_Class == 2
#define LoadLimitValue 0x32//1a
#endif

#if Switch_Class == 1
#define LoadLimitValue 0x42
#endif
#endif


#if Max_Percent == 50
#if Switch_Class == 3		
#define LoadLimitValue 0x22
#endif

#if Switch_Class == 2			
#define LoadLimitValue 0x32
#endif

#if Switch_Class == 1			
#define LoadLimitValue 0x42
#endif
#endif

#if Max_Percent == 55				//clear
#if Switch_Class == 3		
#define LoadLimitValue 0x22
#endif

#if Switch_Class == 2			
#define LoadLimitValue 0x32
#endif

#if Switch_Class == 1			
#define LoadLimitValue 0x42
#endif
#endif

#if Max_Percent == 60
#if Switch_Class == 3		
#define LoadLimitValue 0x22
#endif

#if Switch_Class == 2			
#define LoadLimitValue 0x32
#endif

#if Switch_Class == 1			
#define LoadLimitValue 0x42
#endif
#endif

#if Max_Percent == 65
#if Switch_Class == 3		
#define LoadLimitValue 0x22
#endif

#if Switch_Class == 2			
#define LoadLimitValue 0x32//1a
#endif

#if Switch_Class == 1			
#define LoadLimitValue 0x42
#endif
#endif

#if Max_Percent == 70
#if Switch_Class == 3		
#define LoadLimitValue 0x22
#endif

#if Switch_Class == 2			
#define LoadLimitValue 0x32//1a
#endif

#if Switch_Class == 1			
#define LoadLimitValue 0x42
#endif
#endif


#if Max_Percent == 75
#if Switch_Class == 3		
#define LoadLimitValue 0x22
#endif

#if Switch_Class == 2			
#define LoadLimitValue 0x32//1a
#endif

#if Switch_Class == 1			
#define LoadLimitValue 0x42
#endif
#endif

#if Max_Percent == 80
#if Switch_Class == 3		
#define LoadLimitValue 0x22
#endif

#if Switch_Class == 2			
#define LoadLimitValue 0x32//1a
#endif

#if Switch_Class == 1			
#define LoadLimitValue 0x42
#endif
#endif

#if Max_Percent == 85
#if Switch_Class == 3		
#define LoadLimitValue 0x22
#endif

#if Switch_Class == 2			
#define LoadLimitValue 0x32//1a
#endif

#if Switch_Class == 1			
#define LoadLimitValue 0x42
#endif
#endif

#if Max_Percent == 90
#if Switch_Class == 3		
#define LoadLimitValue 0x22
#endif

#if Switch_Class == 2
#define LoadLimitValue 0x32//1a
#endif

#if Switch_Class == 1	
#define LoadLimitValue 0x42
#endif
#endif
#else
#define LoadLimitValue 0x42
#endif

//Global extern variable declaration

struct OverLoad {

    union {

        struct {
            unsigned Enable : 1;
            unsigned GO : 1;
            unsigned LightsON : 1;
            unsigned Safe : 1;
            unsigned ADtoGO : 1;
            unsigned ERROR : 1;
            unsigned Status : 1;
            unsigned OK : 1;
        };
    };

    union {

        struct {
            unsigned status1 : 1;
            unsigned status2 : 1;
            unsigned status3 : 1;
            unsigned empty : 5;

        };
    };
    unsigned int Time;
    unsigned int ErrorTime;
    unsigned char ErrorStatus;
    unsigned int ADH;
    unsigned int ADL;

#ifdef MCU_16F723A
    unsigned char TotalLoad;
    unsigned char AH[5];
    unsigned char AL[5];
    unsigned char AD;
    unsigned char ADRES;
#endif 

#ifdef MCU_16F1516
    unsigned int TotalLoad;
    unsigned int AH[5];
    unsigned int AL[5];
    unsigned int AD;
    unsigned int ADRES;
#endif

#ifdef MCU_16F1518
    unsigned int TotalLoad;
    unsigned int AH[5];
    unsigned int AL[5];
    unsigned int AD;
    unsigned int ADRES;
#endif


    unsigned int LightsJudgeValue;
    unsigned int JudgeValue;
    unsigned int Judge;

    unsigned char Count;
    unsigned char ErrorCount;
    unsigned char LightsCount;
    //    unsigned char NumberCount;
    unsigned char SafeCount;

    //    unsigned char Lights1Status;
    //    unsigned char Lights2Status;
    //    unsigned char Lights3Status;
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
void setLoad_Count(char command);
void setLoad_GO(char command);
void setLoad_StatusOn(char lights, char command);
void setLoad_StatusOff(char lights, char command);
char getLoad_Safe();
char getLoad_ERROR();
char getLoad_Status();
#else
#define Load_Initialization() ;
#define Load_Main() ;
#define getLoad_AD(char) ;
#define setLoad_Exceptions(char) ;
#define setLoad_AH_AL_Restore() ;
#define setLoad_Count(char) ;
#define setLoad_GO(char) ;
#define setLoad_StatusOn(char,char) ;
#define setLoad_StatusOff(char,char) ; 
#define getLoad_Safe() 1
#define getLoad_ERROR() 0
#endif

#endif
