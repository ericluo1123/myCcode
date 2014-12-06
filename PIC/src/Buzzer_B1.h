/**
 * buzzer header file
 */
#ifndef _Buzzer_H_
#define _Buzzer_H_


#if Buzzer_use == 1
//Global variable declaration

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
#ifdef Buzzer1
struct Buzzer Buz1;
#endif

//default Interval Time
#define BuzzerPowerOnTime	50	//ms 
#define BuzzerErrorTime		300	//ms 
#define BuzzerOnOffTime		100	//ms 

/**
 * void Buzzer_Initialization()\n
 * buzzer initialization\n
 */
inline void Buzzer_Initialization();
/**
 * void Buzzer_Main()\n
 * buzzer main code \n
 */
inline void Buzzer_Main();
/**
 * void setBuz(char count, int time)\n
 * set buzzer beeps and time\n
 * @param count\n
 * count value=1~10\n
 * @param time\n
 * time value=100~1000 ms\n
 */
void setBuz(char count, int time);
/**
 * void setBuz_Enable(char command)\n
 * control buzzer enable/disable\n
 * @param command\n
 * enable command value=1/enable
 * disable command value=0/disable
 */
void setBuz_Enable(char command);
/**
 * get buz GO value
 */
int getBuz_GO();
#else
#define Buzzer_Initialization() ;
#define Buzzer_Main() ;
#define setBuz_Main(char) ;
#define setBuz(char,int) ;	
#define setBuz_Enable(char) ;
#define getBuz_GO() 0
#endif

//End file
#endif
