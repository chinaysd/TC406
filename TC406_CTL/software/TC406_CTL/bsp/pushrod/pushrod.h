#ifndef PUSHROD_H_
#define PUSHROD_H_

#include "sys_config.h"
/*
	@brief : ÍÆ¸Ëµ×²ãÇý¶¯
	@version:V5.0
	@author:marco
*/


/*
	@brief:	key mode:do not need to delay ;other mode:need to delay
			push rod do not need the reversing latency 
*/
//#define PUSHROD_REVERSING_DELAY

/**
	@function: Push rod changes direction delay time.
*/
#define PUSH_SWITCH_DELAY_VALUE			300		  //ms

/*
	@function: reverse switch
			defaults to shut down
	@brief: can use a switch ,to control the push rod reverse
*/
//#define PUSHROD_REVERSE_SWITCH	

/*
	@function :get push rod running status 
*/
#define PUSHROD_GET_RUNNING_STATUS	

/**
	@function: The number of the push rod
*/
#define PUSHROD_NUM						(6)

/*	@brief : for initial push rod 
	@example :	Push_Para_t PushRod[2];
				PushRod[PUSHROD_A] = PushRod[0]
				PushRod[PUSHROD_B] = PushRod[1]
*/
#define PUSHROD_A						(0)
#define PUSHROD_B						(1)
#define PUSHROD_C						(2)
#define PUSHROD_D						(3)
#define PUSHROD_E						(4)
#define PUSHROD_F						(5)

typedef enum{
	PUSH_STOP = 0,
	PUSH_OPEN,
	PUSH_CLOSE
}Push_Status_t;

typedef struct{
	unsigned char id;
	#ifdef PUSHROD_REVERSE_SWITCH
	unsigned char ReverseFlag;
	#endif
	#ifdef PUSHROD_GET_RUNNING_STATUS
	unsigned char IsRun;
	#endif
	Push_Status_t Sta;
}Push_Para_t;





INT8U Pushrod_Init(Push_Para_t *para);
void Pushrod_Handle(Push_Para_t *para);
void Pushrod_SetSta(Push_Para_t *para,Push_Status_t sta);
#ifdef PUSHROD_REVERSE_SWITCH
void Pushrod_SetReverseFlag(Push_Para_t *para,INT8U flag);
#endif
#ifdef PUSHROD_GET_RUNNING_STATUS
INT8U Pushrod_GetRunFlag(Push_Para_t *para);
#endif

