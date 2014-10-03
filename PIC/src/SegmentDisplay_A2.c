
// Includes
#include "Select_File.h"


#if SegmentDisplay_use == 1

void SegmentDisplay_Initial() {
    Segment = &VarSegment;
    Segment->Enable = 1;
#if Display_Dec == 1
    Segment->Dec = 1;
#endif
#if Display_Hex == 1
    Segment->Hex = 1;
#endif
}
//*********************************************************

void setSegmentDisplayNumber(int number) {
    char i;
    if (Segment->Enable) {
        Segment->GO = 1;
        if (Segment->Hex) {
            Segment->Num[0] = (number & 0x000f);
            Segment->Num[1] = ((number >> 4)&0x000f);
            Segment->Num[2] = ((number >> 8)&0x000f);
            Segment->Num[3] = ((number >> 12)&0x000f);
        } else if (Segment->Dec) {
            if (number > 0x270f)//max 9999
            {
                for (i = 0; i < 4; i++) {
                    Segment->Num[i] = 16;
                }
            } else {
                Segment->Num[3] = (number / 1000);
                number %= 1000;
                Segment->Num[2] = (number / 100);
                number %= 100;
                Segment->Num[1] = (number / 10);
                number %= 10;
                Segment->Num[0] = number;
            }
        }
        if (Segment->Num[3] > 0)//���줸>0�~���
        {
            Segment->DisplayCount = 3;
        } else if (Segment->Num[2] > 0) {
            Segment->DisplayCount = 2;
        } else if (Segment->Num[1] > 0) {
            Segment->DisplayCount = 1;
        } else {
            Segment->DisplayCount = 0;
        }
    }
}
//*********************************************************

void SegmentDisplay_Main() {
    if (Segment->GO) {
        Segment->Time++;
        if (Segment->Time == 5)//ms
        {
            Segment->Time = 0;
            ComValue &= 0x0f; //RA4~RA7�M0�A�O��RA0~RA3���A
            if (Segment->ComCount == 0) {
                Com0 = 1;
            } else if (Segment->ComCount == 1) {
                Com1 = 1;
            } else if (Segment->ComCount == 2) {
                Com2 = 1;
            } else if (Segment->ComCount == 3) {
                Com3 = 1;
            }
            DisplayValue = Segment->Display[Segment->Num[Segment->ComCount]]; //set display value
            if (Segment->ComCount < Segment->DisplayCount)//���Ȥ~���
            {
                Segment->ComCount++;
            } else {
                Segment->ComCount = 0;
            }
        }
    }
}

#endif
