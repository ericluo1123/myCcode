
#ifndef _Dimmer_H_
#define _Dimmer_H_
/**
 * Dimmer header
 */
#if Dimmer_use == 1

//private

struct DimmerLights {

    union {

        struct {
            unsigned GO : 1;
            unsigned Signal : 1;
            unsigned AdjRF : 1;
            unsigned AdjFlag : 1; //adj control
            unsigned AdjStatus : 1; //adj status
            unsigned Status : 1; //lights status
            unsigned StatusFlag : 1; //triac control
            unsigned OverLoad : 1;
        };
    };
    unsigned char DimmingTime;
    unsigned char DimmingTimeValue;
    unsigned char Count;
    unsigned char DimmingValue;
    unsigned char MaxmumValue;
    unsigned char MinimumValue;

    unsigned char TriacTime;

    union {

        struct {
            unsigned Flag : 1;
            unsigned Switch : 1;
            unsigned Trigger : 1;
            unsigned AdjGo : 1;
            unsigned TriggerAdj : 1;
            unsigned Triac : 1;
            unsigned MosfetOpen : 1;
            unsigned MosfetClose : 1;
        };
    };

    union {

        struct {
            unsigned Line : 1;
            unsigned DetectClose : 1;
            unsigned OK : 1;
            unsigned MosfetSignal : 1;
            unsigned MosfetOK : 1;
            unsigned TriacFlag : 1;
            unsigned SwFlag : 1;
            unsigned SwAdj : 1;
        };
    };
    unsigned char TriacCount;
    unsigned char DetectCount;
    unsigned char MosfetSignalCount;
    unsigned char TuneValue;
    unsigned char MosfetOK_Count;
};
struct DimmerLights *DimmerLights;
struct DimmerLights *DimmerLightsIntr;
struct DimmerLights *DimmerLightsIntrIOC;

#if Switch_Class == 1
#define ID_1KEY_1 RB4=1
#define ID_1KEY_0 RB4=0
#define setLED2(command) LED2=!command
#else
#define ID_1KEY_1 ;
#define ID_1KEY_0 ;
#define setLED2 ;
#endif


#ifdef use_1KEY
struct DimmerLights *DimmerLights11;
struct DimmerLights DimmerLights1;
#endif

#ifdef use_2KEY
struct DimmerLights *DimmerLights22;
struct DimmerLights DimmerLights2;
#endif

#ifdef use_3KEY
struct DimmerLights *DimmerLights33;
struct DimmerLights DimmerLights3;
#endif

#if Self_Test == 1
void DimmerLightsOpenShow();
#else
#define DimmerLightsOpenShow() ;
#endif


//public
inline void DimmerIntrIOCPointSelect(char lights);
inline void setDimmerLights_IntrIOC_GO(char lights);

inline void setDimmerLights_IntrControl(char lights);
inline void DimmerIntrPointSelect(char lights);


void DimmerLightsPointSelect(char lights);
void DimmerLights_Initialization();
void DimmerLights_Main();
void DimmerLights_Exceptions(char status);
void DimmerLights_Close();

void setDimmerLights_Initialization(char lights);
void setDimmerLights_GO(char lights, char command);
void setDimmerLights_Main(char lights);
void setDimmerLights_ERROR(char lights);
void setDimmerLights_TriggerERROR(char lights, char command);
void setDimmerLights(char lights, char status);
void setDimmerLights_Adj(char lights, char status);
void setDimmerLights_AdjRF(char lights);
char getPercentValue(char value);
char setPercentValue(char value);

void setDimmerLights_MaxmumValue(char, char);
void setDimmerLights_Trigger(char, char);
void setDimmerLights_TriggerAdj(char, char);
char getDimmerLights_StatusFlag();
char getDimmerLights_Trigger();
char getDimmerLights_Status(char lights);

void setDimmerLights_Clear(char, char);
inline void setDimmerLights_IntrControl(char lights);
char getAll_DimmerLights_AdjGO();
void setDimmerLights_SwOn(char sw);
void setDimmerLights_SwOff(char sw);
void setDimmerLights_AdjControl(char sw);
char getSw_KeyStatus(char sw);
void setDimmerLights_ErrorClose(char lights);
void setDimmerLights_Status(char lights, char command);
void setDimmerLights_Line(char lights);
char getDimmerLights_Line();

//	char getDimmerLights_Clear(char);
/*	void setDimmerLights_Close(char,char);
        char getDimmerLights_Close(char);
 */

//Global extern variable declaration

struct Dimmer {
    //	unsigned LoadERROR:1;
    //	unsigned TempERROR:1;
    //	unsigned PFERROR:1;

    union {

        struct {
            unsigned AdjGO : 1;
            unsigned LoadOK : 1;
            unsigned LoadGO : 1;
            unsigned empty : 5;
        };
    };
    unsigned char Load;
    unsigned char Correction;
};
#ifdef DimmerReference1
struct Dimmer Dimmer;
#endif
char getDimmer_LoadOK();
inline void Dimmer_Initialization();
//		void DimmerPointSelect(char);

//              void setDimmer_TempERROR(char,char);
//              void setDimmer_LoadERROR(char,char);
//              void setDimmer_PFERROR(char,char);
//
//              char getDimmer_TempERROR(char);
//              char getDimmer_LoadERROR(char);
//              char getDimmer_PFERROR(char);
//
//              void setDimmer_Detect(char,char);
//              char getDimmer_Detect(char);

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
#define setDimmerLights(char,char) ;
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

#endif

//End file
#endif

