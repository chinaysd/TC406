/*--------------------------------------------------------------------------
SC92F754X_ASM.H

ASM Header file for SC92F754X microcontroller.
Copyright (c) 2017 Shenzhen SinOne Chip Electronic CO., Ltd.
All rights reserved.
深圳市赛元微电子有限公司
版本号:  V1.0    
日期:  2017.08.01

--------------------------------------------------------------------------*/
#ifndef _SC92F754X_ASM_H_
#define _SC92F754X_ASM_H_

/* ------------------- 字节寄存器-------------------- */
/*CPU*/
ACC	    EQU 0xE0	//累加器Ａ
B       EQU 0xF0	//通用寄存器B		
PSW	    EQU 0xD0	//程序状态字		
DPH	    EQU 0x83	//数据指针高8位		
DPL	    EQU 0x82	//数据指针低8位		
SP      EQU 0x81	//堆栈指针			
                       
/*system*/             
PCON    EQU 0x87	//电源管理控制寄存器
                       
/*interrupt*/          
IP	    EQU 0xB8	//中断优先权控制寄存器
IE	    EQU 0xA8	//中断控制寄存器
IP1     EQU 0XB9 //中断优先级控制寄存器1
IE1     EQU 0XA9 //中断控制寄存器1
                       
/*PORT*/  
P5PH	  EQU 0xDA	//P5口模式控制寄存器0		
P5CON  	EQU 0xD9	//P5口模式控制寄存器1		
P5	    EQU 0xD8	//P5口数据寄存器 
P4PH    EQU 0xC2	//P4口模式控制寄存器0		
P4CON	  EQU 0xC1	//P4口模式控制寄存器1	
P4	    EQU 0xC0	//P4口数据寄存器
P3PH    EQU 0xB2	//P3口模式控制寄存器0		
P3CON	  EQU 0xB1	//P3口模式控制寄存器1	
P3	    EQU 0xB0	//P3口数据寄存器            
P2PH	  EQU 0xA2	//P2口模式控制寄存器0		
P2CON  	EQU 0xA1	//P2口模式控制寄存器1		
P2	    EQU 0xA0	//P2口数据寄存器
P1PH    EQU 0x92	//P1口模式控制寄存器0		
P1CON	  EQU 0x91	//P1口模式控制寄存器1	
P1	    EQU 0x90	//P1口数据寄存器
P0PH	  EQU 0x9B	//P0口模式控制寄存器1		
P0CON  	EQU 0x9A	//P0口模式控制寄存器1		
P0	    EQU 0x80	//P0口数据寄存器
IOHCON0	EQU 0x96	//IOH0设置寄存器
IOHCON1	EQU 0x97	//IOH1设置寄存器
                       
/*TIMER*/              
TMCON   EQU 0x8E	//定时器频率控制寄存器
TH1	    EQU 0x8D	//定时器1高8位
TH0	    EQU 0x8C	//定时器0高8位
TL1	    EQU 0x8B	//定时器1低8位
TL0	    EQU 0x8A	//定时器0低8位
TMOD	  EQU 0x89	//定时器工作模式寄存器
TCON	  EQU 0x88	//定时器控制寄存器
T2CON   EQU 0XC8 //定时器2控制寄存器
T2MOD   EQU 0XC9 //定时器2工作模式寄存器
RCAP2L  EQU 0XCA //定时器2重载/捕捉低8位
RCAP2H  EQU 0XCB //定时器2重载/捕捉高8位
TL2     EQU 0XCC //定时器2低8位
TH2     EQU 0XCD //定时器2高8位
                       
/*ADC*/                
ADCCFG0 EQU 0xAB	//ADC功能配置寄存器0
ADCCFG1 EQU 0xAC	//ADC功能配置寄存器1
ADCCFG2 EQU 0xAA	//ADC功能配置寄存器2
ADCCON  EQU 0XAD //ADC控制寄存器
ADCVL	  EQU 0xAE	//ADC 结果寄存器
ADCVH	  EQU 0xAF	//ADC 结果寄存器
                       
/*PWM*/                
PWMCFG	EQU 0xD4	//PWM设置寄存器
PWMCON	EQU 0xD3	//PWM控制寄存器
                      
/*WatchDog*/          
BTMCON  EQU 0XCE //低频定时器控制寄存器
WDTCON  EQU 0xCF	//WDT控制寄存器
                                              
/*LCD*/
OTCON   EQU 0X8F	//LCD电压输出控制寄存器
P0VO    EQU 0X9C //P0 LCD Bais 输出寄存器
P1VO    EQU 0X94 //P1 LCD Bais 输出寄存器
P2VO    EQU 0XA4 //P2 LCD Bais 输出寄存器
P3VO    EQU 0XB3 //P3 LCD Bais 输出寄存器

DDRCON  EQU 0X93 //P2 LCD Bais 输出寄存器

/*INT*/
INT0F   EQU 0XBA 	//INT0 下降沿中断控制寄存器
INT0R   EQU 0XBB 	//INT0 上降沿中断控制寄存器
INT1F   EQU 0XBC 	//INT1 下降沿中断控制寄存器
INT1R   EQU 0XBD 	//INT1 上降沿中断控制寄存器
INT2F   EQU 0XC6 	//INT2 下降沿中断控制寄存器
INT2R   EQU 0XC7 	//INT2 上降沿中断控制寄存器

/*PGA*/

/*IAP */
IAPCTL	EQU 0xF6	//IAP控制寄存器
IAPDAT	EQU 0xF5	//IAP数据寄存器
IAPADE  EQU 0xF4 //IAP扩展地址寄存器
IAPADH	EQU 0xF3	//IAP写入地址高位寄存器
IAPADL	EQU 0xF2	//IAP写入地址低8位寄存器
IAPKEY	EQU 0xF1	//IAP保护寄存器

/*UART*/
SCON    EQU 0X98  	//串口控制寄存器
SBUF    EQU 0X99  	//串口数据缓存寄存器

/*SPI*/
SSCON0  EQU 0X9D   //SSI控制寄存器0
SSCON1  EQU 0X9E   //SSI控制寄存器1
SSCON2  EQU 0X95   //SSI控制寄存器2
SSDAT   EQU 0X9F   //SPI数据寄存器

OPINX   EQU 0XFE 
OPREG   EQU 0XFF 
EXADH   EQU 0XF7

/*Check Sum*/
CHKSUML EQU 0XFC        //Check Sum结果寄存器低位
CHKSUMH EQU 0XFD	       //Check Sum结果寄存器高位

/*模拟比较器*/
CMPCFG  EQU 0XB6	       //模拟比较器设置寄存器
CMPCON  EQU 0XB7	       //模拟比较器控制寄存器

/*乘除法器*/
EXA0    EQU 0xE9        //扩展累加器0
EXA1    EQU 0xEA        //扩展累加器1
EXA2    EQU 0xEB        //扩展累加器2
EXA3    EQU 0xEC        //扩展累加器3
EXBL    EQU 0xED        //扩展B寄存器0
EXBH    EQU 0xEE        //扩展B寄存器1
OPERCON EQU 0xEF        //运算控制寄存器

/* ------------------- 位寄存器-------------------- */
/*PSW*/
CY	EQU  PSW .7	//标志位		0:加法运算最高位无进位，或者减法运算最高位无借位时		1:加法运算最高位有进位，或者减法运算最高位有借位时
AC	EQU  PSW .6	//进位辅助标志位	0:无借位、进位		1:加法运算时在bit3位有进位，或减法运算在bit3位有借位时
F0	EQU  PSW .5	//用户标志位
RS1	EQU  PSW .4	//工作寄存器组选择位
RS0 EQU  PSW .3	//工作寄存器组选择位
OV	EQU  PSW .2	//溢出标志位
F1	EQU  PSW .1	//F1标志
P	  EQU  PSW .0	//奇偶标志位		0:ACC中1的个数为偶数（包括0个）		1:ACC中1的个数为奇数

/*T2CON*/
TF2  	EQU  T2CON .7
EXF2	EQU  T2CON .6
RCLK	EQU  T2CON .5
TCLK	EQU  T2CON .4
EXEN2	EQU  T2CON .3
TR2	  EQU  T2CON .2
T2    EQU  T2CON .1
CP	  EQU  T2CON .0

/*IP*/
IPADC	  EQU  IP .6		//ADC中断优先控制位	0:设定 ADC的中断优先权是 “低”		1:设定 ADC的中断优先权是 “高”
IPT2	  EQU  IP .5		//PWM中断优先控制位	0:设定 PWM的中断优先权是 “低”		1:设定 PWM 的中断优先权是 “高”
IPUART	EQU  IP .4		//SIF中断优先控制位	0:设定 SIF的中断优先权是 “低”		1:设定 SIF的中断优先权是 “高”
IPT1	  EQU  IP .3		//Timer1中断优先控制位	0:设定 Timer 1的中断优先权是 “低”	1:设定 Timer 1的中断优先权是 “高”
IPINT1	EQU  IP .2		//32K Base Timer中断优先控制位		0:设定 32K的中断优先权是 “低”		1:设定 32K的中断优先权是 “高”
IPT0	  EQU  IP .1		//Timer0中断优先控制位	0:设定 Timer 0的中断优先权是 “低”	1:设定 Timer 0的中断优先权是 “高”
IPINT0	EQU  IP .0

/*IE*/
EA	  EQU  IE .7		//中断使能的总控制	0:关闭所有的中断	1:打开所有的中断
EADC	EQU  IE .6		//ADC中断使能控制	0:关闭ADC中断		1:打开ADC中断
ET2 	EQU  IE .5		//PWM中断使能控制	0:关闭PWM中断		1:打开PWM中断
EUART EQU  IE .4		//UART中断使能控制	0:关闭SIF中断		1:打开SIF中断
ET1 	EQU  IE .3		//Timer1中断使能控制	0:关闭TIMER1中断	1:打开TIMER1中断
EINT1	EQU  IE .2		//32K Base Timer中断使能控制	0:关闭32K中断		1:打开32K中断	
ET0	  EQU  IE .1		//Timer0中断使能控制	0:关闭TIMER0中断	1:打开TIMER0中断
EINT0	EQU  IE .0		//TouchKey的中断使能控制	0:关闭TouchKey中断  1:打开TouchKey中断

/*TCON*/
TF1 EQU  TCON .7	//T1溢出中断请求标志位	T1产生溢出，发生中断时，硬件将TF1置为“1”，申请中断，CPU响应时，硬件清“0”。
TR1	EQU  TCON .6	//定时器T1的运行控制位	0:Timer1禁止计数		1:Timer1开始计数
TF0	EQU  TCON .5	//T0溢出中断请求标志位	T0产生溢出，发生中断时，硬件将TF0置为“1”，申请中断，CPU响应时，硬件清“0”。
TR0	EQU  TCON .4	//定时器T0的运行控制位	0:Timer0禁止计数		1:Timer0开始计数

/*SCON*/
SM0	EQU  SCON .7
SM1	EQU  SCON .6
SM2	EQU  SCON .5
REN	EQU  SCON .4
TB8 EQU  SCON .3
RB8 EQU  SCON .2
TI	EQU  SCON .1
RI	EQU  SCON .0

/******************* P0 ******************
*SC92F7547封装未引出的管脚：无
*SC92F7546封装未引出的管脚：无
*SC92F7545封装未引出的管脚：P00
*SC92F7543封装未引出的管脚：P00/P01
******************************************/
P07	EQU  P0 .7
P06 EQU  P0 .6
P05	EQU  P0 .5
P04 EQU  P0 .4
P03	EQU  P0 .3
P02 EQU  P0 .2
P01	EQU  P0 .1
P00 EQU  P0 .0

/******************* P1 ******************
*SC92F7547封装未引出的管脚：无
*SC92F7546封装未引出的管脚：无
*SC92F7545封装未引出的管脚：无
*SC92F7543封装未引出的管脚：P10/P14/P15/P16/P17
******************************************/
P17	EQU  P1 .7
P16	EQU  P1 .6
P15 EQU  P1 .5
P14	EQU  P1 .4
P13 EQU  P1 .3
P12	EQU  P1 .2
P11	EQU  P1 .1
P10	EQU  P1 .0

/******************* P2 ******************
*SC92F7547封装未引出的管脚：无
*SC92F7546封装未引出的管脚：无
*SC92F7545封装未引出的管脚：无
*SC92F7543封装未引出的管脚：P26/P27
******************************************/
P27 EQU  P2 .7
P26	EQU  P2 .6
P25 EQU  P2 .5
P24	EQU  P2 .4
P23	EQU  P2 .3
P22	EQU  P2 .2
P21	EQU  P2 .1
P20	EQU  P2 .0

/******************* P3 ******************
*SC92F7547封装未引出的管脚：无
*SC92F7546封装未引出的管脚：无
*SC92F7545封装未引出的管脚：P3
*SC92F7543封装未引出的管脚：无
******************************************/
P37	EQU  P3 .7
P36	EQU  P3 .6
P35	EQU  P3 .5
P34	EQU  P3 .4
P33	EQU  P3 .3
P32	EQU  P3 .2
P31	EQU  P3 .1
P30	EQU  P3 .0

/******************* P4 ******************
*SC92F7547封装未引出的管脚：无
*SC92F7546封装未引出的管脚：P46/P47
*SC92F7545封装未引出的管脚：P40
*SC92F7543封装未引出的管脚：P40/P44/P45/P46/P47
******************************************/
P47	EQU  P4 .7
P46	EQU  P4 .6
P45	EQU  P4 .5
P44	EQU  P4 .4
P43	EQU  P4 .3
P42	EQU  P4 .2
P41	EQU  P4 .1
P40	EQU  P4 .0

/******************* P5 ******************
*SC92F7547封装未引出的管脚：无
*SC92F7546封装未引出的管脚：P54/P55
*SC92F7545封装未引出的管脚：P5
*SC92F7543封装未引出的管脚：P5
******************************************/
P55	EQU  P5 .5
P54	EQU  P5 .4
P53	EQU  P5 .3
P52	EQU  P5 .2
P51	EQU  P5 .1
P50	EQU  P5 .0

/****************************************************************************
*注意：封装未引出的管脚，需设置为强推挽输出模式
*IC选型：请根据所使用的IC型号,在初始化完IO口后，调用相对应的未引出管脚的IO口配置
*如若选择SC92F7547，则不用调用宏定义。
*****************************************************************************/  
SC92F7546_IO_Init  MACRO  IO                     //SC92F7546未引出管脚的IO口配置
									 ORL P4CON,#0XC0
									 ORL P5CON,#0X30
                   ENDM
SC92F7545_IO_Init  MACRO  IO                     //SC92F7545未引出管脚的IO口配置
                   ORL P0CON,#0X01
									 ORL P3CON,#0XFF
									 ORL P2CON,#0X01
									 ORL P5CON,#0XFF
                   ENDM
SC92F7543_IO_Init  MACRO  IO                     //SC92F7543未引出管脚的IO口配置
                   ORL P0CON,#0X03
									 ORL P1CON,#0XF1
									 ORL P2CON,#0XC0
									 ORL P0CON,#0XF1
									 ORL P5CON,#0XFF
                   ENDM
#endif
