#include "bsp_timer.h"

/*****************************************************************************
 * Function	  : bsp_Timer0Init
 * Description   : tim0����Ϊ1ms�ж�
 * Input           : void  
 * Output		  : None
 * Return		  : 
 * Others		  : 
 * Record
 * 1.Date		  : 20180414
 *   Author       : marco
 *   Modification: Created function

*****************************************************************************/
void Bsp_Timer0Init(void){ 
	TMCON |= 0x00;		
	TMOD = 0x11;    
	TL0 = (65536 - 1600 + 200)%256;    
	TH0 = (65536 - 1600 + 200)/256;
	TR0 = 0;
	ET0 = 1;//��ʱ��0����
	TR0 = 1;//�򿪶�ʱ��0
}

#if 0
void Bsp_Timer0IqrHandle() interrupt 1{

}

#endif


