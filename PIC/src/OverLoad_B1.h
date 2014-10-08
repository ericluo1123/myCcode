
#ifndef _OverLoad_H_
#define _OverLoad_H_

#if OverLoad_use == 1

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

#endif

//Global extern variable declaration

struct OverLoad {

    struct {
        unsigned Enable : 1;
        unsigned GO : 1;
        unsigned LightsON : 1;
        unsigned Safe : 1;
        unsigned ADtoGO : 1;
        unsigned ERROR : 1;
        unsigned empty : 2;
    };

    unsigned int Time;
    unsigned int ErrorTime;
    unsigned char ErrorStatus;

#ifdef _16F723A
    unsigned char TotalLoad;
    unsigned char AH[9];
    unsigned char AL[9];
    unsigned char AD;
    unsigned char ADH;
    unsigned char ADL;
    unsigned char ADRES;
#endif

#ifdef _16F1516
    unsigned int TotalLoad;
    unsigned int AH[9];
    unsigned int AL[9];
    unsigned int AD;
    unsigned int ADH;
    unsigned int ADL;
    unsigned int ADRES;
#endif

#ifdef _16F1518
    unsigned int TotalLoad;
    unsigned int AH[9];
    unsigned int AL[9];
    unsigned int AD;
    unsigned int ADH;
    unsigned int ADL;
    unsigned int ADRES;
#endif


    unsigned int LightsJudgeValue;
    unsigned int JudgeValue;
    unsigned int Judge;

    unsigned char Count;
    unsigned char OffCount;
    unsigned char ErrorCount;
    unsigned char UpdateCount;
    unsigned char LightsCount;
    unsigned char NumberCount;
    unsigned char CloseCount;
    unsigned char ADCount;
    unsigned char SafeCount;

    unsigned char Lights1Status;
    unsigned char Lights2Status;
    unsigned char Lights3Status;
    unsigned StatusOn : 1;
    unsigned StatusOff : 1;
};
struct OverLoad *Load;

#ifdef OverLoad1
struct OverLoad Load1;
#endif

#define DetectCountValue 30

void Load_Initialization();
void Load_Main();
void getLoad_AD(char);
void setLoad_Exceptions(char);
void setLoad_Enable(char);
void setLoad_AH_AL_Restore();
//	void setLoad_LightsStatus(char,char);
void setLoad_Count(char);
void setLoad_GO(char);
void setLoad_StatusOn(char, char);
void setLoad_StatusOff(char, char);
char getLoad_Safe();
char getLoad_ERROR();

#else
#define Load_Initialization() ;
#define Load_Main() ;
#define getLoad_AD(char) ;
#define setLoad_Exceptions(char) ;
#define setLoad_Enable(char) ;
#define setLoad_AH_AL_Restore() ;
#define setLoad_Count(char) ;
#define setLoad_GO(char) ;
#define setLoad_StatusOn(char,char) ;
#define setLoad_StatusOff(char,char) ; 
#define getLoad_Safe() 1
#define getLoad_ERROR() 0
#endif

#endif
