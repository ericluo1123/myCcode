
#ifndef _Switch_H_
#define _Switch_H_

#if Switch_use == 1
//define
#define DebounceTimeValue 	5//*10ms
#define Hold1TimeValue 		150//*10ms	
#define Hold2TimeValue 		150//*10ms
#define Hold3TimeValue 		300//*10ms

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
    unsigned int Hold2Time;
    unsigned int Hold3Time;


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
