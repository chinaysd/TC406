#ifndef APP_H_
#define APP_H_

#include "pushrod.h"
#include "sys_config.h"
#include "bsp_uart.h"

/**
	@brief:串口通讯
*/
#define MESSAGE_ID				0X01
#define START_FIELD				0X55
#define STOP_MESSAGE				0X0D0A
#define MSG_ID					0X01
/*
     @brief:复位延时
*/
#define TOUCH_SHAKE_TIME		1000//10


/**
	@brief: 灯和加热模块id
*/
#define FOOT_ID0					0
#define FOOT_ID1					1

#define HEAT_ID0					0
#define HEAT_ID1					1

/**
	@brief:灯和加热IO
*/
#define FOOT1_LED				P10
#define FOOT2_LED				P14

#define HEAT1_PIN				P42
#define HEAT2_PIN				P41


#define TK1_VALUE				0X01
#define TK2_VALUE				0X02
#define TK3_VALUE				0X04
#define TK4_VALUE				0X08
#define TK5_VALUE				0X10
#define TK6_VALUE				0X20
#define TK7_VALUE				0X40
#define TK8_VALUE				0X80
#define TK9_VALUE				0X0100
#define TK10_VALUE				0X0200

#define LED1_VALUE				0X0001
#define LED2_VALUE				0X0002
#define LED3_VALUE				0X0004
#define LED4_VALUE				0X0008
#define LED5_VALUE				0X0010
#define LED6_VALUE				0X0020
#define LED7_VALUE				0X0040
#define LED8_VALUE				0X0080
#define LED9_VALUE				0X0100
#define LED10_VALUE				0X0200
#define BACK_LIGHT_VALUE			0X8000

#define WARN_AUTO_CLOSE		3600
#define MASS_AUTO_CLOSE			1800
#define SYSTEM_AUTO_CLOSE		14400	


typedef struct{
	INT8U buf[BSP_UART_SIZE];
	INT8U len;
}Rev_Buf_t;


typedef struct{
	Rev_Buf_t rev_buf[2];
	INT16U get_key[2],cur_key[2];
	INT8U send_buf[BSP_UART_SIZE]; 
	INT8U foot_ledsta[2],msge_sta[2],warn_sta[2],reset_sta[2];
	INT8U warn_auto_clsflag[2],system_auto_clsflag,system_shutdw_flag,msge_auto_clsflag[2];
	INT8U warn_auto_clscnt[2],system_auto_clscnt,msge_auto_clscnt[2];
	INT16U led_sta[2];
	INT8U reset_cntflag[2],reset_ing[2];
	INT16U reset_cnt;
}App_Para_t;










void App_Init(void);
void App_Handle(void);

#endif
