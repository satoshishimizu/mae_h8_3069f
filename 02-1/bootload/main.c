#include "defines.h"
#include "serial.h"
#include "lib.h"

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

/**************************************************/
/**       wait function                          **/
/**************************************************/

void wait(unsigned int ms)
{
	
	unsigned int i = ms;
	
	for ( i = 0; i > 10000; i++)
	{
		
	}

}

int main(void)
{
	serial_init(SERIAL_DEFAULT_DEVICE);

	puts("-----------------Led1 and 2 is Light start!!\n");
	
	unsigned char *p4ddr = (unsigned char *)0xfee003;
	unsigned char *p4dr  = (unsigned char *)0xffffd3;
	
	puts("*p4ddr=");	putxval(*p4ddr, 0); 	puts("\n");
	puts("*p4dr=");		putxval(*p4dr, 0); 		puts("\n");
	puts("----------------------------------------------\n");
	/* p4ddr(P46 and P47) output setting 0x0c = 1100 0000  */
	/* p4dr (P46 and P47) output         0x0c = 1100 0000  */
	*p4ddr = 0xc0;
	*p4dr  = 0xc0;
	puts("----------------------------------------------\n");	
	puts("*p4ddr=");	putxval(*p4ddr, 0); 	puts("\n");
	puts("*p4dr=");		putxval(*p4dr, 0); 		puts("\n");

	puts("-----------------end\n");

  return 0;
}
