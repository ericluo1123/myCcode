
#ifndef _SegmentDisplay_A_H_
#define _SegmentDisplay_A_H_

/**
 *
 *	method:
 *		setDisplayData(data);
 *	Decrption:
 *		data =display data
 *
 *
 */

#if SegmentDisplay_use == 1

#if Polarity == 1	
#define		Zero	 	0xc0
#define		One		0xf9
#define		Two		0xa4
#define		Three		0xb0
#define		Four		0x99
#define		Five		0x92
#define		Six		0x82
#define		Seven		0xd8
#define		Eight		0x80
#define		Nine		0x90
#define		Ten		0x88
#define		Eleven		0x83
#define		Twelve		0xa7
#define		Thirteen	0xa1
#define		Fourteen	0x86
#define		Fifteen		0x8e
#define		Hyphen		0xbf				
#else		
#define		Zero		0x3f
#define		One		0x06
#define		Two		0x5b
#define		Three		0x4f
#define		Four		0x66
#define		Five		0x6d
#define		Six		0x7d
#define		Seven		0x27
#define		Eight		0x7f
#define		Nine		0x90
#define		Ten		0x88
#define		Eleven		0x83
#define		Twelve		0xa7
#define		Thirteen	0xa1
#define		Fourteen	0x86
#define		Fifteen		0x8e	
#define		Hyphen		0x40	
#endif


//Global extern vriables declaration*

struct Segment {
    unsigned char Display[17];
    unsigned char Num[4];
    unsigned Enable : 1;
    unsigned GO : 1;
    unsigned Hex : 1;
    unsigned Dec : 1;
    unsigned char ComCount;
    unsigned char DisplayCount;
    unsigned char Count;
    unsigned char Time;
};
struct Segment *Segment;
struct Segment VarSegment = {
    {Zero, One, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Eleven, Twelve, Thirteen, Fourteen, Fifteen, Hyphen}
};

void SegmentDisplay_Initial();
void setSegmentDisplayNumber(int);
void SegmentDisplay_Main();

#else
//NOP
#define SegmentDisplay_Initial() ;
#define setSegmentDisplayNumber(int) ;
#define SegmentDisplay_Main() ;

#endif




#endif