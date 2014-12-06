/**
 * main header file
 */
#ifndef _Main_H_	
#define	_Main_H_

//Global  variable declaration

#ifndef MCU_16F723A 

typedef struct Product {
    unsigned char Data[32];
} Product;

Product *product;

Product _product = {
    {
        0x63, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00
    }
};
//0=Command	
//1=Command
//1=Temperature
//3=Temperature
//4=Humidity
//5=Humidity 
//6=Barometric pressure 
//7=Barometric pressure 
//8=Electricity
//9=Dimmer
//10=Electric  current 
//11=Year
//12=Week 
//13=Serial  Number
//14=Serial  Number
//15=Lights Status
//16=Timmer Command
//17=Timmer Time
//18=Reserved
//19=Reserved
//20=Key ID
//21=Key1 Dimmer Value
//22=Key2 Dimmer Value
//23=Key3 Dimmer Value
//24=TemperatureH
//25=TemperatureL
//26=?
//27=Key1 Timer
//28=Key2 Timer
//29=Key3 Timer


#define setProductData(address,data) product->Data[address]=data
#else
#define setProductData(address,data) ;
#endif

struct myMain {

    struct {
        unsigned PowerON : 1;
        unsigned Flag : 1;
        unsigned GO : 1;
        unsigned FirstOpen : 1;
        unsigned SelfTest : 1;
        unsigned First : 1;
        unsigned Test : 1;
        unsigned Tempty : 1;
    };

    unsigned char PowerCount;
#if Debug == 1
    unsigned int Count;
    unsigned int Count1;
    unsigned int Count2;
    unsigned int Count3;
#endif
    //    unsigned char IOC_Count;
    //    unsigned char Test;
    //    unsigned char ClockCount;

    struct {
        unsigned i : 1;
        unsigned j : 1;
        unsigned k : 1;
        unsigned l : 1;
        unsigned m : 1;
        unsigned n : 1;
        unsigned o : 1;
        unsigned p : 1;
    };

    struct {
        unsigned q : 1;
        unsigned r : 1;
        unsigned Timeout : 1;
        unsigned empty : 5;
    };

    unsigned int Timeout_Counter;

};
struct myMain myMain;
//struct myMain *myMain;


//Routine declaration
/**
 * void myMain_Initialization()\n
 * my main initialization\n
 */
inline void myMain_Initialization();
/**
 * inline void my_Main();\n
 * my Main\n
 */
inline void my_Main();
/**
 * void my_Main()\n
 * my main time\n
 */
inline void my_MainTimer();
//end
/**
 * Test Point cleared
 */
inline void Timeout_Counter();
inline void set_TimeoutCleared();
void setMain_Exception(char command);
char getMain_AD_OK();
char getMain_LightsStatus();
char getMain_All_Error_Status(char command);
char getMain_Lights_Count();
char getMain_LoadOK();

#endif		