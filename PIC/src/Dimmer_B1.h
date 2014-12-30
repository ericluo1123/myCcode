
#ifndef _Dimmer_H_
#define _Dimmer_H_
/**
 * Dimmer header
 */
#if Dimmer_use == 1
#define Dimmer_Debug 0
//private

struct DimmerLights {
    //public
    //private

    struct {
        unsigned SwFlag : 1;
        unsigned Trigger : 1;
        unsigned Switch : 1;

        unsigned DimmingSwFlag : 1;
        unsigned DimmingTrigger : 1;
        unsigned DimmingSwitch : 1;

        unsigned MosfetOpen : 1;
        unsigned MosfetClose : 1;
    };

    struct {
        unsigned Status : 1;
        unsigned Line : 1;
        unsigned Loop : 1;
        unsigned TriacFlag : 1;
        unsigned OK : 1;
        unsigned Triac : 1;
        unsigned DimmingRun : 1;
        unsigned empty : 2;
    };


    unsigned char TriacCount;
    unsigned char MosfetSignalCount;
    unsigned char TriacTime;
    unsigned char DetectCount;
    unsigned char TuneValue;
    unsigned char MosfetOK_Count;
};
struct DimmerLights *DimmerLights;

#if Switch_Class == 1
#define ID_1KEY_1 RB4 = 1
#define ID_1KEY_0 RB4 = 0
#if Switch_Optrion == 1
#define setLED2(command) LED2=!command
#else
#define setLED2(command) ;
#endif
#else
#define ID_1KEY_1 ;
#define ID_1KEY_0 ;
#define setLED2 ;
#endif


#ifdef use_1KEY
struct DimmerLights DimmerLights1;
#endif

#ifdef use_2KEY
struct DimmerLights DimmerLights2;
#endif

#ifdef use_3KEY
struct DimmerLights DimmerLights3;
#endif

#if Self_Test == 1
void DimmerLightsOpenShow();
#else
#define DimmerLightsOpenShow() ;
#endif


//public
inline void DimmerLights_SelectPointer(char lights);
void DimmerLights_Initialization();
void setDimmerLights_Initialization(char lights);
void setDimmerLights_SwOn(char sw);
void setDimmerLights_SwOff(char sw);
void setDimmerLights_DimmingOn(char sw);
void DimmerLights_Main();
void setDimmerLights_Main(char lights);
void setDimmerLights_OnOff(char lights, char command);
void setDimmerLights_Dimming(char lights, char status);
char getDimmerLights_Allow_Condition(char lights);

void setDimmerLights_Line(char lights);
char getDimmerLights_Line();
void setDimmerLights_Status(char lights, char command);
char getDimmerLights_Status(char lights);

char getDimmerLights_PercentToValue(char value);
char getDimmerLights_ValueToPercent(char value);

char getAll_DimmerLights_Trigger();
void setDimmerLights_DimmingRun(char lights,char command);

//Global extern variable declaration
//******************************************************************************

struct Dimmer_Interrut {

    struct {
        unsigned GO : 1;
        unsigned Tune : 1;
        unsigned Start : 1;
        unsigned ControlStatus : 1;
        unsigned Dimming_Sw : 1;
        unsigned Dimming_Status : 1;
        unsigned Dimming_RF : 1;
        unsigned empty : 1;
    };


    unsigned char Count;
    unsigned char TuneTime;
    unsigned char TuneTimeValue;
    unsigned char DimmingValue;
    unsigned char MaxmumValue;
    unsigned char MinimumValue;
};
struct Dimmer_Interrut *DimmerIntr;

#ifdef use_1KEY
struct Dimmer_Interrut DimmerIntr1;
#endif

#ifdef use_2KEY
struct Dimmer_Interrut DimmerIntr2;
#endif

#ifdef use_3KEY
struct Dimmer_Intr DimmerIntr3;
#endif

void DimmerIntr_Initialization();
void setDimmerIntr_ControlStatus(char lights, char command);
void setDimmerIntr_DimmingValue(char lights, char value);
char getDimmerIntr_DimmingValue(char lights);
void setDimmerIntr_MaxmumValue(char lights, char value);
char getDimmerIntr_MaxmumValue(char lights);
void setDimmerIntr_MinimumValue(char lights, char value);
char getDimmerIntr_MinimumValue(char lights);
void setDimmerIntr_Dimming_Sw(char lights, char command);
void setDimmerIntr_Dimming_RF(char lights, char command);
char getAll_DimmerIntr_ControlStatus();
char getAll_DimmerIntr_Dimming_Sw();
char getAll_DimmerIntr_Dimming_Sw_RF();

inline void setDimmerIntr_TMR(char lights);
inline void setDimmerIntr_IOC(char lights);

inline void DimmerLights_MOSFET_TMR_1();
inline void DimmerLights_MOSFET_TMR_2();

inline void DimmerLights_MOSFET_IOC_1();
inline void DimmerLights_MOSFET_IOC_2();

//******************************************************************************

struct Dimmer {
    //	unsigned LoadERROR:1;
    //	unsigned TempERROR:1;
    //	unsigned PFERROR:1;

    struct {
        unsigned AdjGO : 1;
        unsigned LoadGO : 1;
        unsigned Load_Status : 1;
        unsigned empty : 4;
    };

    unsigned char Load;
    volatile unsigned char Correction;
};
#ifdef DimmerReference1
struct Dimmer Dimmer;
#endif

inline void Dimmer_Initialization();
char getDimmer_LoadGO();
char getDimmer_Load_Status();

//*********************************************************


#else
#define DimmerLightsOpenShow() ;

#define DimmerLightsPointSelect(char) ;
#define DimmerLights_Initialization() ;
#define DimmerLights_Main() ;
#define DimmerLights_Exceptions(char) ;
#define DimmerLights_Close() ;

#define setDimmerLights_Initialization(char) ;
#define setDimmerLights_GO(char,char) ;
#define setDimmerLights_Main(char) ;
#define setDimmerLights_IntrControl(lights) ;
#define setDimmerLights_ERROR(char) ;
#define setDimmerLights_TriggerERROR(char,char) ; 
#define setDimmerLights_OnOff(char,char) ;
#define setDimmerLights_Adj(char,char) ;
#define setDimmerLights_AdjRF(char) ;
#define getPercentValue(char) 0
#define setPercentValue(char) 0

#define setDimmerLights_MaxmumValue(char,char) ; 
#define setDimmerLights_Trigger(char,char) ; 
#define setDimmerLights_Switch(char,char) ; 
#define setDimmerLights_AdjGo(char,char) ; 
#define setDimmerLights_TriggerAdj(char,char) ;
#define getDimmerLights_StatusFlag() ;
#define getDimmerLights_Trigger() ;

#define setDimmerLights_Detect(char,char) ;
//		#define setDimmerLights_Open(char,char);
//		#define getDimmerLights_Open(char);
//		#define setDimmerLights_Close(char,char);
//		#define getDimmerLights_Close(char);	

#define Dimmer_Initialization() ;
//	#define DimmerPointSelect(char) ;
//	#define setDimmer_TempERROR(char,char) ; 	
//	#define setDimmer_LoadERROR(char,char) ; 
//	#define setDimmer_PFERROR(char,char) ;
//	#define setDimmer_Detect(char,char) ;
//	#define getDimmer_Detect(char) ;
#define getDimmerLights_Status(char) 0
#define getDimmer_LoadGO() ;
#define getAll_DimmerLights_AdjSw() ;
#define getDimmer_Load_Status() ;
#endif

//End file
#endif

