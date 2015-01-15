
// Includes
#include "Select_File.h"

#if CDS_use == 1

inline void CDS_Initialization() {
    _CDS.Enable = true;
}

inline void CDS_Main() {
    //setCDSPoint(cds);
    if (_CDS.Enable == true) {
        if (_CDS.GO == false) {
            if (_CDS.ADtoGO == false) {
                _CDS.Time++;
                if (_CDS.Time >= (100 / Main_Time))//(ms/main time)
                {
                    _CDS.Time = 0;
                    _CDS.ADtoGO = true;
                }
            }
        } else {
            if (_CDS.GO == true) {
                _CDS.GO = false;
                if (_CDS.Status == false) {
                    if (_CDS.SignalAD >= _CDS.VRAD) {
                        _CDS.Status = true;
                    }
                } else {
                    if (_CDS.SignalAD <= (_CDS.VRAD - 100)) {
                        _CDS.Status = false;
                    }
                }
            }
        }
    }
}

//******************************************************************************

char getCDS_Status() {
    char status = _CDS.Status == true ? 1 : 0;
    return status;
}
//******************************************************************************

inline void getCDS_AD(char channel1, char channel2) {
    char i = 0, j = 0;
    if (_CDS.ADtoGO == true) {
        _CDS.GO = true;
        _CDS.VRAD = getAD(channel1, ADCON1_VDD);
        _CDS.SignalAD = getAD(channel2, ADCON1_VDD);
    }
}
#endif