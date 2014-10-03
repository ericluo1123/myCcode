
// Includes
#include "../1.Switch_1Key_Dimmer.X/Select_File.h"


#if PowerFault_use == 1

/*	void PowerFaultPointSelect(char pf)
	{
		#ifdef PFV1
			PF=&PF1;
		#endif
	}*/
	//*********************************************************
	void PowerFault_Initialization()
	{
		#ifdef PFV1
			setPowerFault_Initialization();
		#endif
	}
	//*********************************************************
	void PowerFault_Main()
	{
		#ifdef PFV1
			setPowerFault_Main();
		#endif
	}
	//*********************************************************
	void setPowerFault_Initialization()
	{
		PF=&PF1;
		PF->Enable=1;
		PF->Safe=1;
	}
	//*********************************************************
	void setPF_Enable(char command)
	{
		PF->Enable=command;
	}
	char getPF_Safe()
	{
		return PF->Safe;
	} 
	char getPF_ERROR()
	{
		return PF->ERROR;
	}
	//*********************************************************
	void getPowerFault_AD(char channel)
	{
		if(PF->ADtoGO)
		{
			PF->ADRES=getAD(channel,ADCON1_VDD);
			if(PF->AD < PF->ADRES)
			{
				PF->AD=PF->ADRES;
			}
		}
	}
	//*********************************************************
	void setPowerFault_Main()
	{	
		if(PF->Enable)
		{
			if(PF->ADtoGO == 0)
			{
				PF->Time++;
				if(PF->Time >= 700)//*10ms
				{
					if(getLoad_Safe() && getTemp_Safe())
					{
						PF->Time=0;
						PF->ADtoGO=1;
						PF->Safe=0;
					}
					else
					{
						PF->Time=700;
					}
				}
			}
			else
			{
				PF->Time++;
				if(PF->Time >= 2)//*10ms
				{
					PF->Time=0;
					PF->ADtoGO=0;
			
					if(PF->ERROR)		
					{
						if(PF->AD <= (300+100) && PF->AD >= (300-100))
						{
							PF->Count++;
							if(PF->Count > 1)
							{
								PF->Count=0;
								setPowerFault_Exceptions(0);
							}
						}	
						else
						{
							PF->Count=0;
						}
					}
					else
					{
						if(PF->AD >= (300+100) || PF->AD <= (310-100))
						{
							PF->Count++;
							if(PF->Count > 1)
							{
								PF->Count=0;
								setPowerFault_Exceptions(1);
							}
						}
						else
						{
							PF->Count=0;
						}	

					}
					if(PF->ERROR == 0)		
					{
						PF->Safe=1;
					}
					PF->AD=0;
				}
			}
		}
	}

	void setPowerFault_Exceptions(char command)
	{
		PF->ERROR=command;
		PF->Safe=(~command) & 0x01;
		if(command == 1)
		{
			DimmerLights_Exceptions(3);
			#if Switch_Class == 1 && Dimmer_use == 1
				setLED(2,1);
			#endif
		}
		setLED(99,command+10);

		setSw_Enable((~command) & 0x01);
		#ifdef RadioFrequency1
			setRF_Enable(1,(~command) & 0x01);
		#endif

	}
#endif