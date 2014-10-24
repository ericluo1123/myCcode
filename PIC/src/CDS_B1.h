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
        unsigned High : 1;
        unsigned Low : 1;
        unsigned empty : 2;
    };
 
    unsigned char Time;
#ifdef _16F723A
    unsigned char VRAD;
    unsigned char SignalAD;
    unsigned char ADRES;
#else
    unsigned int VRAD;
    unsigned int SignalAD;
    unsigned int ADRES;
#endif
};

#ifdef CDS_1
struct CDS _CDS;
#endif

//void selectCDSPoint(char);
void CDS_Initialization();
void CDS_Main();
//void setCDS_Initialization(char);
//void setCDS_Main(char);
void getCDS_AD(char, char, char);

#else
//#define selectCDSPoint(char) ;
#define CDS_Initialization() ;
#define CDS_Main() ;
//#define setCDS_Initialization(char) ;
//#define setCDS_Main(char) ;
#define getCDS_AD(char,char,char) ;

#endif
#endif