
#ifndef _Switch_H_
#define _Switch_H_

#if Switch_use == 1
//define  
#define DebounceTimeValue 	100//ms
#if Switch_Mode == 2
#define Hold1TimeValue 		3000//ms
#else 
#define Hold1TimeValue 		1500//ms
#endif
#define Hold2TimeValue 		1500//ms
#define Hold3TimeValue 		3000//ms

//Global extern vriables declaration/

struct Switch {

    struct {
        unsigned Enable : 1;
        unsigned Touch : 1;
        unsigned Debounce : 1;
        unsigned Hold1 : 1;
        unsigned Hold2 : 1;
        unsigned Hold3 : 1;
        unsigned Status : 1;
        unsigned Flag : 1;
    };

    struct {
        unsigned Adj : 1;
        unsigned Detect : 1;
        unsigned empty : 6;
    };

    unsigned char DebounceTime;
    unsigned int Hold1Time;
#if PIR_use == 0
    unsigned int Hold2Time;
    unsigned int Hold3Time;
#endif
};
struct Switch *Sw;

//***************************************************************
#ifdef use_1KEY
struct Switch Sw1;
#endif
#ifdef use_2KEY
struct Switch Sw2;
#endif
#ifdef use_3KEY
struct Switch Sw3;
#endif
//***************************************************************

void SwPointSelect(char sw);
inline void Switch_Initialization();
inline void Switch_Main();
void setSw_Initialization(char sw);
void setSw_Main(char sw);
void setSw_Enable(char command);
void Switch_Exception(char command);
void setSw_Status(char sw, char command);
char getSw_KeyStatus(char sw);
char getAll_Sw_KeyStatus();

//void Sw_Detect();

#ifdef TTPW
void TouchPower();
#else 
#define TouchPower() ;
#endif

//***************************************************************	
#else
#define SwPointSelect(char ) ;
#define Switch_Initialization() ;
#define Switch_Main() ;
#define setSw_Initialization(char) ;
#define setSw_Main(char) ;
#define setSw_Enable(char) ;
#define Switch_Exception(char) ;
#define setSw_Status(char,char) ;
#define Sw_Detect() ;

#define Sw_DimmerOnFunc(char) ;
#define Sw_DimmerOffFunc(char) ;
#define Sw_DimmerAdjFunc(char) ;

#define TouchPower() ;
#define getSw_Other_KeyStatus(char) ;
#endif

struct SwitchDetect {

    union {

        struct {
            unsigned Error : 1;
            unsigned empty : 7;
        };
    };
};
struct SwitchDetect SwDetect;
//End file
#endif
