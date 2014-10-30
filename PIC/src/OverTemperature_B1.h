
#ifndef _OverTemperature_H_
#define _OverTemperature_H_

#if OverTemperature_use == 1

struct OverTemp {

    union {

        struct {
            unsigned Enable : 1;
            unsigned ERROR : 1;
            unsigned ADtoGO : 1;
            unsigned LoadADGO : 1;
            unsigned Safe : 1;
            unsigned empty : 3;
        };
    };
    unsigned int Time;
    unsigned char Count;

    unsigned char AD1;
    unsigned char AD2;

#ifdef MCU_16F723A
    unsigned char AD;
    unsigned char ADH[2];
    unsigned char ADRES;
    unsigned char SafeValue;
    unsigned char DangerValue;
#endif

#ifdef MCU_16F1516
    unsigned int AD;
    unsigned int ADH[2];
    unsigned int ADRES;
    unsigned int SafeValue;
    unsigned int DangerValue;
#endif

#ifdef MCU_16F1518
    unsigned int AD;
    unsigned int ADH[2];
    unsigned int ADRES;
    unsigned int SafeValue;
    unsigned int DangerValue;
#endif

};
#ifdef SYSC1
struct OverTemp Temp;
#endif

#ifdef MCU_16F723A
#define TempDangerValueH 170		//NTC 68 value 500
#define TempDangerValueL 100		//NTC 68 value 500
//NTC 71 value 490
//NTC 73.5 value 480	
//65,600
#define TempSafeValueH	190		//NTC 47 value 600
#define TempSafeValueL	120		//NTC 47 value 600
//NTC 61.2 value 540
//NTC 58 value 535
//51,700
#endif

#ifdef MCU_16F1516
#define TempDangerValue	550		//NTC 68 value 500
//NTC 71 value 490
//NTC 73.5 value 480
//65,600

#define TempSafeValue	600		//NTC 47 value 600
//NTC 61.2 value 540
//NTC 58 value 535
//51,700
#endif
#ifdef MCU_16F1518
#define TempDangerValue	550		//NTC 68 value 500
//NTC 71 value 490
//NTC 73.5 value 480
//65,600

#define TempSafeValue	600		//NTC 47 value 600
//NTC 61.2 value 540
//NTC 58 value 535
//51,700
#endif

#define TempCountValue 	3




/**
 * temp initialization
 */
inline void Temp_Initialization();
inline void Temp_Main();
void setTemp_Main();
void setTemp_Initialization();
inline void getTemp_AD(char channel);
void setOverTemp_Exceptions(char command);
void setTemp_Enable(char command);
char getTemp_Safe();
char getTemp_ERROR();
#else
//NOP
#define getTemp_Safe() 1
#define getTemp_ERROR() 0
#define TempPointSelect() ;
#define Temp_Initialization() ;
#define Temp_Main() ;
#define setTemp_Main() ;
#define setTemp_Initialization() ;
#define getTemp_AD(char) ;
#define setOverTemp_Exceptions(char) ;
#define setTemp_Enable(char) ;

#endif

#endif

