#include "bsp_uart.h"
#include "sys_config.h"
#include "data_type.h"

#include <string.h>

 Bsp_Tx_t Tx_Buf[UART_NUM];

/*****************************************************************************
 * Function	  : Bsp_UartInit1
 * Description   : ���ڳ�ʼ��
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
		SCON |= 0X50;   //����ͨ�ŷ�ʽΪģʽһ���������
		TMCON|=0X02;
		TMOD|=0X20;
		PCON |= 0X80;	//SMOD=1
		TH1=(INT8U)((SYS_FRE_SET/BSP_BAURATE)>>8);	  //������ΪT1�����ʱ�䣻
		TL1=(INT8U)(SYS_FRE_SET/BSP_BAURATE);
		TR1=0;
		ET1=0;
		EUART = 1;     //����Uart0�ж�
		return 0;
		#endif
	}else if(id == BSP_UART1_ID){
		#ifdef UART1_ENABLE
		SET_REG_CON(1,3);	// ��������IO�ڣ�������Ϊ����״̬
		P13 = 1;
		OTCON = 0xC0;    //���нӿ�SSIѡ��Uart1ͨ��
		SSCON0 = 0x50;   //����ͨ�ŷ�ʽΪģʽһ���������
		SSCON1 = (INT8U)(SYS_FRE_SET/BSP_BAURATE);   //�����ʵ�λ����
		SSCON2 = (INT8U)((SYS_FRE_SET/BSP_BAURATE)>>8);   //�����ʸ�λ����
		IE1 = 0x01;      //����SSI�ж�
		return 0;
		#endif
	}	
	return -1;
}

/*****************************************************************************
 * Function	  : Bsp_UartSendBuf
 * Description   : ���ڷ�������
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
			/*<��������>*/
			SSDAT = Tx_Buf[UART_NUM1].buf[0];
		}
		#endif
	}
}



