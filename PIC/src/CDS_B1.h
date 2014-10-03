
#ifndef _CDS_H_
#define _CDS_H_

#if CDS_use == 1

struct CDS {
    unsigned Enable : 1;
    unsigned GO : 1;
    unsigned OK : 1;
    unsigned ADtoGO : 1;
    unsigned High : 1;
    unsigned Low : 1;
    unsigned char Time;
    unsigned ADtype VRAD;
    unsigned ADtype SignalAD;
    unsigned ADtype ADRES;
};
struct CDS *CDS;

#ifdef CDS_1
struct CDS _CDS1;
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