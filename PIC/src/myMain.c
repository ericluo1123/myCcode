
// Includes
#include "Select_File.h"

//main
void main()
{
	MainT_Initial();
	Mcu_Initialization();
	SegmentDisplay_Initial();
	RF_Initialization();
	CC2500_PowerOnInitial();
	while(1)
	{		

		//TMR0
		if(TMain->T1_Timerout)	//1ms
		{
			TMain->T1_Timerout = 0;
			MainT();	
			if(TMain->PowerON)
			{	
				RF_Main();
				I2C_Main();
				UART_Main();
				SegmentDisplay_Main();			
			}
		}		
	}
}

//Tmain initial
void MainT_Initial()
{
	TMain=&VarTMain;
	TMain->FirstOpen=1;
	Product=&VarProduct;
}

//T main
void MainT()
{
	char i;
	//Power
	if(!TMain->PowerON)
	{
		TMain->PowerCount++;
		if(TMain->PowerCount == 1500)
		{
			TMain->PowerCount=0;
			TMain->PowerON=1;

			#ifdef RadioFrequency1
				setRF_Enable(1,1);
			#endif
		}
	}
	else
	{
		TMain->Count1++;
		if(TMain->Count1 == 1000)	//1s
		{
			TMain->Count1=0;
			LED1=~LED1;
			#if UART_use == 1
	//			for(i=0;i<32;i++)
	//			{
	//				printf("%d,",i);
	//			}
	//	printf("\rUart Baue Rate=38400\n");
	//	printf("\rReceiver Original Data:\n\r");

			//	UART->TxGO=1;
			#endif
			//	setTxData(1);
			if(TMain->Flag == 0)
			{
			//	TMain->Flag=1;
		
			}
			#if I2C_use == 1
				#if Master_Mode == 1
				//setSegmentDisplayNumber(I2C->BufferReader[0]);
				/*	if(TMain->Test)
					{
						setSegmentDisplayNumber(I2C->BufferReader[I2C->Count]);
						I2C->Count++;
						if(I2C->Count==32)
						{
							I2C->Count=0;
						}
					}*/
				#endif
				#if Slave_Mode == 1
			/*		for(i=0;i<21;i++){
						RF_Data[i]=i+1;
					}
					Tx_Length=0;
					RSSI=22;
					CRC=23;
					I2C_SetData(1);*/
				#endif
			#endif
		}
		#if Master_Mode == 1

			TMain->Count2++;
			if(TMain->Count2 == 2000)	//1s
			{
				TMain->Count2=0;
			//	if(!TMain->Test)
			//	{
			//		I2C->MasterRxGO=1;	
			//	}

			/*	#if I2C_use == 1
					for(i=0;i<21;i++)
					{
						I2C->BufferWriter[i]=i+1;
					}
					I2C->MasterTxGO=1;
				#endif*/
			}
		
		#endif
	}
}


//End file