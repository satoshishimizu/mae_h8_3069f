#include "defines.h"
#include "serial.h"
#include "lib.h"

/**************************************************/


unsigned int orOpm(unsigned int a, unsigned int vaule)
{
	unsigned int reuslt = 0;
	return reuslt = a | vaule;
	
}

int main(void)
{
	serial_init(SERIAL_DEFAULT_DEVICE);

	puts("-----------------Led1 and 2 is Light start!!\n");	
	/* p4ddr(P46 and P47) output setting 0x0c = 1100 0000  */
	/* p4dr (P46 and P47) output         0x0c = 1100 0000  */

	P4DDR.BYTE		= 0;
	P4DDR.BIT.B6	= ENABLE;
	P4DDR.BIT.B7	= ENABLE;

	P4DR.BYTE		= DISABLE;
	
	P4DR.BIT.B6 	= LED_ON;
	P4DR.BIT.B7 	= LED_OFF;
	
	/**
	 * カウンター
	*/
	int T_16TCR0_COUNTER = 0;
	int secCount = 0;
	
	/**
	 * カウントクロック設定 φ/8
	 */
	T_16TCR0.BIT.TPSC = 0x03;
	//T_16TCR1.BIT.TPSC = 0x03;
	
	/**
	 * カウンタクリア要因の選択
	 */
	T_16TCR0.BIT.CCLR = 0x01; // GRA
	//T_16TCR1.BIT.CCLR = 0x01; // GRA
	
	/**
	 * アウトプットコンペアレジスタの選択
	 */
	T_TIOR0.BIT.IOA = 0x02; // GRA コンペアマッチ 1出力
	//T_TIOR1.BIT.IOA = 0x02; // GRA コンペアマッチ 1出力
	
	/**
	 * IMF フラグ割込 要求許可
	T_TISRA.BIT.IMIE = 0x01; //割込 要求許可
	T_TISRB.BIT.IMIE = 0x01; //割込 要求許可
	 */
	
	/**
	 * 周期設定
	 */
	T_GRA0_H.BYTE = 0x27; // 10000
	T_GRA0_L.BYTE = 0x10; 
	//T_GRA1_H.BYTE = 0x00; //   250
	//T_GRA1_H.BYTE = 0xFA; 
	
	/**
	 * TIMER START
	 */
	T_TSTR.BYTE = 0x01; // 16TCNT0 Start
	
	while(1)
	{
		puts("T_16TCNT0:");	
			putxval(T_16TCNT0_H.BYTE,2);
			putxval(T_16TCNT0_L.BYTE,2);
		puts("\n");	
		if(T_TISRA.BIT.IMF == 0x01)
		{
			
			T_16TCR0_COUNTER++;
			puts("T_16TCR0_COUNTER:");	
				putxval(T_16TCR0_COUNTER,3);
			puts("\n");	
			
			if(T_16TCR0_COUNTER >= 25)
			{
				
				P4DR.BIT.B6 	=~ P4DR.BIT.B6;
				P4DR.BIT.B7 	=~ P4DR.BIT.B7;
				T_16TCR0_COUNTER = 0;
				secCount++;
				puts("----------------secCount:");	
					putxval(secCount,3);
				puts("\n");	
				/*
				if(secCount > 10)
				{
					break;
				}
				*/
			}
			
		}
	}
	
  return 0;	
}
