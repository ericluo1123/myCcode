/**
 * LED header file\n
 */
#ifndef _LED_H_
#define _LED_H_

#if LED_use == 1
//Global ariable declaration

struct LED {

    union {

        struct {
            unsigned Enable : 1;
            unsigned GO : 1;
            unsigned empty : 6;
        };
    };
    unsigned int Time;
    unsigned char Number;
};
struct LED *LED;

//ErrLED
#ifdef ErrLED
struct LED VarErrLED;
#else
#define ErrLED ;
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

/**
 * void LED_Initialization()\n
 * led initialization\n
 */
inline void LED_Initialization();
/**
 * void LED_Main()\n
 * led main\n
 */
inline void LED_Main();
/**
 *void LedPointSelect(char led)\n
 * @param led\n
 * select LED1      value = 1\n
 * select LED1      value = 1\n
 * select LED1      value = 1\n
 * select ErrLED    value = 99\n
 */
void LedPointSelect(char led);
/**
 * void setLED_Initialization(char led)\n
 * @param led\n
 * select LED1      value = 1\n
 * select LED1      value = 1\n
 * select LED1      value = 1\n
 * select ErrLED    value = 99\n
 */
void setLED_Initialization(char led);
/**
 * void setLED_Main(char led)\n
 * @param led\n
 * select LED1      value = 1\n
 * select LED1      value = 1\n
 * select LED1      value = 1\n
 * select ErrLED    value = 99\n
 */
void setLED_Main(char led);
/**
 * void setLED(char led, char command)\n
 * @param led\n
 * select LED1      value = 1\n
 * select LED1      value = 1\n
 * select LED1      value = 1\n
 * select ErrLED    value = 99\n
 * @param command\n
 * led off  command         value=0\n
 * led on   command         value=1\n
 * led flash off command    value =10\n
 * led flash on command     value = 11\n
 */
void setLED(char led, char command);
#else
#define LED_Initialization() ;
#define LED_Main() ;
#define LedPointSelect(char) ;
#define setLED_Initialization(char) ;
#define setLED_Main(char) ;
#define setLED(char,char) ;
#endif

#if PIR_use == true

struct PIRLED {

    union {

        struct {
            unsigned GO : 1;
            unsigned GO1 : 1;
            unsigned GO2 : 1;
            unsigned GO3 : 1;
            unsigned status:1;
            unsigned empty : 3;
        };
    };
    unsigned char Count;
    unsigned int Time;
};
struct PIRLED PIRLED;

void setPIRLED_Main();
#else
#endif

#endif
//End file