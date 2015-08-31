#ifndef _DEFINES_H_INCLUDED_
#define _DEFINES_H_INCLUDED_

#define NULL ((void *)0)
#define SERIAL_DEFAULT_DEVICE 1

typedef unsigned char  uint8;
typedef unsigned short uint16;
typedef unsigned long  uint32;
/**************************************************/
/**       Common                                 **/
/**************************************************/
#define DISABLE 0x00
#define ENABLE	0x01

/**************************************************/
/**       LED                                    **/
/**************************************************/

#define LED_ON	0x01
#define LED_OFF	0x00
/**************************************************/
/**       1Byte Struct                           **/
/**************************************************/

typedef union{
	
	unsigned char BYTE;
	
	struct {
		
		unsigned char B7:1;
		unsigned char B6:1;
		unsigned char B5:1;
		unsigned char B4:1;
		unsigned char B3:1;
		unsigned char B2:1;
		unsigned char B1:1;
		unsigned char B0:1;
		
	} BIT;
	
} _IOREG;

/**************************************************/
/**       I/O port regster                       **/
/**************************************************/
#define ABWCR (*(volatile _IOREG *)0xfee020)
#define P4DDR (*(volatile _IOREG *)0xfee003)
#define P4DR  (*(volatile _IOREG *)0xffffd3)
#define P4PCR (*(volatile _IOREG *)0xfee03e)

/**************************************************/
/**                  Timer                       **/
/**************************************************/

typedef union{
	
	unsigned char BYTE;
	
	struct {
		
		unsigned char RESERVE0	:1;
		unsigned char IMIE		:3; // IMFフラグによる割り込み 許可/禁止 設定
		unsigned char RESERVE1	:1;
		unsigned char IMF		:3; // GRの発生を示すステータスフラグ
		
	} BIT;
	
} _TISR;

typedef union{
	
	unsigned char BYTE;
	
	struct {
		
		unsigned char RESERVE	:1;
		unsigned char CCLR		:2;
		unsigned char CKEG		:2;
		unsigned char TPSC		:3;
		
	} BIT;
	
} _16TCR;


typedef union{
	
	unsigned char BYTE;
	
	struct {
		
		unsigned char RESERVE0	:1;
		unsigned char IOB		:3;
		unsigned char REVER1	:1;
		unsigned char IOA		:3;
		
	} BIT;
	
} _16TIOR;


/**                  Common                      **/

#define T_TSTR 		(*(volatile _IOREG	*)0xffff60)
#define T_TSNC 		(*(volatile _IOREG	*)0xffff61)
#define T_TMDR 		(*(volatile _IOREG	*)0xffff62)
#define T_TOLR 		(*(volatile _IOREG	*)0xffff63)
#define T_TISRA		(*(volatile _TISR	*)0xffff64)
#define T_TISRB		(*(volatile _TISR	*)0xffff65)
#define T_TISRC		(*(volatile _TISR	*)0xffff66)

/**                  Ch0                       **/

#define T_16TCR0 	(*(volatile _16TCR 	*)0xffff68)
#define T_TIOR0 	(*(volatile _16TIOR *)0xffff69)
#define T_16TCNT0_H (*(volatile _IOREG 	*)0xffff6A)
#define T_16TCNT0_L (*(volatile _IOREG 	*)0xffff6B)
#define T_GRA0_H 	(*(volatile _IOREG 	*)0xffff6C)
#define T_GRA0_L 	(*(volatile _IOREG 	*)0xffff6D)
#define T_GRB0_H 	(*(volatile _IOREG 	*)0xffff6E)
#define T_GRB0_L 	(*(volatile _IOREG 	*)0xffff6F)

/**                  Ch1                       **/

#define T_16TCR1 	(*(volatile _16TCR 	*)0xffff70)
#define T_TIOR1 	(*(volatile _16TIOR *)0xffff71)
#define T_16TCNT1_H (*(volatile _IOREG 	*)0xffff72)
#define T_16TCNT1_L (*(volatile _IOREG 	*)0xffff73)
#define T_GRA1_H 	(*(volatile _IOREG 	*)0xffff74)
#define T_GRA1_L 	(*(volatile _IOREG 	*)0xffff75)
#define T_GRB1_H 	(*(volatile _IOREG 	*)0xffff76)
#define T_GRB1_L 	(*(volatile _IOREG 	*)0xffff77)

/**                  Ch2                       **/

#define T_16TCR2 	(*(volatile _16TCR 	*)0xffff78)
#define T_TIOR2 	(*(volatile _16TIOR *)0xffff79)
#define T_16TCNT2_H (*(volatile _IOREG 	*)0xffff7A)
#define T_16TCNT2_L (*(volatile _IOREG 	*)0xffff7B)
#define T_GRA2_H 	(*(volatile _IOREG 	*)0xffff7C)
#define T_GRA2_L 	(*(volatile _IOREG 	*)0xffff7D)
#define T_GRB2_H 	(*(volatile _IOREG 	*)0xffff7E)
#define T_GRB2_L 	(*(volatile _IOREG 	*)0xffff7F)

#endif
