
#ifndef _RF_Control_H_
#define _RF_Control_H_

/****************************************************************
        File list:
                CC2500_A1.c
                CC2500_A1.h
                RF_Control_A1.c
                RF_Control_A1.h
	
        addFunction
                CC2500_PowerOnInitial();
                RF_Initial();
                RF_Main();

        method:
 *send data step:
                step:1
                                setRF_Data(char location,char value);
                                        location(0~20)
                                        value(1~255)
                step:2
                                setTxData();

 *receive data
                                getRxData(); //if have receive data


                setRF_Enable(char command);
                        command(0 ~ 1)

/***************************************************************/

#if CC2500_use == 1
//Global extern variable declaration

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
        unsigned Count : 1;
        unsigned Run : 1;
        unsigned Bus:1;
        unsigned empty : 5;
    };

    unsigned char DebounceTime;

};
struct RF *RF;

#ifdef RadioFrequency1
struct RF RF1;
#endif

void RfPointSelect(char);
void RF_Initialization();
void RF_Main();
void setRF_Initialization(char);
void setRF_Main(char);
void setTxData(char);
void getRxData(char);
void setRF_Enable(char, char);
void setLog_Code(char);
void setControl_Lights_Table(char);
void RF_RxDisable(char);
void setRF_Learn(char, char);
void setRF_ReceiveGO(char, char);
void setRF_RxStatus(char, char);

#define setRF_Data(location,value) RF_Data[location]=value

struct RFSW {

    struct {
        unsigned Status : 1;
        unsigned empty : 7;
    };
};
struct RFSW *RFSW;


void RfSWPointSelect(char);
void setRFSW_Control(char);
void setRFSW_AdjControl(char);
void setRFSW_Status(char, char);


#ifdef use_1KEY
struct RFSW RFSW1;
#endif

#ifdef use_2KEY
struct RFSW RFSW2;
#endif

#ifdef use_3KEY 
struct RFSW RFSW3;
#endif


#if Dimmer_use == 1
void setRF_DimmerValue(char);
void setRF_DimmerLights(char, char);
#else
#define setRF_DimmerValue(char) ;
#define setRF_DimmerLights(char,char) ;
#endif

#else 

#define RfPointSelect(char) ;
#define RF_Initialization() ;
#define RF_Main() ;
#define setRF_Initialization(char) ;
#define setRF_Main(char) ;
#define setTxData(char) ;
#define getRxData(char) ;
#define setRF_Enable(char,char) ;
#define setLog_Code(char) ;
#define setControl_Lights_Table(char) ;
#define RF_RxDisable(char) ;
#define setRF_Learn(char,char) ;
#define setRF_ReceiveGO(char,char) ;
#define setRF_RxStatus(char,char) ;

#define setRF_Data(location,value) ;

#define setRF_DimmerValue(char) ;
#define setRF_DimmerLights(char,char) ;

#define RfSWPointSelect(char) ;
#define setRFSW_Control(char) ;
#define setRFSW_AdjControl(char) ;
#define setRFSW_Status(char,char) ;
#endif

#endif