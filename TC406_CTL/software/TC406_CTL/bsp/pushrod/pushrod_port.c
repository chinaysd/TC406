#include "sys_config.h"

/**
	@brief:io definition
*/
#define PUSH1A_PIN				P46
#define PUSH1B_PIN				P47

#define PUSH2A_PIN				P07
#define PUSH2B_PIN				P06

#define PUSH3A_PIN				P05
#define PUSH3B_PIN				P04

#define PUSH4A_PIN				P01
#define PUSH4B_PIN				P27

#define PUSH5A_PIN				P26
#define PUSH5B_PIN				P25

#define PUSH6A_PIN				P24
#define PUSH6B_PIN				P23


#define Set_Push1A_Out(X)			((X)?(PUSH1A_PIN = 1):(PUSH1A_PIN = 0))	
#define Set_Push1B_Out(X)			((X)?(PUSH1B_PIN = 1):(PUSH1B_PIN = 0))	
#define Set_Push2A_Out(X)			((X)?(PUSH2A_PIN = 1):(PUSH2A_PIN = 0))	
#define Set_Push2B_Out(X)			((X)?(PUSH2B_PIN = 1):(PUSH2B_PIN = 0))	
#define Set_Push3A_Out(X)			((X)?(PUSH3A_PIN = 1):(PUSH3A_PIN = 0))	
#define Set_Push3B_Out(X)			((X)?(PUSH3B_PIN = 1):(PUSH3B_PIN = 0))	
#define Set_Push4A_Out(X)			((X)?(PUSH4A_PIN = 1):(PUSH4A_PIN = 0))	
#define Set_Push4B_Out(X)			((X)?(PUSH4B_PIN = 1):(PUSH4B_PIN = 0))	
#define Set_Push5A_Out(X)			((X)?(PUSH5A_PIN = 1):(PUSH5A_PIN = 0))	
#define Set_Push5B_Out(X)			((X)?(PUSH5B_PIN = 1):(PUSH5B_PIN = 0))	
#define Set_Push6A_Out(X)			((X)?(PUSH6A_PIN = 1):(PUSH6A_PIN = 0))	
#define Set_Push6B_Out(X)			((X)?(PUSH6B_PIN = 1):(PUSH6B_PIN = 0))	


INT8U Pushrod_PortInit(INT8U id){
	if(id == 0){
		SET_REG_CON(4,6);
		Set_Push1A_Out(0);
		SET_REG_CON(4,7);
		Set_Push1B_Out(0);
		return 1;
	}else if(id == 1){
		SET_REG_CON(0,7);
		Set_Push2A_Out(0);
		SET_REG_CON(0,6);
		Set_Push2B_Out(0);
	}else if(id == 2){
		SET_REG_CON(0,5);
		Set_Push2A_Out(0);
		SET_REG_CON(0,4);
		Set_Push2B_Out(0);
	}else if(id == 3){
		SET_REG_CON(0,1);
		Set_Push2A_Out(0);
		SET_REG_CON(2,7);
		Set_Push2B_Out(0);
	}else if(id == 4){
		SET_REG_CON(2,6);
		Set_Push2A_Out(0);
		SET_REG_CON(2,5);
		Set_Push2B_Out(0);
	}else if(id == 5){
		SET_REG_CON(2,4);
		Set_Push2A_Out(0);
		SET_REG_CON(2,3);
		Set_Push2B_Out(0);
	}
	return 0;
}

/*****************************************************************************
 * Function	  : Pushrod_PortSet
 * Description   : ÉèÖÃpushrod µ×²ãÇı¶¯IO
 * Input           : INT8U id   
			    INT8U sta  :0->STOP  1->OPEN 2->CLOSE
 * Output		  : None
 * Return		  : 
 * Others		  : 
 * Record
 * 1.Date		  : 20180419
 *   Author       : marco
 *   Modification: Created function

*****************************************************************************/
INT8U Pushrod_PortSet(INT8U id,INT8U sta){
	if(id == 0){
		if(sta == 0){
			Set_Push1A_Out(0),Set_Push1B_Out(0);
			return 1;
		}else if(sta == 1){
			Set_Push1A_Out(0),Set_Push1B_Out(1);
			return 1;
		}else if(sta == 2){
			Set_Push1A_Out(1),Set_Push1B_Out(0);
			return 1;
		}else{
			return 0;
		}
	}else if(id == 1){
		if(sta == 0){
			Set_Push2A_Out(0),Set_Push2B_Out(0);
			return 1;
		}else if(sta == 1){
			Set_Push2A_Out(0),Set_Push2B_Out(1);
			return 1;
		}else if(sta == 2){
			Set_Push2A_Out(1),Set_Push2B_Out(0);
			return 1;
		}else{
			return 0;
		}
	}else if(id == 2){
		if(sta == 0){
			Set_Push3A_Out(0),Set_Push3B_Out(0);
			return 1;
		}else if(sta == 1){
			Set_Push3A_Out(0),Set_Push3B_Out(1);
			return 1;
		}else if(sta == 2){
			Set_Push3A_Out(1),Set_Push3B_Out(0);
			return 1;
		}else{
			return 0;
		}
	}else if(id == 3){
		if(sta == 0){
			Set_Push4A_Out(0),Set_Push4B_Out(0);
			return 1;
		}else if(sta == 1){
			Set_Push4A_Out(0),Set_Push4B_Out(1);
			return 1;
		}else if(sta == 2){
			Set_Push4A_Out(1),Set_Push4B_Out(0);
			return 1;
		}else{
			return 0;
		}
	}else if(id == 4){
		if(sta == 0){
			Set_Push5A_Out(0),Set_Push5B_Out(0);
			return 1;
		}else if(sta == 1){
			Set_Push5A_Out(0),Set_Push5B_Out(1);
			return 1;
		}else if(sta == 2){
			Set_Push5A_Out(1),Set_Push5B_Out(0);
			return 1;
		}else{
			return 0;
		}
	}else if(id == 5){
		if(sta == 0){
			Set_Push6A_Out(0),Set_Push6B_Out(0);
			return 1;
		}else if(sta == 1){
			Set_Push6A_Out(0),Set_Push6B_Out(1);
			return 1;
		}else if(sta == 2){
			Set_Push6A_Out(1),Set_Push6B_Out(0);
			return 1;
		}else{
			return 0;
		}
	}
	return 0;
}
