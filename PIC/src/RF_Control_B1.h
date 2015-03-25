
#ifndef _RF_Control_H_
#define _RF_Control_H_
/**
 * RF control header
 */

#if CC2500_use == 1 
//Global extern variable declaration
#define RF_RunTime_Value 200

struct RF {

    struct {
        unsigned Enable : 1;
        unsigned ReceiveGO : 1;
        unsigned TransceiveGO : 1;
        unsigned RxStatus : 1;
        unsigned TxStatus : 1;
        unsigned Debounce : 1;
        unsigned Learn : 1;
        unsigned Key : 1;
    };

    struct {
        unsigned Sleep : 1;
        unsigned Run : 1;
        unsigned Bus : 1;
        unsigned Checked : 1;
        unsigned RxChecked : 1;
        unsigned Correction : 1;
        unsigned Timeout : 1;
        unsigned All_Lights_Close : 1;
    };

    struct {
        unsigned flagDimming : 1;
        unsigned empty : 7;
    };

    unsigned int Count;
    unsigned char CheckCount;
    unsigned int CheckedCounter;
    unsigned int RunTime;
    unsigned char DebounceTime;
    unsigned int CorrectionCounter;
    unsigned int TimeoutCount;

};

#ifdef RadioFrequency1
struct RF RF1;
#endif

inline void RF_Initialization();
inline void setRF_Initialization();
inline void RF_Main();
inline void setRF_Main();
inline void setTxData();
inline void setData();
inline void getRxData();
//inline void setRF_Enable(char command);
inline void setLog_Code();
inline void setControl_Lights_Table();
inline void RF_RxDisable();
inline void setRF_Learn(char command);
//inline void setRF_ReceiveGO(char command);
inline void setRF_RxStatus(char command);
inline char getRF_KeyStatus();
inline void RF_Timeout_Counter();
inline void setRF_TimeoutCleared();
//#define setRF_Data(location,value) RF_Data[location]=value

void setRFSW_Control(char sw);
void setRFSW_AdjControl(char sw);
inline void setRFSW_Status(char sw, char command);
inline void setRF_TransceiveGO(char command);
void setRF_AdjControl(char sw);
char getRF_flagDimming();
void setRF_flagDimming(char command);

#if Dimmer_use == 1
//inline void setRF_DimmerValue(char lights);
inline void setRF_DimmerLights(char lights, char on);
#else
#define setRF_DimmerValue(char) ;
#define setRF_DimmerLights(char,char) ;
#endif

#else 

#define RF_Initialization() ;
#define RF_Main() ;
#define setRF_Initialization() ;
#define setRF_Main() ;
#define setTxData() ;
#define getRxData() ;
#define setRF_Enable(char) ;
#define setLog_Code() ;
#define setControl_Lights_Table() ;
#define RF_RxDisable() ;
#define setRF_Learn(char) ;
#define setRF_ReceiveGO(char) ;
#define setRF_RxStatus(char) ;

#define setRF_Data(location,value) ;

#define setRF_DimmerValue(char) ;
#define setRF_DimmerLights(char,char) ;

#define RfSWPointSelect(char) ;
#define setRFSW_Control(char) ;
#define setRFSW_AdjControl(char) ;
#define setRFSW_Status(char,char) ;
#define setRF_TransceiveGO(char);
#endif

#endif