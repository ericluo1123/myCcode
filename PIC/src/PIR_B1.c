
// Includes
#include "Select_File.h"

#if PIR_use == 1

void PIR_Initialization() {
    _PIR.RangeValue = RangeMinimum;
    _PIR.CloseTimeValue = 5;
}
//******************************************************************************

void PIR_Main() {
    char error = getMain_All_Error_Status(0);
    char cds = getCDS_Status();
    char LightsStatus = 0;

#if LightsControl_use == 1
#ifdef use_1KEY
    LightsStatus = getLights_Status(1);
#endif
#endif

#if Dimmer_use == 1
#ifdef use_1KEY
    LightsStatus = getDimmerLights_Status(1);
#endif
#endif

    if (_PIR.Enable == true) {
        if (error == 0) {
#if PIR_TestTime_Mode == 0
            if (cds == 1) {
                _PIR.Available = true;
            } else {
                _PIR.Available = false;
                if (_PIR.OK == true) {
#if LightsControl_use == 1
                    if (getLights_Status(1) == 1) {
                        setLights_Trigger(1, 0);
                    }
#endif
#if Dimmer_use == 1
#ifdef use_1KEY
                    if (getDimmerLights_Status(1) == 1) {
                        Dimmer.PIR_Trigger = true;
                        Dimmer.PIR_Sw = false;
                    }

#endif
#endif
                }
            }
#else
            _PIR.Available = true;
#endif
            if (_PIR.Detect == false) {
                _PIR.Detect = true;
                if (_PIR.OK == false) {
                    setLED(1, 1);
                }
            }
        } else {
            if (_PIR.Detect == true) {
                _PIR.Detect = false;
                _PIR.Available = false;


                //                _PIR.Status = false;
                //                _PIR.CloseTimeSeconds = 0;
                //                _PIR.CloseTimeMinutes = 0;
                //                //                setMain_Exception(error);
                //                //auto gain restore
                //                _PIR.Time = 0;
                //                _PIR.RangeTime1 = 0;
                //                _PIR.RangeValue = RangeMinimum;
                //                _PIR.RangeCount = 0;
                //                //PIR
                //
                //                if (_PIR.OK == true) {
                //                    _PIR.Count = 0;
                //                }

            }
        }

        if (_PIR.ADtoGO == false) {
            _PIR.Time++;
            if (_PIR.Time == (100 / Main_Time)) {
                _PIR.Time = 0;
                _PIR.ADtoGO = true;
            }
        } else {
            if (_PIR.GO == true) {
                _PIR.GO = false;
                _PIR.ADtoGO = false;
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
                        if ((_PIR.SignalAD >= (_PIR.ReferenceVoltage - _PIR.RangeValue))
                                && (_PIR.SignalAD <= (_PIR.ReferenceVoltage + _PIR.RangeValue))) {
#if PIR_TestTime_Mode == 0
                            _PIR.Count = 0;
#else
                            if (cds == 1) {
                                _PIR.Count = 0;
                            }
#endif
                            setLED(1, 0);
                            setLED(2, 0);
                        } else {


                            _PIR.RangeCount++;
                            _PIR.Count++;

                            _PIR.TriggerValue = LightsStatus == 1 ? 3 : 3;

                            if (_PIR.Count == _PIR.TriggerValue) {
                                _PIR.Count = 0;
#if PIR_TestTime_Mode == 0
                                _PIR.CloseTimeSeconds = 0;
                                _PIR.CloseTimeMinutes = 0;
                                //                                _PIR.Status = true;

#if LightsControl_use == 1
#ifdef use_1KEY
#if PIR_Test_Mode == 0
                                if (getLights_Status(1) == 0) {
                                    setLights_Trigger(1, 1);
                                }
#endif
#endif
#endif

#if Dimmer_use == 1
#ifdef use_1KEY

                                Dimmer.PIR_Trigger = true;
                                Dimmer.PIR_Sw = true;

#endif
#endif

                                if ((_PIR.SignalAD <= (_PIR.ReferenceVoltage - _PIR.RangeValue))) {
                                    setLED(1, 1);
                                    setLED(2, 0);
                                } else {
                                    setLED(1, 0);
                                    setLED(2, 1);
                                }
#else
                                if (cds == 1) {
                                    _PIR.CloseTimeSeconds = 0;
                                    _PIR.CloseTimeMinutes = 0;
                                    //                                    _PIR.Status = true;

#if LightsControl_use == 1
#ifdef use_1KEY
#if PIR_Test_Mode == 0
                                    if (getLights_Status(1) == 0) {
                                        setLights_Trigger(1, 1);
                                    }
#endif
#endif
#endif

#if Dimmer_use == 1
#ifdef use_1KEY

                                    Dimmer.PIR_Trigger = true;
                                    Dimmer.PIR_Sw = true;

#endif
#endif
                                    if ((_PIR.SignalAD <= (_PIR.ReferenceVoltage - (_PIR.RangeValue + _PIR.Offset)))) {
                                        setLED(1, 1);
                                        setLED(2, 0);
                                    } else {
                                        setLED(1, 0);
                                        setLED(2, 1);
                                    }
                                }
#endif
                            }
                        }
                    }
                }
            }
        }
        if (_PIR.OK == false) {
            _PIR.Count++;
            if (_PIR.Count == (30000 / Main_Time)) {
                _PIR.Count = 0;
                _PIR.OK = true;
                setLED(1, 0);
                if (cds == 0) {
#if LightsControl_use == 1
#ifdef use_1KEY
                    if (getLights_Status(1) == 1) {
                        setLights_Trigger(1, 0);
                    }
#endif
#endif
#if Dimmer_use == 1
#ifdef use_1KEY
                    if (getDimmerLights_Status(1) == 1) {
                        Dimmer.PIR_Trigger = true;
                        Dimmer.PIR_Sw = false;
                    }

#endif
#endif
                }
            }
        } else {
            if (LightsStatus == 1) {
                _PIR.CloseTimeSeconds++;
                if (_PIR.CloseTimeSeconds == (1000 / Main_Time)) {
                    _PIR.CloseTimeSeconds = 0;
                    _PIR.CloseTimeMinutes++;
                    if (_PIR.CloseTimeMinutes == _PIR.CloseTimeValue) {
                        _PIR.CloseTimeMinutes = 0;
                        //                    _PIR.Status = false;

#if LightsControl_use == 1
#ifdef use_1KEY
#if PIR_Test_Mode == 0
                        if (getLights_Status(1) == 1) {
                            setLights_Trigger(1, 0);
                        }
#endif
#endif
#endif
#if Dimmer_use == 1
#ifdef use_1KEY
                        if (getDimmerLights_Status(1) == 1) {
                            Dimmer.PIR_Trigger = true;
                            Dimmer.PIR_Sw = false;
                        }
#endif
#endif
                    }
                }
            }
        }
    } else {
        if (myMain.PowerON == true) {
            _PIR.Enable = true;
            setLED(1, 1);

#if LightsControl_use == 1
#ifdef use_1KEY
            if (getLights_Status(1) == 0) {
                setLights_Trigger(1, 1);
            }
#endif
#endif
#if Dimmer_use == 1
#ifdef use_1KEY

            Dimmer.PIR_Trigger = true;
            Dimmer.PIR_Sw = true;

#endif
#endif
        }
    }
}
//******************************************************************************

void getPIR_AD(char channel1, char channel2) {
    char i = 0, j = 0;

    if (_PIR.ADtoGO == true && _PIR.GO == false) {
        _PIR.GO = true;
        _PIR.ADRES = getAD(channel1, ADCON1_VDD);
        _PIR.VRAD = _PIR.ADRES / 25;
        _PIR.VRAD1 = _PIR.ADRES;
        _PIR.ADRES = getAD(channel2, ADCON1_VDD);
        _PIR.SignalAD = _PIR.ADRES;

        if (_PIR.VRAD < 1) {
            _PIR.CloseTimeValue = 5;
        } else if (_PIR.VRAD < 3) {
            _PIR.CloseTimeValue = 60;
        } else if (_PIR.VRAD < 5) {
            _PIR.CloseTimeValue = 300;
        } else if (_PIR.VRAD < 7) {
            _PIR.CloseTimeValue = 600;
        } else if (_PIR.VRAD < 9) {
            _PIR.CloseTimeValue = 900;
        } else {
            _PIR.CloseTimeValue = 1200;
        }

#if PIR_TestTime_Mode == 1
#if UART_use == 1
        UART.Data[0] = _PIR.VRAD1;
        UART.Data[1] = _PIR.VRAD;
#endif
#endif
#if Hunder_Average == 1
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
#else
        _PIR.TenAverage[_PIR.TenCount] = _PIR.SignalAD;
        for (i = 0; i < 10; i++) {
            _PIR.TenAverageValue += _PIR.TenAverage[i];
        }
        _PIR.ReferenceVoltage = (_PIR.TenAverageValue / 10);
        _PIR.TenAverageValue = 0;

        if (_PIR.TenCount < 10) {
            _PIR.TenCount++;
        } else {
            _PIR.TenCount = 0;
        }
#endif
    }
}
//******************************************************************************

char getPIR_OK() {
    char ok = _PIR.OK == true ? 1 : 0;
    return ok;
}
#endif