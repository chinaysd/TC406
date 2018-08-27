#ifndef SYS_CONFIG_H_
#define SYS_CONFIG_H_

#include "SC92F754x_C.H"
#include "data_type.h"

/**
	@brief:是否开启WDT选项
*/
#define SYS_ENABLE_WDT

/**
	@brief:系统时间设置
*/
#define SYS_FRE_SET					16000000

#ifndef ON
#define ON  1
#endif

#ifndef OFF
#define OFF 0
#endif

/**
	@breif:定义到外部RAM
*/
#define XDATA						xdata

/**
	@brief:IO 方向控制
*/
#define IO_OUT						1
#define IO_IN							0

#define Get_Low(x)					((x) & 0XFF)
#define Get_High(x)					(((x) >> 8) & 0XFF)
#define Get_32bit(x,y)					((((x) << 8) | (y)) & 0XFFFF)


/**
	@brief:IO 控制寄存器设置
*/
#define SET_REG_CON(X,Y)				(P##X##CON |= ((1)<<(Y)))
#define CLR_REG_CON(X,Y)				(P##X##CON &= ~((1)<<(Y)))

/**
	@brief:IO 上拉设置
*/
#define SET_IO_PU(X,Y)				(P##X##PH |= ((1)<<(Y)))
#define CLR_IO_PU(X,Y)				(P##X##PH &= ~((1)<<(Y)))

/**
	@brief:喂狗功能
*/
#define SYS_ENABLE_WDT
#define CLEAR_WDT()					(WDTCON  = 0x10)	


#define UART0_ENABLE					
#define UART1_ENABLE











#endif
