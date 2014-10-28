
// Includes
#include "Select_File.h"

#if PIR_use == 1

void PIR_Initialization() {
    _PIR.Enable = true;
    _PIR.RangeValue = RangeMinimum;
    _PIR.CloseTimeValue = 150;
    _PIR.TriggerValue = 2;
}

void PIR_Main() {
    if (_PIR.Enable == true) {

        if (getCDS_Status() == true) {
            if (_PIR.Detect == false) {
                _PIR.Detect = true;
                _PIR.Available = true;
                if (_PIR.OK == false) {
                    setLED(2, 1);
                }
            }
        } else {
            if (_PIR.Detect == true) {
                _PIR.Detect = false;
                _PIR.Available = false;
                _PIR.Status = false;
                ErrLED = true;
                //auto gain restore
                _PIR.Time = 0;
                _PIR.RangeTime1 = 0;
                _PIR.RangeValue = RangeMinimum;
                _PIR.RangeCount = 0;
                //PIR
                setLED(1, 0);
                setLED(2, 0);
                _PIR.Status = false;
                if (_PIR.OK == true) {
                    _PIR.Count = 0;
                }
                _PIR.CloseTimeSeconds = 0;
                _PIR.CloseTimeMinutes = 0;

                //Lights
#ifdef use_1KEY
#if LightsControl_use == 1
                if (getLights_Status(1) == true) {
                    setLights_Trigger(1, 1);
                    setLights_Switch(1, 0);
                }
#endif
#endif
            }
        }

        if (_PIR.ADtoGO == false) {
            _PIR.Time++;
            if (_PIR.Time == 10) {//*10ms
                _PIR.Time = 0;
                _PIR.ADtoGO = true;
            }
        } else {
            if (_PIR.GO == true) {
                _PIR.GO = false;
                if (_PIR.Available == true) {
                    if (_PIR.OK == true) {
                        //auto gain
                        _PIR.Time++;
                        if (_PIR.Time == 60) {
                            _PIR.Time = 0;
                            if (_PIR.RangeCount >= 90) {
                                _PIR.RangeTime1 = 0;

                                if (_PIR.RangeValue == RangeMinimum) {
                                    _PIR.RangeValue = RangeMedium;
                                } else if (_PIR.RangeValue == RangeMedium) {
                                    _PIR.RangeValue = RangeMaximum;
                                }
                            } else if (_PIR.RangeCount <= 10) {
                                _PIR.RangeTime1++;
                                if (_PIR.RangeTime1 == 2) {
                                    _PIR.RangeTime1 = 0;

                                    if (_PIR.RangeValue == RangeMaximum) {
                                        _PIR.RangeValue = RangeMedium;
                                    } else if (_PIR.RangeValue == RangeMedium) {
                                        _PIR.RangeValue = RangeMinimum;
                                    }
                                }
                            }
                            _PIR.RangeCount = 0;
                        }

                        //PIR
                        if ((_PIR.SignalAD >= (_PIR.ReferenceVoltage - (_PIR.RangeValue + _PIR.Offset)))
                                && (_PIR.SignalAD <= (_PIR.ReferenceVoltage + (_PIR.RangeValue + _PIR.Offset)))) {
                            _PIR.Count = 0;
                            setLED(1, 0);
                            setLED(2, 0);
                        } else {
                            _PIR.RangeCount++;
                            _PIR.Count++;
                            if (_PIR.Count == _PIR.TriggerValue) {
                                _PIR.Count = 0;
                                _PIR.CloseTimeSeconds = 0;
                                _PIR.CloseTimeMinutes = 0;
                                //  Turn_On_Lights();
#ifdef use_1KEY
#if LightsControl_use == 1
                                if (getLights_Status(1) == false) {
                                    setLights_Trigger(1, 1);
                                    setLights_Switch(1, 1);
                                }
#endif
#endif

                                _PIR.Status = true;

                                if ((_PIR.SignalAD <= (_PIR.ReferenceVoltage - (_PIR.RangeValue + _PIR.Offset)))) {
                                    setLED(1, 1);
                                    setLED(2, 0);
                                } else {
                                    setLED(1, 0);
                                    setLED(2, 1);
                                }
                            }
                        }
                    }
                }
            }
        }
        if (_PIR.OK == false) {
            _PIR.Count++;
            if (_PIR.Count == 3000) {
                _PIR.Count = 0;
                _PIR.OK = true;
                setLED(2, 0);
            }
        }
        if (_PIR.Status == true) {
            _PIR.CloseTimeSeconds++;
            if (_PIR.CloseTimeSeconds == 100) {
                _PIR.CloseTimeSeconds = 0;
                _PIR.CloseTimeMinutes++;
                if (_PIR.CloseTimeMinutes == _PIR.CloseTimeValue) {
                    _PIR.CloseTimeMinutes = 0;
                    _PIR.Status = false;
                    //Turn_Off_Lights();
#ifdef use_1KEY
#if LightsControl_use == 1
                    if (getLights_Status(1) == true) {
                        setLights_Trigger(1, 1);
                        setLights_Switch(1, 0);
                    }
#endif
#endif

                }
            }
        }
    }
}

void getPIR_AD(char channel1, char channel2) {
    char i = 0, j = 0;

    if (_PIR.ADtoGO == true) {
        _PIR.GO = true;
        _PIR.ADRES = getAD(channel1, ADCON1_VDD);
        _PIR.VRAD = _PIR.ADRES / 51;
        _PIR.VRAD1 = _PIR.ADRES;
        _PIR.ADRES = getAD(channel2, ADCON1_VDD);
        _PIR.SignalAD = _PIR.ADRES;

        switch (_PIR.VRAD) {
            case 0:
                if (_PIR.VRAD1 < 10) {
                    _PIR.CloseTimeValue = 5;
                } else {
                    _PIR.CloseTimeValue = 60;
                }
                break;
            case 1:
                _PIR.CloseTimeValue = 300;
                break;
            case 2:
                _PIR.CloseTimeValue = 600;
                break;
            case 3:
                _PIR.CloseTimeValue = 900;
                break;
            case 4:
                _PIR.CloseTimeValue = 1200;
                break;
        }

        _PIR.TenAverage[_PIR.TenCount] = _PIR.SignalAD;
        for (i = 0; i < 10; i++) {
            _PIR.TenAverageValue += _PIR.TenAverage[i];
        }
        _PIR.HundredAverage[_PIR.HundreCount] = (_PIR.TenAverageValue / 10);
        _PIR.TenAverageValue = 0;

        for (i = 0; i <= 9; i++) {
            _PIR.HundredAverageValue += _PIR.HundredAverage[i];
        }
        _PIR.ReferenceVoltage = (_PIR.HundredAverageValue / 10);
        _PIR.HundredAverageValue = 0;

        if (_PIR.TenCount < 10) {
            _PIR.TenCount++;
        } else {
            _PIR.TenCount = 0;
            if (_PIR.HundreCount < 10)
                _PIR.HundreCount++;
            else
                _PIR.HundreCount = 0;
        }
    }
}


#endif