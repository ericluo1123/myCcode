
#ifndef _Buzzer_H_
#define _Buzzer_H_

/****************************************************************
        File list:
                Buzzer_B1.c
                Buzzer_B1.h

        addFunction
                Buzzer_Initialization();
                Buzzer_Main();

        method:
                setBuz(char buz,char count,int time);
                        buz(n)
                        count(1 ~ 10)
                        time(1 ~ 65536)/ms

/***************************************************************/

#if Buzzer_use == 1
//Global extern variable declaration

struct Buzzer {
    unsigned Enable : 1;
    unsigned GO : 1;
    unsigned PowerON : 1;
    unsigned BufferStatus1 : 1;
    unsigned BufferStatus2 : 1;
    unsigned Switch : 1;
    unsigned int Time;
    unsigned char Count;
    unsigned char CountBuffer1;
    unsigned char CountBuffer2;
    unsigned int TimeValue;
    unsigned int TimeValueBuffer1;
    unsigned int TimeValueBuffer2;
};
struct Buzzer *Buz;

#ifdef Buzzer1
struct Buzzer Buz1;
#endif

//default Interval Time
#define BuzzerPowerOnTime	50	//*1ms 
#define BuzzerErrorTime		300	//*1ms 
#define BuzzerOnOffTime		100	//*1ms 

void Buzzer_Initialization();
void Buzzer_Main();
void setBuz_Main(char);
void setBuz(char, int);
void setBuz_Enable(char);

#else
#define Buzzer_Initialization() ;
#define Buzzer_Main() ;
#define setBuz_Main(char) ;
#define setBuz(char,int) ;	
#define setBuz_Enable(char) ;
#endif

//End file
#endif
