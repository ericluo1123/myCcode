
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
 * void Buzzer_Initialization()\n
 * \n
 * buzzer initialization
 */
void Buzzer_Initialization();
/**
 * void Buzzer_Main()\n\n
 * buzzer main code 
 */
void Buzzer_Main();
/**
 * void setBuz(char count, int time)
 * 
 * set buzzer beeps and time
 *
 * @param count
 *
 * beeps count value
 *
 * @param time
 *
 * time value /ms
 */
void setBuz(char count, int time);
/**
 * void setBuz_Enable(char command)
 *
 * control buzzer enable/disable
 * 
 * @param command
 * 
 * command 1(enable)/0(disable)
 */
void setBuz_Enable(char command);
/**
 * inline void setBuz_Counter()
 * 
 * buzzer counter
 */
inline void Buz_Counter();
#else
#define Buzzer_Initialization() ;
#define Buzzer_Main() ;
#define setBuz_Main(char) ;
#define setBuz(char,int) ;	
#define setBuz_Enable(char) ;
#endif

//End file
#endif
