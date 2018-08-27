#include "sys_config.h"
// simulate iic  

#define SDA0_PIN		P43
#define SCL0_PIN		P44

#define SDA1_PIN		P02
#define SCL1_PIN		P03


#define SDA0_Read()	SDA0_PIN
#define SDA0_Set(x)	((x) ? (SDA0_PIN = 1): (SDA0_PIN = 0))

#define SCL0_Read()	SCL0_PIN
#define SCL0_Set(x)	((x) ? (SCL0_PIN = 1) : (SCL0_PIN = 0))

#define SDA1_Read()	SDA1_PIN
#define SDA1_Set(x)	((x) ? (SDA1_PIN = 1): (SDA1_PIN = 0))

#define SCL1_Read()	SCL1_PIN
#define SCL1_Set(x)	((x) ? (SCL1_PIN = 1) : (SCL1_PIN = 0))


int IIC_Port_Init(int ID){
	if(ID == 0){
		//GPIO_Init(SDA0_PORT, SDA0_PIN, GPIO_MODE_OUT_PP_HIGH_FAST);
		//SDA0_Set(1);
		//GPIO_Init(SCL0_PORT, SCL0_PIN, GPIO_MODE_OUT_PP_HIGH_FAST);
		//SCL0_Set(1);
		//P1CON |= 0X30;
		//P1 |= 0X30;
	}
	return 1;
}
/*
	Func : 0 ->IN ;1 ->OUT
*/
int IIC_Port_SDA_Set(int ID,int Func){
	if(ID == 0){
		if(Func == 0){
			SET_REG_CON(4,3);
		}else if(Func == 1){
			SET_REG_CON(4,3);
		}else{
			return 0;
		}
	}else if(ID == 1){
		if(Func == 0){
			SET_REG_CON(0,2);
		}else if(Func == 1){
			SET_REG_CON(0,2);
		}else{
			return 0;
		}
	}else{
		return 0;
	}
	return 0;
	
}
/*
	Func : 0->SDA 1->SCL
	Data: 0->out 0;
*/
int IIC_Port_Write(int ID,int Func,int Data){
	if(ID == 0){
		if(Func == 0){
			SDA0_Set(Data);
		}else if(Func == 1){
			SCL0_Set(Data);
		}else{
			return 0;
		}
	}else if(ID == 1){
		if(Func == 0){
			SDA1_Set(Data);
		}else if(Func == 1){
			SCL1_Set(Data);
		}else{
			return 0;
		}
	}else{
		return 0;
	}
	return 0;

}

int IIC_Port_Read(int ID ,int Func ){
	if(ID == 0){
		if(Func == 0){
			return SDA0_Read();
		}else if(Func == 1){
			return SCL0_Read();
		}else{
			return 0;
		}
	}else if(ID == 1){
		if(Func == 0){
			return SDA1_Read();
		}else if(Func == 1){
			return SCL1_Read();
		}else{
			return 0;
		}
	}else{
		return 0;
	}
	return 0;
}

