#include "app.h"
#include "msge.h"
#include "bsp_timer.h"
#include "timeout.h"
#include "sys_config.h"
#include <string.h>


XDATA App_Para_t App_Para;
XDATA Push_Para_t Push_Para[PUSHROD_NUM];
XDATA Msge_Para_t Msge_Para[MSGE_NUM];
extern  Bsp_Tx_t Tx_Buf[UART_NUM];
TIMEOUT_PARA Poll_SentTime; 

INT8U i;
unsigned char PUSH1_SWITCH_FLAG;
unsigned int  PUSH1_SWITCH_CNT;
unsigned char PUSH1_SWITCH_CNT_FLAG;
unsigned char PUSH2_SWITCH_FLAG;
unsigned int  PUSH2_SWITCH_CNT;
TIMEOUT_PARA Shake_Time[2];


#define APP_CLR_SYS_CLS()			(App_Para.system_auto_clscnt = 0)

void App_SetLed(INT8U id,INT16U set){
	App_Para.led_sta[id] |= set & 0xffff;
}

void App_ClrLed(INT8U id,INT16U clr){
	App_Para.led_sta[id] &= ~(clr & 0xffff);
}

void App_FootLedSet(INT8U id,INT8U set){
	if(id == 0){
		FOOT1_LED = set;
	}else if(id == 1){
		FOOT2_LED = set;
	}
}

void App_HeatSet(INT8U id,INT8U set){
	if(id == 0){
		HEAT1_PIN = set;
	}else if(id == 1){
		HEAT2_PIN = set;
	}
}

void App_Init(void){
	for(i = 0;i < PUSHROD_NUM;i++){
		Push_Para[i].id = i;
		Push_Para[i].IsRun = False;
		Push_Para[i].Sta = PUSH_STOP;
		Pushrod_Init(&Push_Para[i]);
	}
	
	for(i = 0; i < MSGE_NUM;i ++){
		Msge_Para[i].id = i;
		Msge_Para[i].intensity = 7;
		Msge_Para[i].mode = AUTO_CTR;
		Msge_Para[i].sw_sta = False;
		Msge_Init(&Msge_Para[i]);
	}

	for(i = 0;i < UART_NUM;i ++){
		Bsp_UartInit(i);
	}
	
	/*led*/
	SET_REG_CON(1,0);
	SET_REG_CON(1,4);
	/*heat*/
	SET_REG_CON(4,1);
	SET_REG_CON(4,2);
	
	App_FootLedSet(FOOT_ID0,OFF);
	App_FootLedSet(FOOT_ID1,OFF);

	App_HeatSet(HEAT_ID0, OFF);	
	App_HeatSet(HEAT_ID1, OFF);

	TimeOutDet_Init();

	Bsp_Timer0Init();
	memset(&App_Para,0,sizeof(App_Para_t));
	EA = 1;
}

static int App_SentMsg(INT8U id,unsigned int cont){    
	memset((void*)&App_Para.send_buf[0],0,BSP_UART_SIZE);
	App_Para.send_buf[0] = START_FIELD;
	App_Para.send_buf[1] = MSG_ID;
	App_Para.send_buf[2] = Get_High(cont);
	App_Para.send_buf[3] = Get_Low(cont);
	App_Para.send_buf[4] = (INT8U)(App_Para.send_buf[0] +App_Para.send_buf[1]+App_Para.send_buf[2]+App_Para.send_buf[3]);
	App_Para.send_buf[5] = Get_High(STOP_MESSAGE);
	App_Para.send_buf[6] = Get_Low(STOP_MESSAGE);
	Bsp_UartSendBuf(id,&App_Para.send_buf[0],BSP_UART_SIZE);
	return 0; 
} 

/**
	@brief:按键功能
*/
void App_HeatHandle(INT8U id){
	if(App_Para.warn_sta[id]){
		App_Para.warn_sta[id] = OFF;
		App_HeatSet(id, OFF);
		App_ClrLed(id, LED8_VALUE);
		App_Para.warn_auto_clsflag[id] = False;
		App_Para.warn_auto_clscnt[id] = 0;
	}else{
		App_Para.warn_sta[id] = ON;
		App_HeatSet(id, ON);
		App_SetLed(id, LED8_VALUE);
		App_Para.warn_auto_clsflag[id] = True;
		App_Para.warn_auto_clscnt[id] = 0;
	}
}

void App_MsgeHandle(INT8U id){
	if(App_Para.msge_sta[id]){
		App_Para.msge_sta[id] = OFF;		
		Msge_Close(&Msge_Para[id]);
		App_ClrLed(id, LED9_VALUE);
		App_Para.msge_auto_clsflag[id] = False;
		App_Para.msge_auto_clscnt[id] = 0;
	}else{
		App_Para.msge_sta[id] = ON;
		Msge_Open(&Msge_Para[id], AUTO_CTR);
		App_SetLed(id, LED9_VALUE);
		App_Para.msge_auto_clsflag[id] = True;
		App_Para.msge_auto_clscnt[id] = 0;
	}
}

void App_LedHandle(INT8U id){
	if(App_Para.foot_ledsta[id]){
		App_Para.foot_ledsta[id] = OFF;
		App_FootLedSet(id, OFF);
		App_ClrLed(id, LED10_VALUE);
	}else{
		App_Para.foot_ledsta[id] = ON;
		App_FootLedSet(id, ON);
		App_SetLed(id, LED10_VALUE);
	}
}

void App_PushAOpenHandle(void){
	Pushrod_SetSta(&Push_Para[PUSHROD_A], PUSH_OPEN);
}

void App_PushBOpenHandle(void){
	Pushrod_SetSta(&Push_Para[PUSHROD_B], PUSH_OPEN);
}

void App_PushCOpenHandle(void){
	Pushrod_SetSta(&Push_Para[PUSHROD_C], PUSH_OPEN);
}

void App_PushDOpenHandle(void){
	Pushrod_SetSta(&Push_Para[PUSHROD_D], PUSH_OPEN);
}

void App_PushEOpenHandle(void){
	Pushrod_SetSta(&Push_Para[PUSHROD_E], PUSH_OPEN);
}

void App_PushFOpenHandle(void){
	Pushrod_SetSta(&Push_Para[PUSHROD_F], PUSH_OPEN);
}

void App_PushACloseHandle(void){
	Pushrod_SetSta(&Push_Para[PUSHROD_A], PUSH_CLOSE);
}

void App_PushBCloseHandle(void){
	Pushrod_SetSta(&Push_Para[PUSHROD_B], PUSH_CLOSE);
}

void App_PushCCloseHandle(void){
	Pushrod_SetSta(&Push_Para[PUSHROD_C], PUSH_CLOSE);
}

void App_PushDCloseHandle(void){
	Pushrod_SetSta(&Push_Para[PUSHROD_D], PUSH_CLOSE);
}

void App_PushECloseHandle(void){
	Pushrod_SetSta(&Push_Para[PUSHROD_E], PUSH_CLOSE);
}

void App_PushFCloseHandle(void){
	Pushrod_SetSta(&Push_Para[PUSHROD_F], PUSH_CLOSE);
}

/**
	@brief:按键处理入口
*/
void Key1_Handle(INT8U id){
	if(id == BSP_UART0_ID){
		App_PushAOpenHandle();
		App_SetLed(BSP_UART0_ID,LED1_VALUE);
	}else{
		App_PushDOpenHandle();
		App_SetLed(BSP_UART1_ID,LED1_VALUE);
	}
}

void Key2_Handle(INT8U id){
	if(id == BSP_UART0_ID){
		App_PushACloseHandle();
		App_SetLed(BSP_UART0_ID,LED2_VALUE);
	}else{
		App_PushDCloseHandle();
		App_SetLed(BSP_UART1_ID,LED2_VALUE);
	}
}

/**
	@brief:按下复位
*/
void delay_ms(unsigned int time)
{
    unsigned int i,j;
	for(i=time;i>0;i--)
	{
	   for(j=120;j>0;j--);
	}
}
void Key3_Handle(INT8U id){
	App_Para.reset_sta[id] = True;
	if(id == BSP_UART0_ID){			
		App_PushAOpenHandle();
		#if 0
		//FOOT1_LED = 1;
		delay_ms(5000);
			//PUSH1_SWITCH_FLAG = 1;
			//FOOT1_LED = 1;
			//if(PUSH1_SWITCH_CNT_FLAG)
			//{
			   //FOOT2_LED = 1;
			   //PUSH1_SWITCH_CNT = 0;
			   //PUSH1_SWITCH_CNT_FLAG = 0;
			   //PUSH1_SWITCH_FLAG = 0;
			   App_PushBOpenHandle();
			   //App_PushCOpenHandle();
			//}
		 #endif
		App_PushBOpenHandle();
		App_PushCOpenHandle();
		App_SetLed(BSP_UART0_ID, LED3_VALUE);
	}else{
		App_PushDOpenHandle();
		#if 0
		PUSH2_SWITCH_FLAG = 1; 
		if(PUSH2_SWITCH_CNT == 500)
		{
		  PUSH2_SWITCH_CNT = 0;
		  PUSH2_SWITCH_FLAG = 0; 
		  //App_PushEOpenHandle();
		  //App_PushFOpenHandle();
		}
		#endif
		App_PushEOpenHandle();
		App_PushFOpenHandle();
		App_SetLed(BSP_UART1_ID, LED3_VALUE);
	}
}

void Key4_Handle(INT8U id){
	if(id == BSP_UART0_ID){
		App_PushBOpenHandle();
		App_SetLed(BSP_UART0_ID, LED4_VALUE);
	}else{
		App_PushEOpenHandle();
		App_SetLed(BSP_UART1_ID, LED4_VALUE);
	}
}

void Key5_Handle(INT8U id){
	if(id == BSP_UART0_ID){
		App_PushBCloseHandle();
		App_SetLed(BSP_UART0_ID, LED5_VALUE);
	}else{
		App_PushECloseHandle();
		App_SetLed(BSP_UART1_ID, LED5_VALUE);
	}
}

void Key6_Handle(INT8U id){
	if(id == BSP_UART0_ID){
		App_PushCOpenHandle();
		App_SetLed(BSP_UART0_ID, LED6_VALUE);
	}else{
		App_PushFOpenHandle();
		App_SetLed(BSP_UART1_ID, LED6_VALUE);
	}
}

void Key7_Handle(INT8U id){
	if(id == BSP_UART0_ID){
		App_PushCCloseHandle();
		App_SetLed(BSP_UART0_ID, LED7_VALUE);
	}else{
		App_PushFCloseHandle();
		App_SetLed(BSP_UART1_ID, LED7_VALUE);
	}
}

void Key8_Handle(INT8U id){
	App_HeatHandle(id);
}

void Key9_Handle(INT8U id){
	App_MsgeHandle(id);
}

void Key10_Handle(INT8U id){
	App_LedHandle(id);
}

static void App_KeyHandle(void){
	for(i = 0; i < 2 ;i++){
		switch(App_Para.get_key[i]){
			case TK1_VALUE:{
				if(App_Para.cur_key[i] != TK1_VALUE){
					App_Para.cur_key[i] = TK1_VALUE;
					Key1_Handle(i);
				}
				break;
			}

			case TK2_VALUE:{
				if(App_Para.cur_key[i] != TK2_VALUE){
					App_Para.cur_key[i] = TK2_VALUE;
					Key2_Handle(i);
				}
				break;
			}

			case TK3_VALUE:{
				if(App_Para.cur_key[i] != TK3_VALUE){
					App_Para.cur_key[i] = TK3_VALUE;
					Key3_Handle(i);
				}
				break;
			}

			case TK4_VALUE:{
				if(App_Para.cur_key[i] != TK4_VALUE){
					App_Para.cur_key[i] = TK4_VALUE;
					Key4_Handle(i);
				}
				break;
			}

			case TK5_VALUE:{
				if(App_Para.cur_key[i] != TK5_VALUE){
					App_Para.cur_key[i] = TK5_VALUE;
					Key5_Handle(i);
				}
				break;
			}

			case TK6_VALUE:{
				if(App_Para.cur_key[i] != TK6_VALUE){
					App_Para.cur_key[i] = TK6_VALUE;
					Key6_Handle(i);
				}
				break;
			}

			case TK7_VALUE:{
				if(App_Para.cur_key[i] != TK7_VALUE){
					App_Para.cur_key[i] = TK7_VALUE;
					Key7_Handle(i);
				}
				break;
			}
			
			case TK8_VALUE:{
				if(App_Para.cur_key[i] != TK8_VALUE){
					App_Para.cur_key[i] = TK8_VALUE;
					Key8_Handle(i);
				}
				break;
			}

			case TK9_VALUE:{
				if(App_Para.cur_key[i] != TK9_VALUE){
					App_Para.cur_key[i] = TK9_VALUE;
					Key9_Handle(i);
				}
				break;
			}

			case TK10_VALUE:{
				if(App_Para.cur_key[i] != TK10_VALUE){
					App_Para.cur_key[i] = TK10_VALUE;
					Key10_Handle(i);
				}
				break;
			}

			default:{
				if(App_Para.cur_key[i]){
					App_Para.cur_key[i] = 0;
					App_ClrLed(i, LED1_VALUE);
					App_ClrLed(i, LED2_VALUE);
					App_ClrLed(i, LED3_VALUE);
					App_ClrLed(i, LED4_VALUE);
					App_ClrLed(i, LED5_VALUE);
					App_ClrLed(i, LED6_VALUE);
					App_ClrLed(i, LED7_VALUE);
					App_Para.reset_sta[i] = False;
					if(i == BSP_UART0_ID){						
						Pushrod_SetSta(&Push_Para[PUSHROD_A],PUSH_STOP);
						Pushrod_SetSta(&Push_Para[PUSHROD_B],PUSH_STOP);
						Pushrod_SetSta(&Push_Para[PUSHROD_C],PUSH_STOP);
					}else{
						Pushrod_SetSta(&Push_Para[PUSHROD_D],PUSH_STOP);
						Pushrod_SetSta(&Push_Para[PUSHROD_E],PUSH_STOP);
						Pushrod_SetSta(&Push_Para[PUSHROD_F],PUSH_STOP);
					}	
				}
				break;
			}
		}
	}
}

void App_Handle(void){	
	#ifdef SYS_ENABLE_WDT
		CLEAR_WDT();
	#endif
	
	App_KeyHandle();
	
	for(i = 0;i < PUSHROD_NUM;i++){
		Pushrod_Handle(&Push_Para[i]);
	}

	for(i = 0; i < MSGE_NUM;i++){
		Msge_Handle(&Msge_Para[i]);
	}

	if(TimeOutDet_Check(&Poll_SentTime)){
		TimeOut_Record(&Poll_SentTime, 50);
		App_SentMsg(BSP_UART0_ID, App_Para.led_sta[0]);
		App_SentMsg(BSP_UART1_ID, App_Para.led_sta[1]);
	}

	/**
		@brief:auto close funciton
	*/
	for(i = 0; i < 2 ;i ++){
		if(App_Para.warn_auto_clscnt[i] >= WARN_AUTO_CLOSE && App_Para.warn_sta[i]){
			App_Para.warn_sta[i] = OFF;
			App_Para.warn_auto_clscnt[i] = 0;
			App_Para.warn_auto_clsflag[i] = 0;
			App_HeatSet(i, OFF);
			App_ClrLed(i, LED8_VALUE);
		}
		if(App_Para.msge_auto_clscnt[i] >= MASS_AUTO_CLOSE && App_Para.msge_sta[i]){
			App_Para.msge_sta[i] = OFF;
			App_Para.msge_auto_clscnt[i] = 0;
			App_Para.msge_auto_clsflag[i] = 0;
			Msge_Close(&Msge_Para[i]);
			App_ClrLed(i, LED9_VALUE);
		}
	}

	if(App_Para.system_auto_clscnt  >= SYSTEM_AUTO_CLOSE && !App_Para.system_shutdw_flag){
		App_Para.system_shutdw_flag = True;
		
	}
	
	/**
		@brief:A key reset function.
	*/
	if(App_Para.reset_sta[0]){
		
	   	
	}
	
	if(App_Para.reset_sta[1]){

	  	
	}

	
}

void Timer0IqrHandle() interrupt 1{
	static unsigned int base_time = 0;
	INT8U j;
	TL0 = (65536 - 1600 + 200)%256;    
	TH0 = (65536 - 1600 + 200)/256;

	TimeOutDet_DecHandle();
	if(PUSH1_SWITCH_FLAG)
	{
	   PUSH1_SWITCH_CNT++;
	   if(PUSH1_SWITCH_CNT == 1000)
	   {
	      PUSH1_SWITCH_CNT_FLAG = 1; 
		  PUSH1_SWITCH_CNT = 0;
	   }
	}
	if(PUSH2_SWITCH_FLAG)
	{
	   PUSH2_SWITCH_CNT++;
	}
	
	for(j = 0; j < MSGE_NUM;j++){
		Msge_TimeHandle(&Msge_Para[j]);
	}

	if(base_time ++ > 1000){
		base_time = 0;
		for(j = 0;j < 2;j ++){
			if(App_Para.warn_auto_clsflag[j]){
				if(App_Para.warn_auto_clscnt[j] ++ > WARN_AUTO_CLOSE){
					App_Para.warn_auto_clsflag[j] = False;
				}
			}

			if(App_Para.msge_auto_clsflag[j]){
				if(App_Para.msge_auto_clscnt[j]++ > MASS_AUTO_CLOSE){
					App_Para.msge_auto_clsflag[j] = False;
				}
			}
		}
		if(App_Para.system_auto_clsflag){
			if(App_Para.system_auto_clscnt ++ > SYSTEM_AUTO_CLOSE){
				App_Para.system_auto_clsflag = False;
			}
		}
	}
}

void Uart0IqrHandle() interrupt 4{
	if(TI){
		TI=0;		
		if(Tx_Buf[UART_NUM0].send_cnt == Tx_Buf[UART_NUM0].len - 1){
			memset((void*)&Tx_Buf[UART_NUM0],0,sizeof(Bsp_Tx_t));
			P02 = 1;
			return ;
		}	
		SBUF = Tx_Buf[UART_NUM0].buf[++Tx_Buf[UART_NUM0].send_cnt];	
	}
	
	if(RI){
		RI = 0;
		App_Para.rev_buf[BSP_UART0_ID].buf[App_Para.rev_buf[BSP_UART0_ID].len ++] = SBUF;
		
		if(App_Para.rev_buf[BSP_UART0_ID].buf[0] != START_FIELD){
			memset((void*)&App_Para.rev_buf[BSP_UART0_ID],0,sizeof(Rev_Buf_t));
			App_Para.get_key[BSP_UART0_ID] = 0;
			return ;
		}
		
		if(App_Para.rev_buf[BSP_UART0_ID].len >= BSP_UART_SIZE){
			if(App_Para.rev_buf[BSP_UART0_ID].buf[1] != MSG_ID){
				memset((void*)&App_Para.rev_buf[BSP_UART0_ID],0,sizeof(Rev_Buf_t));
				App_Para.get_key[BSP_UART0_ID] = 0;
				return ;
			}
			/*<结束符>*/
			if(App_Para.rev_buf[BSP_UART0_ID].buf[BSP_UART_SIZE - 2] != 0x0d || App_Para.rev_buf[BSP_UART0_ID].buf[BSP_UART_SIZE - 1] != 0x0a){
				memset((void*)&App_Para.rev_buf[BSP_UART0_ID],0,sizeof(Rev_Buf_t));
				App_Para.get_key[0] = 0;
				return ;
			}
			
			/*<检验CS>*/
			if(App_Para.rev_buf[BSP_UART0_ID].buf[4] != (App_Para.rev_buf[BSP_UART0_ID].buf[0] + App_Para.rev_buf[BSP_UART0_ID].buf[1] + App_Para.rev_buf[BSP_UART0_ID].buf[2] + App_Para.rev_buf[BSP_UART0_ID].buf[3])){
				memset((void*)&App_Para.rev_buf[BSP_UART0_ID],0,sizeof(Rev_Buf_t));
				App_Para.get_key[0] = 0;
				return ;
			}
			
			App_Para.get_key[BSP_UART0_ID] = (INT16U)App_Para.rev_buf[BSP_UART0_ID].buf[2] << 8 |App_Para.rev_buf[BSP_UART0_ID].buf[3];	
			//App_SentMsg(BSP_UART0_ID,App_Para.get_key[BSP_UART0_ID]);
			memset((void*)&App_Para.rev_buf[BSP_UART0_ID],0,sizeof(Rev_Buf_t));
		}
	}
}

void Bsp_Uart1IqrHandle() interrupt 7{
	unsigned char crc = 0;
	/*<发送数据>*/
	if(SSCON0&0x02){
		SSCON0&=0xFD;
		if(Tx_Buf[UART_NUM1].send_cnt == Tx_Buf[UART_NUM1].len - 1){
			memset((void*)&Tx_Buf[UART_NUM1],0,sizeof(Bsp_Tx_t));
			P13 = 1;
			return ;
		}
			
		SSDAT = Tx_Buf[UART_NUM1].buf[++Tx_Buf[UART_NUM1].send_cnt];	
	}
	/*<接收数据>*/
	if((SSCON0&0x01)){
		SSCON0&=0xFE;
		App_Para.rev_buf[BSP_UART1_ID].buf[App_Para.rev_buf[BSP_UART1_ID].len++] = SSDAT;
		
		if(App_Para.rev_buf[BSP_UART1_ID].buf[0] != START_FIELD){
			memset((void*)&App_Para.rev_buf[BSP_UART1_ID],0,sizeof(Rev_Buf_t));
			App_Para.get_key[BSP_UART1_ID] = 0;
			return ;
		}
		
		if(App_Para.rev_buf[BSP_UART1_ID].len>= BSP_UART_SIZE){
			/*<不是发送到本机的数据，不理会>*/
			if(App_Para.rev_buf[BSP_UART1_ID].buf[1] != MESSAGE_ID){				
				memset((void*)&App_Para.rev_buf[UART_NUM1],0,sizeof(Rev_Buf_t));
				return ;
			}
			/*<结尾符错误>*/
			if(App_Para.rev_buf[UART_NUM1].buf[BSP_UART_SIZE-2] != 0x0d || App_Para.rev_buf[UART_NUM1].buf[BSP_UART_SIZE-1] != 0x0a){
				memset((void*)&App_Para.rev_buf[UART_NUM1],0,sizeof(Rev_Buf_t));
				return ;
			}
			/*<校验错误>*/
			crc = (unsigned char)(App_Para.rev_buf[BSP_UART1_ID].buf[0] + App_Para.rev_buf[BSP_UART1_ID].buf[1] + App_Para.rev_buf[BSP_UART1_ID].buf[2] + App_Para.rev_buf[BSP_UART1_ID].buf[3]);
			if(crc != App_Para.rev_buf[BSP_UART1_ID].buf[4]){
				memset((void*)&App_Para.rev_buf[UART_NUM1],0,sizeof(Rev_Buf_t));
				return ;
			}
			App_Para.get_key[BSP_UART1_ID] = (INT16U)App_Para.rev_buf[BSP_UART1_ID].buf[2] << 8 |App_Para.rev_buf[BSP_UART1_ID].buf[3];	
			//App_SentMsg(BSP_UART1_ID,App_Para.get_key[BSP_UART1_ID]);
			memset((void*)&App_Para.rev_buf[BSP_UART1_ID],0,sizeof(Rev_Buf_t));
		}
	}
}





#endif

