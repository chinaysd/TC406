/*--------------------------------------------------------------------------
SC92F754X_ASM.H

ASM Header file for SC92F754X microcontroller.
Copyright (c) 2017 Shenzhen SinOne Chip Electronic CO., Ltd.
All rights reserved.
��������Ԫ΢�������޹�˾
�汾��:  V1.0    
����:  2017.08.01

--------------------------------------------------------------------------*/
#ifndef _SC92F754X_ASM_H_
#define _SC92F754X_ASM_H_

/* ------------------- �ֽڼĴ���-------------------- */
/*CPU*/
ACC	    EQU 0xE0	//�ۼ�����
B       EQU 0xF0	//ͨ�üĴ���B		
PSW	    EQU 0xD0	//����״̬��		
DPH	    EQU 0x83	//����ָ���8λ		
DPL	    EQU 0x82	//����ָ���8λ		
SP      EQU 0x81	//��ջָ��			
                       
/*system*/             
PCON    EQU 0x87	//��Դ�������ƼĴ���
                       
/*interrupt*/          
IP	    EQU 0xB8	//�ж�����Ȩ���ƼĴ���
IE	    EQU 0xA8	//�жϿ��ƼĴ���
IP1     EQU 0XB9 //�ж����ȼ����ƼĴ���1
IE1     EQU 0XA9 //�жϿ��ƼĴ���1
                       
/*PORT*/  
P5PH	  EQU 0xDA	//P5��ģʽ���ƼĴ���0		
P5CON  	EQU 0xD9	//P5��ģʽ���ƼĴ���1		
P5	    EQU 0xD8	//P5�����ݼĴ��� 
P4PH    EQU 0xC2	//P4��ģʽ���ƼĴ���0		
P4CON	  EQU 0xC1	//P4��ģʽ���ƼĴ���1	
P4	    EQU 0xC0	//P4�����ݼĴ���
P3PH    EQU 0xB2	//P3��ģʽ���ƼĴ���0		
P3CON	  EQU 0xB1	//P3��ģʽ���ƼĴ���1	
P3	    EQU 0xB0	//P3�����ݼĴ���            
P2PH	  EQU 0xA2	//P2��ģʽ���ƼĴ���0		
P2CON  	EQU 0xA1	//P2��ģʽ���ƼĴ���1		
P2	    EQU 0xA0	//P2�����ݼĴ���
P1PH    EQU 0x92	//P1��ģʽ���ƼĴ���0		
P1CON	  EQU 0x91	//P1��ģʽ���ƼĴ���1	
P1	    EQU 0x90	//P1�����ݼĴ���
P0PH	  EQU 0x9B	//P0��ģʽ���ƼĴ���1		
P0CON  	EQU 0x9A	//P0��ģʽ���ƼĴ���1		
P0	    EQU 0x80	//P0�����ݼĴ���
IOHCON0	EQU 0x96	//IOH0���üĴ���
IOHCON1	EQU 0x97	//IOH1���üĴ���
                       
/*TIMER*/              
TMCON   EQU 0x8E	//��ʱ��Ƶ�ʿ��ƼĴ���
TH1	    EQU 0x8D	//��ʱ��1��8λ
TH0	    EQU 0x8C	//��ʱ��0��8λ
TL1	    EQU 0x8B	//��ʱ��1��8λ
TL0	    EQU 0x8A	//��ʱ��0��8λ
TMOD	  EQU 0x89	//��ʱ������ģʽ�Ĵ���
TCON	  EQU 0x88	//��ʱ�����ƼĴ���
T2CON   EQU 0XC8 //��ʱ��2���ƼĴ���
T2MOD   EQU 0XC9 //��ʱ��2����ģʽ�Ĵ���
RCAP2L  EQU 0XCA //��ʱ��2����/��׽��8λ
RCAP2H  EQU 0XCB //��ʱ��2����/��׽��8λ
TL2     EQU 0XCC //��ʱ��2��8λ
TH2     EQU 0XCD //��ʱ��2��8λ
                       
/*ADC*/                
ADCCFG0 EQU 0xAB	//ADC�������üĴ���0
ADCCFG1 EQU 0xAC	//ADC�������üĴ���1
ADCCFG2 EQU 0xAA	//ADC�������üĴ���2
ADCCON  EQU 0XAD //ADC���ƼĴ���
ADCVL	  EQU 0xAE	//ADC ����Ĵ���
ADCVH	  EQU 0xAF	//ADC ����Ĵ���
                       
/*PWM*/                
PWMCFG	EQU 0xD4	//PWM���üĴ���
PWMCON	EQU 0xD3	//PWM���ƼĴ���
                      
/*WatchDog*/          
BTMCON  EQU 0XCE //��Ƶ��ʱ�����ƼĴ���
WDTCON  EQU 0xCF	//WDT���ƼĴ���
                                              
/*LCD*/
OTCON   EQU 0X8F	//LCD��ѹ������ƼĴ���
P0VO    EQU 0X9C //P0 LCD Bais ����Ĵ���
P1VO    EQU 0X94 //P1 LCD Bais ����Ĵ���
P2VO    EQU 0XA4 //P2 LCD Bais ����Ĵ���
P3VO    EQU 0XB3 //P3 LCD Bais ����Ĵ���

DDRCON  EQU 0X93 //P2 LCD Bais ����Ĵ���

/*INT*/
INT0F   EQU 0XBA 	//INT0 �½����жϿ��ƼĴ���
INT0R   EQU 0XBB 	//INT0 �Ͻ����жϿ��ƼĴ���
INT1F   EQU 0XBC 	//INT1 �½����жϿ��ƼĴ���
INT1R   EQU 0XBD 	//INT1 �Ͻ����жϿ��ƼĴ���
INT2F   EQU 0XC6 	//INT2 �½����жϿ��ƼĴ���
INT2R   EQU 0XC7 	//INT2 �Ͻ����жϿ��ƼĴ���

/*PGA*/

/*IAP */
IAPCTL	EQU 0xF6	//IAP���ƼĴ���
IAPDAT	EQU 0xF5	//IAP���ݼĴ���
IAPADE  EQU 0xF4 //IAP��չ��ַ�Ĵ���
IAPADH	EQU 0xF3	//IAPд���ַ��λ�Ĵ���
IAPADL	EQU 0xF2	//IAPд���ַ��8λ�Ĵ���
IAPKEY	EQU 0xF1	//IAP�����Ĵ���

/*UART*/
SCON    EQU 0X98  	//���ڿ��ƼĴ���
SBUF    EQU 0X99  	//�������ݻ���Ĵ���

/*SPI*/
SSCON0  EQU 0X9D   //SSI���ƼĴ���0
SSCON1  EQU 0X9E   //SSI���ƼĴ���1
SSCON2  EQU 0X95   //SSI���ƼĴ���2
SSDAT   EQU 0X9F   //SPI���ݼĴ���

OPINX   EQU 0XFE 
OPREG   EQU 0XFF 
EXADH   EQU 0XF7

/*Check Sum*/
CHKSUML EQU 0XFC        //Check Sum����Ĵ�����λ
CHKSUMH EQU 0XFD	       //Check Sum����Ĵ�����λ

/*ģ��Ƚ���*/
CMPCFG  EQU 0XB6	       //ģ��Ƚ������üĴ���
CMPCON  EQU 0XB7	       //ģ��Ƚ������ƼĴ���

/*�˳�����*/
EXA0    EQU 0xE9        //��չ�ۼ���0
EXA1    EQU 0xEA        //��չ�ۼ���1
EXA2    EQU 0xEB        //��չ�ۼ���2
EXA3    EQU 0xEC        //��չ�ۼ���3
EXBL    EQU 0xED        //��չB�Ĵ���0
EXBH    EQU 0xEE        //��չB�Ĵ���1
OPERCON EQU 0xEF        //������ƼĴ���

/* ------------------- λ�Ĵ���-------------------- */
/*PSW*/
CY	EQU  PSW .7	//��־λ		0:�ӷ��������λ�޽�λ�����߼����������λ�޽�λʱ		1:�ӷ��������λ�н�λ�����߼����������λ�н�λʱ
AC	EQU  PSW .6	//��λ������־λ	0:�޽�λ����λ		1:�ӷ�����ʱ��bit3λ�н�λ�������������bit3λ�н�λʱ
F0	EQU  PSW .5	//�û���־λ
RS1	EQU  PSW .4	//�����Ĵ�����ѡ��λ
RS0 EQU  PSW .3	//�����Ĵ�����ѡ��λ
OV	EQU  PSW .2	//�����־λ
F1	EQU  PSW .1	//F1��־
P	  EQU  PSW .0	//��ż��־λ		0:ACC��1�ĸ���Ϊż��������0����		1:ACC��1�ĸ���Ϊ����

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
IPADC	  EQU  IP .6		//ADC�ж����ȿ���λ	0:�趨 ADC���ж�����Ȩ�� ���͡�		1:�趨 ADC���ж�����Ȩ�� ���ߡ�
IPT2	  EQU  IP .5		//PWM�ж����ȿ���λ	0:�趨 PWM���ж�����Ȩ�� ���͡�		1:�趨 PWM ���ж�����Ȩ�� ���ߡ�
IPUART	EQU  IP .4		//SIF�ж����ȿ���λ	0:�趨 SIF���ж�����Ȩ�� ���͡�		1:�趨 SIF���ж�����Ȩ�� ���ߡ�
IPT1	  EQU  IP .3		//Timer1�ж����ȿ���λ	0:�趨 Timer 1���ж�����Ȩ�� ���͡�	1:�趨 Timer 1���ж�����Ȩ�� ���ߡ�
IPINT1	EQU  IP .2		//32K Base Timer�ж����ȿ���λ		0:�趨 32K���ж�����Ȩ�� ���͡�		1:�趨 32K���ж�����Ȩ�� ���ߡ�
IPT0	  EQU  IP .1		//Timer0�ж����ȿ���λ	0:�趨 Timer 0���ж�����Ȩ�� ���͡�	1:�趨 Timer 0���ж�����Ȩ�� ���ߡ�
IPINT0	EQU  IP .0

/*IE*/
EA	  EQU  IE .7		//�ж�ʹ�ܵ��ܿ���	0:�ر����е��ж�	1:�����е��ж�
EADC	EQU  IE .6		//ADC�ж�ʹ�ܿ���	0:�ر�ADC�ж�		1:��ADC�ж�
ET2 	EQU  IE .5		//PWM�ж�ʹ�ܿ���	0:�ر�PWM�ж�		1:��PWM�ж�
EUART EQU  IE .4		//UART�ж�ʹ�ܿ���	0:�ر�SIF�ж�		1:��SIF�ж�
ET1 	EQU  IE .3		//Timer1�ж�ʹ�ܿ���	0:�ر�TIMER1�ж�	1:��TIMER1�ж�
EINT1	EQU  IE .2		//32K Base Timer�ж�ʹ�ܿ���	0:�ر�32K�ж�		1:��32K�ж�	
ET0	  EQU  IE .1		//Timer0�ж�ʹ�ܿ���	0:�ر�TIMER0�ж�	1:��TIMER0�ж�
EINT0	EQU  IE .0		//TouchKey���ж�ʹ�ܿ���	0:�ر�TouchKey�ж�  1:��TouchKey�ж�

/*TCON*/
TF1 EQU  TCON .7	//T1����ж������־λ	T1��������������ж�ʱ��Ӳ����TF1��Ϊ��1���������жϣ�CPU��Ӧʱ��Ӳ���塰0����
TR1	EQU  TCON .6	//��ʱ��T1�����п���λ	0:Timer1��ֹ����		1:Timer1��ʼ����
TF0	EQU  TCON .5	//T0����ж������־λ	T0��������������ж�ʱ��Ӳ����TF0��Ϊ��1���������жϣ�CPU��Ӧʱ��Ӳ���塰0����
TR0	EQU  TCON .4	//��ʱ��T0�����п���λ	0:Timer0��ֹ����		1:Timer0��ʼ����

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
*SC92F7547��װδ�����Ĺܽţ���
*SC92F7546��װδ�����Ĺܽţ���
*SC92F7545��װδ�����Ĺܽţ�P00
*SC92F7543��װδ�����Ĺܽţ�P00/P01
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
*SC92F7547��װδ�����Ĺܽţ���
*SC92F7546��װδ�����Ĺܽţ���
*SC92F7545��װδ�����Ĺܽţ���
*SC92F7543��װδ�����Ĺܽţ�P10/P14/P15/P16/P17
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
*SC92F7547��װδ�����Ĺܽţ���
*SC92F7546��װδ�����Ĺܽţ���
*SC92F7545��װδ�����Ĺܽţ���
*SC92F7543��װδ�����Ĺܽţ�P26/P27
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
*SC92F7547��װδ�����Ĺܽţ���
*SC92F7546��װδ�����Ĺܽţ���
*SC92F7545��װδ�����Ĺܽţ�P3
*SC92F7543��װδ�����Ĺܽţ���
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
*SC92F7547��װδ�����Ĺܽţ���
*SC92F7546��װδ�����Ĺܽţ�P46/P47
*SC92F7545��װδ�����Ĺܽţ�P40
*SC92F7543��װδ�����Ĺܽţ�P40/P44/P45/P46/P47
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
*SC92F7547��װδ�����Ĺܽţ���
*SC92F7546��װδ�����Ĺܽţ�P54/P55
*SC92F7545��װδ�����Ĺܽţ�P5
*SC92F7543��װδ�����Ĺܽţ�P5
******************************************/
P55	EQU  P5 .5
P54	EQU  P5 .4
P53	EQU  P5 .3
P52	EQU  P5 .2
P51	EQU  P5 .1
P50	EQU  P5 .0

/****************************************************************************
*ע�⣺��װδ�����Ĺܽţ�������Ϊǿ�������ģʽ
*ICѡ�ͣ��������ʹ�õ�IC�ͺ�,�ڳ�ʼ����IO�ں󣬵������Ӧ��δ�����ܽŵ�IO������
*����ѡ��SC92F7547�����õ��ú궨�塣
*****************************************************************************/  
SC92F7546_IO_Init  MACRO  IO                     //SC92F7546δ�����ܽŵ�IO������
									 ORL P4CON,#0XC0
									 ORL P5CON,#0X30
                   ENDM
SC92F7545_IO_Init  MACRO  IO                     //SC92F7545δ�����ܽŵ�IO������
                   ORL P0CON,#0X01
									 ORL P3CON,#0XFF
									 ORL P2CON,#0X01
									 ORL P5CON,#0XFF
                   ENDM
SC92F7543_IO_Init  MACRO  IO                     //SC92F7543δ�����ܽŵ�IO������
                   ORL P0CON,#0X03
									 ORL P1CON,#0XF1
									 ORL P2CON,#0XC0
									 ORL P0CON,#0XF1
									 ORL P5CON,#0XFF
                   ENDM
#endif