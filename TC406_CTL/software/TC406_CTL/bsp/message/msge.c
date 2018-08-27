#include "msge.h"

static  XDATA INT8U Motor_Ctr[MSGE_NUM][2];
static  XDATA INT8U FreCnt[MSGE_NUM],Mode_SwCnt[MSGE_NUM];
static  XDATA INT16U TimeCnt[MSGE_NUM],TimeCntFlag[MSGE_NUM];
static  XDATA INT16U AutoSwitchCnt[MSGE_NUM];

extern INT8U Msge_PortSet(INT8U id,INT8U num,INT8U set);

INT8U Msge_Init(Msge_Para_t *para){
	extern INT8U Msge_PortInit(INT8U id);
	return Msge_PortInit(para->id);
}

void Msge_Handle(Msge_Para_t *para){	
	if(!para)
		return ;
	
	/*模式自动切换*/
	if(para->mode_sw_type){
		if(AutoSwitchCnt[para->id]  > M_SWITCH_VALUES){
			AutoSwitchCnt[para->id] = 0; 
			TimeCnt[para->id] = 0;
			if(para->mode ++ > M_MODE_3){
				Mode_SwCnt[para->id] = 0;
				para->mode = M_MODE_1;
			}
		}
	}
	
	switch(para->mode){
		case M_MODE_1:{
			TimeCntFlag[para->id] = True;
			if(TimeCnt[para->id] > M_500MS){	
				
				TimeCnt[para->id] = 0;
				
				if(Mode_SwCnt[para->id] ++ >= 2){
					Mode_SwCnt[para->id] = 0;
				}

				Motor_Ctr[para->id][0] = (Mode_SwCnt[para->id] == 0) ? True:False;
				Motor_Ctr[para->id][1] = (Mode_SwCnt[para->id] == 1) ? True:False;

			}
			break;
		}

		case M_MODE_2:{
			TimeCntFlag[para->id] = True;
			if(TimeCnt[para->id] > M_1S){
				Mode_SwCnt[para->id] = !Mode_SwCnt[para->id];
				Motor_Ctr[para->id][0] = (Mode_SwCnt[para->id]) ? True:False;
				Motor_Ctr[para->id][1] = !Motor_Ctr[para->id][0];
				TimeCnt[para->id] = 0;
			}
			break;
		}

		case M_MODE_3:{
			TimeCntFlag[para->id] = True;
			if(TimeCnt[para->id] > M_1S){
				TimeCnt[para->id] = 0;
				
				Mode_SwCnt[para->id] =!Mode_SwCnt[para->id];
				
				Motor_Ctr[para->id][0] = (Mode_SwCnt[para->id]) ? True:False;
				Motor_Ctr[para->id][1] = (Mode_SwCnt[para->id]) ? True:False;
			}
			break;
		}
		default:{
			para->mode = M_MODE_1;
			break;
		}
	}
	return ;
}

/*****************************************************************************
 * Function	  : Msge_TimeHandle
 * Description   : 定时器里面处理，时基1ms
 * Input           : void  
 * Output		  : None
 * Return		  : 
 * Others		  : 
 * Record
 * 1.Date		  : 20180420
 *   Author       : marco
 *   Modification: Created function

*****************************************************************************/
void Msge_TimeHandle(Msge_Para_t *para){
	if(!para)
		return ;
	if(para->sw_sta){
		FreCnt[para->id] ++;
		
		if(FreCnt[para->id] < para->intensity){
			if(Motor_Ctr[para->id][0]){
				Msge_PortSet(para->id,0,1);
			}else{
				Msge_PortSet(para->id,0,0);
			}
			if(Motor_Ctr[para->id][1]){
				Msge_PortSet(para->id,1,1);
			}else{
				Msge_PortSet(para->id,1,0);
			}
		}else {
			Msge_PortSet(para->id,0,0);
			Msge_PortSet(para->id,1,0);
			if(FreCnt[para->id] > 13){				
				FreCnt[para->id] = 0;
			}
		}

		/*模式计时*/
		if(TimeCntFlag[para->id]){
			TimeCnt[para->id] ++;
		}
		
		if(para->mode_sw_type){
			AutoSwitchCnt[para->id] ++;
		}
	}	
}

void Msge_SetIntensity(Msge_Para_t *para,INT8U set){
	if(!para)
		return ;
	para->intensity = set;
}

void Msge_SetMode(Msge_Para_t *para,INT8U set){
	if(!para)
		return ;
	para->mode = set;
	Mode_SwCnt[para->id] = 0; 
}

void Msge_Open(Msge_Para_t *para,INT8U run_type){
	para->sw_sta = True;
	para->mode_sw_type = run_type;
	para->mode = M_MODE_1;
	AutoSwitchCnt[para->id] = 0;
	TimeCnt[para->id] = 0; 
	TimeCntFlag[para->id] = 0;
	FreCnt[para->id] = 0;
	Mode_SwCnt[para->id] = 0;
}

void Msge_Close(Msge_Para_t *para){
	para->sw_sta = False;
	Msge_PortSet(para->id,1,0);
	Msge_PortSet(para->id,0,0);
}

INT8U Msge_GetRunSta(Msge_Para_t *para){
	return para->sw_sta;
}