

// Includes
#include "Select_File.h"


#if Buzzer_use == 1

//*********************************************************

inline void Buzzer_Initialization() {

    Buz1.Enable = true;
}
//*********************************************************

void setBuz_Enable(char command) {
    Buz1.Enable = command;
}
//*********************************************************

void setBuz(char count, int time) {
    time /= 10;
    if (Buz1.Enable == true) {
        if (Buz1.GO == false) {
            Buz1.GO = true;
            Buz1.Counter = 0;
            Buz1.Count = count;
            Buz1.TimeValue = time;
            Buzzer1 = true;
        } else {
            if (Buz1.BufferStatus1 == false) {
                Buz1.BufferStatus1 = true;
                Buz1.CountBuffer1 = count;
                Buz1.TimeValueBuffer1 = time;
            } else if (Buz1.BufferStatus2 == false) {
                Buz1.BufferStatus2 = true;
                Buz1.CountBuffer2 = count;
                Buz1.TimeValueBuffer2 = time;
            }
        }
    }
}
//*****************************************************************************

inline void Buzzer_Main() {
    if (Buz1.GO == true) {
        Buz1.Counter++;
        if (Buz1.Counter >= Buz1.TimeValue) {
            Buz1.Counter = 0;
            Buz1.Switch = (Buzzer1 == true) ? true : false;
            if (Buz1.Switch == false) {
                if (Buz1.Count == 0) {
                    if (Buz1.BufferStatus1 == true) {
                        Buz1.BufferStatus1 = false;
                        Buz1.Count = Buz1.CountBuffer1;
                        Buz1.TimeValue = Buz1.TimeValueBuffer1;
                    } else if (Buz1.BufferStatus2 == true) {
                        Buz1.BufferStatus2 = false;
                        Buz1.Count = Buz1.CountBuffer2;
                        Buz1.TimeValue = Buz1.TimeValueBuffer2;
                    } else {
                        Buz1.GO = false;
                    }
                } else {
                    Buz1.Switch = true;

                    Buzzer1 = true;
                }
            } else {
                Buz1.Switch = false;

                Buzzer1 = false;

                Buz1.Count--;
            }
        }
    }
}
//*****************************************************************************

int getBuz_GO() {
    int i = Buz1.GO;
    return i;
}

#endif