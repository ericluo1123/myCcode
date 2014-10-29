
#ifndef _SYSC_H_
#define _SYSC_H_


#if SYSC_use == 1

struct SYSC {

    union {

        struct {
            unsigned Enable : 1;
            unsigned ERROR : 1;
            unsigned PowerON : 1;
            unsigned Signal : 1;
            unsigned empty : 4;
        };
    };
    unsigned int Timer;
    unsigned int Counter;
};

#ifdef SYSC1
struct SYSC SYSC;
#endif

inline void SYSC_Initialization();
inline void SYSC_Main();
void setSYSC_Initialization();
void setSYSC_Main();
inline void DetectSYSC_Signal();

#else
#define selectSYSCPoint(char) ;
#define SYSC_Initialization();
#define SYSC_Main() ;
#define setSYSC_Initialization() ;
#define setSYSC_Main() ;
#define DetectSYSC_Signal(char) ;

#endif
#endif