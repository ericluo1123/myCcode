
#ifndef _SYSC_H_
#define _SYSC_H_


#if SYSC_use == 1

struct SYSC {
    unsigned Enable : 1;
    unsigned ERROR : 1;
    unsigned PowerON : 1;
    unsigned int Time;
    unsigned int Count;
};
struct SYSC *SYSC;

#ifdef SYSC1
struct SYSC _SYSC1;
#endif

void selectSYSCPoint(char);
void SYSC_Initialization();
void SYSC_Main();
void setSYSC_Initialization(char);
void setSYSC_Main(char);
void DetectSYSC_Signal(char);

#else
#define selectSYSCPoint(char) ;
#define SYSC_Initialization() ;
#define SYSC_Main() ;
#define setSYSC_Initialization() ;
#define setSYSC_Main() ;
#define DetectSYSC_Signal(char) ;

#endif
#endif