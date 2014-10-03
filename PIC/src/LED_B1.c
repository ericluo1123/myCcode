
// Includes
#include "Select_File.h"

#if LED_use == 1

	void LedPointSelect(char led)
	{
		#ifdef LED1
			if(led == 1)
			{
				LED=&VarLED1;
			}
		#endif
		#ifdef LED2
			else if(led == 2)
			{
				LED=&VarLED2;
			}
		#endif
		#ifdef LED3
			else if(led == 3)
			{
				LED=&VarLED3;
			}
		#endif	
		#ifdef ErrLED
			else if(led == 99)
			{
				LED=&VarErrLED;
			}
		#endif
	}
	//*********************************************************
	void LED_Initialization()
	{
		#ifdef LED1
			setLED_Initialization(1);
		#endif	
		#ifdef LED2
			setLED_Initialization(2);
		#endif	
		#ifdef LED3
			setLED_Initialization(3);
		#endif	
		#ifdef ErrLED
			setLED_Initialization(99);
		#endif	
	}
	//*********************************************************	
	void LED_Main()
	{
		#ifdef LED1
			setLED_Main(1);
		#endif
		#ifdef LED2
			setLED_Main(2);
		#endif
		#ifdef LED3
			setLED_Main(3);
		#endif
		#ifdef ErrLED
			setLED_Main(99);
		#endif
	}
	//*********************************************************
	void setLED_Initialization(char led)
	{
		LedPointSelect(led);
		LED->Enable=1;
		setLED(led,0);
	}
	//*********************************************************
	void setLED(char led,char command)
	{
		LedPointSelect(led);
		if(command == 0)
		{
			#ifdef LED1
				if(led == 1)
				{
					#if LED1_ON == 1
						LED1=0;
					#else
						LED1=1;
					#endif
				}
			#endif
			#ifdef LED2
				else if(led == 2)
				{
					#if LED2_ON == 1
						LED2=0;
					#else
						LED2=1;
					#endif
				}
			#endif
			#ifdef LED3
				else if(led == 3)
				{
					#if LED3_ON == 1	
						LED3=0;
					#else
						LED3=1;
					#endif
				}
			#endif
			#ifdef ErrLED
				else if(led == 99)		
				{
					#if ErrLED_ON == 1
						ErrLED=0;
					#else
						ErrLED=1;
					#endif
				}
			#endif
		}
		else if(command == 1)
		{
			#ifdef LED1
				if(led == 1)
				{
					#if LED1_ON == 1
						LED1=1;
					#else
						LED1=0;
					#endif
				}
			#endif
			#ifdef LED2
				else if(led == 2)
				{
					#if LED2_ON == 1
						LED2=1;
					#else
						LED2=0;
					#endif
				}
			#endif
			#ifdef LED3
				else if(led == 3)
				{
					#if LED3_ON == 1	
						LED3=1;
					#else
						LED3=0;
					#endif
				}
			#endif
			#ifdef ErrLED
				else if(led == 99)		
				{
					#if ErrLED_ON == 1
						ErrLED=1;
					#else
						ErrLED=0;
					#endif
				}
			#endif
		}
		else if(command == 10)
		{
			LED->GO=0;
			LED->Time=0;
			#ifdef LED1
				if(led == 1)
				{
					#if LED1_ON == 1
						LED1=0;
					#else
						LED1=1;
					#endif
				}
			#endif
			#ifdef LED2
				else if(led == 2)
				{
					#if LED2_ON == 1
						LED2=0;
					#else
						LED2=1;
					#endif
				}
			#endif
			#ifdef LED3
				else if(led == 3)
				{
					#if LED3_ON == 1	
						LED3=0;
					#else
						LED3=1;
					#endif
				}
			#endif
			#ifdef ErrLED
				else if(led == 99)		
				{
					#if ErrLED_ON == 1
						ErrLED=0;
					#else
						ErrLED=1;
					#endif
				}
			#endif
		}
		else if(command == 11)
		{
			LED->GO=1;
		}
	}
	//*********************************************************
	void setLED_Main(char led)
	{
		LedPointSelect(led);
		if(LED->GO)
		{
			LED->Time++;
			if(LED->Time >= LEDTime/10)
			{
				LED->Time=0;
				#ifdef LED1
					if(led == 1)
					{
						LED1=~LED1;	
					}
				#endif
				#ifdef LED2
					else if(led == 2)
					{
						LED2=~LED2;
					}
				#endif
				#ifdef LED3
					else if(led == 3)
					{
						LED3=~LED3;
					}
				#endif
				#ifdef ErrLED
					else if(led == 99)
					{
						ErrLED=~ErrLED;
					}
				#endif
			}
		}
	}
	//*********************************************************	
	

//end file
#endif