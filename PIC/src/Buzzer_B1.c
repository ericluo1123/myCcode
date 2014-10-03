

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

void setBuz(char count, int time) {
    time *= 20;
    if (Buz->Enable) {
        if (!Buz->GO) {
            Buz->GO = 1;
            Buz->Count = count;
            Buz->TimeValue = time;

            Buzzer1 = 1;
        } else {
            if (!Buz->BufferStatus1) {
                Buz->BufferStatus1 = 1;
                Buz->CountBuffer1 = count;
                Buz->TimeValueBuffer1 = time;
            } else if (!Buz->BufferStatus2) {
                Buz->BufferStatus2 = 1;
                Buz->CountBuffer2 = count;
                Buz->TimeValueBuffer2 = time;
            }
        }
    }
}
//*********************************************************

void Buzzer_Main() {
    Buz->Switch = (Buzzer1) ? 1 : 0;

    if (Buz->GO) {
        //Buz->Time++;
        if (Buz->Time >= Buz->TimeValue) {
            Buz->Time = 0;
            if (!Buz->Switch) {
                if (Buz->Count == 0) {
                    if (Buz->BufferStatus1) {
                        Buz->BufferStatus1 = 0;
                        Buz->Count = Buz->CountBuffer1;
                        Buz->TimeValue = Buz->TimeValueBuffer1;
                    } else if (Buz->BufferStatus2) {
                        Buz->BufferStatus2 = 0;
                        Buz->Count = Buz->CountBuffer2;
                        Buz->TimeValue = Buz->TimeValueBuffer2;
                    } else {
                        Buz->GO = 0;
                    }
                } else {
                    Buz->Switch = 1;

                    Buzzer1 = 1;
                }
            } else {
                Buz->Switch = 0;

                Buzzer1 = 0;

                Buz->Count--;
            }
        }
    }
}

#endif