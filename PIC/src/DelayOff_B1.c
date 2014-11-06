
// Includes
#include "Select_File.h"

#if DelayOff_use == 1

void DelayOffPointSelect(char sw) {
#ifdef use_1KEY
    if (sw == 1) {
        DelayOff = &DlySw1;
    }
#endif
#ifdef use_2KEY
    else if (sw == 2) {
        DelayOff = &DlySw2;
    }
#endif
#ifdef use_3KEY
    else if (sw == 3) {
        DelayOff = &DlySw3;
    }
#endif
}
//*********************************************************

inline void DelayOff_Initialization() {
#ifdef use_1KEY
    DlyOff_Initialization(1);
#endif

#ifdef use_2KEY
    DlyOff_Initialization(2);
#endif

#ifdef use_3KEY
    DlyOff_Initialization(3);
#endif
}
//*********************************************************

inline void DelayOff_Main() {
#ifdef use_1KEY
    DlyOff_Main(1);
#endif

#ifdef use_2KEY
    DlyOff_Main(2);
#endif

#ifdef use_3KEY
    DlyOff_Main(3);
#endif
}
//*********************************************************

void DlyOff_Initialization(char sw) {
    DelayOffPointSelect(sw);
    DelayOff->Enable = true;
}
//*********************************************************

void DlyOff_Main(char sw) {
    DelayOffPointSelect(sw);
    if (DelayOff->GO == true) {
        DelayOff->SecondTime++;
        if (DelayOff->SecondTime >= SecondTimeValue) {
            DelayOff->SecondTime = 0;
            DelayOff->MinuteTime++;
            if (DelayOff->MinuteTime >= DelayOff->Value) {
                DelayOff->MinuteTime = 0;
                DelayOff->GO = false;
                //關燈
                setSw_Status(sw, 0);
                setRFSW_Status(sw, 0);
                setRF_DimmerLights(sw, 0);
                setDimmerLights_Trigger(sw, 0);
                setTxData();
                setBuz(1, BuzzerOnOffTime);
            }
        }
    }
}
//*********************************************************

void setDelayOff_GO(char sw, char command, char value) {
    DelayOffPointSelect(sw);
    if (DelayOff->Enable == true) {
        DelayOff->GO = command == 1 ? true : false;
        if (command == 1) {
            DelayOff->Value = DelayTimejudge(value);
            if (((value % 16) == 5 || (value % 16) == 0) && value <= 0x25) {
                setProductData(26 + sw, value);
            } else {
                setProductData(26 + sw, 0x05);
            }
        } else if (command == 0) {
            setProductData(sw + 26, 0);
        }
        DelayOff->SecondTime = 0;
        DelayOff->MinuteTime = 0;
    }
}
//*********************************************************

char DelayTimejudge(char value) {
    char i = 5, j = 0, k = 0;
    if (value <= 0x30) {
        j = value & 0x0f;
        k = (value >> 4) & 0x0f;
        i = j + (k * 10);
    }
    //    switch (value) {
    //        case 0x05:
    //            i = 5;
    //            break;
    //        case 0x10:
    //            i = 10;
    //            break;
    //        case 0x15:
    //            i = 15;
    //            break;
    //        case 0x20:
    //            i = 20;
    //            break;
    //        case 0x25:
    //            i = 25;
    //            break;
    //        case 0x30:
    //            i = 30;
    //            break;
    //    }
    return i;
}

//end file
#endif