#include "sys_config.h"

#define MOTOR_A_PIN				P15
#define MOTOR_B_PIN				P16

#define MOTOR_C_PIN				P17
#define MOTOR_D_PIN				P20

#define MOTOR_E_PIN				P21
#define MOTOR_F_PIN				P22


#define Set_MotorA_Out(X)			((X)?(MOTOR_A_PIN = 1):(MOTOR_A_PIN = 0))	
#define Set_MotorB_Out(X)			((X)?(MOTOR_B_PIN = 1):(MOTOR_B_PIN = 0))	

#define Set_MotorC_Out(X)			((X)?(MOTOR_C_PIN = 1):(MOTOR_C_PIN = 0))	
#define Set_MotorD_Out(X)			((X)?(MOTOR_D_PIN = 1):(MOTOR_D_PIN = 0))	

#define Set_MotorE_Out(X)			((X)?(MOTOR_E_PIN = 1):(MOTOR_E_PIN = 0))	
#define Set_MotorF_Out(X)			((X)?(MOTOR_F_PIN = 1):(MOTOR_F_PIN = 0))	


INT8U Msge_PortInit(INT8U id){
	if(id == 0){
		SET_REG_CON(1,5);
		Set_MotorA_Out(0);
		SET_REG_CON(1,6);
		Set_MotorB_Out(0);
		return 1;
	}else if(id == 1){
		SET_REG_CON(1,7);
		Set_MotorC_Out(0);
		SET_REG_CON(2,0);
		Set_MotorD_Out(0);
		return 1;
	}else if(id == 2){
		SET_REG_CON(2,1);
		Set_MotorE_Out(0);
		SET_REG_CON(2,2);
		Set_MotorF_Out(0);
		return 1;
	}
	return 0;
}

INT8U Msge_PortSet(INT8U id,INT8U num,INT8U set){
	if(id == 0){
		if(num == 0){
			Set_MotorA_Out(set);
		}else{
			Set_MotorB_Out(set);
		}
		return 1;
	}else if(id == 1){
		if(num == 0){
			Set_MotorC_Out(set);
		}else{
			Set_MotorD_Out(set);
		}
		return 1;
	}else if(id == 0){
		if(num == 0){
			Set_MotorE_Out(set);
		}else{
			Set_MotorF_Out(set);
		}
		return 1;
	}
	return 0;
}


