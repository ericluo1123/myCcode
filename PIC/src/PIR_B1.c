
// Includes
#include "Select_File.h"

#if PIR_use == 1
 
/*	void selectPIRPoint(char pir)
	{	
	}
*/
	void PIR_Initialization()
	{	
		_PIR.Enable=1;
		_PIR.RangeValue=RangeMinimum;
		_PIR.CloseTimeValue=150;
		setLED(1,1);
	}
	void PIR_Main()
	{	
	}
	void getPIR_AD(char pir ,char channel1,char charchannel2)
	{	
	}


#endif