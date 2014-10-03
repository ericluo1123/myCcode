

// Includes
#include "Select_File.h"

#if OverTemperature_use == 1

/*	void TempPointSelect(char temp)
	{
		#ifdef SYSC1
			Temp=&Temp1;
		#endif
	}*/
	//*********************************************************
	void Temp_Initialization()
	{
		#ifdef SYSC1
			setTemp_Initialization();
		#endif
	}
	//*********************************************************
	void setTemp_Enable(char command)
	{
		Temp->Enable=command;
	}
	char getTemp_Safe()
	{
		return Temp->Safe;
	} 
	char getTemp_ERROR()
	{
		return Temp->ERROR;
	} 
	//*********************************************************
	void getTemp_AD(char channel)
	{
		if(Temp->ADtoGO)
		{
			Temp->ADRES=getAD(channel,ADCON1_VDD);
			if(Temp->ADH[0] < Temp->ADRES)
			{
				Temp->ADH[0]=Temp->ADRES;
			}
			else if(Temp->ADH[1] < Temp->ADRES)
			{
				Temp->ADH[1]=Temp->ADRES;
			}
		}
	}
	//*********************************************************
	void setTemp_Initialization()
	{
		Temp=&Temp1;
		Temp->Safe=1;
	}
	//*********************************************************
	void Temp_Main()
	{
		#ifdef SYSC1
			setTemp_Main();		
		#endif	
	}
	//*********************************************************
	void setTemp_Main()
	{
		if(Temp->Enable)
		{
			if(Temp->ADtoGO == 0)
			{
				Temp->Time++;
				if(Temp->Time >= 500)//*10ms
				{
					if(getLoad_Safe() && getPF_Safe())
					{
						Temp->Time=0;
						Temp->ADtoGO=1;
						Temp->Safe=0;
					}
					else
					{
						Temp->Time=1000;//*5
					}
				}
			}
			else
			{
				Temp->Time++;
				if(Temp->Time >= 4)//*10ms
				{
					Temp->Time=0;
					Temp->ADtoGO=0;
					Temp->AD=Temp->ADH[1];
					if(Temp->ERROR)
					{
						if(Temp->AD >= TempSafeValue)
						{
							Temp->Count++;
							if(Temp->Count >= TempCountValue)
							{
								Temp->Count=0;
								setOverTemp_Exceptions(0);
							}
						}
						else
						{
							Temp->Count=0;
						}
					}
					else
					{
						if(Temp->AD <= TempDangerValue)
						{
							Temp->Count++;
							if(Temp->Count >= TempCountValue)
							{
								Temp->Count=0;
								setOverTemp_Exceptions(1);
							}
						}
						else
						{
							Temp->Count=0;
						}
					}
					if(Temp->ERROR == 0)
					{
						Temp->Safe=1;
					}
					setProductData(24,Temp->AD >> 8);
					setProductData(25,Temp->AD);
					Temp->ADH[0]=0;
					Temp->ADH[1]=0;
				}
			}
		}
	}
	//*********************************************************
	void setOverTemp_Exceptions(char command)
	{
		Temp->ERROR=command;
		Temp->Safe=(~command) & 0x01;
		if(command)
		{
			DimmerLights_Exceptions(1);
			#if Switch_Class == 1 && Dimmer_use == 1
				setLED(2,1);
			#endif
		}
		else
		{
			setBuz(2,BuzzerOnOffTime);
		}
		//Lights_ERROR();

		setLED(99,command+10);

		setSw_Enable((~command) & 0x01);
		#ifdef RadioFrequency1
			setRF_Enable(1,(~command) & 0x01);
		#endif
		
	}
#endif