#ifndef MSGE_H_
#define MSGE_H_

#include "sys_config.h"

/**
	@brief:The intensity of the motor
*/
#define MIN_INTENSITY_VALUE						0
#define MAX_INTENSITY_VALUE						3

#define MSGE_NUM								2

/**
	@breif:Motor toggle time definition.
*/
#define M_500MS									500			
#define M_1S										1000			
#define M_SWITCH_VALUES							60000		

/**
	@brief:mode definition
*/
enum{
	M_MODE_1 =0,
	M_MODE_2,
	M_MODE_3
};

/**
	@breif:Mode control type
*/
enum{
	MANUAL_CTR = 0,
	AUTO_CTR
};

typedef struct{
	INT8U id;
	INT8U intensity;						/*<Motor strength value>*/
	INT8U mode_sw_type;					/*<Motor mode switching mode.>*/
	INT8U sw_sta;						/*<switch>*/
	INT8U mode;
}Msge_Para_t;
















INT8U Msge_Init(Msge_Para_t *para);
void Msge_Handle(Msge_Para_t *para);
void Msge_TimeHandle(Msge_Para_t *para);
void Msge_SetIntensity(Msge_Para_t *para,INT8U set);
void Msge_SetMode(Msge_Para_t *para,INT8U set);
void Msge_Open(Msge_Para_t *para,INT8U run_type);
void Msge_Close(Msge_Para_t *para);
INT8U Msge_GetRunSta(Msge_Para_t *para);


#endif
