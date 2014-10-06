
#ifndef _Buzzer_H_
#define _Buzzer_H_
/**
 * buzzer header file
 *
 */

#if Buzzer_use == 1
//Global extern variable declaration

struct Buzzer {

    struct {
        unsigned Enable : 1;
        unsigned GO : 1;
        unsigned PowerON : 1;
        unsigned BufferStatus1 : 1;
        unsigned BufferStatus2 : 1;
        unsigned Switch : 1;
        unsigned empty1 : 2;

    };


    unsigned int Counter;
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

/**
 * buzzer initialization
 */
inline void Buzzer_Initialization();
/**
 * buzzer main
 */
void Buzzer_Main();
/**
 * set buzzer beeps and time
 * @param count //number of time
 * @param time  //ms
 */
void setBuz(char count, int time);
/**
 * set buzzer enable
 * @param command   //1=enable,0=disable
 */
inline void setBuz_Enable(char command);
/**
 * buzzer counter
 */
inline void setBuz_Counter();
#else
#define Buzzer_Initialization() ;
#define Buzzer_Main() ;
#define setBuz_Main(char) ;
#define setBuz(char,int) ;	
#define setBuz_Enable(char) ;
#endif

//End file
#endif
