
#ifndef _Dimmer_H_
#define _Dimmer_H_
/**
 * Dimmer header
 */
	#if Dimmer_use == 1

		//private
		struct DimmerLights
		{
                    struct{
                        unsigned GO:1;
			unsigned Signal:1;
			unsigned AdjRF:1;
			unsigned AdjFlag:1;			//adj control
			unsigned AdjStatus:1;			//adj status
			unsigned Status:1;			//lights status
			unsigned StatusFlag:1;			//triac control
			unsigned OverLoad:1;
                    };

			unsigned char DimmingTime;		
			unsigned char DimmingTimeValue;
			unsigned char Count;
			unsigned char DimmingValue;
			unsigned char MaxmumValue;
			unsigned char MinimumValue;
	
			unsigned char TriacTime;
                        struct{
                            unsigned Flag:1;
                            unsigned Switch:1;
                            unsigned Trigger:1;
                            unsigned AdjGo:1;
                            unsigned TriggerAdj:1;
                            unsigned Triac:1;
                            unsigned MosfetOpen:1;
                            unsigned MosfetClose:1;
                        };

                        struct{
                            unsigned DetectOpen:1;
                            unsigned DetectClose:1;
                            unsigned Clear:1;
                            unsigned MosfetSignal:1;
                            unsigned MosfetOK:1;
                            unsigned TriacFlag:1;
                            unsigned empty:2;
                        };
                        unsigned char TriacCount;
                        unsigned char DetectCount;
			unsigned char MosfetSignalCount;
                        unsigned char TuneValue;
                        unsigned char MosfetOK_Count;

			
		};
		struct DimmerLights *DimmerLights;
		struct DimmerLights *DimmerLightsIntr;
                struct DimmerLights *DimmerLightsIntrIOC;

		#if Switch_Class == 1
			#define ID_1KEY_1 RB4=1
			#define ID_1KEY_0 RB4=0
			#define setLED2(command) LED2=!command
		#else
			#define ID_1KEY_1 ;
			#define ID_1KEY_0 ;
			#define setLED2 ;
		#endif


		#ifdef use_1KEY
			struct DimmerLights *DimmerLights11;
			struct DimmerLights DimmerLights1;	
		#endif

		#ifdef use_2KEY
			struct DimmerLights *DimmerLights22;
			struct DimmerLights DimmerLights2;
		#endif

		#ifdef use_3KEY
			struct DimmerLights *DimmerLights33;
			struct DimmerLights DimmerLights3;
		#endif



		#if Self_Test == 1
			void DimmerLightsOpenShow();
		#else
			#define DimmerLightsOpenShow() ;
		#endif

        
		//public
                inline void DimmerIntrIOCPointSelect(char lights);
                inline void setDimmerLights_IntrIOC_GO(char lights);

                inline void setDimmerLights_IntrControl(char lights);
                inline void DimmerIntrPointSelect(char);


		void DimmerLightsPointSelect(char);
		void DimmerLights_Initialization();
		void DimmerLights_Main();
		void DimmerLights_Exceptions(char);
		void DimmerLights_Close();

		void setDimmerLights_Initialization(char);
		void setDimmerLights_GO(char,char);
		void setDimmerLights_Main(char);
		void setDimmerLights_ERROR(char);
		void setDimmerLights_TriggerERROR(char,char); 
		void setDimmerLights(char,char);
		void setDimmerLights_Adj(char,char);
		void setDimmerLights_AdjRF(char);
		char getPercentValue(char);
		char setPercentValue(char);

		void setDimmerLights_MaxmumValue(char,char); 
		void setDimmerLights_Trigger(char,char); 
		void setDimmerLights_Switch(char,char); 
		void setDimmerLights_AdjGo(char,char); 
		void setDimmerLights_TriggerAdj(char,char);
		char getDimmerLights_StatusFlag();
		char getDimmerLights_Trigger();

		void setDimmerLights_Clear(char,char);
                inline void setDimmerLights_IntrControl(char lights);
	//	char getDimmerLights_Clear(char);
	/*	void setDimmerLights_Close(char,char);
		char getDimmerLights_Close(char);
	*/	

		//Global extern variable declaration
		struct Dimmer
		{
		//	unsigned LoadERROR:1;
		//	unsigned TempERROR:1;
		//	unsigned PFERROR:1;
                    struct{
                      	unsigned Detect:1;
                        unsigned empty:7;
                    };

			unsigned char Load;
			unsigned char Correction;
		};
		struct Dimmer *Dimmer;

		#ifdef DimmerReference1
			struct Dimmer Dimmer1;	
		#endif
	
		inline void Dimmer_Initialization();
//		void DimmerPointSelect(char);
/*
		void setDimmer_TempERROR(char,char); 	
		void setDimmer_LoadERROR(char,char); 
		void setDimmer_PFERROR(char,char);

		char getDimmer_TempERROR(char);
		char getDimmer_LoadERROR(char);
		char getDimmer_PFERROR(char);
*/
	//	void setDimmer_Detect(char,char);
	//	char getDimmer_Detect(char);

	//*********************************************************
//		#ifdef Triac1
//			#define setDimmerLights_IntrControl(lights)\
//				if(DimmerLights11->GO)\
//				{\
//					DimmerLights11->Count++;\
//					if(DimmerLights11->Count >= (DimmerLights11->DimmingValue-Dimmer->Correction))\
//					{\
//						DimmerLights11->Count=0;\
//						DimmerLights11->GO=0;\
//						DimmerLights11->Flag=1;\
//						if(DimmerLights11->StatusFlag)\
//						{\
//							Triac1=1;\
//							ID_1KEY_1;\
//						}\
//					}\
//				}\
//				else\
//				{\
//					if(DimmerLights11->Flag)\
//					{\
//						DimmerLights11->Flag=0;\
//						if(DimmerLights11->Signal)\
//						{\
//							DimmerLights11->DimmingTime++;\
//							if(DimmerLights11->DimmingTime >= DimmerLights11->DimmingTimeValue)\
//							{\
//								DimmerLights11->DimmingTime=0;\
//								if(DimmerLights11->AdjFlag)\
//								{\
//									if(DimmerLights11->AdjStatus == 0)\
//									{\
//										if(DimmerLights11->DimmingValue > Dimmer_Maxum)\
//										{\
//											DimmerLights11->DimmingValue--;\
//										}\
//										else\
//										{\
//											DimmerLights11->AdjStatus=1;\
//										}\
//									}\
//									else\
//									{\
//										if(DimmerLights11->DimmingValue < Dimmer_Minimum)\
//										{\
//											DimmerLights11->DimmingValue++;\
//										}\
//										else\
//										{\
//											DimmerLights11->AdjStatus=0;\
//										}\
//									}\
//								}\
//								else if(DimmerLights11->AdjRF)\
//								{\
//									if(DimmerLights11->DimmingValue > DimmerLights11->MaxmumValue)\
//									{\
//										DimmerLights11->DimmingValue--;\
//									}\
//									else if(DimmerLights11->DimmingValue < DimmerLights11->MaxmumValue)\
//									{\
//										DimmerLights11->DimmingValue++;\
//									}\
//									if(DimmerLights11->DimmingValue == DimmerLights11->MaxmumValue)\
//									{\
//										DimmerLights11->AdjRF=0;\
//										DimmerLights11->Signal=0;\
//									}\
//								}\
//								else\
//								{\
//									if(DimmerLights11->Status)\
//									{\
//										DimmerLights11->DimmingValue--;\
//										if(DimmerLights11->DimmingValue <= DimmerLights11->MaxmumValue)\
//										{\
//											DimmerLights11->Signal=0;\
//										}\
//									}\
//									else\
//									{\
//										DimmerLights11->DimmingValue++;\
//										if(DimmerLights11->DimmingValue >= DimmerLights11->MinimumValue)\
//										{\
//											DimmerLights11->Signal=0;\
//											DimmerLights11->StatusFlag=0;\
//											DimmerLights11->Clear=1;\
//											Dimmer->Detect=1;\
//											LED1=0;\
//											setLED2(1);\
//											setLoad_StatusOff(lights,1);\
//										}\
//									}\
//								}\
//							}\
//						}\
//					}\
//					if(Triac1)\
//					{\
//						DimmerLights11->TriacTime++;\
//						if(DimmerLights11->TriacTime >= (120-DimmerLights11->DimmingValue))\
//						{\
//							DimmerLights11->TriacTime=0;\
//							Triac1=0;\
//							ID_1KEY_0;\
//						}\
//					}\
//				}\
//				;
//
//		#endif
//		//*********************************************************
//		#ifdef Triac2
//
//			#define setDimmerLights22_Control(lights)\
//				if(DimmerLights22->GO)\
//				{\
//					DimmerLights22->Count++;\
//					if(DimmerLights22->Count >= (DimmerLights22->DimmingValue-Dimmer->Correction))\
//					{\
//						DimmerLights22->Count=0;\
//						DimmerLights22->GO=0;\
//						DimmerLights22->Flag=1;\
//						if(DimmerLights22->StatusFlag)\
//						{\
//							Triac2=1;\
//						}\
//					}\
//				}\
//				else\
//				{\
//					if(DimmerLights22->Flag)\
//					{\
//						DimmerLights22->Flag=0;\
//						if(DimmerLights22->Signal)\
//						{\
//							DimmerLights22->DimmingTime++;\
//							if(DimmerLights22->DimmingTime >= DimmerLights22->DimmingTimeValue)\
//							{\
//								DimmerLights22->DimmingTime=0;\
//								if(DimmerLights22->AdjFlag)\
//								{\
//									if(DimmerLights22->AdjStatus == 0)\
//									{\
//										if(DimmerLights22->DimmingValue > Dimmer_Maxum)\
//										{\
//											DimmerLights22->DimmingValue--;\
//										}\
//										else\
//										{\
//											DimmerLights22->AdjStatus=1;\
//										}\
//									}\
//									else\
//									{\
//										if(DimmerLights22->DimmingValue < Dimmer_Minimum)\
//										{\
//											DimmerLights22->DimmingValue++;\
//										}\
//										else\
//										{\
//											DimmerLights22->AdjStatus=0;\
//										}\
//									}\
//								}\
//								else if(DimmerLights22->AdjRF)\
//								{\
//									if(DimmerLights22->DimmingValue > DimmerLights22->MaxmumValue)\
//									{\
//										DimmerLights22->DimmingValue--;\
//									}\
//									else if(DimmerLights22->DimmingValue < DimmerLights22->MaxmumValue)\
//									{\
//										DimmerLights22->DimmingValue++;\
//									}\
//									if(DimmerLights22->DimmingValue == DimmerLights22->MaxmumValue)\
//									{\
//										DimmerLights22->AdjRF=0;\
//										DimmerLights22->Signal=0;\
//									}\
//								}\
//								else\
//								{\
//									if(DimmerLights22->Status)\
//									{\
//										DimmerLights22->DimmingValue--;\
//										if(DimmerLights22->DimmingValue <= DimmerLights22->MaxmumValue)\
//										{\
//											DimmerLights22->Signal=0;\
//										}\
//									}\
//									else\
//									{\
//										DimmerLights22->DimmingValue++;\
//										if(DimmerLights22->DimmingValue >= DimmerLights22->MinimumValue)\
//										{\
//											DimmerLights22->Signal=0;\
//											DimmerLights22->StatusFlag=0;\
//											DimmerLights22->Clear=1;\
//											Dimmer->Detect=1;\
//											LED2=0;\
//											setLoad_StatusOff(lights,1);\
//										}\
//									}\
//								}\
//							}\
//						}\
//					}\
//					if(Triac2)\
//					{\
//						DimmerLights22->TriacTime++;\
//						if(DimmerLights22->TriacTime >= (120-DimmerLights22->DimmingValue))\
//						{\
//							DimmerLights22->TriacTime=0;\
//							Triac2=0;\
//						}\
//					}\
//				}\
//				;
//
//
//		#endif
//		//*********************************************************
//		#ifdef Triac3
//
//			#define setDimmerLights33_Control(lights)\
//				if(DimmerLights33->GO)\
//				{\
//					DimmerLights33->Count++;\
//					if(DimmerLights33->Count >= (DimmerLights33->DimmingValue-Dimmer->Correction))\
//					{\
//						DimmerLights33->Count=0;\
//						DimmerLights33->GO=0;\
//						DimmerLights33->Flag=1;\
//						if(DimmerLights33->StatusFlag)\
//						{\
//							Triac3=1;\
//						}\
//					}\
//				}\
//				else\
//				{\
//					if(DimmerLights33->Flag)\
//					{\
//						DimmerLights33->Flag=0;\
//						if(DimmerLights33->Signal)\
//						{\
//							DimmerLights33->DimmingTime++;\
//							if(DimmerLights33->DimmingTime >= DimmerLights33->DimmingTimeValue)\
//							{\
//								DimmerLights33->DimmingTime=0;\
//								if(DimmerLights33->AdjFlag)\
//								{\
//									if(DimmerLights33->AdjStatus == 0)\
//									{\
//										if(DimmerLights33->DimmingValue > Dimmer_Maxum)\
//										{\
//											DimmerLights33->DimmingValue--;\
//										}\
//										else\
//										{\
//											DimmerLights33->AdjStatus=1;\
//										}\
//									}\
//									else\
//									{\
//										if(DimmerLights33->DimmingValue < Dimmer_Minimum)\
//										{\
//											DimmerLights33->DimmingValue++;\
//										}\
//										else\
//										{\
//											DimmerLights33->AdjStatus=0;\
//										}\
//									}\
//								}\
//								else if(DimmerLights33->AdjRF)\
//								{\
//									if(DimmerLights33->DimmingValue > DimmerLights33->MaxmumValue)\
//									{\
//										DimmerLights33->DimmingValue--;\
//									}\
//									else if(DimmerLights33->DimmingValue < DimmerLights33->MaxmumValue)\
//									{\
//										DimmerLights33->DimmingValue++;\
//									}\
//									if(DimmerLights33->DimmingValue == DimmerLights33->MaxmumValue)\
//									{\
//										DimmerLights33->AdjRF=0;\
//										DimmerLights33->Signal=0;\
//									}\
//								}\
//								else\
//								{\
//									if(DimmerLights33->Status)\
//									{\
//										DimmerLights33->DimmingValue--;\
//										if(DimmerLights33->DimmingValue <= DimmerLights33->MaxmumValue)\
//										{\
//											DimmerLights33->Signal=0;\
//										}\
//									}\
//									else\
//									{\
//										DimmerLights33->DimmingValue++;\
//										if(DimmerLights33->DimmingValue >= DimmerLights33->MinimumValue)\
//										{\
//											DimmerLights33->Signal=0;\
//											DimmerLights33->StatusFlag=0;\
//											DimmerLights33->Clear=1;\
//											Dimmer->Detect=1;\
//											LED3=0;\
//											setLoad_StatusOff(lights,1);\
//										}\
//									}\
//								}\
//							}\
//						}\
//					}\
//					if(Triac3)\
//					{\
//						DimmerLights33->TriacTime++;\
//						if(DimmerLights33->TriacTime >= (120-DimmerLights33->DimmingValue))\
//						{\
//							DimmerLights33->TriacTime=0;\
//							Triac3=0;\
//						}\
//					}\
//				}\
//				;
//		#endif
		//*********************************************************
		#ifdef Mosfet1
			#if Dimmer_Full_Wave == 1
				#define setDimmerLights_IntrControl(lights)\
					if(DimmerLights11->GO)\//reclock
					{\
						DimmerLights11->Count++;\
						if(DimmerLights11->Count >= DimmerLights11->DimmingValue)\
						{\
							DimmerLights11->Count=0;\
							DimmerLights11->GO=0;\
							DimmerLights11->Flag=1;\
							if(DimmerLights11->StatusFlag)\
							{\
								Mosfet1=0;\
								if(DimmerLights11->MosfetClose)\
								{\
									DimmerLights11->MosfetClose=0;\
									DimmerLights11->StatusFlag=0;\
									DimmerLights11->Clear=1;\
									LED1=0;\
									setLED2(1);\
									ID_1KEY_0;\
									Dimmer->Detect=1;\
									setLoad_StatusOff(1,lights,1);\
								}\
							}\
						}\
					}\
					else\
					{\
						if(DimmerLights11->MosfetOpen)\
						{\
							DimmerLights11->Count++;\
							if(DimmerLights11->Count >= MosfetOpenToCloseValue)\
							{\
								DimmerLights11->Count=0;\
								DimmerLights11->MosfetOpen=0;\
							}\
						}\
						if(DimmerLights11->Flag)\
						{\
							DimmerLights11->Flag=0;\
							if(DimmerLights11->Signal)\
							{\
								DimmerLights11->DimmingTime++;\
								if(DimmerLights11->DimmingTime >= DimmerLights11->DimmingTimeValue)\
								{\
									DimmerLights11->DimmingTime=0;\
									if(DimmerLights11->AdjFlag)\
									{\
										if(!DimmerLights11->AdjStatus)\
										{\
											if(DimmerLights11->DimmingValue < Dimmer_Maxum)\
											{\
												DimmerLights11->DimmingValue++;\
											}\
											else\
											{\
												DimmerLights11->AdjStatus=1;\
											}\
										}\
										else\
										{\
											if(DimmerLights11->DimmingValue > Dimmer_Minimum)\
											{\
												DimmerLights11->DimmingValue--;\
											}\
											else\
											{\
												DimmerLights11->AdjStatus=0;\
											}\
										}\
									}\
									else if(DimmerLights11->AdjRF)\
									{\
										if(DimmerLights11->DimmingValue < DimmerLights11->MaxmumValue)\
										{\
											DimmerLights11->DimmingValue++;\
										}\
										else if(DimmerLights11->DimmingValue > DimmerLights11->MaxmumValue)\
										{\
											DimmerLights11->DimmingValue--;\
										}\
										if(DimmerLights11->DimmingValue == DimmerLights11->MaxmumValue)\
										{\
											DimmerLights11->AdjRF=0;\
											DimmerLights11->Signal=0;\
										}\
									}\
									else\
									{\
										DimmerLights11->Signal=0;\
									}\
								}\
							}\
						}\
					}\
					;
			#endif

//                                        if(DimmerLights11->MosfetSignal)\
//					{\
//						DimmerLights11->MosfetSignalCount++;\
//						if(DimmerLights11->MosfetSignalCount == DimmerLights11->TuneValue )\
//						{\
//							DimmerLights11->MosfetSignalCount=0;\
//							DimmerLights11->MosfetSignal=0;\
//                                                    if (!DimmerLights11->GO && !DimmerLights11->MosfetOpen) {
//                                                        DimmerLights11->GO = 1;
//                                                        if (DimmerLights11->StatusFlag) {
//                                                            Mosfet1 = 1;
//                                                            ID_1KEY_1;
//                                                        }
//                                                    }
//						}\
//					}\


            #if Dimmer_Half_Wave == 1
                
//				#define setDimmerLights11_Control(lights)\
//					if(DimmerLights11->GO)\
//					{\
//						DimmerLights11->Count++;\
//						if(DimmerLights11->Count >= (DimmerLights11->DimmingValue-Dimmer->Correction))\
//						{\
//							DimmerLights11->Count=0;\
//							DimmerLights11->GO=0;\
//							DimmerLights11->Flag=1;\
//							if(DimmerLights11->StatusFlag)\
//							{\
//								Mosfet1=0;\
//								ID_1KEY_0;\
//								if(DimmerLights11->MosfetClose)\
//								{\
//									DimmerLights11->MosfetClose=0;\
//									DimmerLights11->StatusFlag=0;\
//									DimmerLights11->Clear=1;\
//									LED1=0;\
//									setLED2(1);\
//									Dimmer->Detect=1;\
//									setLoad_StatusOff(lights,1);\
//								}\
//							}\
//						}\
//					}\
//					else\
//					{\
//						if(DimmerLights11->MosfetOpen)\
//						{\
//							DimmerLights11->Count++;\
//							if(DimmerLights11->Count >= MosfetOpenToCloseValue)\
//							{\
//								DimmerLights11->Count=0;\
//								DimmerLights11->MosfetOpen=0;\
//							}\
//						}\
//						if(DimmerLights11->Flag)\
//						{\
//							DimmerLights11->Flag=0;\
//							if(DimmerLights11->Signal)\
//							{\
//								DimmerLights11->DimmingTime++;\
//								if(DimmerLights11->DimmingTime >= DimmerLights11->DimmingTimeValue)\
//								{\
//									DimmerLights11->DimmingTime=0;\
//									if(DimmerLights11->AdjFlag)\
//									{\
//										if(DimmerLights11->AdjStatus == 0)\
//										{\
//											if(DimmerLights11->DimmingValue < Dimmer_Maxum)\
//											{\
//												DimmerLights11->DimmingValue++;\
//											}\
//											else\
//											{\
//												DimmerLights11->AdjStatus=1;\
//											}\
//										}\
//										else\
//										{\
//											if(DimmerLights11->DimmingValue > Dimmer_Minimum)\
//											{\
//												DimmerLights11->DimmingValue--;\
//											}\
//											else\
//											{\
//												DimmerLights11->AdjStatus=0;\
//											}\
//										}\
//									}\
//									else if(DimmerLights11->AdjRF)\
//									{\
//										if(DimmerLights11->DimmingValue < DimmerLights11->MaxmumValue)\
//										{\
//											DimmerLights11->DimmingValue++;\
//										}\
//										else if(DimmerLights11->DimmingValue > DimmerLights11->MaxmumValue)\
//										{\
//											DimmerLights11->DimmingValue--;\
//										}\
//										if(DimmerLights11->DimmingValue == DimmerLights11->MaxmumValue)\
//										{\
//											DimmerLights11->AdjRF=0;\
//											DimmerLights11->Signal=0;\
//										}\
//									}\
//									else\
//									{\
//										DimmerLights11->Signal=0;\
//									}\
//								}\
//							}\
//						}\
//					}\
//					;
			#endif
		#endif

		#ifdef Mosfet2

			#if Dimmer_Full_Wave == 1
				#define setDimmerLights22_Control(lights)\
					if(DimmerLights22->GO)\//reclock
					{\
						DimmerLights22->Count++;\
						if(DimmerLights22->Count >= DimmerLights22->DimmingValue)\
						{\
							DimmerLights22->Count=0;\
							DimmerLights22->GO=0;\
							DimmerLights22->Flag=1;\
							if(DimmerLights22->StatusFlag)\
							{\
								Mosfet2=0;\
								if(DimmerLights22->MosfetClose)\
								{\
									DimmerLights22->MosfetClose=0;\
									DimmerLights22->StatusFlag=0;\
									DimmerLights22->Clear=1;\
									LED2=0;\
									Dimmer->Detect=1;\
									setLoad_StatusOff(1,lights,1);\
								}\
							}\
						}\
					}\
					else\
					{\
						if(DimmerLights22->MosfetOpen)\
						{\
							DimmerLights22->Count++;\
							if(DimmerLights22->Count >= MosfetOpenToCloseValue)\
							{\
								DimmerLights22->Count=0;\
								DimmerLights22->MosfetOpen=0;\
							}\
						}\
						if(DimmerLights22->Flag)\
						{\
							DimmerLights22->Flag=0;\
							if(DimmerLights22->Signal)\
							{\
								DimmerLights22->DimmingTime++;\
								if(DimmerLights22->DimmingTime >= DimmerLights22->DimmingTimeValue)\
								{\
									DimmerLights22->DimmingTime=0;\
									if(DimmerLights22->AdjFlag)\
									{\
										if(!DimmerLights22->AdjStatus)\
										{\
											if(DimmerLights22->DimmingValue < Dimmer_Maxum)\
											{\
												DimmerLights22->DimmingValue++;\
											}\
											else\
											{\
												DimmerLights22->AdjStatus=1;\
											}\
										}\
										else\
										{\
											if(DimmerLights22->DimmingValue > Dimmer_Minimum)\
											{\
												DimmerLights22->DimmingValue--;\
											}\
											else\
											{\
												DimmerLights22->AdjStatus=0;\
											}\
										}\
									}\
									else if(DimmerLights22->AdjRF)\
									{\
										if(DimmerLights22->DimmingValue < DimmerLights22->MaxmumValue)\
										{\
											DimmerLights22->DimmingValue++;\
										}\
										else if(DimmerLights22->DimmingValue > DimmerLights22->MaxmumValue)\
										{\
											DimmerLights22->DimmingValue--;\
										}\
										if(DimmerLights22->DimmingValue == DimmerLights22->MaxmumValue)\
										{\
											DimmerLights22->AdjRF=0;\
											DimmerLights22->Signal=0;\
										}\
									}\
									else\
 {\
										DimmerLights22->Signal = 0;                                                  \
									                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                }\
								                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        }\
							                                                                                                                                                                                                                                                                                                                                                                                                                }\
						                                                                                                                                                                                                        }\
					}\
					;
#endif

#if Dimmer_Half_Wave == 1

//                                      	if(DimmerLights22->MosfetSignal)\
//					{\
//						DimmerLights22->MosfetSignalCount++;\
//						if(DimmerLights22->MosfetSignalCount == DimmerTuneValue-10)\
//						{\
//							DimmerLights22->MosfetSignalCount=0;\
//							DimmerLights22->MosfetSignal=0;\
//							if(!DimmerLights22->GO  && !DimmerLights22->MosfetOpen)\
//							{\
//								DimmerLights22->GO=1;\
//								if(DimmerLights22->StatusFlag)\
//								{\
//									Mosfet2=1;\
//								}\
//							}\
//						}\
//					}\

#define setDimmerLights22_Control(lights)\
					if(DimmerLights22->GO)\
					{\
						DimmerLights22->Count++;\
						if(DimmerLights22->Count >= (DimmerLights22->DimmingValue-Dimmer->Correction))\
						{\
							DimmerLights22->Count=0;\
							DimmerLights22->GO=0;\
							DimmerLights22->Flag=1;\
							if(DimmerLights22->StatusFlag)\
							{\
								Mosfet2=0;\
								if(DimmerLights22->MosfetClose)\
								{\
									DimmerLights22->MosfetClose=0;\
									DimmerLights22->StatusFlag=0;\
									DimmerLights22->Clear=1;\
									LED2=0;\
									Dimmer->Detect=1;\
									setLoad_StatusOff(lights,1);\
								}\
							}\
						}\
					}\
					else\
					{\
						if(DimmerLights22->MosfetOpen)\
						{\
							DimmerLights22->Count++;\
							if(DimmerLights22->Count >= MosfetOpenToCloseValue)\
							{\
								DimmerLights22->Count=0;\
								DimmerLights22->MosfetOpen=0;\
							}\
						}\
						if(DimmerLights22->Flag)\
						{\
							DimmerLights22->Flag=0;\
							if(DimmerLights22->Signal)\
							{\
								DimmerLights22->DimmingTime++;\
								if(DimmerLights22->DimmingTime >= DimmerLights22->DimmingTimeValue)\
								{\
									DimmerLights22->DimmingTime=0;\
									if(DimmerLights22->AdjFlag)\
									{\
										if(DimmerLights22->AdjStatus == 0)\
										{\
											if(DimmerLights22->DimmingValue < Dimmer_Maxum)\
											{\
												DimmerLights22->DimmingValue++;\
											}\
											else\
											{\
												DimmerLights22->AdjStatus=1;\
											}\
										}\
										else\
										{\
											if(DimmerLights22->DimmingValue > Dimmer_Minimum)\
											{\
												DimmerLights22->DimmingValue--;\
											}\
											else\
											{\
												DimmerLights22->AdjStatus=0;\
											}\
										}\
									}\
									else if(DimmerLights22->AdjRF)\
									{\
										if(DimmerLights22->DimmingValue < DimmerLights22->MaxmumValue)\
										{\
											DimmerLights22->DimmingValue++;\
										}\
										else if(DimmerLights22->DimmingValue > DimmerLights22->MaxmumValue)\
										{\
											DimmerLights22->DimmingValue--;\
										}\
										if(DimmerLights22->DimmingValue == DimmerLights22->MaxmumValue)\
										{\
											DimmerLights22->AdjRF=0;\
											DimmerLights22->Signal=0;\
										}\
									}\
									else\
 {\
										DimmerLights22->Signal = 0;             \
									                                                                                                                                                                                                                }\
								                                                                                                                                                            }\
							                                                                                                        }\
						                                                    }\
					}\
					;
#endif


#endif


#else
#define DimmerLightsOpenShow() ;

#define DimmerLightsPointSelect(char) ;
#define DimmerLights_Initialization() ;
#define DimmerLights_Main() ;
#define DimmerLights_Exceptions(char) ;
#define DimmerLights_Close() ;

#define setDimmerLights_Initialization(char) ;
#define setDimmerLights_GO(char,char) ;
#define setDimmerLights_Main(char) ;
#define setDimmerLights_IntrControl(lights) ;
#define setDimmerLights_ERROR(char) ;
#define setDimmerLights_TriggerERROR(char,char) ; 
#define setDimmerLights(char,char) ;
#define setDimmerLights_Adj(char,char) ;
#define setDimmerLights_AdjRF(char) ;
#define getPercentValue(char) 0
#define setPercentValue(char) 0

#define setDimmerLights_MaxmumValue(char,char) ; 
#define setDimmerLights_Trigger(char,char) ; 
#define setDimmerLights_Switch(char,char) ; 
#define setDimmerLights_AdjGo(char,char) ; 
#define setDimmerLights_TriggerAdj(char,char) ;
#define getDimmerLights_StatusFlag() ;
#define getDimmerLights_Trigger() ;

#define setDimmerLights_Detect(char,char) ;
//		#define setDimmerLights_Open(char,char);
//		#define getDimmerLights_Open(char);
//		#define setDimmerLights_Close(char,char);
//		#define getDimmerLights_Close(char);	

#define Dimmer_Initialization() ;
//	#define DimmerPointSelect(char) ;
//	#define setDimmer_TempERROR(char,char) ; 	
//	#define setDimmer_LoadERROR(char,char) ; 
//	#define setDimmer_PFERROR(char,char) ;
//	#define setDimmer_Detect(char,char) ;
//	#define getDimmer_Detect(char) ;

#endif

//End file
#endif

