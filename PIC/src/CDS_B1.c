
// Includes
#include "Select_File.h"

#if CDS_use == 1

	void CDS_Initialization()
	{
		_CDS.Enable=1;
		setLED(1,1);
		setLED(2,0);
	}
	void CDS_Main()
	{
		//setCDSPoint(cds);
		if(_CDS.Enable)
		{
			if(!_CDS.GO)
			{
				if(!_CDS.ADtoGO)
				{
					_CDS.Time++;
					if(_CDS.Time >= 100)//*10ms
					{
						_CDS.Time=0;
						_CDS.ADtoGO=1;
					}
				}
			}
			else
			{
				_CDS.GO=0;
				if(_CDS.High)
				{
					if(_CDS.SignalAD >= _CDS.VRAD)
					{
						_CDS.High=0;
						ErrLED=0;
						setLights_Trigger(1,1);
						setLights_Switch(1,1);
					}
				}
				else
				{
					if(_CDS.SignalAD <= (_CDS.VRAD-100))
					{
						_CDS.High=1;
						ErrLED=1;
						setLights_Trigger(1,1);
						setLights_Switch(1,0);
					}
				}
			}
		}
	}
	void getCDS_AD(char cds,char channel1,char channel2)
	{
		char i=0,j=0;
		//setCDSPoint(cds);
		if(_CDS.ADtoGO)
		{
			_CDS.ADtoGO=0;
			_CDS.GO=1;
			_CDS.ADRES=getAD(channel1,ADCON1_VDD);
			_CDS.VRAD=_CDS.ADRES;
			_CDS.ADRES=getAD(channel2,ADCON1_VDD);
			_CDS.SignalAD=_CDS.ADRES;
		}
	}


#endif