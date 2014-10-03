
#ifndef _LED_H_
#define _LED_H_

/******************************************************************
        method:
                setErrLED(char status)
                setLED1(char status)
                setLED2(char status)
                setLED3(char status)
        Description:
                status = 0	OFF
                                 1	ON
                                 10	Flash OFF
                             11	Flash ON

 *****************************************************************/

#if LED_use == 1
//Global extern variable declaration

struct LED {
    unsigned Enable : 1;
    unsigned GO : 1;
    unsigned int Time;
    unsigned char Number;
};
struct LED *LED;

//ErrLED
#ifdef ErrLED
struct LED VarErrLED;
#endif

//LED1
#ifdef LED1
struct LED VarLED1;
#endif

//LED2
#ifdef LED2
struct LED VarLED2;
#endif

//LED3
#ifdef LED3
struct LED VarLED3;
#endif

void LED_Initialization();
void LED_Main();
void LedPointSelect(char);
void setLED_Initialization(char);
void setLED_Main(char);
void setLED(char, char);
#else
#define LED_Initialization() ;
#define LED_Main() ;
#define LedPointSelect(char) ;
#define setLED_Initialization(char) ;
#define setLED_Main(char) ;
#define setLED(char,char) ;
#endif

#endif
//End file