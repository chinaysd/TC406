#include "pushrod.h"
#include "timeout.h"
#include "sys_config.h"

XDATA TIMEOUT_PARA Pushrod_Timer[PUSHROD_NUM];

INT8U Pushrod_Init(Push_Para_t *para){
	extern  INT8U Pushrod_PortInit(INT8U id);

	return Pushrod_PortInit(para->id);
}

static INT8U Pushrod_Set(INT8U id,Push_Status_t sta){
	extern INT8U Pushrod_PortSet(INT8U id,INT8U sta);

	return Pushrod_PortSet(id,sta);
}

static INT8U Pushrod_Open(Push_Para_t *para){
	if(para->id> PUSHROD_NUM)
		return 0;
	para->Sta = PUSH_OPEN;
	
	#ifdef PUSHROD_GET_RUNNING_STATUS
		para->IsRun = True;
	#endif
	
	return Pushrod_Set(para->id, PUSH_OPEN);
}

static INT8U Pushrod_Close(Push_Para_t *para){
	if(para->id > PUSHROD_NUM)
		return 0;
	para->Sta = PUSH_CLOSE;
	
	#ifdef PUSHROD_GET_RUNNING_STATUS
		para->IsRun = True;
	#endif
	
	return Pushrod_Set(para->id, PUSH_CLOSE);
}

static INT8U Pushrod_Stop(Push_Para_t *para){
	if(para->id > PUSHROD_NUM)
		return 0;
	para->Sta = PUSH_STOP;
	
	#ifdef PUSHROD_GET_RUNNING_STATUS
		para->IsRun = False;
	#endif
	
	return Pushrod_Set(para->id, PUSH_STOP);
}

void Pushrod_Handle(const Push_Para_t *para){
#ifdef PUSHROD_REVERSING_DELAY	
	Push_Status_t cur_sta = para->Sta;
	static INT8U flag[PUSHROD_NUM] = {0};
	
	#ifdef PUSHROD_REVERSE_SWITCH
	if(para->Sta!= cur_sta && !para->ReverseFlag){
	#else
	if(para->Sta!= cur_sta){
	#endif
	
		if(!flag[para->id]){
			flag[para->id] = True;
			TimeOut_Record(&Pushrod_Timer[para->id], PUSH_SWITCH_DELAY_VALUE);
			Pushrod_Stop(para);
		}
	}else{
		flag[para->id] = True;
		
		if(cur_sta== PUSH_STOP){
			Pushrod_Stop(para);
		}else if(cur_sta == PUSH_OPEN){
			#ifdef PUSHROD_REVERSE_SWITCH
			if(para->ReverseFlag){
				Pushrod_Close(para);
			}else{
				Pushrod_Open(para);
			}
			#else
			Pushrod_Open(p);
			#endif
		}else if(cur_sta == PUSH_CLOSE){
			#ifdef PUSHROD_REVERSE_SWITCH
			if(para->ReverseFlag){
				Pushrod_Open(para);
			}else{
				Pushrod_Close(para);
			}
			#else
			Pushrod_Close(para);
			#endif
		}
	}
	
	if(TimeOutDet_Check(&Pushrod_Timer[para->id])){
		flag[para->id] = False;
		
		if(cur_sta== PUSH_STOP){
			Pushrod_Stop(para);
		}else if(cur_sta == PUSH_OPEN){
			#ifdef PUSHROD_REVERSE_SWITCH
			if(para->ReverseFlag){
				Pushrod_Close(para);
			}else{
				Pushrod_Open(para);
			}
			#else
			Pushrod_Open(para);
			#endif
		}else if(cur_sta == PUSH_CLOSE){
			#ifdef PUSHROD_REVERSE_SWITCH
			if(para->ReverseFlag){
				Pushrod_Open(para);
			}else{
				Pushrod_Close(para);
			}
			#else
			Pushrod_Close(para);
			#endif
		}	
	}
}
#else
	if(!para)
		return ;
	
	if(para->Sta == PUSH_STOP){
		Pushrod_Stop(para);
	}else if(para->Sta == PUSH_OPEN){
		#ifdef PUSHROD_REVERSE_SWITCH
			if(para->ReverseFlag){
				Pushrod_Close(para);
			}else{
				Pushrod_Open(para);
			}
		#else
			Pushrod_Open(para);
		#endif
	}else if(para->Sta == PUSH_CLOSE){
		#ifdef PUSHROD_REVERSE_SWITCH
			if(para->ReverseFlag){
				Pushrod_Open(para);
			}else{
				Pushrod_Close(para);
			}
		#else
			Pushrod_Close(para);
		#endif
	}else{
		return;
	}
}
#endif

void Pushrod_SetSta(Push_Para_t *para,Push_Status_t sta){
	if(!para)
		return;
	para->Sta = sta;
}

#ifdef PUSHROD_REVERSE_SWITCH
void Pushrod_SetReverseFlag(Push_Para_t *para,INT8U flag){
	if(!para)
		return ;
	para->ReverseFlag = flag;
}
#endif

#ifdef PUSHROD_GET_RUNNING_STATUS
INT8U Pushrod_GetRunFlag(Push_Para_t *para){
	if(!para)
		return 0;
	return para->IsRun;
}
#endif
