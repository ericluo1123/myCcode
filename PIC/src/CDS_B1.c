
// Includes
#include "Select_File.h"

#if CDS_use == 1

/*	void setCDSPoint(char cds)
	{
		#ifdef CDS_1
			if(cds == 1)
			{
				CDS=&_CDS1;
			}
		#endif
	}
*/
	void CDS_Initialization()
	{
		CDS=&_CDS1;
		CDS->Enable=1;
		setLED(1,1);
		setLED(2,0);
	}
	void CDS_Main()
	{
		//setCDSPoint(cds);
		if(CDS->Enable)
		{
			if(!CDS->GO)
			{
				if(!CDS->ADtoGO)
				{
					CDS->Time++;
					if(CDS->Time >= 100)//*10ms
					{
						CDS->Time=0;
						CDS->ADtoGO=1;
					}
				}
			}
			else
			{
				CDS->GO=0;
				if(CDS->High)
				{
					if(CDS->SignalAD >= CDS->VRAD)
					{
						CDS->High=0;
						ErrLED=0;
						setLights_Trigger(1,1);
						setLights_Switch(1,1);
					}
				}
				else
				{
					if(CDS->SignalAD <= (CDS->VRAD-100))
					{
						CDS->High=1;
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
		if(CDS->ADtoGO)
		{
			CDS->ADtoGO=0;
			CDS->GO=1;
			CDS->ADRES=getAD(channel1,ADCON1_VDD);
			CDS->VRAD=CDS->ADRES;
			CDS->ADRES=getAD(channel2,ADCON1_VDD);
			CDS->SignalAD=CDS->ADRES;
		}
	}


#endif