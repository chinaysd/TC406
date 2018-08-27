#ifndef BSP_UART_H_
#define BSP_UART_H_

#include "sys_config.h"

/**
	@brief:串口波特率设置
*/
#define	BSP_BAURATE						9600

#define 	BSP_UART0_ID					0X00
#define 	BSP_UART1_ID					0X01

/**
	@brief:Number of hardware serial ports.
*/
#define 	UART_NUM						2
#define 	UART_NUM0						0
#define 	UART_NUM1						1
/**
	@brief:Serial port reception length.
*/
#define 	BSP_UART_SIZE					7

typedef struct{
	unsigned char flag;
	unsigned int len,send_cnt;
	unsigned char buf[BSP_UART_SIZE];
}Bsp_Tx_t;






int Bsp_UartInit(unsigned char id);
void Bsp_UartSendBuf(unsigned char id,unsigned char *buf,unsigned int len);

#endif





