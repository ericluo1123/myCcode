
#ifndef PowerFault_H_
#define PowerFault_H_

#if PowerFault_use == 1

struct PF {

    union {

        struct {
            unsigned Enable : 1;
            unsigned ERROR : 1;
            unsigned Safe : 1;
            unsigned ADtoGO : 1;
            unsigned empty : 4;
        };
    };
    unsigned char Count;
    unsigned int Time;

#ifdef _16F723A
    unsigned char AD;
    unsigned char ADRES;
#endif
#ifdef _16F1516
    unsigned int AD;
    unsigned int ADRES;
#endif
#ifdef _16F1518
    unsigned int AD;
    unsigned int ADRES;
#endif
};

#ifdef PFV1
struct PF PF1;
#endif

inline void PowerFault_Initialization();
inline inline void PowerFault_Main();
void getPowerFault_AD(char channel);
void setPowerFault_Initialization();
void setPowerFault_Main();
void setPowerFault_Exceptions(char command);
void setPF_Enable(char command);
char getPF_Safe();
char getPF_ERROR();
#else
#define getPF_Safe() 1
#define getPF_ERROR() 0
//		#define PowerFaultPointSelect(char) ;
#define PowerFault_Initialization() ;
#define PowerFault_Main() ;
#define getPowerFault_AD(char) ;
#define setPowerFault_Initialization() ;
#define setPowerFault_Main() ;
#define setPowerFault_Exceptions(char) ;
#define setPF_Enable(char) ;

#endif

#endif