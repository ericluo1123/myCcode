
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
#if Dimmer_use == 1
                if (getDimmerLights_Status(sw) == 1) {
                    setDimmerLights_SwOn(sw);
                    setDimmerLights_SwOff(sw);
                }
#endif
                setProductData(26 + sw, 0);
            }
        }
    }
}
//*********************************************************

void setDelayOff_GO(char sw, char command, char value) {

    DelayOffPointSelect(sw);
    DelayOff->GO = command == 1 ? true : false;
    DelayOff->SecondTime = 0;
    DelayOff->MinuteTime = 0;

    if (command == 1) {

        char i = 5, j = 0, k = 0;
        if (((value % 16) == 5 || (value % 16) == 0) && value <= 0x30) {
            j = value & 0x0f;
            k = (value >> 4) & 0x0f;
            DelayOff->Value = j + (k * 10);

            setProductData(26 + sw, value);
        } else {
            DelayOff->Value = 0x05;
            setProductData(26 + sw, 0x05);
        }

    } else if (command == 0) {
        setProductData(26 + sw, 0);
    }
}
//*****************************************************************************

char getDelayOff_GO(char sw) {
    DelayOffPointSelect(sw);
    char go = DelayOff->GO == true ? 1 : 0;
    return go;
}
//*****************************************************************************

char DelayTimejudge(char value) {
    char i = 5, j = 0, k = 0;
    if (value <= 0x30) {
        j = value & 0x0f;
        k = (value >> 4) & 0x0f;
        i = j + (k * 10);
    }
    return i;
}

//end file
#endif