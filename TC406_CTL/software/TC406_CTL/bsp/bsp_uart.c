#include "bsp_uart.h"
#include "sys_config.h"
#include "data_type.h"

#include <string.h>

 Bsp_Tx_t Tx_Buf[UART_NUM];

/*****************************************************************************
 * Function	  : Bsp_UartInit1
 * Description   : 串口初始化
 * Input           : void  
 * Output		  : None
 * Return		  : 
 * Others		  : 
 * Record
 * 1.Date		  : 20180403
 *   Author       : marco
 *   Modification: Created function

*****************************************************************************/
int Bsp_UartInit(unsigned char id){
	if(id == BSP_UART0_ID){
		#ifdef UART0_ENABLE
		SET_REG_CON(0,2);
		SCON |= 0X50;   //设置通信方式为模式一，允许接收
		TMCON|=0X02;
		TMOD|=0X20;
		PCON |= 0X80;	//SMOD=1
		TH1=(INT8U)((SYS_FRE_SET/BSP_BAURATE)>>8);	  //波特率为T1的溢出时间；
		TL1=(INT8U)(SYS_FRE_SET/BSP_BAURATE);
		TR1=0;
		ET1=0;
		EUART = 1;     //开启Uart0中断
		return 0;
		#endif
	}else if(id == BSP_UART1_ID){
		#ifdef UART1_ENABLE
		SET_REG_CON(1,3);	// 必须设置IO口，否则则为输入状态
		P13 = 1;
		OTCON = 0xC0;    //串行接口SSI选择Uart1通信
		SSCON0 = 0x50;   //设置通信方式为模式一，允许接收
		SSCON1 = (INT8U)(SYS_FRE_SET/BSP_BAURATE);   //波特率低位控制
		SSCON2 = (INT8U)((SYS_FRE_SET/BSP_BAURATE)>>8);   //波特率高位控制
		IE1 = 0x01;      //开启SSI中断
		return 0;
		#endif
	}	
	return -1;
}

/*****************************************************************************
 * Function	  : Bsp_UartSendBuf
 * Description   : 串口发送数据
 * Input           : unsigned char id    
			    unsigned char *buf  
			    unsigned int len    
 * Output		  : None
 * Return		  : 
 * Others		  : 
 * Record
 * 1.Date		  : 20180409
 *   Author       : marco
 *   Modification: Created function

*****************************************************************************/
void Bsp_UartSendBuf(unsigned char id,unsigned char *buf,unsigned int len){
	if(id == BSP_UART0_ID){
		#ifdef UART0_ENABLE
		if(!Tx_Buf[UART_NUM0].flag){
			if(len > BSP_UART_SIZE)
				return ;
			memset((void*)&Tx_Buf[UART_NUM0],0,sizeof(Bsp_Tx_t));
			memcpy(&Tx_Buf[UART_NUM0].buf[0],buf,len);
			Tx_Buf[UART_NUM0].len = len;
			Tx_Buf[UART_NUM0].flag = True;
			TI = 0;
			SBUF = *buf;
		}
		#endif
	}else if(id == BSP_UART1_ID){
		#ifdef UART1_ENABLE
		if(!Tx_Buf[UART_NUM1].flag){
			if(len > BSP_UART_SIZE)
				return ;
			memset((void*)&Tx_Buf[UART_NUM1],0,sizeof(Bsp_Tx_t));
			memcpy(&Tx_Buf[UART_NUM1].buf[0],buf,len);
			Tx_Buf[UART_NUM1].len = len;
			Tx_Buf[UART_NUM1].flag = True;
			/*<开启传输>*/
			SSDAT = Tx_Buf[UART_NUM1].buf[0];
		}
		#endif
	}
}



