						 /*--------------------------------------------------------------------------
SC92F754X_C.H

C Header file for SC92F754X microcontroller.
Copyright (c) 2017 Shenzhen SinOne Chip Electronic CO., Ltd.
All rights reserved.
��������Ԫ΢�������޹�˾
�汾��:  V0.1    
����:  2017.08.02
--------------------------------------------------------------------------*/
#ifndef _SC92F754X_H_
#define _SC92F754X_H_

/* ------------------- �ֽڼĴ���-------------------- */
///*CPU*/
sfr 	ACC	= 0xE0;		//�ۼ�����
sfr 	B	  = 0xF0;		//ͨ�üĴ���B		
sfr 	PSW	= 0xD0;		//����״̬��		
sfr 	DPH	= 0x83;		//����ָ���8λ		
sfr 	DPL	= 0x82;		//����ָ���8λ		
sfr 	SP	= 0x81;		//��ջָ��	
		

/*system*/
sfr 	PCON	= 0x87;		//��Դ�������ƼĴ���

/*interrupt*/
sfr   IP1   = 0XB9;   //�ж����ȼ����ƼĴ���1
sfr 	IP	  = 0xB8;		//�ж�����Ȩ���ƼĴ���
sfr 	IE	  = 0xA8;		//�жϿ��ƼĴ���
sfr   IE1   = 0XA9;  	//�жϿ��ƼĴ���1

/*PORT*/
sfr 	P5PH	  = 0xDA;		//P5��ģʽ���ƼĴ���		
sfr	  P5CON	  = 0xD9;		//P5��ģʽ���ƼĴ���		
sfr 	P5	    = 0xD8;		//P5�����ݼĴ���
sfr 	P4PH	  = 0xC2;		//P4��ģʽ���ƼĴ���		
sfr	  P4CON	  = 0xC1;		//P4��ģʽ���ƼĴ���		
sfr 	P4	    = 0xC0;		//P4�����ݼĴ���
sfr 	P3PH	  = 0xB2;		//P3��ģʽ���ƼĴ���		
sfr	  P3CON	  = 0xB1;		//P3��ģʽ���ƼĴ���		
sfr 	P3	    = 0xB0;		//P3�����ݼĴ���
sfr 	P2PH	  = 0xA2;		//P2��ģʽ���ƼĴ���		
sfr	  P2CON	  = 0xA1;		//P2��ģʽ���ƼĴ���		
sfr 	P2	    = 0xA0;		//P2�����ݼĴ���
sfr 	P1PH    = 0x92;		//P1��ģʽ���ƼĴ���		
sfr	  P1CON	  = 0x91;		//P1��ģʽ���ƼĴ���	
sfr 	P1	    = 0x90;		//P1�����ݼĴ���
sfr	  P0PH	  = 0x9B;		//P0��ģʽ���ƼĴ���		
sfr	  P0CON	  = 0x9A;		//P0��ģʽ���ƼĴ���		
sfr 	P0	    = 0x80;		//P0�����ݼĴ���
sfr 	IOHCON0 = 0x96;		//IOH0���üĴ���
sfr 	IOHCON1 = 0x97;		//IOH1���üĴ���

/*TIMER*/
sfr 	TMCON	  = 0x8E;		//��ʱ��Ƶ�ʿ��ƼĴ���
sfr 	TH1	    = 0x8D;		//��ʱ��1��8λ
sfr 	TH0	    = 0x8C;		//��ʱ��0��8λ
sfr 	TL1	    = 0x8B;		//��ʱ��1��8λ
sfr 	TL0	    = 0x8A;		//��ʱ��0��8λ
sfr 	TMOD	  = 0x89;		//��ʱ������ģʽ�Ĵ���
sfr 	TCON	  = 0x88;		//��ʱ�����ƼĴ���
sfr   T2CON   = 0xC8;   //��ʱ��2���ƼĴ���
sfr   T2MOD   = 0xC9; 	//��ʱ��2����ģʽ�Ĵ���
sfr   RCAP2L  = 0xCA;   //��ʱ��2����/��׽��8λ
sfr   RCAP2H  = 0xCB;   //��ʱ��2����/��׽��8λ
sfr   TL2     = 0xCC;   //��ʱ��2��8λ
sfr   TH2     = 0xCD;   //��ʱ��2��8λ


/*ADC*/
sfr	  ADCCFG0 = 0xAB;		//ADC�������üĴ���0
sfr	  ADCCFG1 = 0xAC;		//ADC�������üĴ���1
sfr   ADCCFG2 = 0XAA;   //ADC�������üĴ���2
sfr   ADCCON  = 0XAD;   //ADC���ƼĴ���
sfr 	ADCVL	  = 0xAE;		//ADC ����Ĵ���
sfr 	ADCVH	  = 0xAF;		//ADC ����Ĵ���

/*PWM*/
sfr 	PWMCFG	= 0xD4;		//PWM���üĴ���
sfr 	PWMCON	= 0xD3;		//PWM���üĴ���


//
///*WatchDog*/
sfr  	BTMCON  = 0XCE;   //��Ƶ��ʱ�����ƼĴ���
sfr 	WDTCON	= 0xCF;		//WDT���ƼĴ���


/*LCD*/
sfr   OTCON   = 0X8F;		//LCD��ѹ������ƼĴ���
sfr   P0VO    = 0X9C;   //P0 LCD Bais ����Ĵ���
sfr   P1VO    = 0X94;   //P1 LCD Bais ����Ĵ���
sfr   P2VO    = 0XA3;   //P2 LCD Bais ����Ĵ���
sfr   P3VO    = 0XB3;   //P3 LCD Bais ����Ĵ���

sfr   DDRCON  = 0X93;   //��ʾ�������üĴ���


/*INT*/
sfr   INT0F   = 0XBA; 	//INT0 �½����жϿ��ƼĴ���
sfr   INT0R   = 0XBB; 	//INT0 �Ͻ����жϿ��ƼĴ���
sfr   INT1F   = 0XBC; 	//INT1 �½����жϿ��ƼĴ���
sfr   INT1R   = 0XBD; 	//INT1 �Ͻ����жϿ��ƼĴ���
sfr   INT2F   = 0XC6; 	//INT2 �½����жϿ��ƼĴ���
sfr   INT2R   = 0XC7; 	//INT2 �Ͻ����жϿ��ƼĴ���

/*PGA*/


/*IAP */
sfr   IAPCTL	= 0xF6;		//IAP���ƼĴ���
sfr   IAPDAT	= 0xF5;		//IAP���ݼĴ���
sfr   IAPADE  = 0xF4;   //IAP��չ��ַ�Ĵ���
sfr   IAPADH	= 0xF3;		//IAPд���ַ��λ�Ĵ���
sfr   IAPADL	= 0xF2;		//IAPд���ַ��8λ�Ĵ���
sfr   IAPKEY	= 0xF1;		//IAP�����Ĵ���

/*UART*/
sfr     SCON    = 0X98;  	//���ڿ��ƼĴ���
sfr     SBUF    = 0X99;  	//�������ݻ���Ĵ���

/*SPI*/
sfr     SSCON0  = 0X9D;         //SPI���ƼĴ���0
sfr     SSCON1  = 0X9E;         //SPI���ƼĴ���1
sfr     SSCON2  = 0X95;         //SPI���ƼĴ���2
sfr     SSDAT   = 0X9F;         //SPI���ݼĴ���

sfr     OPINX   = 0XFE; 
sfr     OPREG   = 0XFF;
sfr     EXADH   = 0XF7;

/*Check Sum*/
sfr     CHKSUML = 0XFC;        //Check Sum����Ĵ�����λ
sfr     CHKSUMH = 0XFD;	       //Check Sum����Ĵ�����λ

/*ģ��Ƚ���*/
sfr     CMPCFG  = 0XB6;	       //ģ��Ƚ������üĴ���
sfr     CMPCON  = 0XB7;	       //ģ��Ƚ������ƼĴ���

/*�˳�����*/
sfr     EXA0    = 0xE9;        //��չ�ۼ���0
sfr     EXA1    = 0xEA;        //��չ�ۼ���1
sfr     EXA2    = 0xEB;        //��չ�ۼ���2
sfr     EXA3    = 0xEC;        //��չ�ۼ���3
sfr     EXBL    = 0xED;        //��չB�Ĵ���0
sfr     EXBH    = 0xEE;        //��չB�Ĵ���1
sfr     OPERCON = 0xEF;        //������ƼĴ���

///* ------------------- λ�Ĵ���-------------------- */
/*B*/
/*TKCON*/
/*ACC*/
/*PSW*/
sbit 	CY	= PSW^7;	//��־λ		0:�ӷ��������λ�޽�λ�����߼����������λ�޽�λʱ		1:�ӷ��������λ�н�λ�����߼����������λ�н�λʱ
sbit 	AC	= PSW^6;	//��λ������־λ	0:�޽�λ����λ		1:�ӷ�����ʱ��bit3λ�н�λ�������������bit3λ�н�λʱ
sbit 	F0	= PSW^5;	//�û���־λ
sbit 	RS1	= PSW^4;	//�����Ĵ�����ѡ��λ
sbit 	RS0	= PSW^3;	//�����Ĵ�����ѡ��λ
sbit 	OV	= PSW^2;	//�����־λ
sbit 	F1	= PSW^1;	//F1��־
sbit 	P	  = PSW^0;	//��ż��־λ		0:ACC��1�ĸ���Ϊż��������0����		1:ACC��1�ĸ���Ϊ����

/*T2CON*/
sbit  TF2   = T2CON^7;
sbit  EXF2	= T2CON^6;
sbit  RCLK  = T2CON^5;
sbit  CLK	  = T2CON^4;
sbit  EXEN2	= T2CON^3;
sbit  TR2	  = T2CON^2;
sbit  T2    = T2CON^1;
sbit  CP	  = T2CON^0;


/*IP*/
sbit 	IPADC   = IP^6;		//ADC�ж����ȿ���λ	0:�趨 ADC���ж�����Ȩ�� ���͡�		1:�趨 ADC���ж�����Ȩ�� ���ߡ�
sbit	IPT2	  = IP^5;		//PWM�ж����ȿ���λ	0:�趨 PWM���ж�����Ȩ�� ���͡�		1:�趨 PWM ���ж�����Ȩ�� ���ߡ�
sbit 	IPUART	= IP^4;		//SIF�ж����ȿ���λ	0:�趨 SIF���ж�����Ȩ�� ���͡�		1:�趨 SIF���ж�����Ȩ�� ���ߡ�
sbit 	IPT1	  = IP^3;		//Timer1�ж����ȿ���λ	0:�趨 Timer 1���ж�����Ȩ�� ���͡�	1:�趨 Timer 1���ж�����Ȩ�� ���ߡ�
sbit	IPINT1	= IP^2;		//32K Base Timer�ж����ȿ���λ		0:�趨 32K���ж�����Ȩ�� ���͡�		1:�趨 32K���ж�����Ȩ�� ���ߡ�
sbit 	IPT0	  = IP^1;		//Timer0�ж����ȿ���λ	0:�趨 Timer 0���ж�����Ȩ�� ���͡�	1:�趨 Timer 0���ж�����Ȩ�� ���ߡ�
sbit	IPINT0	= IP^0;

/*IE*/
sbit 	EA	  = IE^7;		//�ж�ʹ�ܵ��ܿ���	0:�ر����е��ж�	1:�����е��ж�
sbit 	EADC	= IE^6;		//ADC�ж�ʹ�ܿ���	0:�ر�ADC�ж�		1:��ADC�ж�
sbit 	ET2 	= IE^5;		//PWM�ж�ʹ�ܿ���	0:�ر�PWM�ж�		1:��PWM�ж�
sbit	EUART = IE^4;		//UART�ж�ʹ�ܿ���	0:�ر�SIF�ж�		1:��SIF�ж�
sbit 	ET1 	= IE^3;		//Timer1�ж�ʹ�ܿ���	0:�ر�TIMER1�ж�	1:��TIMER1�ж�
sbit	EINT1	= IE^2;		//32K Base Timer�ж�ʹ�ܿ���	0:�ر�32K�ж�		1:��32K�ж�	
sbit 	ET0	  = IE^1;		//Timer0�ж�ʹ�ܿ���	0:�ر�TIMER0�ж�	1:��TIMER0�ж�
sbit	EINT0	= IE^0;		//TouchKey���ж�ʹ�ܿ���	0:�ر�TouchKey�ж�  1:��TouchKey�ж�

/*TCON*/
sbit 	TF1	= TCON^7;	//T1����ж������־λ	T1��������������ж�ʱ��Ӳ����TF1��Ϊ��1���������жϣ�CPU��Ӧʱ��Ӳ���塰0����
sbit 	TR1	= TCON^6;	//��ʱ��T1�����п���λ	0:Timer1��ֹ����		1:Timer1��ʼ����
sbit 	TF0	= TCON^5;	//T0����ж������־λ	T0��������������ж�ʱ��Ӳ����TF0��Ϊ��1���������жϣ�CPU��Ӧʱ��Ӳ���塰0����
sbit 	TR0	= TCON^4;	//��ʱ��T0�����п���λ	0:Timer0��ֹ����		1:Timer0��ʼ����

/*SCON*/
sbit	SM0	= SCON^7;
sbit	SM1	= SCON^6;
sbit	SM2	= SCON^5;
sbit	REN	= SCON^4;
sbit	TB8	= SCON^3;
sbit	RB8	= SCON^2;
sbit	TI	= SCON^1;
sbit	RI	= SCON^0;

/******************* P0 ******************
*SC92F7547��װδ�����Ĺܽţ���
*SC92F7546��װδ�����Ĺܽţ���
*SC92F7545��װδ�����Ĺܽţ�P00
*SC92F7543��װδ�����Ĺܽţ�P00/P01
******************************************/
sbit 	P07	= P0^7;
sbit 	P06	= P0^6;
sbit 	P05	= P0^5;
sbit 	P04	= P0^4;
sbit 	P03	= P0^3;
sbit 	P02	= P0^2;
sbit 	P01	= P0^1;
sbit 	P00	= P0^0;

/******************* P1 ******************
*SC92F7547��װδ�����Ĺܽţ���
*SC92F7546��װδ�����Ĺܽţ���
*SC92F7545��װδ�����Ĺܽţ���
*SC92F7543��װδ�����Ĺܽţ�P10/P14/P15/P16/P17
******************************************/
sbit 	P17	= P1^7;
sbit 	P16	= P1^6;
sbit 	P15	= P1^5;
sbit 	P14	= P1^4;
sbit 	P13	= P1^3;
sbit 	P12	= P1^2;
sbit 	P11	= P1^1;
sbit 	P10	= P1^0;

/******************* P2 ******************
*SC92F7547��װδ�����Ĺܽţ���
*SC92F7546��װδ�����Ĺܽţ���
*SC92F7545��װδ�����Ĺܽţ���
*SC92F7543��װδ�����Ĺܽţ�P26/P27
******************************************/
sbit 	P27	= P2^7;
sbit 	P26	= P2^6;
sbit 	P25	= P2^5;
sbit 	P24	= P2^4;
sbit 	P23	= P2^3;
sbit 	P22	= P2^2;
sbit 	P21	= P2^1;
sbit 	P20	= P2^0;

/******************* P3 ******************
*SC92F7547��װδ�����Ĺܽţ���
*SC92F7546��װδ�����Ĺܽţ���
*SC92F7545��װδ�����Ĺܽţ�P3
*SC92F7543��װδ�����Ĺܽţ���
******************************************/
sbit 	P37	= P3^7;
sbit 	P36	= P3^6;
sbit 	P35	= P3^5;
sbit 	P34	= P3^4;
sbit 	P33	= P3^3;
sbit 	P32	= P3^2;
sbit 	P31	= P3^1;
sbit 	P30	= P3^0;

/******************* P4 ******************
*SC92F7547��װδ�����Ĺܽţ���
*SC92F7546��װδ�����Ĺܽţ�P46/P47
*SC92F7545��װδ�����Ĺܽţ�P40
*SC92F7543��װδ�����Ĺܽţ�P40/P44/P45/P46/P47
******************************************/
sbit 	P47	= P4^7;
sbit 	P46	= P4^6;
sbit 	P45	= P4^5;
sbit 	P44	= P4^4;
sbit 	P43	= P4^3;
sbit 	P42	= P4^2;
sbit 	P41	= P4^1;
sbit 	P40	= P4^0;

/******************* P5 ******************
*SC92F7547��װδ�����Ĺܽţ���
*SC92F7546��װδ�����Ĺܽţ�P54/P55
*SC92F7545��װδ�����Ĺܽţ�P5
*SC92F7543��װδ�����Ĺܽţ�P5
******************************************/
sbit 	P55	= P5^5;
sbit 	P54	= P5^4;
sbit 	P53	= P5^3;
sbit 	P52	= P5^2;
sbit 	P51	= P5^1;
sbit 	P50	= P5^0;

/****************************************************************************
*ע�⣺��װδ�����Ĺܽţ�������Ϊǿ�������ģʽ
*ICѡ�ͣ��������ʹ�õ�IC�ͺ�,�ڳ�ʼ����IO�ں󣬵������Ӧ��δ�����ܽŵ�IO������;
*����ѡ��SC92F7547�����õ��ú궨�塣
*****************************************************************************/                                    
#define  SC92F7546_IO_Init()   {P4CON|=0xC0,P5CON|=0x30;}                                                 //SC92F7546��δ��������IO������
#define  SC92F7545_IO_Init()   {P0CON|=0x01,P3CON|=0xFF,P4CON|=0x01,P5CON|=0xFF;}                         //SC92F7545��δ��������IO������
#define  SC92F7543_IO_Init()   {P0CON|=0x03,P1CON|=0xF1,P2CON|=0xC0,P4CON|=0xF1,P5CON|=0xFF;}             //SC92F7543��δ��������IO������
#endif