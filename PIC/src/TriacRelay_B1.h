
#ifndef _TriacRelay_H_
#define _TriacRelay_H_


//=================================================================
#if LightsControl_use == 1 

//Global extern variable declaration

struct LightsControl {

    struct {
        unsigned Detect : 1;
        unsigned LoadGO : 1;
        unsigned LoadOK : 1;
        unsigned empty : 5;
    };

};
struct LightsControl LightsControl;

struct Lights {

    struct {
        unsigned Enable : 1;
        unsigned GO : 1;
        unsigned Status : 1;
        unsigned Trigger : 1;
        unsigned Switch : 1;
        unsigned Relay : 1;
        unsigned Triac : 1;
        unsigned RelaySet : 1;
    };

    struct {
        unsigned Line : 1;
        unsigned Loop : 1;
        unsigned empty : 6;
    };

    unsigned char Time;
    unsigned char TriacTime;
    unsigned char TriacValue;
    unsigned char RelayTime;
    unsigned char RelayValue;
};
struct Lights *Lights;


#ifdef use_1KEY
struct Lights Lights1;
#endif

#ifdef use_2KEY
struct Lights Lights2;
#endif

#ifdef use_3KEY
struct Lights Lights3;
#endif

void LightsPointSelect(char lights);
void Lights_Initialization();
void Lights_Main();

void setLights_Initialization(char lights);
void setLights_Main(char lights);
void Lights_Control(char lights);
void setLights_Trigger(char lights, char command);
void setLights(char lights, char status);
char getLights_Status(char lights);
void setLights_Line(char lights);
char getAll_Lights_Line();
char getLightsControl_GO();
char getLightsControl_OK();
void setLights_ErrorClose(char lights);
char getLights_Allow_Condition(char lights);
//char getAll_Lights_Status();
#else

#define LightsPointSelect(char) ;
#define Lights_Initialization() ;
#define Lights_Main() ;
#define Lights_ERROR() ;
#define Lights_Close() ;	

#define setLights_Clear(char,char) ;
#define setLights_Initialization(char) ;
#define setLights_GO(char,char) ;
#define setLights_Main(char) ;
#define setLights_ERROR(char) ;
#define setLights_TriggerERROR(char,char) ; 
#define Lights_Control(char) ;

#define setLights_Trigger(char,char) ; 
#define setLights_Switch(char,char) ; 
#define setLights_Open(char,char) ;
#define getLights_Open(char) ;
#define setLights_Close(char,char) ;
#define getLights_Close(char) ;
#define setLights(char,char) ;
#define setLights_ErrorClose(char) ;
#endif

struct Light {

    struct {
        unsigned LoadGO : 1;
        unsigned Load_Status : 1;
        unsigned empty : 6;
    };
};
struct Light Light;

char getLight_LoadGO();
char getLight_Load_Status();
//End file
#endif