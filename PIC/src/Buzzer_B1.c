

// Includes
#include "Select_File.h"


#if Buzzer_use == 1

//*********************************************************

void Buzzer_Initialization() {
    Buz = &Buz1;
    Buz->Enable = 1;
}

//*********************************************************

void setBuz_Enable(char command) {
    Buz->Enable = command;
}
//*********************************************************

inline void Buz_Counter() {
    if (Buz->GO == true) {
        Buz->Counter++;
    }
}
//*********************************************************

void setBuz(char count, int time) {
    Buz = &Buz1;
    time /= 10;
    if (Buz->Enable == true) {
        if (Buz->GO == false) {
            Buz->GO = true;
            Buz->Counter = 0;
            Buz->Count = count;
            Buz->TimeValue = time;
            Buzzer1 = true;
        } else {
            if (Buz->BufferStatus1 == false) {
                Buz->BufferStatus1 = true;
                Buz->CountBuffer1 = count;
                Buz->TimeValueBuffer1 = time;
            } else if (Buz->BufferStatus2 == false) {
                Buz->BufferStatus2 = true;
                Buz->CountBuffer2 = count;
                Buz->TimeValueBuffer2 = time;
            }
        }
    }
}
//*********************************************************

void Buzzer_Main() {
    Buz = &Buz1;
    if (Buz->GO == true) {
        Buz->Counter++;
        if (Buz->Counter >= Buz->TimeValue) {
            Buz->Counter = 0;
            Buz->Switch = (Buzzer1 == true) ? true : false;
            if (Buz->Switch == false) {
                if (Buz->Count == 0) {
                    if (Buz->BufferStatus1 == true) {
                        Buz->BufferStatus1 = false;
                        Buz->Count = Buz->CountBuffer1;
                        Buz->TimeValue = Buz->TimeValueBuffer1;
                    } else if (Buz->BufferStatus2 == true) {
                        Buz->BufferStatus2 = false;
                        Buz->Count = Buz->CountBuffer2;
                        Buz->TimeValue = Buz->TimeValueBuffer2;
                    } else {
                        Buz->GO = false;
                    }
                } else {
                    Buz->Switch = true;

                    Buzzer1 = true;
                }
            } else {
                Buz->Switch = false;

                Buzzer1 = false;

                Buz->Count--;
            }
        }
    }
}

#endif