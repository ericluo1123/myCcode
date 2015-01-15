/**
 * CDS header file
 */
#ifndef _CDS_H_
#define _CDS_H_

#if CDS_use == 1

struct CDS {

    struct {
        unsigned Enable : 1;
        unsigned GO : 1;
        unsigned OK : 1;
        unsigned ADtoGO : 1;
        unsigned Status : 1;
        unsigned Low : 1;
        unsigned empty : 2;
    };

    unsigned char Time;
#ifdef MCU_16F723A
    unsigned char VRAD;
    unsigned char SignalAD;
//    unsigned char ADRES;
#else
    unsigned int VRAD;
    unsigned int SignalAD;
    unsigned int ADRES;
#endif
};

#ifdef CDS_1
struct CDS _CDS;
#endif

inline void CDS_Initialization();
inline void CDS_Main();
inline void getCDS_AD(char channel1, char channel2);
char getCDS_Status();

#else

#define CDS_Initialization() ;
#define CDS_Main() ;
#define getCDS_AD(char,char) ;
#define getCDS_Status() 1

#endif
#endif